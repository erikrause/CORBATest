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

	CORBA::String_var src = (const char*)"Hello!";
	CORBA::String_var dest;

	dest = e->echoString(src);

	std::cout << "Testing echoString: I said,\"" << src << "\"."
		<< " The Server said,\"" << dest << "\"" << std::endl;

	dest = e->echoReversedString(src);

	std::cout << "Testing echoReversedString: I said,\"" << src << "\"."
		<< " The Server said,\"" << dest << "\"" << std::endl;
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