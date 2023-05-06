#ifndef HEADER_MENUHELP_H
#define HEADER_MENUHELP_H

class IWidget;

#include "GameState.h"
#include "Drawable.h"

/**
 * Help screen.
 */
class MenuHelp : public GameState, public Drawable
{
private:
	IWidget* m_help;

protected:
	void own_initState() override;

	void own_updateState() override
	{
	}

	void own_pauseState() override
	{
	}

	void own_resumeState() override;

	void own_cleanState() override
	{
	}

public:
	MenuHelp();
	~MenuHelp() override;
	const char* getName() const override { return "state_help"; };
	bool allowBg() const override { return true; }

	void drawOn(SDL_Surface* screen) override;
};

#endif
