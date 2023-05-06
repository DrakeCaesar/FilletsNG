#ifndef HEADER_RADIOBOX_H
#define HEADER_RADIOBOX_H

class Path;

#include "WiContainer.h"

/**
 * Radio box with picture background.
 */
class RadioBox : public WiContainer
{
private:
	static const int BORDER = 4;
	std::string m_param;
	std::string m_value;

protected:
	void own_mouseButton(const MouseStroke& stroke) override;

public:
	RadioBox(const std::string& param, const std::string& value,
	         const Path& picture);

	void drawOn(SDL_Surface* screen) override;
};

#endif
