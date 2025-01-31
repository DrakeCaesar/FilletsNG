/*
 * Copyright (C) 2004 Ivo Danihelka (ivo@danihelka.net)
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 */
#include "EffectReverse.h"

#include "PixelTool.h"
#include "SurfaceLock.h"

const char *EffectReverse::NAME = "reverse";
//-----------------------------------------------------------------
/**
 * Reverse left and right.
 */
void EffectReverse::blit(SDL_Renderer *renderer, SDL_Texture *texture, SDL_Surface *surface, int x, int y)
{
  int width, height;
  SDL_GetRendererOutputSize(renderer, &width, &height);
  SDL_Surface *screen = SDL_CreateRGBSurface(0, width, height, 32, 0, 0, 0, 0);
  SurfaceLock lock1(screen);
  SurfaceLock lock2(surface);

  for (int py = 0; py < surface->h; ++py)
  {
    for (int px = 0; px < surface->w; ++px)
    {
      SDL_Color pixel = PixelTool::getColor(surface, px, py);
      if (pixel.a == 255)
      {
        PixelTool::putColor(screen, x + surface->w - 1 - px, y + py, pixel);
      }
    }
  }
  auto texture_s = SDL_CreateTextureFromSurface(renderer, screen);
  SDL_RenderCopy(renderer, texture_s, NULL, NULL);
  SDL_DestroyTexture(texture_s);
  SDL_FreeSurface(screen);
}
