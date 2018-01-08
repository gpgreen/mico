/*
 * A simple "Hello World" example that uses the POA
 */

#include "hello.h"
#ifdef HAVE_ANSI_CPLUSPLUS_HEADERS
#include <fstream>
#else
#include <fstream.h>
#endif
#include <unistd.h>

using namespace std;

/*
 * Hello World implementation inherits the POA skeleton class
 */

class HelloWorld_impl : virtual public POA_HelloWorld
{
public:
  void hello ();
  void hello_with_timeout(CORBA::Long sec);
};

void
HelloWorld_impl::hello ()
{
  cout << "Hello World" << endl;
}

void
HelloWorld_impl::hello_with_timeout(CORBA::Long sec)
{
#ifndef WIN32
  assert(sleep(sec) == 0);
#else // WIN32
  Sleep(sec * 1000);
#endif // WIN32
  cout << "Hello " << sec << " seconds sleeping world" << endl;
}

int
main (int argc, char *argv[])
{
  /*
   * Initialize the ORB
   */

  CORBA::ORB_var orb = CORBA::ORB_init (argc, argv);

  /*
   * Obtain a reference to the RootPOA and its Manager
   */

  CORBA::Object_var poaobj = orb->resolve_initial_references ("RootPOA");
  PortableServer::POA_var poa = PortableServer::POA::_narrow (poaobj);
  PortableServer::POAManager_var mgr = poa->the_POAManager();

  /*
   * Create a Hello World object
   */

  HelloWorld_impl * hello = new HelloWorld_impl;

  /*
   * Activate the Servant
   */

  PortableServer::ObjectId_var oid = poa->activate_object (hello);

  /*
   * Write reference to file
   */

  ofstream of ("hello.ref");
  CORBA::Object_var ref = poa->id_to_reference (oid.in());
  CORBA::String_var str = orb->object_to_string (ref.in());
  of << str.in() << endl;
  of.close ();

  /*
   * Activate the POA and start serving requests
   */

  cout << "Running." << endl;

  mgr->activate ();
  orb->run();

  /*
   * Shutdown (never reached)
   */

  poa->destroy (TRUE, TRUE);
  delete hello;

  return 0;
}
