

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Fri May 05 14:30:19 2017
 */
/* Compiler settings for TestCom3.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 8.00.0603 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __TestCom3_i_h__
#define __TestCom3_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IFirstObject_FWD_DEFINED__
#define __IFirstObject_FWD_DEFINED__
typedef interface IFirstObject IFirstObject;

#endif 	/* __IFirstObject_FWD_DEFINED__ */


#ifndef __FirstObject_FWD_DEFINED__
#define __FirstObject_FWD_DEFINED__

#ifdef __cplusplus
typedef class FirstObject FirstObject;
#else
typedef struct FirstObject FirstObject;
#endif /* __cplusplus */

#endif 	/* __FirstObject_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IFirstObject_INTERFACE_DEFINED__
#define __IFirstObject_INTERFACE_DEFINED__

/* interface IFirstObject */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IFirstObject;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E5AC5C50-B6FB-479C-8251-4E420E511099")
    IFirstObject : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Test( 
            BSTR bstr) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IFirstObjectVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFirstObject * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFirstObject * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFirstObject * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IFirstObject * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IFirstObject * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IFirstObject * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFirstObject * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Test )( 
            IFirstObject * This,
            BSTR bstr);
        
        END_INTERFACE
    } IFirstObjectVtbl;

    interface IFirstObject
    {
        CONST_VTBL struct IFirstObjectVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFirstObject_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFirstObject_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFirstObject_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IFirstObject_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IFirstObject_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IFirstObject_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IFirstObject_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IFirstObject_Test(This,bstr)	\
    ( (This)->lpVtbl -> Test(This,bstr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IFirstObject_INTERFACE_DEFINED__ */



#ifndef __TestCom3Lib_LIBRARY_DEFINED__
#define __TestCom3Lib_LIBRARY_DEFINED__

/* library TestCom3Lib */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_TestCom3Lib;

EXTERN_C const CLSID CLSID_FirstObject;

#ifdef __cplusplus

class DECLSPEC_UUID("F31B5110-595E-44A9-8DEC-53F448ACCD1C")
FirstObject;
#endif
#endif /* __TestCom3Lib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


