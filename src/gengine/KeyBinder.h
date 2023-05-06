#ifndef HEADER_KEYBINDER_H
#define HEADER_KEYBINDER_H

class BaseMsg;

#include "NoCopy.h"
#include "KeyStroke.h"

#include <map>

/**
 * Key binder.
 */
class KeyBinder : public NoCopy
{
private:
	using t_strokes = std::map<KeyStroke, BaseMsg*, stroke_less>;
	t_strokes m_strokes;

public:
	~KeyBinder() override;

	void addStroke(const KeyStroke& stroke, BaseMsg* msg);
	void removeStroke(const KeyStroke& stroke);

	void keyDown(const SDL_Keysym& keysym) const;
};

#endif
