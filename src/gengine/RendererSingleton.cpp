#include "RendererSingleton.h"

RendererSingleton::RendererSingleton() : renderer(nullptr)
{
}

RendererSingleton::~RendererSingleton()
{
  if (renderer)
  {
    SDL_DestroyRenderer(renderer);
  }
}

RendererSingleton &RendererSingleton::getInstance()
{
  static RendererSingleton instance;
  return instance;
}

SDL_Renderer *RendererSingleton::initialize(SDL_Window *window, int index, Uint32 flags)
{
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  return renderer;
}

SDL_Renderer *RendererSingleton::getRenderer() const
{
  return renderer;
}