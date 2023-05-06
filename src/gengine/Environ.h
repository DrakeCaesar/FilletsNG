#ifndef HEADER_ENVIRON_H
#define HEADER_ENVIRON_H

class Path;
class BaseMsg;

#include "NoCopy.h"

#include <string>
#include <map>

/**
 * Params.
 */
class Environ : public NoCopy
{
private:
	using t_values = std::map<std::string, std::string>;
	using t_watchers = std::multimap<std::string, BaseMsg*>;
	t_values m_values;
	t_watchers m_watchers;

public:
	~Environ() override;
	void store(const Path& file);

	void setParam(const std::string& name, const std::string& value);
	void setParam(const std::string& name, long value);

	std::string getParam(const std::string& name,
	                     const std::string& implicit = "") const;
	int getAsInt(const std::string& name,
	             int implicit = 0) const;
	bool getAsBool(const std::string& name,
	               bool implicit = false) const;

	void addWatcher(const std::string& name, BaseMsg* msg);
	void removeWatchers(const std::string& listenerName);
	std::string toString() const;
	std::string getHelpInfo() const;
};

#endif
