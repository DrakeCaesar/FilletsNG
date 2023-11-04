/*
 * Copyright (C) 2004 Ivo Danihelka (ivo@danihelka.net)
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 */
#include "EffectMirror.h"

#include "SurfaceLock.h"
#include "PixelTool.h"

const char *EffectMirror::NAME = "mirror";
//-----------------------------------------------------------------
/**
 * Mirror effect. Draw left side inside.
 * The pixel in the middle will be used as a mask.
 * NOTE: mirror object should be drawn as the last.
 */
void EffectMirror::blit(SDL_Renderer *renderer, SDL_Texture *texture, SDL_Surface *surface, int x, int y) {
    // Determine the area we will be updating based on the position and size of the texture.
    SDL_Rect dstRect;
    dstRect.x = x - surface->w;
    dstRect.y = y;
    dstRect.w = surface->w * 2;
    dstRect.h = surface->h;

    SDL_Rect srcRect;
    srcRect.x = 0;
    srcRect.y = 0;
    srcRect.w = surface->w * 2;
    srcRect.h = surface->h;

    int width, height;
    SDL_GetRendererOutputSize(renderer, &width, &height);
    SDL_Surface *screen = SDL_CreateRGBSurface(0, width, height, 32, 0, 0, 0, 0);
    SDL_RenderReadPixels(renderer, &dstRect, SDL_PIXELFORMAT_ARGB8888, screen->pixels, screen->pitch);
    SurfaceLock lock2(surface);
    SDL_Color mask = PixelTool::getColor(surface,
                                         surface->w / 2, surface->h / 2);

    for (int py = 0; py < surface->h; ++py) {
        for (int px = 0; px < surface->w; ++px) {
            SDL_Color pixel = PixelTool::getColor(surface, px, py);
            if (px > MIRROR_BORDER && PixelTool::colorEquals(pixel, mask)) {
                SDL_Color sample = PixelTool::getColor(screen,
                                                       surface->w - px + MIRROR_BORDER, py);
                PixelTool::putColor(screen, px + surface->w, py, sample);
            } else {
                if (pixel.a == 255) {
                    PixelTool::putColor(screen, px + surface->w, py, pixel);
                }
            }
        }
    }
    auto texture_s = SDL_CreateTextureFromSurface(renderer, screen);
    SDL_SetRenderDrawColor(renderer, dstRect.x, dstRect.y, dstRect.w, dstRect.h);
    //SDL_RenderCopy(renderer, texture_s, &srcRect, &dstRect);
    SDL_RenderCopy(renderer, texture_s, &srcRect, &dstRect);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    SDL_RenderDrawRect(renderer, &dstRect);
    SDL_DestroyTexture(texture_s);
    SDL_FreeSurface(screen);

}
