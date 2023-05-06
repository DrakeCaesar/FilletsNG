#ifndef HEADER_RESSOUNDPACK_H
#define HEADER_RESSOUNDPACK_H

class Path;

#include "ResourcePack.h"

#include "SDL2/SDL_mixer.h"

/**
 * Sound resources.
 */
class ResSoundPack : public ResourcePack<Mix_Chunk*>
{
public:
	const char* getName() const override { return "sound_pack"; }

	static Mix_Chunk* loadSound(const Path& file);
	void addSound(const std::string& name, const Path& file);
	void unloadRes(Mix_Chunk* res) override;
};

#endif
