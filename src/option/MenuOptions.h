#ifndef HEADER_MENUOPTIONS_H
#define HEADER_MENUOPTIONS_H

class Picture;
class MouseStroke;
class IWidget;
class WiStatusBar;
class Labels;

#include "GameState.h"
#include "Drawable.h"

/**
 * Options menu which allow to set lang and tune volume.
 */
class MenuOptions : public GameState, public Drawable
{
private:
	IWidget* m_container;
	WiStatusBar* m_statusBar;
	bool m_needRefresh;

private:
	void prepareMenu();
	IWidget* createSoundPanel(const Labels& labels);
	IWidget* createMusicPanel(const Labels& labels);
	IWidget* createLangPanel(const Labels& labels);
	IWidget* createSpeechPanel(const Labels& labels);
	IWidget* createSubtitlesPanel(const Labels& labels);
	IWidget* createBackButton(const Labels& labels);
	WiStatusBar* createStatusBar(int width);

protected:
	void own_initState() override;
	void own_updateState() override;

	void own_pauseState() override
	{
	}

	void own_resumeState() override;

	void own_cleanState() override
	{
	}

public:
	MenuOptions();
	~MenuOptions() override;
	const char* getName() const override { return "state_options"; };
	bool allowBg() const override { return true; }

	void mouseButton(const MouseStroke& stroke);
	void drawOn(SDL_Surface* screen) override;

	void receiveString(const StringMsg* msg) override;
};

#endif
