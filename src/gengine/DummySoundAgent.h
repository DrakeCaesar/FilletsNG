#ifndef HEADER_DUMMYSOUNDAGENT_H
#define HEADER_DUMMYSOUNDAGENT_H

#include "SoundAgent.h"

/**
 * NO sound and music.
 */
class DummySoundAgent : public SoundAgent
{
protected:
	void setSoundVolume(int) override
	{
	}

	void setMusicVolume(int) override
	{
	}

public:
	int playSound(Mix_Chunk*, int /*volume*/, int /*loops*/) override
	{
		return -1;
	}

	void playMusic(const Path&,
	               BaseMsg* finished) override
	{
		if (finished)
		{
			delete finished;
		}
	}

	void stopMusic() override
	{
	}
};

#endif
