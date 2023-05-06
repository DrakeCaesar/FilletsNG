#ifndef HEADER_BASEEXCEPTION_H
#define HEADER_BASEEXCEPTION_H

#include "ExInfo.h"

#include <stdexcept>

/**
 * Generic exception.
 */
class BaseException : public std::exception
{
private:
	ExInfo m_info;

public:
	explicit BaseException(const ExInfo& exinfo);

	~BaseException() throw() override
	{
	}

	const char* what() const throw() override;
	virtual const ExInfo& info() const throw();
};

#endif
