/* errno.h: ANSI 'C' (X3J11 Oct 88) library header, section 4.1.3 */
/* Copyright (C) Codemist Ltd., 1988                            */
/* Copyright 1991 ARM Limited. All rights reserved.             */
/* version 1 */

/*
 * RCS $Revision: 172039 $
 * Checkin $Date: 2011-11-02 12:58:12 +0000 (Wed, 02 Nov 2011) $
 * Revising $Author: drodgman $
 */

#ifndef __errno_h
#define __errno_h
#define __ARMCLIB_VERSION 410000

#define _ARMABI_PURE __declspec(__nothrow) __pure

  #ifndef __ERRNO_DECLS
  #define __ERRNO_DECLS

    #undef __CLIBNS

    #ifdef __cplusplus
        namespace std {
        #define __CLIBNS std::
        extern "C" {
    #else
      #define __CLIBNS
    #endif  /* __cplusplus */


extern _ARMABI_PURE volatile int *__aeabi_errno_addr(void);


    #ifdef __cplusplus
         }  /* extern "C" */
      }  /* namespace std */
    #endif /* __cplusplus */
  #endif /* __ERRNO_DECLS */

  #ifdef __cplusplus
    #ifndef __ERRNO_NO_EXPORTS
      using ::std::__aeabi_errno_addr;
    #endif /* __ERRNO_NO_EXPORTS */
  #endif /* __cplusplus */

#define errno (*__CLIBNS __aeabi_errno_addr())
/*
 * expands to a modifiable lvalue that has type volatile int, the value of
 * which is set to a positive error code by several library functions. It is
 * initialised to zero at program startup, but is never set to zero by any
 * library function. The value of errno may be set to nonzero by a library
 * function call whether or not there is an error, provided the use of errno
 * is not documented in the description of the function in the Standard.
 */


/*
 * Error numbers defined in the C standard need the ABI portability
 * mechanism.
 */
#if _AEABI_PORTABILITY_LEVEL != 0 && !defined _AEABI_PORTABLE
  #define _AEABI_PORTABLE
#endif

/* The ABI-defined signal numbers (EDOM, ERANGE and EILSEQ) are
 * defined differently depending on ABI conformance level. */
#if _AEABI_PORTABILITY_LEVEL != 0 || (!defined _AEABI_PORTABILITY_LEVEL && __DEFAULT_AEABI_PORTABILITY_LEVEL != 0)
extern const int __aeabi_EDOM;
extern const int __aeabi_ERANGE;
extern const int __aeabi_EILSEQ;
#define EDOM (__aeabi_EDOM)
#define ERANGE (__aeabi_ERANGE)
#define EILSEQ (__aeabi_EILSEQ)
#else

#define EDOM    1
/*
 * If a mathematical function suffers a domain error (an input
 * argument is outside the domain over which the mathematical
 * function is defined, e.g. log of a negative number) the integer
 * expression errno acquires the value of the macro EDOM.
 *
 * EDOM is also returned by ftell, fgetpos and fsetpos when they
 * fail.
 */

#define ERANGE 2
/*
 * If a mathematical function suffers a range error (the result of
 * the function is too large or too small to be accurately
 * represented in the output floating-point format), the integer
 * expression errno acquires the value of the macro ERANGE.
 *
 * ERANGE is used by functions in math.h and complex.h, and also by
 * the strto* and wcsto* family of decimal-to-binary conversion
 * functions (both floating and integer) and by floating-point
 * conversions in scanf.
 */

#define EILSEQ  4
/*
 * EILSEQ is generated by the restartable multi-byte character
 * processing routines to indicate an encoding error: that is, it is
 * generated by mbrtowc, wcrtomb, mbsrtowcs and wcsrtombs, but not
 * by mbtowc, wctomb, mbstowcs or wcsrtombs.
 *
 * It is also generated by the wide-character stdio functions:
 * fputwc, putwc, putwchar, fputws, fgetwc, getwc, getwchar, fgetws.
 */

#endif /* end of conditional definition of ABI-defined signals */

#define ESIGNUM 3
/*
 * ESIGNUM is generated by signal() if the user attempts to change
 * the handling of a nonexistent signal. ESIGNUM is not part of the
 * ANSI C standard.
 */

#define EINVAL  5
#define ENOMEM  6
/*
 * EINVAL and ENOMEM can be generated by posix_memalign().
 */

#endif

/* end of errno.h */
