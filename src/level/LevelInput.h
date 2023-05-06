#ifndef HEADER_LEVELINPUT_H
#define HEADER_LEVELINPUT_H

class Level;
class Keymap;
class KeyStroke;

#include "GameInput.h"

/**
 * Handle input for level.
 */
class LevelInput : public GameInput
{
private:
	static const int KEY_SWITCH = 101;
	static const int KEY_SAVE = 102;
	static const int KEY_LOAD = 103;
	static const int KEY_RESTART = 104;
	static const int KEY_UNDO = 105;
	static const int KEY_REDO = 106;
	static const int KEY_SHOW_STEPS = 107;

private:
	Level* getLevel();

protected:
	void specKey(int keyIndex) override;
	void specStroke(const KeyStroke& stroke) override;

public:
	LevelInput(Level* level);
	void mouseEvent(const MouseStroke& buttons) override;
	void keyUp(const KeyStroke& stroke) override;
};

#endif
