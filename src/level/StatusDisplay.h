#ifndef HEADER_STATUSDISPLAY_H
#define HEADER_STATUSDISPLAY_H

class Picture;

#include "Drawable.h"

/**
 * Show status change.
 */
class StatusDisplay : public Drawable
{
private:
	Picture* m_picture;
	int m_time;

public:
	StatusDisplay();
	~StatusDisplay() override;
	void displayStatus(Picture* new_picture, int time);
	void drawOn(SDL_Surface* screen) override;
};

#endif
