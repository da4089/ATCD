// $Id$
// -*- C++ -*-

#if !defined (QUOTER_CLIENT_H)
#define QUOTER_CLIENT_H

// ============================================================================
//
// = LIBRARY
//    TAO/tests/Quoter
//
// = FILENAME
//    quoter_client.h
//
// = DESCRIPTION
//    @@@ Write this
//
// = AUTHORS
//    Darrell Brunsch
//
// ============================================================================

#include "ace/Get_Opt.h"
#include "ace/Task.h"
#include "ace/Thread_Manager.h"
#include "tao/corba.h"
#include "quoterC.h"

class Quoter_Client
{
  // = TITLE
  //    @@@ Write this
  //
  // = DESCRIPTION
  //    @@@ Write this
public:
  // = Constructor and destructor.
  Quoter_Client (void);
  ~Quoter_Client (void);

  int run (void);
  // Execute client example code.

  int init (int argc, char **argv);
  // Initialize the client communication endpoint with server.

private:
  int init_naming_service (void);
  // Function to initialize the naming service.

  int read_ior (char *filename);
  // Function to read the Quoter factory ior from a file.

  int parse_args (void);
  // Parses the arguments passed on the command line.

  int argc_;
  // # of arguments on the command line.

  char **argv_;
  // arguments from command line.

  char *quoter_factory_key_;
  // Key of factory obj ref.

  char *quoter_key_;
  // Key of the obj ref to be retrieved via the factory.

  int shutdown_;
  // Flag to tell server to shutdown.

  Stock::Quoter_Factory_var factory_;
  // factory pointer for cubit.

  CORBA::Environment env_;
  // Environment variable.

  Stock::Quoter_ptr quoter_;
  // Quoter obj ref.

  CORBA::ORB_var orb_;
  // Remember our orb.

  FILE *quoter_factory_ior_file_;
  // File from which to obtain the IOR.

  ACE_HANDLE f_handle_;
  // File handle to read the IOR.

  int use_naming_service_;
  // Flag to tell client not to use Namingservice to find the cubit
  // Factory.
};

class Quoter_Task : public ACE_Task<ACE_SYNCH>
{
public:
  Quoter_Task (int argc, char **argv);

  virtual int svc (void);

private:
  Quoter_Client quoter_client;
  int argc_;
  char **argv_;
};

#endif /* QUOTER_CLIENT_H */