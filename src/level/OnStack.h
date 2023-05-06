#ifndef HEADER_ONSTACK_H
#define HEADER_ONSTACK_H

#include "OnCondition.h"
#include "Cube.h"
#include "Rules.h"

/**
 * Test whether object can carry moved stack.
 */
class OnStack : public OnCondition
{
public:
	bool isSatisfy(Cube* model) const override
	{
		bool result = false;
		if (!model->isAlive())
		{
			if (model->rules()->getDir() == Dir::DIR_NO
				&& model->rules()->isOnStrongPad(Cube::LIGHT))
			{
				result = true;
			}
		}
		return result;
	}

	bool isWrong(Cube* model) const override
	{
		return model->isAlive();
	}
};

#endif
