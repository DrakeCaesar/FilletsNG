#ifndef HEADER_DEMOMODE_H
#define HEADER_DEMOMODE_H

class Picture;
class DemoInput;

#include "Path.h"
#include "GameState.h"
#include "Planner.h"
#include "Drawable.h"

/**
 * Graphic demo.
 */
class DemoMode : public Planner, public GameState, public Drawable
{
private:
	int m_oldLimitY;
	Path m_demoscript;
	SDL_Surface* m_surfaceBuffer;
	Picture* m_display;

protected:
	void own_initState() override;
	void own_updateState() override;

	void own_pauseState() override
	{
	}

	void own_resumeState() override
	{
	}

	void own_cleanState() override;

public:
	DemoMode(const Path& demoscript);
	~DemoMode() override;
	const char* getName() const override { return "state_demo"; };

	bool action_display(Picture* picture);
	void drawOn(SDL_Surface* screen) override;
};

#endif
