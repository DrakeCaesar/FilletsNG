#ifndef HEADER_VBOX_H
#define HEADER_VBOX_H

#include "WiBox.h"

/**
 * Vertical box.
 */
class VBox : public WiBox
{
private:
	int m_w;
	int m_h;
	bool m_centered;

public:
	VBox();
	void enableCentered() { m_centered = true; }
	void recenter() { setShift(m_shift); }

	int getW() const override { return m_w; }
	int getH() const override { return m_h; }
	void addWidget(IWidget* new_widget) override;
	void setShift(const V2& shift) override;
};

#endif
