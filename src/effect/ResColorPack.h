#ifndef HEADER_RESCOLORPACK_H
#define HEADER_RESCOLORPACK_H

#include "ResourcePack.h"
#include "Color.h"

/**
 * Pack of color aliases.
 */
class ResColorPack : public ResourcePack<Color*>
{
public:
	const char* getName() const override { return "color_pack"; }
	void unloadRes(Color* res) override { delete res; }
};

#endif
