#ifndef HEADER_DEMOINPUT_H
#define HEADER_DEMOINPUT_H

class GameState;

#include "GameInput.h"

/**
 * Handle input for demo.
 */
class DemoInput : public GameInput
{
protected:
	void enableHelp() override
	{
	}

public:
	DemoInput(GameState* demo);

	void mouseEvent(const MouseStroke& buttons) override;
};

#endif
