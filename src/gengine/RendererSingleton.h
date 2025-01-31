#ifndef RENDERERSINGLETON_H
#define RENDERERSINGLETON_H

#include <SDL.h>

class RendererSingleton
{
public:
  static RendererSingleton &getInstance();
  SDL_Renderer *initialize(SDL_Window *window, int index, Uint32 flags);
  SDL_Renderer *getRenderer() const;

  RendererSingleton(const RendererSingleton &) = delete;
  RendererSingleton &operator=(const RendererSingleton &) = delete;

private:
  RendererSingleton();
  ~RendererSingleton();

  SDL_Renderer *renderer;
};

#endif // RENDERERSINGLETON_H