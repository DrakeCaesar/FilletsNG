#ifndef HEADER_APPLICATION_H
#define HEADER_APPLICATION_H
extern int tick;
extern int speedup;
extern int offset;
extern int skip;
extern bool movingfish;
class AgentPack;

#include "NoCopy.h"
#include "BaseListener.h"
#include "Name.h"

/**
 * Main application
 */
class Application : public NoCopy, public BaseListener
{
private:
	AgentPack* m_agents;
	bool m_quit;

private:
	void prepareLogLevel();
	void prepareOptions(int argc, char* argv[]);
	void customizeGame();
	void addSoundAgent();

public:
	Application();
	~Application() override;
	const char* getName() const override { return Name::APP_NAME; }

	void init(int argc, char* argv[]);
	void run();
	void shutdown();

	void receiveSimple(const SimpleMsg* msg) override;
	void receiveString(const StringMsg* msg) override;
};

#endif
