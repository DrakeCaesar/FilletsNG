#ifndef HEADER_POSTERSCROLLER_H
#define HEADER_POSTERSCROLLER_H

class Path;
class Picture;

#include "PosterState.h"

/**
 * Scroll very height picture.
 */
class PosterScroller : public PosterState
{
private:
	static const int SHIFT_SPEED = 4;
	int m_shift;
	int m_screenH;

protected:
	void own_initState() override;
	void own_updateState() override;

public:
	PosterScroller(const Path& picture);
	bool allowBg() const override { return true; }
};

#endif
