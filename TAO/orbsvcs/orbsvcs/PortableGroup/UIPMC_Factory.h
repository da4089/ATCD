// -*- C++ -*-

//=============================================================================
/**
 *  @file     UIPMC_Factory.h
 *
 *  $Id$
 *
 *  @author Frank Hunleth <fhunleth@cs.wustl.edu>
 */
//=============================================================================

#ifndef TAO_UIPMC_FACTORY_H
#define TAO_UIPMC_FACTORY_H
#include "ace/pre.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/Protocol_Factory.h"
#include "ace/Service_Config.h"
#include "portablegroup_export.h"

class TAO_Acceptor;
class TAO_Connector;

class TAO_PortableGroup_Export TAO_UIPMC_Protocol_Factory : public TAO_Protocol_Factory
{
public:
  TAO_UIPMC_Protocol_Factory (void);
  virtual ~TAO_UIPMC_Protocol_Factory (void);

  // = Service Configurator hooks.
  /// Dynamic linking hook
  virtual int init (int argc, char* argv[]);

  /// Verify prefix is a match
  virtual int match_prefix (const ACE_CString &prefix);

  /// Returns the prefix used by the protocol.
  virtual const char *prefix (void) const;

  /// Return the character used to mark where an endpoint ends and
  /// where its options begin.
  virtual char options_delimiter (void) const;

  // = Check Protocol_Factory.h for a description of these methods.
  virtual TAO_Acceptor  *make_acceptor (void);
  virtual TAO_Connector *make_connector  (void);
  virtual int requires_explicit_endpoint (void) const;

private:
  /// Changing the version number can be used to provide backwards
  /// compatibility with old clients.
  int major_;
  int minor_;
};

ACE_STATIC_SVC_DECLARE (TAO_UIPMC_Protocol_Factory)
ACE_FACTORY_DECLARE (TAO_PortableGroup, TAO_UIPMC_Protocol_Factory)

#include "ace/post.h"
#endif /* TAO_UIPMC_FACTORY_H */
