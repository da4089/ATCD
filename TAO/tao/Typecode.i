// -*- C++ -*-
//
// $Id$

ACE_INLINE CORBA::ULong
CORBA::TypeCode::_incr_refcnt (void)
{
  ACE_GUARD_RETURN (TAO_SYNCH_MUTEX, guard, this->refcount_lock_, 0);
  return this->refcount_++;
}

ACE_INLINE CORBA::ULong
CORBA::TypeCode::_decr_refcnt (void)
{
  {
    ACE_GUARD_RETURN (TAO_SYNCH_MUTEX, guard, this->refcount_lock_, 0);
    this->refcount_--;
    if (this->refcount_ != 0)
      return this->refcount_;
  }
  delete this;
  return 0;
}

ACE_INLINE CORBA::TypeCode_ptr
CORBA::TypeCode::_duplicate (CORBA::TypeCode_ptr tc)
{
  if (tc)
    tc->_incr_refcnt ();
  return tc;
}

ACE_INLINE CORBA::TypeCode_ptr
CORBA::TypeCode::_nil (void)
{
  return (CORBA::TypeCode_ptr)0;
}

ACE_INLINE CORBA::TCKind
CORBA::TypeCode::kind (ACE_ENV_SINGLE_ARG_DECL_NOT_USED) const
{
  return (CORBA::TCKind) this->kind_;
}

// Returns true if the two typecodes are equivalent.
ACE_INLINE CORBA::Boolean
CORBA::TypeCode::equivalent (CORBA::TypeCode_ptr tc
                            ACE_ENV_ARG_DECL) const
{
  return this->equ_common (tc,
                           1
                            ACE_ENV_ARG_PARAMETER);
}

// Returns true if the two typecodes are identical.
ACE_INLINE CORBA::Boolean
CORBA::TypeCode::equal (CORBA::TypeCode_ptr tc
                       ACE_ENV_ARG_DECL) const
{
  return this->equ_common (tc,
                           0
                            ACE_ENV_ARG_PARAMETER);
}

// returns the Repository ID
ACE_INLINE const char *
CORBA::TypeCode::id (ACE_ENV_SINGLE_ARG_DECL) const
{
  // if already precomputed
  if (this->private_state_->tc_id_known_)
    return this->private_state_->tc_id_;
  else
    return this->private_id (ACE_ENV_SINGLE_ARG_PARAMETER);
}

// returns the string name
ACE_INLINE const char *
CORBA::TypeCode::name (ACE_ENV_SINGLE_ARG_DECL) const
{
  // if already precomputed
  if (this->private_state_->tc_name_known_)
    return this->private_state_->tc_name_;
  else
    return this->private_name (ACE_ENV_SINGLE_ARG_PARAMETER);
}

// Return the number of members defined by this typecode
//
// Applicable to struct, union, enum, alias, and except
// For the rest of the cases, raises the BadKind exception.

ACE_INLINE CORBA::ULong
CORBA::TypeCode::member_count (ACE_ENV_SINGLE_ARG_DECL) const
{
  // if already precomputed
  if (this->private_state_->tc_member_count_known_)
    return this->private_state_->tc_member_count_;
  else
    return this->private_member_count (ACE_ENV_SINGLE_ARG_PARAMETER);
}

// ************************************************************
// These are in CORBA namespace

ACE_INLINE CORBA::Boolean
CORBA::is_nil (CORBA::TypeCode_ptr obj)
{
  return obj == 0;
}

ACE_INLINE void
CORBA::release (CORBA::TypeCode_ptr obj)
{
  if (obj)
    obj->_decr_refcnt ();
}

// ****************************************************************

ACE_INLINE
CORBA::TypeCode_var::TypeCode_var (void)
  : ptr_ (CORBA::TypeCode::_nil ())
{}

ACE_INLINE
CORBA::TypeCode_var::TypeCode_var (CORBA::TypeCode_ptr p)
  : ptr_ (p)
{}

ACE_INLINE CORBA::TypeCode_ptr
CORBA::TypeCode_var::ptr (void) const
{
  return this->ptr_;
}

ACE_INLINE
CORBA::TypeCode_var::TypeCode_var (const CORBA::TypeCode_var &p)
  : ptr_ (CORBA::TypeCode::_duplicate (p.ptr ()))
{}

ACE_INLINE
CORBA::TypeCode_var::~TypeCode_var (void)
{
  CORBA::release (this->ptr_);
}

ACE_INLINE CORBA::TypeCode_var &
CORBA::TypeCode_var::operator= (CORBA::TypeCode_ptr p)
{
  CORBA::release (this->ptr_);
  this->ptr_ = p;
  return *this;
}

ACE_INLINE CORBA::TypeCode_var &
CORBA::TypeCode_var::operator= (const CORBA::TypeCode_var &p)
{
  if (this != &p)
    {
      CORBA::release (this->ptr_);
      this->ptr_ = CORBA::TypeCode::_duplicate (p.ptr ());
    }
  return *this;
}

ACE_INLINE
CORBA::TypeCode_var::operator const CORBA::TypeCode_ptr &() const
{
  return this->ptr_;
}

ACE_INLINE
CORBA::TypeCode_var::operator CORBA::TypeCode_ptr &()
{
  return this->ptr_;
}

ACE_INLINE CORBA::TypeCode_ptr
CORBA::TypeCode_var::operator-> (void) const
{
  return this->ptr_;
}

ACE_INLINE CORBA::TypeCode_ptr
CORBA::TypeCode_var::in (void) const
{
  return this->ptr_;
}

ACE_INLINE CORBA::TypeCode_ptr &
CORBA::TypeCode_var::inout (void)
{
  return this->ptr_;
}

ACE_INLINE CORBA::TypeCode_ptr &
CORBA::TypeCode_var::out (void)
{
  CORBA::release (this->ptr_);
  this->ptr_ = CORBA::TypeCode::_nil ();
  return this->ptr_;
}

ACE_INLINE CORBA::TypeCode_ptr
CORBA::TypeCode_var::_retn (void)
{
  // yield ownership of managed obj reference
  CORBA::TypeCode_ptr val = this->ptr_;
  this->ptr_ = CORBA::TypeCode::_nil ();
  return val;
}

// *************************************************************
// Inline operations for class CORBA::TypeCode_out
// *************************************************************

ACE_INLINE
CORBA::TypeCode_out::TypeCode_out (CORBA::TypeCode_ptr &p)
  : ptr_ (p)
{
  this->ptr_ = CORBA::TypeCode::_nil ();
}

ACE_INLINE
CORBA::TypeCode_out::TypeCode_out (CORBA::TypeCode_var &p)
  : ptr_ (p.out ())
{
  CORBA::release (this->ptr_);
  this->ptr_ = CORBA::TypeCode::_nil ();
}

ACE_INLINE
CORBA::TypeCode_out::TypeCode_out (const CORBA::TypeCode_out &p)
  : ptr_ (p.ptr_)
{}

ACE_INLINE CORBA::TypeCode_out &
CORBA::TypeCode_out::operator= (const CORBA::TypeCode_out &p)
{
  this->ptr_ = p.ptr_;
  return *this;
}

ACE_INLINE CORBA::TypeCode_out &
CORBA::TypeCode_out::operator= (CORBA::TypeCode_ptr p)
{
  this->ptr_ = p;
  return *this;
}

ACE_INLINE
CORBA::TypeCode_out::operator CORBA::TypeCode_ptr &()
{
  return this->ptr_;
}

ACE_INLINE CORBA::TypeCode_ptr &
CORBA::TypeCode_out::ptr (void)
{
  return this->ptr_;
}

ACE_INLINE CORBA::TypeCode_ptr
CORBA::TypeCode_out::operator-> (void)
{
  return this->ptr_;
}
