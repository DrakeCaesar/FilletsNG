/*
 * Copyright (C) 2004 Ivo Danihelka (ivo@danihelka.net)
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 */
#include "LayeredPicture.h"

#include "Path.h"
#include "ResImagePack.h"
#include "ResourceException.h"
#include "SurfaceLock.h"
#include "PixelTool.h"

//-----------------------------------------------------------------
/**
 * Create picture with two layers and color mask to select
 * active areas.
 *
 * @throws ResourceException when lowerLayer and colorMask have
 * different proportions
 */
LayeredPicture::LayeredPicture(const Path &bg_file, const V2 &loc,
                               const Path &lowerLayer, const Path &colorMask)
        : Picture(bg_file, loc) {
    m_lowerLayer = ResImagePack::loadImage(lowerLayer);
    m_colorMask = ResImagePack::loadImage(colorMask);
    if (m_lowerLayer->w != m_colorMask->w || m_lowerLayer->h != m_colorMask->h) {
        SDL_FreeSurface(m_lowerLayer);
        SDL_FreeSurface(m_colorMask);
        SDL_FreeSurface(m_surface);

        throw ResourceException(ExInfo(
                "lowerLayer and colorMask have different proportions")
                                        .addInfo("lowerLayer", lowerLayer.getNative())
                                        .addInfo("colorMask", colorMask.getNative()));
    }

    setNoActive();
}

//-----------------------------------------------------------------
LayeredPicture::~LayeredPicture() {
    SDL_FreeSurface(m_lowerLayer);
    SDL_FreeSurface(m_colorMask);
}
//-----------------------------------------------------------------
/**
 * Return pixel at worldLoc.
 * Translates world coordinates to local coordinates.
 */
Uint32
LayeredPicture::getMaskAtWorld(const V2 &worldLoc) {
    V2 localLoc = worldLoc.minus(m_loc);
    return getMaskAt(localLoc);
}
//-----------------------------------------------------------------
/**
 * Return pixel at position from left top image corner.
 */
Uint32
LayeredPicture::getMaskAt(const V2 &loc) {
    Uint32 result = MASK_NO;

    if ((0 <= loc.getX() && loc.getX() < m_colorMask->w) && (0 <= loc.getY() && loc.getY() < m_colorMask->h)) {
        SurfaceLock lock1(m_colorMask);
        result = PixelTool::getPixel(m_colorMask,
                                     loc.getX(), loc.getY());
    }
    return result;
}

//-----------------------------------------------------------------
void LayeredPicture::drawOn(SDL_Surface *screen, SDL_Renderer *renderer) {
    Picture::drawOn(screen, renderer); // Assuming this function has been updated to use SDL_Renderer

    if (m_activeColor == MASK_NO) {
        return;
    }

    // Create textures from surfaces
    SDL_Texture *lowerLayerTexture = SDL_CreateTextureFromSurface(renderer, m_lowerLayer);
    SDL_Texture *colorMaskTexture = SDL_CreateTextureFromSurface(renderer, m_colorMask);

    // Set blend modes to blend the textures
    SDL_SetTextureBlendMode(lowerLayerTexture, SDL_BLENDMODE_BLEND);
    SDL_SetTextureBlendMode(colorMaskTexture, SDL_BLENDMODE_BLEND);

    // Copy the lower layer to the renderer first
    SDL_Rect lowerLayerRect = {m_loc.getX(), m_loc.getY(), m_lowerLayer->w, m_lowerLayer->h};
    SDL_RenderCopy(renderer, lowerLayerTexture, NULL, &lowerLayerRect);

    // You will now need to handle the masking and copying of the color mask
    // ...

    // TODO: You need to replace the direct pixel manipulation with a shader or some other means of combining textures
    // Since SDL does not provide a built-in way to do this, you might need to use a custom shader with SDL_RenderReadPixels or similar

    // Cleanup textures
    SDL_DestroyTexture(lowerLayerTexture);
    SDL_DestroyTexture(colorMaskTexture);
}


