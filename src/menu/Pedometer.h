#ifndef HEADER_PEDOMETER_H
#define HEADER_PEDOMETER_H

class Level;
class LevelStatus;
class LayeredPicture;
class Picture;

#include "Drawable.h"
#include "GameState.h"

#include "SDL2/SDL.h"
#include <string>

/**
 * Pedometer with tree buttons.
 */
class Pedometer : public GameState, public Drawable
{
private:
	Picture* m_bg;
	LayeredPicture* m_rack;
	SDL_Surface* m_numbers;
	LevelStatus* m_status;
	Level* m_level;
	Uint32 m_activeMask;
	Uint32 m_maskRun;
	Uint32 m_maskReplay;
	Uint32 m_maskCancel;
	std::string m_solution;
	int m_meterPhase;

private:
	void prepareBg();
	void prepareRack();

	void watchCursor();
	void runLevel();
	void runReplay();

	void drawNumbers(SDL_Surface* screen, int value);
	void drawNumber(SDL_Surface* screen, int x, int y, int shiftY);

protected:
	void own_initState() override;
	void own_updateState() override;

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
	Pedometer(LevelStatus* status, Level* level);
	~Pedometer() override;
	const char* getName() const override { return "state_pedometer"; };

	void runSelected();
	void drawOn(SDL_Surface* screen) override;
	void receiveString(const StringMsg* msg) override;
};

#endif
