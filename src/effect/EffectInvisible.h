#ifndef HEADER_EFFECTINVISIBLE_H
#define HEADER_EFFECTINVISIBLE_H

#include "ViewEffect.h"

/**
 * Draw nothing.
 */
class EffectInvisible : public ViewEffect
{
public:
  static const char *NAME;

  virtual const char *getName() const
  {
    return NAME;
  }

  virtual bool isInvisible() const
  {
    return true;
  }

  virtual void blit(SDL_Renderer *renderer, SDL_Texture *texture, SDL_Surface *surface, int, int)
  {
  }
};

const char *EffectInvisible::NAME = "invisible";

#endif
