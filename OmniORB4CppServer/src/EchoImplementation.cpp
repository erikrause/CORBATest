#include "EchoImplementation.h"
#include <algorithm>

char* EchoImplementation::echoString(const char* mesg)
{
	return CORBA::string_dup(mesg);
}

char* EchoImplementation::echoReversedString(const char* mesg)
{
	char* duplicateMesg = CORBA::string_dup(mesg);
	std::reverse(duplicateMesg, duplicateMesg + std::strlen(duplicateMesg));
	return duplicateMesg;
}