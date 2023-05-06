#ifndef HEADER_SDLSOUNDAGENT_H
#define HEADER_SDLSOUNDAGENT_H

#include "SoundAgent.h"
#include "SDLMusicLooper.h"

#include "SDL2/SDL.h"
#include "SDL2/SDL_mixer.h"
#include <string>

/**
 * Sound and music.
 */
class SDLSoundAgent : public SoundAgent
{
private:
	static BaseMsg* ms_finished;
	Mix_Music* m_music;
	SDLMusicLooper* m_looper;
	std::string m_playingPath;
	int m_soundVolume;
	int m_musicVolume;

private:
	std::string generateIdName(const Path& file);
	Mix_Chunk* findChunk(const std::string& name);

	static void musicFinished();

protected:
	void own_init() override;
	void own_shutdown() override;
	void reinit() override;

	void setSoundVolume(int volume) override;
	void setMusicVolume(int volume) override;

public:
	int playSound(Mix_Chunk* sound, int volume, int loops = 0) override;

	void playMusic(const Path& file,
	               BaseMsg* finished) override;
	void stopMusic() override;
};

#endif
