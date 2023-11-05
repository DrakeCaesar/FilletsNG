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



SDL_BlendMode customBlendMode = SDL_ComposeCustomBlendMode(
        SDL_BLENDFACTOR_ONE, // srcColorFactor
        SDL_BLENDFACTOR_ONE, // dstColorFactor
        SDL_BLENDOPERATION_SUBTRACT, // colorOperation
        SDL_BLENDFACTOR_ZERO, // srcAlphaFactor
        SDL_BLENDFACTOR_ONE, // dstAlphaFactor
        SDL_BLENDOPERATION_ADD // alphaOperation
);


void EffectMirror::blit(SDL_Renderer *renderer, SDL_Texture *texture, SDL_Surface *surface, int x, int y) {
    // Determine the area we will be updating based on the position and size of the texture.

    int mirrorX = x;
    int mirrorY = y;
    int mirrorW;
    int mirrorH;
    SDL_QueryTexture(texture, NULL, NULL, &mirrorW, &mirrorH);

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

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawRect(renderer, &srcRect);
    SDL_RenderCopy(renderer, texture, NULL, &dstRect);

    int width, height;
    SDL_GetRendererOutputSize(renderer, &width, &height);
    SDL_Surface *screenSurface = SDL_CreateRGBSurface(0, width, height, 32, 0, 0, 0, 0);
    SDL_RenderReadPixels(renderer, &srcRect, SDL_PIXELFORMAT_ARGB8888, screenSurface->pixels, screenSurface->pitch);
    auto screenTexture = SDL_CreateTextureFromSurface(renderer, screenSurface);
    SDL_Texture *mirroredTexture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_TARGET,
                                                     mirrorW, mirrorH);
    SDL_Texture *maskTexture = IMG_LoadTexture(renderer, "/home/domin/Desktop/zrcadlo_mask.png");


    SDL_SetRenderTarget(renderer, mirroredTexture);
    // SDL_RenderCopy(renderer, texture, &mirrorRect, &mirrorRect);
    SDL_RenderCopy(renderer, maskTexture, &mirrorRect, &mirrorRect);
    SDL_SetTextureBlendMode(screenTexture, SDL_BLENDMODE_MOD);
    SDL_RenderCopyEx(renderer, screenTexture, &mirrorRect, &mirrorRect, 0, nullptr, SDL_FLIP_HORIZONTAL);


    SDL_SetRenderTarget(renderer, nullptr);
    SDL_SetTextureBlendMode(mirroredTexture, SDL_BLENDMODE_ADD);


    SDL_RenderCopy(renderer, mirroredTexture, &mirrorRect, &dstRect);
    SDL_Texture *targetTexture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, width,
                                                   height);


    // SDL_SetTextureBlendMode(targetTexture, SDL_BLENDMODE_BLEND);
    // SDL_SetRenderTarget(renderer, targetTexture);
    // SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    // SDL_RenderClear(renderer);
    //
    // SDL_SetRenderTarget(renderer, nullptr);


    SDL_DestroyTexture(screenTexture);
    SDL_DestroyTexture(maskTexture);
    SDL_DestroyTexture(mirroredTexture);
    SDL_FreeSurface(screenSurface);
}
