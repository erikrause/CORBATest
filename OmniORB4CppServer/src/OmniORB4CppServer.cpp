#include <omniORB4/CORBA.h>
#include "EchoImplementation.h"
#include <iostream>


int main(int argc, char** argv)
{
	CORBA::ORB_var orb = CORBA::ORB_init(argc, argv);

	CORBA::Object_var obj = orb->resolve_initial_references("RootPOA");
	PortableServer::POA_var poa = PortableServer::POA::_narrow(obj);

	PortableServer::Servant_var<EchoImplementation> myecho = new EchoImplementation();

	PortableServer::ObjectId_var myechoid = poa->activate_object(myecho);

	obj = myecho->_this();
	CORBA::String_var sior(orb->object_to_string(obj));
	std::cerr << sior << std::endl;

	PortableServer::POAManager_var pman = poa->the_POAManager();
	pman->activate();

	orb->run();
	orb->destroy();


	CosNaming::NamingContext_var rootContext;

	CORBA::Object_var obj2 = orb->resolve_initial_references("NameService");
	// Narrow the reference returned.
	rootContext = CosNaming::NamingContext::_narrow(obj2);
	if (CORBA::is_nil(rootContext)) {
		std::cerr << "Failed to narrow the root naming context." << std::endl;
		return 0;
	}


	return 0;
}