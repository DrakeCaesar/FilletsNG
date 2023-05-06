#ifndef HEADER_OPTIONSINPUT_H
#define HEADER_OPTIONSINPUT_H

class MenuOptions;

#include "StateInput.h"

/**
 * Handle input for options menu.
 */
class OptionsInput : public StateInput
{
private:
	MenuOptions* getMenu();

protected:
	void enableMenu() override;

public:
	OptionsInput(MenuOptions* menu);

	void mouseEvent(const MouseStroke& buttons) override;
};

#endif
