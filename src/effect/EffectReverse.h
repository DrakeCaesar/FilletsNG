#ifndef HEADER_EFFECTREVERSE_H
#define HEADER_EFFECTREVERSE_H

#include "ViewEffect.h"

/**
 * Blit with reversed left and right side.
 */
class EffectReverse : public ViewEffect
{
public:
	static const char* NAME;
	const char* getName() const override { return NAME; }
	void blit(SDL_Surface* screen, SDL_Surface* surface,
	          int x, int y) override;
};

#endif
