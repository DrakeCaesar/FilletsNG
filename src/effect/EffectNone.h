#ifndef HEADER_EFFECTNONE_H
#define HEADER_EFFECTNONE_H

#include "ViewEffect.h"

/**
 * Blit without any special effect.
 */
class EffectNone : public ViewEffect
{
public:
	static const char* NAME;
	const char* getName() const override { return NAME; }
	void blit(SDL_Surface* screen, SDL_Surface* surface,
	          int x, int y) override;
};

#endif
