#ifndef HEADER_HELPINPUT_H
#define HEADER_HELPINPUT_H

class GameState;

#include "StateInput.h"

/**
 * Handle input for help screen.
 */
class HelpInput : public StateInput
{
protected:
	void enableHelp() override { quitState(); }
	void enableMenu() override { quitState(); }
	void specStroke(const KeyStroke& stroke) override;

public:
	HelpInput(GameState* state);

	void mouseEvent(const MouseStroke& buttons) override;
};

#endif
