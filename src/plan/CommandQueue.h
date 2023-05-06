#ifndef HEADER_COMMANDQUEUE_H
#define HEADER_COMMANDQUEUE_H

class Command;

#include "NoCopy.h"

#include <deque>

/**
 * Queue for sequential commands.
 */
class CommandQueue : public NoCopy
{
private:
	using t_commands = std::deque<Command*>;
	t_commands m_commands;
	int m_count;

public:
	CommandQueue();
	~CommandQueue() override;

	void planCommand(Command* new_command);
	bool executeFirst();
	void removeAll();
	bool empty() const { return m_commands.empty(); }
};

#endif
