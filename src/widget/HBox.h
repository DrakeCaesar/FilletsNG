#ifndef HEADER_HBOX_H
#define HEADER_HBOX_H

#include "WiBox.h"

/**
 * Horizontal box.
 */
class HBox : public WiBox
{
private:
	int m_w;
	int m_h;

public:
	HBox();
	int getW() const override { return m_w; }
	int getH() const override { return m_h; }
	void addWidget(IWidget* new_widget) override;
	void setShift(const V2& shift) override;
};

#endif
