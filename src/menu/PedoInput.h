#ifndef HEADER_PEDOINPUT_H
#define HEADER_PEDOINPUT_H

class Keymap;
class Pedometer;

#include "GameInput.h"

/**
 * Handle input for pedometer.
 */
class PedoInput : public GameInput
{
private:
	Pedometer* getPedo();

protected:
	void enableSubtitles() override
	{
	}

	void enableHelp() override
	{
	}

public:
	PedoInput(Pedometer* pedometer);

	void mouseEvent(const MouseStroke& buttons) override;
};

#endif
