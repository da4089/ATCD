// -*- C++ -*-

//=============================================================================
/**
 *  @file    Services.h
 *
 *  $Id$
 *
 *  Service_Detail stubs. This code generated by the The ACE ORB (TAO) IDL
 *  Compiler and was then hand crafted
 */
//=============================================================================


#ifndef TAO_SERVICES_H
#define TAO_SERVICES_H
#include "ace/pre.h"

#include "tao/Sequence.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if defined(_MSC_VER)
#if (_MSC_VER >= 1200)
#pragma warning(push)
#endif /* _MSC_VER >= 1200 */
#pragma warning(disable:4250)
#endif /* _MSC_VER */

namespace CORBA
{
  /**
   * @class ServiceDetail
   *
   * @brief CORBA::ServiceDetail implementation.
   *
   * CORBA::ServiceDetail implementation.
   */
  struct TAO_Export ServiceDetail
  {
    static void _tao_any_destructor (void*);

    CORBA::ServiceDetailType service_detail_type;

#if !defined (_CORBA_SERVICEDETAIL__TAO_SEQ_OCTET_CH_)
#define _CORBA_SERVICEDETAIL__TAO_SEQ_OCTET_CH_

    // *************************************************************
    // _tao_seq_Octet
    // *************************************************************

    class  _tao_seq_Octet : public TAO_Unbounded_Sequence<CORBA::Octet>
    {
    public:
      _tao_seq_Octet (void); // default ctor
      _tao_seq_Octet (CORBA::ULong max); // uses max size
      _tao_seq_Octet (
                      CORBA::ULong max,
                      CORBA::ULong length,
                      CORBA::Octet *buffer,
                      CORBA::Boolean release=0
                      );
      _tao_seq_Octet (const _tao_seq_Octet &); // copy ctor
      virtual ~_tao_seq_Octet (void); // dtor

#if (TAO_NO_COPY_OCTET_SEQUENCES == 1)
      _tao_seq_Octet (
                      CORBA::ULong length,
                      const ACE_Message_Block* mb
                      )
        : TAO_Unbounded_Sequence<CORBA::Octet> (length, mb) {}
#endif /* TAO_NO_COPY_OCTET_SEQUENCE == 1 */
    };

    static CORBA::TypeCode_ptr _tc__tao_seq_Octet;
#endif /* end #if !defined */

#if !defined (_CORBA_SERVICEDETAIL__TAO_SEQ_OCTET___VAR_CH_)
#define _CORBA_SERVICEDETAIL__TAO_SEQ_OCTET___VAR_CH_

    // *************************************************************
    // class CORBA::ServiceDetail::_tao_seq_Octet_var
    // *************************************************************

    class  _tao_seq_Octet_var
    {
    public:
      _tao_seq_Octet_var (void); // default constructor
      _tao_seq_Octet_var (_tao_seq_Octet *);
      _tao_seq_Octet_var (const _tao_seq_Octet_var &); // copy constructor
      ~_tao_seq_Octet_var (void); // destructor

      _tao_seq_Octet_var &operator= (_tao_seq_Octet *);
      _tao_seq_Octet_var &operator= (const _tao_seq_Octet_var &);
      _tao_seq_Octet *operator-> (void);
      const _tao_seq_Octet *operator-> (void) const;

      operator const _tao_seq_Octet &() const;
      operator _tao_seq_Octet &();
      operator _tao_seq_Octet &() const;
      CORBA::Octet &operator[] (CORBA::ULong slot);
      // in, inout, out, _retn
      const _tao_seq_Octet &in (void) const;
      _tao_seq_Octet &inout (void);
      _tao_seq_Octet *&out (void);
      _tao_seq_Octet *_retn (void);
      _tao_seq_Octet *ptr (void) const;

    private:
      _tao_seq_Octet *ptr_;
    };

#endif /* end #if !defined */


#if !defined (_CORBA_SERVICEDETAIL__TAO_SEQ_OCTET___OUT_CH_)
#define _CORBA_SERVICEDETAIL__TAO_SEQ_OCTET___OUT_CH_

    class  _tao_seq_Octet_out
    {
    public:
      _tao_seq_Octet_out (_tao_seq_Octet *&);
      _tao_seq_Octet_out (_tao_seq_Octet_var &);
      _tao_seq_Octet_out (const _tao_seq_Octet_out &);
      _tao_seq_Octet_out &operator= (const _tao_seq_Octet_out &);
      _tao_seq_Octet_out &operator= (_tao_seq_Octet *);
      operator _tao_seq_Octet *&();
      _tao_seq_Octet *&ptr (void);
      _tao_seq_Octet *operator-> (void);
      CORBA::Octet &operator[] (CORBA::ULong slot);

    private:
      _tao_seq_Octet *&ptr_;
      // assignment from T_var not allowed
      void operator= (const _tao_seq_Octet_var &);
    };


#endif /* end #if !defined */

    _tao_seq_Octet service_detail;
  };

  class ServiceDetail_var
  {
  public:
    ServiceDetail_var (void); // default constructor
    ServiceDetail_var (ServiceDetail *);
    ServiceDetail_var (const ServiceDetail_var &); // copy constructor
    ~ServiceDetail_var (void); // destructor

    ServiceDetail_var &operator= (ServiceDetail *);
    ServiceDetail_var &operator= (const ServiceDetail_var &);
    ServiceDetail *operator-> (void);
    const ServiceDetail *operator-> (void) const;

    /// in, inout, out, _retn
    operator const ServiceDetail &() const;
    operator ServiceDetail &();
    operator ServiceDetail &() const;
    const ServiceDetail &in (void) const;
    ServiceDetail &inout (void);
    ServiceDetail *&out (void);
    ServiceDetail *_retn (void);
    ServiceDetail *ptr (void) const;

  private:
    ServiceDetail *ptr_;
  };

  class  ServiceDetail_out
  {
  public:
    ServiceDetail_out (ServiceDetail *&);
    ServiceDetail_out (ServiceDetail_var &);
    ServiceDetail_out (const ServiceDetail_out &);
    ServiceDetail_out &operator= (const ServiceDetail_out &);
    ServiceDetail_out &operator= (ServiceDetail *);
    operator ServiceDetail *&();
    ServiceDetail *&ptr (void);
    ServiceDetail *operator-> (void);

  private:
    /// assignment from T_var not allowed
    ServiceDetail *&ptr_;
    void operator= (const ServiceDetail_var &);
  };

  struct  ServiceInformation
  {
    static void _tao_any_destructor (void*);

#if !defined (TAO_USE_SEQUENCE_TEMPLATES)

#if !defined (__TAO_UNBOUNDED_SEQUENCE_CORBA_SERVICEINFORMATION__TAO_SEQ_SERVICEOPTION_CH_)
#define __TAO_UNBOUNDED_SEQUENCE_CORBA_SERVICEINFORMATION__TAO_SEQ_SERVICEOPTION_CH_

    class _TAO_Unbounded_Sequence_CORBA_ServiceInformation__tao_seq_ServiceOption : public TAO_Unbounded_Base_Sequence
    {
    public:
      // = Initialization and termination methods.

      _TAO_Unbounded_Sequence_CORBA_ServiceInformation__tao_seq_ServiceOption (void); // Default constructor.
      _TAO_Unbounded_Sequence_CORBA_ServiceInformation__tao_seq_ServiceOption (CORBA::ULong maximum);
      _TAO_Unbounded_Sequence_CORBA_ServiceInformation__tao_seq_ServiceOption (CORBA::ULong maximum,
                                                                               CORBA::ULong length,
                                                                               CORBA::ULong *data,
                                                                               CORBA::Boolean release = 0);
      _TAO_Unbounded_Sequence_CORBA_ServiceInformation__tao_seq_ServiceOption (const _TAO_Unbounded_Sequence_CORBA_ServiceInformation__tao_seq_ServiceOption & rhs);
      _TAO_Unbounded_Sequence_CORBA_ServiceInformation__tao_seq_ServiceOption &operator= (const _TAO_Unbounded_Sequence_CORBA_ServiceInformation__tao_seq_ServiceOption &rhs);
      virtual ~_TAO_Unbounded_Sequence_CORBA_ServiceInformation__tao_seq_ServiceOption (void); // Dtor.

      // = Accessors.
      CORBA::ULong &operator[] (CORBA::ULong i);
      const CORBA::ULong &operator[] (CORBA::ULong i) const;
      // = Static operations.
      static CORBA::ULong *allocbuf (CORBA::ULong size);
      static void freebuf (CORBA::ULong *buffer);
      virtual void _allocate_buffer (CORBA::ULong length);
      virtual void _deallocate_buffer (void);
      // Implement the TAO_Base_Sequence methods (see Sequence.h)

      CORBA::ULong *get_buffer (CORBA::Boolean orphan = 0);
      const CORBA::ULong *get_buffer (void) const;
      void replace (CORBA::ULong max,
                    CORBA::ULong length,
                    CORBA::ULong *data,
                    CORBA::Boolean release);
    };

#endif /* end #if !defined */


#endif /* !TAO_USE_SEQUENCE_TEMPLATES */

#if !defined (_CORBA_SERVICEINFORMATION__TAO_SEQ_SERVICEOPTION_CH_)
#define _CORBA_SERVICEINFORMATION__TAO_SEQ_SERVICEOPTION_CH_

  // *************************************************************
  // _tao_seq_ServiceOption
  // *************************************************************

    class  _tao_seq_ServiceOption : public
#if !defined (TAO_USE_SEQUENCE_TEMPLATES)
  _TAO_Unbounded_Sequence_CORBA_ServiceInformation__tao_seq_ServiceOption
#else /* TAO_USE_SEQUENCE_TEMPLATES */
  TAO_Unbounded_Sequence<CORBA::ULong>
#endif /* !TAO_USE_SEQUENCE_TEMPLATES */
    {
    public:
      _tao_seq_ServiceOption (void); // default ctor
      _tao_seq_ServiceOption (CORBA::ULong max); // uses max size
      _tao_seq_ServiceOption (
                              CORBA::ULong max,
                              CORBA::ULong length,
                              CORBA::ULong *buffer,
                              CORBA::Boolean release=0
                              );
      _tao_seq_ServiceOption (const _tao_seq_ServiceOption &); // copy ctor
      ~_tao_seq_ServiceOption (void); // dtor
    };
    typedef _tao_seq_ServiceOption *_tao_seq_ServiceOption_ptr;
    static CORBA::TypeCode_ptr _tc__tao_seq_ServiceOption;


#endif /* end #if !defined */


#if !defined (_CORBA_SERVICEINFORMATION__TAO_SEQ_SERVICEOPTION___VAR_CH_)
#define _CORBA_SERVICEINFORMATION__TAO_SEQ_SERVICEOPTION___VAR_CH_

    // *************************************************************
    // class CORBA::ServiceInformation::_tao_seq_ServiceOption_var
    // *************************************************************

    class  _tao_seq_ServiceOption_var
    {
    public:
      _tao_seq_ServiceOption_var (void); // default constructor
      _tao_seq_ServiceOption_var (_tao_seq_ServiceOption *);
      _tao_seq_ServiceOption_var (const _tao_seq_ServiceOption_var &); // copy constructor
      ~_tao_seq_ServiceOption_var (void); // destructor
      _tao_seq_ServiceOption_var &operator= (_tao_seq_ServiceOption *);
      _tao_seq_ServiceOption_var &operator= (const _tao_seq_ServiceOption_var &);
      _tao_seq_ServiceOption *operator-> (void);
      const _tao_seq_ServiceOption *operator-> (void) const;

      operator const _tao_seq_ServiceOption &() const;
      operator _tao_seq_ServiceOption &();
      operator _tao_seq_ServiceOption &() const;
      CORBA::ServiceOption &operator[] (CORBA::ULong slot);
      // in, inout, out, _retn
      const _tao_seq_ServiceOption &in (void) const;
      _tao_seq_ServiceOption &inout (void);
      _tao_seq_ServiceOption *&out (void);
      _tao_seq_ServiceOption *_retn (void);
      _tao_seq_ServiceOption *ptr (void) const;

    private:
      _tao_seq_ServiceOption *ptr_;
    };


#endif /* end #if !defined */


#if !defined (_CORBA_SERVICEINFORMATION__TAO_SEQ_SERVICEOPTION___OUT_CH_)
#define _CORBA_SERVICEINFORMATION__TAO_SEQ_SERVICEOPTION___OUT_CH_

    class  _tao_seq_ServiceOption_out
    {
    public:
      _tao_seq_ServiceOption_out (_tao_seq_ServiceOption *&);
      _tao_seq_ServiceOption_out (_tao_seq_ServiceOption_var &);
      _tao_seq_ServiceOption_out (const _tao_seq_ServiceOption_out &);
      _tao_seq_ServiceOption_out &operator= (const _tao_seq_ServiceOption_out &);
      _tao_seq_ServiceOption_out &operator= (_tao_seq_ServiceOption *);
      operator _tao_seq_ServiceOption *&();
      _tao_seq_ServiceOption *&ptr (void);
      _tao_seq_ServiceOption *operator-> (void);
      CORBA::ServiceOption &operator[] (CORBA::ULong slot);
    private:
      _tao_seq_ServiceOption *&ptr_;
      // assignment from T_var not allowed
      void operator= (const _tao_seq_ServiceOption_var &);
    };


#endif /* end #if !defined */

    _tao_seq_ServiceOption service_options;

#if !defined (TAO_USE_SEQUENCE_TEMPLATES)

#if !defined (__TAO_UNBOUNDED_SEQUENCE_CORBA_SERVICEINFORMATION__TAO_SEQ_SERVICEDETAIL_CH_)
#define __TAO_UNBOUNDED_SEQUENCE_CORBA_SERVICEINFORMATION__TAO_SEQ_SERVICEDETAIL_CH_

    class _TAO_Unbounded_Sequence_CORBA_ServiceInformation__tao_seq_ServiceDetail : public TAO_Unbounded_Base_Sequence
    {
    public:
      // = Initialization and termination methods.

      _TAO_Unbounded_Sequence_CORBA_ServiceInformation__tao_seq_ServiceDetail (void); // Default constructor.
      _TAO_Unbounded_Sequence_CORBA_ServiceInformation__tao_seq_ServiceDetail (CORBA::ULong maximum);
      _TAO_Unbounded_Sequence_CORBA_ServiceInformation__tao_seq_ServiceDetail (CORBA::ULong maximum,
                                                                               CORBA::ULong length,
                                                                               CORBA::ServiceDetail *data,
                                                                               CORBA::Boolean release = 0);
      _TAO_Unbounded_Sequence_CORBA_ServiceInformation__tao_seq_ServiceDetail (const _TAO_Unbounded_Sequence_CORBA_ServiceInformation__tao_seq_ServiceDetail & rhs);
      _TAO_Unbounded_Sequence_CORBA_ServiceInformation__tao_seq_ServiceDetail &operator= (const _TAO_Unbounded_Sequence_CORBA_ServiceInformation__tao_seq_ServiceDetail &rhs);
      virtual ~_TAO_Unbounded_Sequence_CORBA_ServiceInformation__tao_seq_ServiceDetail (void); // Dtor.
      // = Accessors.
      CORBA::ServiceDetail &operator[] (CORBA::ULong i);
      const CORBA::ServiceDetail &operator[] (CORBA::ULong i) const;
      // = Static operations.
      static CORBA::ServiceDetail *allocbuf (CORBA::ULong size);
      static void freebuf (CORBA::ServiceDetail *buffer);
      virtual void _allocate_buffer (CORBA::ULong length);
      virtual void _deallocate_buffer (void);
      // Implement the TAO_Base_Sequence methods (see Sequence.h)

      CORBA::ServiceDetail *get_buffer (CORBA::Boolean orphan = 0);
      const CORBA::ServiceDetail *get_buffer (void) const;
      void replace (CORBA::ULong max,
                    CORBA::ULong length,
                    CORBA::ServiceDetail *data,
                    CORBA::Boolean release);
    };

#endif /* end #if !defined */

#endif /* !TAO_USE_SEQUENCE_TEMPLATES */

#if !defined (_CORBA_SERVICEINFORMATION__TAO_SEQ_SERVICEDETAIL_CH_)
#define _CORBA_SERVICEINFORMATION__TAO_SEQ_SERVICEDETAIL_CH_

    // *************************************************************
    // _tao_seq_ServiceDetail
    // *************************************************************

    class  _tao_seq_ServiceDetail : public
#if !defined (TAO_USE_SEQUENCE_TEMPLATES)
    _TAO_Unbounded_Sequence_CORBA_ServiceInformation__tao_seq_ServiceDetail
#else /* TAO_USE_SEQUENCE_TEMPLATES */
    TAO_Unbounded_Sequence<CORBA::ServiceDetail>
#endif /* !TAO_USE_SEQUENCE_TEMPLATES */
    {
    public:
      _tao_seq_ServiceDetail (void); // default ctor
      _tao_seq_ServiceDetail (CORBA::ULong max); // uses max size
      _tao_seq_ServiceDetail (
                              CORBA::ULong max,
                              CORBA::ULong length,
                              CORBA::ServiceDetail *buffer,
                              CORBA::Boolean release=0
                              );
      _tao_seq_ServiceDetail (const _tao_seq_ServiceDetail &); // copy ctor
      ~_tao_seq_ServiceDetail (void); // dtor
    };
  typedef _tao_seq_ServiceDetail *_tao_seq_ServiceDetail_ptr;
  static CORBA::TypeCode_ptr _tc__tao_seq_ServiceDetail;


#endif /* end #if !defined */

#if !defined (_CORBA_SERVICEINFORMATION__TAO_SEQ_SERVICEDETAIL___VAR_CH_)
#define _CORBA_SERVICEINFORMATION__TAO_SEQ_SERVICEDETAIL___VAR_CH_

    // *************************************************************
    // class CORBA::ServiceInformation::_tao_seq_ServiceDetail_var
    // *************************************************************

    class  _tao_seq_ServiceDetail_var
    {
    public:
      _tao_seq_ServiceDetail_var (void); // default constructor
      _tao_seq_ServiceDetail_var (_tao_seq_ServiceDetail *);
      _tao_seq_ServiceDetail_var (const _tao_seq_ServiceDetail_var &); // copy constructor
      ~_tao_seq_ServiceDetail_var (void); // destructor

      _tao_seq_ServiceDetail_var &operator= (_tao_seq_ServiceDetail *);
      _tao_seq_ServiceDetail_var &operator= (const _tao_seq_ServiceDetail_var &);
      _tao_seq_ServiceDetail *operator-> (void);
      const _tao_seq_ServiceDetail *operator-> (void) const;

      operator const _tao_seq_ServiceDetail &() const;
      operator _tao_seq_ServiceDetail &();
      operator _tao_seq_ServiceDetail &() const;
      CORBA::ServiceDetail &operator[] (CORBA::ULong slot);
      // in, inout, out, _retn
      const _tao_seq_ServiceDetail &in (void) const;
      _tao_seq_ServiceDetail &inout (void);
      _tao_seq_ServiceDetail *&out (void);
      _tao_seq_ServiceDetail *_retn (void);
      _tao_seq_ServiceDetail *ptr (void) const;

    private:
      _tao_seq_ServiceDetail *ptr_;
    };


#endif /* end #if !defined */


#if !defined (_CORBA_SERVICEINFORMATION__TAO_SEQ_SERVICEDETAIL___OUT_CH_)
#define _CORBA_SERVICEINFORMATION__TAO_SEQ_SERVICEDETAIL___OUT_CH_

    class  _tao_seq_ServiceDetail_out
    {
    public:
      _tao_seq_ServiceDetail_out (_tao_seq_ServiceDetail *&);
      _tao_seq_ServiceDetail_out (_tao_seq_ServiceDetail_var &);
      _tao_seq_ServiceDetail_out (const _tao_seq_ServiceDetail_out &);
      _tao_seq_ServiceDetail_out &operator= (const _tao_seq_ServiceDetail_out &);
      _tao_seq_ServiceDetail_out &operator= (_tao_seq_ServiceDetail *);
      operator _tao_seq_ServiceDetail *&();
      _tao_seq_ServiceDetail *&ptr (void);
      _tao_seq_ServiceDetail *operator-> (void);
      CORBA::ServiceDetail &operator[] (CORBA::ULong slot);

    private:
      _tao_seq_ServiceDetail *&ptr_;
      // assignment from T_var not allowed
      void operator= (const _tao_seq_ServiceDetail_var &);
    };


#endif /* end #if !defined */

    _tao_seq_ServiceDetail service_details;
  };


  class ServiceInformation_var
  {
  public:
    ServiceInformation_var (void); // default constructor
    ServiceInformation_var (ServiceInformation *);
    ServiceInformation_var (const ServiceInformation_var &); // copy constructor
    ~ServiceInformation_var (void); // destructor

    ServiceInformation_var &operator= (ServiceInformation *);
    ServiceInformation_var &operator= (const ServiceInformation_var &);
    ServiceInformation *operator-> (void);
    const ServiceInformation *operator-> (void) const;

    /// in, inout, out, _retn
    operator const ServiceInformation &() const;
    operator ServiceInformation &();
    operator ServiceInformation &() const;
    const ServiceInformation &in (void) const;
    ServiceInformation &inout (void);
    ServiceInformation *&out (void);
    ServiceInformation *_retn (void);
    ServiceInformation *ptr (void) const;

  private:
    ServiceInformation *ptr_;
  };

  class  ServiceInformation_out
  {
  public:
    ServiceInformation_out (ServiceInformation *&);
    ServiceInformation_out (ServiceInformation_var &);
    ServiceInformation_out (const ServiceInformation_out &);
    ServiceInformation_out &operator= (const ServiceInformation_out &);
    ServiceInformation_out &operator= (ServiceInformation *);

    operator ServiceInformation *&();
    ServiceInformation *&ptr (void);
    ServiceInformation *operator-> (void);

  private:
    /// assignment from T_var not allowed
    ServiceInformation *&ptr_;
    void operator= (const ServiceInformation_var &);
  };
}  // End namespace CORBA

void  operator<<= (CORBA::Any &, const CORBA::ServiceDetail &); // copying version
void  operator<<= (CORBA::Any &, CORBA::ServiceDetail*); // noncopying version
  CORBA::Boolean  operator>>= (const CORBA::Any &, CORBA::ServiceDetail *&);
void  operator<<= (CORBA::Any &, const CORBA::ServiceInformation &); // copying version
void  operator<<= (CORBA::Any &, CORBA::ServiceInformation*); // noncopying version
CORBA::Boolean  operator>>= (const CORBA::Any &, CORBA::ServiceInformation *&);

CORBA::Boolean  operator<< (TAO_OutputCDR &, const CORBA::ServiceDetail &); //
CORBA::Boolean  operator>> (TAO_InputCDR &, CORBA::ServiceDetail &);
CORBA::Boolean  operator<< (TAO_OutputCDR &, const CORBA::ServiceDetail::_tao_seq_Octet &); //
CORBA::Boolean  operator>> (TAO_InputCDR &, CORBA::ServiceDetail::_tao_seq_Octet &);

CORBA::Boolean  operator<< (TAO_OutputCDR &, const CORBA::ServiceInformation &);
CORBA::Boolean  operator>> (TAO_InputCDR &, CORBA::ServiceInformation &);
CORBA::Boolean  operator<< (TAO_OutputCDR &, const CORBA::ServiceInformation::_tao_seq_ServiceOption &);
CORBA::Boolean  operator>> (TAO_InputCDR &, CORBA::ServiceInformation::_tao_seq_ServiceOption &);
CORBA::Boolean  operator<< (TAO_OutputCDR &, const CORBA::ServiceInformation::_tao_seq_ServiceDetail &);
CORBA::Boolean  operator>> (TAO_InputCDR &, CORBA::ServiceInformation::_tao_seq_ServiceDetail &);

#if defined (__ACE_INLINE__)
#include "tao/Services.i"
#endif /* defined INLINE */

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma warning(pop)
#endif /* _MSC_VER */

#include "ace/post.h"
#endif /* TAO_SERVICES_H */
