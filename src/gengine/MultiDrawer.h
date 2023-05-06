#ifndef HEADER_MULTIDRAWER_H
#define HEADER_MULTIDRAWER_H

#include "Drawable.h"

#include <vector>

/**
 * Container for pasive drawers.
 */
class MultiDrawer : public Drawable
{
private:
	using t_drawers = std::vector<Drawable*>;
	t_drawers m_drawers;

public:
	void acceptDrawer(Drawable* drawer);
	void removeDrawer(const Drawable* drawer);
	void removeAll();

	void drawOn(SDL_Surface* screen) override;
};

#endif
