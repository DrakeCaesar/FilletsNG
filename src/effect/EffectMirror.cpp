/*
 * Copyright (C) 2004 Ivo Danihelka (ivo@danihelka.net)
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 */
#include <iostream>
#include <SDL_image.h>
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
    mirrorW /= 2;

    SDL_Rect srcRect;
    srcRect.x = mirrorX - mirrorW;
    srcRect.y = mirrorY;
    srcRect.w = mirrorW;
    srcRect.h = mirrorH;

    SDL_Rect dstRect;
    dstRect.x = mirrorX;
    dstRect.y = mirrorY;
    dstRect.w = mirrorW;
    dstRect.h = mirrorH;


    SDL_Rect mirrorRect;
    mirrorRect.x = 0;
    mirrorRect.y = 0;
    mirrorRect.w = mirrorW;
    mirrorRect.h = mirrorH;

    SDL_Rect maskRect;
    maskRect.x = mirrorW;
    maskRect.y = 0;
    maskRect.w = mirrorW;
    maskRect.h = mirrorH;

    const int format = SDL_PIXELFORMAT_ARGB8888;
    const int access = SDL_TEXTUREACCESS_TARGET;


    int width, height;
    SDL_GetRendererOutputSize(renderer, &width, &height);
    SDL_Surface *screenSurface = SDL_CreateRGBSurface(0, width, height, 32, 0, 0, 0, 0);
    SDL_RenderReadPixels(renderer, &srcRect, format, screenSurface->pixels, screenSurface->pitch);
    auto screenTexture = SDL_CreateTextureFromSurface(renderer, screenSurface);
    SDL_Texture *mirroredTexture = SDL_CreateTexture(renderer, format, access, mirrorW, mirrorH);

    SDL_Texture *maskTexture = SDL_CreateTexture(renderer, format, access, mirrorW, mirrorH);
    SDL_SetRenderTarget(renderer, maskTexture);
    SDL_RenderCopy(renderer, texture, &maskRect, &mirrorRect);

    SDL_Texture *mirrorTexture = SDL_CreateTexture(renderer, format, access, mirrorW, mirrorH);
    SDL_SetRenderTarget(renderer, mirrorTexture);
    SDL_RenderCopy(renderer, texture, &mirrorRect, &mirrorRect);


    SDL_SetRenderTarget(renderer, nullptr);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawRect(renderer, &srcRect);
    SDL_RenderCopy(renderer, texture, &mirrorRect, &dstRect);


    SDL_SetRenderTarget(renderer, mirroredTexture);
    // SDL_RenderCopy(renderer, texture, &mirrorRect, &mirrorRect);
    SDL_RenderCopy(renderer, maskTexture, &mirrorRect, &mirrorRect);
    SDL_SetTextureBlendMode(screenTexture, SDL_BLENDMODE_MOD);
    SDL_RenderCopyEx(renderer, screenTexture, &mirrorRect, &mirrorRect, 0, nullptr, SDL_FLIP_HORIZONTAL);


    SDL_SetRenderTarget(renderer, nullptr);
    SDL_SetTextureBlendMode(mirroredTexture, SDL_BLENDMODE_ADD);


    SDL_RenderCopy(renderer, mirroredTexture, &mirrorRect, &dstRect);


    SDL_DestroyTexture(screenTexture);
    SDL_DestroyTexture(maskTexture);
    SDL_DestroyTexture(mirroredTexture);
    SDL_DestroyTexture(mirrorTexture);
    SDL_FreeSurface(screenSurface);
}
