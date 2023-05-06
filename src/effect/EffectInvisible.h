#ifndef HEADER_EFFECTINVISIBLE_H
#define HEADER_EFFECTINVISIBLE_H

#include "ViewEffect.h"

/**
 * Draw nothing.
 */
class EffectInvisible : public ViewEffect
{
public:
	static const char* NAME;
	const char* getName() const override { return NAME; }
	bool isInvisible() const override { return true; }

	void blit(SDL_Surface*, SDL_Surface*, int, int) override
	{
	}
};

const char* EffectInvisible::NAME = "invisible";

#endif
