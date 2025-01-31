/*
 * Copyright (C) 2004 Ivo Danihelka (ivo@danihelka.net)
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 */
#include "EffectMirror.h"
#include <SDL_image.h>
#include <chrono>
#include <deque>
#include <iostream>

#include "PixelTool.h"
#include "SurfaceLock.h"

const char *EffectMirror::NAME = "mirror";
static SDL_Texture *mirrored = nullptr;
//-----------------------------------------------------------------
/**
 * Mirror effect. Draw left side inside.
 * The pixel in the middle will be used as a mask.
 * NOTE: mirror object should be drawn as the last.
 */

void EffectMirror::blit(SDL_Renderer *renderer, SDL_Texture *texture, SDL_Surface * /* surface */, int x, int y)
{
  int w, h;
  SDL_QueryTexture(texture, nullptr, nullptr, &w, &h);
  w /= 2;
  SDL_Rect srcRect = {x - w + MIRROR_BORDER + 1, y, w, h};
  SDL_Rect dstRect = {x, y, w, h};
  SDL_Rect mrrRect = {0, 0, w, h};
  SDL_Rect mskRect = {w, 0, w, h};

  if (mirrored == nullptr)
    mirrored = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_TARGET, w, h);

  SDL_RenderCopy(renderer, texture, &mrrRect, &dstRect);
  SDL_Texture *screen = SDL_GetRenderTarget(renderer);

  SDL_SetRenderTarget(renderer, mirrored);
  SDL_RenderCopy(renderer, texture, &mskRect, nullptr);

  SDL_SetTextureBlendMode(screen, SDL_BLENDMODE_MOD);
  SDL_RenderCopyEx(renderer, screen, &srcRect, &mrrRect, 0, nullptr, SDL_FLIP_HORIZONTAL);
  SDL_SetTextureBlendMode(screen, SDL_BLENDMODE_NONE);

  SDL_SetRenderTarget(renderer, screen);
  SDL_SetTextureBlendMode(mirrored, SDL_BLENDMODE_BLEND);
  SDL_RenderCopy(renderer, mirrored, nullptr, &dstRect);
}

void EffectMirror::cleanup()
{
  if (mirrored)
  {
    SDL_DestroyTexture(mirrored);
    mirrored = nullptr;
  }
}