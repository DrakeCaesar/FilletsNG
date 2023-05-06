#ifndef HEADER_WIBOX_H
#define HEADER_WIBOX_H

#include "IWidget.h"

#include <vector>

/**
 * Box which care about subwidget layout.
 * NOTE: soubwidgets should have constant size.
 */
class WiBox : public IWidget
{
protected:
	using t_widgets = std::vector<IWidget*>;
	t_widgets m_widgets;
	std::string own_getTip(const V2& loc) override;
	void own_mouseButton(const MouseStroke& stroke) override;

public:
	~WiBox() override;
	virtual void addWidget(IWidget* new_widget) = 0;

	void drawOn(SDL_Surface* screen) override;
};

#endif
