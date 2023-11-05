/*
 * Copyright (C) 2004 Ivo Danihelka (ivo@danihelka.net)
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 */
#include <iostream>
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

    int mirrorX = x;
    int mirrorY = y;
    int mirrorW;
    int mirrorH;
    SDL_QueryTexture(texture, NULL, NULL, &mirrorW, &mirrorH);

    SDL_Rect dstRect;
    dstRect.x = mirrorX - mirrorW;
    dstRect.y = mirrorY;
    dstRect.w = mirrorW * 2;
    dstRect.h = mirrorH;

    SDL_Rect srcRect;
    srcRect.x = 0;
    srcRect.y = 0;
    srcRect.w = mirrorW * 2;
    srcRect.h = mirrorH;

    SDL_Rect mirrorRect;
    mirrorRect.x = mirrorX;
    mirrorRect.y = mirrorY;
    mirrorRect.w = mirrorW;
    mirrorRect.h = mirrorH;
    SDL_RenderCopy(renderer, texture, NULL, &mirrorRect);

    int width, height;
    SDL_GetRendererOutputSize(renderer, &width, &height);
    SDL_Surface *screen = SDL_CreateRGBSurface(0, width, height, 32, 0, 0, 0, 0);
    SDL_RenderReadPixels(renderer, &dstRect, SDL_PIXELFORMAT_ARGB8888, screen->pixels, screen->pitch);
    SurfaceLock lock2(surface);

    SDL_Color mask = PixelTool::getColor(surface, mirrorW / 2, mirrorH / 2);
    for (int py = 0; py < mirrorH; ++py) {
        for (int px = 0; px < mirrorW; ++px) {
            SDL_Color pixel = PixelTool::getColor(surface, px, py);
            if (px > MIRROR_BORDER && PixelTool::colorEquals(pixel, mask)) {
                SDL_Color sample = PixelTool::getColor(screen, mirrorW - px + MIRROR_BORDER, py);
                PixelTool::putColor(screen, px + mirrorW, py, sample);
            }
        }
    }
    auto texture_s = SDL_CreateTextureFromSurface(renderer, screen);
    SDL_SetRenderDrawColor(renderer, dstRect.x, dstRect.y, dstRect.w, dstRect.h);
    SDL_RenderCopy(renderer, texture_s, &srcRect, &dstRect);
    SDL_RenderCopy(renderer, texture_s, &srcRect, &dstRect);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawRect(renderer, &dstRect);

    SDL_DestroyTexture(texture_s);
    SDL_FreeSurface(screen);

}
