#pragma once

#include "echo.hh";

class EchoImplementation : public POA_CORBATest::Echo
{
public:

	inline EchoImplementation() {};
	virtual ~EchoImplementation() {};
	virtual void reverseString(::CORBATest::PersonSeq& persons);
};