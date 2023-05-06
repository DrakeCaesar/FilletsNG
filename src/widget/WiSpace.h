#ifndef HEADER_WISPACE_H
#define HEADER_WISPACE_H

#include "IWidget.h"

/**
 * Empty place with width and height.
 */
class WiSpace : public IWidget
{
private:
	int m_w;
	int m_h;

public:
	WiSpace(int width, int height) : m_w(width), m_h(height)
	{
	}

	int getW() const override { return m_w; }
	int getH() const override { return m_h; }

	void drawOn(SDL_Surface* /*screen*/) override
	{
	}
};

#endif
