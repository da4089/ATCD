// -*- C++ -*-

//=============================================================================
/**
 *  @file   Portable_Group_Map.h
 *
 *  $Id$
 *
 *  @author Frank Hunleth <fhunleth@cs.wustl.edu>
 */
//=============================================================================

#ifndef TAO_PORTABLE_GROUP_MAP_H
#define TAO_PORTABLE_GROUP_MAP_H
#include "ace/pre.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Hash_Map_Manager_T.h"
#include "orbsvcs/PortableGroupC.h"
#include "tao/Object_KeyC.h"

class TAO_PortableGroup_Export TAO_GroupId_Hash
{
  // = TITLE
  //     Hashing class for Group Ids.
  //
  // = DESCRIPTION
  //     Define the hash() method for Group Ids.
public:

  u_long operator () (const PortableGroup::TagGroupTaggedComponent *id) const;
  // Returns hash value.
};

class TAO_PortableGroup_Export TAO_GroupId_Equal_To
{
  // = TITLE
  //     Hashing class for Group Ids.
  //
  // = DESCRIPTION
  //     Define the Equal_To () method for Object Ids.
public:

  int operator () (const PortableGroup::TagGroupTaggedComponent *lhs,
                   const PortableGroup::TagGroupTaggedComponent *rhs) const;
  // Returns 1 if equal.
};

class TAO_PortableGroup_Export TAO_Portable_Group_Map
{
  // = TITLE
  //     Map of GroupIds to ObjectKeys.
  //
  // = DESCRIPTION
public:

  struct Map_Entry
  {
    // = TITLE
    //     Value field of the portable group map.
    //
    // = DESCRIPTION

    /// The key.
    TAO_ObjectKey key;

    /// next ObjectKey in the group.
    struct Map_Entry *next;
  };

  /// Constructor.
  TAO_Portable_Group_Map ();

  /// Destructor.
  ~TAO_Portable_Group_Map (void);

  /// Add a GroupId->ObjectKey mapping to the map.
  /// This function takes ownership of the memory pointed to be group_id
  void add_groupid_objectkey_pair (PortableGroup::TagGroupTaggedComponent *group_id,
                                   const TAO_ObjectKey &key
                                   TAO_ENV_ARG_DECL);


  /// Remove a GroupId->ObjectKey mapping from the map.
  void remove_groupid_objectkey_pair (const PortableGroup::TagGroupTaggedComponent* group_id,
                                      const TAO_ObjectKey &key
                                      TAO_ENV_ARG_DECL);

  /// Dispatch a request to all of the ObjectIds that belong to
  /// the specified group.
  void dispatch (PortableGroup::TagGroupTaggedComponent* group_id,
                                    TAO_ORB_Core *orb_core,
                                    TAO_ServerRequest &request,
                                    CORBA::Object_out forward_to
                                    TAO_ENV_ARG_DECL);

  /// Id hash map.
  typedef ACE_Hash_Map_Manager_Ex<
    PortableGroup::TagGroupTaggedComponent *,
    Map_Entry *,
    TAO_GroupId_Hash,
    TAO_GroupId_Equal_To,
    ACE_Null_Mutex> GroupId_Table;
  typedef GroupId_Table::iterator Iterator;

protected:
  /// @@ Frank: This class will need a mutex to protect
  ///    this eventually...

  /// Id map.
  GroupId_Table map_;
};



//#if defined (__ACE_INLINE__)
//# include "Portable_Group_Map.i"
//#endif /* __ACE_INLINE__ */

#include "ace/post.h"
#endif /* TAO_PORTABLE_GROUP_MAP_H */
