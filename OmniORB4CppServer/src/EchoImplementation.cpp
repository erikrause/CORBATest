#include "EchoImplementation.h"
#include <algorithm>


void EchoImplementation::reverseString(::CORBATest::PersonSeq& persons)
{
	for (long i = 0; i < persons.length(); i++)
	{
		CORBATest::Person* currentPerson = &persons[i];
		char* strings[3] = { currentPerson->Name, currentPerson->Surename, currentPerson->Patronymic };

		for (char* str : strings)
		{
			std::reverse(str, str + std::strlen(str));
		}
	}
}