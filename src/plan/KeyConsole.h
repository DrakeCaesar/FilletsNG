#ifndef HEADER_KEYCONSOLE_H
#define HEADER_KEYCONSOLE_H

class Font;

#include "GameState.h"
#include "Drawable.h"
#include "Color.h"

#include <string>
#include "SDL2/SDL.h"

/**
 * Debug console.
 */
class KeyConsole : public GameState, public Drawable
{
private:
	Font* m_font;
	Color m_color;
	std::string m_input;

protected:
	void own_initState() override
	{
	};

	void own_updateState() override
	{
	};

	void own_pauseState() override
	{
	};

	void own_resumeState() override
	{
	};

	void own_cleanState() override
	{
	};

public:
	KeyConsole();
	~KeyConsole() override;
	const char* getName() const override { return "state_console"; };
	bool allowBg() const override { return true; }

	void setInput(const std::string& input) { m_input = input; }
	std::string getInput() const { return m_input; }

	bool sendCommand();
	void drawOn(SDL_Surface* screen) override;
};

#endif
