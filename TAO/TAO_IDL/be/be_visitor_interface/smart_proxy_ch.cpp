//
// $Id$
//
// ============================================================================
//
// = LIBRARY
//    TAO IDL
//
// = FILENAME
//    smart_proxy_ch.cpp
//
// = DESCRIPTION
//    This provides code generation for smart proxy classes for an
//    interface in the client header.
//
// = AUTHOR
//    Kirthika Parameswaran  <kirthika@cs.wustl.edu>
//
// ============================================================================

#include	"idl.h"
#include	"idl_extern.h"
#include	"be.h"

#include "be_visitor_interface.h"

ACE_RCSID(be_visitor_interface, smart_proxy_ch, "$Id$")


// ************************************************************
//  smart proxy class in header
// ************************************************************


be_visitor_interface_smart_proxy_ch::be_visitor_interface_smart_proxy_ch
(be_visitor_context *ctx)
  : be_visitor_interface (ctx)
{
}

be_visitor_interface_smart_proxy_ch::~be_visitor_interface_smart_proxy_ch (void)
{
}

int be_visitor_interface_smart_proxy_ch::visit_interface (be_interface *node)
{
  TAO_OutStream *os = this->ctx_->stream ();

  // output the class defn
  
  *os << "class TAO_" << node->flat_name () 
      << "_Default_Proxy_Factory" << be_nl
      << "{" << be_nl
      << "public:" << be_idt_nl << be_nl
      << "TAO_" << node->flat_name () 
      << "_Default_Proxy_Factory (int register_proxy_factory = 1);" 
      << be_nl << be_nl
      << "virtual ~TAO_" << node->flat_name ()
      << "_Default_Proxy_Factory (void);" << be_nl << be_nl
      << "virtual "<< node->full_name () 
      << "_ptr create_proxy (" << be_idt << be_idt_nl 
      << node->full_name () << "_ptr proxy," << be_nl
      << "CORBA::Environment &env = " << be_idt_nl
      << "TAO_default_environment ()" << be_uidt << be_uidt_nl
      << ");" << be_uidt << be_uidt_nl
      << "};\n\n";
  
  *os << "class TAO_" << node->flat_name () 
      << "_Proxy_Factory_Adapter" << be_nl
      << "{" << be_nl
      << "public:" << be_idt_nl << be_nl
      << "friend class ACE_Singleton<TAO_" << node->flat_name () 
      << "_Proxy_Factory_Adapter, ACE_SYNCH_RECURSIVE_MUTEX>;" << be_nl << be_nl
      << "int register_proxy_factory (" << be_idt << be_idt_nl
      << "TAO_" << node->flat_name () << "_Default_Proxy_Factory *df,"<< be_nl 
      << "CORBA::Environment &env = " << be_idt_nl
      << "TAO_default_environment ()" << be_uidt << be_uidt_nl
      << ");" << be_uidt_nl << be_nl
      << "int unregister_proxy_factory (" << be_idt << be_idt_nl
      << "CORBA::Environment &env = " << be_idt_nl
      << "TAO_default_environment ()" << be_uidt << be_uidt_nl
      << ");" << be_uidt_nl << be_nl
      << node->full_name () << "_ptr create_proxy (" << be_idt << be_idt_nl 
      << node->full_name () << "_ptr proxy," << be_nl
      << "CORBA::Environment &env = " << be_idt_nl
      << "TAO_default_environment ()" << be_uidt << be_uidt_nl
      << ");" << be_uidt << be_uidt_nl << be_nl
      << "protected:" << be_idt_nl
      << "TAO_" << node->flat_name () 
      << "_Proxy_Factory_Adapter (void);" << be_nl
      << "~TAO_" << node->flat_name () 
      << "_Proxy_Factory_Adapter (void);" << be_nl
      << "TAO_" << node->flat_name () 
      << "_Proxy_Factory_Adapter &operator= (" << be_idt << be_idt_nl 
      << "const TAO_" << node->flat_name () 
      << "_Proxy_Factory_Adapter &" << be_uidt_nl 
      << ");" << be_uidt_nl
      << "TAO_" << node->flat_name () 
      << "_Default_Proxy_Factory *proxy_factory_;" << be_nl
      << "int delete_proxy_factory_;" << be_nl
      << "ACE_Recursive_Thread_Mutex lock_;"<<be_nl
      << "};\n\n";
  
  os->indent ();
  *os << "typedef ACE_Singleton<TAO_"<<node->flat_name ()
      << "_Proxy_Factory_Adapter, ACE_SYNCH_RECURSIVE_MUTEX> TAO_"
      << node->flat_name ()<< "_PROXY_FACTORY_ADAPTER;"<<be_nl;
  
  *os << "class TAO_"<< node->flat_name () 
      << "_Smart_Proxy_Base : public virtual "<< node->full_name ()
      << be_nl
      << "{" << be_nl
      << "public:" << be_idt_nl
      << "TAO_"<< node->flat_name () << "_Smart_Proxy_Base ("
      << node->full_name () << "_ptr proxy);" << be_uidt_nl;
  
  // generate code for the interface definition by traversing thru the
  // elements of its scope. We depend on the front-end to have made sure
  // that only legal syntactic elements appear in our scope.
  
  os->indent ();
  if (this->visit_scope (node) == -1)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "(%N:%l) be_visitor_interface_ch::"
                         "visit_interface - "
                         "codegen for scope failed\n"), -1);
    }
  
  os->decr_indent ();  
  *os << "private:" << be_idt_nl
      << node->full_name () << "_var base_proxy_;" 
      << be_uidt_nl
      << "};\n\n";
  
  return 0;
}


