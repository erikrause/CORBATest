#include <omniORB4/CORBA.h>
#include "echo.hh";
#include <iostream>

void hello(CORBA::Object_ptr obj)
{
	CORBATest::Echo_var e = CORBATest::Echo::_narrow(obj);

	if (CORBA::is_nil(e)) {
		std::cerr << "cannot invoke on a nil object reference." << std::endl;
		return;
	}


	// Initialization.
	unsigned long numPersons = 2;
	auto persons = new CORBATest::Person[numPersons];
	{
		persons[0].Name = "Иван";
		persons[0].Surename = "Иванов";
		persons[0].Patronymic = "Иванович";

		persons[1].Name = "Эркин";
		persons[1].Surename = "Камилов";
		persons[1].Patronymic = "Махмуджанович";
	}


	// RPC.
	CORBATest::PersonSeq_var personSeq = new CORBATest::PersonSeq(numPersons, numPersons, persons);
	e->reverseString(personSeq);


	// Output.
	setlocale(LC_ALL, "");
	{
		std::cout << "Testing reverse names: " << std::endl;

			for (unsigned int i = 0; i < personSeq->length(); i++)
			{
				CORBATest::Person currentPerson = personSeq[i];
				std::cout << currentPerson.Surename << " " << currentPerson.Name << " " << currentPerson.Patronymic << std::endl;
			}
	}
	std::getchar();
}


int main(int argc, char** argv)
{
	try
	{
		CORBA::ORB_var orb = CORBA::ORB_init(argc, argv);
		if (argc != 2) {
			std::cerr << "usage: eg2_clt <object reference>" << std::endl;
			return 1;
		}
		CORBA::Object_var obj = orb->string_to_object(argv[1]);
		CORBATest::Echo_var echoref = CORBATest::Echo::_narrow(obj);

		if (CORBA::is_nil(echoref)) {
			std::cerr << "Can’t narrow reference to type Echo (or it was nil)." << std::endl;
			return 1;
		}

		hello(echoref);
			
		orb->destroy();
	}
	catch (CORBA::TRANSIENT&) {
		std::cerr << "Caught system exception TRANSIENT -- unable to contact the "
			<< "server." << std::endl;
	}
	catch (CORBA::SystemException& ex) {
		std::cerr << "Caught a CORBA::" << ex._name() << std::endl;
	}
	catch (CORBA::Exception& ex) {
		std::cerr << "Caught CORBA::Exception: " << ex._name() << std::endl;
	}
}