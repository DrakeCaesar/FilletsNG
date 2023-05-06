#ifndef HEADER_WORLDMAP_H
#define HEADER_WORLDMAP_H

class Path;
class Level;
class LevelNode;
class NodeDrawer;
class ResDialogPack;
class LevelDesc;
class LevelStatus;
class LayeredPicture;

#include "Drawable.h"
#include "GameState.h"
#include "DescFinder.h"
#include "V2.h"

/**
 * Map with path from one level to another.
 */
class WorldMap : public GameState, public DescFinder, public Drawable
{
private:
	V2 m_lastMouseLoc;
	LevelNode* m_startNode;
	LevelNode* m_selected;
	LevelNode* m_ending;
	NodeDrawer* m_drawer;
	ResDialogPack* m_descPack;
	LevelStatus* m_levelStatus;

	LayeredPicture* m_bg;
	Uint32 m_activeMask;
	Uint32 m_maskIntro;
	Uint32 m_maskExit;
	Uint32 m_maskCredits;
	Uint32 m_maskOptions;

private:
	void prepareBg();
	void watchCursor();
	Level* createSelected() const;
	void markSolved();
	bool checkEnding() const;

	void runIntro();
	void runCredits();
	void runOptions();

protected:
	void own_initState() override;
	void own_updateState() override;

	void own_pauseState() override
	{
	}

	void own_resumeState() override;
	void own_cleanState() override;

public:
	WorldMap();
	~WorldMap() override;
	const char* getName() const override { return "state_worldmap"; };
	void initMap(const Path& mapfile);

	void drawOn(SDL_Surface* screen) override;
	void selectNextLevel();
	void runSelected();

	void addDesc(const std::string& codename, LevelDesc* desc);
	std::string findLevelName(const std::string& codename) const override;
	std::string findDesc(const std::string& codename) const override;
};

#endif
