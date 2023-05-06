#ifndef HEADER_WICONTAINER_H
#define HEADER_WICONTAINER_H

#include "IWidget.h"

/**
 * Widget with one subwidget inside.
 */
class WiContainer : public IWidget
{
private:
	IWidget* m_content;
	int m_border;

protected:
	void own_mouseButton(const MouseStroke& stroke) override;

public:
	WiContainer(IWidget* new_content, int border = 0);
	~WiContainer() override;
	int getW() const override;
	int getH() const override;
	void setShift(const V2& shift) override;

	void drawOn(SDL_Surface* screen) override;
};

#endif
