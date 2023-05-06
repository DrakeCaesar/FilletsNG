#ifndef HEADER_INTMSG_H
#define HEADER_INTMSG_H

#include "BaseMsg.h"
#include "BaseListener.h"

/**
 * Message with integer value.
 */
class IntMsg : public BaseMsg
{
private:
	int m_value;

public:
	CLONE(IntMsg);

	IntMsg(BaseListener* listener, const std::string& name,
	       int value)
		: BaseMsg(listener->getName(), name), m_value(value)
	{
	}

	IntMsg(const std::string& listenerName, const std::string& name,
	       int value)
		: BaseMsg(listenerName, name), m_value(value)
	{
	}

	void sendActual(BaseListener* listener) const override
	{
		listener->receiveInt(this);
	}

	int getValue() const { return m_value; }
	std::string toString() const override;
};


#endif
