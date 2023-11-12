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
WavyPicture::WavyPicture(const Path&file, const V2&loc)
    : Picture(file, loc) {
    m_amp = 0;
    m_periode = m_surface->w;
    m_speed = 0;
}

//-----------------------------------------------------------------
/**
 * Blit entire surface to [x,y].
 * Do vertical waves with phase shift.
 */
static int test = 0;

void WavyPicture::drawOn(SDL_Surface* screen, SDL_Renderer* renderer) {
    test++;
    if (test % 2 == -1) {
        if (m_amp == 0) {
            Picture::drawOn(screen, renderer);
            return;
        }
        Picture::drawOn(screen, renderer);
        // NOTE: Wamp = Wamp_in_orig/2.0
        // NOTE: Wspeed = 1.0/Wspd_in_orig
        SDL_Rect dest_rect;
        SDL_Rect line_rect;
        line_rect.w = m_surface->w;
        line_rect.h = 1;
        SDL_Rect pad;
        pad.h = 1;

        m_texture = SDL_CreateTextureFromSurface(renderer, m_surface);


        // copy surface
        SDL_Surface* m_surface2 = SDL_CreateRGBSurface(0, m_surface->w, m_surface->h, 32, 0, 0, 0, 0);
        SDL_BlitSurface(m_surface, NULL, m_surface2, NULL);

        float shift = TimerAgent::agent()->getCycles() * m_speed;
        shift = shift / speedup;
        SDL_Rect srcRect;
        SDL_FRect dstRect;


        for (int py = 0; py < m_surface->h; ++py) {
            // NOTE: C99 has lrintf and sinf
            Sint16 shiftX = static_cast<Sint16>(0.5 +
                                                m_amp * sin(py / m_periode + shift));
            line_rect.x = shiftX;
            line_rect.y = py;
            dest_rect.x = m_loc.getX();
            dest_rect.y = m_loc.getY() + py;
            SDL_BlitSurface(m_surface, &line_rect, m_surface2, &dest_rect);

            pad.x = (shiftX < 0) ? 0 : m_surface->w - shiftX;
            pad.y = py;
            pad.w = abs(shiftX);
            dest_rect.x = m_loc.getX() + pad.x;
            dest_rect.y = m_loc.getY() + py;
            SDL_BlitSurface(m_surface, &pad, m_surface2, &dest_rect);
        }

        auto texture = SDL_CreateTextureFromSurface(renderer, m_surface2);
        SDL_RenderCopy(renderer, texture, NULL, NULL);
        SDL_DestroyTexture(texture);
        SDL_FreeSurface(m_surface2);

        SDL_DestroyTexture(m_texture);
    }
    else {
        int renderer_width, renderer_height;
        int texture_width, texture_height;
        SDL_GetRendererOutputSize(renderer, &renderer_width, &renderer_height);
        m_texture = SDL_CreateTextureFromSurface(renderer, m_surface);
        SDL_QueryTexture(m_texture, nullptr, nullptr, &texture_width, &texture_height);

        const float scaleX = static_cast<float>(renderer_width) / static_cast<float>(m_surface->w);
        const float scaleY = static_cast<float>(renderer_height) / static_cast<float>(m_surface->h);
        const int x = m_loc.getX();
        const int y = m_loc.getY();
        if (m_amp == 0) {
            const SDL_Rect destRect = {m_loc.getX(), m_loc.getY(), m_surface->w, m_surface->h};
            SDL_RenderCopy(renderer, m_texture, nullptr, &destRect);
            return;
        }
        SDL_QueryTexture(m_texture, nullptr, nullptr, &renderer_width, &renderer_height);
        SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
        const float shift = static_cast<float>(TimerAgent::agent()->getCycles()) * m_speed / static_cast<float>(
                                speedup);
        for (int py = 0; py < renderer_height; ++py) {
            const float shiftXf = -(0.5f + m_amp * sinf(static_cast<float>(py) / m_periode + shift));
            SDL_Rect srcRect = {0, py, texture_width, 1};
            SDL_FRect dstRect = {
                static_cast<float>(x) + shiftXf,
                static_cast<float>(y) + static_cast<float>(py) * scaleY,
                static_cast<float>(texture_width) * scaleX,
                scaleY
            };
            SDL_RenderCopyExF(renderer, m_texture, &srcRect, &dstRect, 0.0, NULL, SDL_FLIP_NONE);
        }
        SDL_DestroyTexture(m_texture);
    }
}
