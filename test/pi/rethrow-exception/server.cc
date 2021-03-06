
#include "bench.h"
#include <CORBA.h>
#include <fstream>


using namespace std;

CORBA::ORB_ptr orb = NULL;

class bench_impl
    : public virtual POA_bench
{
public:
    void
    perform()
    {
    }
};


class MyServerInterceptor
    : virtual public PortableInterceptor::ServerRequestInterceptor,
      virtual public CORBA::LocalObject
{
    string nm;
        
public:
    MyServerInterceptor()
    { nm = ""; }
    MyServerInterceptor(const char * name)
    { nm = name; }
        
    char*
    name()
    { return CORBA::string_dup(nm.c_str()); }

    void
    destroy()
    { cerr << this->name() << " destroy" << endl; }

    void
    receive_request_service_contexts(PortableInterceptor::ServerRequestInfo_ptr ri)
    {
	cout << this->name() << "::receive_request_service_contexts" << endl;
    }
    
    void
    receive_request(PortableInterceptor::ServerRequestInfo_ptr ri)
    {
	cout << this->name() << "::receive_request" << endl;
	if (nm == "MyServerInterceptor3")
	    throw 10;
    }
    
    void
    send_reply(PortableInterceptor::ServerRequestInfo_ptr ri)
    {
	cout << this->name() << "::send_reply" << endl;
    }
    
    void
    send_exception(PortableInterceptor::ServerRequestInfo_ptr ri)
    {
	cout << this->name() << "::send_exception: ";
	CORBA::Any* any = ri->sending_exception();
	cout << any->type()->id() << endl;
	if (nm == "MyServerInterceptor1")
	    throw CORBA::NO_PERMISSION();
	if (nm == "MyServerInterceptor2")
	    throw Exc();
//  	if (nm == "MyServerInterceptor3")
//  	    throw 10;
    }
    
    void
    send_other(PortableInterceptor::ServerRequestInfo_ptr ri)
    {
	cout << this->name() << "::send_other" << endl;
    }
        
};

class MyInitializer
    : virtual public PortableInterceptor::ORBInitializer,
      virtual public CORBA::LocalObject
{
public:
    MyInitializer()
    {}
    ~MyInitializer()
    {}

    virtual void
    pre_init(PortableInterceptor::ORBInitInfo_ptr info)
    {
        MyServerInterceptor* interceptor1 = new MyServerInterceptor("MyServerInterceptor1");
        info->add_server_request_interceptor(interceptor1);
	MyServerInterceptor* interceptor2 = new MyServerInterceptor("MyServerInterceptor2");
	info->add_server_request_interceptor(interceptor2);
	MyServerInterceptor* interceptor3 = new MyServerInterceptor("MyServerInterceptor3");
	info->add_server_request_interceptor(interceptor3);
    }
    
    virtual void
    post_init(PortableInterceptor::ORBInitInfo_ptr info)
    {}
};


int
main (int argc, char* argv[])
{
    //  cerr << "main thread: " << MICOMT::Thread::self() << endl;
    MyInitializer* ini = new MyInitializer;
    PortableInterceptor::register_orb_initializer(ini);
    orb = CORBA::ORB_init (argc, argv, "mico-local-orb");
    CORBA::Object_ptr obj = orb->resolve_initial_references ("RootPOA");
    PortableServer::POA_ptr poa = PortableServer::POA::_narrow (obj);
    CORBA::release (obj);

    bench_impl* servant = new bench_impl;

    poa->activate_object (servant);
    CORBA::Object_ptr ref = poa->servant_to_reference (servant);
  
    CORBA::String_var ior = orb->object_to_string (ref);
    ofstream out("ref");
    out << ior << endl;
    out.close();

    CORBA::release (ref);

    PortableServer::POAManager_ptr manager = poa->the_POAManager ();
    manager->activate ();

    orb->run ();

    CORBA::release (manager);
    CORBA::release (poa);
    CORBA::release (orb);

    return 0;
}
