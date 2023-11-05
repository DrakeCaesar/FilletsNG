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
    const int format = SDL_PIXELFORMAT_ARGB8888;
    const int access = SDL_TEXTUREACCESS_TARGET;

    int w, h;
    SDL_QueryTexture(texture, nullptr, nullptr, &w, &h);
    w /= 2;

    SDL_Rect srcRect = {x - w + MIRROR_BORDER + 1, y, w, h};
    SDL_Rect dstRect = {x, y, w, h};
    SDL_Rect frmRect = {0, 0, w, h};
    SDL_Rect mskRect = {w, 0, w, h};


    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawRect(renderer, &srcRect);

    SDL_RenderCopy(renderer, texture, &frmRect, &dstRect);

    SDL_Surface *screenSurface = SDL_CreateRGBSurface(0, w, h, 32, 0, 0, 0, 0);
    SDL_RenderReadPixels(renderer, &srcRect, format, screenSurface->pixels, screenSurface->pitch);
    SDL_Texture *screenTexture = SDL_CreateTextureFromSurface(renderer, screenSurface);
    SDL_FreeSurface(screenSurface);

    SDL_Texture *mirroredTexture = SDL_CreateTexture(renderer, format, access, w, h);
    SDL_SetRenderTarget(renderer, mirroredTexture);
    SDL_RenderCopy(renderer, texture, &mskRect, &frmRect);
    SDL_SetTextureBlendMode(screenTexture, SDL_BLENDMODE_MOD);
    SDL_RenderCopyEx(renderer, screenTexture, &frmRect, &frmRect, 0, nullptr, SDL_FLIP_HORIZONTAL);
    SDL_DestroyTexture(screenTexture);

    SDL_SetRenderTarget(renderer, nullptr);
    SDL_SetTextureBlendMode(mirroredTexture, SDL_BLENDMODE_ADD);
    SDL_RenderCopy(renderer, mirroredTexture, &frmRect, &dstRect);
    SDL_DestroyTexture(mirroredTexture);
}
