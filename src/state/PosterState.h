#ifndef HEADER_POSTERSTATE_H
#define HEADER_POSTERSTATE_H

class Path;
class Picture;

#include "GameState.h"

/**
 * Static picture.
 */
class PosterState : public GameState
{
protected:
	Picture* m_bg;

protected:
	void own_initState() override;

	void own_updateState() override
	{
	}

	void own_pauseState() override
	{
	}

	void own_resumeState() override
	{
	}

	void own_cleanState() override
	{
	}

public:
	PosterState(const Path& picture);
	~PosterState() override;
	const char* getName() const override { return "state_poster"; };
};

#endif
