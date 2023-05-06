#ifndef HEADER_INPUTAGENT_H
#define HEADER_INPUTAGENT_H

class KeyBinder;
class InputHandler;

#include "BaseAgent.h"
#include "Name.h"
#include "V2.h"

#include "SDL2/SDL.h"

/**
 * Forward input events to handlers.
 */
class InputAgent : public BaseAgent
{
	AGENT(InputAgent, Name::INPUT_NAME);

private:
	Uint8* m_keys;
	KeyBinder* m_keyBinder;
	InputHandler* m_handler;

private:
	V2 getMouseState(Uint8* out_buttons);

protected:
	void own_init() override;
	void own_update() override;
	void own_shutdown() override;

public:
	void installHandler(InputHandler* handler);

	KeyBinder* keyBinder() { return m_keyBinder; }
};

#endif
