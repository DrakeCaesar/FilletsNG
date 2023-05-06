#ifndef HEADER_WIPICTURE_H
#define HEADER_WIPICTURE_H

class Path;

#include "IWidget.h"

/**
 * Picture widget.
 */
class WiPicture : public IWidget
{
protected:
	SDL_Surface* m_surface;

protected:
	WiPicture(SDL_Surface* new_surface) { m_surface = new_surface; }

public:
	WiPicture(const Path& picture);
	~WiPicture() override;
	int getW() const override { return m_surface->w; }
	int getH() const override { return m_surface->h; }

	void drawOn(SDL_Surface* screen) override;
};

#endif
