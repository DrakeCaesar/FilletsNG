#ifndef HEADER_ONWALL_H
#define HEADER_ONWALL_H

#include "OnCondition.h"
#include "Cube.h"

/**
 * Test whether model is on Wall.
 */
class OnWall : public OnCondition
{
public:
	bool isSatisfy(Cube* model) const override
	{
		return model->isWall();
	}

	bool isWrong(Cube* model) const override
	{
		return model->isAlive();
	}
};

#endif
