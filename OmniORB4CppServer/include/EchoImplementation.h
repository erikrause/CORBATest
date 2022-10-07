#pragma once

#include "echo.hh";

class EchoImplementation : public POA_CORBATest::Echo
{
public:

	inline EchoImplementation() {};
	virtual ~EchoImplementation() {};
	virtual char* echoString(const char* mesg);
	virtual char* echoReversedString(const char* msg);
};