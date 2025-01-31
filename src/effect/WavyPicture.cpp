/*
 * Copyright (C) 2004 Ivo Danihelka (ivo@danihelka.net)
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 */
#include "WavyPicture.h"

#include <iostream>

#include "TimerAgent.h"

#include <math.h>
#include <ostream>

#include "Application.h"
//-----------------------------------------------------------------
/**
 * Load surface.
 * Default is no waves.
 */
WavyPicture::WavyPicture(const Path &file, const V2 &loc) : Picture(file, loc)
{
  m_amp = 0;
  m_periode = m_surface->w;
  m_speed = 0;
}

//-----------------------------------------------------------------
/**
 * Blit entire surface to [x,y].
 * Do vertical waves with phase shift.
 */

void WavyPicture::drawOn(SDL_Surface *screen, SDL_Renderer *renderer)
{
  int renderer_width, renderer_height;
  int texture_width, texture_height;
  SDL_GetRendererOutputSize(renderer, &renderer_width, &renderer_height);
  m_texture = SDL_CreateTextureFromSurface(renderer, m_surface);
  SDL_QueryTexture(m_texture, nullptr, nullptr, &texture_width, &texture_height);

  const float scaleX = static_cast<float>(renderer_width) / static_cast<float>(m_surface->w);
  const float scaleY = static_cast<float>(renderer_height) / static_cast<float>(m_surface->h);
  const int x = m_loc.getX();
  const int y = m_loc.getY();
  if (m_amp == 0)
  {
    const SDL_Rect srcRect = {0, 0, texture_width, texture_height};
    const SDL_FRect dstRect = {static_cast<float>(x), static_cast<float>(y), static_cast<float>(renderer_width),
                               static_cast<float>(renderer_height)};
    SDL_RenderCopyExF(renderer, m_texture, &srcRect, &dstRect, 0.0, nullptr, SDL_FLIP_NONE);
    return;
  }
  SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
  const float shift = static_cast<float>(TimerAgent::agent()->getCycles()) * m_speed / static_cast<float>(speedup);
  for (int py = 0; py < renderer_height; ++py)
  {
    const float shiftXf = -(0.5f + m_amp * sinf(static_cast<float>(py) / m_periode + shift));
    SDL_Rect srcRect = {0, py, texture_width, 1};

    SDL_FRect dstRect = {0.0f, static_cast<float>(y) + static_cast<float>(py) * scaleY,
                         static_cast<float>(texture_width) * scaleX, scaleY};

    dstRect.x = static_cast<float>(x) + shiftXf - static_cast<float>(texture_width) * scaleX;
    SDL_RenderCopyExF(renderer, m_texture, &srcRect, &dstRect, 0.0, nullptr, SDL_FLIP_HORIZONTAL);

    dstRect.x = static_cast<float>(x) + shiftXf;
    SDL_RenderCopyExF(renderer, m_texture, &srcRect, &dstRect, 0.0, nullptr, SDL_FLIP_NONE);

    dstRect.x = static_cast<float>(x) + shiftXf + static_cast<float>(texture_width) * scaleX;
    SDL_RenderCopyExF(renderer, m_texture, &srcRect, &dstRect, 0.0, nullptr, SDL_FLIP_HORIZONTAL);
  }
  SDL_DestroyTexture(m_texture);
}
