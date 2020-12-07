#ifndef G_BASIC_H__________
#define G_BASIC_H__________
#ifndef GC_MALLOC
#define GC_MALLOC malloc
#endif
#ifndef GC_FREE
#define GC_FREE free
#endif
#pragma GCC diagnostic push                              
#pragma GCC diagnostic ignored "-Wbool-operation"      
#pragma GCC diagnostic ignored "-Wint-in-bool-context" 
#pragma GCC diagnostic ignored "-Wsign-compare"        
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <complex.h>
static __attribute__((unused)) bool g_example_b;
static __attribute__((unused)) char g_example_c;
static __attribute__((unused)) short g_example_ss;
static __attribute__((unused)) int g_example_si;
static __attribute__((unused)) long g_example_sl;
static __attribute__((unused)) unsigned long g_example_ul;
static __attribute__((unused)) float g_example_f;
static __attribute__((unused)) double g_example_d;

#define g_example(x) _Generic((x) \
	, bool : g_example_b \
	, char : g_example_c \
	, short : g_example_ss \
	, int : g_example_si \
	, long : g_example_sl \
	, unsigned long : g_example_ul \
	, float : g_example_f \
	, double : g_example_d \
)

#define g_format_str(x) _Generic((x) \
	, bool : "%d" \
	, char : "%c" \
	, signed char : "%c" \
	, unsigned char : "%c" \
	, signed short : "%hd" \
	, unsigned short : "%hu" \
	, signed int : "%d" \
	, unsigned int : "%u" \
	, signed long : "%ld" \
	, unsigned long : "%lu" \
	, signed long long : "%lld" \
	, unsigned long long : "%llu" \
	, float : "%g" \
	, double : "%g" \
	, long double : "%Lg" \
	, float complex : "?" \
	, double complex : "??" \
	, long double complex : "???" \
	, char * : "%s" \
)
static __attribute__((unused)) bool * g_ptr_from_void_b(void* p){return (bool *)p;}
static __attribute__((unused)) char * g_ptr_from_void_c(void* p){return (char *)p;}
static __attribute__((unused)) short * g_ptr_from_void_ss(void* p){return (short *)p;}
static __attribute__((unused)) int * g_ptr_from_void_si(void* p){return (int *)p;}
static __attribute__((unused)) long * g_ptr_from_void_sl(void* p){return (long *)p;}
static __attribute__((unused)) unsigned long * g_ptr_from_void_ul(void* p){return (unsigned long *)p;}
static __attribute__((unused)) float * g_ptr_from_void_f(void* p){return (float *)p;}
static __attribute__((unused)) double * g_ptr_from_void_d(void* p){return (double *)p;}

#define g_ptr_from_void(x) _Generic((x) \
	, bool : g_ptr_from_void_b \
	, char : g_ptr_from_void_c \
	, short : g_ptr_from_void_ss \
	, int : g_ptr_from_void_si \
	, long : g_ptr_from_void_sl \
	, unsigned long : g_ptr_from_void_ul \
	, float : g_ptr_from_void_f \
	, double : g_ptr_from_void_d \
)
static __attribute__((unused)) const bool * g_cptr_from_void_b(const void* p){return (const bool *)p;}
static __attribute__((unused)) const char * g_cptr_from_void_c(const void* p){return (const char *)p;}
static __attribute__((unused)) const short * g_cptr_from_void_ss(const void* p){return (const short *)p;}
static __attribute__((unused)) const int * g_cptr_from_void_si(const void* p){return (const int *)p;}
static __attribute__((unused)) const long * g_cptr_from_void_sl(const void* p){return (const long *)p;}
static __attribute__((unused)) const unsigned long * g_cptr_from_void_ul(const void* p){return (const unsigned long *)p;}
static __attribute__((unused)) const float * g_cptr_from_void_f(const void* p){return (const float *)p;}
static __attribute__((unused)) const double * g_cptr_from_void_d(const void* p){return (const double *)p;}

#define g_cptr_from_void(x) _Generic((x) \
	, bool : g_cptr_from_void_b \
	, char : g_cptr_from_void_c \
	, short : g_cptr_from_void_ss \
	, int : g_cptr_from_void_si \
	, long : g_cptr_from_void_sl \
	, unsigned long : g_cptr_from_void_ul \
	, float : g_cptr_from_void_f \
	, double : g_cptr_from_void_d \
)
static __attribute__((unused)) bool g_value_from_void_b(void* p){return *((bool *)p);}
static __attribute__((unused)) char g_value_from_void_c(void* p){return *((char *)p);}
static __attribute__((unused)) short g_value_from_void_ss(void* p){return *((short *)p);}
static __attribute__((unused)) int g_value_from_void_si(void* p){return *((int *)p);}
static __attribute__((unused)) long g_value_from_void_sl(void* p){return *((long *)p);}
static __attribute__((unused)) unsigned long g_value_from_void_ul(void* p){return *((unsigned long *)p);}
static __attribute__((unused)) float g_value_from_void_f(void* p){return *((float *)p);}
static __attribute__((unused)) double g_value_from_void_d(void* p){return *((double *)p);}

#define g_value_from_void(x) _Generic((x) \
	, bool : g_value_from_void_b \
	, char : g_value_from_void_c \
	, short : g_value_from_void_ss \
	, int : g_value_from_void_si \
	, long : g_value_from_void_sl \
	, unsigned long : g_value_from_void_ul \
	, float : g_value_from_void_f \
	, double : g_value_from_void_d \
)
static __attribute__((unused)) bool g_value_from_void_free_b(void* p){bool ret = *((bool *)p);GC_FREE(p);return ret;}
static __attribute__((unused)) char g_value_from_void_free_c(void* p){char ret = *((char *)p);GC_FREE(p);return ret;}
static __attribute__((unused)) short g_value_from_void_free_ss(void* p){short ret = *((short *)p);GC_FREE(p);return ret;}
static __attribute__((unused)) int g_value_from_void_free_si(void* p){int ret = *((int *)p);GC_FREE(p);return ret;}
static __attribute__((unused)) long g_value_from_void_free_sl(void* p){long ret = *((long *)p);GC_FREE(p);return ret;}
static __attribute__((unused)) unsigned long g_value_from_void_free_ul(void* p){unsigned long ret = *((unsigned long *)p);GC_FREE(p);return ret;}
static __attribute__((unused)) float g_value_from_void_free_f(void* p){float ret = *((float *)p);GC_FREE(p);return ret;}
static __attribute__((unused)) double g_value_from_void_free_d(void* p){double ret = *((double *)p);GC_FREE(p);return ret;}

#define g_value_from_void_free(x) _Generic((x) \
	, bool : g_value_from_void_free_b \
	, char : g_value_from_void_free_c \
	, short : g_value_from_void_free_ss \
	, int : g_value_from_void_free_si \
	, long : g_value_from_void_free_sl \
	, unsigned long : g_value_from_void_free_ul \
	, float : g_value_from_void_free_f \
	, double : g_value_from_void_free_d \
)
static __attribute__((unused)) void* g_malloc_value_b(bool x){void* p=GC_MALLOC(sizeof(x));memcpy(p, &x, sizeof(x));return p;}
static __attribute__((unused)) void* g_malloc_value_c(char x){void* p=GC_MALLOC(sizeof(x));memcpy(p, &x, sizeof(x));return p;}
static __attribute__((unused)) void* g_malloc_value_ss(short x){void* p=GC_MALLOC(sizeof(x));memcpy(p, &x, sizeof(x));return p;}
static __attribute__((unused)) void* g_malloc_value_si(int x){void* p=GC_MALLOC(sizeof(x));memcpy(p, &x, sizeof(x));return p;}
static __attribute__((unused)) void* g_malloc_value_sl(long x){void* p=GC_MALLOC(sizeof(x));memcpy(p, &x, sizeof(x));return p;}
static __attribute__((unused)) void* g_malloc_value_ul(unsigned long x){void* p=GC_MALLOC(sizeof(x));memcpy(p, &x, sizeof(x));return p;}
static __attribute__((unused)) void* g_malloc_value_f(float x){void* p=GC_MALLOC(sizeof(x));memcpy(p, &x, sizeof(x));return p;}
static __attribute__((unused)) void* g_malloc_value_d(double x){void* p=GC_MALLOC(sizeof(x));memcpy(p, &x, sizeof(x));return p;}

#define g_malloc_value(x) _Generic((x) \
	, bool : g_malloc_value_b \
	, char : g_malloc_value_c \
	, short : g_malloc_value_ss \
	, int : g_malloc_value_si \
	, long : g_malloc_value_sl \
	, unsigned long : g_malloc_value_ul \
	, float : g_malloc_value_f \
	, double : g_malloc_value_d \
)

#define g_type_id(x) _Generic((x) \
	, bool   : 1 \
	, bool * : 2 \
	, bool **: 3 \
	, char   : 4 \
	, char * : 5 \
	, char **: 6 \
	, short   : 7 \
	, short * : 8 \
	, short **: 9 \
	, int   : 10 \
	, int * : 11 \
	, int **: 12 \
	, long   : 13 \
	, long * : 14 \
	, long **: 15 \
	, unsigned long   : 16 \
	, unsigned long * : 17 \
	, unsigned long **: 18 \
	, float   : 19 \
	, float * : 20 \
	, float **: 21 \
	, double   : 22 \
	, double * : 23 \
	, double **: 24 \
)

#define g_type_str(x) _Generic((x) \
	, bool   : "bool" \
	, bool * : "bool *" \
	, char   : "char" \
	, char * : "char *" \
	, short   : "short" \
	, short * : "short *" \
	, int   : "int" \
	, int * : "int *" \
	, long   : "long" \
	, long * : "long *" \
	, unsigned long   : "unsigned long" \
	, unsigned long * : "unsigned long *" \
	, float   : "float" \
	, float * : "float *" \
	, double   : "double" \
	, double * : "double *" \
)
typedef struct pair_bool_t { bool first ; bool second ; } pair_bool_t; 
typedef struct pair_char_t { char first ; char second ; } pair_char_t; 
typedef struct pair_short_t { short first ; short second ; } pair_short_t; 
typedef struct pair_int_t { int first ; int second ; } pair_int_t; 
typedef struct pair_long_t { long first ; long second ; } pair_long_t; 
typedef struct pair_unsigned_long_t { unsigned long first ; unsigned long second ; } pair_unsigned_long_t; 
typedef struct pair_float_t { float first ; float second ; } pair_float_t; 
typedef struct pair_double_t { double first ; double second ; } pair_double_t; 
static __attribute__((unused)) bool g_is_eq_b_b(const void* a, const void* b){return *((bool*)a) == *((bool*)b);}
static __attribute__((unused)) bool g_is_eq_b_c(const void* a, const void* b){return *((bool*)a) == *((char*)b);}
static __attribute__((unused)) bool g_is_eq_b_ss(const void* a, const void* b){return *((bool*)a) == *((short*)b);}
static __attribute__((unused)) bool g_is_eq_b_si(const void* a, const void* b){return *((bool*)a) == *((int*)b);}
static __attribute__((unused)) bool g_is_eq_b_sl(const void* a, const void* b){return *((bool*)a) == *((long*)b);}
static __attribute__((unused)) bool g_is_eq_b_ul(const void* a, const void* b){return *((bool*)a) == *((unsigned long*)b);}
static __attribute__((unused)) bool g_is_eq_b_f(const void* a, const void* b){return *((bool*)a) == *((float*)b);}
static __attribute__((unused)) bool g_is_eq_b_d(const void* a, const void* b){return *((bool*)a) == *((double*)b);}
static __attribute__((unused)) bool g_is_eq_c_b(const void* a, const void* b){return *((char*)a) == *((bool*)b);}
static __attribute__((unused)) bool g_is_eq_c_c(const void* a, const void* b){return *((char*)a) == *((char*)b);}
static __attribute__((unused)) bool g_is_eq_c_ss(const void* a, const void* b){return *((char*)a) == *((short*)b);}
static __attribute__((unused)) bool g_is_eq_c_si(const void* a, const void* b){return *((char*)a) == *((int*)b);}
static __attribute__((unused)) bool g_is_eq_c_sl(const void* a, const void* b){return *((char*)a) == *((long*)b);}
static __attribute__((unused)) bool g_is_eq_c_ul(const void* a, const void* b){return *((char*)a) == *((unsigned long*)b);}
static __attribute__((unused)) bool g_is_eq_c_f(const void* a, const void* b){return *((char*)a) == *((float*)b);}
static __attribute__((unused)) bool g_is_eq_c_d(const void* a, const void* b){return *((char*)a) == *((double*)b);}
static __attribute__((unused)) bool g_is_eq_ss_b(const void* a, const void* b){return *((short*)a) == *((bool*)b);}
static __attribute__((unused)) bool g_is_eq_ss_c(const void* a, const void* b){return *((short*)a) == *((char*)b);}
static __attribute__((unused)) bool g_is_eq_ss_ss(const void* a, const void* b){return *((short*)a) == *((short*)b);}
static __attribute__((unused)) bool g_is_eq_ss_si(const void* a, const void* b){return *((short*)a) == *((int*)b);}
static __attribute__((unused)) bool g_is_eq_ss_sl(const void* a, const void* b){return *((short*)a) == *((long*)b);}
static __attribute__((unused)) bool g_is_eq_ss_ul(const void* a, const void* b){return *((short*)a) == *((unsigned long*)b);}
static __attribute__((unused)) bool g_is_eq_ss_f(const void* a, const void* b){return *((short*)a) == *((float*)b);}
static __attribute__((unused)) bool g_is_eq_ss_d(const void* a, const void* b){return *((short*)a) == *((double*)b);}
static __attribute__((unused)) bool g_is_eq_si_b(const void* a, const void* b){return *((int*)a) == *((bool*)b);}
static __attribute__((unused)) bool g_is_eq_si_c(const void* a, const void* b){return *((int*)a) == *((char*)b);}
static __attribute__((unused)) bool g_is_eq_si_ss(const void* a, const void* b){return *((int*)a) == *((short*)b);}
static __attribute__((unused)) bool g_is_eq_si_si(const void* a, const void* b){return *((int*)a) == *((int*)b);}
static __attribute__((unused)) bool g_is_eq_si_sl(const void* a, const void* b){return *((int*)a) == *((long*)b);}
static __attribute__((unused)) bool g_is_eq_si_ul(const void* a, const void* b){return *((int*)a) == *((unsigned long*)b);}
static __attribute__((unused)) bool g_is_eq_si_f(const void* a, const void* b){return *((int*)a) == *((float*)b);}
static __attribute__((unused)) bool g_is_eq_si_d(const void* a, const void* b){return *((int*)a) == *((double*)b);}
static __attribute__((unused)) bool g_is_eq_sl_b(const void* a, const void* b){return *((long*)a) == *((bool*)b);}
static __attribute__((unused)) bool g_is_eq_sl_c(const void* a, const void* b){return *((long*)a) == *((char*)b);}
static __attribute__((unused)) bool g_is_eq_sl_ss(const void* a, const void* b){return *((long*)a) == *((short*)b);}
static __attribute__((unused)) bool g_is_eq_sl_si(const void* a, const void* b){return *((long*)a) == *((int*)b);}
static __attribute__((unused)) bool g_is_eq_sl_sl(const void* a, const void* b){return *((long*)a) == *((long*)b);}
static __attribute__((unused)) bool g_is_eq_sl_ul(const void* a, const void* b){return *((long*)a) == *((unsigned long*)b);}
static __attribute__((unused)) bool g_is_eq_sl_f(const void* a, const void* b){return *((long*)a) == *((float*)b);}
static __attribute__((unused)) bool g_is_eq_sl_d(const void* a, const void* b){return *((long*)a) == *((double*)b);}
static __attribute__((unused)) bool g_is_eq_ul_b(const void* a, const void* b){return *((unsigned long*)a) == *((bool*)b);}
static __attribute__((unused)) bool g_is_eq_ul_c(const void* a, const void* b){return *((unsigned long*)a) == *((char*)b);}
static __attribute__((unused)) bool g_is_eq_ul_ss(const void* a, const void* b){return *((unsigned long*)a) == *((short*)b);}
static __attribute__((unused)) bool g_is_eq_ul_si(const void* a, const void* b){return *((unsigned long*)a) == *((int*)b);}
static __attribute__((unused)) bool g_is_eq_ul_sl(const void* a, const void* b){return *((unsigned long*)a) == *((long*)b);}
static __attribute__((unused)) bool g_is_eq_ul_ul(const void* a, const void* b){return *((unsigned long*)a) == *((unsigned long*)b);}
static __attribute__((unused)) bool g_is_eq_ul_f(const void* a, const void* b){return *((unsigned long*)a) == *((float*)b);}
static __attribute__((unused)) bool g_is_eq_ul_d(const void* a, const void* b){return *((unsigned long*)a) == *((double*)b);}
static __attribute__((unused)) bool g_is_eq_f_b(const void* a, const void* b){return *((float*)a) == *((bool*)b);}
static __attribute__((unused)) bool g_is_eq_f_c(const void* a, const void* b){return *((float*)a) == *((char*)b);}
static __attribute__((unused)) bool g_is_eq_f_ss(const void* a, const void* b){return *((float*)a) == *((short*)b);}
static __attribute__((unused)) bool g_is_eq_f_si(const void* a, const void* b){return *((float*)a) == *((int*)b);}
static __attribute__((unused)) bool g_is_eq_f_sl(const void* a, const void* b){return *((float*)a) == *((long*)b);}
static __attribute__((unused)) bool g_is_eq_f_ul(const void* a, const void* b){return *((float*)a) == *((unsigned long*)b);}
static __attribute__((unused)) bool g_is_eq_f_f(const void* a, const void* b){return *((float*)a) == *((float*)b);}
static __attribute__((unused)) bool g_is_eq_f_d(const void* a, const void* b){return *((float*)a) == *((double*)b);}
static __attribute__((unused)) bool g_is_eq_d_b(const void* a, const void* b){return *((double*)a) == *((bool*)b);}
static __attribute__((unused)) bool g_is_eq_d_c(const void* a, const void* b){return *((double*)a) == *((char*)b);}
static __attribute__((unused)) bool g_is_eq_d_ss(const void* a, const void* b){return *((double*)a) == *((short*)b);}
static __attribute__((unused)) bool g_is_eq_d_si(const void* a, const void* b){return *((double*)a) == *((int*)b);}
static __attribute__((unused)) bool g_is_eq_d_sl(const void* a, const void* b){return *((double*)a) == *((long*)b);}
static __attribute__((unused)) bool g_is_eq_d_ul(const void* a, const void* b){return *((double*)a) == *((unsigned long*)b);}
static __attribute__((unused)) bool g_is_eq_d_f(const void* a, const void* b){return *((double*)a) == *((float*)b);}
static __attribute__((unused)) bool g_is_eq_d_d(const void* a, const void* b){return *((double*)a) == *((double*)b);}
static __attribute__((unused)) bool g_is_ne_b_b(const void* a, const void* b){return *((bool*)a) != *((bool*)b);}
static __attribute__((unused)) bool g_is_ne_b_c(const void* a, const void* b){return *((bool*)a) != *((char*)b);}
static __attribute__((unused)) bool g_is_ne_b_ss(const void* a, const void* b){return *((bool*)a) != *((short*)b);}
static __attribute__((unused)) bool g_is_ne_b_si(const void* a, const void* b){return *((bool*)a) != *((int*)b);}
static __attribute__((unused)) bool g_is_ne_b_sl(const void* a, const void* b){return *((bool*)a) != *((long*)b);}
static __attribute__((unused)) bool g_is_ne_b_ul(const void* a, const void* b){return *((bool*)a) != *((unsigned long*)b);}
static __attribute__((unused)) bool g_is_ne_b_f(const void* a, const void* b){return *((bool*)a) != *((float*)b);}
static __attribute__((unused)) bool g_is_ne_b_d(const void* a, const void* b){return *((bool*)a) != *((double*)b);}
static __attribute__((unused)) bool g_is_ne_c_b(const void* a, const void* b){return *((char*)a) != *((bool*)b);}
static __attribute__((unused)) bool g_is_ne_c_c(const void* a, const void* b){return *((char*)a) != *((char*)b);}
static __attribute__((unused)) bool g_is_ne_c_ss(const void* a, const void* b){return *((char*)a) != *((short*)b);}
static __attribute__((unused)) bool g_is_ne_c_si(const void* a, const void* b){return *((char*)a) != *((int*)b);}
static __attribute__((unused)) bool g_is_ne_c_sl(const void* a, const void* b){return *((char*)a) != *((long*)b);}
static __attribute__((unused)) bool g_is_ne_c_ul(const void* a, const void* b){return *((char*)a) != *((unsigned long*)b);}
static __attribute__((unused)) bool g_is_ne_c_f(const void* a, const void* b){return *((char*)a) != *((float*)b);}
static __attribute__((unused)) bool g_is_ne_c_d(const void* a, const void* b){return *((char*)a) != *((double*)b);}
static __attribute__((unused)) bool g_is_ne_ss_b(const void* a, const void* b){return *((short*)a) != *((bool*)b);}
static __attribute__((unused)) bool g_is_ne_ss_c(const void* a, const void* b){return *((short*)a) != *((char*)b);}
static __attribute__((unused)) bool g_is_ne_ss_ss(const void* a, const void* b){return *((short*)a) != *((short*)b);}
static __attribute__((unused)) bool g_is_ne_ss_si(const void* a, const void* b){return *((short*)a) != *((int*)b);}
static __attribute__((unused)) bool g_is_ne_ss_sl(const void* a, const void* b){return *((short*)a) != *((long*)b);}
static __attribute__((unused)) bool g_is_ne_ss_ul(const void* a, const void* b){return *((short*)a) != *((unsigned long*)b);}
static __attribute__((unused)) bool g_is_ne_ss_f(const void* a, const void* b){return *((short*)a) != *((float*)b);}
static __attribute__((unused)) bool g_is_ne_ss_d(const void* a, const void* b){return *((short*)a) != *((double*)b);}
static __attribute__((unused)) bool g_is_ne_si_b(const void* a, const void* b){return *((int*)a) != *((bool*)b);}
static __attribute__((unused)) bool g_is_ne_si_c(const void* a, const void* b){return *((int*)a) != *((char*)b);}
static __attribute__((unused)) bool g_is_ne_si_ss(const void* a, const void* b){return *((int*)a) != *((short*)b);}
static __attribute__((unused)) bool g_is_ne_si_si(const void* a, const void* b){return *((int*)a) != *((int*)b);}
static __attribute__((unused)) bool g_is_ne_si_sl(const void* a, const void* b){return *((int*)a) != *((long*)b);}
static __attribute__((unused)) bool g_is_ne_si_ul(const void* a, const void* b){return *((int*)a) != *((unsigned long*)b);}
static __attribute__((unused)) bool g_is_ne_si_f(const void* a, const void* b){return *((int*)a) != *((float*)b);}
static __attribute__((unused)) bool g_is_ne_si_d(const void* a, const void* b){return *((int*)a) != *((double*)b);}
static __attribute__((unused)) bool g_is_ne_sl_b(const void* a, const void* b){return *((long*)a) != *((bool*)b);}
static __attribute__((unused)) bool g_is_ne_sl_c(const void* a, const void* b){return *((long*)a) != *((char*)b);}
static __attribute__((unused)) bool g_is_ne_sl_ss(const void* a, const void* b){return *((long*)a) != *((short*)b);}
static __attribute__((unused)) bool g_is_ne_sl_si(const void* a, const void* b){return *((long*)a) != *((int*)b);}
static __attribute__((unused)) bool g_is_ne_sl_sl(const void* a, const void* b){return *((long*)a) != *((long*)b);}
static __attribute__((unused)) bool g_is_ne_sl_ul(const void* a, const void* b){return *((long*)a) != *((unsigned long*)b);}
static __attribute__((unused)) bool g_is_ne_sl_f(const void* a, const void* b){return *((long*)a) != *((float*)b);}
static __attribute__((unused)) bool g_is_ne_sl_d(const void* a, const void* b){return *((long*)a) != *((double*)b);}
static __attribute__((unused)) bool g_is_ne_ul_b(const void* a, const void* b){return *((unsigned long*)a) != *((bool*)b);}
static __attribute__((unused)) bool g_is_ne_ul_c(const void* a, const void* b){return *((unsigned long*)a) != *((char*)b);}
static __attribute__((unused)) bool g_is_ne_ul_ss(const void* a, const void* b){return *((unsigned long*)a) != *((short*)b);}
static __attribute__((unused)) bool g_is_ne_ul_si(const void* a, const void* b){return *((unsigned long*)a) != *((int*)b);}
static __attribute__((unused)) bool g_is_ne_ul_sl(const void* a, const void* b){return *((unsigned long*)a) != *((long*)b);}
static __attribute__((unused)) bool g_is_ne_ul_ul(const void* a, const void* b){return *((unsigned long*)a) != *((unsigned long*)b);}
static __attribute__((unused)) bool g_is_ne_ul_f(const void* a, const void* b){return *((unsigned long*)a) != *((float*)b);}
static __attribute__((unused)) bool g_is_ne_ul_d(const void* a, const void* b){return *((unsigned long*)a) != *((double*)b);}
static __attribute__((unused)) bool g_is_ne_f_b(const void* a, const void* b){return *((float*)a) != *((bool*)b);}
static __attribute__((unused)) bool g_is_ne_f_c(const void* a, const void* b){return *((float*)a) != *((char*)b);}
static __attribute__((unused)) bool g_is_ne_f_ss(const void* a, const void* b){return *((float*)a) != *((short*)b);}
static __attribute__((unused)) bool g_is_ne_f_si(const void* a, const void* b){return *((float*)a) != *((int*)b);}
static __attribute__((unused)) bool g_is_ne_f_sl(const void* a, const void* b){return *((float*)a) != *((long*)b);}
static __attribute__((unused)) bool g_is_ne_f_ul(const void* a, const void* b){return *((float*)a) != *((unsigned long*)b);}
static __attribute__((unused)) bool g_is_ne_f_f(const void* a, const void* b){return *((float*)a) != *((float*)b);}
static __attribute__((unused)) bool g_is_ne_f_d(const void* a, const void* b){return *((float*)a) != *((double*)b);}
static __attribute__((unused)) bool g_is_ne_d_b(const void* a, const void* b){return *((double*)a) != *((bool*)b);}
static __attribute__((unused)) bool g_is_ne_d_c(const void* a, const void* b){return *((double*)a) != *((char*)b);}
static __attribute__((unused)) bool g_is_ne_d_ss(const void* a, const void* b){return *((double*)a) != *((short*)b);}
static __attribute__((unused)) bool g_is_ne_d_si(const void* a, const void* b){return *((double*)a) != *((int*)b);}
static __attribute__((unused)) bool g_is_ne_d_sl(const void* a, const void* b){return *((double*)a) != *((long*)b);}
static __attribute__((unused)) bool g_is_ne_d_ul(const void* a, const void* b){return *((double*)a) != *((unsigned long*)b);}
static __attribute__((unused)) bool g_is_ne_d_f(const void* a, const void* b){return *((double*)a) != *((float*)b);}
static __attribute__((unused)) bool g_is_ne_d_d(const void* a, const void* b){return *((double*)a) != *((double*)b);}
static __attribute__((unused)) bool g_is_gt_b_b(const void* a, const void* b){return *((bool*)a) > *((bool*)b);}
static __attribute__((unused)) bool g_is_gt_b_c(const void* a, const void* b){return *((bool*)a) > *((char*)b);}
static __attribute__((unused)) bool g_is_gt_b_ss(const void* a, const void* b){return *((bool*)a) > *((short*)b);}
static __attribute__((unused)) bool g_is_gt_b_si(const void* a, const void* b){return *((bool*)a) > *((int*)b);}
static __attribute__((unused)) bool g_is_gt_b_sl(const void* a, const void* b){return *((bool*)a) > *((long*)b);}
static __attribute__((unused)) bool g_is_gt_b_ul(const void* a, const void* b){return *((bool*)a) > *((unsigned long*)b);}
static __attribute__((unused)) bool g_is_gt_b_f(const void* a, const void* b){return *((bool*)a) > *((float*)b);}
static __attribute__((unused)) bool g_is_gt_b_d(const void* a, const void* b){return *((bool*)a) > *((double*)b);}
static __attribute__((unused)) bool g_is_gt_c_b(const void* a, const void* b){return *((char*)a) > *((bool*)b);}
static __attribute__((unused)) bool g_is_gt_c_c(const void* a, const void* b){return *((char*)a) > *((char*)b);}
static __attribute__((unused)) bool g_is_gt_c_ss(const void* a, const void* b){return *((char*)a) > *((short*)b);}
static __attribute__((unused)) bool g_is_gt_c_si(const void* a, const void* b){return *((char*)a) > *((int*)b);}
static __attribute__((unused)) bool g_is_gt_c_sl(const void* a, const void* b){return *((char*)a) > *((long*)b);}
static __attribute__((unused)) bool g_is_gt_c_ul(const void* a, const void* b){return *((char*)a) > *((unsigned long*)b);}
static __attribute__((unused)) bool g_is_gt_c_f(const void* a, const void* b){return *((char*)a) > *((float*)b);}
static __attribute__((unused)) bool g_is_gt_c_d(const void* a, const void* b){return *((char*)a) > *((double*)b);}
static __attribute__((unused)) bool g_is_gt_ss_b(const void* a, const void* b){return *((short*)a) > *((bool*)b);}
static __attribute__((unused)) bool g_is_gt_ss_c(const void* a, const void* b){return *((short*)a) > *((char*)b);}
static __attribute__((unused)) bool g_is_gt_ss_ss(const void* a, const void* b){return *((short*)a) > *((short*)b);}
static __attribute__((unused)) bool g_is_gt_ss_si(const void* a, const void* b){return *((short*)a) > *((int*)b);}
static __attribute__((unused)) bool g_is_gt_ss_sl(const void* a, const void* b){return *((short*)a) > *((long*)b);}
static __attribute__((unused)) bool g_is_gt_ss_ul(const void* a, const void* b){return *((short*)a) > *((unsigned long*)b);}
static __attribute__((unused)) bool g_is_gt_ss_f(const void* a, const void* b){return *((short*)a) > *((float*)b);}
static __attribute__((unused)) bool g_is_gt_ss_d(const void* a, const void* b){return *((short*)a) > *((double*)b);}
static __attribute__((unused)) bool g_is_gt_si_b(const void* a, const void* b){return *((int*)a) > *((bool*)b);}
static __attribute__((unused)) bool g_is_gt_si_c(const void* a, const void* b){return *((int*)a) > *((char*)b);}
static __attribute__((unused)) bool g_is_gt_si_ss(const void* a, const void* b){return *((int*)a) > *((short*)b);}
static __attribute__((unused)) bool g_is_gt_si_si(const void* a, const void* b){return *((int*)a) > *((int*)b);}
static __attribute__((unused)) bool g_is_gt_si_sl(const void* a, const void* b){return *((int*)a) > *((long*)b);}
static __attribute__((unused)) bool g_is_gt_si_ul(const void* a, const void* b){return *((int*)a) > *((unsigned long*)b);}
static __attribute__((unused)) bool g_is_gt_si_f(const void* a, const void* b){return *((int*)a) > *((float*)b);}
static __attribute__((unused)) bool g_is_gt_si_d(const void* a, const void* b){return *((int*)a) > *((double*)b);}
static __attribute__((unused)) bool g_is_gt_sl_b(const void* a, const void* b){return *((long*)a) > *((bool*)b);}
static __attribute__((unused)) bool g_is_gt_sl_c(const void* a, const void* b){return *((long*)a) > *((char*)b);}
static __attribute__((unused)) bool g_is_gt_sl_ss(const void* a, const void* b){return *((long*)a) > *((short*)b);}
static __attribute__((unused)) bool g_is_gt_sl_si(const void* a, const void* b){return *((long*)a) > *((int*)b);}
static __attribute__((unused)) bool g_is_gt_sl_sl(const void* a, const void* b){return *((long*)a) > *((long*)b);}
static __attribute__((unused)) bool g_is_gt_sl_ul(const void* a, const void* b){return *((long*)a) > *((unsigned long*)b);}
static __attribute__((unused)) bool g_is_gt_sl_f(const void* a, const void* b){return *((long*)a) > *((float*)b);}
static __attribute__((unused)) bool g_is_gt_sl_d(const void* a, const void* b){return *((long*)a) > *((double*)b);}
static __attribute__((unused)) bool g_is_gt_ul_b(const void* a, const void* b){return *((unsigned long*)a) > *((bool*)b);}
static __attribute__((unused)) bool g_is_gt_ul_c(const void* a, const void* b){return *((unsigned long*)a) > *((char*)b);}
static __attribute__((unused)) bool g_is_gt_ul_ss(const void* a, const void* b){return *((unsigned long*)a) > *((short*)b);}
static __attribute__((unused)) bool g_is_gt_ul_si(const void* a, const void* b){return *((unsigned long*)a) > *((int*)b);}
static __attribute__((unused)) bool g_is_gt_ul_sl(const void* a, const void* b){return *((unsigned long*)a) > *((long*)b);}
static __attribute__((unused)) bool g_is_gt_ul_ul(const void* a, const void* b){return *((unsigned long*)a) > *((unsigned long*)b);}
static __attribute__((unused)) bool g_is_gt_ul_f(const void* a, const void* b){return *((unsigned long*)a) > *((float*)b);}
static __attribute__((unused)) bool g_is_gt_ul_d(const void* a, const void* b){return *((unsigned long*)a) > *((double*)b);}
static __attribute__((unused)) bool g_is_gt_f_b(const void* a, const void* b){return *((float*)a) > *((bool*)b);}
static __attribute__((unused)) bool g_is_gt_f_c(const void* a, const void* b){return *((float*)a) > *((char*)b);}
static __attribute__((unused)) bool g_is_gt_f_ss(const void* a, const void* b){return *((float*)a) > *((short*)b);}
static __attribute__((unused)) bool g_is_gt_f_si(const void* a, const void* b){return *((float*)a) > *((int*)b);}
static __attribute__((unused)) bool g_is_gt_f_sl(const void* a, const void* b){return *((float*)a) > *((long*)b);}
static __attribute__((unused)) bool g_is_gt_f_ul(const void* a, const void* b){return *((float*)a) > *((unsigned long*)b);}
static __attribute__((unused)) bool g_is_gt_f_f(const void* a, const void* b){return *((float*)a) > *((float*)b);}
static __attribute__((unused)) bool g_is_gt_f_d(const void* a, const void* b){return *((float*)a) > *((double*)b);}
static __attribute__((unused)) bool g_is_gt_d_b(const void* a, const void* b){return *((double*)a) > *((bool*)b);}
static __attribute__((unused)) bool g_is_gt_d_c(const void* a, const void* b){return *((double*)a) > *((char*)b);}
static __attribute__((unused)) bool g_is_gt_d_ss(const void* a, const void* b){return *((double*)a) > *((short*)b);}
static __attribute__((unused)) bool g_is_gt_d_si(const void* a, const void* b){return *((double*)a) > *((int*)b);}
static __attribute__((unused)) bool g_is_gt_d_sl(const void* a, const void* b){return *((double*)a) > *((long*)b);}
static __attribute__((unused)) bool g_is_gt_d_ul(const void* a, const void* b){return *((double*)a) > *((unsigned long*)b);}
static __attribute__((unused)) bool g_is_gt_d_f(const void* a, const void* b){return *((double*)a) > *((float*)b);}
static __attribute__((unused)) bool g_is_gt_d_d(const void* a, const void* b){return *((double*)a) > *((double*)b);}
static __attribute__((unused)) bool g_is_lt_b_b(const void* a, const void* b){return *((bool*)a) < *((bool*)b);}
static __attribute__((unused)) bool g_is_lt_b_c(const void* a, const void* b){return *((bool*)a) < *((char*)b);}
static __attribute__((unused)) bool g_is_lt_b_ss(const void* a, const void* b){return *((bool*)a) < *((short*)b);}
static __attribute__((unused)) bool g_is_lt_b_si(const void* a, const void* b){return *((bool*)a) < *((int*)b);}
static __attribute__((unused)) bool g_is_lt_b_sl(const void* a, const void* b){return *((bool*)a) < *((long*)b);}
static __attribute__((unused)) bool g_is_lt_b_ul(const void* a, const void* b){return *((bool*)a) < *((unsigned long*)b);}
static __attribute__((unused)) bool g_is_lt_b_f(const void* a, const void* b){return *((bool*)a) < *((float*)b);}
static __attribute__((unused)) bool g_is_lt_b_d(const void* a, const void* b){return *((bool*)a) < *((double*)b);}
static __attribute__((unused)) bool g_is_lt_c_b(const void* a, const void* b){return *((char*)a) < *((bool*)b);}
static __attribute__((unused)) bool g_is_lt_c_c(const void* a, const void* b){return *((char*)a) < *((char*)b);}
static __attribute__((unused)) bool g_is_lt_c_ss(const void* a, const void* b){return *((char*)a) < *((short*)b);}
static __attribute__((unused)) bool g_is_lt_c_si(const void* a, const void* b){return *((char*)a) < *((int*)b);}
static __attribute__((unused)) bool g_is_lt_c_sl(const void* a, const void* b){return *((char*)a) < *((long*)b);}
static __attribute__((unused)) bool g_is_lt_c_ul(const void* a, const void* b){return *((char*)a) < *((unsigned long*)b);}
static __attribute__((unused)) bool g_is_lt_c_f(const void* a, const void* b){return *((char*)a) < *((float*)b);}
static __attribute__((unused)) bool g_is_lt_c_d(const void* a, const void* b){return *((char*)a) < *((double*)b);}
static __attribute__((unused)) bool g_is_lt_ss_b(const void* a, const void* b){return *((short*)a) < *((bool*)b);}
static __attribute__((unused)) bool g_is_lt_ss_c(const void* a, const void* b){return *((short*)a) < *((char*)b);}
static __attribute__((unused)) bool g_is_lt_ss_ss(const void* a, const void* b){return *((short*)a) < *((short*)b);}
static __attribute__((unused)) bool g_is_lt_ss_si(const void* a, const void* b){return *((short*)a) < *((int*)b);}
static __attribute__((unused)) bool g_is_lt_ss_sl(const void* a, const void* b){return *((short*)a) < *((long*)b);}
static __attribute__((unused)) bool g_is_lt_ss_ul(const void* a, const void* b){return *((short*)a) < *((unsigned long*)b);}
static __attribute__((unused)) bool g_is_lt_ss_f(const void* a, const void* b){return *((short*)a) < *((float*)b);}
static __attribute__((unused)) bool g_is_lt_ss_d(const void* a, const void* b){return *((short*)a) < *((double*)b);}
static __attribute__((unused)) bool g_is_lt_si_b(const void* a, const void* b){return *((int*)a) < *((bool*)b);}
static __attribute__((unused)) bool g_is_lt_si_c(const void* a, const void* b){return *((int*)a) < *((char*)b);}
static __attribute__((unused)) bool g_is_lt_si_ss(const void* a, const void* b){return *((int*)a) < *((short*)b);}
static __attribute__((unused)) bool g_is_lt_si_si(const void* a, const void* b){return *((int*)a) < *((int*)b);}
static __attribute__((unused)) bool g_is_lt_si_sl(const void* a, const void* b){return *((int*)a) < *((long*)b);}
static __attribute__((unused)) bool g_is_lt_si_ul(const void* a, const void* b){return *((int*)a) < *((unsigned long*)b);}
static __attribute__((unused)) bool g_is_lt_si_f(const void* a, const void* b){return *((int*)a) < *((float*)b);}
static __attribute__((unused)) bool g_is_lt_si_d(const void* a, const void* b){return *((int*)a) < *((double*)b);}
static __attribute__((unused)) bool g_is_lt_sl_b(const void* a, const void* b){return *((long*)a) < *((bool*)b);}
static __attribute__((unused)) bool g_is_lt_sl_c(const void* a, const void* b){return *((long*)a) < *((char*)b);}
static __attribute__((unused)) bool g_is_lt_sl_ss(const void* a, const void* b){return *((long*)a) < *((short*)b);}
static __attribute__((unused)) bool g_is_lt_sl_si(const void* a, const void* b){return *((long*)a) < *((int*)b);}
static __attribute__((unused)) bool g_is_lt_sl_sl(const void* a, const void* b){return *((long*)a) < *((long*)b);}
static __attribute__((unused)) bool g_is_lt_sl_ul(const void* a, const void* b){return *((long*)a) < *((unsigned long*)b);}
static __attribute__((unused)) bool g_is_lt_sl_f(const void* a, const void* b){return *((long*)a) < *((float*)b);}
static __attribute__((unused)) bool g_is_lt_sl_d(const void* a, const void* b){return *((long*)a) < *((double*)b);}
static __attribute__((unused)) bool g_is_lt_ul_b(const void* a, const void* b){return *((unsigned long*)a) < *((bool*)b);}
static __attribute__((unused)) bool g_is_lt_ul_c(const void* a, const void* b){return *((unsigned long*)a) < *((char*)b);}
static __attribute__((unused)) bool g_is_lt_ul_ss(const void* a, const void* b){return *((unsigned long*)a) < *((short*)b);}
static __attribute__((unused)) bool g_is_lt_ul_si(const void* a, const void* b){return *((unsigned long*)a) < *((int*)b);}
static __attribute__((unused)) bool g_is_lt_ul_sl(const void* a, const void* b){return *((unsigned long*)a) < *((long*)b);}
static __attribute__((unused)) bool g_is_lt_ul_ul(const void* a, const void* b){return *((unsigned long*)a) < *((unsigned long*)b);}
static __attribute__((unused)) bool g_is_lt_ul_f(const void* a, const void* b){return *((unsigned long*)a) < *((float*)b);}
static __attribute__((unused)) bool g_is_lt_ul_d(const void* a, const void* b){return *((unsigned long*)a) < *((double*)b);}
static __attribute__((unused)) bool g_is_lt_f_b(const void* a, const void* b){return *((float*)a) < *((bool*)b);}
static __attribute__((unused)) bool g_is_lt_f_c(const void* a, const void* b){return *((float*)a) < *((char*)b);}
static __attribute__((unused)) bool g_is_lt_f_ss(const void* a, const void* b){return *((float*)a) < *((short*)b);}
static __attribute__((unused)) bool g_is_lt_f_si(const void* a, const void* b){return *((float*)a) < *((int*)b);}
static __attribute__((unused)) bool g_is_lt_f_sl(const void* a, const void* b){return *((float*)a) < *((long*)b);}
static __attribute__((unused)) bool g_is_lt_f_ul(const void* a, const void* b){return *((float*)a) < *((unsigned long*)b);}
static __attribute__((unused)) bool g_is_lt_f_f(const void* a, const void* b){return *((float*)a) < *((float*)b);}
static __attribute__((unused)) bool g_is_lt_f_d(const void* a, const void* b){return *((float*)a) < *((double*)b);}
static __attribute__((unused)) bool g_is_lt_d_b(const void* a, const void* b){return *((double*)a) < *((bool*)b);}
static __attribute__((unused)) bool g_is_lt_d_c(const void* a, const void* b){return *((double*)a) < *((char*)b);}
static __attribute__((unused)) bool g_is_lt_d_ss(const void* a, const void* b){return *((double*)a) < *((short*)b);}
static __attribute__((unused)) bool g_is_lt_d_si(const void* a, const void* b){return *((double*)a) < *((int*)b);}
static __attribute__((unused)) bool g_is_lt_d_sl(const void* a, const void* b){return *((double*)a) < *((long*)b);}
static __attribute__((unused)) bool g_is_lt_d_ul(const void* a, const void* b){return *((double*)a) < *((unsigned long*)b);}
static __attribute__((unused)) bool g_is_lt_d_f(const void* a, const void* b){return *((double*)a) < *((float*)b);}
static __attribute__((unused)) bool g_is_lt_d_d(const void* a, const void* b){return *((double*)a) < *((double*)b);}
static __attribute__((unused)) bool g_is_ge_b_b(const void* a, const void* b){return *((bool*)a) >= *((bool*)b);}
static __attribute__((unused)) bool g_is_ge_b_c(const void* a, const void* b){return *((bool*)a) >= *((char*)b);}
static __attribute__((unused)) bool g_is_ge_b_ss(const void* a, const void* b){return *((bool*)a) >= *((short*)b);}
static __attribute__((unused)) bool g_is_ge_b_si(const void* a, const void* b){return *((bool*)a) >= *((int*)b);}
static __attribute__((unused)) bool g_is_ge_b_sl(const void* a, const void* b){return *((bool*)a) >= *((long*)b);}
static __attribute__((unused)) bool g_is_ge_b_ul(const void* a, const void* b){return *((bool*)a) >= *((unsigned long*)b);}
static __attribute__((unused)) bool g_is_ge_b_f(const void* a, const void* b){return *((bool*)a) >= *((float*)b);}
static __attribute__((unused)) bool g_is_ge_b_d(const void* a, const void* b){return *((bool*)a) >= *((double*)b);}
static __attribute__((unused)) bool g_is_ge_c_b(const void* a, const void* b){return *((char*)a) >= *((bool*)b);}
static __attribute__((unused)) bool g_is_ge_c_c(const void* a, const void* b){return *((char*)a) >= *((char*)b);}
static __attribute__((unused)) bool g_is_ge_c_ss(const void* a, const void* b){return *((char*)a) >= *((short*)b);}
static __attribute__((unused)) bool g_is_ge_c_si(const void* a, const void* b){return *((char*)a) >= *((int*)b);}
static __attribute__((unused)) bool g_is_ge_c_sl(const void* a, const void* b){return *((char*)a) >= *((long*)b);}
static __attribute__((unused)) bool g_is_ge_c_ul(const void* a, const void* b){return *((char*)a) >= *((unsigned long*)b);}
static __attribute__((unused)) bool g_is_ge_c_f(const void* a, const void* b){return *((char*)a) >= *((float*)b);}
static __attribute__((unused)) bool g_is_ge_c_d(const void* a, const void* b){return *((char*)a) >= *((double*)b);}
static __attribute__((unused)) bool g_is_ge_ss_b(const void* a, const void* b){return *((short*)a) >= *((bool*)b);}
static __attribute__((unused)) bool g_is_ge_ss_c(const void* a, const void* b){return *((short*)a) >= *((char*)b);}
static __attribute__((unused)) bool g_is_ge_ss_ss(const void* a, const void* b){return *((short*)a) >= *((short*)b);}
static __attribute__((unused)) bool g_is_ge_ss_si(const void* a, const void* b){return *((short*)a) >= *((int*)b);}
static __attribute__((unused)) bool g_is_ge_ss_sl(const void* a, const void* b){return *((short*)a) >= *((long*)b);}
static __attribute__((unused)) bool g_is_ge_ss_ul(const void* a, const void* b){return *((short*)a) >= *((unsigned long*)b);}
static __attribute__((unused)) bool g_is_ge_ss_f(const void* a, const void* b){return *((short*)a) >= *((float*)b);}
static __attribute__((unused)) bool g_is_ge_ss_d(const void* a, const void* b){return *((short*)a) >= *((double*)b);}
static __attribute__((unused)) bool g_is_ge_si_b(const void* a, const void* b){return *((int*)a) >= *((bool*)b);}
static __attribute__((unused)) bool g_is_ge_si_c(const void* a, const void* b){return *((int*)a) >= *((char*)b);}
static __attribute__((unused)) bool g_is_ge_si_ss(const void* a, const void* b){return *((int*)a) >= *((short*)b);}
static __attribute__((unused)) bool g_is_ge_si_si(const void* a, const void* b){return *((int*)a) >= *((int*)b);}
static __attribute__((unused)) bool g_is_ge_si_sl(const void* a, const void* b){return *((int*)a) >= *((long*)b);}
static __attribute__((unused)) bool g_is_ge_si_ul(const void* a, const void* b){return *((int*)a) >= *((unsigned long*)b);}
static __attribute__((unused)) bool g_is_ge_si_f(const void* a, const void* b){return *((int*)a) >= *((float*)b);}
static __attribute__((unused)) bool g_is_ge_si_d(const void* a, const void* b){return *((int*)a) >= *((double*)b);}
static __attribute__((unused)) bool g_is_ge_sl_b(const void* a, const void* b){return *((long*)a) >= *((bool*)b);}
static __attribute__((unused)) bool g_is_ge_sl_c(const void* a, const void* b){return *((long*)a) >= *((char*)b);}
static __attribute__((unused)) bool g_is_ge_sl_ss(const void* a, const void* b){return *((long*)a) >= *((short*)b);}
static __attribute__((unused)) bool g_is_ge_sl_si(const void* a, const void* b){return *((long*)a) >= *((int*)b);}
static __attribute__((unused)) bool g_is_ge_sl_sl(const void* a, const void* b){return *((long*)a) >= *((long*)b);}
static __attribute__((unused)) bool g_is_ge_sl_ul(const void* a, const void* b){return *((long*)a) >= *((unsigned long*)b);}
static __attribute__((unused)) bool g_is_ge_sl_f(const void* a, const void* b){return *((long*)a) >= *((float*)b);}
static __attribute__((unused)) bool g_is_ge_sl_d(const void* a, const void* b){return *((long*)a) >= *((double*)b);}
static __attribute__((unused)) bool g_is_ge_ul_b(const void* a, const void* b){return *((unsigned long*)a) >= *((bool*)b);}
static __attribute__((unused)) bool g_is_ge_ul_c(const void* a, const void* b){return *((unsigned long*)a) >= *((char*)b);}
static __attribute__((unused)) bool g_is_ge_ul_ss(const void* a, const void* b){return *((unsigned long*)a) >= *((short*)b);}
static __attribute__((unused)) bool g_is_ge_ul_si(const void* a, const void* b){return *((unsigned long*)a) >= *((int*)b);}
static __attribute__((unused)) bool g_is_ge_ul_sl(const void* a, const void* b){return *((unsigned long*)a) >= *((long*)b);}
static __attribute__((unused)) bool g_is_ge_ul_ul(const void* a, const void* b){return *((unsigned long*)a) >= *((unsigned long*)b);}
static __attribute__((unused)) bool g_is_ge_ul_f(const void* a, const void* b){return *((unsigned long*)a) >= *((float*)b);}
static __attribute__((unused)) bool g_is_ge_ul_d(const void* a, const void* b){return *((unsigned long*)a) >= *((double*)b);}
static __attribute__((unused)) bool g_is_ge_f_b(const void* a, const void* b){return *((float*)a) >= *((bool*)b);}
static __attribute__((unused)) bool g_is_ge_f_c(const void* a, const void* b){return *((float*)a) >= *((char*)b);}
static __attribute__((unused)) bool g_is_ge_f_ss(const void* a, const void* b){return *((float*)a) >= *((short*)b);}
static __attribute__((unused)) bool g_is_ge_f_si(const void* a, const void* b){return *((float*)a) >= *((int*)b);}
static __attribute__((unused)) bool g_is_ge_f_sl(const void* a, const void* b){return *((float*)a) >= *((long*)b);}
static __attribute__((unused)) bool g_is_ge_f_ul(const void* a, const void* b){return *((float*)a) >= *((unsigned long*)b);}
static __attribute__((unused)) bool g_is_ge_f_f(const void* a, const void* b){return *((float*)a) >= *((float*)b);}
static __attribute__((unused)) bool g_is_ge_f_d(const void* a, const void* b){return *((float*)a) >= *((double*)b);}
static __attribute__((unused)) bool g_is_ge_d_b(const void* a, const void* b){return *((double*)a) >= *((bool*)b);}
static __attribute__((unused)) bool g_is_ge_d_c(const void* a, const void* b){return *((double*)a) >= *((char*)b);}
static __attribute__((unused)) bool g_is_ge_d_ss(const void* a, const void* b){return *((double*)a) >= *((short*)b);}
static __attribute__((unused)) bool g_is_ge_d_si(const void* a, const void* b){return *((double*)a) >= *((int*)b);}
static __attribute__((unused)) bool g_is_ge_d_sl(const void* a, const void* b){return *((double*)a) >= *((long*)b);}
static __attribute__((unused)) bool g_is_ge_d_ul(const void* a, const void* b){return *((double*)a) >= *((unsigned long*)b);}
static __attribute__((unused)) bool g_is_ge_d_f(const void* a, const void* b){return *((double*)a) >= *((float*)b);}
static __attribute__((unused)) bool g_is_ge_d_d(const void* a, const void* b){return *((double*)a) >= *((double*)b);}
static __attribute__((unused)) bool g_is_le_b_b(const void* a, const void* b){return *((bool*)a) <= *((bool*)b);}
static __attribute__((unused)) bool g_is_le_b_c(const void* a, const void* b){return *((bool*)a) <= *((char*)b);}
static __attribute__((unused)) bool g_is_le_b_ss(const void* a, const void* b){return *((bool*)a) <= *((short*)b);}
static __attribute__((unused)) bool g_is_le_b_si(const void* a, const void* b){return *((bool*)a) <= *((int*)b);}
static __attribute__((unused)) bool g_is_le_b_sl(const void* a, const void* b){return *((bool*)a) <= *((long*)b);}
static __attribute__((unused)) bool g_is_le_b_ul(const void* a, const void* b){return *((bool*)a) <= *((unsigned long*)b);}
static __attribute__((unused)) bool g_is_le_b_f(const void* a, const void* b){return *((bool*)a) <= *((float*)b);}
static __attribute__((unused)) bool g_is_le_b_d(const void* a, const void* b){return *((bool*)a) <= *((double*)b);}
static __attribute__((unused)) bool g_is_le_c_b(const void* a, const void* b){return *((char*)a) <= *((bool*)b);}
static __attribute__((unused)) bool g_is_le_c_c(const void* a, const void* b){return *((char*)a) <= *((char*)b);}
static __attribute__((unused)) bool g_is_le_c_ss(const void* a, const void* b){return *((char*)a) <= *((short*)b);}
static __attribute__((unused)) bool g_is_le_c_si(const void* a, const void* b){return *((char*)a) <= *((int*)b);}
static __attribute__((unused)) bool g_is_le_c_sl(const void* a, const void* b){return *((char*)a) <= *((long*)b);}
static __attribute__((unused)) bool g_is_le_c_ul(const void* a, const void* b){return *((char*)a) <= *((unsigned long*)b);}
static __attribute__((unused)) bool g_is_le_c_f(const void* a, const void* b){return *((char*)a) <= *((float*)b);}
static __attribute__((unused)) bool g_is_le_c_d(const void* a, const void* b){return *((char*)a) <= *((double*)b);}
static __attribute__((unused)) bool g_is_le_ss_b(const void* a, const void* b){return *((short*)a) <= *((bool*)b);}
static __attribute__((unused)) bool g_is_le_ss_c(const void* a, const void* b){return *((short*)a) <= *((char*)b);}
static __attribute__((unused)) bool g_is_le_ss_ss(const void* a, const void* b){return *((short*)a) <= *((short*)b);}
static __attribute__((unused)) bool g_is_le_ss_si(const void* a, const void* b){return *((short*)a) <= *((int*)b);}
static __attribute__((unused)) bool g_is_le_ss_sl(const void* a, const void* b){return *((short*)a) <= *((long*)b);}
static __attribute__((unused)) bool g_is_le_ss_ul(const void* a, const void* b){return *((short*)a) <= *((unsigned long*)b);}
static __attribute__((unused)) bool g_is_le_ss_f(const void* a, const void* b){return *((short*)a) <= *((float*)b);}
static __attribute__((unused)) bool g_is_le_ss_d(const void* a, const void* b){return *((short*)a) <= *((double*)b);}
static __attribute__((unused)) bool g_is_le_si_b(const void* a, const void* b){return *((int*)a) <= *((bool*)b);}
static __attribute__((unused)) bool g_is_le_si_c(const void* a, const void* b){return *((int*)a) <= *((char*)b);}
static __attribute__((unused)) bool g_is_le_si_ss(const void* a, const void* b){return *((int*)a) <= *((short*)b);}
static __attribute__((unused)) bool g_is_le_si_si(const void* a, const void* b){return *((int*)a) <= *((int*)b);}
static __attribute__((unused)) bool g_is_le_si_sl(const void* a, const void* b){return *((int*)a) <= *((long*)b);}
static __attribute__((unused)) bool g_is_le_si_ul(const void* a, const void* b){return *((int*)a) <= *((unsigned long*)b);}
static __attribute__((unused)) bool g_is_le_si_f(const void* a, const void* b){return *((int*)a) <= *((float*)b);}
static __attribute__((unused)) bool g_is_le_si_d(const void* a, const void* b){return *((int*)a) <= *((double*)b);}
static __attribute__((unused)) bool g_is_le_sl_b(const void* a, const void* b){return *((long*)a) <= *((bool*)b);}
static __attribute__((unused)) bool g_is_le_sl_c(const void* a, const void* b){return *((long*)a) <= *((char*)b);}
static __attribute__((unused)) bool g_is_le_sl_ss(const void* a, const void* b){return *((long*)a) <= *((short*)b);}
static __attribute__((unused)) bool g_is_le_sl_si(const void* a, const void* b){return *((long*)a) <= *((int*)b);}
static __attribute__((unused)) bool g_is_le_sl_sl(const void* a, const void* b){return *((long*)a) <= *((long*)b);}
static __attribute__((unused)) bool g_is_le_sl_ul(const void* a, const void* b){return *((long*)a) <= *((unsigned long*)b);}
static __attribute__((unused)) bool g_is_le_sl_f(const void* a, const void* b){return *((long*)a) <= *((float*)b);}
static __attribute__((unused)) bool g_is_le_sl_d(const void* a, const void* b){return *((long*)a) <= *((double*)b);}
static __attribute__((unused)) bool g_is_le_ul_b(const void* a, const void* b){return *((unsigned long*)a) <= *((bool*)b);}
static __attribute__((unused)) bool g_is_le_ul_c(const void* a, const void* b){return *((unsigned long*)a) <= *((char*)b);}
static __attribute__((unused)) bool g_is_le_ul_ss(const void* a, const void* b){return *((unsigned long*)a) <= *((short*)b);}
static __attribute__((unused)) bool g_is_le_ul_si(const void* a, const void* b){return *((unsigned long*)a) <= *((int*)b);}
static __attribute__((unused)) bool g_is_le_ul_sl(const void* a, const void* b){return *((unsigned long*)a) <= *((long*)b);}
static __attribute__((unused)) bool g_is_le_ul_ul(const void* a, const void* b){return *((unsigned long*)a) <= *((unsigned long*)b);}
static __attribute__((unused)) bool g_is_le_ul_f(const void* a, const void* b){return *((unsigned long*)a) <= *((float*)b);}
static __attribute__((unused)) bool g_is_le_ul_d(const void* a, const void* b){return *((unsigned long*)a) <= *((double*)b);}
static __attribute__((unused)) bool g_is_le_f_b(const void* a, const void* b){return *((float*)a) <= *((bool*)b);}
static __attribute__((unused)) bool g_is_le_f_c(const void* a, const void* b){return *((float*)a) <= *((char*)b);}
static __attribute__((unused)) bool g_is_le_f_ss(const void* a, const void* b){return *((float*)a) <= *((short*)b);}
static __attribute__((unused)) bool g_is_le_f_si(const void* a, const void* b){return *((float*)a) <= *((int*)b);}
static __attribute__((unused)) bool g_is_le_f_sl(const void* a, const void* b){return *((float*)a) <= *((long*)b);}
static __attribute__((unused)) bool g_is_le_f_ul(const void* a, const void* b){return *((float*)a) <= *((unsigned long*)b);}
static __attribute__((unused)) bool g_is_le_f_f(const void* a, const void* b){return *((float*)a) <= *((float*)b);}
static __attribute__((unused)) bool g_is_le_f_d(const void* a, const void* b){return *((float*)a) <= *((double*)b);}
static __attribute__((unused)) bool g_is_le_d_b(const void* a, const void* b){return *((double*)a) <= *((bool*)b);}
static __attribute__((unused)) bool g_is_le_d_c(const void* a, const void* b){return *((double*)a) <= *((char*)b);}
static __attribute__((unused)) bool g_is_le_d_ss(const void* a, const void* b){return *((double*)a) <= *((short*)b);}
static __attribute__((unused)) bool g_is_le_d_si(const void* a, const void* b){return *((double*)a) <= *((int*)b);}
static __attribute__((unused)) bool g_is_le_d_sl(const void* a, const void* b){return *((double*)a) <= *((long*)b);}
static __attribute__((unused)) bool g_is_le_d_ul(const void* a, const void* b){return *((double*)a) <= *((unsigned long*)b);}
static __attribute__((unused)) bool g_is_le_d_f(const void* a, const void* b){return *((double*)a) <= *((float*)b);}
static __attribute__((unused)) bool g_is_le_d_d(const void* a, const void* b){return *((double*)a) <= *((double*)b);}
static __attribute__((unused)) int g_cmp_b_b(const void* a, const void* b){if(*((bool*)a) < *((bool*)b))return -1; if(*((bool*)a) > *((bool*)b))return 1; return 0;}
static __attribute__((unused)) int g_cmp_b_c(const void* a, const void* b){if(*((bool*)a) < *((char*)b))return -1; if(*((bool*)a) > *((char*)b))return 1; return 0;}
static __attribute__((unused)) int g_cmp_b_ss(const void* a, const void* b){if(*((bool*)a) < *((short*)b))return -1; if(*((bool*)a) > *((short*)b))return 1; return 0;}
static __attribute__((unused)) int g_cmp_b_si(const void* a, const void* b){if(*((bool*)a) < *((int*)b))return -1; if(*((bool*)a) > *((int*)b))return 1; return 0;}
static __attribute__((unused)) int g_cmp_b_sl(const void* a, const void* b){if(*((bool*)a) < *((long*)b))return -1; if(*((bool*)a) > *((long*)b))return 1; return 0;}
static __attribute__((unused)) int g_cmp_b_ul(const void* a, const void* b){if(*((bool*)a) < *((unsigned long*)b))return -1; if(*((bool*)a) > *((unsigned long*)b))return 1; return 0;}
static __attribute__((unused)) int g_cmp_b_f(const void* a, const void* b){if(*((bool*)a) < *((float*)b))return -1; if(*((bool*)a) > *((float*)b))return 1; return 0;}
static __attribute__((unused)) int g_cmp_b_d(const void* a, const void* b){if(*((bool*)a) < *((double*)b))return -1; if(*((bool*)a) > *((double*)b))return 1; return 0;}
static __attribute__((unused)) int g_cmp_c_b(const void* a, const void* b){if(*((char*)a) < *((bool*)b))return -1; if(*((char*)a) > *((bool*)b))return 1; return 0;}
static __attribute__((unused)) int g_cmp_c_c(const void* a, const void* b){if(*((char*)a) < *((char*)b))return -1; if(*((char*)a) > *((char*)b))return 1; return 0;}
static __attribute__((unused)) int g_cmp_c_ss(const void* a, const void* b){if(*((char*)a) < *((short*)b))return -1; if(*((char*)a) > *((short*)b))return 1; return 0;}
static __attribute__((unused)) int g_cmp_c_si(const void* a, const void* b){if(*((char*)a) < *((int*)b))return -1; if(*((char*)a) > *((int*)b))return 1; return 0;}
static __attribute__((unused)) int g_cmp_c_sl(const void* a, const void* b){if(*((char*)a) < *((long*)b))return -1; if(*((char*)a) > *((long*)b))return 1; return 0;}
static __attribute__((unused)) int g_cmp_c_ul(const void* a, const void* b){if(*((char*)a) < *((unsigned long*)b))return -1; if(*((char*)a) > *((unsigned long*)b))return 1; return 0;}
static __attribute__((unused)) int g_cmp_c_f(const void* a, const void* b){if(*((char*)a) < *((float*)b))return -1; if(*((char*)a) > *((float*)b))return 1; return 0;}
static __attribute__((unused)) int g_cmp_c_d(const void* a, const void* b){if(*((char*)a) < *((double*)b))return -1; if(*((char*)a) > *((double*)b))return 1; return 0;}
static __attribute__((unused)) int g_cmp_ss_b(const void* a, const void* b){if(*((short*)a) < *((bool*)b))return -1; if(*((short*)a) > *((bool*)b))return 1; return 0;}
static __attribute__((unused)) int g_cmp_ss_c(const void* a, const void* b){if(*((short*)a) < *((char*)b))return -1; if(*((short*)a) > *((char*)b))return 1; return 0;}
static __attribute__((unused)) int g_cmp_ss_ss(const void* a, const void* b){if(*((short*)a) < *((short*)b))return -1; if(*((short*)a) > *((short*)b))return 1; return 0;}
static __attribute__((unused)) int g_cmp_ss_si(const void* a, const void* b){if(*((short*)a) < *((int*)b))return -1; if(*((short*)a) > *((int*)b))return 1; return 0;}
static __attribute__((unused)) int g_cmp_ss_sl(const void* a, const void* b){if(*((short*)a) < *((long*)b))return -1; if(*((short*)a) > *((long*)b))return 1; return 0;}
static __attribute__((unused)) int g_cmp_ss_ul(const void* a, const void* b){if(*((short*)a) < *((unsigned long*)b))return -1; if(*((short*)a) > *((unsigned long*)b))return 1; return 0;}
static __attribute__((unused)) int g_cmp_ss_f(const void* a, const void* b){if(*((short*)a) < *((float*)b))return -1; if(*((short*)a) > *((float*)b))return 1; return 0;}
static __attribute__((unused)) int g_cmp_ss_d(const void* a, const void* b){if(*((short*)a) < *((double*)b))return -1; if(*((short*)a) > *((double*)b))return 1; return 0;}
static __attribute__((unused)) int g_cmp_si_b(const void* a, const void* b){if(*((int*)a) < *((bool*)b))return -1; if(*((int*)a) > *((bool*)b))return 1; return 0;}
static __attribute__((unused)) int g_cmp_si_c(const void* a, const void* b){if(*((int*)a) < *((char*)b))return -1; if(*((int*)a) > *((char*)b))return 1; return 0;}
static __attribute__((unused)) int g_cmp_si_ss(const void* a, const void* b){if(*((int*)a) < *((short*)b))return -1; if(*((int*)a) > *((short*)b))return 1; return 0;}
static __attribute__((unused)) int g_cmp_si_si(const void* a, const void* b){if(*((int*)a) < *((int*)b))return -1; if(*((int*)a) > *((int*)b))return 1; return 0;}
static __attribute__((unused)) int g_cmp_si_sl(const void* a, const void* b){if(*((int*)a) < *((long*)b))return -1; if(*((int*)a) > *((long*)b))return 1; return 0;}
static __attribute__((unused)) int g_cmp_si_ul(const void* a, const void* b){if(*((int*)a) < *((unsigned long*)b))return -1; if(*((int*)a) > *((unsigned long*)b))return 1; return 0;}
static __attribute__((unused)) int g_cmp_si_f(const void* a, const void* b){if(*((int*)a) < *((float*)b))return -1; if(*((int*)a) > *((float*)b))return 1; return 0;}
static __attribute__((unused)) int g_cmp_si_d(const void* a, const void* b){if(*((int*)a) < *((double*)b))return -1; if(*((int*)a) > *((double*)b))return 1; return 0;}
static __attribute__((unused)) int g_cmp_sl_b(const void* a, const void* b){if(*((long*)a) < *((bool*)b))return -1; if(*((long*)a) > *((bool*)b))return 1; return 0;}
static __attribute__((unused)) int g_cmp_sl_c(const void* a, const void* b){if(*((long*)a) < *((char*)b))return -1; if(*((long*)a) > *((char*)b))return 1; return 0;}
static __attribute__((unused)) int g_cmp_sl_ss(const void* a, const void* b){if(*((long*)a) < *((short*)b))return -1; if(*((long*)a) > *((short*)b))return 1; return 0;}
static __attribute__((unused)) int g_cmp_sl_si(const void* a, const void* b){if(*((long*)a) < *((int*)b))return -1; if(*((long*)a) > *((int*)b))return 1; return 0;}
static __attribute__((unused)) int g_cmp_sl_sl(const void* a, const void* b){if(*((long*)a) < *((long*)b))return -1; if(*((long*)a) > *((long*)b))return 1; return 0;}
static __attribute__((unused)) int g_cmp_sl_ul(const void* a, const void* b){if(*((long*)a) < *((unsigned long*)b))return -1; if(*((long*)a) > *((unsigned long*)b))return 1; return 0;}
static __attribute__((unused)) int g_cmp_sl_f(const void* a, const void* b){if(*((long*)a) < *((float*)b))return -1; if(*((long*)a) > *((float*)b))return 1; return 0;}
static __attribute__((unused)) int g_cmp_sl_d(const void* a, const void* b){if(*((long*)a) < *((double*)b))return -1; if(*((long*)a) > *((double*)b))return 1; return 0;}
static __attribute__((unused)) int g_cmp_ul_b(const void* a, const void* b){if(*((unsigned long*)a) < *((bool*)b))return -1; if(*((unsigned long*)a) > *((bool*)b))return 1; return 0;}
static __attribute__((unused)) int g_cmp_ul_c(const void* a, const void* b){if(*((unsigned long*)a) < *((char*)b))return -1; if(*((unsigned long*)a) > *((char*)b))return 1; return 0;}
static __attribute__((unused)) int g_cmp_ul_ss(const void* a, const void* b){if(*((unsigned long*)a) < *((short*)b))return -1; if(*((unsigned long*)a) > *((short*)b))return 1; return 0;}
static __attribute__((unused)) int g_cmp_ul_si(const void* a, const void* b){if(*((unsigned long*)a) < *((int*)b))return -1; if(*((unsigned long*)a) > *((int*)b))return 1; return 0;}
static __attribute__((unused)) int g_cmp_ul_sl(const void* a, const void* b){if(*((unsigned long*)a) < *((long*)b))return -1; if(*((unsigned long*)a) > *((long*)b))return 1; return 0;}
static __attribute__((unused)) int g_cmp_ul_ul(const void* a, const void* b){if(*((unsigned long*)a) < *((unsigned long*)b))return -1; if(*((unsigned long*)a) > *((unsigned long*)b))return 1; return 0;}
static __attribute__((unused)) int g_cmp_ul_f(const void* a, const void* b){if(*((unsigned long*)a) < *((float*)b))return -1; if(*((unsigned long*)a) > *((float*)b))return 1; return 0;}
static __attribute__((unused)) int g_cmp_ul_d(const void* a, const void* b){if(*((unsigned long*)a) < *((double*)b))return -1; if(*((unsigned long*)a) > *((double*)b))return 1; return 0;}
static __attribute__((unused)) int g_cmp_f_b(const void* a, const void* b){if(*((float*)a) < *((bool*)b))return -1; if(*((float*)a) > *((bool*)b))return 1; return 0;}
static __attribute__((unused)) int g_cmp_f_c(const void* a, const void* b){if(*((float*)a) < *((char*)b))return -1; if(*((float*)a) > *((char*)b))return 1; return 0;}
static __attribute__((unused)) int g_cmp_f_ss(const void* a, const void* b){if(*((float*)a) < *((short*)b))return -1; if(*((float*)a) > *((short*)b))return 1; return 0;}
static __attribute__((unused)) int g_cmp_f_si(const void* a, const void* b){if(*((float*)a) < *((int*)b))return -1; if(*((float*)a) > *((int*)b))return 1; return 0;}
static __attribute__((unused)) int g_cmp_f_sl(const void* a, const void* b){if(*((float*)a) < *((long*)b))return -1; if(*((float*)a) > *((long*)b))return 1; return 0;}
static __attribute__((unused)) int g_cmp_f_ul(const void* a, const void* b){if(*((float*)a) < *((unsigned long*)b))return -1; if(*((float*)a) > *((unsigned long*)b))return 1; return 0;}
static __attribute__((unused)) int g_cmp_f_f(const void* a, const void* b){if(*((float*)a) < *((float*)b))return -1; if(*((float*)a) > *((float*)b))return 1; return 0;}
static __attribute__((unused)) int g_cmp_f_d(const void* a, const void* b){if(*((float*)a) < *((double*)b))return -1; if(*((float*)a) > *((double*)b))return 1; return 0;}
static __attribute__((unused)) int g_cmp_d_b(const void* a, const void* b){if(*((double*)a) < *((bool*)b))return -1; if(*((double*)a) > *((bool*)b))return 1; return 0;}
static __attribute__((unused)) int g_cmp_d_c(const void* a, const void* b){if(*((double*)a) < *((char*)b))return -1; if(*((double*)a) > *((char*)b))return 1; return 0;}
static __attribute__((unused)) int g_cmp_d_ss(const void* a, const void* b){if(*((double*)a) < *((short*)b))return -1; if(*((double*)a) > *((short*)b))return 1; return 0;}
static __attribute__((unused)) int g_cmp_d_si(const void* a, const void* b){if(*((double*)a) < *((int*)b))return -1; if(*((double*)a) > *((int*)b))return 1; return 0;}
static __attribute__((unused)) int g_cmp_d_sl(const void* a, const void* b){if(*((double*)a) < *((long*)b))return -1; if(*((double*)a) > *((long*)b))return 1; return 0;}
static __attribute__((unused)) int g_cmp_d_ul(const void* a, const void* b){if(*((double*)a) < *((unsigned long*)b))return -1; if(*((double*)a) > *((unsigned long*)b))return 1; return 0;}
static __attribute__((unused)) int g_cmp_d_f(const void* a, const void* b){if(*((double*)a) < *((float*)b))return -1; if(*((double*)a) > *((float*)b))return 1; return 0;}
static __attribute__((unused)) int g_cmp_d_d(const void* a, const void* b){if(*((double*)a) < *((double*)b))return -1; if(*((double*)a) > *((double*)b))return 1; return 0;}
static __attribute__((unused)) void g_add_b_b(void* r, const void* a, const void* b){*(g_ptr_from_void((bool){0} + (bool){0})(r)) = *((bool*)a) + *((bool*)b);}
static __attribute__((unused)) void g_add_b_c(void* r, const void* a, const void* b){*(g_ptr_from_void((bool){0} + (char){0})(r)) = *((bool*)a) + *((char*)b);}
static __attribute__((unused)) void g_add_b_ss(void* r, const void* a, const void* b){*(g_ptr_from_void((bool){0} + (short){0})(r)) = *((bool*)a) + *((short*)b);}
static __attribute__((unused)) void g_add_b_si(void* r, const void* a, const void* b){*(g_ptr_from_void((bool){0} + (int){0})(r)) = *((bool*)a) + *((int*)b);}
static __attribute__((unused)) void g_add_b_sl(void* r, const void* a, const void* b){*(g_ptr_from_void((bool){0} + (long){0})(r)) = *((bool*)a) + *((long*)b);}
static __attribute__((unused)) void g_add_b_ul(void* r, const void* a, const void* b){*(g_ptr_from_void((bool){0} + (unsigned long){0})(r)) = *((bool*)a) + *((unsigned long*)b);}
static __attribute__((unused)) void g_add_b_f(void* r, const void* a, const void* b){*(g_ptr_from_void((bool){0} + (float){0})(r)) = *((bool*)a) + *((float*)b);}
static __attribute__((unused)) void g_add_b_d(void* r, const void* a, const void* b){*(g_ptr_from_void((bool){0} + (double){0})(r)) = *((bool*)a) + *((double*)b);}
static __attribute__((unused)) void g_add_c_b(void* r, const void* a, const void* b){*(g_ptr_from_void((char){0} + (bool){0})(r)) = *((char*)a) + *((bool*)b);}
static __attribute__((unused)) void g_add_c_c(void* r, const void* a, const void* b){*(g_ptr_from_void((char){0} + (char){0})(r)) = *((char*)a) + *((char*)b);}
static __attribute__((unused)) void g_add_c_ss(void* r, const void* a, const void* b){*(g_ptr_from_void((char){0} + (short){0})(r)) = *((char*)a) + *((short*)b);}
static __attribute__((unused)) void g_add_c_si(void* r, const void* a, const void* b){*(g_ptr_from_void((char){0} + (int){0})(r)) = *((char*)a) + *((int*)b);}
static __attribute__((unused)) void g_add_c_sl(void* r, const void* a, const void* b){*(g_ptr_from_void((char){0} + (long){0})(r)) = *((char*)a) + *((long*)b);}
static __attribute__((unused)) void g_add_c_ul(void* r, const void* a, const void* b){*(g_ptr_from_void((char){0} + (unsigned long){0})(r)) = *((char*)a) + *((unsigned long*)b);}
static __attribute__((unused)) void g_add_c_f(void* r, const void* a, const void* b){*(g_ptr_from_void((char){0} + (float){0})(r)) = *((char*)a) + *((float*)b);}
static __attribute__((unused)) void g_add_c_d(void* r, const void* a, const void* b){*(g_ptr_from_void((char){0} + (double){0})(r)) = *((char*)a) + *((double*)b);}
static __attribute__((unused)) void g_add_ss_b(void* r, const void* a, const void* b){*(g_ptr_from_void((short){0} + (bool){0})(r)) = *((short*)a) + *((bool*)b);}
static __attribute__((unused)) void g_add_ss_c(void* r, const void* a, const void* b){*(g_ptr_from_void((short){0} + (char){0})(r)) = *((short*)a) + *((char*)b);}
static __attribute__((unused)) void g_add_ss_ss(void* r, const void* a, const void* b){*(g_ptr_from_void((short){0} + (short){0})(r)) = *((short*)a) + *((short*)b);}
static __attribute__((unused)) void g_add_ss_si(void* r, const void* a, const void* b){*(g_ptr_from_void((short){0} + (int){0})(r)) = *((short*)a) + *((int*)b);}
static __attribute__((unused)) void g_add_ss_sl(void* r, const void* a, const void* b){*(g_ptr_from_void((short){0} + (long){0})(r)) = *((short*)a) + *((long*)b);}
static __attribute__((unused)) void g_add_ss_ul(void* r, const void* a, const void* b){*(g_ptr_from_void((short){0} + (unsigned long){0})(r)) = *((short*)a) + *((unsigned long*)b);}
static __attribute__((unused)) void g_add_ss_f(void* r, const void* a, const void* b){*(g_ptr_from_void((short){0} + (float){0})(r)) = *((short*)a) + *((float*)b);}
static __attribute__((unused)) void g_add_ss_d(void* r, const void* a, const void* b){*(g_ptr_from_void((short){0} + (double){0})(r)) = *((short*)a) + *((double*)b);}
static __attribute__((unused)) void g_add_si_b(void* r, const void* a, const void* b){*(g_ptr_from_void((int){0} + (bool){0})(r)) = *((int*)a) + *((bool*)b);}
static __attribute__((unused)) void g_add_si_c(void* r, const void* a, const void* b){*(g_ptr_from_void((int){0} + (char){0})(r)) = *((int*)a) + *((char*)b);}
static __attribute__((unused)) void g_add_si_ss(void* r, const void* a, const void* b){*(g_ptr_from_void((int){0} + (short){0})(r)) = *((int*)a) + *((short*)b);}
static __attribute__((unused)) void g_add_si_si(void* r, const void* a, const void* b){*(g_ptr_from_void((int){0} + (int){0})(r)) = *((int*)a) + *((int*)b);}
static __attribute__((unused)) void g_add_si_sl(void* r, const void* a, const void* b){*(g_ptr_from_void((int){0} + (long){0})(r)) = *((int*)a) + *((long*)b);}
static __attribute__((unused)) void g_add_si_ul(void* r, const void* a, const void* b){*(g_ptr_from_void((int){0} + (unsigned long){0})(r)) = *((int*)a) + *((unsigned long*)b);}
static __attribute__((unused)) void g_add_si_f(void* r, const void* a, const void* b){*(g_ptr_from_void((int){0} + (float){0})(r)) = *((int*)a) + *((float*)b);}
static __attribute__((unused)) void g_add_si_d(void* r, const void* a, const void* b){*(g_ptr_from_void((int){0} + (double){0})(r)) = *((int*)a) + *((double*)b);}
static __attribute__((unused)) void g_add_sl_b(void* r, const void* a, const void* b){*(g_ptr_from_void((long){0} + (bool){0})(r)) = *((long*)a) + *((bool*)b);}
static __attribute__((unused)) void g_add_sl_c(void* r, const void* a, const void* b){*(g_ptr_from_void((long){0} + (char){0})(r)) = *((long*)a) + *((char*)b);}
static __attribute__((unused)) void g_add_sl_ss(void* r, const void* a, const void* b){*(g_ptr_from_void((long){0} + (short){0})(r)) = *((long*)a) + *((short*)b);}
static __attribute__((unused)) void g_add_sl_si(void* r, const void* a, const void* b){*(g_ptr_from_void((long){0} + (int){0})(r)) = *((long*)a) + *((int*)b);}
static __attribute__((unused)) void g_add_sl_sl(void* r, const void* a, const void* b){*(g_ptr_from_void((long){0} + (long){0})(r)) = *((long*)a) + *((long*)b);}
static __attribute__((unused)) void g_add_sl_ul(void* r, const void* a, const void* b){*(g_ptr_from_void((long){0} + (unsigned long){0})(r)) = *((long*)a) + *((unsigned long*)b);}
static __attribute__((unused)) void g_add_sl_f(void* r, const void* a, const void* b){*(g_ptr_from_void((long){0} + (float){0})(r)) = *((long*)a) + *((float*)b);}
static __attribute__((unused)) void g_add_sl_d(void* r, const void* a, const void* b){*(g_ptr_from_void((long){0} + (double){0})(r)) = *((long*)a) + *((double*)b);}
static __attribute__((unused)) void g_add_ul_b(void* r, const void* a, const void* b){*(g_ptr_from_void((unsigned long){0} + (bool){0})(r)) = *((unsigned long*)a) + *((bool*)b);}
static __attribute__((unused)) void g_add_ul_c(void* r, const void* a, const void* b){*(g_ptr_from_void((unsigned long){0} + (char){0})(r)) = *((unsigned long*)a) + *((char*)b);}
static __attribute__((unused)) void g_add_ul_ss(void* r, const void* a, const void* b){*(g_ptr_from_void((unsigned long){0} + (short){0})(r)) = *((unsigned long*)a) + *((short*)b);}
static __attribute__((unused)) void g_add_ul_si(void* r, const void* a, const void* b){*(g_ptr_from_void((unsigned long){0} + (int){0})(r)) = *((unsigned long*)a) + *((int*)b);}
static __attribute__((unused)) void g_add_ul_sl(void* r, const void* a, const void* b){*(g_ptr_from_void((unsigned long){0} + (long){0})(r)) = *((unsigned long*)a) + *((long*)b);}
static __attribute__((unused)) void g_add_ul_ul(void* r, const void* a, const void* b){*(g_ptr_from_void((unsigned long){0} + (unsigned long){0})(r)) = *((unsigned long*)a) + *((unsigned long*)b);}
static __attribute__((unused)) void g_add_ul_f(void* r, const void* a, const void* b){*(g_ptr_from_void((unsigned long){0} + (float){0})(r)) = *((unsigned long*)a) + *((float*)b);}
static __attribute__((unused)) void g_add_ul_d(void* r, const void* a, const void* b){*(g_ptr_from_void((unsigned long){0} + (double){0})(r)) = *((unsigned long*)a) + *((double*)b);}
static __attribute__((unused)) void g_add_f_b(void* r, const void* a, const void* b){*(g_ptr_from_void((float){0} + (bool){0})(r)) = *((float*)a) + *((bool*)b);}
static __attribute__((unused)) void g_add_f_c(void* r, const void* a, const void* b){*(g_ptr_from_void((float){0} + (char){0})(r)) = *((float*)a) + *((char*)b);}
static __attribute__((unused)) void g_add_f_ss(void* r, const void* a, const void* b){*(g_ptr_from_void((float){0} + (short){0})(r)) = *((float*)a) + *((short*)b);}
static __attribute__((unused)) void g_add_f_si(void* r, const void* a, const void* b){*(g_ptr_from_void((float){0} + (int){0})(r)) = *((float*)a) + *((int*)b);}
static __attribute__((unused)) void g_add_f_sl(void* r, const void* a, const void* b){*(g_ptr_from_void((float){0} + (long){0})(r)) = *((float*)a) + *((long*)b);}
static __attribute__((unused)) void g_add_f_ul(void* r, const void* a, const void* b){*(g_ptr_from_void((float){0} + (unsigned long){0})(r)) = *((float*)a) + *((unsigned long*)b);}
static __attribute__((unused)) void g_add_f_f(void* r, const void* a, const void* b){*(g_ptr_from_void((float){0} + (float){0})(r)) = *((float*)a) + *((float*)b);}
static __attribute__((unused)) void g_add_f_d(void* r, const void* a, const void* b){*(g_ptr_from_void((float){0} + (double){0})(r)) = *((float*)a) + *((double*)b);}
static __attribute__((unused)) void g_add_d_b(void* r, const void* a, const void* b){*(g_ptr_from_void((double){0} + (bool){0})(r)) = *((double*)a) + *((bool*)b);}
static __attribute__((unused)) void g_add_d_c(void* r, const void* a, const void* b){*(g_ptr_from_void((double){0} + (char){0})(r)) = *((double*)a) + *((char*)b);}
static __attribute__((unused)) void g_add_d_ss(void* r, const void* a, const void* b){*(g_ptr_from_void((double){0} + (short){0})(r)) = *((double*)a) + *((short*)b);}
static __attribute__((unused)) void g_add_d_si(void* r, const void* a, const void* b){*(g_ptr_from_void((double){0} + (int){0})(r)) = *((double*)a) + *((int*)b);}
static __attribute__((unused)) void g_add_d_sl(void* r, const void* a, const void* b){*(g_ptr_from_void((double){0} + (long){0})(r)) = *((double*)a) + *((long*)b);}
static __attribute__((unused)) void g_add_d_ul(void* r, const void* a, const void* b){*(g_ptr_from_void((double){0} + (unsigned long){0})(r)) = *((double*)a) + *((unsigned long*)b);}
static __attribute__((unused)) void g_add_d_f(void* r, const void* a, const void* b){*(g_ptr_from_void((double){0} + (float){0})(r)) = *((double*)a) + *((float*)b);}
static __attribute__((unused)) void g_add_d_d(void* r, const void* a, const void* b){*(g_ptr_from_void((double){0} + (double){0})(r)) = *((double*)a) + *((double*)b);}
static __attribute__((unused)) void g_sub_b_b(void* r, const void* a, const void* b){*(g_ptr_from_void((bool){0} - (bool){0})(r)) = *((bool*)a) - *((bool*)b);}
static __attribute__((unused)) void g_sub_b_c(void* r, const void* a, const void* b){*(g_ptr_from_void((bool){0} - (char){0})(r)) = *((bool*)a) - *((char*)b);}
static __attribute__((unused)) void g_sub_b_ss(void* r, const void* a, const void* b){*(g_ptr_from_void((bool){0} - (short){0})(r)) = *((bool*)a) - *((short*)b);}
static __attribute__((unused)) void g_sub_b_si(void* r, const void* a, const void* b){*(g_ptr_from_void((bool){0} - (int){0})(r)) = *((bool*)a) - *((int*)b);}
static __attribute__((unused)) void g_sub_b_sl(void* r, const void* a, const void* b){*(g_ptr_from_void((bool){0} - (long){0})(r)) = *((bool*)a) - *((long*)b);}
static __attribute__((unused)) void g_sub_b_ul(void* r, const void* a, const void* b){*(g_ptr_from_void((bool){0} - (unsigned long){0})(r)) = *((bool*)a) - *((unsigned long*)b);}
static __attribute__((unused)) void g_sub_b_f(void* r, const void* a, const void* b){*(g_ptr_from_void((bool){0} - (float){0})(r)) = *((bool*)a) - *((float*)b);}
static __attribute__((unused)) void g_sub_b_d(void* r, const void* a, const void* b){*(g_ptr_from_void((bool){0} - (double){0})(r)) = *((bool*)a) - *((double*)b);}
static __attribute__((unused)) void g_sub_c_b(void* r, const void* a, const void* b){*(g_ptr_from_void((char){0} - (bool){0})(r)) = *((char*)a) - *((bool*)b);}
static __attribute__((unused)) void g_sub_c_c(void* r, const void* a, const void* b){*(g_ptr_from_void((char){0} - (char){0})(r)) = *((char*)a) - *((char*)b);}
static __attribute__((unused)) void g_sub_c_ss(void* r, const void* a, const void* b){*(g_ptr_from_void((char){0} - (short){0})(r)) = *((char*)a) - *((short*)b);}
static __attribute__((unused)) void g_sub_c_si(void* r, const void* a, const void* b){*(g_ptr_from_void((char){0} - (int){0})(r)) = *((char*)a) - *((int*)b);}
static __attribute__((unused)) void g_sub_c_sl(void* r, const void* a, const void* b){*(g_ptr_from_void((char){0} - (long){0})(r)) = *((char*)a) - *((long*)b);}
static __attribute__((unused)) void g_sub_c_ul(void* r, const void* a, const void* b){*(g_ptr_from_void((char){0} - (unsigned long){0})(r)) = *((char*)a) - *((unsigned long*)b);}
static __attribute__((unused)) void g_sub_c_f(void* r, const void* a, const void* b){*(g_ptr_from_void((char){0} - (float){0})(r)) = *((char*)a) - *((float*)b);}
static __attribute__((unused)) void g_sub_c_d(void* r, const void* a, const void* b){*(g_ptr_from_void((char){0} - (double){0})(r)) = *((char*)a) - *((double*)b);}
static __attribute__((unused)) void g_sub_ss_b(void* r, const void* a, const void* b){*(g_ptr_from_void((short){0} - (bool){0})(r)) = *((short*)a) - *((bool*)b);}
static __attribute__((unused)) void g_sub_ss_c(void* r, const void* a, const void* b){*(g_ptr_from_void((short){0} - (char){0})(r)) = *((short*)a) - *((char*)b);}
static __attribute__((unused)) void g_sub_ss_ss(void* r, const void* a, const void* b){*(g_ptr_from_void((short){0} - (short){0})(r)) = *((short*)a) - *((short*)b);}
static __attribute__((unused)) void g_sub_ss_si(void* r, const void* a, const void* b){*(g_ptr_from_void((short){0} - (int){0})(r)) = *((short*)a) - *((int*)b);}
static __attribute__((unused)) void g_sub_ss_sl(void* r, const void* a, const void* b){*(g_ptr_from_void((short){0} - (long){0})(r)) = *((short*)a) - *((long*)b);}
static __attribute__((unused)) void g_sub_ss_ul(void* r, const void* a, const void* b){*(g_ptr_from_void((short){0} - (unsigned long){0})(r)) = *((short*)a) - *((unsigned long*)b);}
static __attribute__((unused)) void g_sub_ss_f(void* r, const void* a, const void* b){*(g_ptr_from_void((short){0} - (float){0})(r)) = *((short*)a) - *((float*)b);}
static __attribute__((unused)) void g_sub_ss_d(void* r, const void* a, const void* b){*(g_ptr_from_void((short){0} - (double){0})(r)) = *((short*)a) - *((double*)b);}
static __attribute__((unused)) void g_sub_si_b(void* r, const void* a, const void* b){*(g_ptr_from_void((int){0} - (bool){0})(r)) = *((int*)a) - *((bool*)b);}
static __attribute__((unused)) void g_sub_si_c(void* r, const void* a, const void* b){*(g_ptr_from_void((int){0} - (char){0})(r)) = *((int*)a) - *((char*)b);}
static __attribute__((unused)) void g_sub_si_ss(void* r, const void* a, const void* b){*(g_ptr_from_void((int){0} - (short){0})(r)) = *((int*)a) - *((short*)b);}
static __attribute__((unused)) void g_sub_si_si(void* r, const void* a, const void* b){*(g_ptr_from_void((int){0} - (int){0})(r)) = *((int*)a) - *((int*)b);}
static __attribute__((unused)) void g_sub_si_sl(void* r, const void* a, const void* b){*(g_ptr_from_void((int){0} - (long){0})(r)) = *((int*)a) - *((long*)b);}
static __attribute__((unused)) void g_sub_si_ul(void* r, const void* a, const void* b){*(g_ptr_from_void((int){0} - (unsigned long){0})(r)) = *((int*)a) - *((unsigned long*)b);}
static __attribute__((unused)) void g_sub_si_f(void* r, const void* a, const void* b){*(g_ptr_from_void((int){0} - (float){0})(r)) = *((int*)a) - *((float*)b);}
static __attribute__((unused)) void g_sub_si_d(void* r, const void* a, const void* b){*(g_ptr_from_void((int){0} - (double){0})(r)) = *((int*)a) - *((double*)b);}
static __attribute__((unused)) void g_sub_sl_b(void* r, const void* a, const void* b){*(g_ptr_from_void((long){0} - (bool){0})(r)) = *((long*)a) - *((bool*)b);}
static __attribute__((unused)) void g_sub_sl_c(void* r, const void* a, const void* b){*(g_ptr_from_void((long){0} - (char){0})(r)) = *((long*)a) - *((char*)b);}
static __attribute__((unused)) void g_sub_sl_ss(void* r, const void* a, const void* b){*(g_ptr_from_void((long){0} - (short){0})(r)) = *((long*)a) - *((short*)b);}
static __attribute__((unused)) void g_sub_sl_si(void* r, const void* a, const void* b){*(g_ptr_from_void((long){0} - (int){0})(r)) = *((long*)a) - *((int*)b);}
static __attribute__((unused)) void g_sub_sl_sl(void* r, const void* a, const void* b){*(g_ptr_from_void((long){0} - (long){0})(r)) = *((long*)a) - *((long*)b);}
static __attribute__((unused)) void g_sub_sl_ul(void* r, const void* a, const void* b){*(g_ptr_from_void((long){0} - (unsigned long){0})(r)) = *((long*)a) - *((unsigned long*)b);}
static __attribute__((unused)) void g_sub_sl_f(void* r, const void* a, const void* b){*(g_ptr_from_void((long){0} - (float){0})(r)) = *((long*)a) - *((float*)b);}
static __attribute__((unused)) void g_sub_sl_d(void* r, const void* a, const void* b){*(g_ptr_from_void((long){0} - (double){0})(r)) = *((long*)a) - *((double*)b);}
static __attribute__((unused)) void g_sub_ul_b(void* r, const void* a, const void* b){*(g_ptr_from_void((unsigned long){0} - (bool){0})(r)) = *((unsigned long*)a) - *((bool*)b);}
static __attribute__((unused)) void g_sub_ul_c(void* r, const void* a, const void* b){*(g_ptr_from_void((unsigned long){0} - (char){0})(r)) = *((unsigned long*)a) - *((char*)b);}
static __attribute__((unused)) void g_sub_ul_ss(void* r, const void* a, const void* b){*(g_ptr_from_void((unsigned long){0} - (short){0})(r)) = *((unsigned long*)a) - *((short*)b);}
static __attribute__((unused)) void g_sub_ul_si(void* r, const void* a, const void* b){*(g_ptr_from_void((unsigned long){0} - (int){0})(r)) = *((unsigned long*)a) - *((int*)b);}
static __attribute__((unused)) void g_sub_ul_sl(void* r, const void* a, const void* b){*(g_ptr_from_void((unsigned long){0} - (long){0})(r)) = *((unsigned long*)a) - *((long*)b);}
static __attribute__((unused)) void g_sub_ul_ul(void* r, const void* a, const void* b){*(g_ptr_from_void((unsigned long){0} - (unsigned long){0})(r)) = *((unsigned long*)a) - *((unsigned long*)b);}
static __attribute__((unused)) void g_sub_ul_f(void* r, const void* a, const void* b){*(g_ptr_from_void((unsigned long){0} - (float){0})(r)) = *((unsigned long*)a) - *((float*)b);}
static __attribute__((unused)) void g_sub_ul_d(void* r, const void* a, const void* b){*(g_ptr_from_void((unsigned long){0} - (double){0})(r)) = *((unsigned long*)a) - *((double*)b);}
static __attribute__((unused)) void g_sub_f_b(void* r, const void* a, const void* b){*(g_ptr_from_void((float){0} - (bool){0})(r)) = *((float*)a) - *((bool*)b);}
static __attribute__((unused)) void g_sub_f_c(void* r, const void* a, const void* b){*(g_ptr_from_void((float){0} - (char){0})(r)) = *((float*)a) - *((char*)b);}
static __attribute__((unused)) void g_sub_f_ss(void* r, const void* a, const void* b){*(g_ptr_from_void((float){0} - (short){0})(r)) = *((float*)a) - *((short*)b);}
static __attribute__((unused)) void g_sub_f_si(void* r, const void* a, const void* b){*(g_ptr_from_void((float){0} - (int){0})(r)) = *((float*)a) - *((int*)b);}
static __attribute__((unused)) void g_sub_f_sl(void* r, const void* a, const void* b){*(g_ptr_from_void((float){0} - (long){0})(r)) = *((float*)a) - *((long*)b);}
static __attribute__((unused)) void g_sub_f_ul(void* r, const void* a, const void* b){*(g_ptr_from_void((float){0} - (unsigned long){0})(r)) = *((float*)a) - *((unsigned long*)b);}
static __attribute__((unused)) void g_sub_f_f(void* r, const void* a, const void* b){*(g_ptr_from_void((float){0} - (float){0})(r)) = *((float*)a) - *((float*)b);}
static __attribute__((unused)) void g_sub_f_d(void* r, const void* a, const void* b){*(g_ptr_from_void((float){0} - (double){0})(r)) = *((float*)a) - *((double*)b);}
static __attribute__((unused)) void g_sub_d_b(void* r, const void* a, const void* b){*(g_ptr_from_void((double){0} - (bool){0})(r)) = *((double*)a) - *((bool*)b);}
static __attribute__((unused)) void g_sub_d_c(void* r, const void* a, const void* b){*(g_ptr_from_void((double){0} - (char){0})(r)) = *((double*)a) - *((char*)b);}
static __attribute__((unused)) void g_sub_d_ss(void* r, const void* a, const void* b){*(g_ptr_from_void((double){0} - (short){0})(r)) = *((double*)a) - *((short*)b);}
static __attribute__((unused)) void g_sub_d_si(void* r, const void* a, const void* b){*(g_ptr_from_void((double){0} - (int){0})(r)) = *((double*)a) - *((int*)b);}
static __attribute__((unused)) void g_sub_d_sl(void* r, const void* a, const void* b){*(g_ptr_from_void((double){0} - (long){0})(r)) = *((double*)a) - *((long*)b);}
static __attribute__((unused)) void g_sub_d_ul(void* r, const void* a, const void* b){*(g_ptr_from_void((double){0} - (unsigned long){0})(r)) = *((double*)a) - *((unsigned long*)b);}
static __attribute__((unused)) void g_sub_d_f(void* r, const void* a, const void* b){*(g_ptr_from_void((double){0} - (float){0})(r)) = *((double*)a) - *((float*)b);}
static __attribute__((unused)) void g_sub_d_d(void* r, const void* a, const void* b){*(g_ptr_from_void((double){0} - (double){0})(r)) = *((double*)a) - *((double*)b);}
static __attribute__((unused)) void g_mul_b_b(void* r, const void* a, const void* b){*(g_ptr_from_void((bool){0} * (bool){0})(r)) = *((bool*)a) * *((bool*)b);}
static __attribute__((unused)) void g_mul_b_c(void* r, const void* a, const void* b){*(g_ptr_from_void((bool){0} * (char){0})(r)) = *((bool*)a) * *((char*)b);}
static __attribute__((unused)) void g_mul_b_ss(void* r, const void* a, const void* b){*(g_ptr_from_void((bool){0} * (short){0})(r)) = *((bool*)a) * *((short*)b);}
static __attribute__((unused)) void g_mul_b_si(void* r, const void* a, const void* b){*(g_ptr_from_void((bool){0} * (int){0})(r)) = *((bool*)a) * *((int*)b);}
static __attribute__((unused)) void g_mul_b_sl(void* r, const void* a, const void* b){*(g_ptr_from_void((bool){0} * (long){0})(r)) = *((bool*)a) * *((long*)b);}
static __attribute__((unused)) void g_mul_b_ul(void* r, const void* a, const void* b){*(g_ptr_from_void((bool){0} * (unsigned long){0})(r)) = *((bool*)a) * *((unsigned long*)b);}
static __attribute__((unused)) void g_mul_b_f(void* r, const void* a, const void* b){*(g_ptr_from_void((bool){0} * (float){0})(r)) = *((bool*)a) * *((float*)b);}
static __attribute__((unused)) void g_mul_b_d(void* r, const void* a, const void* b){*(g_ptr_from_void((bool){0} * (double){0})(r)) = *((bool*)a) * *((double*)b);}
static __attribute__((unused)) void g_mul_c_b(void* r, const void* a, const void* b){*(g_ptr_from_void((char){0} * (bool){0})(r)) = *((char*)a) * *((bool*)b);}
static __attribute__((unused)) void g_mul_c_c(void* r, const void* a, const void* b){*(g_ptr_from_void((char){0} * (char){0})(r)) = *((char*)a) * *((char*)b);}
static __attribute__((unused)) void g_mul_c_ss(void* r, const void* a, const void* b){*(g_ptr_from_void((char){0} * (short){0})(r)) = *((char*)a) * *((short*)b);}
static __attribute__((unused)) void g_mul_c_si(void* r, const void* a, const void* b){*(g_ptr_from_void((char){0} * (int){0})(r)) = *((char*)a) * *((int*)b);}
static __attribute__((unused)) void g_mul_c_sl(void* r, const void* a, const void* b){*(g_ptr_from_void((char){0} * (long){0})(r)) = *((char*)a) * *((long*)b);}
static __attribute__((unused)) void g_mul_c_ul(void* r, const void* a, const void* b){*(g_ptr_from_void((char){0} * (unsigned long){0})(r)) = *((char*)a) * *((unsigned long*)b);}
static __attribute__((unused)) void g_mul_c_f(void* r, const void* a, const void* b){*(g_ptr_from_void((char){0} * (float){0})(r)) = *((char*)a) * *((float*)b);}
static __attribute__((unused)) void g_mul_c_d(void* r, const void* a, const void* b){*(g_ptr_from_void((char){0} * (double){0})(r)) = *((char*)a) * *((double*)b);}
static __attribute__((unused)) void g_mul_ss_b(void* r, const void* a, const void* b){*(g_ptr_from_void((short){0} * (bool){0})(r)) = *((short*)a) * *((bool*)b);}
static __attribute__((unused)) void g_mul_ss_c(void* r, const void* a, const void* b){*(g_ptr_from_void((short){0} * (char){0})(r)) = *((short*)a) * *((char*)b);}
static __attribute__((unused)) void g_mul_ss_ss(void* r, const void* a, const void* b){*(g_ptr_from_void((short){0} * (short){0})(r)) = *((short*)a) * *((short*)b);}
static __attribute__((unused)) void g_mul_ss_si(void* r, const void* a, const void* b){*(g_ptr_from_void((short){0} * (int){0})(r)) = *((short*)a) * *((int*)b);}
static __attribute__((unused)) void g_mul_ss_sl(void* r, const void* a, const void* b){*(g_ptr_from_void((short){0} * (long){0})(r)) = *((short*)a) * *((long*)b);}
static __attribute__((unused)) void g_mul_ss_ul(void* r, const void* a, const void* b){*(g_ptr_from_void((short){0} * (unsigned long){0})(r)) = *((short*)a) * *((unsigned long*)b);}
static __attribute__((unused)) void g_mul_ss_f(void* r, const void* a, const void* b){*(g_ptr_from_void((short){0} * (float){0})(r)) = *((short*)a) * *((float*)b);}
static __attribute__((unused)) void g_mul_ss_d(void* r, const void* a, const void* b){*(g_ptr_from_void((short){0} * (double){0})(r)) = *((short*)a) * *((double*)b);}
static __attribute__((unused)) void g_mul_si_b(void* r, const void* a, const void* b){*(g_ptr_from_void((int){0} * (bool){0})(r)) = *((int*)a) * *((bool*)b);}
static __attribute__((unused)) void g_mul_si_c(void* r, const void* a, const void* b){*(g_ptr_from_void((int){0} * (char){0})(r)) = *((int*)a) * *((char*)b);}
static __attribute__((unused)) void g_mul_si_ss(void* r, const void* a, const void* b){*(g_ptr_from_void((int){0} * (short){0})(r)) = *((int*)a) * *((short*)b);}
static __attribute__((unused)) void g_mul_si_si(void* r, const void* a, const void* b){*(g_ptr_from_void((int){0} * (int){0})(r)) = *((int*)a) * *((int*)b);}
static __attribute__((unused)) void g_mul_si_sl(void* r, const void* a, const void* b){*(g_ptr_from_void((int){0} * (long){0})(r)) = *((int*)a) * *((long*)b);}
static __attribute__((unused)) void g_mul_si_ul(void* r, const void* a, const void* b){*(g_ptr_from_void((int){0} * (unsigned long){0})(r)) = *((int*)a) * *((unsigned long*)b);}
static __attribute__((unused)) void g_mul_si_f(void* r, const void* a, const void* b){*(g_ptr_from_void((int){0} * (float){0})(r)) = *((int*)a) * *((float*)b);}
static __attribute__((unused)) void g_mul_si_d(void* r, const void* a, const void* b){*(g_ptr_from_void((int){0} * (double){0})(r)) = *((int*)a) * *((double*)b);}
static __attribute__((unused)) void g_mul_sl_b(void* r, const void* a, const void* b){*(g_ptr_from_void((long){0} * (bool){0})(r)) = *((long*)a) * *((bool*)b);}
static __attribute__((unused)) void g_mul_sl_c(void* r, const void* a, const void* b){*(g_ptr_from_void((long){0} * (char){0})(r)) = *((long*)a) * *((char*)b);}
static __attribute__((unused)) void g_mul_sl_ss(void* r, const void* a, const void* b){*(g_ptr_from_void((long){0} * (short){0})(r)) = *((long*)a) * *((short*)b);}
static __attribute__((unused)) void g_mul_sl_si(void* r, const void* a, const void* b){*(g_ptr_from_void((long){0} * (int){0})(r)) = *((long*)a) * *((int*)b);}
static __attribute__((unused)) void g_mul_sl_sl(void* r, const void* a, const void* b){*(g_ptr_from_void((long){0} * (long){0})(r)) = *((long*)a) * *((long*)b);}
static __attribute__((unused)) void g_mul_sl_ul(void* r, const void* a, const void* b){*(g_ptr_from_void((long){0} * (unsigned long){0})(r)) = *((long*)a) * *((unsigned long*)b);}
static __attribute__((unused)) void g_mul_sl_f(void* r, const void* a, const void* b){*(g_ptr_from_void((long){0} * (float){0})(r)) = *((long*)a) * *((float*)b);}
static __attribute__((unused)) void g_mul_sl_d(void* r, const void* a, const void* b){*(g_ptr_from_void((long){0} * (double){0})(r)) = *((long*)a) * *((double*)b);}
static __attribute__((unused)) void g_mul_ul_b(void* r, const void* a, const void* b){*(g_ptr_from_void((unsigned long){0} * (bool){0})(r)) = *((unsigned long*)a) * *((bool*)b);}
static __attribute__((unused)) void g_mul_ul_c(void* r, const void* a, const void* b){*(g_ptr_from_void((unsigned long){0} * (char){0})(r)) = *((unsigned long*)a) * *((char*)b);}
static __attribute__((unused)) void g_mul_ul_ss(void* r, const void* a, const void* b){*(g_ptr_from_void((unsigned long){0} * (short){0})(r)) = *((unsigned long*)a) * *((short*)b);}
static __attribute__((unused)) void g_mul_ul_si(void* r, const void* a, const void* b){*(g_ptr_from_void((unsigned long){0} * (int){0})(r)) = *((unsigned long*)a) * *((int*)b);}
static __attribute__((unused)) void g_mul_ul_sl(void* r, const void* a, const void* b){*(g_ptr_from_void((unsigned long){0} * (long){0})(r)) = *((unsigned long*)a) * *((long*)b);}
static __attribute__((unused)) void g_mul_ul_ul(void* r, const void* a, const void* b){*(g_ptr_from_void((unsigned long){0} * (unsigned long){0})(r)) = *((unsigned long*)a) * *((unsigned long*)b);}
static __attribute__((unused)) void g_mul_ul_f(void* r, const void* a, const void* b){*(g_ptr_from_void((unsigned long){0} * (float){0})(r)) = *((unsigned long*)a) * *((float*)b);}
static __attribute__((unused)) void g_mul_ul_d(void* r, const void* a, const void* b){*(g_ptr_from_void((unsigned long){0} * (double){0})(r)) = *((unsigned long*)a) * *((double*)b);}
static __attribute__((unused)) void g_mul_f_b(void* r, const void* a, const void* b){*(g_ptr_from_void((float){0} * (bool){0})(r)) = *((float*)a) * *((bool*)b);}
static __attribute__((unused)) void g_mul_f_c(void* r, const void* a, const void* b){*(g_ptr_from_void((float){0} * (char){0})(r)) = *((float*)a) * *((char*)b);}
static __attribute__((unused)) void g_mul_f_ss(void* r, const void* a, const void* b){*(g_ptr_from_void((float){0} * (short){0})(r)) = *((float*)a) * *((short*)b);}
static __attribute__((unused)) void g_mul_f_si(void* r, const void* a, const void* b){*(g_ptr_from_void((float){0} * (int){0})(r)) = *((float*)a) * *((int*)b);}
static __attribute__((unused)) void g_mul_f_sl(void* r, const void* a, const void* b){*(g_ptr_from_void((float){0} * (long){0})(r)) = *((float*)a) * *((long*)b);}
static __attribute__((unused)) void g_mul_f_ul(void* r, const void* a, const void* b){*(g_ptr_from_void((float){0} * (unsigned long){0})(r)) = *((float*)a) * *((unsigned long*)b);}
static __attribute__((unused)) void g_mul_f_f(void* r, const void* a, const void* b){*(g_ptr_from_void((float){0} * (float){0})(r)) = *((float*)a) * *((float*)b);}
static __attribute__((unused)) void g_mul_f_d(void* r, const void* a, const void* b){*(g_ptr_from_void((float){0} * (double){0})(r)) = *((float*)a) * *((double*)b);}
static __attribute__((unused)) void g_mul_d_b(void* r, const void* a, const void* b){*(g_ptr_from_void((double){0} * (bool){0})(r)) = *((double*)a) * *((bool*)b);}
static __attribute__((unused)) void g_mul_d_c(void* r, const void* a, const void* b){*(g_ptr_from_void((double){0} * (char){0})(r)) = *((double*)a) * *((char*)b);}
static __attribute__((unused)) void g_mul_d_ss(void* r, const void* a, const void* b){*(g_ptr_from_void((double){0} * (short){0})(r)) = *((double*)a) * *((short*)b);}
static __attribute__((unused)) void g_mul_d_si(void* r, const void* a, const void* b){*(g_ptr_from_void((double){0} * (int){0})(r)) = *((double*)a) * *((int*)b);}
static __attribute__((unused)) void g_mul_d_sl(void* r, const void* a, const void* b){*(g_ptr_from_void((double){0} * (long){0})(r)) = *((double*)a) * *((long*)b);}
static __attribute__((unused)) void g_mul_d_ul(void* r, const void* a, const void* b){*(g_ptr_from_void((double){0} * (unsigned long){0})(r)) = *((double*)a) * *((unsigned long*)b);}
static __attribute__((unused)) void g_mul_d_f(void* r, const void* a, const void* b){*(g_ptr_from_void((double){0} * (float){0})(r)) = *((double*)a) * *((float*)b);}
static __attribute__((unused)) void g_mul_d_d(void* r, const void* a, const void* b){*(g_ptr_from_void((double){0} * (double){0})(r)) = *((double*)a) * *((double*)b);}
static __attribute__((unused)) void g_assign_b_b(void* r, const void* a){*((bool*)r) = (*((bool*)a));}
static __attribute__((unused)) void g_assign_b_c(void* r, const void* a){*((bool*)r) = (*((char*)a));}
static __attribute__((unused)) void g_assign_b_ss(void* r, const void* a){*((bool*)r) = (*((short*)a));}
static __attribute__((unused)) void g_assign_b_si(void* r, const void* a){*((bool*)r) = (*((int*)a));}
static __attribute__((unused)) void g_assign_b_sl(void* r, const void* a){*((bool*)r) = (*((long*)a));}
static __attribute__((unused)) void g_assign_b_ul(void* r, const void* a){*((bool*)r) = (*((unsigned long*)a));}
static __attribute__((unused)) void g_assign_b_f(void* r, const void* a){*((bool*)r) = (*((float*)a));}
static __attribute__((unused)) void g_assign_b_d(void* r, const void* a){*((bool*)r) = (*((double*)a));}
static __attribute__((unused)) void g_assign_c_b(void* r, const void* a){*((char*)r) = (*((bool*)a));}
static __attribute__((unused)) void g_assign_c_c(void* r, const void* a){*((char*)r) = (*((char*)a));}
static __attribute__((unused)) void g_assign_c_ss(void* r, const void* a){*((char*)r) = (*((short*)a));}
static __attribute__((unused)) void g_assign_c_si(void* r, const void* a){*((char*)r) = (*((int*)a));}
static __attribute__((unused)) void g_assign_c_sl(void* r, const void* a){*((char*)r) = (*((long*)a));}
static __attribute__((unused)) void g_assign_c_ul(void* r, const void* a){*((char*)r) = (*((unsigned long*)a));}
static __attribute__((unused)) void g_assign_c_f(void* r, const void* a){*((char*)r) = (*((float*)a));}
static __attribute__((unused)) void g_assign_c_d(void* r, const void* a){*((char*)r) = (*((double*)a));}
static __attribute__((unused)) void g_assign_ss_b(void* r, const void* a){*((short*)r) = (*((bool*)a));}
static __attribute__((unused)) void g_assign_ss_c(void* r, const void* a){*((short*)r) = (*((char*)a));}
static __attribute__((unused)) void g_assign_ss_ss(void* r, const void* a){*((short*)r) = (*((short*)a));}
static __attribute__((unused)) void g_assign_ss_si(void* r, const void* a){*((short*)r) = (*((int*)a));}
static __attribute__((unused)) void g_assign_ss_sl(void* r, const void* a){*((short*)r) = (*((long*)a));}
static __attribute__((unused)) void g_assign_ss_ul(void* r, const void* a){*((short*)r) = (*((unsigned long*)a));}
static __attribute__((unused)) void g_assign_ss_f(void* r, const void* a){*((short*)r) = (*((float*)a));}
static __attribute__((unused)) void g_assign_ss_d(void* r, const void* a){*((short*)r) = (*((double*)a));}
static __attribute__((unused)) void g_assign_si_b(void* r, const void* a){*((int*)r) = (*((bool*)a));}
static __attribute__((unused)) void g_assign_si_c(void* r, const void* a){*((int*)r) = (*((char*)a));}
static __attribute__((unused)) void g_assign_si_ss(void* r, const void* a){*((int*)r) = (*((short*)a));}
static __attribute__((unused)) void g_assign_si_si(void* r, const void* a){*((int*)r) = (*((int*)a));}
static __attribute__((unused)) void g_assign_si_sl(void* r, const void* a){*((int*)r) = (*((long*)a));}
static __attribute__((unused)) void g_assign_si_ul(void* r, const void* a){*((int*)r) = (*((unsigned long*)a));}
static __attribute__((unused)) void g_assign_si_f(void* r, const void* a){*((int*)r) = (*((float*)a));}
static __attribute__((unused)) void g_assign_si_d(void* r, const void* a){*((int*)r) = (*((double*)a));}
static __attribute__((unused)) void g_assign_sl_b(void* r, const void* a){*((long*)r) = (*((bool*)a));}
static __attribute__((unused)) void g_assign_sl_c(void* r, const void* a){*((long*)r) = (*((char*)a));}
static __attribute__((unused)) void g_assign_sl_ss(void* r, const void* a){*((long*)r) = (*((short*)a));}
static __attribute__((unused)) void g_assign_sl_si(void* r, const void* a){*((long*)r) = (*((int*)a));}
static __attribute__((unused)) void g_assign_sl_sl(void* r, const void* a){*((long*)r) = (*((long*)a));}
static __attribute__((unused)) void g_assign_sl_ul(void* r, const void* a){*((long*)r) = (*((unsigned long*)a));}
static __attribute__((unused)) void g_assign_sl_f(void* r, const void* a){*((long*)r) = (*((float*)a));}
static __attribute__((unused)) void g_assign_sl_d(void* r, const void* a){*((long*)r) = (*((double*)a));}
static __attribute__((unused)) void g_assign_ul_b(void* r, const void* a){*((unsigned long*)r) = (*((bool*)a));}
static __attribute__((unused)) void g_assign_ul_c(void* r, const void* a){*((unsigned long*)r) = (*((char*)a));}
static __attribute__((unused)) void g_assign_ul_ss(void* r, const void* a){*((unsigned long*)r) = (*((short*)a));}
static __attribute__((unused)) void g_assign_ul_si(void* r, const void* a){*((unsigned long*)r) = (*((int*)a));}
static __attribute__((unused)) void g_assign_ul_sl(void* r, const void* a){*((unsigned long*)r) = (*((long*)a));}
static __attribute__((unused)) void g_assign_ul_ul(void* r, const void* a){*((unsigned long*)r) = (*((unsigned long*)a));}
static __attribute__((unused)) void g_assign_ul_f(void* r, const void* a){*((unsigned long*)r) = (*((float*)a));}
static __attribute__((unused)) void g_assign_ul_d(void* r, const void* a){*((unsigned long*)r) = (*((double*)a));}
static __attribute__((unused)) void g_assign_f_b(void* r, const void* a){*((float*)r) = (*((bool*)a));}
static __attribute__((unused)) void g_assign_f_c(void* r, const void* a){*((float*)r) = (*((char*)a));}
static __attribute__((unused)) void g_assign_f_ss(void* r, const void* a){*((float*)r) = (*((short*)a));}
static __attribute__((unused)) void g_assign_f_si(void* r, const void* a){*((float*)r) = (*((int*)a));}
static __attribute__((unused)) void g_assign_f_sl(void* r, const void* a){*((float*)r) = (*((long*)a));}
static __attribute__((unused)) void g_assign_f_ul(void* r, const void* a){*((float*)r) = (*((unsigned long*)a));}
static __attribute__((unused)) void g_assign_f_f(void* r, const void* a){*((float*)r) = (*((float*)a));}
static __attribute__((unused)) void g_assign_f_d(void* r, const void* a){*((float*)r) = (*((double*)a));}
static __attribute__((unused)) void g_assign_d_b(void* r, const void* a){*((double*)r) = (*((bool*)a));}
static __attribute__((unused)) void g_assign_d_c(void* r, const void* a){*((double*)r) = (*((char*)a));}
static __attribute__((unused)) void g_assign_d_ss(void* r, const void* a){*((double*)r) = (*((short*)a));}
static __attribute__((unused)) void g_assign_d_si(void* r, const void* a){*((double*)r) = (*((int*)a));}
static __attribute__((unused)) void g_assign_d_sl(void* r, const void* a){*((double*)r) = (*((long*)a));}
static __attribute__((unused)) void g_assign_d_ul(void* r, const void* a){*((double*)r) = (*((unsigned long*)a));}
static __attribute__((unused)) void g_assign_d_f(void* r, const void* a){*((double*)r) = (*((float*)a));}
static __attribute__((unused)) void g_assign_d_d(void* r, const void* a){*((double*)r) = (*((double*)a));}
static __attribute__((unused)) void g_add_eq_b_b(void* r, const void* a){*((bool*)r) += (*((bool*)a));}
static __attribute__((unused)) void g_add_eq_b_c(void* r, const void* a){*((bool*)r) += (*((char*)a));}
static __attribute__((unused)) void g_add_eq_b_ss(void* r, const void* a){*((bool*)r) += (*((short*)a));}
static __attribute__((unused)) void g_add_eq_b_si(void* r, const void* a){*((bool*)r) += (*((int*)a));}
static __attribute__((unused)) void g_add_eq_b_sl(void* r, const void* a){*((bool*)r) += (*((long*)a));}
static __attribute__((unused)) void g_add_eq_b_ul(void* r, const void* a){*((bool*)r) += (*((unsigned long*)a));}
static __attribute__((unused)) void g_add_eq_b_f(void* r, const void* a){*((bool*)r) += (*((float*)a));}
static __attribute__((unused)) void g_add_eq_b_d(void* r, const void* a){*((bool*)r) += (*((double*)a));}
static __attribute__((unused)) void g_add_eq_c_b(void* r, const void* a){*((char*)r) += (*((bool*)a));}
static __attribute__((unused)) void g_add_eq_c_c(void* r, const void* a){*((char*)r) += (*((char*)a));}
static __attribute__((unused)) void g_add_eq_c_ss(void* r, const void* a){*((char*)r) += (*((short*)a));}
static __attribute__((unused)) void g_add_eq_c_si(void* r, const void* a){*((char*)r) += (*((int*)a));}
static __attribute__((unused)) void g_add_eq_c_sl(void* r, const void* a){*((char*)r) += (*((long*)a));}
static __attribute__((unused)) void g_add_eq_c_ul(void* r, const void* a){*((char*)r) += (*((unsigned long*)a));}
static __attribute__((unused)) void g_add_eq_c_f(void* r, const void* a){*((char*)r) += (*((float*)a));}
static __attribute__((unused)) void g_add_eq_c_d(void* r, const void* a){*((char*)r) += (*((double*)a));}
static __attribute__((unused)) void g_add_eq_ss_b(void* r, const void* a){*((short*)r) += (*((bool*)a));}
static __attribute__((unused)) void g_add_eq_ss_c(void* r, const void* a){*((short*)r) += (*((char*)a));}
static __attribute__((unused)) void g_add_eq_ss_ss(void* r, const void* a){*((short*)r) += (*((short*)a));}
static __attribute__((unused)) void g_add_eq_ss_si(void* r, const void* a){*((short*)r) += (*((int*)a));}
static __attribute__((unused)) void g_add_eq_ss_sl(void* r, const void* a){*((short*)r) += (*((long*)a));}
static __attribute__((unused)) void g_add_eq_ss_ul(void* r, const void* a){*((short*)r) += (*((unsigned long*)a));}
static __attribute__((unused)) void g_add_eq_ss_f(void* r, const void* a){*((short*)r) += (*((float*)a));}
static __attribute__((unused)) void g_add_eq_ss_d(void* r, const void* a){*((short*)r) += (*((double*)a));}
static __attribute__((unused)) void g_add_eq_si_b(void* r, const void* a){*((int*)r) += (*((bool*)a));}
static __attribute__((unused)) void g_add_eq_si_c(void* r, const void* a){*((int*)r) += (*((char*)a));}
static __attribute__((unused)) void g_add_eq_si_ss(void* r, const void* a){*((int*)r) += (*((short*)a));}
static __attribute__((unused)) void g_add_eq_si_si(void* r, const void* a){*((int*)r) += (*((int*)a));}
static __attribute__((unused)) void g_add_eq_si_sl(void* r, const void* a){*((int*)r) += (*((long*)a));}
static __attribute__((unused)) void g_add_eq_si_ul(void* r, const void* a){*((int*)r) += (*((unsigned long*)a));}
static __attribute__((unused)) void g_add_eq_si_f(void* r, const void* a){*((int*)r) += (*((float*)a));}
static __attribute__((unused)) void g_add_eq_si_d(void* r, const void* a){*((int*)r) += (*((double*)a));}
static __attribute__((unused)) void g_add_eq_sl_b(void* r, const void* a){*((long*)r) += (*((bool*)a));}
static __attribute__((unused)) void g_add_eq_sl_c(void* r, const void* a){*((long*)r) += (*((char*)a));}
static __attribute__((unused)) void g_add_eq_sl_ss(void* r, const void* a){*((long*)r) += (*((short*)a));}
static __attribute__((unused)) void g_add_eq_sl_si(void* r, const void* a){*((long*)r) += (*((int*)a));}
static __attribute__((unused)) void g_add_eq_sl_sl(void* r, const void* a){*((long*)r) += (*((long*)a));}
static __attribute__((unused)) void g_add_eq_sl_ul(void* r, const void* a){*((long*)r) += (*((unsigned long*)a));}
static __attribute__((unused)) void g_add_eq_sl_f(void* r, const void* a){*((long*)r) += (*((float*)a));}
static __attribute__((unused)) void g_add_eq_sl_d(void* r, const void* a){*((long*)r) += (*((double*)a));}
static __attribute__((unused)) void g_add_eq_ul_b(void* r, const void* a){*((unsigned long*)r) += (*((bool*)a));}
static __attribute__((unused)) void g_add_eq_ul_c(void* r, const void* a){*((unsigned long*)r) += (*((char*)a));}
static __attribute__((unused)) void g_add_eq_ul_ss(void* r, const void* a){*((unsigned long*)r) += (*((short*)a));}
static __attribute__((unused)) void g_add_eq_ul_si(void* r, const void* a){*((unsigned long*)r) += (*((int*)a));}
static __attribute__((unused)) void g_add_eq_ul_sl(void* r, const void* a){*((unsigned long*)r) += (*((long*)a));}
static __attribute__((unused)) void g_add_eq_ul_ul(void* r, const void* a){*((unsigned long*)r) += (*((unsigned long*)a));}
static __attribute__((unused)) void g_add_eq_ul_f(void* r, const void* a){*((unsigned long*)r) += (*((float*)a));}
static __attribute__((unused)) void g_add_eq_ul_d(void* r, const void* a){*((unsigned long*)r) += (*((double*)a));}
static __attribute__((unused)) void g_add_eq_f_b(void* r, const void* a){*((float*)r) += (*((bool*)a));}
static __attribute__((unused)) void g_add_eq_f_c(void* r, const void* a){*((float*)r) += (*((char*)a));}
static __attribute__((unused)) void g_add_eq_f_ss(void* r, const void* a){*((float*)r) += (*((short*)a));}
static __attribute__((unused)) void g_add_eq_f_si(void* r, const void* a){*((float*)r) += (*((int*)a));}
static __attribute__((unused)) void g_add_eq_f_sl(void* r, const void* a){*((float*)r) += (*((long*)a));}
static __attribute__((unused)) void g_add_eq_f_ul(void* r, const void* a){*((float*)r) += (*((unsigned long*)a));}
static __attribute__((unused)) void g_add_eq_f_f(void* r, const void* a){*((float*)r) += (*((float*)a));}
static __attribute__((unused)) void g_add_eq_f_d(void* r, const void* a){*((float*)r) += (*((double*)a));}
static __attribute__((unused)) void g_add_eq_d_b(void* r, const void* a){*((double*)r) += (*((bool*)a));}
static __attribute__((unused)) void g_add_eq_d_c(void* r, const void* a){*((double*)r) += (*((char*)a));}
static __attribute__((unused)) void g_add_eq_d_ss(void* r, const void* a){*((double*)r) += (*((short*)a));}
static __attribute__((unused)) void g_add_eq_d_si(void* r, const void* a){*((double*)r) += (*((int*)a));}
static __attribute__((unused)) void g_add_eq_d_sl(void* r, const void* a){*((double*)r) += (*((long*)a));}
static __attribute__((unused)) void g_add_eq_d_ul(void* r, const void* a){*((double*)r) += (*((unsigned long*)a));}
static __attribute__((unused)) void g_add_eq_d_f(void* r, const void* a){*((double*)r) += (*((float*)a));}
static __attribute__((unused)) void g_add_eq_d_d(void* r, const void* a){*((double*)r) += (*((double*)a));}
static __attribute__((unused)) void g_sub_eq_b_b(void* r, const void* a){*((bool*)r) -= (*((bool*)a));}
static __attribute__((unused)) void g_sub_eq_b_c(void* r, const void* a){*((bool*)r) -= (*((char*)a));}
static __attribute__((unused)) void g_sub_eq_b_ss(void* r, const void* a){*((bool*)r) -= (*((short*)a));}
static __attribute__((unused)) void g_sub_eq_b_si(void* r, const void* a){*((bool*)r) -= (*((int*)a));}
static __attribute__((unused)) void g_sub_eq_b_sl(void* r, const void* a){*((bool*)r) -= (*((long*)a));}
static __attribute__((unused)) void g_sub_eq_b_ul(void* r, const void* a){*((bool*)r) -= (*((unsigned long*)a));}
static __attribute__((unused)) void g_sub_eq_b_f(void* r, const void* a){*((bool*)r) -= (*((float*)a));}
static __attribute__((unused)) void g_sub_eq_b_d(void* r, const void* a){*((bool*)r) -= (*((double*)a));}
static __attribute__((unused)) void g_sub_eq_c_b(void* r, const void* a){*((char*)r) -= (*((bool*)a));}
static __attribute__((unused)) void g_sub_eq_c_c(void* r, const void* a){*((char*)r) -= (*((char*)a));}
static __attribute__((unused)) void g_sub_eq_c_ss(void* r, const void* a){*((char*)r) -= (*((short*)a));}
static __attribute__((unused)) void g_sub_eq_c_si(void* r, const void* a){*((char*)r) -= (*((int*)a));}
static __attribute__((unused)) void g_sub_eq_c_sl(void* r, const void* a){*((char*)r) -= (*((long*)a));}
static __attribute__((unused)) void g_sub_eq_c_ul(void* r, const void* a){*((char*)r) -= (*((unsigned long*)a));}
static __attribute__((unused)) void g_sub_eq_c_f(void* r, const void* a){*((char*)r) -= (*((float*)a));}
static __attribute__((unused)) void g_sub_eq_c_d(void* r, const void* a){*((char*)r) -= (*((double*)a));}
static __attribute__((unused)) void g_sub_eq_ss_b(void* r, const void* a){*((short*)r) -= (*((bool*)a));}
static __attribute__((unused)) void g_sub_eq_ss_c(void* r, const void* a){*((short*)r) -= (*((char*)a));}
static __attribute__((unused)) void g_sub_eq_ss_ss(void* r, const void* a){*((short*)r) -= (*((short*)a));}
static __attribute__((unused)) void g_sub_eq_ss_si(void* r, const void* a){*((short*)r) -= (*((int*)a));}
static __attribute__((unused)) void g_sub_eq_ss_sl(void* r, const void* a){*((short*)r) -= (*((long*)a));}
static __attribute__((unused)) void g_sub_eq_ss_ul(void* r, const void* a){*((short*)r) -= (*((unsigned long*)a));}
static __attribute__((unused)) void g_sub_eq_ss_f(void* r, const void* a){*((short*)r) -= (*((float*)a));}
static __attribute__((unused)) void g_sub_eq_ss_d(void* r, const void* a){*((short*)r) -= (*((double*)a));}
static __attribute__((unused)) void g_sub_eq_si_b(void* r, const void* a){*((int*)r) -= (*((bool*)a));}
static __attribute__((unused)) void g_sub_eq_si_c(void* r, const void* a){*((int*)r) -= (*((char*)a));}
static __attribute__((unused)) void g_sub_eq_si_ss(void* r, const void* a){*((int*)r) -= (*((short*)a));}
static __attribute__((unused)) void g_sub_eq_si_si(void* r, const void* a){*((int*)r) -= (*((int*)a));}
static __attribute__((unused)) void g_sub_eq_si_sl(void* r, const void* a){*((int*)r) -= (*((long*)a));}
static __attribute__((unused)) void g_sub_eq_si_ul(void* r, const void* a){*((int*)r) -= (*((unsigned long*)a));}
static __attribute__((unused)) void g_sub_eq_si_f(void* r, const void* a){*((int*)r) -= (*((float*)a));}
static __attribute__((unused)) void g_sub_eq_si_d(void* r, const void* a){*((int*)r) -= (*((double*)a));}
static __attribute__((unused)) void g_sub_eq_sl_b(void* r, const void* a){*((long*)r) -= (*((bool*)a));}
static __attribute__((unused)) void g_sub_eq_sl_c(void* r, const void* a){*((long*)r) -= (*((char*)a));}
static __attribute__((unused)) void g_sub_eq_sl_ss(void* r, const void* a){*((long*)r) -= (*((short*)a));}
static __attribute__((unused)) void g_sub_eq_sl_si(void* r, const void* a){*((long*)r) -= (*((int*)a));}
static __attribute__((unused)) void g_sub_eq_sl_sl(void* r, const void* a){*((long*)r) -= (*((long*)a));}
static __attribute__((unused)) void g_sub_eq_sl_ul(void* r, const void* a){*((long*)r) -= (*((unsigned long*)a));}
static __attribute__((unused)) void g_sub_eq_sl_f(void* r, const void* a){*((long*)r) -= (*((float*)a));}
static __attribute__((unused)) void g_sub_eq_sl_d(void* r, const void* a){*((long*)r) -= (*((double*)a));}
static __attribute__((unused)) void g_sub_eq_ul_b(void* r, const void* a){*((unsigned long*)r) -= (*((bool*)a));}
static __attribute__((unused)) void g_sub_eq_ul_c(void* r, const void* a){*((unsigned long*)r) -= (*((char*)a));}
static __attribute__((unused)) void g_sub_eq_ul_ss(void* r, const void* a){*((unsigned long*)r) -= (*((short*)a));}
static __attribute__((unused)) void g_sub_eq_ul_si(void* r, const void* a){*((unsigned long*)r) -= (*((int*)a));}
static __attribute__((unused)) void g_sub_eq_ul_sl(void* r, const void* a){*((unsigned long*)r) -= (*((long*)a));}
static __attribute__((unused)) void g_sub_eq_ul_ul(void* r, const void* a){*((unsigned long*)r) -= (*((unsigned long*)a));}
static __attribute__((unused)) void g_sub_eq_ul_f(void* r, const void* a){*((unsigned long*)r) -= (*((float*)a));}
static __attribute__((unused)) void g_sub_eq_ul_d(void* r, const void* a){*((unsigned long*)r) -= (*((double*)a));}
static __attribute__((unused)) void g_sub_eq_f_b(void* r, const void* a){*((float*)r) -= (*((bool*)a));}
static __attribute__((unused)) void g_sub_eq_f_c(void* r, const void* a){*((float*)r) -= (*((char*)a));}
static __attribute__((unused)) void g_sub_eq_f_ss(void* r, const void* a){*((float*)r) -= (*((short*)a));}
static __attribute__((unused)) void g_sub_eq_f_si(void* r, const void* a){*((float*)r) -= (*((int*)a));}
static __attribute__((unused)) void g_sub_eq_f_sl(void* r, const void* a){*((float*)r) -= (*((long*)a));}
static __attribute__((unused)) void g_sub_eq_f_ul(void* r, const void* a){*((float*)r) -= (*((unsigned long*)a));}
static __attribute__((unused)) void g_sub_eq_f_f(void* r, const void* a){*((float*)r) -= (*((float*)a));}
static __attribute__((unused)) void g_sub_eq_f_d(void* r, const void* a){*((float*)r) -= (*((double*)a));}
static __attribute__((unused)) void g_sub_eq_d_b(void* r, const void* a){*((double*)r) -= (*((bool*)a));}
static __attribute__((unused)) void g_sub_eq_d_c(void* r, const void* a){*((double*)r) -= (*((char*)a));}
static __attribute__((unused)) void g_sub_eq_d_ss(void* r, const void* a){*((double*)r) -= (*((short*)a));}
static __attribute__((unused)) void g_sub_eq_d_si(void* r, const void* a){*((double*)r) -= (*((int*)a));}
static __attribute__((unused)) void g_sub_eq_d_sl(void* r, const void* a){*((double*)r) -= (*((long*)a));}
static __attribute__((unused)) void g_sub_eq_d_ul(void* r, const void* a){*((double*)r) -= (*((unsigned long*)a));}
static __attribute__((unused)) void g_sub_eq_d_f(void* r, const void* a){*((double*)r) -= (*((float*)a));}
static __attribute__((unused)) void g_sub_eq_d_d(void* r, const void* a){*((double*)r) -= (*((double*)a));}
static __attribute__((unused)) void g_mul_eq_b_b(void* r, const void* a){*((bool*)r) *= (*((bool*)a));}
static __attribute__((unused)) void g_mul_eq_b_c(void* r, const void* a){*((bool*)r) *= (*((char*)a));}
static __attribute__((unused)) void g_mul_eq_b_ss(void* r, const void* a){*((bool*)r) *= (*((short*)a));}
static __attribute__((unused)) void g_mul_eq_b_si(void* r, const void* a){*((bool*)r) *= (*((int*)a));}
static __attribute__((unused)) void g_mul_eq_b_sl(void* r, const void* a){*((bool*)r) *= (*((long*)a));}
static __attribute__((unused)) void g_mul_eq_b_ul(void* r, const void* a){*((bool*)r) *= (*((unsigned long*)a));}
static __attribute__((unused)) void g_mul_eq_b_f(void* r, const void* a){*((bool*)r) *= (*((float*)a));}
static __attribute__((unused)) void g_mul_eq_b_d(void* r, const void* a){*((bool*)r) *= (*((double*)a));}
static __attribute__((unused)) void g_mul_eq_c_b(void* r, const void* a){*((char*)r) *= (*((bool*)a));}
static __attribute__((unused)) void g_mul_eq_c_c(void* r, const void* a){*((char*)r) *= (*((char*)a));}
static __attribute__((unused)) void g_mul_eq_c_ss(void* r, const void* a){*((char*)r) *= (*((short*)a));}
static __attribute__((unused)) void g_mul_eq_c_si(void* r, const void* a){*((char*)r) *= (*((int*)a));}
static __attribute__((unused)) void g_mul_eq_c_sl(void* r, const void* a){*((char*)r) *= (*((long*)a));}
static __attribute__((unused)) void g_mul_eq_c_ul(void* r, const void* a){*((char*)r) *= (*((unsigned long*)a));}
static __attribute__((unused)) void g_mul_eq_c_f(void* r, const void* a){*((char*)r) *= (*((float*)a));}
static __attribute__((unused)) void g_mul_eq_c_d(void* r, const void* a){*((char*)r) *= (*((double*)a));}
static __attribute__((unused)) void g_mul_eq_ss_b(void* r, const void* a){*((short*)r) *= (*((bool*)a));}
static __attribute__((unused)) void g_mul_eq_ss_c(void* r, const void* a){*((short*)r) *= (*((char*)a));}
static __attribute__((unused)) void g_mul_eq_ss_ss(void* r, const void* a){*((short*)r) *= (*((short*)a));}
static __attribute__((unused)) void g_mul_eq_ss_si(void* r, const void* a){*((short*)r) *= (*((int*)a));}
static __attribute__((unused)) void g_mul_eq_ss_sl(void* r, const void* a){*((short*)r) *= (*((long*)a));}
static __attribute__((unused)) void g_mul_eq_ss_ul(void* r, const void* a){*((short*)r) *= (*((unsigned long*)a));}
static __attribute__((unused)) void g_mul_eq_ss_f(void* r, const void* a){*((short*)r) *= (*((float*)a));}
static __attribute__((unused)) void g_mul_eq_ss_d(void* r, const void* a){*((short*)r) *= (*((double*)a));}
static __attribute__((unused)) void g_mul_eq_si_b(void* r, const void* a){*((int*)r) *= (*((bool*)a));}
static __attribute__((unused)) void g_mul_eq_si_c(void* r, const void* a){*((int*)r) *= (*((char*)a));}
static __attribute__((unused)) void g_mul_eq_si_ss(void* r, const void* a){*((int*)r) *= (*((short*)a));}
static __attribute__((unused)) void g_mul_eq_si_si(void* r, const void* a){*((int*)r) *= (*((int*)a));}
static __attribute__((unused)) void g_mul_eq_si_sl(void* r, const void* a){*((int*)r) *= (*((long*)a));}
static __attribute__((unused)) void g_mul_eq_si_ul(void* r, const void* a){*((int*)r) *= (*((unsigned long*)a));}
static __attribute__((unused)) void g_mul_eq_si_f(void* r, const void* a){*((int*)r) *= (*((float*)a));}
static __attribute__((unused)) void g_mul_eq_si_d(void* r, const void* a){*((int*)r) *= (*((double*)a));}
static __attribute__((unused)) void g_mul_eq_sl_b(void* r, const void* a){*((long*)r) *= (*((bool*)a));}
static __attribute__((unused)) void g_mul_eq_sl_c(void* r, const void* a){*((long*)r) *= (*((char*)a));}
static __attribute__((unused)) void g_mul_eq_sl_ss(void* r, const void* a){*((long*)r) *= (*((short*)a));}
static __attribute__((unused)) void g_mul_eq_sl_si(void* r, const void* a){*((long*)r) *= (*((int*)a));}
static __attribute__((unused)) void g_mul_eq_sl_sl(void* r, const void* a){*((long*)r) *= (*((long*)a));}
static __attribute__((unused)) void g_mul_eq_sl_ul(void* r, const void* a){*((long*)r) *= (*((unsigned long*)a));}
static __attribute__((unused)) void g_mul_eq_sl_f(void* r, const void* a){*((long*)r) *= (*((float*)a));}
static __attribute__((unused)) void g_mul_eq_sl_d(void* r, const void* a){*((long*)r) *= (*((double*)a));}
static __attribute__((unused)) void g_mul_eq_ul_b(void* r, const void* a){*((unsigned long*)r) *= (*((bool*)a));}
static __attribute__((unused)) void g_mul_eq_ul_c(void* r, const void* a){*((unsigned long*)r) *= (*((char*)a));}
static __attribute__((unused)) void g_mul_eq_ul_ss(void* r, const void* a){*((unsigned long*)r) *= (*((short*)a));}
static __attribute__((unused)) void g_mul_eq_ul_si(void* r, const void* a){*((unsigned long*)r) *= (*((int*)a));}
static __attribute__((unused)) void g_mul_eq_ul_sl(void* r, const void* a){*((unsigned long*)r) *= (*((long*)a));}
static __attribute__((unused)) void g_mul_eq_ul_ul(void* r, const void* a){*((unsigned long*)r) *= (*((unsigned long*)a));}
static __attribute__((unused)) void g_mul_eq_ul_f(void* r, const void* a){*((unsigned long*)r) *= (*((float*)a));}
static __attribute__((unused)) void g_mul_eq_ul_d(void* r, const void* a){*((unsigned long*)r) *= (*((double*)a));}
static __attribute__((unused)) void g_mul_eq_f_b(void* r, const void* a){*((float*)r) *= (*((bool*)a));}
static __attribute__((unused)) void g_mul_eq_f_c(void* r, const void* a){*((float*)r) *= (*((char*)a));}
static __attribute__((unused)) void g_mul_eq_f_ss(void* r, const void* a){*((float*)r) *= (*((short*)a));}
static __attribute__((unused)) void g_mul_eq_f_si(void* r, const void* a){*((float*)r) *= (*((int*)a));}
static __attribute__((unused)) void g_mul_eq_f_sl(void* r, const void* a){*((float*)r) *= (*((long*)a));}
static __attribute__((unused)) void g_mul_eq_f_ul(void* r, const void* a){*((float*)r) *= (*((unsigned long*)a));}
static __attribute__((unused)) void g_mul_eq_f_f(void* r, const void* a){*((float*)r) *= (*((float*)a));}
static __attribute__((unused)) void g_mul_eq_f_d(void* r, const void* a){*((float*)r) *= (*((double*)a));}
static __attribute__((unused)) void g_mul_eq_d_b(void* r, const void* a){*((double*)r) *= (*((bool*)a));}
static __attribute__((unused)) void g_mul_eq_d_c(void* r, const void* a){*((double*)r) *= (*((char*)a));}
static __attribute__((unused)) void g_mul_eq_d_ss(void* r, const void* a){*((double*)r) *= (*((short*)a));}
static __attribute__((unused)) void g_mul_eq_d_si(void* r, const void* a){*((double*)r) *= (*((int*)a));}
static __attribute__((unused)) void g_mul_eq_d_sl(void* r, const void* a){*((double*)r) *= (*((long*)a));}
static __attribute__((unused)) void g_mul_eq_d_ul(void* r, const void* a){*((double*)r) *= (*((unsigned long*)a));}
static __attribute__((unused)) void g_mul_eq_d_f(void* r, const void* a){*((double*)r) *= (*((float*)a));}
static __attribute__((unused)) void g_mul_eq_d_d(void* r, const void* a){*((double*)r) *= (*((double*)a));}
typedef bool (*g_b_function_t)(void);
typedef char (*g_c_function_t)(void);
typedef short (*g_ss_function_t)(void);
typedef int (*g_si_function_t)(void);
typedef long (*g_sl_function_t)(void);
typedef unsigned long (*g_ul_function_t)(void);
typedef float (*g_f_function_t)(void);
typedef double (*g_d_function_t)(void);
static __attribute__((unused)) void g_b_forward(g_b_function_t f, void* r){*((bool*)r) = f();}
static __attribute__((unused)) void g_c_forward(g_c_function_t f, void* r){*((char*)r) = f();}
static __attribute__((unused)) void g_ss_forward(g_ss_function_t f, void* r){*((short*)r) = f();}
static __attribute__((unused)) void g_si_forward(g_si_function_t f, void* r){*((int*)r) = f();}
static __attribute__((unused)) void g_sl_forward(g_sl_function_t f, void* r){*((long*)r) = f();}
static __attribute__((unused)) void g_ul_forward(g_ul_function_t f, void* r){*((unsigned long*)r) = f();}
static __attribute__((unused)) void g_f_forward(g_f_function_t f, void* r){*((float*)r) = f();}
static __attribute__((unused)) void g_d_forward(g_d_function_t f, void* r){*((double*)r) = f();}

#define g_forward_0(x) _Generic((x) \
	, g_b_function_t : g_b_forward \
	, g_c_function_t : g_c_forward \
	, g_ss_function_t : g_ss_forward \
	, g_si_function_t : g_si_forward \
	, g_sl_function_t : g_sl_forward \
	, g_ul_function_t : g_ul_forward \
	, g_f_function_t : g_f_forward \
	, g_d_function_t : g_d_forward \
)
typedef void (*g_function_b_t)(bool);
typedef void (*g_function_c_t)(char);
typedef void (*g_function_ss_t)(short);
typedef void (*g_function_si_t)(int);
typedef void (*g_function_sl_t)(long);
typedef void (*g_function_ul_t)(unsigned long);
typedef void (*g_function_f_t)(float);
typedef void (*g_function_d_t)(double);
typedef bool (*g_b_function_b_t)(bool);
typedef bool (*g_b_function_c_t)(char);
typedef bool (*g_b_function_ss_t)(short);
typedef bool (*g_b_function_si_t)(int);
typedef bool (*g_b_function_sl_t)(long);
typedef bool (*g_b_function_ul_t)(unsigned long);
typedef bool (*g_b_function_f_t)(float);
typedef bool (*g_b_function_d_t)(double);
typedef char (*g_c_function_b_t)(bool);
typedef char (*g_c_function_c_t)(char);
typedef char (*g_c_function_ss_t)(short);
typedef char (*g_c_function_si_t)(int);
typedef char (*g_c_function_sl_t)(long);
typedef char (*g_c_function_ul_t)(unsigned long);
typedef char (*g_c_function_f_t)(float);
typedef char (*g_c_function_d_t)(double);
typedef short (*g_ss_function_b_t)(bool);
typedef short (*g_ss_function_c_t)(char);
typedef short (*g_ss_function_ss_t)(short);
typedef short (*g_ss_function_si_t)(int);
typedef short (*g_ss_function_sl_t)(long);
typedef short (*g_ss_function_ul_t)(unsigned long);
typedef short (*g_ss_function_f_t)(float);
typedef short (*g_ss_function_d_t)(double);
typedef int (*g_si_function_b_t)(bool);
typedef int (*g_si_function_c_t)(char);
typedef int (*g_si_function_ss_t)(short);
typedef int (*g_si_function_si_t)(int);
typedef int (*g_si_function_sl_t)(long);
typedef int (*g_si_function_ul_t)(unsigned long);
typedef int (*g_si_function_f_t)(float);
typedef int (*g_si_function_d_t)(double);
typedef long (*g_sl_function_b_t)(bool);
typedef long (*g_sl_function_c_t)(char);
typedef long (*g_sl_function_ss_t)(short);
typedef long (*g_sl_function_si_t)(int);
typedef long (*g_sl_function_sl_t)(long);
typedef long (*g_sl_function_ul_t)(unsigned long);
typedef long (*g_sl_function_f_t)(float);
typedef long (*g_sl_function_d_t)(double);
typedef unsigned long (*g_ul_function_b_t)(bool);
typedef unsigned long (*g_ul_function_c_t)(char);
typedef unsigned long (*g_ul_function_ss_t)(short);
typedef unsigned long (*g_ul_function_si_t)(int);
typedef unsigned long (*g_ul_function_sl_t)(long);
typedef unsigned long (*g_ul_function_ul_t)(unsigned long);
typedef unsigned long (*g_ul_function_f_t)(float);
typedef unsigned long (*g_ul_function_d_t)(double);
typedef float (*g_f_function_b_t)(bool);
typedef float (*g_f_function_c_t)(char);
typedef float (*g_f_function_ss_t)(short);
typedef float (*g_f_function_si_t)(int);
typedef float (*g_f_function_sl_t)(long);
typedef float (*g_f_function_ul_t)(unsigned long);
typedef float (*g_f_function_f_t)(float);
typedef float (*g_f_function_d_t)(double);
typedef double (*g_d_function_b_t)(bool);
typedef double (*g_d_function_c_t)(char);
typedef double (*g_d_function_ss_t)(short);
typedef double (*g_d_function_si_t)(int);
typedef double (*g_d_function_sl_t)(long);
typedef double (*g_d_function_ul_t)(unsigned long);
typedef double (*g_d_function_f_t)(float);
typedef double (*g_d_function_d_t)(double);
typedef bool (*g_b_function_b_b_t)(bool, bool);
typedef bool (*g_b_function_b_c_t)(bool, char);
typedef bool (*g_b_function_b_ss_t)(bool, short);
typedef bool (*g_b_function_b_si_t)(bool, int);
typedef bool (*g_b_function_b_sl_t)(bool, long);
typedef bool (*g_b_function_b_ul_t)(bool, unsigned long);
typedef bool (*g_b_function_b_f_t)(bool, float);
typedef bool (*g_b_function_b_d_t)(bool, double);
typedef bool (*g_b_function_c_b_t)(char, bool);
typedef bool (*g_b_function_c_c_t)(char, char);
typedef bool (*g_b_function_c_ss_t)(char, short);
typedef bool (*g_b_function_c_si_t)(char, int);
typedef bool (*g_b_function_c_sl_t)(char, long);
typedef bool (*g_b_function_c_ul_t)(char, unsigned long);
typedef bool (*g_b_function_c_f_t)(char, float);
typedef bool (*g_b_function_c_d_t)(char, double);
typedef bool (*g_b_function_ss_b_t)(short, bool);
typedef bool (*g_b_function_ss_c_t)(short, char);
typedef bool (*g_b_function_ss_ss_t)(short, short);
typedef bool (*g_b_function_ss_si_t)(short, int);
typedef bool (*g_b_function_ss_sl_t)(short, long);
typedef bool (*g_b_function_ss_ul_t)(short, unsigned long);
typedef bool (*g_b_function_ss_f_t)(short, float);
typedef bool (*g_b_function_ss_d_t)(short, double);
typedef bool (*g_b_function_si_b_t)(int, bool);
typedef bool (*g_b_function_si_c_t)(int, char);
typedef bool (*g_b_function_si_ss_t)(int, short);
typedef bool (*g_b_function_si_si_t)(int, int);
typedef bool (*g_b_function_si_sl_t)(int, long);
typedef bool (*g_b_function_si_ul_t)(int, unsigned long);
typedef bool (*g_b_function_si_f_t)(int, float);
typedef bool (*g_b_function_si_d_t)(int, double);
typedef bool (*g_b_function_sl_b_t)(long, bool);
typedef bool (*g_b_function_sl_c_t)(long, char);
typedef bool (*g_b_function_sl_ss_t)(long, short);
typedef bool (*g_b_function_sl_si_t)(long, int);
typedef bool (*g_b_function_sl_sl_t)(long, long);
typedef bool (*g_b_function_sl_ul_t)(long, unsigned long);
typedef bool (*g_b_function_sl_f_t)(long, float);
typedef bool (*g_b_function_sl_d_t)(long, double);
typedef bool (*g_b_function_ul_b_t)(unsigned long, bool);
typedef bool (*g_b_function_ul_c_t)(unsigned long, char);
typedef bool (*g_b_function_ul_ss_t)(unsigned long, short);
typedef bool (*g_b_function_ul_si_t)(unsigned long, int);
typedef bool (*g_b_function_ul_sl_t)(unsigned long, long);
typedef bool (*g_b_function_ul_ul_t)(unsigned long, unsigned long);
typedef bool (*g_b_function_ul_f_t)(unsigned long, float);
typedef bool (*g_b_function_ul_d_t)(unsigned long, double);
typedef bool (*g_b_function_f_b_t)(float, bool);
typedef bool (*g_b_function_f_c_t)(float, char);
typedef bool (*g_b_function_f_ss_t)(float, short);
typedef bool (*g_b_function_f_si_t)(float, int);
typedef bool (*g_b_function_f_sl_t)(float, long);
typedef bool (*g_b_function_f_ul_t)(float, unsigned long);
typedef bool (*g_b_function_f_f_t)(float, float);
typedef bool (*g_b_function_f_d_t)(float, double);
typedef bool (*g_b_function_d_b_t)(double, bool);
typedef bool (*g_b_function_d_c_t)(double, char);
typedef bool (*g_b_function_d_ss_t)(double, short);
typedef bool (*g_b_function_d_si_t)(double, int);
typedef bool (*g_b_function_d_sl_t)(double, long);
typedef bool (*g_b_function_d_ul_t)(double, unsigned long);
typedef bool (*g_b_function_d_f_t)(double, float);
typedef bool (*g_b_function_d_d_t)(double, double);
typedef char (*g_c_function_b_b_t)(bool, bool);
typedef char (*g_c_function_b_c_t)(bool, char);
typedef char (*g_c_function_b_ss_t)(bool, short);
typedef char (*g_c_function_b_si_t)(bool, int);
typedef char (*g_c_function_b_sl_t)(bool, long);
typedef char (*g_c_function_b_ul_t)(bool, unsigned long);
typedef char (*g_c_function_b_f_t)(bool, float);
typedef char (*g_c_function_b_d_t)(bool, double);
typedef char (*g_c_function_c_b_t)(char, bool);
typedef char (*g_c_function_c_c_t)(char, char);
typedef char (*g_c_function_c_ss_t)(char, short);
typedef char (*g_c_function_c_si_t)(char, int);
typedef char (*g_c_function_c_sl_t)(char, long);
typedef char (*g_c_function_c_ul_t)(char, unsigned long);
typedef char (*g_c_function_c_f_t)(char, float);
typedef char (*g_c_function_c_d_t)(char, double);
typedef char (*g_c_function_ss_b_t)(short, bool);
typedef char (*g_c_function_ss_c_t)(short, char);
typedef char (*g_c_function_ss_ss_t)(short, short);
typedef char (*g_c_function_ss_si_t)(short, int);
typedef char (*g_c_function_ss_sl_t)(short, long);
typedef char (*g_c_function_ss_ul_t)(short, unsigned long);
typedef char (*g_c_function_ss_f_t)(short, float);
typedef char (*g_c_function_ss_d_t)(short, double);
typedef char (*g_c_function_si_b_t)(int, bool);
typedef char (*g_c_function_si_c_t)(int, char);
typedef char (*g_c_function_si_ss_t)(int, short);
typedef char (*g_c_function_si_si_t)(int, int);
typedef char (*g_c_function_si_sl_t)(int, long);
typedef char (*g_c_function_si_ul_t)(int, unsigned long);
typedef char (*g_c_function_si_f_t)(int, float);
typedef char (*g_c_function_si_d_t)(int, double);
typedef char (*g_c_function_sl_b_t)(long, bool);
typedef char (*g_c_function_sl_c_t)(long, char);
typedef char (*g_c_function_sl_ss_t)(long, short);
typedef char (*g_c_function_sl_si_t)(long, int);
typedef char (*g_c_function_sl_sl_t)(long, long);
typedef char (*g_c_function_sl_ul_t)(long, unsigned long);
typedef char (*g_c_function_sl_f_t)(long, float);
typedef char (*g_c_function_sl_d_t)(long, double);
typedef char (*g_c_function_ul_b_t)(unsigned long, bool);
typedef char (*g_c_function_ul_c_t)(unsigned long, char);
typedef char (*g_c_function_ul_ss_t)(unsigned long, short);
typedef char (*g_c_function_ul_si_t)(unsigned long, int);
typedef char (*g_c_function_ul_sl_t)(unsigned long, long);
typedef char (*g_c_function_ul_ul_t)(unsigned long, unsigned long);
typedef char (*g_c_function_ul_f_t)(unsigned long, float);
typedef char (*g_c_function_ul_d_t)(unsigned long, double);
typedef char (*g_c_function_f_b_t)(float, bool);
typedef char (*g_c_function_f_c_t)(float, char);
typedef char (*g_c_function_f_ss_t)(float, short);
typedef char (*g_c_function_f_si_t)(float, int);
typedef char (*g_c_function_f_sl_t)(float, long);
typedef char (*g_c_function_f_ul_t)(float, unsigned long);
typedef char (*g_c_function_f_f_t)(float, float);
typedef char (*g_c_function_f_d_t)(float, double);
typedef char (*g_c_function_d_b_t)(double, bool);
typedef char (*g_c_function_d_c_t)(double, char);
typedef char (*g_c_function_d_ss_t)(double, short);
typedef char (*g_c_function_d_si_t)(double, int);
typedef char (*g_c_function_d_sl_t)(double, long);
typedef char (*g_c_function_d_ul_t)(double, unsigned long);
typedef char (*g_c_function_d_f_t)(double, float);
typedef char (*g_c_function_d_d_t)(double, double);
typedef short (*g_ss_function_b_b_t)(bool, bool);
typedef short (*g_ss_function_b_c_t)(bool, char);
typedef short (*g_ss_function_b_ss_t)(bool, short);
typedef short (*g_ss_function_b_si_t)(bool, int);
typedef short (*g_ss_function_b_sl_t)(bool, long);
typedef short (*g_ss_function_b_ul_t)(bool, unsigned long);
typedef short (*g_ss_function_b_f_t)(bool, float);
typedef short (*g_ss_function_b_d_t)(bool, double);
typedef short (*g_ss_function_c_b_t)(char, bool);
typedef short (*g_ss_function_c_c_t)(char, char);
typedef short (*g_ss_function_c_ss_t)(char, short);
typedef short (*g_ss_function_c_si_t)(char, int);
typedef short (*g_ss_function_c_sl_t)(char, long);
typedef short (*g_ss_function_c_ul_t)(char, unsigned long);
typedef short (*g_ss_function_c_f_t)(char, float);
typedef short (*g_ss_function_c_d_t)(char, double);
typedef short (*g_ss_function_ss_b_t)(short, bool);
typedef short (*g_ss_function_ss_c_t)(short, char);
typedef short (*g_ss_function_ss_ss_t)(short, short);
typedef short (*g_ss_function_ss_si_t)(short, int);
typedef short (*g_ss_function_ss_sl_t)(short, long);
typedef short (*g_ss_function_ss_ul_t)(short, unsigned long);
typedef short (*g_ss_function_ss_f_t)(short, float);
typedef short (*g_ss_function_ss_d_t)(short, double);
typedef short (*g_ss_function_si_b_t)(int, bool);
typedef short (*g_ss_function_si_c_t)(int, char);
typedef short (*g_ss_function_si_ss_t)(int, short);
typedef short (*g_ss_function_si_si_t)(int, int);
typedef short (*g_ss_function_si_sl_t)(int, long);
typedef short (*g_ss_function_si_ul_t)(int, unsigned long);
typedef short (*g_ss_function_si_f_t)(int, float);
typedef short (*g_ss_function_si_d_t)(int, double);
typedef short (*g_ss_function_sl_b_t)(long, bool);
typedef short (*g_ss_function_sl_c_t)(long, char);
typedef short (*g_ss_function_sl_ss_t)(long, short);
typedef short (*g_ss_function_sl_si_t)(long, int);
typedef short (*g_ss_function_sl_sl_t)(long, long);
typedef short (*g_ss_function_sl_ul_t)(long, unsigned long);
typedef short (*g_ss_function_sl_f_t)(long, float);
typedef short (*g_ss_function_sl_d_t)(long, double);
typedef short (*g_ss_function_ul_b_t)(unsigned long, bool);
typedef short (*g_ss_function_ul_c_t)(unsigned long, char);
typedef short (*g_ss_function_ul_ss_t)(unsigned long, short);
typedef short (*g_ss_function_ul_si_t)(unsigned long, int);
typedef short (*g_ss_function_ul_sl_t)(unsigned long, long);
typedef short (*g_ss_function_ul_ul_t)(unsigned long, unsigned long);
typedef short (*g_ss_function_ul_f_t)(unsigned long, float);
typedef short (*g_ss_function_ul_d_t)(unsigned long, double);
typedef short (*g_ss_function_f_b_t)(float, bool);
typedef short (*g_ss_function_f_c_t)(float, char);
typedef short (*g_ss_function_f_ss_t)(float, short);
typedef short (*g_ss_function_f_si_t)(float, int);
typedef short (*g_ss_function_f_sl_t)(float, long);
typedef short (*g_ss_function_f_ul_t)(float, unsigned long);
typedef short (*g_ss_function_f_f_t)(float, float);
typedef short (*g_ss_function_f_d_t)(float, double);
typedef short (*g_ss_function_d_b_t)(double, bool);
typedef short (*g_ss_function_d_c_t)(double, char);
typedef short (*g_ss_function_d_ss_t)(double, short);
typedef short (*g_ss_function_d_si_t)(double, int);
typedef short (*g_ss_function_d_sl_t)(double, long);
typedef short (*g_ss_function_d_ul_t)(double, unsigned long);
typedef short (*g_ss_function_d_f_t)(double, float);
typedef short (*g_ss_function_d_d_t)(double, double);
typedef int (*g_si_function_b_b_t)(bool, bool);
typedef int (*g_si_function_b_c_t)(bool, char);
typedef int (*g_si_function_b_ss_t)(bool, short);
typedef int (*g_si_function_b_si_t)(bool, int);
typedef int (*g_si_function_b_sl_t)(bool, long);
typedef int (*g_si_function_b_ul_t)(bool, unsigned long);
typedef int (*g_si_function_b_f_t)(bool, float);
typedef int (*g_si_function_b_d_t)(bool, double);
typedef int (*g_si_function_c_b_t)(char, bool);
typedef int (*g_si_function_c_c_t)(char, char);
typedef int (*g_si_function_c_ss_t)(char, short);
typedef int (*g_si_function_c_si_t)(char, int);
typedef int (*g_si_function_c_sl_t)(char, long);
typedef int (*g_si_function_c_ul_t)(char, unsigned long);
typedef int (*g_si_function_c_f_t)(char, float);
typedef int (*g_si_function_c_d_t)(char, double);
typedef int (*g_si_function_ss_b_t)(short, bool);
typedef int (*g_si_function_ss_c_t)(short, char);
typedef int (*g_si_function_ss_ss_t)(short, short);
typedef int (*g_si_function_ss_si_t)(short, int);
typedef int (*g_si_function_ss_sl_t)(short, long);
typedef int (*g_si_function_ss_ul_t)(short, unsigned long);
typedef int (*g_si_function_ss_f_t)(short, float);
typedef int (*g_si_function_ss_d_t)(short, double);
typedef int (*g_si_function_si_b_t)(int, bool);
typedef int (*g_si_function_si_c_t)(int, char);
typedef int (*g_si_function_si_ss_t)(int, short);
typedef int (*g_si_function_si_si_t)(int, int);
typedef int (*g_si_function_si_sl_t)(int, long);
typedef int (*g_si_function_si_ul_t)(int, unsigned long);
typedef int (*g_si_function_si_f_t)(int, float);
typedef int (*g_si_function_si_d_t)(int, double);
typedef int (*g_si_function_sl_b_t)(long, bool);
typedef int (*g_si_function_sl_c_t)(long, char);
typedef int (*g_si_function_sl_ss_t)(long, short);
typedef int (*g_si_function_sl_si_t)(long, int);
typedef int (*g_si_function_sl_sl_t)(long, long);
typedef int (*g_si_function_sl_ul_t)(long, unsigned long);
typedef int (*g_si_function_sl_f_t)(long, float);
typedef int (*g_si_function_sl_d_t)(long, double);
typedef int (*g_si_function_ul_b_t)(unsigned long, bool);
typedef int (*g_si_function_ul_c_t)(unsigned long, char);
typedef int (*g_si_function_ul_ss_t)(unsigned long, short);
typedef int (*g_si_function_ul_si_t)(unsigned long, int);
typedef int (*g_si_function_ul_sl_t)(unsigned long, long);
typedef int (*g_si_function_ul_ul_t)(unsigned long, unsigned long);
typedef int (*g_si_function_ul_f_t)(unsigned long, float);
typedef int (*g_si_function_ul_d_t)(unsigned long, double);
typedef int (*g_si_function_f_b_t)(float, bool);
typedef int (*g_si_function_f_c_t)(float, char);
typedef int (*g_si_function_f_ss_t)(float, short);
typedef int (*g_si_function_f_si_t)(float, int);
typedef int (*g_si_function_f_sl_t)(float, long);
typedef int (*g_si_function_f_ul_t)(float, unsigned long);
typedef int (*g_si_function_f_f_t)(float, float);
typedef int (*g_si_function_f_d_t)(float, double);
typedef int (*g_si_function_d_b_t)(double, bool);
typedef int (*g_si_function_d_c_t)(double, char);
typedef int (*g_si_function_d_ss_t)(double, short);
typedef int (*g_si_function_d_si_t)(double, int);
typedef int (*g_si_function_d_sl_t)(double, long);
typedef int (*g_si_function_d_ul_t)(double, unsigned long);
typedef int (*g_si_function_d_f_t)(double, float);
typedef int (*g_si_function_d_d_t)(double, double);
typedef long (*g_sl_function_b_b_t)(bool, bool);
typedef long (*g_sl_function_b_c_t)(bool, char);
typedef long (*g_sl_function_b_ss_t)(bool, short);
typedef long (*g_sl_function_b_si_t)(bool, int);
typedef long (*g_sl_function_b_sl_t)(bool, long);
typedef long (*g_sl_function_b_ul_t)(bool, unsigned long);
typedef long (*g_sl_function_b_f_t)(bool, float);
typedef long (*g_sl_function_b_d_t)(bool, double);
typedef long (*g_sl_function_c_b_t)(char, bool);
typedef long (*g_sl_function_c_c_t)(char, char);
typedef long (*g_sl_function_c_ss_t)(char, short);
typedef long (*g_sl_function_c_si_t)(char, int);
typedef long (*g_sl_function_c_sl_t)(char, long);
typedef long (*g_sl_function_c_ul_t)(char, unsigned long);
typedef long (*g_sl_function_c_f_t)(char, float);
typedef long (*g_sl_function_c_d_t)(char, double);
typedef long (*g_sl_function_ss_b_t)(short, bool);
typedef long (*g_sl_function_ss_c_t)(short, char);
typedef long (*g_sl_function_ss_ss_t)(short, short);
typedef long (*g_sl_function_ss_si_t)(short, int);
typedef long (*g_sl_function_ss_sl_t)(short, long);
typedef long (*g_sl_function_ss_ul_t)(short, unsigned long);
typedef long (*g_sl_function_ss_f_t)(short, float);
typedef long (*g_sl_function_ss_d_t)(short, double);
typedef long (*g_sl_function_si_b_t)(int, bool);
typedef long (*g_sl_function_si_c_t)(int, char);
typedef long (*g_sl_function_si_ss_t)(int, short);
typedef long (*g_sl_function_si_si_t)(int, int);
typedef long (*g_sl_function_si_sl_t)(int, long);
typedef long (*g_sl_function_si_ul_t)(int, unsigned long);
typedef long (*g_sl_function_si_f_t)(int, float);
typedef long (*g_sl_function_si_d_t)(int, double);
typedef long (*g_sl_function_sl_b_t)(long, bool);
typedef long (*g_sl_function_sl_c_t)(long, char);
typedef long (*g_sl_function_sl_ss_t)(long, short);
typedef long (*g_sl_function_sl_si_t)(long, int);
typedef long (*g_sl_function_sl_sl_t)(long, long);
typedef long (*g_sl_function_sl_ul_t)(long, unsigned long);
typedef long (*g_sl_function_sl_f_t)(long, float);
typedef long (*g_sl_function_sl_d_t)(long, double);
typedef long (*g_sl_function_ul_b_t)(unsigned long, bool);
typedef long (*g_sl_function_ul_c_t)(unsigned long, char);
typedef long (*g_sl_function_ul_ss_t)(unsigned long, short);
typedef long (*g_sl_function_ul_si_t)(unsigned long, int);
typedef long (*g_sl_function_ul_sl_t)(unsigned long, long);
typedef long (*g_sl_function_ul_ul_t)(unsigned long, unsigned long);
typedef long (*g_sl_function_ul_f_t)(unsigned long, float);
typedef long (*g_sl_function_ul_d_t)(unsigned long, double);
typedef long (*g_sl_function_f_b_t)(float, bool);
typedef long (*g_sl_function_f_c_t)(float, char);
typedef long (*g_sl_function_f_ss_t)(float, short);
typedef long (*g_sl_function_f_si_t)(float, int);
typedef long (*g_sl_function_f_sl_t)(float, long);
typedef long (*g_sl_function_f_ul_t)(float, unsigned long);
typedef long (*g_sl_function_f_f_t)(float, float);
typedef long (*g_sl_function_f_d_t)(float, double);
typedef long (*g_sl_function_d_b_t)(double, bool);
typedef long (*g_sl_function_d_c_t)(double, char);
typedef long (*g_sl_function_d_ss_t)(double, short);
typedef long (*g_sl_function_d_si_t)(double, int);
typedef long (*g_sl_function_d_sl_t)(double, long);
typedef long (*g_sl_function_d_ul_t)(double, unsigned long);
typedef long (*g_sl_function_d_f_t)(double, float);
typedef long (*g_sl_function_d_d_t)(double, double);
typedef unsigned long (*g_ul_function_b_b_t)(bool, bool);
typedef unsigned long (*g_ul_function_b_c_t)(bool, char);
typedef unsigned long (*g_ul_function_b_ss_t)(bool, short);
typedef unsigned long (*g_ul_function_b_si_t)(bool, int);
typedef unsigned long (*g_ul_function_b_sl_t)(bool, long);
typedef unsigned long (*g_ul_function_b_ul_t)(bool, unsigned long);
typedef unsigned long (*g_ul_function_b_f_t)(bool, float);
typedef unsigned long (*g_ul_function_b_d_t)(bool, double);
typedef unsigned long (*g_ul_function_c_b_t)(char, bool);
typedef unsigned long (*g_ul_function_c_c_t)(char, char);
typedef unsigned long (*g_ul_function_c_ss_t)(char, short);
typedef unsigned long (*g_ul_function_c_si_t)(char, int);
typedef unsigned long (*g_ul_function_c_sl_t)(char, long);
typedef unsigned long (*g_ul_function_c_ul_t)(char, unsigned long);
typedef unsigned long (*g_ul_function_c_f_t)(char, float);
typedef unsigned long (*g_ul_function_c_d_t)(char, double);
typedef unsigned long (*g_ul_function_ss_b_t)(short, bool);
typedef unsigned long (*g_ul_function_ss_c_t)(short, char);
typedef unsigned long (*g_ul_function_ss_ss_t)(short, short);
typedef unsigned long (*g_ul_function_ss_si_t)(short, int);
typedef unsigned long (*g_ul_function_ss_sl_t)(short, long);
typedef unsigned long (*g_ul_function_ss_ul_t)(short, unsigned long);
typedef unsigned long (*g_ul_function_ss_f_t)(short, float);
typedef unsigned long (*g_ul_function_ss_d_t)(short, double);
typedef unsigned long (*g_ul_function_si_b_t)(int, bool);
typedef unsigned long (*g_ul_function_si_c_t)(int, char);
typedef unsigned long (*g_ul_function_si_ss_t)(int, short);
typedef unsigned long (*g_ul_function_si_si_t)(int, int);
typedef unsigned long (*g_ul_function_si_sl_t)(int, long);
typedef unsigned long (*g_ul_function_si_ul_t)(int, unsigned long);
typedef unsigned long (*g_ul_function_si_f_t)(int, float);
typedef unsigned long (*g_ul_function_si_d_t)(int, double);
typedef unsigned long (*g_ul_function_sl_b_t)(long, bool);
typedef unsigned long (*g_ul_function_sl_c_t)(long, char);
typedef unsigned long (*g_ul_function_sl_ss_t)(long, short);
typedef unsigned long (*g_ul_function_sl_si_t)(long, int);
typedef unsigned long (*g_ul_function_sl_sl_t)(long, long);
typedef unsigned long (*g_ul_function_sl_ul_t)(long, unsigned long);
typedef unsigned long (*g_ul_function_sl_f_t)(long, float);
typedef unsigned long (*g_ul_function_sl_d_t)(long, double);
typedef unsigned long (*g_ul_function_ul_b_t)(unsigned long, bool);
typedef unsigned long (*g_ul_function_ul_c_t)(unsigned long, char);
typedef unsigned long (*g_ul_function_ul_ss_t)(unsigned long, short);
typedef unsigned long (*g_ul_function_ul_si_t)(unsigned long, int);
typedef unsigned long (*g_ul_function_ul_sl_t)(unsigned long, long);
typedef unsigned long (*g_ul_function_ul_ul_t)(unsigned long, unsigned long);
typedef unsigned long (*g_ul_function_ul_f_t)(unsigned long, float);
typedef unsigned long (*g_ul_function_ul_d_t)(unsigned long, double);
typedef unsigned long (*g_ul_function_f_b_t)(float, bool);
typedef unsigned long (*g_ul_function_f_c_t)(float, char);
typedef unsigned long (*g_ul_function_f_ss_t)(float, short);
typedef unsigned long (*g_ul_function_f_si_t)(float, int);
typedef unsigned long (*g_ul_function_f_sl_t)(float, long);
typedef unsigned long (*g_ul_function_f_ul_t)(float, unsigned long);
typedef unsigned long (*g_ul_function_f_f_t)(float, float);
typedef unsigned long (*g_ul_function_f_d_t)(float, double);
typedef unsigned long (*g_ul_function_d_b_t)(double, bool);
typedef unsigned long (*g_ul_function_d_c_t)(double, char);
typedef unsigned long (*g_ul_function_d_ss_t)(double, short);
typedef unsigned long (*g_ul_function_d_si_t)(double, int);
typedef unsigned long (*g_ul_function_d_sl_t)(double, long);
typedef unsigned long (*g_ul_function_d_ul_t)(double, unsigned long);
typedef unsigned long (*g_ul_function_d_f_t)(double, float);
typedef unsigned long (*g_ul_function_d_d_t)(double, double);
typedef float (*g_f_function_b_b_t)(bool, bool);
typedef float (*g_f_function_b_c_t)(bool, char);
typedef float (*g_f_function_b_ss_t)(bool, short);
typedef float (*g_f_function_b_si_t)(bool, int);
typedef float (*g_f_function_b_sl_t)(bool, long);
typedef float (*g_f_function_b_ul_t)(bool, unsigned long);
typedef float (*g_f_function_b_f_t)(bool, float);
typedef float (*g_f_function_b_d_t)(bool, double);
typedef float (*g_f_function_c_b_t)(char, bool);
typedef float (*g_f_function_c_c_t)(char, char);
typedef float (*g_f_function_c_ss_t)(char, short);
typedef float (*g_f_function_c_si_t)(char, int);
typedef float (*g_f_function_c_sl_t)(char, long);
typedef float (*g_f_function_c_ul_t)(char, unsigned long);
typedef float (*g_f_function_c_f_t)(char, float);
typedef float (*g_f_function_c_d_t)(char, double);
typedef float (*g_f_function_ss_b_t)(short, bool);
typedef float (*g_f_function_ss_c_t)(short, char);
typedef float (*g_f_function_ss_ss_t)(short, short);
typedef float (*g_f_function_ss_si_t)(short, int);
typedef float (*g_f_function_ss_sl_t)(short, long);
typedef float (*g_f_function_ss_ul_t)(short, unsigned long);
typedef float (*g_f_function_ss_f_t)(short, float);
typedef float (*g_f_function_ss_d_t)(short, double);
typedef float (*g_f_function_si_b_t)(int, bool);
typedef float (*g_f_function_si_c_t)(int, char);
typedef float (*g_f_function_si_ss_t)(int, short);
typedef float (*g_f_function_si_si_t)(int, int);
typedef float (*g_f_function_si_sl_t)(int, long);
typedef float (*g_f_function_si_ul_t)(int, unsigned long);
typedef float (*g_f_function_si_f_t)(int, float);
typedef float (*g_f_function_si_d_t)(int, double);
typedef float (*g_f_function_sl_b_t)(long, bool);
typedef float (*g_f_function_sl_c_t)(long, char);
typedef float (*g_f_function_sl_ss_t)(long, short);
typedef float (*g_f_function_sl_si_t)(long, int);
typedef float (*g_f_function_sl_sl_t)(long, long);
typedef float (*g_f_function_sl_ul_t)(long, unsigned long);
typedef float (*g_f_function_sl_f_t)(long, float);
typedef float (*g_f_function_sl_d_t)(long, double);
typedef float (*g_f_function_ul_b_t)(unsigned long, bool);
typedef float (*g_f_function_ul_c_t)(unsigned long, char);
typedef float (*g_f_function_ul_ss_t)(unsigned long, short);
typedef float (*g_f_function_ul_si_t)(unsigned long, int);
typedef float (*g_f_function_ul_sl_t)(unsigned long, long);
typedef float (*g_f_function_ul_ul_t)(unsigned long, unsigned long);
typedef float (*g_f_function_ul_f_t)(unsigned long, float);
typedef float (*g_f_function_ul_d_t)(unsigned long, double);
typedef float (*g_f_function_f_b_t)(float, bool);
typedef float (*g_f_function_f_c_t)(float, char);
typedef float (*g_f_function_f_ss_t)(float, short);
typedef float (*g_f_function_f_si_t)(float, int);
typedef float (*g_f_function_f_sl_t)(float, long);
typedef float (*g_f_function_f_ul_t)(float, unsigned long);
typedef float (*g_f_function_f_f_t)(float, float);
typedef float (*g_f_function_f_d_t)(float, double);
typedef float (*g_f_function_d_b_t)(double, bool);
typedef float (*g_f_function_d_c_t)(double, char);
typedef float (*g_f_function_d_ss_t)(double, short);
typedef float (*g_f_function_d_si_t)(double, int);
typedef float (*g_f_function_d_sl_t)(double, long);
typedef float (*g_f_function_d_ul_t)(double, unsigned long);
typedef float (*g_f_function_d_f_t)(double, float);
typedef float (*g_f_function_d_d_t)(double, double);
typedef double (*g_d_function_b_b_t)(bool, bool);
typedef double (*g_d_function_b_c_t)(bool, char);
typedef double (*g_d_function_b_ss_t)(bool, short);
typedef double (*g_d_function_b_si_t)(bool, int);
typedef double (*g_d_function_b_sl_t)(bool, long);
typedef double (*g_d_function_b_ul_t)(bool, unsigned long);
typedef double (*g_d_function_b_f_t)(bool, float);
typedef double (*g_d_function_b_d_t)(bool, double);
typedef double (*g_d_function_c_b_t)(char, bool);
typedef double (*g_d_function_c_c_t)(char, char);
typedef double (*g_d_function_c_ss_t)(char, short);
typedef double (*g_d_function_c_si_t)(char, int);
typedef double (*g_d_function_c_sl_t)(char, long);
typedef double (*g_d_function_c_ul_t)(char, unsigned long);
typedef double (*g_d_function_c_f_t)(char, float);
typedef double (*g_d_function_c_d_t)(char, double);
typedef double (*g_d_function_ss_b_t)(short, bool);
typedef double (*g_d_function_ss_c_t)(short, char);
typedef double (*g_d_function_ss_ss_t)(short, short);
typedef double (*g_d_function_ss_si_t)(short, int);
typedef double (*g_d_function_ss_sl_t)(short, long);
typedef double (*g_d_function_ss_ul_t)(short, unsigned long);
typedef double (*g_d_function_ss_f_t)(short, float);
typedef double (*g_d_function_ss_d_t)(short, double);
typedef double (*g_d_function_si_b_t)(int, bool);
typedef double (*g_d_function_si_c_t)(int, char);
typedef double (*g_d_function_si_ss_t)(int, short);
typedef double (*g_d_function_si_si_t)(int, int);
typedef double (*g_d_function_si_sl_t)(int, long);
typedef double (*g_d_function_si_ul_t)(int, unsigned long);
typedef double (*g_d_function_si_f_t)(int, float);
typedef double (*g_d_function_si_d_t)(int, double);
typedef double (*g_d_function_sl_b_t)(long, bool);
typedef double (*g_d_function_sl_c_t)(long, char);
typedef double (*g_d_function_sl_ss_t)(long, short);
typedef double (*g_d_function_sl_si_t)(long, int);
typedef double (*g_d_function_sl_sl_t)(long, long);
typedef double (*g_d_function_sl_ul_t)(long, unsigned long);
typedef double (*g_d_function_sl_f_t)(long, float);
typedef double (*g_d_function_sl_d_t)(long, double);
typedef double (*g_d_function_ul_b_t)(unsigned long, bool);
typedef double (*g_d_function_ul_c_t)(unsigned long, char);
typedef double (*g_d_function_ul_ss_t)(unsigned long, short);
typedef double (*g_d_function_ul_si_t)(unsigned long, int);
typedef double (*g_d_function_ul_sl_t)(unsigned long, long);
typedef double (*g_d_function_ul_ul_t)(unsigned long, unsigned long);
typedef double (*g_d_function_ul_f_t)(unsigned long, float);
typedef double (*g_d_function_ul_d_t)(unsigned long, double);
typedef double (*g_d_function_f_b_t)(float, bool);
typedef double (*g_d_function_f_c_t)(float, char);
typedef double (*g_d_function_f_ss_t)(float, short);
typedef double (*g_d_function_f_si_t)(float, int);
typedef double (*g_d_function_f_sl_t)(float, long);
typedef double (*g_d_function_f_ul_t)(float, unsigned long);
typedef double (*g_d_function_f_f_t)(float, float);
typedef double (*g_d_function_f_d_t)(float, double);
typedef double (*g_d_function_d_b_t)(double, bool);
typedef double (*g_d_function_d_c_t)(double, char);
typedef double (*g_d_function_d_ss_t)(double, short);
typedef double (*g_d_function_d_si_t)(double, int);
typedef double (*g_d_function_d_sl_t)(double, long);
typedef double (*g_d_function_d_ul_t)(double, unsigned long);
typedef double (*g_d_function_d_f_t)(double, float);
typedef double (*g_d_function_d_d_t)(double, double);
static __attribute__((unused)) void g_forward_b(g_function_b_t f, const void* a){f(*((bool*)a));}
static __attribute__((unused)) void g_forward_c(g_function_c_t f, const void* a){f(*((char*)a));}
static __attribute__((unused)) void g_forward_ss(g_function_ss_t f, const void* a){f(*((short*)a));}
static __attribute__((unused)) void g_forward_si(g_function_si_t f, const void* a){f(*((int*)a));}
static __attribute__((unused)) void g_forward_sl(g_function_sl_t f, const void* a){f(*((long*)a));}
static __attribute__((unused)) void g_forward_ul(g_function_ul_t f, const void* a){f(*((unsigned long*)a));}
static __attribute__((unused)) void g_forward_f(g_function_f_t f, const void* a){f(*((float*)a));}
static __attribute__((unused)) void g_forward_d(g_function_d_t f, const void* a){f(*((double*)a));}
static __attribute__((unused)) void g_0b_forward_b(g_b_function_b_t f, const void* a){f(*((bool*)a));}
static __attribute__((unused)) void g_0b_forward_c(g_b_function_c_t f, const void* a){f(*((char*)a));}
static __attribute__((unused)) void g_0b_forward_ss(g_b_function_ss_t f, const void* a){f(*((short*)a));}
static __attribute__((unused)) void g_0b_forward_si(g_b_function_si_t f, const void* a){f(*((int*)a));}
static __attribute__((unused)) void g_0b_forward_sl(g_b_function_sl_t f, const void* a){f(*((long*)a));}
static __attribute__((unused)) void g_0b_forward_ul(g_b_function_ul_t f, const void* a){f(*((unsigned long*)a));}
static __attribute__((unused)) void g_0b_forward_f(g_b_function_f_t f, const void* a){f(*((float*)a));}
static __attribute__((unused)) void g_0b_forward_d(g_b_function_d_t f, const void* a){f(*((double*)a));}
static __attribute__((unused)) void g_0c_forward_b(g_c_function_b_t f, const void* a){f(*((bool*)a));}
static __attribute__((unused)) void g_0c_forward_c(g_c_function_c_t f, const void* a){f(*((char*)a));}
static __attribute__((unused)) void g_0c_forward_ss(g_c_function_ss_t f, const void* a){f(*((short*)a));}
static __attribute__((unused)) void g_0c_forward_si(g_c_function_si_t f, const void* a){f(*((int*)a));}
static __attribute__((unused)) void g_0c_forward_sl(g_c_function_sl_t f, const void* a){f(*((long*)a));}
static __attribute__((unused)) void g_0c_forward_ul(g_c_function_ul_t f, const void* a){f(*((unsigned long*)a));}
static __attribute__((unused)) void g_0c_forward_f(g_c_function_f_t f, const void* a){f(*((float*)a));}
static __attribute__((unused)) void g_0c_forward_d(g_c_function_d_t f, const void* a){f(*((double*)a));}
static __attribute__((unused)) void g_0ss_forward_b(g_ss_function_b_t f, const void* a){f(*((bool*)a));}
static __attribute__((unused)) void g_0ss_forward_c(g_ss_function_c_t f, const void* a){f(*((char*)a));}
static __attribute__((unused)) void g_0ss_forward_ss(g_ss_function_ss_t f, const void* a){f(*((short*)a));}
static __attribute__((unused)) void g_0ss_forward_si(g_ss_function_si_t f, const void* a){f(*((int*)a));}
static __attribute__((unused)) void g_0ss_forward_sl(g_ss_function_sl_t f, const void* a){f(*((long*)a));}
static __attribute__((unused)) void g_0ss_forward_ul(g_ss_function_ul_t f, const void* a){f(*((unsigned long*)a));}
static __attribute__((unused)) void g_0ss_forward_f(g_ss_function_f_t f, const void* a){f(*((float*)a));}
static __attribute__((unused)) void g_0ss_forward_d(g_ss_function_d_t f, const void* a){f(*((double*)a));}
static __attribute__((unused)) void g_0si_forward_b(g_si_function_b_t f, const void* a){f(*((bool*)a));}
static __attribute__((unused)) void g_0si_forward_c(g_si_function_c_t f, const void* a){f(*((char*)a));}
static __attribute__((unused)) void g_0si_forward_ss(g_si_function_ss_t f, const void* a){f(*((short*)a));}
static __attribute__((unused)) void g_0si_forward_si(g_si_function_si_t f, const void* a){f(*((int*)a));}
static __attribute__((unused)) void g_0si_forward_sl(g_si_function_sl_t f, const void* a){f(*((long*)a));}
static __attribute__((unused)) void g_0si_forward_ul(g_si_function_ul_t f, const void* a){f(*((unsigned long*)a));}
static __attribute__((unused)) void g_0si_forward_f(g_si_function_f_t f, const void* a){f(*((float*)a));}
static __attribute__((unused)) void g_0si_forward_d(g_si_function_d_t f, const void* a){f(*((double*)a));}
static __attribute__((unused)) void g_0sl_forward_b(g_sl_function_b_t f, const void* a){f(*((bool*)a));}
static __attribute__((unused)) void g_0sl_forward_c(g_sl_function_c_t f, const void* a){f(*((char*)a));}
static __attribute__((unused)) void g_0sl_forward_ss(g_sl_function_ss_t f, const void* a){f(*((short*)a));}
static __attribute__((unused)) void g_0sl_forward_si(g_sl_function_si_t f, const void* a){f(*((int*)a));}
static __attribute__((unused)) void g_0sl_forward_sl(g_sl_function_sl_t f, const void* a){f(*((long*)a));}
static __attribute__((unused)) void g_0sl_forward_ul(g_sl_function_ul_t f, const void* a){f(*((unsigned long*)a));}
static __attribute__((unused)) void g_0sl_forward_f(g_sl_function_f_t f, const void* a){f(*((float*)a));}
static __attribute__((unused)) void g_0sl_forward_d(g_sl_function_d_t f, const void* a){f(*((double*)a));}
static __attribute__((unused)) void g_0ul_forward_b(g_ul_function_b_t f, const void* a){f(*((bool*)a));}
static __attribute__((unused)) void g_0ul_forward_c(g_ul_function_c_t f, const void* a){f(*((char*)a));}
static __attribute__((unused)) void g_0ul_forward_ss(g_ul_function_ss_t f, const void* a){f(*((short*)a));}
static __attribute__((unused)) void g_0ul_forward_si(g_ul_function_si_t f, const void* a){f(*((int*)a));}
static __attribute__((unused)) void g_0ul_forward_sl(g_ul_function_sl_t f, const void* a){f(*((long*)a));}
static __attribute__((unused)) void g_0ul_forward_ul(g_ul_function_ul_t f, const void* a){f(*((unsigned long*)a));}
static __attribute__((unused)) void g_0ul_forward_f(g_ul_function_f_t f, const void* a){f(*((float*)a));}
static __attribute__((unused)) void g_0ul_forward_d(g_ul_function_d_t f, const void* a){f(*((double*)a));}
static __attribute__((unused)) void g_0f_forward_b(g_f_function_b_t f, const void* a){f(*((bool*)a));}
static __attribute__((unused)) void g_0f_forward_c(g_f_function_c_t f, const void* a){f(*((char*)a));}
static __attribute__((unused)) void g_0f_forward_ss(g_f_function_ss_t f, const void* a){f(*((short*)a));}
static __attribute__((unused)) void g_0f_forward_si(g_f_function_si_t f, const void* a){f(*((int*)a));}
static __attribute__((unused)) void g_0f_forward_sl(g_f_function_sl_t f, const void* a){f(*((long*)a));}
static __attribute__((unused)) void g_0f_forward_ul(g_f_function_ul_t f, const void* a){f(*((unsigned long*)a));}
static __attribute__((unused)) void g_0f_forward_f(g_f_function_f_t f, const void* a){f(*((float*)a));}
static __attribute__((unused)) void g_0f_forward_d(g_f_function_d_t f, const void* a){f(*((double*)a));}
static __attribute__((unused)) void g_0d_forward_b(g_d_function_b_t f, const void* a){f(*((bool*)a));}
static __attribute__((unused)) void g_0d_forward_c(g_d_function_c_t f, const void* a){f(*((char*)a));}
static __attribute__((unused)) void g_0d_forward_ss(g_d_function_ss_t f, const void* a){f(*((short*)a));}
static __attribute__((unused)) void g_0d_forward_si(g_d_function_si_t f, const void* a){f(*((int*)a));}
static __attribute__((unused)) void g_0d_forward_sl(g_d_function_sl_t f, const void* a){f(*((long*)a));}
static __attribute__((unused)) void g_0d_forward_ul(g_d_function_ul_t f, const void* a){f(*((unsigned long*)a));}
static __attribute__((unused)) void g_0d_forward_f(g_d_function_f_t f, const void* a){f(*((float*)a));}
static __attribute__((unused)) void g_0d_forward_d(g_d_function_d_t f, const void* a){f(*((double*)a));}

#define g_forward_0_1(x) _Generic((x) \
	, g_function_b_t : g_forward_b \
	, g_function_c_t : g_forward_c \
	, g_function_ss_t : g_forward_ss \
	, g_function_si_t : g_forward_si \
	, g_function_sl_t : g_forward_sl \
	, g_function_ul_t : g_forward_ul \
	, g_function_f_t : g_forward_f \
	, g_function_d_t : g_forward_d \
	, g_b_function_b_t : g_0b_forward_b \
	, g_b_function_c_t : g_0b_forward_c \
	, g_b_function_ss_t : g_0b_forward_ss \
	, g_b_function_si_t : g_0b_forward_si \
	, g_b_function_sl_t : g_0b_forward_sl \
	, g_b_function_ul_t : g_0b_forward_ul \
	, g_b_function_f_t : g_0b_forward_f \
	, g_b_function_d_t : g_0b_forward_d \
	, g_c_function_b_t : g_0c_forward_b \
	, g_c_function_c_t : g_0c_forward_c \
	, g_c_function_ss_t : g_0c_forward_ss \
	, g_c_function_si_t : g_0c_forward_si \
	, g_c_function_sl_t : g_0c_forward_sl \
	, g_c_function_ul_t : g_0c_forward_ul \
	, g_c_function_f_t : g_0c_forward_f \
	, g_c_function_d_t : g_0c_forward_d \
	, g_ss_function_b_t : g_0ss_forward_b \
	, g_ss_function_c_t : g_0ss_forward_c \
	, g_ss_function_ss_t : g_0ss_forward_ss \
	, g_ss_function_si_t : g_0ss_forward_si \
	, g_ss_function_sl_t : g_0ss_forward_sl \
	, g_ss_function_ul_t : g_0ss_forward_ul \
	, g_ss_function_f_t : g_0ss_forward_f \
	, g_ss_function_d_t : g_0ss_forward_d \
	, g_si_function_b_t : g_0si_forward_b \
	, g_si_function_c_t : g_0si_forward_c \
	, g_si_function_ss_t : g_0si_forward_ss \
	, g_si_function_si_t : g_0si_forward_si \
	, g_si_function_sl_t : g_0si_forward_sl \
	, g_si_function_ul_t : g_0si_forward_ul \
	, g_si_function_f_t : g_0si_forward_f \
	, g_si_function_d_t : g_0si_forward_d \
	, g_sl_function_b_t : g_0sl_forward_b \
	, g_sl_function_c_t : g_0sl_forward_c \
	, g_sl_function_ss_t : g_0sl_forward_ss \
	, g_sl_function_si_t : g_0sl_forward_si \
	, g_sl_function_sl_t : g_0sl_forward_sl \
	, g_sl_function_ul_t : g_0sl_forward_ul \
	, g_sl_function_f_t : g_0sl_forward_f \
	, g_sl_function_d_t : g_0sl_forward_d \
	, g_ul_function_b_t : g_0ul_forward_b \
	, g_ul_function_c_t : g_0ul_forward_c \
	, g_ul_function_ss_t : g_0ul_forward_ss \
	, g_ul_function_si_t : g_0ul_forward_si \
	, g_ul_function_sl_t : g_0ul_forward_sl \
	, g_ul_function_ul_t : g_0ul_forward_ul \
	, g_ul_function_f_t : g_0ul_forward_f \
	, g_ul_function_d_t : g_0ul_forward_d \
	, g_f_function_b_t : g_0f_forward_b \
	, g_f_function_c_t : g_0f_forward_c \
	, g_f_function_ss_t : g_0f_forward_ss \
	, g_f_function_si_t : g_0f_forward_si \
	, g_f_function_sl_t : g_0f_forward_sl \
	, g_f_function_ul_t : g_0f_forward_ul \
	, g_f_function_f_t : g_0f_forward_f \
	, g_f_function_d_t : g_0f_forward_d \
	, g_d_function_b_t : g_0d_forward_b \
	, g_d_function_c_t : g_0d_forward_c \
	, g_d_function_ss_t : g_0d_forward_ss \
	, g_d_function_si_t : g_0d_forward_si \
	, g_d_function_sl_t : g_0d_forward_sl \
	, g_d_function_ul_t : g_0d_forward_ul \
	, g_d_function_f_t : g_0d_forward_f \
	, g_d_function_d_t : g_0d_forward_d \
)
static __attribute__((unused)) void g_b_forward_b(g_b_function_b_t f, void* r, const void* a){*((bool*)r) = f(*((bool*)a));}
static __attribute__((unused)) void g_b_forward_c(g_b_function_c_t f, void* r, const void* a){*((bool*)r) = f(*((char*)a));}
static __attribute__((unused)) void g_b_forward_ss(g_b_function_ss_t f, void* r, const void* a){*((bool*)r) = f(*((short*)a));}
static __attribute__((unused)) void g_b_forward_si(g_b_function_si_t f, void* r, const void* a){*((bool*)r) = f(*((int*)a));}
static __attribute__((unused)) void g_b_forward_sl(g_b_function_sl_t f, void* r, const void* a){*((bool*)r) = f(*((long*)a));}
static __attribute__((unused)) void g_b_forward_ul(g_b_function_ul_t f, void* r, const void* a){*((bool*)r) = f(*((unsigned long*)a));}
static __attribute__((unused)) void g_b_forward_f(g_b_function_f_t f, void* r, const void* a){*((bool*)r) = f(*((float*)a));}
static __attribute__((unused)) void g_b_forward_d(g_b_function_d_t f, void* r, const void* a){*((bool*)r) = f(*((double*)a));}
static __attribute__((unused)) void g_c_forward_b(g_c_function_b_t f, void* r, const void* a){*((char*)r) = f(*((bool*)a));}
static __attribute__((unused)) void g_c_forward_c(g_c_function_c_t f, void* r, const void* a){*((char*)r) = f(*((char*)a));}
static __attribute__((unused)) void g_c_forward_ss(g_c_function_ss_t f, void* r, const void* a){*((char*)r) = f(*((short*)a));}
static __attribute__((unused)) void g_c_forward_si(g_c_function_si_t f, void* r, const void* a){*((char*)r) = f(*((int*)a));}
static __attribute__((unused)) void g_c_forward_sl(g_c_function_sl_t f, void* r, const void* a){*((char*)r) = f(*((long*)a));}
static __attribute__((unused)) void g_c_forward_ul(g_c_function_ul_t f, void* r, const void* a){*((char*)r) = f(*((unsigned long*)a));}
static __attribute__((unused)) void g_c_forward_f(g_c_function_f_t f, void* r, const void* a){*((char*)r) = f(*((float*)a));}
static __attribute__((unused)) void g_c_forward_d(g_c_function_d_t f, void* r, const void* a){*((char*)r) = f(*((double*)a));}
static __attribute__((unused)) void g_ss_forward_b(g_ss_function_b_t f, void* r, const void* a){*((short*)r) = f(*((bool*)a));}
static __attribute__((unused)) void g_ss_forward_c(g_ss_function_c_t f, void* r, const void* a){*((short*)r) = f(*((char*)a));}
static __attribute__((unused)) void g_ss_forward_ss(g_ss_function_ss_t f, void* r, const void* a){*((short*)r) = f(*((short*)a));}
static __attribute__((unused)) void g_ss_forward_si(g_ss_function_si_t f, void* r, const void* a){*((short*)r) = f(*((int*)a));}
static __attribute__((unused)) void g_ss_forward_sl(g_ss_function_sl_t f, void* r, const void* a){*((short*)r) = f(*((long*)a));}
static __attribute__((unused)) void g_ss_forward_ul(g_ss_function_ul_t f, void* r, const void* a){*((short*)r) = f(*((unsigned long*)a));}
static __attribute__((unused)) void g_ss_forward_f(g_ss_function_f_t f, void* r, const void* a){*((short*)r) = f(*((float*)a));}
static __attribute__((unused)) void g_ss_forward_d(g_ss_function_d_t f, void* r, const void* a){*((short*)r) = f(*((double*)a));}
static __attribute__((unused)) void g_si_forward_b(g_si_function_b_t f, void* r, const void* a){*((int*)r) = f(*((bool*)a));}
static __attribute__((unused)) void g_si_forward_c(g_si_function_c_t f, void* r, const void* a){*((int*)r) = f(*((char*)a));}
static __attribute__((unused)) void g_si_forward_ss(g_si_function_ss_t f, void* r, const void* a){*((int*)r) = f(*((short*)a));}
static __attribute__((unused)) void g_si_forward_si(g_si_function_si_t f, void* r, const void* a){*((int*)r) = f(*((int*)a));}
static __attribute__((unused)) void g_si_forward_sl(g_si_function_sl_t f, void* r, const void* a){*((int*)r) = f(*((long*)a));}
static __attribute__((unused)) void g_si_forward_ul(g_si_function_ul_t f, void* r, const void* a){*((int*)r) = f(*((unsigned long*)a));}
static __attribute__((unused)) void g_si_forward_f(g_si_function_f_t f, void* r, const void* a){*((int*)r) = f(*((float*)a));}
static __attribute__((unused)) void g_si_forward_d(g_si_function_d_t f, void* r, const void* a){*((int*)r) = f(*((double*)a));}
static __attribute__((unused)) void g_sl_forward_b(g_sl_function_b_t f, void* r, const void* a){*((long*)r) = f(*((bool*)a));}
static __attribute__((unused)) void g_sl_forward_c(g_sl_function_c_t f, void* r, const void* a){*((long*)r) = f(*((char*)a));}
static __attribute__((unused)) void g_sl_forward_ss(g_sl_function_ss_t f, void* r, const void* a){*((long*)r) = f(*((short*)a));}
static __attribute__((unused)) void g_sl_forward_si(g_sl_function_si_t f, void* r, const void* a){*((long*)r) = f(*((int*)a));}
static __attribute__((unused)) void g_sl_forward_sl(g_sl_function_sl_t f, void* r, const void* a){*((long*)r) = f(*((long*)a));}
static __attribute__((unused)) void g_sl_forward_ul(g_sl_function_ul_t f, void* r, const void* a){*((long*)r) = f(*((unsigned long*)a));}
static __attribute__((unused)) void g_sl_forward_f(g_sl_function_f_t f, void* r, const void* a){*((long*)r) = f(*((float*)a));}
static __attribute__((unused)) void g_sl_forward_d(g_sl_function_d_t f, void* r, const void* a){*((long*)r) = f(*((double*)a));}
static __attribute__((unused)) void g_ul_forward_b(g_ul_function_b_t f, void* r, const void* a){*((unsigned long*)r) = f(*((bool*)a));}
static __attribute__((unused)) void g_ul_forward_c(g_ul_function_c_t f, void* r, const void* a){*((unsigned long*)r) = f(*((char*)a));}
static __attribute__((unused)) void g_ul_forward_ss(g_ul_function_ss_t f, void* r, const void* a){*((unsigned long*)r) = f(*((short*)a));}
static __attribute__((unused)) void g_ul_forward_si(g_ul_function_si_t f, void* r, const void* a){*((unsigned long*)r) = f(*((int*)a));}
static __attribute__((unused)) void g_ul_forward_sl(g_ul_function_sl_t f, void* r, const void* a){*((unsigned long*)r) = f(*((long*)a));}
static __attribute__((unused)) void g_ul_forward_ul(g_ul_function_ul_t f, void* r, const void* a){*((unsigned long*)r) = f(*((unsigned long*)a));}
static __attribute__((unused)) void g_ul_forward_f(g_ul_function_f_t f, void* r, const void* a){*((unsigned long*)r) = f(*((float*)a));}
static __attribute__((unused)) void g_ul_forward_d(g_ul_function_d_t f, void* r, const void* a){*((unsigned long*)r) = f(*((double*)a));}
static __attribute__((unused)) void g_f_forward_b(g_f_function_b_t f, void* r, const void* a){*((float*)r) = f(*((bool*)a));}
static __attribute__((unused)) void g_f_forward_c(g_f_function_c_t f, void* r, const void* a){*((float*)r) = f(*((char*)a));}
static __attribute__((unused)) void g_f_forward_ss(g_f_function_ss_t f, void* r, const void* a){*((float*)r) = f(*((short*)a));}
static __attribute__((unused)) void g_f_forward_si(g_f_function_si_t f, void* r, const void* a){*((float*)r) = f(*((int*)a));}
static __attribute__((unused)) void g_f_forward_sl(g_f_function_sl_t f, void* r, const void* a){*((float*)r) = f(*((long*)a));}
static __attribute__((unused)) void g_f_forward_ul(g_f_function_ul_t f, void* r, const void* a){*((float*)r) = f(*((unsigned long*)a));}
static __attribute__((unused)) void g_f_forward_f(g_f_function_f_t f, void* r, const void* a){*((float*)r) = f(*((float*)a));}
static __attribute__((unused)) void g_f_forward_d(g_f_function_d_t f, void* r, const void* a){*((float*)r) = f(*((double*)a));}
static __attribute__((unused)) void g_d_forward_b(g_d_function_b_t f, void* r, const void* a){*((double*)r) = f(*((bool*)a));}
static __attribute__((unused)) void g_d_forward_c(g_d_function_c_t f, void* r, const void* a){*((double*)r) = f(*((char*)a));}
static __attribute__((unused)) void g_d_forward_ss(g_d_function_ss_t f, void* r, const void* a){*((double*)r) = f(*((short*)a));}
static __attribute__((unused)) void g_d_forward_si(g_d_function_si_t f, void* r, const void* a){*((double*)r) = f(*((int*)a));}
static __attribute__((unused)) void g_d_forward_sl(g_d_function_sl_t f, void* r, const void* a){*((double*)r) = f(*((long*)a));}
static __attribute__((unused)) void g_d_forward_ul(g_d_function_ul_t f, void* r, const void* a){*((double*)r) = f(*((unsigned long*)a));}
static __attribute__((unused)) void g_d_forward_f(g_d_function_f_t f, void* r, const void* a){*((double*)r) = f(*((float*)a));}
static __attribute__((unused)) void g_d_forward_d(g_d_function_d_t f, void* r, const void* a){*((double*)r) = f(*((double*)a));}

#define g_forward_1(x) _Generic((x) \
	, g_b_function_b_t : g_b_forward_b \
	, g_b_function_c_t : g_b_forward_c \
	, g_b_function_ss_t : g_b_forward_ss \
	, g_b_function_si_t : g_b_forward_si \
	, g_b_function_sl_t : g_b_forward_sl \
	, g_b_function_ul_t : g_b_forward_ul \
	, g_b_function_f_t : g_b_forward_f \
	, g_b_function_d_t : g_b_forward_d \
	, g_c_function_b_t : g_c_forward_b \
	, g_c_function_c_t : g_c_forward_c \
	, g_c_function_ss_t : g_c_forward_ss \
	, g_c_function_si_t : g_c_forward_si \
	, g_c_function_sl_t : g_c_forward_sl \
	, g_c_function_ul_t : g_c_forward_ul \
	, g_c_function_f_t : g_c_forward_f \
	, g_c_function_d_t : g_c_forward_d \
	, g_ss_function_b_t : g_ss_forward_b \
	, g_ss_function_c_t : g_ss_forward_c \
	, g_ss_function_ss_t : g_ss_forward_ss \
	, g_ss_function_si_t : g_ss_forward_si \
	, g_ss_function_sl_t : g_ss_forward_sl \
	, g_ss_function_ul_t : g_ss_forward_ul \
	, g_ss_function_f_t : g_ss_forward_f \
	, g_ss_function_d_t : g_ss_forward_d \
	, g_si_function_b_t : g_si_forward_b \
	, g_si_function_c_t : g_si_forward_c \
	, g_si_function_ss_t : g_si_forward_ss \
	, g_si_function_si_t : g_si_forward_si \
	, g_si_function_sl_t : g_si_forward_sl \
	, g_si_function_ul_t : g_si_forward_ul \
	, g_si_function_f_t : g_si_forward_f \
	, g_si_function_d_t : g_si_forward_d \
	, g_sl_function_b_t : g_sl_forward_b \
	, g_sl_function_c_t : g_sl_forward_c \
	, g_sl_function_ss_t : g_sl_forward_ss \
	, g_sl_function_si_t : g_sl_forward_si \
	, g_sl_function_sl_t : g_sl_forward_sl \
	, g_sl_function_ul_t : g_sl_forward_ul \
	, g_sl_function_f_t : g_sl_forward_f \
	, g_sl_function_d_t : g_sl_forward_d \
	, g_ul_function_b_t : g_ul_forward_b \
	, g_ul_function_c_t : g_ul_forward_c \
	, g_ul_function_ss_t : g_ul_forward_ss \
	, g_ul_function_si_t : g_ul_forward_si \
	, g_ul_function_sl_t : g_ul_forward_sl \
	, g_ul_function_ul_t : g_ul_forward_ul \
	, g_ul_function_f_t : g_ul_forward_f \
	, g_ul_function_d_t : g_ul_forward_d \
	, g_f_function_b_t : g_f_forward_b \
	, g_f_function_c_t : g_f_forward_c \
	, g_f_function_ss_t : g_f_forward_ss \
	, g_f_function_si_t : g_f_forward_si \
	, g_f_function_sl_t : g_f_forward_sl \
	, g_f_function_ul_t : g_f_forward_ul \
	, g_f_function_f_t : g_f_forward_f \
	, g_f_function_d_t : g_f_forward_d \
	, g_d_function_b_t : g_d_forward_b \
	, g_d_function_c_t : g_d_forward_c \
	, g_d_function_ss_t : g_d_forward_ss \
	, g_d_function_si_t : g_d_forward_si \
	, g_d_function_sl_t : g_d_forward_sl \
	, g_d_function_ul_t : g_d_forward_ul \
	, g_d_function_f_t : g_d_forward_f \
	, g_d_function_d_t : g_d_forward_d \
)
static __attribute__((unused)) void g_b_forward_b_b(g_b_function_b_b_t f, void* r, const void* a, const void* b){*((bool*)r) = f(*((bool*)a),*((bool*)b));}
static __attribute__((unused)) void g_b_forward_b_c(g_b_function_b_c_t f, void* r, const void* a, const void* b){*((bool*)r) = f(*((bool*)a),*((char*)b));}
static __attribute__((unused)) void g_b_forward_b_ss(g_b_function_b_ss_t f, void* r, const void* a, const void* b){*((bool*)r) = f(*((bool*)a),*((short*)b));}
static __attribute__((unused)) void g_b_forward_b_si(g_b_function_b_si_t f, void* r, const void* a, const void* b){*((bool*)r) = f(*((bool*)a),*((int*)b));}
static __attribute__((unused)) void g_b_forward_b_sl(g_b_function_b_sl_t f, void* r, const void* a, const void* b){*((bool*)r) = f(*((bool*)a),*((long*)b));}
static __attribute__((unused)) void g_b_forward_b_ul(g_b_function_b_ul_t f, void* r, const void* a, const void* b){*((bool*)r) = f(*((bool*)a),*((unsigned long*)b));}
static __attribute__((unused)) void g_b_forward_b_f(g_b_function_b_f_t f, void* r, const void* a, const void* b){*((bool*)r) = f(*((bool*)a),*((float*)b));}
static __attribute__((unused)) void g_b_forward_b_d(g_b_function_b_d_t f, void* r, const void* a, const void* b){*((bool*)r) = f(*((bool*)a),*((double*)b));}
static __attribute__((unused)) void g_b_forward_c_b(g_b_function_c_b_t f, void* r, const void* a, const void* b){*((bool*)r) = f(*((char*)a),*((bool*)b));}
static __attribute__((unused)) void g_b_forward_c_c(g_b_function_c_c_t f, void* r, const void* a, const void* b){*((bool*)r) = f(*((char*)a),*((char*)b));}
static __attribute__((unused)) void g_b_forward_c_ss(g_b_function_c_ss_t f, void* r, const void* a, const void* b){*((bool*)r) = f(*((char*)a),*((short*)b));}
static __attribute__((unused)) void g_b_forward_c_si(g_b_function_c_si_t f, void* r, const void* a, const void* b){*((bool*)r) = f(*((char*)a),*((int*)b));}
static __attribute__((unused)) void g_b_forward_c_sl(g_b_function_c_sl_t f, void* r, const void* a, const void* b){*((bool*)r) = f(*((char*)a),*((long*)b));}
static __attribute__((unused)) void g_b_forward_c_ul(g_b_function_c_ul_t f, void* r, const void* a, const void* b){*((bool*)r) = f(*((char*)a),*((unsigned long*)b));}
static __attribute__((unused)) void g_b_forward_c_f(g_b_function_c_f_t f, void* r, const void* a, const void* b){*((bool*)r) = f(*((char*)a),*((float*)b));}
static __attribute__((unused)) void g_b_forward_c_d(g_b_function_c_d_t f, void* r, const void* a, const void* b){*((bool*)r) = f(*((char*)a),*((double*)b));}
static __attribute__((unused)) void g_b_forward_ss_b(g_b_function_ss_b_t f, void* r, const void* a, const void* b){*((bool*)r) = f(*((short*)a),*((bool*)b));}
static __attribute__((unused)) void g_b_forward_ss_c(g_b_function_ss_c_t f, void* r, const void* a, const void* b){*((bool*)r) = f(*((short*)a),*((char*)b));}
static __attribute__((unused)) void g_b_forward_ss_ss(g_b_function_ss_ss_t f, void* r, const void* a, const void* b){*((bool*)r) = f(*((short*)a),*((short*)b));}
static __attribute__((unused)) void g_b_forward_ss_si(g_b_function_ss_si_t f, void* r, const void* a, const void* b){*((bool*)r) = f(*((short*)a),*((int*)b));}
static __attribute__((unused)) void g_b_forward_ss_sl(g_b_function_ss_sl_t f, void* r, const void* a, const void* b){*((bool*)r) = f(*((short*)a),*((long*)b));}
static __attribute__((unused)) void g_b_forward_ss_ul(g_b_function_ss_ul_t f, void* r, const void* a, const void* b){*((bool*)r) = f(*((short*)a),*((unsigned long*)b));}
static __attribute__((unused)) void g_b_forward_ss_f(g_b_function_ss_f_t f, void* r, const void* a, const void* b){*((bool*)r) = f(*((short*)a),*((float*)b));}
static __attribute__((unused)) void g_b_forward_ss_d(g_b_function_ss_d_t f, void* r, const void* a, const void* b){*((bool*)r) = f(*((short*)a),*((double*)b));}
static __attribute__((unused)) void g_b_forward_si_b(g_b_function_si_b_t f, void* r, const void* a, const void* b){*((bool*)r) = f(*((int*)a),*((bool*)b));}
static __attribute__((unused)) void g_b_forward_si_c(g_b_function_si_c_t f, void* r, const void* a, const void* b){*((bool*)r) = f(*((int*)a),*((char*)b));}
static __attribute__((unused)) void g_b_forward_si_ss(g_b_function_si_ss_t f, void* r, const void* a, const void* b){*((bool*)r) = f(*((int*)a),*((short*)b));}
static __attribute__((unused)) void g_b_forward_si_si(g_b_function_si_si_t f, void* r, const void* a, const void* b){*((bool*)r) = f(*((int*)a),*((int*)b));}
static __attribute__((unused)) void g_b_forward_si_sl(g_b_function_si_sl_t f, void* r, const void* a, const void* b){*((bool*)r) = f(*((int*)a),*((long*)b));}
static __attribute__((unused)) void g_b_forward_si_ul(g_b_function_si_ul_t f, void* r, const void* a, const void* b){*((bool*)r) = f(*((int*)a),*((unsigned long*)b));}
static __attribute__((unused)) void g_b_forward_si_f(g_b_function_si_f_t f, void* r, const void* a, const void* b){*((bool*)r) = f(*((int*)a),*((float*)b));}
static __attribute__((unused)) void g_b_forward_si_d(g_b_function_si_d_t f, void* r, const void* a, const void* b){*((bool*)r) = f(*((int*)a),*((double*)b));}
static __attribute__((unused)) void g_b_forward_sl_b(g_b_function_sl_b_t f, void* r, const void* a, const void* b){*((bool*)r) = f(*((long*)a),*((bool*)b));}
static __attribute__((unused)) void g_b_forward_sl_c(g_b_function_sl_c_t f, void* r, const void* a, const void* b){*((bool*)r) = f(*((long*)a),*((char*)b));}
static __attribute__((unused)) void g_b_forward_sl_ss(g_b_function_sl_ss_t f, void* r, const void* a, const void* b){*((bool*)r) = f(*((long*)a),*((short*)b));}
static __attribute__((unused)) void g_b_forward_sl_si(g_b_function_sl_si_t f, void* r, const void* a, const void* b){*((bool*)r) = f(*((long*)a),*((int*)b));}
static __attribute__((unused)) void g_b_forward_sl_sl(g_b_function_sl_sl_t f, void* r, const void* a, const void* b){*((bool*)r) = f(*((long*)a),*((long*)b));}
static __attribute__((unused)) void g_b_forward_sl_ul(g_b_function_sl_ul_t f, void* r, const void* a, const void* b){*((bool*)r) = f(*((long*)a),*((unsigned long*)b));}
static __attribute__((unused)) void g_b_forward_sl_f(g_b_function_sl_f_t f, void* r, const void* a, const void* b){*((bool*)r) = f(*((long*)a),*((float*)b));}
static __attribute__((unused)) void g_b_forward_sl_d(g_b_function_sl_d_t f, void* r, const void* a, const void* b){*((bool*)r) = f(*((long*)a),*((double*)b));}
static __attribute__((unused)) void g_b_forward_ul_b(g_b_function_ul_b_t f, void* r, const void* a, const void* b){*((bool*)r) = f(*((unsigned long*)a),*((bool*)b));}
static __attribute__((unused)) void g_b_forward_ul_c(g_b_function_ul_c_t f, void* r, const void* a, const void* b){*((bool*)r) = f(*((unsigned long*)a),*((char*)b));}
static __attribute__((unused)) void g_b_forward_ul_ss(g_b_function_ul_ss_t f, void* r, const void* a, const void* b){*((bool*)r) = f(*((unsigned long*)a),*((short*)b));}
static __attribute__((unused)) void g_b_forward_ul_si(g_b_function_ul_si_t f, void* r, const void* a, const void* b){*((bool*)r) = f(*((unsigned long*)a),*((int*)b));}
static __attribute__((unused)) void g_b_forward_ul_sl(g_b_function_ul_sl_t f, void* r, const void* a, const void* b){*((bool*)r) = f(*((unsigned long*)a),*((long*)b));}
static __attribute__((unused)) void g_b_forward_ul_ul(g_b_function_ul_ul_t f, void* r, const void* a, const void* b){*((bool*)r) = f(*((unsigned long*)a),*((unsigned long*)b));}
static __attribute__((unused)) void g_b_forward_ul_f(g_b_function_ul_f_t f, void* r, const void* a, const void* b){*((bool*)r) = f(*((unsigned long*)a),*((float*)b));}
static __attribute__((unused)) void g_b_forward_ul_d(g_b_function_ul_d_t f, void* r, const void* a, const void* b){*((bool*)r) = f(*((unsigned long*)a),*((double*)b));}
static __attribute__((unused)) void g_b_forward_f_b(g_b_function_f_b_t f, void* r, const void* a, const void* b){*((bool*)r) = f(*((float*)a),*((bool*)b));}
static __attribute__((unused)) void g_b_forward_f_c(g_b_function_f_c_t f, void* r, const void* a, const void* b){*((bool*)r) = f(*((float*)a),*((char*)b));}
static __attribute__((unused)) void g_b_forward_f_ss(g_b_function_f_ss_t f, void* r, const void* a, const void* b){*((bool*)r) = f(*((float*)a),*((short*)b));}
static __attribute__((unused)) void g_b_forward_f_si(g_b_function_f_si_t f, void* r, const void* a, const void* b){*((bool*)r) = f(*((float*)a),*((int*)b));}
static __attribute__((unused)) void g_b_forward_f_sl(g_b_function_f_sl_t f, void* r, const void* a, const void* b){*((bool*)r) = f(*((float*)a),*((long*)b));}
static __attribute__((unused)) void g_b_forward_f_ul(g_b_function_f_ul_t f, void* r, const void* a, const void* b){*((bool*)r) = f(*((float*)a),*((unsigned long*)b));}
static __attribute__((unused)) void g_b_forward_f_f(g_b_function_f_f_t f, void* r, const void* a, const void* b){*((bool*)r) = f(*((float*)a),*((float*)b));}
static __attribute__((unused)) void g_b_forward_f_d(g_b_function_f_d_t f, void* r, const void* a, const void* b){*((bool*)r) = f(*((float*)a),*((double*)b));}
static __attribute__((unused)) void g_b_forward_d_b(g_b_function_d_b_t f, void* r, const void* a, const void* b){*((bool*)r) = f(*((double*)a),*((bool*)b));}
static __attribute__((unused)) void g_b_forward_d_c(g_b_function_d_c_t f, void* r, const void* a, const void* b){*((bool*)r) = f(*((double*)a),*((char*)b));}
static __attribute__((unused)) void g_b_forward_d_ss(g_b_function_d_ss_t f, void* r, const void* a, const void* b){*((bool*)r) = f(*((double*)a),*((short*)b));}
static __attribute__((unused)) void g_b_forward_d_si(g_b_function_d_si_t f, void* r, const void* a, const void* b){*((bool*)r) = f(*((double*)a),*((int*)b));}
static __attribute__((unused)) void g_b_forward_d_sl(g_b_function_d_sl_t f, void* r, const void* a, const void* b){*((bool*)r) = f(*((double*)a),*((long*)b));}
static __attribute__((unused)) void g_b_forward_d_ul(g_b_function_d_ul_t f, void* r, const void* a, const void* b){*((bool*)r) = f(*((double*)a),*((unsigned long*)b));}
static __attribute__((unused)) void g_b_forward_d_f(g_b_function_d_f_t f, void* r, const void* a, const void* b){*((bool*)r) = f(*((double*)a),*((float*)b));}
static __attribute__((unused)) void g_b_forward_d_d(g_b_function_d_d_t f, void* r, const void* a, const void* b){*((bool*)r) = f(*((double*)a),*((double*)b));}
static __attribute__((unused)) void g_c_forward_b_b(g_c_function_b_b_t f, void* r, const void* a, const void* b){*((char*)r) = f(*((bool*)a),*((bool*)b));}
static __attribute__((unused)) void g_c_forward_b_c(g_c_function_b_c_t f, void* r, const void* a, const void* b){*((char*)r) = f(*((bool*)a),*((char*)b));}
static __attribute__((unused)) void g_c_forward_b_ss(g_c_function_b_ss_t f, void* r, const void* a, const void* b){*((char*)r) = f(*((bool*)a),*((short*)b));}
static __attribute__((unused)) void g_c_forward_b_si(g_c_function_b_si_t f, void* r, const void* a, const void* b){*((char*)r) = f(*((bool*)a),*((int*)b));}
static __attribute__((unused)) void g_c_forward_b_sl(g_c_function_b_sl_t f, void* r, const void* a, const void* b){*((char*)r) = f(*((bool*)a),*((long*)b));}
static __attribute__((unused)) void g_c_forward_b_ul(g_c_function_b_ul_t f, void* r, const void* a, const void* b){*((char*)r) = f(*((bool*)a),*((unsigned long*)b));}
static __attribute__((unused)) void g_c_forward_b_f(g_c_function_b_f_t f, void* r, const void* a, const void* b){*((char*)r) = f(*((bool*)a),*((float*)b));}
static __attribute__((unused)) void g_c_forward_b_d(g_c_function_b_d_t f, void* r, const void* a, const void* b){*((char*)r) = f(*((bool*)a),*((double*)b));}
static __attribute__((unused)) void g_c_forward_c_b(g_c_function_c_b_t f, void* r, const void* a, const void* b){*((char*)r) = f(*((char*)a),*((bool*)b));}
static __attribute__((unused)) void g_c_forward_c_c(g_c_function_c_c_t f, void* r, const void* a, const void* b){*((char*)r) = f(*((char*)a),*((char*)b));}
static __attribute__((unused)) void g_c_forward_c_ss(g_c_function_c_ss_t f, void* r, const void* a, const void* b){*((char*)r) = f(*((char*)a),*((short*)b));}
static __attribute__((unused)) void g_c_forward_c_si(g_c_function_c_si_t f, void* r, const void* a, const void* b){*((char*)r) = f(*((char*)a),*((int*)b));}
static __attribute__((unused)) void g_c_forward_c_sl(g_c_function_c_sl_t f, void* r, const void* a, const void* b){*((char*)r) = f(*((char*)a),*((long*)b));}
static __attribute__((unused)) void g_c_forward_c_ul(g_c_function_c_ul_t f, void* r, const void* a, const void* b){*((char*)r) = f(*((char*)a),*((unsigned long*)b));}
static __attribute__((unused)) void g_c_forward_c_f(g_c_function_c_f_t f, void* r, const void* a, const void* b){*((char*)r) = f(*((char*)a),*((float*)b));}
static __attribute__((unused)) void g_c_forward_c_d(g_c_function_c_d_t f, void* r, const void* a, const void* b){*((char*)r) = f(*((char*)a),*((double*)b));}
static __attribute__((unused)) void g_c_forward_ss_b(g_c_function_ss_b_t f, void* r, const void* a, const void* b){*((char*)r) = f(*((short*)a),*((bool*)b));}
static __attribute__((unused)) void g_c_forward_ss_c(g_c_function_ss_c_t f, void* r, const void* a, const void* b){*((char*)r) = f(*((short*)a),*((char*)b));}
static __attribute__((unused)) void g_c_forward_ss_ss(g_c_function_ss_ss_t f, void* r, const void* a, const void* b){*((char*)r) = f(*((short*)a),*((short*)b));}
static __attribute__((unused)) void g_c_forward_ss_si(g_c_function_ss_si_t f, void* r, const void* a, const void* b){*((char*)r) = f(*((short*)a),*((int*)b));}
static __attribute__((unused)) void g_c_forward_ss_sl(g_c_function_ss_sl_t f, void* r, const void* a, const void* b){*((char*)r) = f(*((short*)a),*((long*)b));}
static __attribute__((unused)) void g_c_forward_ss_ul(g_c_function_ss_ul_t f, void* r, const void* a, const void* b){*((char*)r) = f(*((short*)a),*((unsigned long*)b));}
static __attribute__((unused)) void g_c_forward_ss_f(g_c_function_ss_f_t f, void* r, const void* a, const void* b){*((char*)r) = f(*((short*)a),*((float*)b));}
static __attribute__((unused)) void g_c_forward_ss_d(g_c_function_ss_d_t f, void* r, const void* a, const void* b){*((char*)r) = f(*((short*)a),*((double*)b));}
static __attribute__((unused)) void g_c_forward_si_b(g_c_function_si_b_t f, void* r, const void* a, const void* b){*((char*)r) = f(*((int*)a),*((bool*)b));}
static __attribute__((unused)) void g_c_forward_si_c(g_c_function_si_c_t f, void* r, const void* a, const void* b){*((char*)r) = f(*((int*)a),*((char*)b));}
static __attribute__((unused)) void g_c_forward_si_ss(g_c_function_si_ss_t f, void* r, const void* a, const void* b){*((char*)r) = f(*((int*)a),*((short*)b));}
static __attribute__((unused)) void g_c_forward_si_si(g_c_function_si_si_t f, void* r, const void* a, const void* b){*((char*)r) = f(*((int*)a),*((int*)b));}
static __attribute__((unused)) void g_c_forward_si_sl(g_c_function_si_sl_t f, void* r, const void* a, const void* b){*((char*)r) = f(*((int*)a),*((long*)b));}
static __attribute__((unused)) void g_c_forward_si_ul(g_c_function_si_ul_t f, void* r, const void* a, const void* b){*((char*)r) = f(*((int*)a),*((unsigned long*)b));}
static __attribute__((unused)) void g_c_forward_si_f(g_c_function_si_f_t f, void* r, const void* a, const void* b){*((char*)r) = f(*((int*)a),*((float*)b));}
static __attribute__((unused)) void g_c_forward_si_d(g_c_function_si_d_t f, void* r, const void* a, const void* b){*((char*)r) = f(*((int*)a),*((double*)b));}
static __attribute__((unused)) void g_c_forward_sl_b(g_c_function_sl_b_t f, void* r, const void* a, const void* b){*((char*)r) = f(*((long*)a),*((bool*)b));}
static __attribute__((unused)) void g_c_forward_sl_c(g_c_function_sl_c_t f, void* r, const void* a, const void* b){*((char*)r) = f(*((long*)a),*((char*)b));}
static __attribute__((unused)) void g_c_forward_sl_ss(g_c_function_sl_ss_t f, void* r, const void* a, const void* b){*((char*)r) = f(*((long*)a),*((short*)b));}
static __attribute__((unused)) void g_c_forward_sl_si(g_c_function_sl_si_t f, void* r, const void* a, const void* b){*((char*)r) = f(*((long*)a),*((int*)b));}
static __attribute__((unused)) void g_c_forward_sl_sl(g_c_function_sl_sl_t f, void* r, const void* a, const void* b){*((char*)r) = f(*((long*)a),*((long*)b));}
static __attribute__((unused)) void g_c_forward_sl_ul(g_c_function_sl_ul_t f, void* r, const void* a, const void* b){*((char*)r) = f(*((long*)a),*((unsigned long*)b));}
static __attribute__((unused)) void g_c_forward_sl_f(g_c_function_sl_f_t f, void* r, const void* a, const void* b){*((char*)r) = f(*((long*)a),*((float*)b));}
static __attribute__((unused)) void g_c_forward_sl_d(g_c_function_sl_d_t f, void* r, const void* a, const void* b){*((char*)r) = f(*((long*)a),*((double*)b));}
static __attribute__((unused)) void g_c_forward_ul_b(g_c_function_ul_b_t f, void* r, const void* a, const void* b){*((char*)r) = f(*((unsigned long*)a),*((bool*)b));}
static __attribute__((unused)) void g_c_forward_ul_c(g_c_function_ul_c_t f, void* r, const void* a, const void* b){*((char*)r) = f(*((unsigned long*)a),*((char*)b));}
static __attribute__((unused)) void g_c_forward_ul_ss(g_c_function_ul_ss_t f, void* r, const void* a, const void* b){*((char*)r) = f(*((unsigned long*)a),*((short*)b));}
static __attribute__((unused)) void g_c_forward_ul_si(g_c_function_ul_si_t f, void* r, const void* a, const void* b){*((char*)r) = f(*((unsigned long*)a),*((int*)b));}
static __attribute__((unused)) void g_c_forward_ul_sl(g_c_function_ul_sl_t f, void* r, const void* a, const void* b){*((char*)r) = f(*((unsigned long*)a),*((long*)b));}
static __attribute__((unused)) void g_c_forward_ul_ul(g_c_function_ul_ul_t f, void* r, const void* a, const void* b){*((char*)r) = f(*((unsigned long*)a),*((unsigned long*)b));}
static __attribute__((unused)) void g_c_forward_ul_f(g_c_function_ul_f_t f, void* r, const void* a, const void* b){*((char*)r) = f(*((unsigned long*)a),*((float*)b));}
static __attribute__((unused)) void g_c_forward_ul_d(g_c_function_ul_d_t f, void* r, const void* a, const void* b){*((char*)r) = f(*((unsigned long*)a),*((double*)b));}
static __attribute__((unused)) void g_c_forward_f_b(g_c_function_f_b_t f, void* r, const void* a, const void* b){*((char*)r) = f(*((float*)a),*((bool*)b));}
static __attribute__((unused)) void g_c_forward_f_c(g_c_function_f_c_t f, void* r, const void* a, const void* b){*((char*)r) = f(*((float*)a),*((char*)b));}
static __attribute__((unused)) void g_c_forward_f_ss(g_c_function_f_ss_t f, void* r, const void* a, const void* b){*((char*)r) = f(*((float*)a),*((short*)b));}
static __attribute__((unused)) void g_c_forward_f_si(g_c_function_f_si_t f, void* r, const void* a, const void* b){*((char*)r) = f(*((float*)a),*((int*)b));}
static __attribute__((unused)) void g_c_forward_f_sl(g_c_function_f_sl_t f, void* r, const void* a, const void* b){*((char*)r) = f(*((float*)a),*((long*)b));}
static __attribute__((unused)) void g_c_forward_f_ul(g_c_function_f_ul_t f, void* r, const void* a, const void* b){*((char*)r) = f(*((float*)a),*((unsigned long*)b));}
static __attribute__((unused)) void g_c_forward_f_f(g_c_function_f_f_t f, void* r, const void* a, const void* b){*((char*)r) = f(*((float*)a),*((float*)b));}
static __attribute__((unused)) void g_c_forward_f_d(g_c_function_f_d_t f, void* r, const void* a, const void* b){*((char*)r) = f(*((float*)a),*((double*)b));}
static __attribute__((unused)) void g_c_forward_d_b(g_c_function_d_b_t f, void* r, const void* a, const void* b){*((char*)r) = f(*((double*)a),*((bool*)b));}
static __attribute__((unused)) void g_c_forward_d_c(g_c_function_d_c_t f, void* r, const void* a, const void* b){*((char*)r) = f(*((double*)a),*((char*)b));}
static __attribute__((unused)) void g_c_forward_d_ss(g_c_function_d_ss_t f, void* r, const void* a, const void* b){*((char*)r) = f(*((double*)a),*((short*)b));}
static __attribute__((unused)) void g_c_forward_d_si(g_c_function_d_si_t f, void* r, const void* a, const void* b){*((char*)r) = f(*((double*)a),*((int*)b));}
static __attribute__((unused)) void g_c_forward_d_sl(g_c_function_d_sl_t f, void* r, const void* a, const void* b){*((char*)r) = f(*((double*)a),*((long*)b));}
static __attribute__((unused)) void g_c_forward_d_ul(g_c_function_d_ul_t f, void* r, const void* a, const void* b){*((char*)r) = f(*((double*)a),*((unsigned long*)b));}
static __attribute__((unused)) void g_c_forward_d_f(g_c_function_d_f_t f, void* r, const void* a, const void* b){*((char*)r) = f(*((double*)a),*((float*)b));}
static __attribute__((unused)) void g_c_forward_d_d(g_c_function_d_d_t f, void* r, const void* a, const void* b){*((char*)r) = f(*((double*)a),*((double*)b));}
static __attribute__((unused)) void g_ss_forward_b_b(g_ss_function_b_b_t f, void* r, const void* a, const void* b){*((short*)r) = f(*((bool*)a),*((bool*)b));}
static __attribute__((unused)) void g_ss_forward_b_c(g_ss_function_b_c_t f, void* r, const void* a, const void* b){*((short*)r) = f(*((bool*)a),*((char*)b));}
static __attribute__((unused)) void g_ss_forward_b_ss(g_ss_function_b_ss_t f, void* r, const void* a, const void* b){*((short*)r) = f(*((bool*)a),*((short*)b));}
static __attribute__((unused)) void g_ss_forward_b_si(g_ss_function_b_si_t f, void* r, const void* a, const void* b){*((short*)r) = f(*((bool*)a),*((int*)b));}
static __attribute__((unused)) void g_ss_forward_b_sl(g_ss_function_b_sl_t f, void* r, const void* a, const void* b){*((short*)r) = f(*((bool*)a),*((long*)b));}
static __attribute__((unused)) void g_ss_forward_b_ul(g_ss_function_b_ul_t f, void* r, const void* a, const void* b){*((short*)r) = f(*((bool*)a),*((unsigned long*)b));}
static __attribute__((unused)) void g_ss_forward_b_f(g_ss_function_b_f_t f, void* r, const void* a, const void* b){*((short*)r) = f(*((bool*)a),*((float*)b));}
static __attribute__((unused)) void g_ss_forward_b_d(g_ss_function_b_d_t f, void* r, const void* a, const void* b){*((short*)r) = f(*((bool*)a),*((double*)b));}
static __attribute__((unused)) void g_ss_forward_c_b(g_ss_function_c_b_t f, void* r, const void* a, const void* b){*((short*)r) = f(*((char*)a),*((bool*)b));}
static __attribute__((unused)) void g_ss_forward_c_c(g_ss_function_c_c_t f, void* r, const void* a, const void* b){*((short*)r) = f(*((char*)a),*((char*)b));}
static __attribute__((unused)) void g_ss_forward_c_ss(g_ss_function_c_ss_t f, void* r, const void* a, const void* b){*((short*)r) = f(*((char*)a),*((short*)b));}
static __attribute__((unused)) void g_ss_forward_c_si(g_ss_function_c_si_t f, void* r, const void* a, const void* b){*((short*)r) = f(*((char*)a),*((int*)b));}
static __attribute__((unused)) void g_ss_forward_c_sl(g_ss_function_c_sl_t f, void* r, const void* a, const void* b){*((short*)r) = f(*((char*)a),*((long*)b));}
static __attribute__((unused)) void g_ss_forward_c_ul(g_ss_function_c_ul_t f, void* r, const void* a, const void* b){*((short*)r) = f(*((char*)a),*((unsigned long*)b));}
static __attribute__((unused)) void g_ss_forward_c_f(g_ss_function_c_f_t f, void* r, const void* a, const void* b){*((short*)r) = f(*((char*)a),*((float*)b));}
static __attribute__((unused)) void g_ss_forward_c_d(g_ss_function_c_d_t f, void* r, const void* a, const void* b){*((short*)r) = f(*((char*)a),*((double*)b));}
static __attribute__((unused)) void g_ss_forward_ss_b(g_ss_function_ss_b_t f, void* r, const void* a, const void* b){*((short*)r) = f(*((short*)a),*((bool*)b));}
static __attribute__((unused)) void g_ss_forward_ss_c(g_ss_function_ss_c_t f, void* r, const void* a, const void* b){*((short*)r) = f(*((short*)a),*((char*)b));}
static __attribute__((unused)) void g_ss_forward_ss_ss(g_ss_function_ss_ss_t f, void* r, const void* a, const void* b){*((short*)r) = f(*((short*)a),*((short*)b));}
static __attribute__((unused)) void g_ss_forward_ss_si(g_ss_function_ss_si_t f, void* r, const void* a, const void* b){*((short*)r) = f(*((short*)a),*((int*)b));}
static __attribute__((unused)) void g_ss_forward_ss_sl(g_ss_function_ss_sl_t f, void* r, const void* a, const void* b){*((short*)r) = f(*((short*)a),*((long*)b));}
static __attribute__((unused)) void g_ss_forward_ss_ul(g_ss_function_ss_ul_t f, void* r, const void* a, const void* b){*((short*)r) = f(*((short*)a),*((unsigned long*)b));}
static __attribute__((unused)) void g_ss_forward_ss_f(g_ss_function_ss_f_t f, void* r, const void* a, const void* b){*((short*)r) = f(*((short*)a),*((float*)b));}
static __attribute__((unused)) void g_ss_forward_ss_d(g_ss_function_ss_d_t f, void* r, const void* a, const void* b){*((short*)r) = f(*((short*)a),*((double*)b));}
static __attribute__((unused)) void g_ss_forward_si_b(g_ss_function_si_b_t f, void* r, const void* a, const void* b){*((short*)r) = f(*((int*)a),*((bool*)b));}
static __attribute__((unused)) void g_ss_forward_si_c(g_ss_function_si_c_t f, void* r, const void* a, const void* b){*((short*)r) = f(*((int*)a),*((char*)b));}
static __attribute__((unused)) void g_ss_forward_si_ss(g_ss_function_si_ss_t f, void* r, const void* a, const void* b){*((short*)r) = f(*((int*)a),*((short*)b));}
static __attribute__((unused)) void g_ss_forward_si_si(g_ss_function_si_si_t f, void* r, const void* a, const void* b){*((short*)r) = f(*((int*)a),*((int*)b));}
static __attribute__((unused)) void g_ss_forward_si_sl(g_ss_function_si_sl_t f, void* r, const void* a, const void* b){*((short*)r) = f(*((int*)a),*((long*)b));}
static __attribute__((unused)) void g_ss_forward_si_ul(g_ss_function_si_ul_t f, void* r, const void* a, const void* b){*((short*)r) = f(*((int*)a),*((unsigned long*)b));}
static __attribute__((unused)) void g_ss_forward_si_f(g_ss_function_si_f_t f, void* r, const void* a, const void* b){*((short*)r) = f(*((int*)a),*((float*)b));}
static __attribute__((unused)) void g_ss_forward_si_d(g_ss_function_si_d_t f, void* r, const void* a, const void* b){*((short*)r) = f(*((int*)a),*((double*)b));}
static __attribute__((unused)) void g_ss_forward_sl_b(g_ss_function_sl_b_t f, void* r, const void* a, const void* b){*((short*)r) = f(*((long*)a),*((bool*)b));}
static __attribute__((unused)) void g_ss_forward_sl_c(g_ss_function_sl_c_t f, void* r, const void* a, const void* b){*((short*)r) = f(*((long*)a),*((char*)b));}
static __attribute__((unused)) void g_ss_forward_sl_ss(g_ss_function_sl_ss_t f, void* r, const void* a, const void* b){*((short*)r) = f(*((long*)a),*((short*)b));}
static __attribute__((unused)) void g_ss_forward_sl_si(g_ss_function_sl_si_t f, void* r, const void* a, const void* b){*((short*)r) = f(*((long*)a),*((int*)b));}
static __attribute__((unused)) void g_ss_forward_sl_sl(g_ss_function_sl_sl_t f, void* r, const void* a, const void* b){*((short*)r) = f(*((long*)a),*((long*)b));}
static __attribute__((unused)) void g_ss_forward_sl_ul(g_ss_function_sl_ul_t f, void* r, const void* a, const void* b){*((short*)r) = f(*((long*)a),*((unsigned long*)b));}
static __attribute__((unused)) void g_ss_forward_sl_f(g_ss_function_sl_f_t f, void* r, const void* a, const void* b){*((short*)r) = f(*((long*)a),*((float*)b));}
static __attribute__((unused)) void g_ss_forward_sl_d(g_ss_function_sl_d_t f, void* r, const void* a, const void* b){*((short*)r) = f(*((long*)a),*((double*)b));}
static __attribute__((unused)) void g_ss_forward_ul_b(g_ss_function_ul_b_t f, void* r, const void* a, const void* b){*((short*)r) = f(*((unsigned long*)a),*((bool*)b));}
static __attribute__((unused)) void g_ss_forward_ul_c(g_ss_function_ul_c_t f, void* r, const void* a, const void* b){*((short*)r) = f(*((unsigned long*)a),*((char*)b));}
static __attribute__((unused)) void g_ss_forward_ul_ss(g_ss_function_ul_ss_t f, void* r, const void* a, const void* b){*((short*)r) = f(*((unsigned long*)a),*((short*)b));}
static __attribute__((unused)) void g_ss_forward_ul_si(g_ss_function_ul_si_t f, void* r, const void* a, const void* b){*((short*)r) = f(*((unsigned long*)a),*((int*)b));}
static __attribute__((unused)) void g_ss_forward_ul_sl(g_ss_function_ul_sl_t f, void* r, const void* a, const void* b){*((short*)r) = f(*((unsigned long*)a),*((long*)b));}
static __attribute__((unused)) void g_ss_forward_ul_ul(g_ss_function_ul_ul_t f, void* r, const void* a, const void* b){*((short*)r) = f(*((unsigned long*)a),*((unsigned long*)b));}
static __attribute__((unused)) void g_ss_forward_ul_f(g_ss_function_ul_f_t f, void* r, const void* a, const void* b){*((short*)r) = f(*((unsigned long*)a),*((float*)b));}
static __attribute__((unused)) void g_ss_forward_ul_d(g_ss_function_ul_d_t f, void* r, const void* a, const void* b){*((short*)r) = f(*((unsigned long*)a),*((double*)b));}
static __attribute__((unused)) void g_ss_forward_f_b(g_ss_function_f_b_t f, void* r, const void* a, const void* b){*((short*)r) = f(*((float*)a),*((bool*)b));}
static __attribute__((unused)) void g_ss_forward_f_c(g_ss_function_f_c_t f, void* r, const void* a, const void* b){*((short*)r) = f(*((float*)a),*((char*)b));}
static __attribute__((unused)) void g_ss_forward_f_ss(g_ss_function_f_ss_t f, void* r, const void* a, const void* b){*((short*)r) = f(*((float*)a),*((short*)b));}
static __attribute__((unused)) void g_ss_forward_f_si(g_ss_function_f_si_t f, void* r, const void* a, const void* b){*((short*)r) = f(*((float*)a),*((int*)b));}
static __attribute__((unused)) void g_ss_forward_f_sl(g_ss_function_f_sl_t f, void* r, const void* a, const void* b){*((short*)r) = f(*((float*)a),*((long*)b));}
static __attribute__((unused)) void g_ss_forward_f_ul(g_ss_function_f_ul_t f, void* r, const void* a, const void* b){*((short*)r) = f(*((float*)a),*((unsigned long*)b));}
static __attribute__((unused)) void g_ss_forward_f_f(g_ss_function_f_f_t f, void* r, const void* a, const void* b){*((short*)r) = f(*((float*)a),*((float*)b));}
static __attribute__((unused)) void g_ss_forward_f_d(g_ss_function_f_d_t f, void* r, const void* a, const void* b){*((short*)r) = f(*((float*)a),*((double*)b));}
static __attribute__((unused)) void g_ss_forward_d_b(g_ss_function_d_b_t f, void* r, const void* a, const void* b){*((short*)r) = f(*((double*)a),*((bool*)b));}
static __attribute__((unused)) void g_ss_forward_d_c(g_ss_function_d_c_t f, void* r, const void* a, const void* b){*((short*)r) = f(*((double*)a),*((char*)b));}
static __attribute__((unused)) void g_ss_forward_d_ss(g_ss_function_d_ss_t f, void* r, const void* a, const void* b){*((short*)r) = f(*((double*)a),*((short*)b));}
static __attribute__((unused)) void g_ss_forward_d_si(g_ss_function_d_si_t f, void* r, const void* a, const void* b){*((short*)r) = f(*((double*)a),*((int*)b));}
static __attribute__((unused)) void g_ss_forward_d_sl(g_ss_function_d_sl_t f, void* r, const void* a, const void* b){*((short*)r) = f(*((double*)a),*((long*)b));}
static __attribute__((unused)) void g_ss_forward_d_ul(g_ss_function_d_ul_t f, void* r, const void* a, const void* b){*((short*)r) = f(*((double*)a),*((unsigned long*)b));}
static __attribute__((unused)) void g_ss_forward_d_f(g_ss_function_d_f_t f, void* r, const void* a, const void* b){*((short*)r) = f(*((double*)a),*((float*)b));}
static __attribute__((unused)) void g_ss_forward_d_d(g_ss_function_d_d_t f, void* r, const void* a, const void* b){*((short*)r) = f(*((double*)a),*((double*)b));}
static __attribute__((unused)) void g_si_forward_b_b(g_si_function_b_b_t f, void* r, const void* a, const void* b){*((int*)r) = f(*((bool*)a),*((bool*)b));}
static __attribute__((unused)) void g_si_forward_b_c(g_si_function_b_c_t f, void* r, const void* a, const void* b){*((int*)r) = f(*((bool*)a),*((char*)b));}
static __attribute__((unused)) void g_si_forward_b_ss(g_si_function_b_ss_t f, void* r, const void* a, const void* b){*((int*)r) = f(*((bool*)a),*((short*)b));}
static __attribute__((unused)) void g_si_forward_b_si(g_si_function_b_si_t f, void* r, const void* a, const void* b){*((int*)r) = f(*((bool*)a),*((int*)b));}
static __attribute__((unused)) void g_si_forward_b_sl(g_si_function_b_sl_t f, void* r, const void* a, const void* b){*((int*)r) = f(*((bool*)a),*((long*)b));}
static __attribute__((unused)) void g_si_forward_b_ul(g_si_function_b_ul_t f, void* r, const void* a, const void* b){*((int*)r) = f(*((bool*)a),*((unsigned long*)b));}
static __attribute__((unused)) void g_si_forward_b_f(g_si_function_b_f_t f, void* r, const void* a, const void* b){*((int*)r) = f(*((bool*)a),*((float*)b));}
static __attribute__((unused)) void g_si_forward_b_d(g_si_function_b_d_t f, void* r, const void* a, const void* b){*((int*)r) = f(*((bool*)a),*((double*)b));}
static __attribute__((unused)) void g_si_forward_c_b(g_si_function_c_b_t f, void* r, const void* a, const void* b){*((int*)r) = f(*((char*)a),*((bool*)b));}
static __attribute__((unused)) void g_si_forward_c_c(g_si_function_c_c_t f, void* r, const void* a, const void* b){*((int*)r) = f(*((char*)a),*((char*)b));}
static __attribute__((unused)) void g_si_forward_c_ss(g_si_function_c_ss_t f, void* r, const void* a, const void* b){*((int*)r) = f(*((char*)a),*((short*)b));}
static __attribute__((unused)) void g_si_forward_c_si(g_si_function_c_si_t f, void* r, const void* a, const void* b){*((int*)r) = f(*((char*)a),*((int*)b));}
static __attribute__((unused)) void g_si_forward_c_sl(g_si_function_c_sl_t f, void* r, const void* a, const void* b){*((int*)r) = f(*((char*)a),*((long*)b));}
static __attribute__((unused)) void g_si_forward_c_ul(g_si_function_c_ul_t f, void* r, const void* a, const void* b){*((int*)r) = f(*((char*)a),*((unsigned long*)b));}
static __attribute__((unused)) void g_si_forward_c_f(g_si_function_c_f_t f, void* r, const void* a, const void* b){*((int*)r) = f(*((char*)a),*((float*)b));}
static __attribute__((unused)) void g_si_forward_c_d(g_si_function_c_d_t f, void* r, const void* a, const void* b){*((int*)r) = f(*((char*)a),*((double*)b));}
static __attribute__((unused)) void g_si_forward_ss_b(g_si_function_ss_b_t f, void* r, const void* a, const void* b){*((int*)r) = f(*((short*)a),*((bool*)b));}
static __attribute__((unused)) void g_si_forward_ss_c(g_si_function_ss_c_t f, void* r, const void* a, const void* b){*((int*)r) = f(*((short*)a),*((char*)b));}
static __attribute__((unused)) void g_si_forward_ss_ss(g_si_function_ss_ss_t f, void* r, const void* a, const void* b){*((int*)r) = f(*((short*)a),*((short*)b));}
static __attribute__((unused)) void g_si_forward_ss_si(g_si_function_ss_si_t f, void* r, const void* a, const void* b){*((int*)r) = f(*((short*)a),*((int*)b));}
static __attribute__((unused)) void g_si_forward_ss_sl(g_si_function_ss_sl_t f, void* r, const void* a, const void* b){*((int*)r) = f(*((short*)a),*((long*)b));}
static __attribute__((unused)) void g_si_forward_ss_ul(g_si_function_ss_ul_t f, void* r, const void* a, const void* b){*((int*)r) = f(*((short*)a),*((unsigned long*)b));}
static __attribute__((unused)) void g_si_forward_ss_f(g_si_function_ss_f_t f, void* r, const void* a, const void* b){*((int*)r) = f(*((short*)a),*((float*)b));}
static __attribute__((unused)) void g_si_forward_ss_d(g_si_function_ss_d_t f, void* r, const void* a, const void* b){*((int*)r) = f(*((short*)a),*((double*)b));}
static __attribute__((unused)) void g_si_forward_si_b(g_si_function_si_b_t f, void* r, const void* a, const void* b){*((int*)r) = f(*((int*)a),*((bool*)b));}
static __attribute__((unused)) void g_si_forward_si_c(g_si_function_si_c_t f, void* r, const void* a, const void* b){*((int*)r) = f(*((int*)a),*((char*)b));}
static __attribute__((unused)) void g_si_forward_si_ss(g_si_function_si_ss_t f, void* r, const void* a, const void* b){*((int*)r) = f(*((int*)a),*((short*)b));}
static __attribute__((unused)) void g_si_forward_si_si(g_si_function_si_si_t f, void* r, const void* a, const void* b){*((int*)r) = f(*((int*)a),*((int*)b));}
static __attribute__((unused)) void g_si_forward_si_sl(g_si_function_si_sl_t f, void* r, const void* a, const void* b){*((int*)r) = f(*((int*)a),*((long*)b));}
static __attribute__((unused)) void g_si_forward_si_ul(g_si_function_si_ul_t f, void* r, const void* a, const void* b){*((int*)r) = f(*((int*)a),*((unsigned long*)b));}
static __attribute__((unused)) void g_si_forward_si_f(g_si_function_si_f_t f, void* r, const void* a, const void* b){*((int*)r) = f(*((int*)a),*((float*)b));}
static __attribute__((unused)) void g_si_forward_si_d(g_si_function_si_d_t f, void* r, const void* a, const void* b){*((int*)r) = f(*((int*)a),*((double*)b));}
static __attribute__((unused)) void g_si_forward_sl_b(g_si_function_sl_b_t f, void* r, const void* a, const void* b){*((int*)r) = f(*((long*)a),*((bool*)b));}
static __attribute__((unused)) void g_si_forward_sl_c(g_si_function_sl_c_t f, void* r, const void* a, const void* b){*((int*)r) = f(*((long*)a),*((char*)b));}
static __attribute__((unused)) void g_si_forward_sl_ss(g_si_function_sl_ss_t f, void* r, const void* a, const void* b){*((int*)r) = f(*((long*)a),*((short*)b));}
static __attribute__((unused)) void g_si_forward_sl_si(g_si_function_sl_si_t f, void* r, const void* a, const void* b){*((int*)r) = f(*((long*)a),*((int*)b));}
static __attribute__((unused)) void g_si_forward_sl_sl(g_si_function_sl_sl_t f, void* r, const void* a, const void* b){*((int*)r) = f(*((long*)a),*((long*)b));}
static __attribute__((unused)) void g_si_forward_sl_ul(g_si_function_sl_ul_t f, void* r, const void* a, const void* b){*((int*)r) = f(*((long*)a),*((unsigned long*)b));}
static __attribute__((unused)) void g_si_forward_sl_f(g_si_function_sl_f_t f, void* r, const void* a, const void* b){*((int*)r) = f(*((long*)a),*((float*)b));}
static __attribute__((unused)) void g_si_forward_sl_d(g_si_function_sl_d_t f, void* r, const void* a, const void* b){*((int*)r) = f(*((long*)a),*((double*)b));}
static __attribute__((unused)) void g_si_forward_ul_b(g_si_function_ul_b_t f, void* r, const void* a, const void* b){*((int*)r) = f(*((unsigned long*)a),*((bool*)b));}
static __attribute__((unused)) void g_si_forward_ul_c(g_si_function_ul_c_t f, void* r, const void* a, const void* b){*((int*)r) = f(*((unsigned long*)a),*((char*)b));}
static __attribute__((unused)) void g_si_forward_ul_ss(g_si_function_ul_ss_t f, void* r, const void* a, const void* b){*((int*)r) = f(*((unsigned long*)a),*((short*)b));}
static __attribute__((unused)) void g_si_forward_ul_si(g_si_function_ul_si_t f, void* r, const void* a, const void* b){*((int*)r) = f(*((unsigned long*)a),*((int*)b));}
static __attribute__((unused)) void g_si_forward_ul_sl(g_si_function_ul_sl_t f, void* r, const void* a, const void* b){*((int*)r) = f(*((unsigned long*)a),*((long*)b));}
static __attribute__((unused)) void g_si_forward_ul_ul(g_si_function_ul_ul_t f, void* r, const void* a, const void* b){*((int*)r) = f(*((unsigned long*)a),*((unsigned long*)b));}
static __attribute__((unused)) void g_si_forward_ul_f(g_si_function_ul_f_t f, void* r, const void* a, const void* b){*((int*)r) = f(*((unsigned long*)a),*((float*)b));}
static __attribute__((unused)) void g_si_forward_ul_d(g_si_function_ul_d_t f, void* r, const void* a, const void* b){*((int*)r) = f(*((unsigned long*)a),*((double*)b));}
static __attribute__((unused)) void g_si_forward_f_b(g_si_function_f_b_t f, void* r, const void* a, const void* b){*((int*)r) = f(*((float*)a),*((bool*)b));}
static __attribute__((unused)) void g_si_forward_f_c(g_si_function_f_c_t f, void* r, const void* a, const void* b){*((int*)r) = f(*((float*)a),*((char*)b));}
static __attribute__((unused)) void g_si_forward_f_ss(g_si_function_f_ss_t f, void* r, const void* a, const void* b){*((int*)r) = f(*((float*)a),*((short*)b));}
static __attribute__((unused)) void g_si_forward_f_si(g_si_function_f_si_t f, void* r, const void* a, const void* b){*((int*)r) = f(*((float*)a),*((int*)b));}
static __attribute__((unused)) void g_si_forward_f_sl(g_si_function_f_sl_t f, void* r, const void* a, const void* b){*((int*)r) = f(*((float*)a),*((long*)b));}
static __attribute__((unused)) void g_si_forward_f_ul(g_si_function_f_ul_t f, void* r, const void* a, const void* b){*((int*)r) = f(*((float*)a),*((unsigned long*)b));}
static __attribute__((unused)) void g_si_forward_f_f(g_si_function_f_f_t f, void* r, const void* a, const void* b){*((int*)r) = f(*((float*)a),*((float*)b));}
static __attribute__((unused)) void g_si_forward_f_d(g_si_function_f_d_t f, void* r, const void* a, const void* b){*((int*)r) = f(*((float*)a),*((double*)b));}
static __attribute__((unused)) void g_si_forward_d_b(g_si_function_d_b_t f, void* r, const void* a, const void* b){*((int*)r) = f(*((double*)a),*((bool*)b));}
static __attribute__((unused)) void g_si_forward_d_c(g_si_function_d_c_t f, void* r, const void* a, const void* b){*((int*)r) = f(*((double*)a),*((char*)b));}
static __attribute__((unused)) void g_si_forward_d_ss(g_si_function_d_ss_t f, void* r, const void* a, const void* b){*((int*)r) = f(*((double*)a),*((short*)b));}
static __attribute__((unused)) void g_si_forward_d_si(g_si_function_d_si_t f, void* r, const void* a, const void* b){*((int*)r) = f(*((double*)a),*((int*)b));}
static __attribute__((unused)) void g_si_forward_d_sl(g_si_function_d_sl_t f, void* r, const void* a, const void* b){*((int*)r) = f(*((double*)a),*((long*)b));}
static __attribute__((unused)) void g_si_forward_d_ul(g_si_function_d_ul_t f, void* r, const void* a, const void* b){*((int*)r) = f(*((double*)a),*((unsigned long*)b));}
static __attribute__((unused)) void g_si_forward_d_f(g_si_function_d_f_t f, void* r, const void* a, const void* b){*((int*)r) = f(*((double*)a),*((float*)b));}
static __attribute__((unused)) void g_si_forward_d_d(g_si_function_d_d_t f, void* r, const void* a, const void* b){*((int*)r) = f(*((double*)a),*((double*)b));}
static __attribute__((unused)) void g_sl_forward_b_b(g_sl_function_b_b_t f, void* r, const void* a, const void* b){*((long*)r) = f(*((bool*)a),*((bool*)b));}
static __attribute__((unused)) void g_sl_forward_b_c(g_sl_function_b_c_t f, void* r, const void* a, const void* b){*((long*)r) = f(*((bool*)a),*((char*)b));}
static __attribute__((unused)) void g_sl_forward_b_ss(g_sl_function_b_ss_t f, void* r, const void* a, const void* b){*((long*)r) = f(*((bool*)a),*((short*)b));}
static __attribute__((unused)) void g_sl_forward_b_si(g_sl_function_b_si_t f, void* r, const void* a, const void* b){*((long*)r) = f(*((bool*)a),*((int*)b));}
static __attribute__((unused)) void g_sl_forward_b_sl(g_sl_function_b_sl_t f, void* r, const void* a, const void* b){*((long*)r) = f(*((bool*)a),*((long*)b));}
static __attribute__((unused)) void g_sl_forward_b_ul(g_sl_function_b_ul_t f, void* r, const void* a, const void* b){*((long*)r) = f(*((bool*)a),*((unsigned long*)b));}
static __attribute__((unused)) void g_sl_forward_b_f(g_sl_function_b_f_t f, void* r, const void* a, const void* b){*((long*)r) = f(*((bool*)a),*((float*)b));}
static __attribute__((unused)) void g_sl_forward_b_d(g_sl_function_b_d_t f, void* r, const void* a, const void* b){*((long*)r) = f(*((bool*)a),*((double*)b));}
static __attribute__((unused)) void g_sl_forward_c_b(g_sl_function_c_b_t f, void* r, const void* a, const void* b){*((long*)r) = f(*((char*)a),*((bool*)b));}
static __attribute__((unused)) void g_sl_forward_c_c(g_sl_function_c_c_t f, void* r, const void* a, const void* b){*((long*)r) = f(*((char*)a),*((char*)b));}
static __attribute__((unused)) void g_sl_forward_c_ss(g_sl_function_c_ss_t f, void* r, const void* a, const void* b){*((long*)r) = f(*((char*)a),*((short*)b));}
static __attribute__((unused)) void g_sl_forward_c_si(g_sl_function_c_si_t f, void* r, const void* a, const void* b){*((long*)r) = f(*((char*)a),*((int*)b));}
static __attribute__((unused)) void g_sl_forward_c_sl(g_sl_function_c_sl_t f, void* r, const void* a, const void* b){*((long*)r) = f(*((char*)a),*((long*)b));}
static __attribute__((unused)) void g_sl_forward_c_ul(g_sl_function_c_ul_t f, void* r, const void* a, const void* b){*((long*)r) = f(*((char*)a),*((unsigned long*)b));}
static __attribute__((unused)) void g_sl_forward_c_f(g_sl_function_c_f_t f, void* r, const void* a, const void* b){*((long*)r) = f(*((char*)a),*((float*)b));}
static __attribute__((unused)) void g_sl_forward_c_d(g_sl_function_c_d_t f, void* r, const void* a, const void* b){*((long*)r) = f(*((char*)a),*((double*)b));}
static __attribute__((unused)) void g_sl_forward_ss_b(g_sl_function_ss_b_t f, void* r, const void* a, const void* b){*((long*)r) = f(*((short*)a),*((bool*)b));}
static __attribute__((unused)) void g_sl_forward_ss_c(g_sl_function_ss_c_t f, void* r, const void* a, const void* b){*((long*)r) = f(*((short*)a),*((char*)b));}
static __attribute__((unused)) void g_sl_forward_ss_ss(g_sl_function_ss_ss_t f, void* r, const void* a, const void* b){*((long*)r) = f(*((short*)a),*((short*)b));}
static __attribute__((unused)) void g_sl_forward_ss_si(g_sl_function_ss_si_t f, void* r, const void* a, const void* b){*((long*)r) = f(*((short*)a),*((int*)b));}
static __attribute__((unused)) void g_sl_forward_ss_sl(g_sl_function_ss_sl_t f, void* r, const void* a, const void* b){*((long*)r) = f(*((short*)a),*((long*)b));}
static __attribute__((unused)) void g_sl_forward_ss_ul(g_sl_function_ss_ul_t f, void* r, const void* a, const void* b){*((long*)r) = f(*((short*)a),*((unsigned long*)b));}
static __attribute__((unused)) void g_sl_forward_ss_f(g_sl_function_ss_f_t f, void* r, const void* a, const void* b){*((long*)r) = f(*((short*)a),*((float*)b));}
static __attribute__((unused)) void g_sl_forward_ss_d(g_sl_function_ss_d_t f, void* r, const void* a, const void* b){*((long*)r) = f(*((short*)a),*((double*)b));}
static __attribute__((unused)) void g_sl_forward_si_b(g_sl_function_si_b_t f, void* r, const void* a, const void* b){*((long*)r) = f(*((int*)a),*((bool*)b));}
static __attribute__((unused)) void g_sl_forward_si_c(g_sl_function_si_c_t f, void* r, const void* a, const void* b){*((long*)r) = f(*((int*)a),*((char*)b));}
static __attribute__((unused)) void g_sl_forward_si_ss(g_sl_function_si_ss_t f, void* r, const void* a, const void* b){*((long*)r) = f(*((int*)a),*((short*)b));}
static __attribute__((unused)) void g_sl_forward_si_si(g_sl_function_si_si_t f, void* r, const void* a, const void* b){*((long*)r) = f(*((int*)a),*((int*)b));}
static __attribute__((unused)) void g_sl_forward_si_sl(g_sl_function_si_sl_t f, void* r, const void* a, const void* b){*((long*)r) = f(*((int*)a),*((long*)b));}
static __attribute__((unused)) void g_sl_forward_si_ul(g_sl_function_si_ul_t f, void* r, const void* a, const void* b){*((long*)r) = f(*((int*)a),*((unsigned long*)b));}
static __attribute__((unused)) void g_sl_forward_si_f(g_sl_function_si_f_t f, void* r, const void* a, const void* b){*((long*)r) = f(*((int*)a),*((float*)b));}
static __attribute__((unused)) void g_sl_forward_si_d(g_sl_function_si_d_t f, void* r, const void* a, const void* b){*((long*)r) = f(*((int*)a),*((double*)b));}
static __attribute__((unused)) void g_sl_forward_sl_b(g_sl_function_sl_b_t f, void* r, const void* a, const void* b){*((long*)r) = f(*((long*)a),*((bool*)b));}
static __attribute__((unused)) void g_sl_forward_sl_c(g_sl_function_sl_c_t f, void* r, const void* a, const void* b){*((long*)r) = f(*((long*)a),*((char*)b));}
static __attribute__((unused)) void g_sl_forward_sl_ss(g_sl_function_sl_ss_t f, void* r, const void* a, const void* b){*((long*)r) = f(*((long*)a),*((short*)b));}
static __attribute__((unused)) void g_sl_forward_sl_si(g_sl_function_sl_si_t f, void* r, const void* a, const void* b){*((long*)r) = f(*((long*)a),*((int*)b));}
static __attribute__((unused)) void g_sl_forward_sl_sl(g_sl_function_sl_sl_t f, void* r, const void* a, const void* b){*((long*)r) = f(*((long*)a),*((long*)b));}
static __attribute__((unused)) void g_sl_forward_sl_ul(g_sl_function_sl_ul_t f, void* r, const void* a, const void* b){*((long*)r) = f(*((long*)a),*((unsigned long*)b));}
static __attribute__((unused)) void g_sl_forward_sl_f(g_sl_function_sl_f_t f, void* r, const void* a, const void* b){*((long*)r) = f(*((long*)a),*((float*)b));}
static __attribute__((unused)) void g_sl_forward_sl_d(g_sl_function_sl_d_t f, void* r, const void* a, const void* b){*((long*)r) = f(*((long*)a),*((double*)b));}
static __attribute__((unused)) void g_sl_forward_ul_b(g_sl_function_ul_b_t f, void* r, const void* a, const void* b){*((long*)r) = f(*((unsigned long*)a),*((bool*)b));}
static __attribute__((unused)) void g_sl_forward_ul_c(g_sl_function_ul_c_t f, void* r, const void* a, const void* b){*((long*)r) = f(*((unsigned long*)a),*((char*)b));}
static __attribute__((unused)) void g_sl_forward_ul_ss(g_sl_function_ul_ss_t f, void* r, const void* a, const void* b){*((long*)r) = f(*((unsigned long*)a),*((short*)b));}
static __attribute__((unused)) void g_sl_forward_ul_si(g_sl_function_ul_si_t f, void* r, const void* a, const void* b){*((long*)r) = f(*((unsigned long*)a),*((int*)b));}
static __attribute__((unused)) void g_sl_forward_ul_sl(g_sl_function_ul_sl_t f, void* r, const void* a, const void* b){*((long*)r) = f(*((unsigned long*)a),*((long*)b));}
static __attribute__((unused)) void g_sl_forward_ul_ul(g_sl_function_ul_ul_t f, void* r, const void* a, const void* b){*((long*)r) = f(*((unsigned long*)a),*((unsigned long*)b));}
static __attribute__((unused)) void g_sl_forward_ul_f(g_sl_function_ul_f_t f, void* r, const void* a, const void* b){*((long*)r) = f(*((unsigned long*)a),*((float*)b));}
static __attribute__((unused)) void g_sl_forward_ul_d(g_sl_function_ul_d_t f, void* r, const void* a, const void* b){*((long*)r) = f(*((unsigned long*)a),*((double*)b));}
static __attribute__((unused)) void g_sl_forward_f_b(g_sl_function_f_b_t f, void* r, const void* a, const void* b){*((long*)r) = f(*((float*)a),*((bool*)b));}
static __attribute__((unused)) void g_sl_forward_f_c(g_sl_function_f_c_t f, void* r, const void* a, const void* b){*((long*)r) = f(*((float*)a),*((char*)b));}
static __attribute__((unused)) void g_sl_forward_f_ss(g_sl_function_f_ss_t f, void* r, const void* a, const void* b){*((long*)r) = f(*((float*)a),*((short*)b));}
static __attribute__((unused)) void g_sl_forward_f_si(g_sl_function_f_si_t f, void* r, const void* a, const void* b){*((long*)r) = f(*((float*)a),*((int*)b));}
static __attribute__((unused)) void g_sl_forward_f_sl(g_sl_function_f_sl_t f, void* r, const void* a, const void* b){*((long*)r) = f(*((float*)a),*((long*)b));}
static __attribute__((unused)) void g_sl_forward_f_ul(g_sl_function_f_ul_t f, void* r, const void* a, const void* b){*((long*)r) = f(*((float*)a),*((unsigned long*)b));}
static __attribute__((unused)) void g_sl_forward_f_f(g_sl_function_f_f_t f, void* r, const void* a, const void* b){*((long*)r) = f(*((float*)a),*((float*)b));}
static __attribute__((unused)) void g_sl_forward_f_d(g_sl_function_f_d_t f, void* r, const void* a, const void* b){*((long*)r) = f(*((float*)a),*((double*)b));}
static __attribute__((unused)) void g_sl_forward_d_b(g_sl_function_d_b_t f, void* r, const void* a, const void* b){*((long*)r) = f(*((double*)a),*((bool*)b));}
static __attribute__((unused)) void g_sl_forward_d_c(g_sl_function_d_c_t f, void* r, const void* a, const void* b){*((long*)r) = f(*((double*)a),*((char*)b));}
static __attribute__((unused)) void g_sl_forward_d_ss(g_sl_function_d_ss_t f, void* r, const void* a, const void* b){*((long*)r) = f(*((double*)a),*((short*)b));}
static __attribute__((unused)) void g_sl_forward_d_si(g_sl_function_d_si_t f, void* r, const void* a, const void* b){*((long*)r) = f(*((double*)a),*((int*)b));}
static __attribute__((unused)) void g_sl_forward_d_sl(g_sl_function_d_sl_t f, void* r, const void* a, const void* b){*((long*)r) = f(*((double*)a),*((long*)b));}
static __attribute__((unused)) void g_sl_forward_d_ul(g_sl_function_d_ul_t f, void* r, const void* a, const void* b){*((long*)r) = f(*((double*)a),*((unsigned long*)b));}
static __attribute__((unused)) void g_sl_forward_d_f(g_sl_function_d_f_t f, void* r, const void* a, const void* b){*((long*)r) = f(*((double*)a),*((float*)b));}
static __attribute__((unused)) void g_sl_forward_d_d(g_sl_function_d_d_t f, void* r, const void* a, const void* b){*((long*)r) = f(*((double*)a),*((double*)b));}
static __attribute__((unused)) void g_ul_forward_b_b(g_ul_function_b_b_t f, void* r, const void* a, const void* b){*((unsigned long*)r) = f(*((bool*)a),*((bool*)b));}
static __attribute__((unused)) void g_ul_forward_b_c(g_ul_function_b_c_t f, void* r, const void* a, const void* b){*((unsigned long*)r) = f(*((bool*)a),*((char*)b));}
static __attribute__((unused)) void g_ul_forward_b_ss(g_ul_function_b_ss_t f, void* r, const void* a, const void* b){*((unsigned long*)r) = f(*((bool*)a),*((short*)b));}
static __attribute__((unused)) void g_ul_forward_b_si(g_ul_function_b_si_t f, void* r, const void* a, const void* b){*((unsigned long*)r) = f(*((bool*)a),*((int*)b));}
static __attribute__((unused)) void g_ul_forward_b_sl(g_ul_function_b_sl_t f, void* r, const void* a, const void* b){*((unsigned long*)r) = f(*((bool*)a),*((long*)b));}
static __attribute__((unused)) void g_ul_forward_b_ul(g_ul_function_b_ul_t f, void* r, const void* a, const void* b){*((unsigned long*)r) = f(*((bool*)a),*((unsigned long*)b));}
static __attribute__((unused)) void g_ul_forward_b_f(g_ul_function_b_f_t f, void* r, const void* a, const void* b){*((unsigned long*)r) = f(*((bool*)a),*((float*)b));}
static __attribute__((unused)) void g_ul_forward_b_d(g_ul_function_b_d_t f, void* r, const void* a, const void* b){*((unsigned long*)r) = f(*((bool*)a),*((double*)b));}
static __attribute__((unused)) void g_ul_forward_c_b(g_ul_function_c_b_t f, void* r, const void* a, const void* b){*((unsigned long*)r) = f(*((char*)a),*((bool*)b));}
static __attribute__((unused)) void g_ul_forward_c_c(g_ul_function_c_c_t f, void* r, const void* a, const void* b){*((unsigned long*)r) = f(*((char*)a),*((char*)b));}
static __attribute__((unused)) void g_ul_forward_c_ss(g_ul_function_c_ss_t f, void* r, const void* a, const void* b){*((unsigned long*)r) = f(*((char*)a),*((short*)b));}
static __attribute__((unused)) void g_ul_forward_c_si(g_ul_function_c_si_t f, void* r, const void* a, const void* b){*((unsigned long*)r) = f(*((char*)a),*((int*)b));}
static __attribute__((unused)) void g_ul_forward_c_sl(g_ul_function_c_sl_t f, void* r, const void* a, const void* b){*((unsigned long*)r) = f(*((char*)a),*((long*)b));}
static __attribute__((unused)) void g_ul_forward_c_ul(g_ul_function_c_ul_t f, void* r, const void* a, const void* b){*((unsigned long*)r) = f(*((char*)a),*((unsigned long*)b));}
static __attribute__((unused)) void g_ul_forward_c_f(g_ul_function_c_f_t f, void* r, const void* a, const void* b){*((unsigned long*)r) = f(*((char*)a),*((float*)b));}
static __attribute__((unused)) void g_ul_forward_c_d(g_ul_function_c_d_t f, void* r, const void* a, const void* b){*((unsigned long*)r) = f(*((char*)a),*((double*)b));}
static __attribute__((unused)) void g_ul_forward_ss_b(g_ul_function_ss_b_t f, void* r, const void* a, const void* b){*((unsigned long*)r) = f(*((short*)a),*((bool*)b));}
static __attribute__((unused)) void g_ul_forward_ss_c(g_ul_function_ss_c_t f, void* r, const void* a, const void* b){*((unsigned long*)r) = f(*((short*)a),*((char*)b));}
static __attribute__((unused)) void g_ul_forward_ss_ss(g_ul_function_ss_ss_t f, void* r, const void* a, const void* b){*((unsigned long*)r) = f(*((short*)a),*((short*)b));}
static __attribute__((unused)) void g_ul_forward_ss_si(g_ul_function_ss_si_t f, void* r, const void* a, const void* b){*((unsigned long*)r) = f(*((short*)a),*((int*)b));}
static __attribute__((unused)) void g_ul_forward_ss_sl(g_ul_function_ss_sl_t f, void* r, const void* a, const void* b){*((unsigned long*)r) = f(*((short*)a),*((long*)b));}
static __attribute__((unused)) void g_ul_forward_ss_ul(g_ul_function_ss_ul_t f, void* r, const void* a, const void* b){*((unsigned long*)r) = f(*((short*)a),*((unsigned long*)b));}
static __attribute__((unused)) void g_ul_forward_ss_f(g_ul_function_ss_f_t f, void* r, const void* a, const void* b){*((unsigned long*)r) = f(*((short*)a),*((float*)b));}
static __attribute__((unused)) void g_ul_forward_ss_d(g_ul_function_ss_d_t f, void* r, const void* a, const void* b){*((unsigned long*)r) = f(*((short*)a),*((double*)b));}
static __attribute__((unused)) void g_ul_forward_si_b(g_ul_function_si_b_t f, void* r, const void* a, const void* b){*((unsigned long*)r) = f(*((int*)a),*((bool*)b));}
static __attribute__((unused)) void g_ul_forward_si_c(g_ul_function_si_c_t f, void* r, const void* a, const void* b){*((unsigned long*)r) = f(*((int*)a),*((char*)b));}
static __attribute__((unused)) void g_ul_forward_si_ss(g_ul_function_si_ss_t f, void* r, const void* a, const void* b){*((unsigned long*)r) = f(*((int*)a),*((short*)b));}
static __attribute__((unused)) void g_ul_forward_si_si(g_ul_function_si_si_t f, void* r, const void* a, const void* b){*((unsigned long*)r) = f(*((int*)a),*((int*)b));}
static __attribute__((unused)) void g_ul_forward_si_sl(g_ul_function_si_sl_t f, void* r, const void* a, const void* b){*((unsigned long*)r) = f(*((int*)a),*((long*)b));}
static __attribute__((unused)) void g_ul_forward_si_ul(g_ul_function_si_ul_t f, void* r, const void* a, const void* b){*((unsigned long*)r) = f(*((int*)a),*((unsigned long*)b));}
static __attribute__((unused)) void g_ul_forward_si_f(g_ul_function_si_f_t f, void* r, const void* a, const void* b){*((unsigned long*)r) = f(*((int*)a),*((float*)b));}
static __attribute__((unused)) void g_ul_forward_si_d(g_ul_function_si_d_t f, void* r, const void* a, const void* b){*((unsigned long*)r) = f(*((int*)a),*((double*)b));}
static __attribute__((unused)) void g_ul_forward_sl_b(g_ul_function_sl_b_t f, void* r, const void* a, const void* b){*((unsigned long*)r) = f(*((long*)a),*((bool*)b));}
static __attribute__((unused)) void g_ul_forward_sl_c(g_ul_function_sl_c_t f, void* r, const void* a, const void* b){*((unsigned long*)r) = f(*((long*)a),*((char*)b));}
static __attribute__((unused)) void g_ul_forward_sl_ss(g_ul_function_sl_ss_t f, void* r, const void* a, const void* b){*((unsigned long*)r) = f(*((long*)a),*((short*)b));}
static __attribute__((unused)) void g_ul_forward_sl_si(g_ul_function_sl_si_t f, void* r, const void* a, const void* b){*((unsigned long*)r) = f(*((long*)a),*((int*)b));}
static __attribute__((unused)) void g_ul_forward_sl_sl(g_ul_function_sl_sl_t f, void* r, const void* a, const void* b){*((unsigned long*)r) = f(*((long*)a),*((long*)b));}
static __attribute__((unused)) void g_ul_forward_sl_ul(g_ul_function_sl_ul_t f, void* r, const void* a, const void* b){*((unsigned long*)r) = f(*((long*)a),*((unsigned long*)b));}
static __attribute__((unused)) void g_ul_forward_sl_f(g_ul_function_sl_f_t f, void* r, const void* a, const void* b){*((unsigned long*)r) = f(*((long*)a),*((float*)b));}
static __attribute__((unused)) void g_ul_forward_sl_d(g_ul_function_sl_d_t f, void* r, const void* a, const void* b){*((unsigned long*)r) = f(*((long*)a),*((double*)b));}
static __attribute__((unused)) void g_ul_forward_ul_b(g_ul_function_ul_b_t f, void* r, const void* a, const void* b){*((unsigned long*)r) = f(*((unsigned long*)a),*((bool*)b));}
static __attribute__((unused)) void g_ul_forward_ul_c(g_ul_function_ul_c_t f, void* r, const void* a, const void* b){*((unsigned long*)r) = f(*((unsigned long*)a),*((char*)b));}
static __attribute__((unused)) void g_ul_forward_ul_ss(g_ul_function_ul_ss_t f, void* r, const void* a, const void* b){*((unsigned long*)r) = f(*((unsigned long*)a),*((short*)b));}
static __attribute__((unused)) void g_ul_forward_ul_si(g_ul_function_ul_si_t f, void* r, const void* a, const void* b){*((unsigned long*)r) = f(*((unsigned long*)a),*((int*)b));}
static __attribute__((unused)) void g_ul_forward_ul_sl(g_ul_function_ul_sl_t f, void* r, const void* a, const void* b){*((unsigned long*)r) = f(*((unsigned long*)a),*((long*)b));}
static __attribute__((unused)) void g_ul_forward_ul_ul(g_ul_function_ul_ul_t f, void* r, const void* a, const void* b){*((unsigned long*)r) = f(*((unsigned long*)a),*((unsigned long*)b));}
static __attribute__((unused)) void g_ul_forward_ul_f(g_ul_function_ul_f_t f, void* r, const void* a, const void* b){*((unsigned long*)r) = f(*((unsigned long*)a),*((float*)b));}
static __attribute__((unused)) void g_ul_forward_ul_d(g_ul_function_ul_d_t f, void* r, const void* a, const void* b){*((unsigned long*)r) = f(*((unsigned long*)a),*((double*)b));}
static __attribute__((unused)) void g_ul_forward_f_b(g_ul_function_f_b_t f, void* r, const void* a, const void* b){*((unsigned long*)r) = f(*((float*)a),*((bool*)b));}
static __attribute__((unused)) void g_ul_forward_f_c(g_ul_function_f_c_t f, void* r, const void* a, const void* b){*((unsigned long*)r) = f(*((float*)a),*((char*)b));}
static __attribute__((unused)) void g_ul_forward_f_ss(g_ul_function_f_ss_t f, void* r, const void* a, const void* b){*((unsigned long*)r) = f(*((float*)a),*((short*)b));}
static __attribute__((unused)) void g_ul_forward_f_si(g_ul_function_f_si_t f, void* r, const void* a, const void* b){*((unsigned long*)r) = f(*((float*)a),*((int*)b));}
static __attribute__((unused)) void g_ul_forward_f_sl(g_ul_function_f_sl_t f, void* r, const void* a, const void* b){*((unsigned long*)r) = f(*((float*)a),*((long*)b));}
static __attribute__((unused)) void g_ul_forward_f_ul(g_ul_function_f_ul_t f, void* r, const void* a, const void* b){*((unsigned long*)r) = f(*((float*)a),*((unsigned long*)b));}
static __attribute__((unused)) void g_ul_forward_f_f(g_ul_function_f_f_t f, void* r, const void* a, const void* b){*((unsigned long*)r) = f(*((float*)a),*((float*)b));}
static __attribute__((unused)) void g_ul_forward_f_d(g_ul_function_f_d_t f, void* r, const void* a, const void* b){*((unsigned long*)r) = f(*((float*)a),*((double*)b));}
static __attribute__((unused)) void g_ul_forward_d_b(g_ul_function_d_b_t f, void* r, const void* a, const void* b){*((unsigned long*)r) = f(*((double*)a),*((bool*)b));}
static __attribute__((unused)) void g_ul_forward_d_c(g_ul_function_d_c_t f, void* r, const void* a, const void* b){*((unsigned long*)r) = f(*((double*)a),*((char*)b));}
static __attribute__((unused)) void g_ul_forward_d_ss(g_ul_function_d_ss_t f, void* r, const void* a, const void* b){*((unsigned long*)r) = f(*((double*)a),*((short*)b));}
static __attribute__((unused)) void g_ul_forward_d_si(g_ul_function_d_si_t f, void* r, const void* a, const void* b){*((unsigned long*)r) = f(*((double*)a),*((int*)b));}
static __attribute__((unused)) void g_ul_forward_d_sl(g_ul_function_d_sl_t f, void* r, const void* a, const void* b){*((unsigned long*)r) = f(*((double*)a),*((long*)b));}
static __attribute__((unused)) void g_ul_forward_d_ul(g_ul_function_d_ul_t f, void* r, const void* a, const void* b){*((unsigned long*)r) = f(*((double*)a),*((unsigned long*)b));}
static __attribute__((unused)) void g_ul_forward_d_f(g_ul_function_d_f_t f, void* r, const void* a, const void* b){*((unsigned long*)r) = f(*((double*)a),*((float*)b));}
static __attribute__((unused)) void g_ul_forward_d_d(g_ul_function_d_d_t f, void* r, const void* a, const void* b){*((unsigned long*)r) = f(*((double*)a),*((double*)b));}
static __attribute__((unused)) void g_f_forward_b_b(g_f_function_b_b_t f, void* r, const void* a, const void* b){*((float*)r) = f(*((bool*)a),*((bool*)b));}
static __attribute__((unused)) void g_f_forward_b_c(g_f_function_b_c_t f, void* r, const void* a, const void* b){*((float*)r) = f(*((bool*)a),*((char*)b));}
static __attribute__((unused)) void g_f_forward_b_ss(g_f_function_b_ss_t f, void* r, const void* a, const void* b){*((float*)r) = f(*((bool*)a),*((short*)b));}
static __attribute__((unused)) void g_f_forward_b_si(g_f_function_b_si_t f, void* r, const void* a, const void* b){*((float*)r) = f(*((bool*)a),*((int*)b));}
static __attribute__((unused)) void g_f_forward_b_sl(g_f_function_b_sl_t f, void* r, const void* a, const void* b){*((float*)r) = f(*((bool*)a),*((long*)b));}
static __attribute__((unused)) void g_f_forward_b_ul(g_f_function_b_ul_t f, void* r, const void* a, const void* b){*((float*)r) = f(*((bool*)a),*((unsigned long*)b));}
static __attribute__((unused)) void g_f_forward_b_f(g_f_function_b_f_t f, void* r, const void* a, const void* b){*((float*)r) = f(*((bool*)a),*((float*)b));}
static __attribute__((unused)) void g_f_forward_b_d(g_f_function_b_d_t f, void* r, const void* a, const void* b){*((float*)r) = f(*((bool*)a),*((double*)b));}
static __attribute__((unused)) void g_f_forward_c_b(g_f_function_c_b_t f, void* r, const void* a, const void* b){*((float*)r) = f(*((char*)a),*((bool*)b));}
static __attribute__((unused)) void g_f_forward_c_c(g_f_function_c_c_t f, void* r, const void* a, const void* b){*((float*)r) = f(*((char*)a),*((char*)b));}
static __attribute__((unused)) void g_f_forward_c_ss(g_f_function_c_ss_t f, void* r, const void* a, const void* b){*((float*)r) = f(*((char*)a),*((short*)b));}
static __attribute__((unused)) void g_f_forward_c_si(g_f_function_c_si_t f, void* r, const void* a, const void* b){*((float*)r) = f(*((char*)a),*((int*)b));}
static __attribute__((unused)) void g_f_forward_c_sl(g_f_function_c_sl_t f, void* r, const void* a, const void* b){*((float*)r) = f(*((char*)a),*((long*)b));}
static __attribute__((unused)) void g_f_forward_c_ul(g_f_function_c_ul_t f, void* r, const void* a, const void* b){*((float*)r) = f(*((char*)a),*((unsigned long*)b));}
static __attribute__((unused)) void g_f_forward_c_f(g_f_function_c_f_t f, void* r, const void* a, const void* b){*((float*)r) = f(*((char*)a),*((float*)b));}
static __attribute__((unused)) void g_f_forward_c_d(g_f_function_c_d_t f, void* r, const void* a, const void* b){*((float*)r) = f(*((char*)a),*((double*)b));}
static __attribute__((unused)) void g_f_forward_ss_b(g_f_function_ss_b_t f, void* r, const void* a, const void* b){*((float*)r) = f(*((short*)a),*((bool*)b));}
static __attribute__((unused)) void g_f_forward_ss_c(g_f_function_ss_c_t f, void* r, const void* a, const void* b){*((float*)r) = f(*((short*)a),*((char*)b));}
static __attribute__((unused)) void g_f_forward_ss_ss(g_f_function_ss_ss_t f, void* r, const void* a, const void* b){*((float*)r) = f(*((short*)a),*((short*)b));}
static __attribute__((unused)) void g_f_forward_ss_si(g_f_function_ss_si_t f, void* r, const void* a, const void* b){*((float*)r) = f(*((short*)a),*((int*)b));}
static __attribute__((unused)) void g_f_forward_ss_sl(g_f_function_ss_sl_t f, void* r, const void* a, const void* b){*((float*)r) = f(*((short*)a),*((long*)b));}
static __attribute__((unused)) void g_f_forward_ss_ul(g_f_function_ss_ul_t f, void* r, const void* a, const void* b){*((float*)r) = f(*((short*)a),*((unsigned long*)b));}
static __attribute__((unused)) void g_f_forward_ss_f(g_f_function_ss_f_t f, void* r, const void* a, const void* b){*((float*)r) = f(*((short*)a),*((float*)b));}
static __attribute__((unused)) void g_f_forward_ss_d(g_f_function_ss_d_t f, void* r, const void* a, const void* b){*((float*)r) = f(*((short*)a),*((double*)b));}
static __attribute__((unused)) void g_f_forward_si_b(g_f_function_si_b_t f, void* r, const void* a, const void* b){*((float*)r) = f(*((int*)a),*((bool*)b));}
static __attribute__((unused)) void g_f_forward_si_c(g_f_function_si_c_t f, void* r, const void* a, const void* b){*((float*)r) = f(*((int*)a),*((char*)b));}
static __attribute__((unused)) void g_f_forward_si_ss(g_f_function_si_ss_t f, void* r, const void* a, const void* b){*((float*)r) = f(*((int*)a),*((short*)b));}
static __attribute__((unused)) void g_f_forward_si_si(g_f_function_si_si_t f, void* r, const void* a, const void* b){*((float*)r) = f(*((int*)a),*((int*)b));}
static __attribute__((unused)) void g_f_forward_si_sl(g_f_function_si_sl_t f, void* r, const void* a, const void* b){*((float*)r) = f(*((int*)a),*((long*)b));}
static __attribute__((unused)) void g_f_forward_si_ul(g_f_function_si_ul_t f, void* r, const void* a, const void* b){*((float*)r) = f(*((int*)a),*((unsigned long*)b));}
static __attribute__((unused)) void g_f_forward_si_f(g_f_function_si_f_t f, void* r, const void* a, const void* b){*((float*)r) = f(*((int*)a),*((float*)b));}
static __attribute__((unused)) void g_f_forward_si_d(g_f_function_si_d_t f, void* r, const void* a, const void* b){*((float*)r) = f(*((int*)a),*((double*)b));}
static __attribute__((unused)) void g_f_forward_sl_b(g_f_function_sl_b_t f, void* r, const void* a, const void* b){*((float*)r) = f(*((long*)a),*((bool*)b));}
static __attribute__((unused)) void g_f_forward_sl_c(g_f_function_sl_c_t f, void* r, const void* a, const void* b){*((float*)r) = f(*((long*)a),*((char*)b));}
static __attribute__((unused)) void g_f_forward_sl_ss(g_f_function_sl_ss_t f, void* r, const void* a, const void* b){*((float*)r) = f(*((long*)a),*((short*)b));}
static __attribute__((unused)) void g_f_forward_sl_si(g_f_function_sl_si_t f, void* r, const void* a, const void* b){*((float*)r) = f(*((long*)a),*((int*)b));}
static __attribute__((unused)) void g_f_forward_sl_sl(g_f_function_sl_sl_t f, void* r, const void* a, const void* b){*((float*)r) = f(*((long*)a),*((long*)b));}
static __attribute__((unused)) void g_f_forward_sl_ul(g_f_function_sl_ul_t f, void* r, const void* a, const void* b){*((float*)r) = f(*((long*)a),*((unsigned long*)b));}
static __attribute__((unused)) void g_f_forward_sl_f(g_f_function_sl_f_t f, void* r, const void* a, const void* b){*((float*)r) = f(*((long*)a),*((float*)b));}
static __attribute__((unused)) void g_f_forward_sl_d(g_f_function_sl_d_t f, void* r, const void* a, const void* b){*((float*)r) = f(*((long*)a),*((double*)b));}
static __attribute__((unused)) void g_f_forward_ul_b(g_f_function_ul_b_t f, void* r, const void* a, const void* b){*((float*)r) = f(*((unsigned long*)a),*((bool*)b));}
static __attribute__((unused)) void g_f_forward_ul_c(g_f_function_ul_c_t f, void* r, const void* a, const void* b){*((float*)r) = f(*((unsigned long*)a),*((char*)b));}
static __attribute__((unused)) void g_f_forward_ul_ss(g_f_function_ul_ss_t f, void* r, const void* a, const void* b){*((float*)r) = f(*((unsigned long*)a),*((short*)b));}
static __attribute__((unused)) void g_f_forward_ul_si(g_f_function_ul_si_t f, void* r, const void* a, const void* b){*((float*)r) = f(*((unsigned long*)a),*((int*)b));}
static __attribute__((unused)) void g_f_forward_ul_sl(g_f_function_ul_sl_t f, void* r, const void* a, const void* b){*((float*)r) = f(*((unsigned long*)a),*((long*)b));}
static __attribute__((unused)) void g_f_forward_ul_ul(g_f_function_ul_ul_t f, void* r, const void* a, const void* b){*((float*)r) = f(*((unsigned long*)a),*((unsigned long*)b));}
static __attribute__((unused)) void g_f_forward_ul_f(g_f_function_ul_f_t f, void* r, const void* a, const void* b){*((float*)r) = f(*((unsigned long*)a),*((float*)b));}
static __attribute__((unused)) void g_f_forward_ul_d(g_f_function_ul_d_t f, void* r, const void* a, const void* b){*((float*)r) = f(*((unsigned long*)a),*((double*)b));}
static __attribute__((unused)) void g_f_forward_f_b(g_f_function_f_b_t f, void* r, const void* a, const void* b){*((float*)r) = f(*((float*)a),*((bool*)b));}
static __attribute__((unused)) void g_f_forward_f_c(g_f_function_f_c_t f, void* r, const void* a, const void* b){*((float*)r) = f(*((float*)a),*((char*)b));}
static __attribute__((unused)) void g_f_forward_f_ss(g_f_function_f_ss_t f, void* r, const void* a, const void* b){*((float*)r) = f(*((float*)a),*((short*)b));}
static __attribute__((unused)) void g_f_forward_f_si(g_f_function_f_si_t f, void* r, const void* a, const void* b){*((float*)r) = f(*((float*)a),*((int*)b));}
static __attribute__((unused)) void g_f_forward_f_sl(g_f_function_f_sl_t f, void* r, const void* a, const void* b){*((float*)r) = f(*((float*)a),*((long*)b));}
static __attribute__((unused)) void g_f_forward_f_ul(g_f_function_f_ul_t f, void* r, const void* a, const void* b){*((float*)r) = f(*((float*)a),*((unsigned long*)b));}
static __attribute__((unused)) void g_f_forward_f_f(g_f_function_f_f_t f, void* r, const void* a, const void* b){*((float*)r) = f(*((float*)a),*((float*)b));}
static __attribute__((unused)) void g_f_forward_f_d(g_f_function_f_d_t f, void* r, const void* a, const void* b){*((float*)r) = f(*((float*)a),*((double*)b));}
static __attribute__((unused)) void g_f_forward_d_b(g_f_function_d_b_t f, void* r, const void* a, const void* b){*((float*)r) = f(*((double*)a),*((bool*)b));}
static __attribute__((unused)) void g_f_forward_d_c(g_f_function_d_c_t f, void* r, const void* a, const void* b){*((float*)r) = f(*((double*)a),*((char*)b));}
static __attribute__((unused)) void g_f_forward_d_ss(g_f_function_d_ss_t f, void* r, const void* a, const void* b){*((float*)r) = f(*((double*)a),*((short*)b));}
static __attribute__((unused)) void g_f_forward_d_si(g_f_function_d_si_t f, void* r, const void* a, const void* b){*((float*)r) = f(*((double*)a),*((int*)b));}
static __attribute__((unused)) void g_f_forward_d_sl(g_f_function_d_sl_t f, void* r, const void* a, const void* b){*((float*)r) = f(*((double*)a),*((long*)b));}
static __attribute__((unused)) void g_f_forward_d_ul(g_f_function_d_ul_t f, void* r, const void* a, const void* b){*((float*)r) = f(*((double*)a),*((unsigned long*)b));}
static __attribute__((unused)) void g_f_forward_d_f(g_f_function_d_f_t f, void* r, const void* a, const void* b){*((float*)r) = f(*((double*)a),*((float*)b));}
static __attribute__((unused)) void g_f_forward_d_d(g_f_function_d_d_t f, void* r, const void* a, const void* b){*((float*)r) = f(*((double*)a),*((double*)b));}
static __attribute__((unused)) void g_d_forward_b_b(g_d_function_b_b_t f, void* r, const void* a, const void* b){*((double*)r) = f(*((bool*)a),*((bool*)b));}
static __attribute__((unused)) void g_d_forward_b_c(g_d_function_b_c_t f, void* r, const void* a, const void* b){*((double*)r) = f(*((bool*)a),*((char*)b));}
static __attribute__((unused)) void g_d_forward_b_ss(g_d_function_b_ss_t f, void* r, const void* a, const void* b){*((double*)r) = f(*((bool*)a),*((short*)b));}
static __attribute__((unused)) void g_d_forward_b_si(g_d_function_b_si_t f, void* r, const void* a, const void* b){*((double*)r) = f(*((bool*)a),*((int*)b));}
static __attribute__((unused)) void g_d_forward_b_sl(g_d_function_b_sl_t f, void* r, const void* a, const void* b){*((double*)r) = f(*((bool*)a),*((long*)b));}
static __attribute__((unused)) void g_d_forward_b_ul(g_d_function_b_ul_t f, void* r, const void* a, const void* b){*((double*)r) = f(*((bool*)a),*((unsigned long*)b));}
static __attribute__((unused)) void g_d_forward_b_f(g_d_function_b_f_t f, void* r, const void* a, const void* b){*((double*)r) = f(*((bool*)a),*((float*)b));}
static __attribute__((unused)) void g_d_forward_b_d(g_d_function_b_d_t f, void* r, const void* a, const void* b){*((double*)r) = f(*((bool*)a),*((double*)b));}
static __attribute__((unused)) void g_d_forward_c_b(g_d_function_c_b_t f, void* r, const void* a, const void* b){*((double*)r) = f(*((char*)a),*((bool*)b));}
static __attribute__((unused)) void g_d_forward_c_c(g_d_function_c_c_t f, void* r, const void* a, const void* b){*((double*)r) = f(*((char*)a),*((char*)b));}
static __attribute__((unused)) void g_d_forward_c_ss(g_d_function_c_ss_t f, void* r, const void* a, const void* b){*((double*)r) = f(*((char*)a),*((short*)b));}
static __attribute__((unused)) void g_d_forward_c_si(g_d_function_c_si_t f, void* r, const void* a, const void* b){*((double*)r) = f(*((char*)a),*((int*)b));}
static __attribute__((unused)) void g_d_forward_c_sl(g_d_function_c_sl_t f, void* r, const void* a, const void* b){*((double*)r) = f(*((char*)a),*((long*)b));}
static __attribute__((unused)) void g_d_forward_c_ul(g_d_function_c_ul_t f, void* r, const void* a, const void* b){*((double*)r) = f(*((char*)a),*((unsigned long*)b));}
static __attribute__((unused)) void g_d_forward_c_f(g_d_function_c_f_t f, void* r, const void* a, const void* b){*((double*)r) = f(*((char*)a),*((float*)b));}
static __attribute__((unused)) void g_d_forward_c_d(g_d_function_c_d_t f, void* r, const void* a, const void* b){*((double*)r) = f(*((char*)a),*((double*)b));}
static __attribute__((unused)) void g_d_forward_ss_b(g_d_function_ss_b_t f, void* r, const void* a, const void* b){*((double*)r) = f(*((short*)a),*((bool*)b));}
static __attribute__((unused)) void g_d_forward_ss_c(g_d_function_ss_c_t f, void* r, const void* a, const void* b){*((double*)r) = f(*((short*)a),*((char*)b));}
static __attribute__((unused)) void g_d_forward_ss_ss(g_d_function_ss_ss_t f, void* r, const void* a, const void* b){*((double*)r) = f(*((short*)a),*((short*)b));}
static __attribute__((unused)) void g_d_forward_ss_si(g_d_function_ss_si_t f, void* r, const void* a, const void* b){*((double*)r) = f(*((short*)a),*((int*)b));}
static __attribute__((unused)) void g_d_forward_ss_sl(g_d_function_ss_sl_t f, void* r, const void* a, const void* b){*((double*)r) = f(*((short*)a),*((long*)b));}
static __attribute__((unused)) void g_d_forward_ss_ul(g_d_function_ss_ul_t f, void* r, const void* a, const void* b){*((double*)r) = f(*((short*)a),*((unsigned long*)b));}
static __attribute__((unused)) void g_d_forward_ss_f(g_d_function_ss_f_t f, void* r, const void* a, const void* b){*((double*)r) = f(*((short*)a),*((float*)b));}
static __attribute__((unused)) void g_d_forward_ss_d(g_d_function_ss_d_t f, void* r, const void* a, const void* b){*((double*)r) = f(*((short*)a),*((double*)b));}
static __attribute__((unused)) void g_d_forward_si_b(g_d_function_si_b_t f, void* r, const void* a, const void* b){*((double*)r) = f(*((int*)a),*((bool*)b));}
static __attribute__((unused)) void g_d_forward_si_c(g_d_function_si_c_t f, void* r, const void* a, const void* b){*((double*)r) = f(*((int*)a),*((char*)b));}
static __attribute__((unused)) void g_d_forward_si_ss(g_d_function_si_ss_t f, void* r, const void* a, const void* b){*((double*)r) = f(*((int*)a),*((short*)b));}
static __attribute__((unused)) void g_d_forward_si_si(g_d_function_si_si_t f, void* r, const void* a, const void* b){*((double*)r) = f(*((int*)a),*((int*)b));}
static __attribute__((unused)) void g_d_forward_si_sl(g_d_function_si_sl_t f, void* r, const void* a, const void* b){*((double*)r) = f(*((int*)a),*((long*)b));}
static __attribute__((unused)) void g_d_forward_si_ul(g_d_function_si_ul_t f, void* r, const void* a, const void* b){*((double*)r) = f(*((int*)a),*((unsigned long*)b));}
static __attribute__((unused)) void g_d_forward_si_f(g_d_function_si_f_t f, void* r, const void* a, const void* b){*((double*)r) = f(*((int*)a),*((float*)b));}
static __attribute__((unused)) void g_d_forward_si_d(g_d_function_si_d_t f, void* r, const void* a, const void* b){*((double*)r) = f(*((int*)a),*((double*)b));}
static __attribute__((unused)) void g_d_forward_sl_b(g_d_function_sl_b_t f, void* r, const void* a, const void* b){*((double*)r) = f(*((long*)a),*((bool*)b));}
static __attribute__((unused)) void g_d_forward_sl_c(g_d_function_sl_c_t f, void* r, const void* a, const void* b){*((double*)r) = f(*((long*)a),*((char*)b));}
static __attribute__((unused)) void g_d_forward_sl_ss(g_d_function_sl_ss_t f, void* r, const void* a, const void* b){*((double*)r) = f(*((long*)a),*((short*)b));}
static __attribute__((unused)) void g_d_forward_sl_si(g_d_function_sl_si_t f, void* r, const void* a, const void* b){*((double*)r) = f(*((long*)a),*((int*)b));}
static __attribute__((unused)) void g_d_forward_sl_sl(g_d_function_sl_sl_t f, void* r, const void* a, const void* b){*((double*)r) = f(*((long*)a),*((long*)b));}
static __attribute__((unused)) void g_d_forward_sl_ul(g_d_function_sl_ul_t f, void* r, const void* a, const void* b){*((double*)r) = f(*((long*)a),*((unsigned long*)b));}
static __attribute__((unused)) void g_d_forward_sl_f(g_d_function_sl_f_t f, void* r, const void* a, const void* b){*((double*)r) = f(*((long*)a),*((float*)b));}
static __attribute__((unused)) void g_d_forward_sl_d(g_d_function_sl_d_t f, void* r, const void* a, const void* b){*((double*)r) = f(*((long*)a),*((double*)b));}
static __attribute__((unused)) void g_d_forward_ul_b(g_d_function_ul_b_t f, void* r, const void* a, const void* b){*((double*)r) = f(*((unsigned long*)a),*((bool*)b));}
static __attribute__((unused)) void g_d_forward_ul_c(g_d_function_ul_c_t f, void* r, const void* a, const void* b){*((double*)r) = f(*((unsigned long*)a),*((char*)b));}
static __attribute__((unused)) void g_d_forward_ul_ss(g_d_function_ul_ss_t f, void* r, const void* a, const void* b){*((double*)r) = f(*((unsigned long*)a),*((short*)b));}
static __attribute__((unused)) void g_d_forward_ul_si(g_d_function_ul_si_t f, void* r, const void* a, const void* b){*((double*)r) = f(*((unsigned long*)a),*((int*)b));}
static __attribute__((unused)) void g_d_forward_ul_sl(g_d_function_ul_sl_t f, void* r, const void* a, const void* b){*((double*)r) = f(*((unsigned long*)a),*((long*)b));}
static __attribute__((unused)) void g_d_forward_ul_ul(g_d_function_ul_ul_t f, void* r, const void* a, const void* b){*((double*)r) = f(*((unsigned long*)a),*((unsigned long*)b));}
static __attribute__((unused)) void g_d_forward_ul_f(g_d_function_ul_f_t f, void* r, const void* a, const void* b){*((double*)r) = f(*((unsigned long*)a),*((float*)b));}
static __attribute__((unused)) void g_d_forward_ul_d(g_d_function_ul_d_t f, void* r, const void* a, const void* b){*((double*)r) = f(*((unsigned long*)a),*((double*)b));}
static __attribute__((unused)) void g_d_forward_f_b(g_d_function_f_b_t f, void* r, const void* a, const void* b){*((double*)r) = f(*((float*)a),*((bool*)b));}
static __attribute__((unused)) void g_d_forward_f_c(g_d_function_f_c_t f, void* r, const void* a, const void* b){*((double*)r) = f(*((float*)a),*((char*)b));}
static __attribute__((unused)) void g_d_forward_f_ss(g_d_function_f_ss_t f, void* r, const void* a, const void* b){*((double*)r) = f(*((float*)a),*((short*)b));}
static __attribute__((unused)) void g_d_forward_f_si(g_d_function_f_si_t f, void* r, const void* a, const void* b){*((double*)r) = f(*((float*)a),*((int*)b));}
static __attribute__((unused)) void g_d_forward_f_sl(g_d_function_f_sl_t f, void* r, const void* a, const void* b){*((double*)r) = f(*((float*)a),*((long*)b));}
static __attribute__((unused)) void g_d_forward_f_ul(g_d_function_f_ul_t f, void* r, const void* a, const void* b){*((double*)r) = f(*((float*)a),*((unsigned long*)b));}
static __attribute__((unused)) void g_d_forward_f_f(g_d_function_f_f_t f, void* r, const void* a, const void* b){*((double*)r) = f(*((float*)a),*((float*)b));}
static __attribute__((unused)) void g_d_forward_f_d(g_d_function_f_d_t f, void* r, const void* a, const void* b){*((double*)r) = f(*((float*)a),*((double*)b));}
static __attribute__((unused)) void g_d_forward_d_b(g_d_function_d_b_t f, void* r, const void* a, const void* b){*((double*)r) = f(*((double*)a),*((bool*)b));}
static __attribute__((unused)) void g_d_forward_d_c(g_d_function_d_c_t f, void* r, const void* a, const void* b){*((double*)r) = f(*((double*)a),*((char*)b));}
static __attribute__((unused)) void g_d_forward_d_ss(g_d_function_d_ss_t f, void* r, const void* a, const void* b){*((double*)r) = f(*((double*)a),*((short*)b));}
static __attribute__((unused)) void g_d_forward_d_si(g_d_function_d_si_t f, void* r, const void* a, const void* b){*((double*)r) = f(*((double*)a),*((int*)b));}
static __attribute__((unused)) void g_d_forward_d_sl(g_d_function_d_sl_t f, void* r, const void* a, const void* b){*((double*)r) = f(*((double*)a),*((long*)b));}
static __attribute__((unused)) void g_d_forward_d_ul(g_d_function_d_ul_t f, void* r, const void* a, const void* b){*((double*)r) = f(*((double*)a),*((unsigned long*)b));}
static __attribute__((unused)) void g_d_forward_d_f(g_d_function_d_f_t f, void* r, const void* a, const void* b){*((double*)r) = f(*((double*)a),*((float*)b));}
static __attribute__((unused)) void g_d_forward_d_d(g_d_function_d_d_t f, void* r, const void* a, const void* b){*((double*)r) = f(*((double*)a),*((double*)b));}

#define g_forward_2(x) _Generic((x) \
	, g_b_function_b_b_t : g_b_forward_b_b \
	, g_b_function_b_c_t : g_b_forward_b_c \
	, g_b_function_b_ss_t : g_b_forward_b_ss \
	, g_b_function_b_si_t : g_b_forward_b_si \
	, g_b_function_b_sl_t : g_b_forward_b_sl \
	, g_b_function_b_ul_t : g_b_forward_b_ul \
	, g_b_function_b_f_t : g_b_forward_b_f \
	, g_b_function_b_d_t : g_b_forward_b_d \
	, g_b_function_c_b_t : g_b_forward_c_b \
	, g_b_function_c_c_t : g_b_forward_c_c \
	, g_b_function_c_ss_t : g_b_forward_c_ss \
	, g_b_function_c_si_t : g_b_forward_c_si \
	, g_b_function_c_sl_t : g_b_forward_c_sl \
	, g_b_function_c_ul_t : g_b_forward_c_ul \
	, g_b_function_c_f_t : g_b_forward_c_f \
	, g_b_function_c_d_t : g_b_forward_c_d \
	, g_b_function_ss_b_t : g_b_forward_ss_b \
	, g_b_function_ss_c_t : g_b_forward_ss_c \
	, g_b_function_ss_ss_t : g_b_forward_ss_ss \
	, g_b_function_ss_si_t : g_b_forward_ss_si \
	, g_b_function_ss_sl_t : g_b_forward_ss_sl \
	, g_b_function_ss_ul_t : g_b_forward_ss_ul \
	, g_b_function_ss_f_t : g_b_forward_ss_f \
	, g_b_function_ss_d_t : g_b_forward_ss_d \
	, g_b_function_si_b_t : g_b_forward_si_b \
	, g_b_function_si_c_t : g_b_forward_si_c \
	, g_b_function_si_ss_t : g_b_forward_si_ss \
	, g_b_function_si_si_t : g_b_forward_si_si \
	, g_b_function_si_sl_t : g_b_forward_si_sl \
	, g_b_function_si_ul_t : g_b_forward_si_ul \
	, g_b_function_si_f_t : g_b_forward_si_f \
	, g_b_function_si_d_t : g_b_forward_si_d \
	, g_b_function_sl_b_t : g_b_forward_sl_b \
	, g_b_function_sl_c_t : g_b_forward_sl_c \
	, g_b_function_sl_ss_t : g_b_forward_sl_ss \
	, g_b_function_sl_si_t : g_b_forward_sl_si \
	, g_b_function_sl_sl_t : g_b_forward_sl_sl \
	, g_b_function_sl_ul_t : g_b_forward_sl_ul \
	, g_b_function_sl_f_t : g_b_forward_sl_f \
	, g_b_function_sl_d_t : g_b_forward_sl_d \
	, g_b_function_ul_b_t : g_b_forward_ul_b \
	, g_b_function_ul_c_t : g_b_forward_ul_c \
	, g_b_function_ul_ss_t : g_b_forward_ul_ss \
	, g_b_function_ul_si_t : g_b_forward_ul_si \
	, g_b_function_ul_sl_t : g_b_forward_ul_sl \
	, g_b_function_ul_ul_t : g_b_forward_ul_ul \
	, g_b_function_ul_f_t : g_b_forward_ul_f \
	, g_b_function_ul_d_t : g_b_forward_ul_d \
	, g_b_function_f_b_t : g_b_forward_f_b \
	, g_b_function_f_c_t : g_b_forward_f_c \
	, g_b_function_f_ss_t : g_b_forward_f_ss \
	, g_b_function_f_si_t : g_b_forward_f_si \
	, g_b_function_f_sl_t : g_b_forward_f_sl \
	, g_b_function_f_ul_t : g_b_forward_f_ul \
	, g_b_function_f_f_t : g_b_forward_f_f \
	, g_b_function_f_d_t : g_b_forward_f_d \
	, g_b_function_d_b_t : g_b_forward_d_b \
	, g_b_function_d_c_t : g_b_forward_d_c \
	, g_b_function_d_ss_t : g_b_forward_d_ss \
	, g_b_function_d_si_t : g_b_forward_d_si \
	, g_b_function_d_sl_t : g_b_forward_d_sl \
	, g_b_function_d_ul_t : g_b_forward_d_ul \
	, g_b_function_d_f_t : g_b_forward_d_f \
	, g_b_function_d_d_t : g_b_forward_d_d \
	, g_c_function_b_b_t : g_c_forward_b_b \
	, g_c_function_b_c_t : g_c_forward_b_c \
	, g_c_function_b_ss_t : g_c_forward_b_ss \
	, g_c_function_b_si_t : g_c_forward_b_si \
	, g_c_function_b_sl_t : g_c_forward_b_sl \
	, g_c_function_b_ul_t : g_c_forward_b_ul \
	, g_c_function_b_f_t : g_c_forward_b_f \
	, g_c_function_b_d_t : g_c_forward_b_d \
	, g_c_function_c_b_t : g_c_forward_c_b \
	, g_c_function_c_c_t : g_c_forward_c_c \
	, g_c_function_c_ss_t : g_c_forward_c_ss \
	, g_c_function_c_si_t : g_c_forward_c_si \
	, g_c_function_c_sl_t : g_c_forward_c_sl \
	, g_c_function_c_ul_t : g_c_forward_c_ul \
	, g_c_function_c_f_t : g_c_forward_c_f \
	, g_c_function_c_d_t : g_c_forward_c_d \
	, g_c_function_ss_b_t : g_c_forward_ss_b \
	, g_c_function_ss_c_t : g_c_forward_ss_c \
	, g_c_function_ss_ss_t : g_c_forward_ss_ss \
	, g_c_function_ss_si_t : g_c_forward_ss_si \
	, g_c_function_ss_sl_t : g_c_forward_ss_sl \
	, g_c_function_ss_ul_t : g_c_forward_ss_ul \
	, g_c_function_ss_f_t : g_c_forward_ss_f \
	, g_c_function_ss_d_t : g_c_forward_ss_d \
	, g_c_function_si_b_t : g_c_forward_si_b \
	, g_c_function_si_c_t : g_c_forward_si_c \
	, g_c_function_si_ss_t : g_c_forward_si_ss \
	, g_c_function_si_si_t : g_c_forward_si_si \
	, g_c_function_si_sl_t : g_c_forward_si_sl \
	, g_c_function_si_ul_t : g_c_forward_si_ul \
	, g_c_function_si_f_t : g_c_forward_si_f \
	, g_c_function_si_d_t : g_c_forward_si_d \
	, g_c_function_sl_b_t : g_c_forward_sl_b \
	, g_c_function_sl_c_t : g_c_forward_sl_c \
	, g_c_function_sl_ss_t : g_c_forward_sl_ss \
	, g_c_function_sl_si_t : g_c_forward_sl_si \
	, g_c_function_sl_sl_t : g_c_forward_sl_sl \
	, g_c_function_sl_ul_t : g_c_forward_sl_ul \
	, g_c_function_sl_f_t : g_c_forward_sl_f \
	, g_c_function_sl_d_t : g_c_forward_sl_d \
	, g_c_function_ul_b_t : g_c_forward_ul_b \
	, g_c_function_ul_c_t : g_c_forward_ul_c \
	, g_c_function_ul_ss_t : g_c_forward_ul_ss \
	, g_c_function_ul_si_t : g_c_forward_ul_si \
	, g_c_function_ul_sl_t : g_c_forward_ul_sl \
	, g_c_function_ul_ul_t : g_c_forward_ul_ul \
	, g_c_function_ul_f_t : g_c_forward_ul_f \
	, g_c_function_ul_d_t : g_c_forward_ul_d \
	, g_c_function_f_b_t : g_c_forward_f_b \
	, g_c_function_f_c_t : g_c_forward_f_c \
	, g_c_function_f_ss_t : g_c_forward_f_ss \
	, g_c_function_f_si_t : g_c_forward_f_si \
	, g_c_function_f_sl_t : g_c_forward_f_sl \
	, g_c_function_f_ul_t : g_c_forward_f_ul \
	, g_c_function_f_f_t : g_c_forward_f_f \
	, g_c_function_f_d_t : g_c_forward_f_d \
	, g_c_function_d_b_t : g_c_forward_d_b \
	, g_c_function_d_c_t : g_c_forward_d_c \
	, g_c_function_d_ss_t : g_c_forward_d_ss \
	, g_c_function_d_si_t : g_c_forward_d_si \
	, g_c_function_d_sl_t : g_c_forward_d_sl \
	, g_c_function_d_ul_t : g_c_forward_d_ul \
	, g_c_function_d_f_t : g_c_forward_d_f \
	, g_c_function_d_d_t : g_c_forward_d_d \
	, g_ss_function_b_b_t : g_ss_forward_b_b \
	, g_ss_function_b_c_t : g_ss_forward_b_c \
	, g_ss_function_b_ss_t : g_ss_forward_b_ss \
	, g_ss_function_b_si_t : g_ss_forward_b_si \
	, g_ss_function_b_sl_t : g_ss_forward_b_sl \
	, g_ss_function_b_ul_t : g_ss_forward_b_ul \
	, g_ss_function_b_f_t : g_ss_forward_b_f \
	, g_ss_function_b_d_t : g_ss_forward_b_d \
	, g_ss_function_c_b_t : g_ss_forward_c_b \
	, g_ss_function_c_c_t : g_ss_forward_c_c \
	, g_ss_function_c_ss_t : g_ss_forward_c_ss \
	, g_ss_function_c_si_t : g_ss_forward_c_si \
	, g_ss_function_c_sl_t : g_ss_forward_c_sl \
	, g_ss_function_c_ul_t : g_ss_forward_c_ul \
	, g_ss_function_c_f_t : g_ss_forward_c_f \
	, g_ss_function_c_d_t : g_ss_forward_c_d \
	, g_ss_function_ss_b_t : g_ss_forward_ss_b \
	, g_ss_function_ss_c_t : g_ss_forward_ss_c \
	, g_ss_function_ss_ss_t : g_ss_forward_ss_ss \
	, g_ss_function_ss_si_t : g_ss_forward_ss_si \
	, g_ss_function_ss_sl_t : g_ss_forward_ss_sl \
	, g_ss_function_ss_ul_t : g_ss_forward_ss_ul \
	, g_ss_function_ss_f_t : g_ss_forward_ss_f \
	, g_ss_function_ss_d_t : g_ss_forward_ss_d \
	, g_ss_function_si_b_t : g_ss_forward_si_b \
	, g_ss_function_si_c_t : g_ss_forward_si_c \
	, g_ss_function_si_ss_t : g_ss_forward_si_ss \
	, g_ss_function_si_si_t : g_ss_forward_si_si \
	, g_ss_function_si_sl_t : g_ss_forward_si_sl \
	, g_ss_function_si_ul_t : g_ss_forward_si_ul \
	, g_ss_function_si_f_t : g_ss_forward_si_f \
	, g_ss_function_si_d_t : g_ss_forward_si_d \
	, g_ss_function_sl_b_t : g_ss_forward_sl_b \
	, g_ss_function_sl_c_t : g_ss_forward_sl_c \
	, g_ss_function_sl_ss_t : g_ss_forward_sl_ss \
	, g_ss_function_sl_si_t : g_ss_forward_sl_si \
	, g_ss_function_sl_sl_t : g_ss_forward_sl_sl \
	, g_ss_function_sl_ul_t : g_ss_forward_sl_ul \
	, g_ss_function_sl_f_t : g_ss_forward_sl_f \
	, g_ss_function_sl_d_t : g_ss_forward_sl_d \
	, g_ss_function_ul_b_t : g_ss_forward_ul_b \
	, g_ss_function_ul_c_t : g_ss_forward_ul_c \
	, g_ss_function_ul_ss_t : g_ss_forward_ul_ss \
	, g_ss_function_ul_si_t : g_ss_forward_ul_si \
	, g_ss_function_ul_sl_t : g_ss_forward_ul_sl \
	, g_ss_function_ul_ul_t : g_ss_forward_ul_ul \
	, g_ss_function_ul_f_t : g_ss_forward_ul_f \
	, g_ss_function_ul_d_t : g_ss_forward_ul_d \
	, g_ss_function_f_b_t : g_ss_forward_f_b \
	, g_ss_function_f_c_t : g_ss_forward_f_c \
	, g_ss_function_f_ss_t : g_ss_forward_f_ss \
	, g_ss_function_f_si_t : g_ss_forward_f_si \
	, g_ss_function_f_sl_t : g_ss_forward_f_sl \
	, g_ss_function_f_ul_t : g_ss_forward_f_ul \
	, g_ss_function_f_f_t : g_ss_forward_f_f \
	, g_ss_function_f_d_t : g_ss_forward_f_d \
	, g_ss_function_d_b_t : g_ss_forward_d_b \
	, g_ss_function_d_c_t : g_ss_forward_d_c \
	, g_ss_function_d_ss_t : g_ss_forward_d_ss \
	, g_ss_function_d_si_t : g_ss_forward_d_si \
	, g_ss_function_d_sl_t : g_ss_forward_d_sl \
	, g_ss_function_d_ul_t : g_ss_forward_d_ul \
	, g_ss_function_d_f_t : g_ss_forward_d_f \
	, g_ss_function_d_d_t : g_ss_forward_d_d \
	, g_si_function_b_b_t : g_si_forward_b_b \
	, g_si_function_b_c_t : g_si_forward_b_c \
	, g_si_function_b_ss_t : g_si_forward_b_ss \
	, g_si_function_b_si_t : g_si_forward_b_si \
	, g_si_function_b_sl_t : g_si_forward_b_sl \
	, g_si_function_b_ul_t : g_si_forward_b_ul \
	, g_si_function_b_f_t : g_si_forward_b_f \
	, g_si_function_b_d_t : g_si_forward_b_d \
	, g_si_function_c_b_t : g_si_forward_c_b \
	, g_si_function_c_c_t : g_si_forward_c_c \
	, g_si_function_c_ss_t : g_si_forward_c_ss \
	, g_si_function_c_si_t : g_si_forward_c_si \
	, g_si_function_c_sl_t : g_si_forward_c_sl \
	, g_si_function_c_ul_t : g_si_forward_c_ul \
	, g_si_function_c_f_t : g_si_forward_c_f \
	, g_si_function_c_d_t : g_si_forward_c_d \
	, g_si_function_ss_b_t : g_si_forward_ss_b \
	, g_si_function_ss_c_t : g_si_forward_ss_c \
	, g_si_function_ss_ss_t : g_si_forward_ss_ss \
	, g_si_function_ss_si_t : g_si_forward_ss_si \
	, g_si_function_ss_sl_t : g_si_forward_ss_sl \
	, g_si_function_ss_ul_t : g_si_forward_ss_ul \
	, g_si_function_ss_f_t : g_si_forward_ss_f \
	, g_si_function_ss_d_t : g_si_forward_ss_d \
	, g_si_function_si_b_t : g_si_forward_si_b \
	, g_si_function_si_c_t : g_si_forward_si_c \
	, g_si_function_si_ss_t : g_si_forward_si_ss \
	, g_si_function_si_si_t : g_si_forward_si_si \
	, g_si_function_si_sl_t : g_si_forward_si_sl \
	, g_si_function_si_ul_t : g_si_forward_si_ul \
	, g_si_function_si_f_t : g_si_forward_si_f \
	, g_si_function_si_d_t : g_si_forward_si_d \
	, g_si_function_sl_b_t : g_si_forward_sl_b \
	, g_si_function_sl_c_t : g_si_forward_sl_c \
	, g_si_function_sl_ss_t : g_si_forward_sl_ss \
	, g_si_function_sl_si_t : g_si_forward_sl_si \
	, g_si_function_sl_sl_t : g_si_forward_sl_sl \
	, g_si_function_sl_ul_t : g_si_forward_sl_ul \
	, g_si_function_sl_f_t : g_si_forward_sl_f \
	, g_si_function_sl_d_t : g_si_forward_sl_d \
	, g_si_function_ul_b_t : g_si_forward_ul_b \
	, g_si_function_ul_c_t : g_si_forward_ul_c \
	, g_si_function_ul_ss_t : g_si_forward_ul_ss \
	, g_si_function_ul_si_t : g_si_forward_ul_si \
	, g_si_function_ul_sl_t : g_si_forward_ul_sl \
	, g_si_function_ul_ul_t : g_si_forward_ul_ul \
	, g_si_function_ul_f_t : g_si_forward_ul_f \
	, g_si_function_ul_d_t : g_si_forward_ul_d \
	, g_si_function_f_b_t : g_si_forward_f_b \
	, g_si_function_f_c_t : g_si_forward_f_c \
	, g_si_function_f_ss_t : g_si_forward_f_ss \
	, g_si_function_f_si_t : g_si_forward_f_si \
	, g_si_function_f_sl_t : g_si_forward_f_sl \
	, g_si_function_f_ul_t : g_si_forward_f_ul \
	, g_si_function_f_f_t : g_si_forward_f_f \
	, g_si_function_f_d_t : g_si_forward_f_d \
	, g_si_function_d_b_t : g_si_forward_d_b \
	, g_si_function_d_c_t : g_si_forward_d_c \
	, g_si_function_d_ss_t : g_si_forward_d_ss \
	, g_si_function_d_si_t : g_si_forward_d_si \
	, g_si_function_d_sl_t : g_si_forward_d_sl \
	, g_si_function_d_ul_t : g_si_forward_d_ul \
	, g_si_function_d_f_t : g_si_forward_d_f \
	, g_si_function_d_d_t : g_si_forward_d_d \
	, g_sl_function_b_b_t : g_sl_forward_b_b \
	, g_sl_function_b_c_t : g_sl_forward_b_c \
	, g_sl_function_b_ss_t : g_sl_forward_b_ss \
	, g_sl_function_b_si_t : g_sl_forward_b_si \
	, g_sl_function_b_sl_t : g_sl_forward_b_sl \
	, g_sl_function_b_ul_t : g_sl_forward_b_ul \
	, g_sl_function_b_f_t : g_sl_forward_b_f \
	, g_sl_function_b_d_t : g_sl_forward_b_d \
	, g_sl_function_c_b_t : g_sl_forward_c_b \
	, g_sl_function_c_c_t : g_sl_forward_c_c \
	, g_sl_function_c_ss_t : g_sl_forward_c_ss \
	, g_sl_function_c_si_t : g_sl_forward_c_si \
	, g_sl_function_c_sl_t : g_sl_forward_c_sl \
	, g_sl_function_c_ul_t : g_sl_forward_c_ul \
	, g_sl_function_c_f_t : g_sl_forward_c_f \
	, g_sl_function_c_d_t : g_sl_forward_c_d \
	, g_sl_function_ss_b_t : g_sl_forward_ss_b \
	, g_sl_function_ss_c_t : g_sl_forward_ss_c \
	, g_sl_function_ss_ss_t : g_sl_forward_ss_ss \
	, g_sl_function_ss_si_t : g_sl_forward_ss_si \
	, g_sl_function_ss_sl_t : g_sl_forward_ss_sl \
	, g_sl_function_ss_ul_t : g_sl_forward_ss_ul \
	, g_sl_function_ss_f_t : g_sl_forward_ss_f \
	, g_sl_function_ss_d_t : g_sl_forward_ss_d \
	, g_sl_function_si_b_t : g_sl_forward_si_b \
	, g_sl_function_si_c_t : g_sl_forward_si_c \
	, g_sl_function_si_ss_t : g_sl_forward_si_ss \
	, g_sl_function_si_si_t : g_sl_forward_si_si \
	, g_sl_function_si_sl_t : g_sl_forward_si_sl \
	, g_sl_function_si_ul_t : g_sl_forward_si_ul \
	, g_sl_function_si_f_t : g_sl_forward_si_f \
	, g_sl_function_si_d_t : g_sl_forward_si_d \
	, g_sl_function_sl_b_t : g_sl_forward_sl_b \
	, g_sl_function_sl_c_t : g_sl_forward_sl_c \
	, g_sl_function_sl_ss_t : g_sl_forward_sl_ss \
	, g_sl_function_sl_si_t : g_sl_forward_sl_si \
	, g_sl_function_sl_sl_t : g_sl_forward_sl_sl \
	, g_sl_function_sl_ul_t : g_sl_forward_sl_ul \
	, g_sl_function_sl_f_t : g_sl_forward_sl_f \
	, g_sl_function_sl_d_t : g_sl_forward_sl_d \
	, g_sl_function_ul_b_t : g_sl_forward_ul_b \
	, g_sl_function_ul_c_t : g_sl_forward_ul_c \
	, g_sl_function_ul_ss_t : g_sl_forward_ul_ss \
	, g_sl_function_ul_si_t : g_sl_forward_ul_si \
	, g_sl_function_ul_sl_t : g_sl_forward_ul_sl \
	, g_sl_function_ul_ul_t : g_sl_forward_ul_ul \
	, g_sl_function_ul_f_t : g_sl_forward_ul_f \
	, g_sl_function_ul_d_t : g_sl_forward_ul_d \
	, g_sl_function_f_b_t : g_sl_forward_f_b \
	, g_sl_function_f_c_t : g_sl_forward_f_c \
	, g_sl_function_f_ss_t : g_sl_forward_f_ss \
	, g_sl_function_f_si_t : g_sl_forward_f_si \
	, g_sl_function_f_sl_t : g_sl_forward_f_sl \
	, g_sl_function_f_ul_t : g_sl_forward_f_ul \
	, g_sl_function_f_f_t : g_sl_forward_f_f \
	, g_sl_function_f_d_t : g_sl_forward_f_d \
	, g_sl_function_d_b_t : g_sl_forward_d_b \
	, g_sl_function_d_c_t : g_sl_forward_d_c \
	, g_sl_function_d_ss_t : g_sl_forward_d_ss \
	, g_sl_function_d_si_t : g_sl_forward_d_si \
	, g_sl_function_d_sl_t : g_sl_forward_d_sl \
	, g_sl_function_d_ul_t : g_sl_forward_d_ul \
	, g_sl_function_d_f_t : g_sl_forward_d_f \
	, g_sl_function_d_d_t : g_sl_forward_d_d \
	, g_ul_function_b_b_t : g_ul_forward_b_b \
	, g_ul_function_b_c_t : g_ul_forward_b_c \
	, g_ul_function_b_ss_t : g_ul_forward_b_ss \
	, g_ul_function_b_si_t : g_ul_forward_b_si \
	, g_ul_function_b_sl_t : g_ul_forward_b_sl \
	, g_ul_function_b_ul_t : g_ul_forward_b_ul \
	, g_ul_function_b_f_t : g_ul_forward_b_f \
	, g_ul_function_b_d_t : g_ul_forward_b_d \
	, g_ul_function_c_b_t : g_ul_forward_c_b \
	, g_ul_function_c_c_t : g_ul_forward_c_c \
	, g_ul_function_c_ss_t : g_ul_forward_c_ss \
	, g_ul_function_c_si_t : g_ul_forward_c_si \
	, g_ul_function_c_sl_t : g_ul_forward_c_sl \
	, g_ul_function_c_ul_t : g_ul_forward_c_ul \
	, g_ul_function_c_f_t : g_ul_forward_c_f \
	, g_ul_function_c_d_t : g_ul_forward_c_d \
	, g_ul_function_ss_b_t : g_ul_forward_ss_b \
	, g_ul_function_ss_c_t : g_ul_forward_ss_c \
	, g_ul_function_ss_ss_t : g_ul_forward_ss_ss \
	, g_ul_function_ss_si_t : g_ul_forward_ss_si \
	, g_ul_function_ss_sl_t : g_ul_forward_ss_sl \
	, g_ul_function_ss_ul_t : g_ul_forward_ss_ul \
	, g_ul_function_ss_f_t : g_ul_forward_ss_f \
	, g_ul_function_ss_d_t : g_ul_forward_ss_d \
	, g_ul_function_si_b_t : g_ul_forward_si_b \
	, g_ul_function_si_c_t : g_ul_forward_si_c \
	, g_ul_function_si_ss_t : g_ul_forward_si_ss \
	, g_ul_function_si_si_t : g_ul_forward_si_si \
	, g_ul_function_si_sl_t : g_ul_forward_si_sl \
	, g_ul_function_si_ul_t : g_ul_forward_si_ul \
	, g_ul_function_si_f_t : g_ul_forward_si_f \
	, g_ul_function_si_d_t : g_ul_forward_si_d \
	, g_ul_function_sl_b_t : g_ul_forward_sl_b \
	, g_ul_function_sl_c_t : g_ul_forward_sl_c \
	, g_ul_function_sl_ss_t : g_ul_forward_sl_ss \
	, g_ul_function_sl_si_t : g_ul_forward_sl_si \
	, g_ul_function_sl_sl_t : g_ul_forward_sl_sl \
	, g_ul_function_sl_ul_t : g_ul_forward_sl_ul \
	, g_ul_function_sl_f_t : g_ul_forward_sl_f \
	, g_ul_function_sl_d_t : g_ul_forward_sl_d \
	, g_ul_function_ul_b_t : g_ul_forward_ul_b \
	, g_ul_function_ul_c_t : g_ul_forward_ul_c \
	, g_ul_function_ul_ss_t : g_ul_forward_ul_ss \
	, g_ul_function_ul_si_t : g_ul_forward_ul_si \
	, g_ul_function_ul_sl_t : g_ul_forward_ul_sl \
	, g_ul_function_ul_ul_t : g_ul_forward_ul_ul \
	, g_ul_function_ul_f_t : g_ul_forward_ul_f \
	, g_ul_function_ul_d_t : g_ul_forward_ul_d \
	, g_ul_function_f_b_t : g_ul_forward_f_b \
	, g_ul_function_f_c_t : g_ul_forward_f_c \
	, g_ul_function_f_ss_t : g_ul_forward_f_ss \
	, g_ul_function_f_si_t : g_ul_forward_f_si \
	, g_ul_function_f_sl_t : g_ul_forward_f_sl \
	, g_ul_function_f_ul_t : g_ul_forward_f_ul \
	, g_ul_function_f_f_t : g_ul_forward_f_f \
	, g_ul_function_f_d_t : g_ul_forward_f_d \
	, g_ul_function_d_b_t : g_ul_forward_d_b \
	, g_ul_function_d_c_t : g_ul_forward_d_c \
	, g_ul_function_d_ss_t : g_ul_forward_d_ss \
	, g_ul_function_d_si_t : g_ul_forward_d_si \
	, g_ul_function_d_sl_t : g_ul_forward_d_sl \
	, g_ul_function_d_ul_t : g_ul_forward_d_ul \
	, g_ul_function_d_f_t : g_ul_forward_d_f \
	, g_ul_function_d_d_t : g_ul_forward_d_d \
	, g_f_function_b_b_t : g_f_forward_b_b \
	, g_f_function_b_c_t : g_f_forward_b_c \
	, g_f_function_b_ss_t : g_f_forward_b_ss \
	, g_f_function_b_si_t : g_f_forward_b_si \
	, g_f_function_b_sl_t : g_f_forward_b_sl \
	, g_f_function_b_ul_t : g_f_forward_b_ul \
	, g_f_function_b_f_t : g_f_forward_b_f \
	, g_f_function_b_d_t : g_f_forward_b_d \
	, g_f_function_c_b_t : g_f_forward_c_b \
	, g_f_function_c_c_t : g_f_forward_c_c \
	, g_f_function_c_ss_t : g_f_forward_c_ss \
	, g_f_function_c_si_t : g_f_forward_c_si \
	, g_f_function_c_sl_t : g_f_forward_c_sl \
	, g_f_function_c_ul_t : g_f_forward_c_ul \
	, g_f_function_c_f_t : g_f_forward_c_f \
	, g_f_function_c_d_t : g_f_forward_c_d \
	, g_f_function_ss_b_t : g_f_forward_ss_b \
	, g_f_function_ss_c_t : g_f_forward_ss_c \
	, g_f_function_ss_ss_t : g_f_forward_ss_ss \
	, g_f_function_ss_si_t : g_f_forward_ss_si \
	, g_f_function_ss_sl_t : g_f_forward_ss_sl \
	, g_f_function_ss_ul_t : g_f_forward_ss_ul \
	, g_f_function_ss_f_t : g_f_forward_ss_f \
	, g_f_function_ss_d_t : g_f_forward_ss_d \
	, g_f_function_si_b_t : g_f_forward_si_b \
	, g_f_function_si_c_t : g_f_forward_si_c \
	, g_f_function_si_ss_t : g_f_forward_si_ss \
	, g_f_function_si_si_t : g_f_forward_si_si \
	, g_f_function_si_sl_t : g_f_forward_si_sl \
	, g_f_function_si_ul_t : g_f_forward_si_ul \
	, g_f_function_si_f_t : g_f_forward_si_f \
	, g_f_function_si_d_t : g_f_forward_si_d \
	, g_f_function_sl_b_t : g_f_forward_sl_b \
	, g_f_function_sl_c_t : g_f_forward_sl_c \
	, g_f_function_sl_ss_t : g_f_forward_sl_ss \
	, g_f_function_sl_si_t : g_f_forward_sl_si \
	, g_f_function_sl_sl_t : g_f_forward_sl_sl \
	, g_f_function_sl_ul_t : g_f_forward_sl_ul \
	, g_f_function_sl_f_t : g_f_forward_sl_f \
	, g_f_function_sl_d_t : g_f_forward_sl_d \
	, g_f_function_ul_b_t : g_f_forward_ul_b \
	, g_f_function_ul_c_t : g_f_forward_ul_c \
	, g_f_function_ul_ss_t : g_f_forward_ul_ss \
	, g_f_function_ul_si_t : g_f_forward_ul_si \
	, g_f_function_ul_sl_t : g_f_forward_ul_sl \
	, g_f_function_ul_ul_t : g_f_forward_ul_ul \
	, g_f_function_ul_f_t : g_f_forward_ul_f \
	, g_f_function_ul_d_t : g_f_forward_ul_d \
	, g_f_function_f_b_t : g_f_forward_f_b \
	, g_f_function_f_c_t : g_f_forward_f_c \
	, g_f_function_f_ss_t : g_f_forward_f_ss \
	, g_f_function_f_si_t : g_f_forward_f_si \
	, g_f_function_f_sl_t : g_f_forward_f_sl \
	, g_f_function_f_ul_t : g_f_forward_f_ul \
	, g_f_function_f_f_t : g_f_forward_f_f \
	, g_f_function_f_d_t : g_f_forward_f_d \
	, g_f_function_d_b_t : g_f_forward_d_b \
	, g_f_function_d_c_t : g_f_forward_d_c \
	, g_f_function_d_ss_t : g_f_forward_d_ss \
	, g_f_function_d_si_t : g_f_forward_d_si \
	, g_f_function_d_sl_t : g_f_forward_d_sl \
	, g_f_function_d_ul_t : g_f_forward_d_ul \
	, g_f_function_d_f_t : g_f_forward_d_f \
	, g_f_function_d_d_t : g_f_forward_d_d \
	, g_d_function_b_b_t : g_d_forward_b_b \
	, g_d_function_b_c_t : g_d_forward_b_c \
	, g_d_function_b_ss_t : g_d_forward_b_ss \
	, g_d_function_b_si_t : g_d_forward_b_si \
	, g_d_function_b_sl_t : g_d_forward_b_sl \
	, g_d_function_b_ul_t : g_d_forward_b_ul \
	, g_d_function_b_f_t : g_d_forward_b_f \
	, g_d_function_b_d_t : g_d_forward_b_d \
	, g_d_function_c_b_t : g_d_forward_c_b \
	, g_d_function_c_c_t : g_d_forward_c_c \
	, g_d_function_c_ss_t : g_d_forward_c_ss \
	, g_d_function_c_si_t : g_d_forward_c_si \
	, g_d_function_c_sl_t : g_d_forward_c_sl \
	, g_d_function_c_ul_t : g_d_forward_c_ul \
	, g_d_function_c_f_t : g_d_forward_c_f \
	, g_d_function_c_d_t : g_d_forward_c_d \
	, g_d_function_ss_b_t : g_d_forward_ss_b \
	, g_d_function_ss_c_t : g_d_forward_ss_c \
	, g_d_function_ss_ss_t : g_d_forward_ss_ss \
	, g_d_function_ss_si_t : g_d_forward_ss_si \
	, g_d_function_ss_sl_t : g_d_forward_ss_sl \
	, g_d_function_ss_ul_t : g_d_forward_ss_ul \
	, g_d_function_ss_f_t : g_d_forward_ss_f \
	, g_d_function_ss_d_t : g_d_forward_ss_d \
	, g_d_function_si_b_t : g_d_forward_si_b \
	, g_d_function_si_c_t : g_d_forward_si_c \
	, g_d_function_si_ss_t : g_d_forward_si_ss \
	, g_d_function_si_si_t : g_d_forward_si_si \
	, g_d_function_si_sl_t : g_d_forward_si_sl \
	, g_d_function_si_ul_t : g_d_forward_si_ul \
	, g_d_function_si_f_t : g_d_forward_si_f \
	, g_d_function_si_d_t : g_d_forward_si_d \
	, g_d_function_sl_b_t : g_d_forward_sl_b \
	, g_d_function_sl_c_t : g_d_forward_sl_c \
	, g_d_function_sl_ss_t : g_d_forward_sl_ss \
	, g_d_function_sl_si_t : g_d_forward_sl_si \
	, g_d_function_sl_sl_t : g_d_forward_sl_sl \
	, g_d_function_sl_ul_t : g_d_forward_sl_ul \
	, g_d_function_sl_f_t : g_d_forward_sl_f \
	, g_d_function_sl_d_t : g_d_forward_sl_d \
	, g_d_function_ul_b_t : g_d_forward_ul_b \
	, g_d_function_ul_c_t : g_d_forward_ul_c \
	, g_d_function_ul_ss_t : g_d_forward_ul_ss \
	, g_d_function_ul_si_t : g_d_forward_ul_si \
	, g_d_function_ul_sl_t : g_d_forward_ul_sl \
	, g_d_function_ul_ul_t : g_d_forward_ul_ul \
	, g_d_function_ul_f_t : g_d_forward_ul_f \
	, g_d_function_ul_d_t : g_d_forward_ul_d \
	, g_d_function_f_b_t : g_d_forward_f_b \
	, g_d_function_f_c_t : g_d_forward_f_c \
	, g_d_function_f_ss_t : g_d_forward_f_ss \
	, g_d_function_f_si_t : g_d_forward_f_si \
	, g_d_function_f_sl_t : g_d_forward_f_sl \
	, g_d_function_f_ul_t : g_d_forward_f_ul \
	, g_d_function_f_f_t : g_d_forward_f_f \
	, g_d_function_f_d_t : g_d_forward_f_d \
	, g_d_function_d_b_t : g_d_forward_d_b \
	, g_d_function_d_c_t : g_d_forward_d_c \
	, g_d_function_d_ss_t : g_d_forward_d_ss \
	, g_d_function_d_si_t : g_d_forward_d_si \
	, g_d_function_d_sl_t : g_d_forward_d_sl \
	, g_d_function_d_ul_t : g_d_forward_d_ul \
	, g_d_function_d_f_t : g_d_forward_d_f \
	, g_d_function_d_d_t : g_d_forward_d_d \
)

#define g_function_rettype(x) _Generic((x) \
	, g_b_function_t : g_example_b \
	, g_c_function_t : g_example_c \
	, g_ss_function_t : g_example_ss \
	, g_si_function_t : g_example_si \
	, g_sl_function_t : g_example_sl \
	, g_ul_function_t : g_example_ul \
	, g_f_function_t : g_example_f \
	, g_d_function_t : g_example_d \
	, g_b_function_b_t : g_example_b \
	, g_b_function_c_t : g_example_b \
	, g_b_function_ss_t : g_example_b \
	, g_b_function_si_t : g_example_b \
	, g_b_function_sl_t : g_example_b \
	, g_b_function_ul_t : g_example_b \
	, g_b_function_f_t : g_example_b \
	, g_b_function_d_t : g_example_b \
	, g_c_function_b_t : g_example_c \
	, g_c_function_c_t : g_example_c \
	, g_c_function_ss_t : g_example_c \
	, g_c_function_si_t : g_example_c \
	, g_c_function_sl_t : g_example_c \
	, g_c_function_ul_t : g_example_c \
	, g_c_function_f_t : g_example_c \
	, g_c_function_d_t : g_example_c \
	, g_ss_function_b_t : g_example_ss \
	, g_ss_function_c_t : g_example_ss \
	, g_ss_function_ss_t : g_example_ss \
	, g_ss_function_si_t : g_example_ss \
	, g_ss_function_sl_t : g_example_ss \
	, g_ss_function_ul_t : g_example_ss \
	, g_ss_function_f_t : g_example_ss \
	, g_ss_function_d_t : g_example_ss \
	, g_si_function_b_t : g_example_si \
	, g_si_function_c_t : g_example_si \
	, g_si_function_ss_t : g_example_si \
	, g_si_function_si_t : g_example_si \
	, g_si_function_sl_t : g_example_si \
	, g_si_function_ul_t : g_example_si \
	, g_si_function_f_t : g_example_si \
	, g_si_function_d_t : g_example_si \
	, g_sl_function_b_t : g_example_sl \
	, g_sl_function_c_t : g_example_sl \
	, g_sl_function_ss_t : g_example_sl \
	, g_sl_function_si_t : g_example_sl \
	, g_sl_function_sl_t : g_example_sl \
	, g_sl_function_ul_t : g_example_sl \
	, g_sl_function_f_t : g_example_sl \
	, g_sl_function_d_t : g_example_sl \
	, g_ul_function_b_t : g_example_ul \
	, g_ul_function_c_t : g_example_ul \
	, g_ul_function_ss_t : g_example_ul \
	, g_ul_function_si_t : g_example_ul \
	, g_ul_function_sl_t : g_example_ul \
	, g_ul_function_ul_t : g_example_ul \
	, g_ul_function_f_t : g_example_ul \
	, g_ul_function_d_t : g_example_ul \
	, g_f_function_b_t : g_example_f \
	, g_f_function_c_t : g_example_f \
	, g_f_function_ss_t : g_example_f \
	, g_f_function_si_t : g_example_f \
	, g_f_function_sl_t : g_example_f \
	, g_f_function_ul_t : g_example_f \
	, g_f_function_f_t : g_example_f \
	, g_f_function_d_t : g_example_f \
	, g_d_function_b_t : g_example_d \
	, g_d_function_c_t : g_example_d \
	, g_d_function_ss_t : g_example_d \
	, g_d_function_si_t : g_example_d \
	, g_d_function_sl_t : g_example_d \
	, g_d_function_ul_t : g_example_d \
	, g_d_function_f_t : g_example_d \
	, g_d_function_d_t : g_example_d \
	, g_b_function_b_b_t : g_example_b \
	, g_b_function_b_c_t : g_example_b \
	, g_b_function_b_ss_t : g_example_b \
	, g_b_function_b_si_t : g_example_b \
	, g_b_function_b_sl_t : g_example_b \
	, g_b_function_b_ul_t : g_example_b \
	, g_b_function_b_f_t : g_example_b \
	, g_b_function_b_d_t : g_example_b \
	, g_b_function_c_b_t : g_example_b \
	, g_b_function_c_c_t : g_example_b \
	, g_b_function_c_ss_t : g_example_b \
	, g_b_function_c_si_t : g_example_b \
	, g_b_function_c_sl_t : g_example_b \
	, g_b_function_c_ul_t : g_example_b \
	, g_b_function_c_f_t : g_example_b \
	, g_b_function_c_d_t : g_example_b \
	, g_b_function_ss_b_t : g_example_b \
	, g_b_function_ss_c_t : g_example_b \
	, g_b_function_ss_ss_t : g_example_b \
	, g_b_function_ss_si_t : g_example_b \
	, g_b_function_ss_sl_t : g_example_b \
	, g_b_function_ss_ul_t : g_example_b \
	, g_b_function_ss_f_t : g_example_b \
	, g_b_function_ss_d_t : g_example_b \
	, g_b_function_si_b_t : g_example_b \
	, g_b_function_si_c_t : g_example_b \
	, g_b_function_si_ss_t : g_example_b \
	, g_b_function_si_si_t : g_example_b \
	, g_b_function_si_sl_t : g_example_b \
	, g_b_function_si_ul_t : g_example_b \
	, g_b_function_si_f_t : g_example_b \
	, g_b_function_si_d_t : g_example_b \
	, g_b_function_sl_b_t : g_example_b \
	, g_b_function_sl_c_t : g_example_b \
	, g_b_function_sl_ss_t : g_example_b \
	, g_b_function_sl_si_t : g_example_b \
	, g_b_function_sl_sl_t : g_example_b \
	, g_b_function_sl_ul_t : g_example_b \
	, g_b_function_sl_f_t : g_example_b \
	, g_b_function_sl_d_t : g_example_b \
	, g_b_function_ul_b_t : g_example_b \
	, g_b_function_ul_c_t : g_example_b \
	, g_b_function_ul_ss_t : g_example_b \
	, g_b_function_ul_si_t : g_example_b \
	, g_b_function_ul_sl_t : g_example_b \
	, g_b_function_ul_ul_t : g_example_b \
	, g_b_function_ul_f_t : g_example_b \
	, g_b_function_ul_d_t : g_example_b \
	, g_b_function_f_b_t : g_example_b \
	, g_b_function_f_c_t : g_example_b \
	, g_b_function_f_ss_t : g_example_b \
	, g_b_function_f_si_t : g_example_b \
	, g_b_function_f_sl_t : g_example_b \
	, g_b_function_f_ul_t : g_example_b \
	, g_b_function_f_f_t : g_example_b \
	, g_b_function_f_d_t : g_example_b \
	, g_b_function_d_b_t : g_example_b \
	, g_b_function_d_c_t : g_example_b \
	, g_b_function_d_ss_t : g_example_b \
	, g_b_function_d_si_t : g_example_b \
	, g_b_function_d_sl_t : g_example_b \
	, g_b_function_d_ul_t : g_example_b \
	, g_b_function_d_f_t : g_example_b \
	, g_b_function_d_d_t : g_example_b \
	, g_c_function_b_b_t : g_example_c \
	, g_c_function_b_c_t : g_example_c \
	, g_c_function_b_ss_t : g_example_c \
	, g_c_function_b_si_t : g_example_c \
	, g_c_function_b_sl_t : g_example_c \
	, g_c_function_b_ul_t : g_example_c \
	, g_c_function_b_f_t : g_example_c \
	, g_c_function_b_d_t : g_example_c \
	, g_c_function_c_b_t : g_example_c \
	, g_c_function_c_c_t : g_example_c \
	, g_c_function_c_ss_t : g_example_c \
	, g_c_function_c_si_t : g_example_c \
	, g_c_function_c_sl_t : g_example_c \
	, g_c_function_c_ul_t : g_example_c \
	, g_c_function_c_f_t : g_example_c \
	, g_c_function_c_d_t : g_example_c \
	, g_c_function_ss_b_t : g_example_c \
	, g_c_function_ss_c_t : g_example_c \
	, g_c_function_ss_ss_t : g_example_c \
	, g_c_function_ss_si_t : g_example_c \
	, g_c_function_ss_sl_t : g_example_c \
	, g_c_function_ss_ul_t : g_example_c \
	, g_c_function_ss_f_t : g_example_c \
	, g_c_function_ss_d_t : g_example_c \
	, g_c_function_si_b_t : g_example_c \
	, g_c_function_si_c_t : g_example_c \
	, g_c_function_si_ss_t : g_example_c \
	, g_c_function_si_si_t : g_example_c \
	, g_c_function_si_sl_t : g_example_c \
	, g_c_function_si_ul_t : g_example_c \
	, g_c_function_si_f_t : g_example_c \
	, g_c_function_si_d_t : g_example_c \
	, g_c_function_sl_b_t : g_example_c \
	, g_c_function_sl_c_t : g_example_c \
	, g_c_function_sl_ss_t : g_example_c \
	, g_c_function_sl_si_t : g_example_c \
	, g_c_function_sl_sl_t : g_example_c \
	, g_c_function_sl_ul_t : g_example_c \
	, g_c_function_sl_f_t : g_example_c \
	, g_c_function_sl_d_t : g_example_c \
	, g_c_function_ul_b_t : g_example_c \
	, g_c_function_ul_c_t : g_example_c \
	, g_c_function_ul_ss_t : g_example_c \
	, g_c_function_ul_si_t : g_example_c \
	, g_c_function_ul_sl_t : g_example_c \
	, g_c_function_ul_ul_t : g_example_c \
	, g_c_function_ul_f_t : g_example_c \
	, g_c_function_ul_d_t : g_example_c \
	, g_c_function_f_b_t : g_example_c \
	, g_c_function_f_c_t : g_example_c \
	, g_c_function_f_ss_t : g_example_c \
	, g_c_function_f_si_t : g_example_c \
	, g_c_function_f_sl_t : g_example_c \
	, g_c_function_f_ul_t : g_example_c \
	, g_c_function_f_f_t : g_example_c \
	, g_c_function_f_d_t : g_example_c \
	, g_c_function_d_b_t : g_example_c \
	, g_c_function_d_c_t : g_example_c \
	, g_c_function_d_ss_t : g_example_c \
	, g_c_function_d_si_t : g_example_c \
	, g_c_function_d_sl_t : g_example_c \
	, g_c_function_d_ul_t : g_example_c \
	, g_c_function_d_f_t : g_example_c \
	, g_c_function_d_d_t : g_example_c \
	, g_ss_function_b_b_t : g_example_ss \
	, g_ss_function_b_c_t : g_example_ss \
	, g_ss_function_b_ss_t : g_example_ss \
	, g_ss_function_b_si_t : g_example_ss \
	, g_ss_function_b_sl_t : g_example_ss \
	, g_ss_function_b_ul_t : g_example_ss \
	, g_ss_function_b_f_t : g_example_ss \
	, g_ss_function_b_d_t : g_example_ss \
	, g_ss_function_c_b_t : g_example_ss \
	, g_ss_function_c_c_t : g_example_ss \
	, g_ss_function_c_ss_t : g_example_ss \
	, g_ss_function_c_si_t : g_example_ss \
	, g_ss_function_c_sl_t : g_example_ss \
	, g_ss_function_c_ul_t : g_example_ss \
	, g_ss_function_c_f_t : g_example_ss \
	, g_ss_function_c_d_t : g_example_ss \
	, g_ss_function_ss_b_t : g_example_ss \
	, g_ss_function_ss_c_t : g_example_ss \
	, g_ss_function_ss_ss_t : g_example_ss \
	, g_ss_function_ss_si_t : g_example_ss \
	, g_ss_function_ss_sl_t : g_example_ss \
	, g_ss_function_ss_ul_t : g_example_ss \
	, g_ss_function_ss_f_t : g_example_ss \
	, g_ss_function_ss_d_t : g_example_ss \
	, g_ss_function_si_b_t : g_example_ss \
	, g_ss_function_si_c_t : g_example_ss \
	, g_ss_function_si_ss_t : g_example_ss \
	, g_ss_function_si_si_t : g_example_ss \
	, g_ss_function_si_sl_t : g_example_ss \
	, g_ss_function_si_ul_t : g_example_ss \
	, g_ss_function_si_f_t : g_example_ss \
	, g_ss_function_si_d_t : g_example_ss \
	, g_ss_function_sl_b_t : g_example_ss \
	, g_ss_function_sl_c_t : g_example_ss \
	, g_ss_function_sl_ss_t : g_example_ss \
	, g_ss_function_sl_si_t : g_example_ss \
	, g_ss_function_sl_sl_t : g_example_ss \
	, g_ss_function_sl_ul_t : g_example_ss \
	, g_ss_function_sl_f_t : g_example_ss \
	, g_ss_function_sl_d_t : g_example_ss \
	, g_ss_function_ul_b_t : g_example_ss \
	, g_ss_function_ul_c_t : g_example_ss \
	, g_ss_function_ul_ss_t : g_example_ss \
	, g_ss_function_ul_si_t : g_example_ss \
	, g_ss_function_ul_sl_t : g_example_ss \
	, g_ss_function_ul_ul_t : g_example_ss \
	, g_ss_function_ul_f_t : g_example_ss \
	, g_ss_function_ul_d_t : g_example_ss \
	, g_ss_function_f_b_t : g_example_ss \
	, g_ss_function_f_c_t : g_example_ss \
	, g_ss_function_f_ss_t : g_example_ss \
	, g_ss_function_f_si_t : g_example_ss \
	, g_ss_function_f_sl_t : g_example_ss \
	, g_ss_function_f_ul_t : g_example_ss \
	, g_ss_function_f_f_t : g_example_ss \
	, g_ss_function_f_d_t : g_example_ss \
	, g_ss_function_d_b_t : g_example_ss \
	, g_ss_function_d_c_t : g_example_ss \
	, g_ss_function_d_ss_t : g_example_ss \
	, g_ss_function_d_si_t : g_example_ss \
	, g_ss_function_d_sl_t : g_example_ss \
	, g_ss_function_d_ul_t : g_example_ss \
	, g_ss_function_d_f_t : g_example_ss \
	, g_ss_function_d_d_t : g_example_ss \
	, g_si_function_b_b_t : g_example_si \
	, g_si_function_b_c_t : g_example_si \
	, g_si_function_b_ss_t : g_example_si \
	, g_si_function_b_si_t : g_example_si \
	, g_si_function_b_sl_t : g_example_si \
	, g_si_function_b_ul_t : g_example_si \
	, g_si_function_b_f_t : g_example_si \
	, g_si_function_b_d_t : g_example_si \
	, g_si_function_c_b_t : g_example_si \
	, g_si_function_c_c_t : g_example_si \
	, g_si_function_c_ss_t : g_example_si \
	, g_si_function_c_si_t : g_example_si \
	, g_si_function_c_sl_t : g_example_si \
	, g_si_function_c_ul_t : g_example_si \
	, g_si_function_c_f_t : g_example_si \
	, g_si_function_c_d_t : g_example_si \
	, g_si_function_ss_b_t : g_example_si \
	, g_si_function_ss_c_t : g_example_si \
	, g_si_function_ss_ss_t : g_example_si \
	, g_si_function_ss_si_t : g_example_si \
	, g_si_function_ss_sl_t : g_example_si \
	, g_si_function_ss_ul_t : g_example_si \
	, g_si_function_ss_f_t : g_example_si \
	, g_si_function_ss_d_t : g_example_si \
	, g_si_function_si_b_t : g_example_si \
	, g_si_function_si_c_t : g_example_si \
	, g_si_function_si_ss_t : g_example_si \
	, g_si_function_si_si_t : g_example_si \
	, g_si_function_si_sl_t : g_example_si \
	, g_si_function_si_ul_t : g_example_si \
	, g_si_function_si_f_t : g_example_si \
	, g_si_function_si_d_t : g_example_si \
	, g_si_function_sl_b_t : g_example_si \
	, g_si_function_sl_c_t : g_example_si \
	, g_si_function_sl_ss_t : g_example_si \
	, g_si_function_sl_si_t : g_example_si \
	, g_si_function_sl_sl_t : g_example_si \
	, g_si_function_sl_ul_t : g_example_si \
	, g_si_function_sl_f_t : g_example_si \
	, g_si_function_sl_d_t : g_example_si \
	, g_si_function_ul_b_t : g_example_si \
	, g_si_function_ul_c_t : g_example_si \
	, g_si_function_ul_ss_t : g_example_si \
	, g_si_function_ul_si_t : g_example_si \
	, g_si_function_ul_sl_t : g_example_si \
	, g_si_function_ul_ul_t : g_example_si \
	, g_si_function_ul_f_t : g_example_si \
	, g_si_function_ul_d_t : g_example_si \
	, g_si_function_f_b_t : g_example_si \
	, g_si_function_f_c_t : g_example_si \
	, g_si_function_f_ss_t : g_example_si \
	, g_si_function_f_si_t : g_example_si \
	, g_si_function_f_sl_t : g_example_si \
	, g_si_function_f_ul_t : g_example_si \
	, g_si_function_f_f_t : g_example_si \
	, g_si_function_f_d_t : g_example_si \
	, g_si_function_d_b_t : g_example_si \
	, g_si_function_d_c_t : g_example_si \
	, g_si_function_d_ss_t : g_example_si \
	, g_si_function_d_si_t : g_example_si \
	, g_si_function_d_sl_t : g_example_si \
	, g_si_function_d_ul_t : g_example_si \
	, g_si_function_d_f_t : g_example_si \
	, g_si_function_d_d_t : g_example_si \
	, g_sl_function_b_b_t : g_example_sl \
	, g_sl_function_b_c_t : g_example_sl \
	, g_sl_function_b_ss_t : g_example_sl \
	, g_sl_function_b_si_t : g_example_sl \
	, g_sl_function_b_sl_t : g_example_sl \
	, g_sl_function_b_ul_t : g_example_sl \
	, g_sl_function_b_f_t : g_example_sl \
	, g_sl_function_b_d_t : g_example_sl \
	, g_sl_function_c_b_t : g_example_sl \
	, g_sl_function_c_c_t : g_example_sl \
	, g_sl_function_c_ss_t : g_example_sl \
	, g_sl_function_c_si_t : g_example_sl \
	, g_sl_function_c_sl_t : g_example_sl \
	, g_sl_function_c_ul_t : g_example_sl \
	, g_sl_function_c_f_t : g_example_sl \
	, g_sl_function_c_d_t : g_example_sl \
	, g_sl_function_ss_b_t : g_example_sl \
	, g_sl_function_ss_c_t : g_example_sl \
	, g_sl_function_ss_ss_t : g_example_sl \
	, g_sl_function_ss_si_t : g_example_sl \
	, g_sl_function_ss_sl_t : g_example_sl \
	, g_sl_function_ss_ul_t : g_example_sl \
	, g_sl_function_ss_f_t : g_example_sl \
	, g_sl_function_ss_d_t : g_example_sl \
	, g_sl_function_si_b_t : g_example_sl \
	, g_sl_function_si_c_t : g_example_sl \
	, g_sl_function_si_ss_t : g_example_sl \
	, g_sl_function_si_si_t : g_example_sl \
	, g_sl_function_si_sl_t : g_example_sl \
	, g_sl_function_si_ul_t : g_example_sl \
	, g_sl_function_si_f_t : g_example_sl \
	, g_sl_function_si_d_t : g_example_sl \
	, g_sl_function_sl_b_t : g_example_sl \
	, g_sl_function_sl_c_t : g_example_sl \
	, g_sl_function_sl_ss_t : g_example_sl \
	, g_sl_function_sl_si_t : g_example_sl \
	, g_sl_function_sl_sl_t : g_example_sl \
	, g_sl_function_sl_ul_t : g_example_sl \
	, g_sl_function_sl_f_t : g_example_sl \
	, g_sl_function_sl_d_t : g_example_sl \
	, g_sl_function_ul_b_t : g_example_sl \
	, g_sl_function_ul_c_t : g_example_sl \
	, g_sl_function_ul_ss_t : g_example_sl \
	, g_sl_function_ul_si_t : g_example_sl \
	, g_sl_function_ul_sl_t : g_example_sl \
	, g_sl_function_ul_ul_t : g_example_sl \
	, g_sl_function_ul_f_t : g_example_sl \
	, g_sl_function_ul_d_t : g_example_sl \
	, g_sl_function_f_b_t : g_example_sl \
	, g_sl_function_f_c_t : g_example_sl \
	, g_sl_function_f_ss_t : g_example_sl \
	, g_sl_function_f_si_t : g_example_sl \
	, g_sl_function_f_sl_t : g_example_sl \
	, g_sl_function_f_ul_t : g_example_sl \
	, g_sl_function_f_f_t : g_example_sl \
	, g_sl_function_f_d_t : g_example_sl \
	, g_sl_function_d_b_t : g_example_sl \
	, g_sl_function_d_c_t : g_example_sl \
	, g_sl_function_d_ss_t : g_example_sl \
	, g_sl_function_d_si_t : g_example_sl \
	, g_sl_function_d_sl_t : g_example_sl \
	, g_sl_function_d_ul_t : g_example_sl \
	, g_sl_function_d_f_t : g_example_sl \
	, g_sl_function_d_d_t : g_example_sl \
	, g_ul_function_b_b_t : g_example_ul \
	, g_ul_function_b_c_t : g_example_ul \
	, g_ul_function_b_ss_t : g_example_ul \
	, g_ul_function_b_si_t : g_example_ul \
	, g_ul_function_b_sl_t : g_example_ul \
	, g_ul_function_b_ul_t : g_example_ul \
	, g_ul_function_b_f_t : g_example_ul \
	, g_ul_function_b_d_t : g_example_ul \
	, g_ul_function_c_b_t : g_example_ul \
	, g_ul_function_c_c_t : g_example_ul \
	, g_ul_function_c_ss_t : g_example_ul \
	, g_ul_function_c_si_t : g_example_ul \
	, g_ul_function_c_sl_t : g_example_ul \
	, g_ul_function_c_ul_t : g_example_ul \
	, g_ul_function_c_f_t : g_example_ul \
	, g_ul_function_c_d_t : g_example_ul \
	, g_ul_function_ss_b_t : g_example_ul \
	, g_ul_function_ss_c_t : g_example_ul \
	, g_ul_function_ss_ss_t : g_example_ul \
	, g_ul_function_ss_si_t : g_example_ul \
	, g_ul_function_ss_sl_t : g_example_ul \
	, g_ul_function_ss_ul_t : g_example_ul \
	, g_ul_function_ss_f_t : g_example_ul \
	, g_ul_function_ss_d_t : g_example_ul \
	, g_ul_function_si_b_t : g_example_ul \
	, g_ul_function_si_c_t : g_example_ul \
	, g_ul_function_si_ss_t : g_example_ul \
	, g_ul_function_si_si_t : g_example_ul \
	, g_ul_function_si_sl_t : g_example_ul \
	, g_ul_function_si_ul_t : g_example_ul \
	, g_ul_function_si_f_t : g_example_ul \
	, g_ul_function_si_d_t : g_example_ul \
	, g_ul_function_sl_b_t : g_example_ul \
	, g_ul_function_sl_c_t : g_example_ul \
	, g_ul_function_sl_ss_t : g_example_ul \
	, g_ul_function_sl_si_t : g_example_ul \
	, g_ul_function_sl_sl_t : g_example_ul \
	, g_ul_function_sl_ul_t : g_example_ul \
	, g_ul_function_sl_f_t : g_example_ul \
	, g_ul_function_sl_d_t : g_example_ul \
	, g_ul_function_ul_b_t : g_example_ul \
	, g_ul_function_ul_c_t : g_example_ul \
	, g_ul_function_ul_ss_t : g_example_ul \
	, g_ul_function_ul_si_t : g_example_ul \
	, g_ul_function_ul_sl_t : g_example_ul \
	, g_ul_function_ul_ul_t : g_example_ul \
	, g_ul_function_ul_f_t : g_example_ul \
	, g_ul_function_ul_d_t : g_example_ul \
	, g_ul_function_f_b_t : g_example_ul \
	, g_ul_function_f_c_t : g_example_ul \
	, g_ul_function_f_ss_t : g_example_ul \
	, g_ul_function_f_si_t : g_example_ul \
	, g_ul_function_f_sl_t : g_example_ul \
	, g_ul_function_f_ul_t : g_example_ul \
	, g_ul_function_f_f_t : g_example_ul \
	, g_ul_function_f_d_t : g_example_ul \
	, g_ul_function_d_b_t : g_example_ul \
	, g_ul_function_d_c_t : g_example_ul \
	, g_ul_function_d_ss_t : g_example_ul \
	, g_ul_function_d_si_t : g_example_ul \
	, g_ul_function_d_sl_t : g_example_ul \
	, g_ul_function_d_ul_t : g_example_ul \
	, g_ul_function_d_f_t : g_example_ul \
	, g_ul_function_d_d_t : g_example_ul \
	, g_f_function_b_b_t : g_example_f \
	, g_f_function_b_c_t : g_example_f \
	, g_f_function_b_ss_t : g_example_f \
	, g_f_function_b_si_t : g_example_f \
	, g_f_function_b_sl_t : g_example_f \
	, g_f_function_b_ul_t : g_example_f \
	, g_f_function_b_f_t : g_example_f \
	, g_f_function_b_d_t : g_example_f \
	, g_f_function_c_b_t : g_example_f \
	, g_f_function_c_c_t : g_example_f \
	, g_f_function_c_ss_t : g_example_f \
	, g_f_function_c_si_t : g_example_f \
	, g_f_function_c_sl_t : g_example_f \
	, g_f_function_c_ul_t : g_example_f \
	, g_f_function_c_f_t : g_example_f \
	, g_f_function_c_d_t : g_example_f \
	, g_f_function_ss_b_t : g_example_f \
	, g_f_function_ss_c_t : g_example_f \
	, g_f_function_ss_ss_t : g_example_f \
	, g_f_function_ss_si_t : g_example_f \
	, g_f_function_ss_sl_t : g_example_f \
	, g_f_function_ss_ul_t : g_example_f \
	, g_f_function_ss_f_t : g_example_f \
	, g_f_function_ss_d_t : g_example_f \
	, g_f_function_si_b_t : g_example_f \
	, g_f_function_si_c_t : g_example_f \
	, g_f_function_si_ss_t : g_example_f \
	, g_f_function_si_si_t : g_example_f \
	, g_f_function_si_sl_t : g_example_f \
	, g_f_function_si_ul_t : g_example_f \
	, g_f_function_si_f_t : g_example_f \
	, g_f_function_si_d_t : g_example_f \
	, g_f_function_sl_b_t : g_example_f \
	, g_f_function_sl_c_t : g_example_f \
	, g_f_function_sl_ss_t : g_example_f \
	, g_f_function_sl_si_t : g_example_f \
	, g_f_function_sl_sl_t : g_example_f \
	, g_f_function_sl_ul_t : g_example_f \
	, g_f_function_sl_f_t : g_example_f \
	, g_f_function_sl_d_t : g_example_f \
	, g_f_function_ul_b_t : g_example_f \
	, g_f_function_ul_c_t : g_example_f \
	, g_f_function_ul_ss_t : g_example_f \
	, g_f_function_ul_si_t : g_example_f \
	, g_f_function_ul_sl_t : g_example_f \
	, g_f_function_ul_ul_t : g_example_f \
	, g_f_function_ul_f_t : g_example_f \
	, g_f_function_ul_d_t : g_example_f \
	, g_f_function_f_b_t : g_example_f \
	, g_f_function_f_c_t : g_example_f \
	, g_f_function_f_ss_t : g_example_f \
	, g_f_function_f_si_t : g_example_f \
	, g_f_function_f_sl_t : g_example_f \
	, g_f_function_f_ul_t : g_example_f \
	, g_f_function_f_f_t : g_example_f \
	, g_f_function_f_d_t : g_example_f \
	, g_f_function_d_b_t : g_example_f \
	, g_f_function_d_c_t : g_example_f \
	, g_f_function_d_ss_t : g_example_f \
	, g_f_function_d_si_t : g_example_f \
	, g_f_function_d_sl_t : g_example_f \
	, g_f_function_d_ul_t : g_example_f \
	, g_f_function_d_f_t : g_example_f \
	, g_f_function_d_d_t : g_example_f \
	, g_d_function_b_b_t : g_example_d \
	, g_d_function_b_c_t : g_example_d \
	, g_d_function_b_ss_t : g_example_d \
	, g_d_function_b_si_t : g_example_d \
	, g_d_function_b_sl_t : g_example_d \
	, g_d_function_b_ul_t : g_example_d \
	, g_d_function_b_f_t : g_example_d \
	, g_d_function_b_d_t : g_example_d \
	, g_d_function_c_b_t : g_example_d \
	, g_d_function_c_c_t : g_example_d \
	, g_d_function_c_ss_t : g_example_d \
	, g_d_function_c_si_t : g_example_d \
	, g_d_function_c_sl_t : g_example_d \
	, g_d_function_c_ul_t : g_example_d \
	, g_d_function_c_f_t : g_example_d \
	, g_d_function_c_d_t : g_example_d \
	, g_d_function_ss_b_t : g_example_d \
	, g_d_function_ss_c_t : g_example_d \
	, g_d_function_ss_ss_t : g_example_d \
	, g_d_function_ss_si_t : g_example_d \
	, g_d_function_ss_sl_t : g_example_d \
	, g_d_function_ss_ul_t : g_example_d \
	, g_d_function_ss_f_t : g_example_d \
	, g_d_function_ss_d_t : g_example_d \
	, g_d_function_si_b_t : g_example_d \
	, g_d_function_si_c_t : g_example_d \
	, g_d_function_si_ss_t : g_example_d \
	, g_d_function_si_si_t : g_example_d \
	, g_d_function_si_sl_t : g_example_d \
	, g_d_function_si_ul_t : g_example_d \
	, g_d_function_si_f_t : g_example_d \
	, g_d_function_si_d_t : g_example_d \
	, g_d_function_sl_b_t : g_example_d \
	, g_d_function_sl_c_t : g_example_d \
	, g_d_function_sl_ss_t : g_example_d \
	, g_d_function_sl_si_t : g_example_d \
	, g_d_function_sl_sl_t : g_example_d \
	, g_d_function_sl_ul_t : g_example_d \
	, g_d_function_sl_f_t : g_example_d \
	, g_d_function_sl_d_t : g_example_d \
	, g_d_function_ul_b_t : g_example_d \
	, g_d_function_ul_c_t : g_example_d \
	, g_d_function_ul_ss_t : g_example_d \
	, g_d_function_ul_si_t : g_example_d \
	, g_d_function_ul_sl_t : g_example_d \
	, g_d_function_ul_ul_t : g_example_d \
	, g_d_function_ul_f_t : g_example_d \
	, g_d_function_ul_d_t : g_example_d \
	, g_d_function_f_b_t : g_example_d \
	, g_d_function_f_c_t : g_example_d \
	, g_d_function_f_ss_t : g_example_d \
	, g_d_function_f_si_t : g_example_d \
	, g_d_function_f_sl_t : g_example_d \
	, g_d_function_f_ul_t : g_example_d \
	, g_d_function_f_f_t : g_example_d \
	, g_d_function_f_d_t : g_example_d \
	, g_d_function_d_b_t : g_example_d \
	, g_d_function_d_c_t : g_example_d \
	, g_d_function_d_ss_t : g_example_d \
	, g_d_function_d_si_t : g_example_d \
	, g_d_function_d_sl_t : g_example_d \
	, g_d_function_d_ul_t : g_example_d \
	, g_d_function_d_f_t : g_example_d \
	, g_d_function_d_d_t : g_example_d \
)

#define g_function_arg1type(x) _Generic((x) \
	, g_function_b_t : g_example_b \
	, g_function_c_t : g_example_c \
	, g_function_ss_t : g_example_ss \
	, g_function_si_t : g_example_si \
	, g_function_sl_t : g_example_sl \
	, g_function_ul_t : g_example_ul \
	, g_function_f_t : g_example_f \
	, g_function_d_t : g_example_d \
	, g_b_function_b_t : g_example_b \
	, g_b_function_c_t : g_example_c \
	, g_b_function_ss_t : g_example_ss \
	, g_b_function_si_t : g_example_si \
	, g_b_function_sl_t : g_example_sl \
	, g_b_function_ul_t : g_example_ul \
	, g_b_function_f_t : g_example_f \
	, g_b_function_d_t : g_example_d \
	, g_c_function_b_t : g_example_b \
	, g_c_function_c_t : g_example_c \
	, g_c_function_ss_t : g_example_ss \
	, g_c_function_si_t : g_example_si \
	, g_c_function_sl_t : g_example_sl \
	, g_c_function_ul_t : g_example_ul \
	, g_c_function_f_t : g_example_f \
	, g_c_function_d_t : g_example_d \
	, g_ss_function_b_t : g_example_b \
	, g_ss_function_c_t : g_example_c \
	, g_ss_function_ss_t : g_example_ss \
	, g_ss_function_si_t : g_example_si \
	, g_ss_function_sl_t : g_example_sl \
	, g_ss_function_ul_t : g_example_ul \
	, g_ss_function_f_t : g_example_f \
	, g_ss_function_d_t : g_example_d \
	, g_si_function_b_t : g_example_b \
	, g_si_function_c_t : g_example_c \
	, g_si_function_ss_t : g_example_ss \
	, g_si_function_si_t : g_example_si \
	, g_si_function_sl_t : g_example_sl \
	, g_si_function_ul_t : g_example_ul \
	, g_si_function_f_t : g_example_f \
	, g_si_function_d_t : g_example_d \
	, g_sl_function_b_t : g_example_b \
	, g_sl_function_c_t : g_example_c \
	, g_sl_function_ss_t : g_example_ss \
	, g_sl_function_si_t : g_example_si \
	, g_sl_function_sl_t : g_example_sl \
	, g_sl_function_ul_t : g_example_ul \
	, g_sl_function_f_t : g_example_f \
	, g_sl_function_d_t : g_example_d \
	, g_ul_function_b_t : g_example_b \
	, g_ul_function_c_t : g_example_c \
	, g_ul_function_ss_t : g_example_ss \
	, g_ul_function_si_t : g_example_si \
	, g_ul_function_sl_t : g_example_sl \
	, g_ul_function_ul_t : g_example_ul \
	, g_ul_function_f_t : g_example_f \
	, g_ul_function_d_t : g_example_d \
	, g_f_function_b_t : g_example_b \
	, g_f_function_c_t : g_example_c \
	, g_f_function_ss_t : g_example_ss \
	, g_f_function_si_t : g_example_si \
	, g_f_function_sl_t : g_example_sl \
	, g_f_function_ul_t : g_example_ul \
	, g_f_function_f_t : g_example_f \
	, g_f_function_d_t : g_example_d \
	, g_d_function_b_t : g_example_b \
	, g_d_function_c_t : g_example_c \
	, g_d_function_ss_t : g_example_ss \
	, g_d_function_si_t : g_example_si \
	, g_d_function_sl_t : g_example_sl \
	, g_d_function_ul_t : g_example_ul \
	, g_d_function_f_t : g_example_f \
	, g_d_function_d_t : g_example_d \
	, g_b_function_b_b_t : g_example_b \
	, g_b_function_b_c_t : g_example_b \
	, g_b_function_b_ss_t : g_example_b \
	, g_b_function_b_si_t : g_example_b \
	, g_b_function_b_sl_t : g_example_b \
	, g_b_function_b_ul_t : g_example_b \
	, g_b_function_b_f_t : g_example_b \
	, g_b_function_b_d_t : g_example_b \
	, g_b_function_c_b_t : g_example_c \
	, g_b_function_c_c_t : g_example_c \
	, g_b_function_c_ss_t : g_example_c \
	, g_b_function_c_si_t : g_example_c \
	, g_b_function_c_sl_t : g_example_c \
	, g_b_function_c_ul_t : g_example_c \
	, g_b_function_c_f_t : g_example_c \
	, g_b_function_c_d_t : g_example_c \
	, g_b_function_ss_b_t : g_example_ss \
	, g_b_function_ss_c_t : g_example_ss \
	, g_b_function_ss_ss_t : g_example_ss \
	, g_b_function_ss_si_t : g_example_ss \
	, g_b_function_ss_sl_t : g_example_ss \
	, g_b_function_ss_ul_t : g_example_ss \
	, g_b_function_ss_f_t : g_example_ss \
	, g_b_function_ss_d_t : g_example_ss \
	, g_b_function_si_b_t : g_example_si \
	, g_b_function_si_c_t : g_example_si \
	, g_b_function_si_ss_t : g_example_si \
	, g_b_function_si_si_t : g_example_si \
	, g_b_function_si_sl_t : g_example_si \
	, g_b_function_si_ul_t : g_example_si \
	, g_b_function_si_f_t : g_example_si \
	, g_b_function_si_d_t : g_example_si \
	, g_b_function_sl_b_t : g_example_sl \
	, g_b_function_sl_c_t : g_example_sl \
	, g_b_function_sl_ss_t : g_example_sl \
	, g_b_function_sl_si_t : g_example_sl \
	, g_b_function_sl_sl_t : g_example_sl \
	, g_b_function_sl_ul_t : g_example_sl \
	, g_b_function_sl_f_t : g_example_sl \
	, g_b_function_sl_d_t : g_example_sl \
	, g_b_function_ul_b_t : g_example_ul \
	, g_b_function_ul_c_t : g_example_ul \
	, g_b_function_ul_ss_t : g_example_ul \
	, g_b_function_ul_si_t : g_example_ul \
	, g_b_function_ul_sl_t : g_example_ul \
	, g_b_function_ul_ul_t : g_example_ul \
	, g_b_function_ul_f_t : g_example_ul \
	, g_b_function_ul_d_t : g_example_ul \
	, g_b_function_f_b_t : g_example_f \
	, g_b_function_f_c_t : g_example_f \
	, g_b_function_f_ss_t : g_example_f \
	, g_b_function_f_si_t : g_example_f \
	, g_b_function_f_sl_t : g_example_f \
	, g_b_function_f_ul_t : g_example_f \
	, g_b_function_f_f_t : g_example_f \
	, g_b_function_f_d_t : g_example_f \
	, g_b_function_d_b_t : g_example_d \
	, g_b_function_d_c_t : g_example_d \
	, g_b_function_d_ss_t : g_example_d \
	, g_b_function_d_si_t : g_example_d \
	, g_b_function_d_sl_t : g_example_d \
	, g_b_function_d_ul_t : g_example_d \
	, g_b_function_d_f_t : g_example_d \
	, g_b_function_d_d_t : g_example_d \
	, g_c_function_b_b_t : g_example_b \
	, g_c_function_b_c_t : g_example_b \
	, g_c_function_b_ss_t : g_example_b \
	, g_c_function_b_si_t : g_example_b \
	, g_c_function_b_sl_t : g_example_b \
	, g_c_function_b_ul_t : g_example_b \
	, g_c_function_b_f_t : g_example_b \
	, g_c_function_b_d_t : g_example_b \
	, g_c_function_c_b_t : g_example_c \
	, g_c_function_c_c_t : g_example_c \
	, g_c_function_c_ss_t : g_example_c \
	, g_c_function_c_si_t : g_example_c \
	, g_c_function_c_sl_t : g_example_c \
	, g_c_function_c_ul_t : g_example_c \
	, g_c_function_c_f_t : g_example_c \
	, g_c_function_c_d_t : g_example_c \
	, g_c_function_ss_b_t : g_example_ss \
	, g_c_function_ss_c_t : g_example_ss \
	, g_c_function_ss_ss_t : g_example_ss \
	, g_c_function_ss_si_t : g_example_ss \
	, g_c_function_ss_sl_t : g_example_ss \
	, g_c_function_ss_ul_t : g_example_ss \
	, g_c_function_ss_f_t : g_example_ss \
	, g_c_function_ss_d_t : g_example_ss \
	, g_c_function_si_b_t : g_example_si \
	, g_c_function_si_c_t : g_example_si \
	, g_c_function_si_ss_t : g_example_si \
	, g_c_function_si_si_t : g_example_si \
	, g_c_function_si_sl_t : g_example_si \
	, g_c_function_si_ul_t : g_example_si \
	, g_c_function_si_f_t : g_example_si \
	, g_c_function_si_d_t : g_example_si \
	, g_c_function_sl_b_t : g_example_sl \
	, g_c_function_sl_c_t : g_example_sl \
	, g_c_function_sl_ss_t : g_example_sl \
	, g_c_function_sl_si_t : g_example_sl \
	, g_c_function_sl_sl_t : g_example_sl \
	, g_c_function_sl_ul_t : g_example_sl \
	, g_c_function_sl_f_t : g_example_sl \
	, g_c_function_sl_d_t : g_example_sl \
	, g_c_function_ul_b_t : g_example_ul \
	, g_c_function_ul_c_t : g_example_ul \
	, g_c_function_ul_ss_t : g_example_ul \
	, g_c_function_ul_si_t : g_example_ul \
	, g_c_function_ul_sl_t : g_example_ul \
	, g_c_function_ul_ul_t : g_example_ul \
	, g_c_function_ul_f_t : g_example_ul \
	, g_c_function_ul_d_t : g_example_ul \
	, g_c_function_f_b_t : g_example_f \
	, g_c_function_f_c_t : g_example_f \
	, g_c_function_f_ss_t : g_example_f \
	, g_c_function_f_si_t : g_example_f \
	, g_c_function_f_sl_t : g_example_f \
	, g_c_function_f_ul_t : g_example_f \
	, g_c_function_f_f_t : g_example_f \
	, g_c_function_f_d_t : g_example_f \
	, g_c_function_d_b_t : g_example_d \
	, g_c_function_d_c_t : g_example_d \
	, g_c_function_d_ss_t : g_example_d \
	, g_c_function_d_si_t : g_example_d \
	, g_c_function_d_sl_t : g_example_d \
	, g_c_function_d_ul_t : g_example_d \
	, g_c_function_d_f_t : g_example_d \
	, g_c_function_d_d_t : g_example_d \
	, g_ss_function_b_b_t : g_example_b \
	, g_ss_function_b_c_t : g_example_b \
	, g_ss_function_b_ss_t : g_example_b \
	, g_ss_function_b_si_t : g_example_b \
	, g_ss_function_b_sl_t : g_example_b \
	, g_ss_function_b_ul_t : g_example_b \
	, g_ss_function_b_f_t : g_example_b \
	, g_ss_function_b_d_t : g_example_b \
	, g_ss_function_c_b_t : g_example_c \
	, g_ss_function_c_c_t : g_example_c \
	, g_ss_function_c_ss_t : g_example_c \
	, g_ss_function_c_si_t : g_example_c \
	, g_ss_function_c_sl_t : g_example_c \
	, g_ss_function_c_ul_t : g_example_c \
	, g_ss_function_c_f_t : g_example_c \
	, g_ss_function_c_d_t : g_example_c \
	, g_ss_function_ss_b_t : g_example_ss \
	, g_ss_function_ss_c_t : g_example_ss \
	, g_ss_function_ss_ss_t : g_example_ss \
	, g_ss_function_ss_si_t : g_example_ss \
	, g_ss_function_ss_sl_t : g_example_ss \
	, g_ss_function_ss_ul_t : g_example_ss \
	, g_ss_function_ss_f_t : g_example_ss \
	, g_ss_function_ss_d_t : g_example_ss \
	, g_ss_function_si_b_t : g_example_si \
	, g_ss_function_si_c_t : g_example_si \
	, g_ss_function_si_ss_t : g_example_si \
	, g_ss_function_si_si_t : g_example_si \
	, g_ss_function_si_sl_t : g_example_si \
	, g_ss_function_si_ul_t : g_example_si \
	, g_ss_function_si_f_t : g_example_si \
	, g_ss_function_si_d_t : g_example_si \
	, g_ss_function_sl_b_t : g_example_sl \
	, g_ss_function_sl_c_t : g_example_sl \
	, g_ss_function_sl_ss_t : g_example_sl \
	, g_ss_function_sl_si_t : g_example_sl \
	, g_ss_function_sl_sl_t : g_example_sl \
	, g_ss_function_sl_ul_t : g_example_sl \
	, g_ss_function_sl_f_t : g_example_sl \
	, g_ss_function_sl_d_t : g_example_sl \
	, g_ss_function_ul_b_t : g_example_ul \
	, g_ss_function_ul_c_t : g_example_ul \
	, g_ss_function_ul_ss_t : g_example_ul \
	, g_ss_function_ul_si_t : g_example_ul \
	, g_ss_function_ul_sl_t : g_example_ul \
	, g_ss_function_ul_ul_t : g_example_ul \
	, g_ss_function_ul_f_t : g_example_ul \
	, g_ss_function_ul_d_t : g_example_ul \
	, g_ss_function_f_b_t : g_example_f \
	, g_ss_function_f_c_t : g_example_f \
	, g_ss_function_f_ss_t : g_example_f \
	, g_ss_function_f_si_t : g_example_f \
	, g_ss_function_f_sl_t : g_example_f \
	, g_ss_function_f_ul_t : g_example_f \
	, g_ss_function_f_f_t : g_example_f \
	, g_ss_function_f_d_t : g_example_f \
	, g_ss_function_d_b_t : g_example_d \
	, g_ss_function_d_c_t : g_example_d \
	, g_ss_function_d_ss_t : g_example_d \
	, g_ss_function_d_si_t : g_example_d \
	, g_ss_function_d_sl_t : g_example_d \
	, g_ss_function_d_ul_t : g_example_d \
	, g_ss_function_d_f_t : g_example_d \
	, g_ss_function_d_d_t : g_example_d \
	, g_si_function_b_b_t : g_example_b \
	, g_si_function_b_c_t : g_example_b \
	, g_si_function_b_ss_t : g_example_b \
	, g_si_function_b_si_t : g_example_b \
	, g_si_function_b_sl_t : g_example_b \
	, g_si_function_b_ul_t : g_example_b \
	, g_si_function_b_f_t : g_example_b \
	, g_si_function_b_d_t : g_example_b \
	, g_si_function_c_b_t : g_example_c \
	, g_si_function_c_c_t : g_example_c \
	, g_si_function_c_ss_t : g_example_c \
	, g_si_function_c_si_t : g_example_c \
	, g_si_function_c_sl_t : g_example_c \
	, g_si_function_c_ul_t : g_example_c \
	, g_si_function_c_f_t : g_example_c \
	, g_si_function_c_d_t : g_example_c \
	, g_si_function_ss_b_t : g_example_ss \
	, g_si_function_ss_c_t : g_example_ss \
	, g_si_function_ss_ss_t : g_example_ss \
	, g_si_function_ss_si_t : g_example_ss \
	, g_si_function_ss_sl_t : g_example_ss \
	, g_si_function_ss_ul_t : g_example_ss \
	, g_si_function_ss_f_t : g_example_ss \
	, g_si_function_ss_d_t : g_example_ss \
	, g_si_function_si_b_t : g_example_si \
	, g_si_function_si_c_t : g_example_si \
	, g_si_function_si_ss_t : g_example_si \
	, g_si_function_si_si_t : g_example_si \
	, g_si_function_si_sl_t : g_example_si \
	, g_si_function_si_ul_t : g_example_si \
	, g_si_function_si_f_t : g_example_si \
	, g_si_function_si_d_t : g_example_si \
	, g_si_function_sl_b_t : g_example_sl \
	, g_si_function_sl_c_t : g_example_sl \
	, g_si_function_sl_ss_t : g_example_sl \
	, g_si_function_sl_si_t : g_example_sl \
	, g_si_function_sl_sl_t : g_example_sl \
	, g_si_function_sl_ul_t : g_example_sl \
	, g_si_function_sl_f_t : g_example_sl \
	, g_si_function_sl_d_t : g_example_sl \
	, g_si_function_ul_b_t : g_example_ul \
	, g_si_function_ul_c_t : g_example_ul \
	, g_si_function_ul_ss_t : g_example_ul \
	, g_si_function_ul_si_t : g_example_ul \
	, g_si_function_ul_sl_t : g_example_ul \
	, g_si_function_ul_ul_t : g_example_ul \
	, g_si_function_ul_f_t : g_example_ul \
	, g_si_function_ul_d_t : g_example_ul \
	, g_si_function_f_b_t : g_example_f \
	, g_si_function_f_c_t : g_example_f \
	, g_si_function_f_ss_t : g_example_f \
	, g_si_function_f_si_t : g_example_f \
	, g_si_function_f_sl_t : g_example_f \
	, g_si_function_f_ul_t : g_example_f \
	, g_si_function_f_f_t : g_example_f \
	, g_si_function_f_d_t : g_example_f \
	, g_si_function_d_b_t : g_example_d \
	, g_si_function_d_c_t : g_example_d \
	, g_si_function_d_ss_t : g_example_d \
	, g_si_function_d_si_t : g_example_d \
	, g_si_function_d_sl_t : g_example_d \
	, g_si_function_d_ul_t : g_example_d \
	, g_si_function_d_f_t : g_example_d \
	, g_si_function_d_d_t : g_example_d \
	, g_sl_function_b_b_t : g_example_b \
	, g_sl_function_b_c_t : g_example_b \
	, g_sl_function_b_ss_t : g_example_b \
	, g_sl_function_b_si_t : g_example_b \
	, g_sl_function_b_sl_t : g_example_b \
	, g_sl_function_b_ul_t : g_example_b \
	, g_sl_function_b_f_t : g_example_b \
	, g_sl_function_b_d_t : g_example_b \
	, g_sl_function_c_b_t : g_example_c \
	, g_sl_function_c_c_t : g_example_c \
	, g_sl_function_c_ss_t : g_example_c \
	, g_sl_function_c_si_t : g_example_c \
	, g_sl_function_c_sl_t : g_example_c \
	, g_sl_function_c_ul_t : g_example_c \
	, g_sl_function_c_f_t : g_example_c \
	, g_sl_function_c_d_t : g_example_c \
	, g_sl_function_ss_b_t : g_example_ss \
	, g_sl_function_ss_c_t : g_example_ss \
	, g_sl_function_ss_ss_t : g_example_ss \
	, g_sl_function_ss_si_t : g_example_ss \
	, g_sl_function_ss_sl_t : g_example_ss \
	, g_sl_function_ss_ul_t : g_example_ss \
	, g_sl_function_ss_f_t : g_example_ss \
	, g_sl_function_ss_d_t : g_example_ss \
	, g_sl_function_si_b_t : g_example_si \
	, g_sl_function_si_c_t : g_example_si \
	, g_sl_function_si_ss_t : g_example_si \
	, g_sl_function_si_si_t : g_example_si \
	, g_sl_function_si_sl_t : g_example_si \
	, g_sl_function_si_ul_t : g_example_si \
	, g_sl_function_si_f_t : g_example_si \
	, g_sl_function_si_d_t : g_example_si \
	, g_sl_function_sl_b_t : g_example_sl \
	, g_sl_function_sl_c_t : g_example_sl \
	, g_sl_function_sl_ss_t : g_example_sl \
	, g_sl_function_sl_si_t : g_example_sl \
	, g_sl_function_sl_sl_t : g_example_sl \
	, g_sl_function_sl_ul_t : g_example_sl \
	, g_sl_function_sl_f_t : g_example_sl \
	, g_sl_function_sl_d_t : g_example_sl \
	, g_sl_function_ul_b_t : g_example_ul \
	, g_sl_function_ul_c_t : g_example_ul \
	, g_sl_function_ul_ss_t : g_example_ul \
	, g_sl_function_ul_si_t : g_example_ul \
	, g_sl_function_ul_sl_t : g_example_ul \
	, g_sl_function_ul_ul_t : g_example_ul \
	, g_sl_function_ul_f_t : g_example_ul \
	, g_sl_function_ul_d_t : g_example_ul \
	, g_sl_function_f_b_t : g_example_f \
	, g_sl_function_f_c_t : g_example_f \
	, g_sl_function_f_ss_t : g_example_f \
	, g_sl_function_f_si_t : g_example_f \
	, g_sl_function_f_sl_t : g_example_f \
	, g_sl_function_f_ul_t : g_example_f \
	, g_sl_function_f_f_t : g_example_f \
	, g_sl_function_f_d_t : g_example_f \
	, g_sl_function_d_b_t : g_example_d \
	, g_sl_function_d_c_t : g_example_d \
	, g_sl_function_d_ss_t : g_example_d \
	, g_sl_function_d_si_t : g_example_d \
	, g_sl_function_d_sl_t : g_example_d \
	, g_sl_function_d_ul_t : g_example_d \
	, g_sl_function_d_f_t : g_example_d \
	, g_sl_function_d_d_t : g_example_d \
	, g_ul_function_b_b_t : g_example_b \
	, g_ul_function_b_c_t : g_example_b \
	, g_ul_function_b_ss_t : g_example_b \
	, g_ul_function_b_si_t : g_example_b \
	, g_ul_function_b_sl_t : g_example_b \
	, g_ul_function_b_ul_t : g_example_b \
	, g_ul_function_b_f_t : g_example_b \
	, g_ul_function_b_d_t : g_example_b \
	, g_ul_function_c_b_t : g_example_c \
	, g_ul_function_c_c_t : g_example_c \
	, g_ul_function_c_ss_t : g_example_c \
	, g_ul_function_c_si_t : g_example_c \
	, g_ul_function_c_sl_t : g_example_c \
	, g_ul_function_c_ul_t : g_example_c \
	, g_ul_function_c_f_t : g_example_c \
	, g_ul_function_c_d_t : g_example_c \
	, g_ul_function_ss_b_t : g_example_ss \
	, g_ul_function_ss_c_t : g_example_ss \
	, g_ul_function_ss_ss_t : g_example_ss \
	, g_ul_function_ss_si_t : g_example_ss \
	, g_ul_function_ss_sl_t : g_example_ss \
	, g_ul_function_ss_ul_t : g_example_ss \
	, g_ul_function_ss_f_t : g_example_ss \
	, g_ul_function_ss_d_t : g_example_ss \
	, g_ul_function_si_b_t : g_example_si \
	, g_ul_function_si_c_t : g_example_si \
	, g_ul_function_si_ss_t : g_example_si \
	, g_ul_function_si_si_t : g_example_si \
	, g_ul_function_si_sl_t : g_example_si \
	, g_ul_function_si_ul_t : g_example_si \
	, g_ul_function_si_f_t : g_example_si \
	, g_ul_function_si_d_t : g_example_si \
	, g_ul_function_sl_b_t : g_example_sl \
	, g_ul_function_sl_c_t : g_example_sl \
	, g_ul_function_sl_ss_t : g_example_sl \
	, g_ul_function_sl_si_t : g_example_sl \
	, g_ul_function_sl_sl_t : g_example_sl \
	, g_ul_function_sl_ul_t : g_example_sl \
	, g_ul_function_sl_f_t : g_example_sl \
	, g_ul_function_sl_d_t : g_example_sl \
	, g_ul_function_ul_b_t : g_example_ul \
	, g_ul_function_ul_c_t : g_example_ul \
	, g_ul_function_ul_ss_t : g_example_ul \
	, g_ul_function_ul_si_t : g_example_ul \
	, g_ul_function_ul_sl_t : g_example_ul \
	, g_ul_function_ul_ul_t : g_example_ul \
	, g_ul_function_ul_f_t : g_example_ul \
	, g_ul_function_ul_d_t : g_example_ul \
	, g_ul_function_f_b_t : g_example_f \
	, g_ul_function_f_c_t : g_example_f \
	, g_ul_function_f_ss_t : g_example_f \
	, g_ul_function_f_si_t : g_example_f \
	, g_ul_function_f_sl_t : g_example_f \
	, g_ul_function_f_ul_t : g_example_f \
	, g_ul_function_f_f_t : g_example_f \
	, g_ul_function_f_d_t : g_example_f \
	, g_ul_function_d_b_t : g_example_d \
	, g_ul_function_d_c_t : g_example_d \
	, g_ul_function_d_ss_t : g_example_d \
	, g_ul_function_d_si_t : g_example_d \
	, g_ul_function_d_sl_t : g_example_d \
	, g_ul_function_d_ul_t : g_example_d \
	, g_ul_function_d_f_t : g_example_d \
	, g_ul_function_d_d_t : g_example_d \
	, g_f_function_b_b_t : g_example_b \
	, g_f_function_b_c_t : g_example_b \
	, g_f_function_b_ss_t : g_example_b \
	, g_f_function_b_si_t : g_example_b \
	, g_f_function_b_sl_t : g_example_b \
	, g_f_function_b_ul_t : g_example_b \
	, g_f_function_b_f_t : g_example_b \
	, g_f_function_b_d_t : g_example_b \
	, g_f_function_c_b_t : g_example_c \
	, g_f_function_c_c_t : g_example_c \
	, g_f_function_c_ss_t : g_example_c \
	, g_f_function_c_si_t : g_example_c \
	, g_f_function_c_sl_t : g_example_c \
	, g_f_function_c_ul_t : g_example_c \
	, g_f_function_c_f_t : g_example_c \
	, g_f_function_c_d_t : g_example_c \
	, g_f_function_ss_b_t : g_example_ss \
	, g_f_function_ss_c_t : g_example_ss \
	, g_f_function_ss_ss_t : g_example_ss \
	, g_f_function_ss_si_t : g_example_ss \
	, g_f_function_ss_sl_t : g_example_ss \
	, g_f_function_ss_ul_t : g_example_ss \
	, g_f_function_ss_f_t : g_example_ss \
	, g_f_function_ss_d_t : g_example_ss \
	, g_f_function_si_b_t : g_example_si \
	, g_f_function_si_c_t : g_example_si \
	, g_f_function_si_ss_t : g_example_si \
	, g_f_function_si_si_t : g_example_si \
	, g_f_function_si_sl_t : g_example_si \
	, g_f_function_si_ul_t : g_example_si \
	, g_f_function_si_f_t : g_example_si \
	, g_f_function_si_d_t : g_example_si \
	, g_f_function_sl_b_t : g_example_sl \
	, g_f_function_sl_c_t : g_example_sl \
	, g_f_function_sl_ss_t : g_example_sl \
	, g_f_function_sl_si_t : g_example_sl \
	, g_f_function_sl_sl_t : g_example_sl \
	, g_f_function_sl_ul_t : g_example_sl \
	, g_f_function_sl_f_t : g_example_sl \
	, g_f_function_sl_d_t : g_example_sl \
	, g_f_function_ul_b_t : g_example_ul \
	, g_f_function_ul_c_t : g_example_ul \
	, g_f_function_ul_ss_t : g_example_ul \
	, g_f_function_ul_si_t : g_example_ul \
	, g_f_function_ul_sl_t : g_example_ul \
	, g_f_function_ul_ul_t : g_example_ul \
	, g_f_function_ul_f_t : g_example_ul \
	, g_f_function_ul_d_t : g_example_ul \
	, g_f_function_f_b_t : g_example_f \
	, g_f_function_f_c_t : g_example_f \
	, g_f_function_f_ss_t : g_example_f \
	, g_f_function_f_si_t : g_example_f \
	, g_f_function_f_sl_t : g_example_f \
	, g_f_function_f_ul_t : g_example_f \
	, g_f_function_f_f_t : g_example_f \
	, g_f_function_f_d_t : g_example_f \
	, g_f_function_d_b_t : g_example_d \
	, g_f_function_d_c_t : g_example_d \
	, g_f_function_d_ss_t : g_example_d \
	, g_f_function_d_si_t : g_example_d \
	, g_f_function_d_sl_t : g_example_d \
	, g_f_function_d_ul_t : g_example_d \
	, g_f_function_d_f_t : g_example_d \
	, g_f_function_d_d_t : g_example_d \
	, g_d_function_b_b_t : g_example_b \
	, g_d_function_b_c_t : g_example_b \
	, g_d_function_b_ss_t : g_example_b \
	, g_d_function_b_si_t : g_example_b \
	, g_d_function_b_sl_t : g_example_b \
	, g_d_function_b_ul_t : g_example_b \
	, g_d_function_b_f_t : g_example_b \
	, g_d_function_b_d_t : g_example_b \
	, g_d_function_c_b_t : g_example_c \
	, g_d_function_c_c_t : g_example_c \
	, g_d_function_c_ss_t : g_example_c \
	, g_d_function_c_si_t : g_example_c \
	, g_d_function_c_sl_t : g_example_c \
	, g_d_function_c_ul_t : g_example_c \
	, g_d_function_c_f_t : g_example_c \
	, g_d_function_c_d_t : g_example_c \
	, g_d_function_ss_b_t : g_example_ss \
	, g_d_function_ss_c_t : g_example_ss \
	, g_d_function_ss_ss_t : g_example_ss \
	, g_d_function_ss_si_t : g_example_ss \
	, g_d_function_ss_sl_t : g_example_ss \
	, g_d_function_ss_ul_t : g_example_ss \
	, g_d_function_ss_f_t : g_example_ss \
	, g_d_function_ss_d_t : g_example_ss \
	, g_d_function_si_b_t : g_example_si \
	, g_d_function_si_c_t : g_example_si \
	, g_d_function_si_ss_t : g_example_si \
	, g_d_function_si_si_t : g_example_si \
	, g_d_function_si_sl_t : g_example_si \
	, g_d_function_si_ul_t : g_example_si \
	, g_d_function_si_f_t : g_example_si \
	, g_d_function_si_d_t : g_example_si \
	, g_d_function_sl_b_t : g_example_sl \
	, g_d_function_sl_c_t : g_example_sl \
	, g_d_function_sl_ss_t : g_example_sl \
	, g_d_function_sl_si_t : g_example_sl \
	, g_d_function_sl_sl_t : g_example_sl \
	, g_d_function_sl_ul_t : g_example_sl \
	, g_d_function_sl_f_t : g_example_sl \
	, g_d_function_sl_d_t : g_example_sl \
	, g_d_function_ul_b_t : g_example_ul \
	, g_d_function_ul_c_t : g_example_ul \
	, g_d_function_ul_ss_t : g_example_ul \
	, g_d_function_ul_si_t : g_example_ul \
	, g_d_function_ul_sl_t : g_example_ul \
	, g_d_function_ul_ul_t : g_example_ul \
	, g_d_function_ul_f_t : g_example_ul \
	, g_d_function_ul_d_t : g_example_ul \
	, g_d_function_f_b_t : g_example_f \
	, g_d_function_f_c_t : g_example_f \
	, g_d_function_f_ss_t : g_example_f \
	, g_d_function_f_si_t : g_example_f \
	, g_d_function_f_sl_t : g_example_f \
	, g_d_function_f_ul_t : g_example_f \
	, g_d_function_f_f_t : g_example_f \
	, g_d_function_f_d_t : g_example_f \
	, g_d_function_d_b_t : g_example_d \
	, g_d_function_d_c_t : g_example_d \
	, g_d_function_d_ss_t : g_example_d \
	, g_d_function_d_si_t : g_example_d \
	, g_d_function_d_sl_t : g_example_d \
	, g_d_function_d_ul_t : g_example_d \
	, g_d_function_d_f_t : g_example_d \
	, g_d_function_d_d_t : g_example_d \
)

#define g_function_arg2type(x) _Generic((x) \
	, g_b_function_b_b_t : g_example_b \
	, g_b_function_b_c_t : g_example_c \
	, g_b_function_b_ss_t : g_example_ss \
	, g_b_function_b_si_t : g_example_si \
	, g_b_function_b_sl_t : g_example_sl \
	, g_b_function_b_ul_t : g_example_ul \
	, g_b_function_b_f_t : g_example_f \
	, g_b_function_b_d_t : g_example_d \
	, g_b_function_c_b_t : g_example_b \
	, g_b_function_c_c_t : g_example_c \
	, g_b_function_c_ss_t : g_example_ss \
	, g_b_function_c_si_t : g_example_si \
	, g_b_function_c_sl_t : g_example_sl \
	, g_b_function_c_ul_t : g_example_ul \
	, g_b_function_c_f_t : g_example_f \
	, g_b_function_c_d_t : g_example_d \
	, g_b_function_ss_b_t : g_example_b \
	, g_b_function_ss_c_t : g_example_c \
	, g_b_function_ss_ss_t : g_example_ss \
	, g_b_function_ss_si_t : g_example_si \
	, g_b_function_ss_sl_t : g_example_sl \
	, g_b_function_ss_ul_t : g_example_ul \
	, g_b_function_ss_f_t : g_example_f \
	, g_b_function_ss_d_t : g_example_d \
	, g_b_function_si_b_t : g_example_b \
	, g_b_function_si_c_t : g_example_c \
	, g_b_function_si_ss_t : g_example_ss \
	, g_b_function_si_si_t : g_example_si \
	, g_b_function_si_sl_t : g_example_sl \
	, g_b_function_si_ul_t : g_example_ul \
	, g_b_function_si_f_t : g_example_f \
	, g_b_function_si_d_t : g_example_d \
	, g_b_function_sl_b_t : g_example_b \
	, g_b_function_sl_c_t : g_example_c \
	, g_b_function_sl_ss_t : g_example_ss \
	, g_b_function_sl_si_t : g_example_si \
	, g_b_function_sl_sl_t : g_example_sl \
	, g_b_function_sl_ul_t : g_example_ul \
	, g_b_function_sl_f_t : g_example_f \
	, g_b_function_sl_d_t : g_example_d \
	, g_b_function_ul_b_t : g_example_b \
	, g_b_function_ul_c_t : g_example_c \
	, g_b_function_ul_ss_t : g_example_ss \
	, g_b_function_ul_si_t : g_example_si \
	, g_b_function_ul_sl_t : g_example_sl \
	, g_b_function_ul_ul_t : g_example_ul \
	, g_b_function_ul_f_t : g_example_f \
	, g_b_function_ul_d_t : g_example_d \
	, g_b_function_f_b_t : g_example_b \
	, g_b_function_f_c_t : g_example_c \
	, g_b_function_f_ss_t : g_example_ss \
	, g_b_function_f_si_t : g_example_si \
	, g_b_function_f_sl_t : g_example_sl \
	, g_b_function_f_ul_t : g_example_ul \
	, g_b_function_f_f_t : g_example_f \
	, g_b_function_f_d_t : g_example_d \
	, g_b_function_d_b_t : g_example_b \
	, g_b_function_d_c_t : g_example_c \
	, g_b_function_d_ss_t : g_example_ss \
	, g_b_function_d_si_t : g_example_si \
	, g_b_function_d_sl_t : g_example_sl \
	, g_b_function_d_ul_t : g_example_ul \
	, g_b_function_d_f_t : g_example_f \
	, g_b_function_d_d_t : g_example_d \
	, g_c_function_b_b_t : g_example_b \
	, g_c_function_b_c_t : g_example_c \
	, g_c_function_b_ss_t : g_example_ss \
	, g_c_function_b_si_t : g_example_si \
	, g_c_function_b_sl_t : g_example_sl \
	, g_c_function_b_ul_t : g_example_ul \
	, g_c_function_b_f_t : g_example_f \
	, g_c_function_b_d_t : g_example_d \
	, g_c_function_c_b_t : g_example_b \
	, g_c_function_c_c_t : g_example_c \
	, g_c_function_c_ss_t : g_example_ss \
	, g_c_function_c_si_t : g_example_si \
	, g_c_function_c_sl_t : g_example_sl \
	, g_c_function_c_ul_t : g_example_ul \
	, g_c_function_c_f_t : g_example_f \
	, g_c_function_c_d_t : g_example_d \
	, g_c_function_ss_b_t : g_example_b \
	, g_c_function_ss_c_t : g_example_c \
	, g_c_function_ss_ss_t : g_example_ss \
	, g_c_function_ss_si_t : g_example_si \
	, g_c_function_ss_sl_t : g_example_sl \
	, g_c_function_ss_ul_t : g_example_ul \
	, g_c_function_ss_f_t : g_example_f \
	, g_c_function_ss_d_t : g_example_d \
	, g_c_function_si_b_t : g_example_b \
	, g_c_function_si_c_t : g_example_c \
	, g_c_function_si_ss_t : g_example_ss \
	, g_c_function_si_si_t : g_example_si \
	, g_c_function_si_sl_t : g_example_sl \
	, g_c_function_si_ul_t : g_example_ul \
	, g_c_function_si_f_t : g_example_f \
	, g_c_function_si_d_t : g_example_d \
	, g_c_function_sl_b_t : g_example_b \
	, g_c_function_sl_c_t : g_example_c \
	, g_c_function_sl_ss_t : g_example_ss \
	, g_c_function_sl_si_t : g_example_si \
	, g_c_function_sl_sl_t : g_example_sl \
	, g_c_function_sl_ul_t : g_example_ul \
	, g_c_function_sl_f_t : g_example_f \
	, g_c_function_sl_d_t : g_example_d \
	, g_c_function_ul_b_t : g_example_b \
	, g_c_function_ul_c_t : g_example_c \
	, g_c_function_ul_ss_t : g_example_ss \
	, g_c_function_ul_si_t : g_example_si \
	, g_c_function_ul_sl_t : g_example_sl \
	, g_c_function_ul_ul_t : g_example_ul \
	, g_c_function_ul_f_t : g_example_f \
	, g_c_function_ul_d_t : g_example_d \
	, g_c_function_f_b_t : g_example_b \
	, g_c_function_f_c_t : g_example_c \
	, g_c_function_f_ss_t : g_example_ss \
	, g_c_function_f_si_t : g_example_si \
	, g_c_function_f_sl_t : g_example_sl \
	, g_c_function_f_ul_t : g_example_ul \
	, g_c_function_f_f_t : g_example_f \
	, g_c_function_f_d_t : g_example_d \
	, g_c_function_d_b_t : g_example_b \
	, g_c_function_d_c_t : g_example_c \
	, g_c_function_d_ss_t : g_example_ss \
	, g_c_function_d_si_t : g_example_si \
	, g_c_function_d_sl_t : g_example_sl \
	, g_c_function_d_ul_t : g_example_ul \
	, g_c_function_d_f_t : g_example_f \
	, g_c_function_d_d_t : g_example_d \
	, g_ss_function_b_b_t : g_example_b \
	, g_ss_function_b_c_t : g_example_c \
	, g_ss_function_b_ss_t : g_example_ss \
	, g_ss_function_b_si_t : g_example_si \
	, g_ss_function_b_sl_t : g_example_sl \
	, g_ss_function_b_ul_t : g_example_ul \
	, g_ss_function_b_f_t : g_example_f \
	, g_ss_function_b_d_t : g_example_d \
	, g_ss_function_c_b_t : g_example_b \
	, g_ss_function_c_c_t : g_example_c \
	, g_ss_function_c_ss_t : g_example_ss \
	, g_ss_function_c_si_t : g_example_si \
	, g_ss_function_c_sl_t : g_example_sl \
	, g_ss_function_c_ul_t : g_example_ul \
	, g_ss_function_c_f_t : g_example_f \
	, g_ss_function_c_d_t : g_example_d \
	, g_ss_function_ss_b_t : g_example_b \
	, g_ss_function_ss_c_t : g_example_c \
	, g_ss_function_ss_ss_t : g_example_ss \
	, g_ss_function_ss_si_t : g_example_si \
	, g_ss_function_ss_sl_t : g_example_sl \
	, g_ss_function_ss_ul_t : g_example_ul \
	, g_ss_function_ss_f_t : g_example_f \
	, g_ss_function_ss_d_t : g_example_d \
	, g_ss_function_si_b_t : g_example_b \
	, g_ss_function_si_c_t : g_example_c \
	, g_ss_function_si_ss_t : g_example_ss \
	, g_ss_function_si_si_t : g_example_si \
	, g_ss_function_si_sl_t : g_example_sl \
	, g_ss_function_si_ul_t : g_example_ul \
	, g_ss_function_si_f_t : g_example_f \
	, g_ss_function_si_d_t : g_example_d \
	, g_ss_function_sl_b_t : g_example_b \
	, g_ss_function_sl_c_t : g_example_c \
	, g_ss_function_sl_ss_t : g_example_ss \
	, g_ss_function_sl_si_t : g_example_si \
	, g_ss_function_sl_sl_t : g_example_sl \
	, g_ss_function_sl_ul_t : g_example_ul \
	, g_ss_function_sl_f_t : g_example_f \
	, g_ss_function_sl_d_t : g_example_d \
	, g_ss_function_ul_b_t : g_example_b \
	, g_ss_function_ul_c_t : g_example_c \
	, g_ss_function_ul_ss_t : g_example_ss \
	, g_ss_function_ul_si_t : g_example_si \
	, g_ss_function_ul_sl_t : g_example_sl \
	, g_ss_function_ul_ul_t : g_example_ul \
	, g_ss_function_ul_f_t : g_example_f \
	, g_ss_function_ul_d_t : g_example_d \
	, g_ss_function_f_b_t : g_example_b \
	, g_ss_function_f_c_t : g_example_c \
	, g_ss_function_f_ss_t : g_example_ss \
	, g_ss_function_f_si_t : g_example_si \
	, g_ss_function_f_sl_t : g_example_sl \
	, g_ss_function_f_ul_t : g_example_ul \
	, g_ss_function_f_f_t : g_example_f \
	, g_ss_function_f_d_t : g_example_d \
	, g_ss_function_d_b_t : g_example_b \
	, g_ss_function_d_c_t : g_example_c \
	, g_ss_function_d_ss_t : g_example_ss \
	, g_ss_function_d_si_t : g_example_si \
	, g_ss_function_d_sl_t : g_example_sl \
	, g_ss_function_d_ul_t : g_example_ul \
	, g_ss_function_d_f_t : g_example_f \
	, g_ss_function_d_d_t : g_example_d \
	, g_si_function_b_b_t : g_example_b \
	, g_si_function_b_c_t : g_example_c \
	, g_si_function_b_ss_t : g_example_ss \
	, g_si_function_b_si_t : g_example_si \
	, g_si_function_b_sl_t : g_example_sl \
	, g_si_function_b_ul_t : g_example_ul \
	, g_si_function_b_f_t : g_example_f \
	, g_si_function_b_d_t : g_example_d \
	, g_si_function_c_b_t : g_example_b \
	, g_si_function_c_c_t : g_example_c \
	, g_si_function_c_ss_t : g_example_ss \
	, g_si_function_c_si_t : g_example_si \
	, g_si_function_c_sl_t : g_example_sl \
	, g_si_function_c_ul_t : g_example_ul \
	, g_si_function_c_f_t : g_example_f \
	, g_si_function_c_d_t : g_example_d \
	, g_si_function_ss_b_t : g_example_b \
	, g_si_function_ss_c_t : g_example_c \
	, g_si_function_ss_ss_t : g_example_ss \
	, g_si_function_ss_si_t : g_example_si \
	, g_si_function_ss_sl_t : g_example_sl \
	, g_si_function_ss_ul_t : g_example_ul \
	, g_si_function_ss_f_t : g_example_f \
	, g_si_function_ss_d_t : g_example_d \
	, g_si_function_si_b_t : g_example_b \
	, g_si_function_si_c_t : g_example_c \
	, g_si_function_si_ss_t : g_example_ss \
	, g_si_function_si_si_t : g_example_si \
	, g_si_function_si_sl_t : g_example_sl \
	, g_si_function_si_ul_t : g_example_ul \
	, g_si_function_si_f_t : g_example_f \
	, g_si_function_si_d_t : g_example_d \
	, g_si_function_sl_b_t : g_example_b \
	, g_si_function_sl_c_t : g_example_c \
	, g_si_function_sl_ss_t : g_example_ss \
	, g_si_function_sl_si_t : g_example_si \
	, g_si_function_sl_sl_t : g_example_sl \
	, g_si_function_sl_ul_t : g_example_ul \
	, g_si_function_sl_f_t : g_example_f \
	, g_si_function_sl_d_t : g_example_d \
	, g_si_function_ul_b_t : g_example_b \
	, g_si_function_ul_c_t : g_example_c \
	, g_si_function_ul_ss_t : g_example_ss \
	, g_si_function_ul_si_t : g_example_si \
	, g_si_function_ul_sl_t : g_example_sl \
	, g_si_function_ul_ul_t : g_example_ul \
	, g_si_function_ul_f_t : g_example_f \
	, g_si_function_ul_d_t : g_example_d \
	, g_si_function_f_b_t : g_example_b \
	, g_si_function_f_c_t : g_example_c \
	, g_si_function_f_ss_t : g_example_ss \
	, g_si_function_f_si_t : g_example_si \
	, g_si_function_f_sl_t : g_example_sl \
	, g_si_function_f_ul_t : g_example_ul \
	, g_si_function_f_f_t : g_example_f \
	, g_si_function_f_d_t : g_example_d \
	, g_si_function_d_b_t : g_example_b \
	, g_si_function_d_c_t : g_example_c \
	, g_si_function_d_ss_t : g_example_ss \
	, g_si_function_d_si_t : g_example_si \
	, g_si_function_d_sl_t : g_example_sl \
	, g_si_function_d_ul_t : g_example_ul \
	, g_si_function_d_f_t : g_example_f \
	, g_si_function_d_d_t : g_example_d \
	, g_sl_function_b_b_t : g_example_b \
	, g_sl_function_b_c_t : g_example_c \
	, g_sl_function_b_ss_t : g_example_ss \
	, g_sl_function_b_si_t : g_example_si \
	, g_sl_function_b_sl_t : g_example_sl \
	, g_sl_function_b_ul_t : g_example_ul \
	, g_sl_function_b_f_t : g_example_f \
	, g_sl_function_b_d_t : g_example_d \
	, g_sl_function_c_b_t : g_example_b \
	, g_sl_function_c_c_t : g_example_c \
	, g_sl_function_c_ss_t : g_example_ss \
	, g_sl_function_c_si_t : g_example_si \
	, g_sl_function_c_sl_t : g_example_sl \
	, g_sl_function_c_ul_t : g_example_ul \
	, g_sl_function_c_f_t : g_example_f \
	, g_sl_function_c_d_t : g_example_d \
	, g_sl_function_ss_b_t : g_example_b \
	, g_sl_function_ss_c_t : g_example_c \
	, g_sl_function_ss_ss_t : g_example_ss \
	, g_sl_function_ss_si_t : g_example_si \
	, g_sl_function_ss_sl_t : g_example_sl \
	, g_sl_function_ss_ul_t : g_example_ul \
	, g_sl_function_ss_f_t : g_example_f \
	, g_sl_function_ss_d_t : g_example_d \
	, g_sl_function_si_b_t : g_example_b \
	, g_sl_function_si_c_t : g_example_c \
	, g_sl_function_si_ss_t : g_example_ss \
	, g_sl_function_si_si_t : g_example_si \
	, g_sl_function_si_sl_t : g_example_sl \
	, g_sl_function_si_ul_t : g_example_ul \
	, g_sl_function_si_f_t : g_example_f \
	, g_sl_function_si_d_t : g_example_d \
	, g_sl_function_sl_b_t : g_example_b \
	, g_sl_function_sl_c_t : g_example_c \
	, g_sl_function_sl_ss_t : g_example_ss \
	, g_sl_function_sl_si_t : g_example_si \
	, g_sl_function_sl_sl_t : g_example_sl \
	, g_sl_function_sl_ul_t : g_example_ul \
	, g_sl_function_sl_f_t : g_example_f \
	, g_sl_function_sl_d_t : g_example_d \
	, g_sl_function_ul_b_t : g_example_b \
	, g_sl_function_ul_c_t : g_example_c \
	, g_sl_function_ul_ss_t : g_example_ss \
	, g_sl_function_ul_si_t : g_example_si \
	, g_sl_function_ul_sl_t : g_example_sl \
	, g_sl_function_ul_ul_t : g_example_ul \
	, g_sl_function_ul_f_t : g_example_f \
	, g_sl_function_ul_d_t : g_example_d \
	, g_sl_function_f_b_t : g_example_b \
	, g_sl_function_f_c_t : g_example_c \
	, g_sl_function_f_ss_t : g_example_ss \
	, g_sl_function_f_si_t : g_example_si \
	, g_sl_function_f_sl_t : g_example_sl \
	, g_sl_function_f_ul_t : g_example_ul \
	, g_sl_function_f_f_t : g_example_f \
	, g_sl_function_f_d_t : g_example_d \
	, g_sl_function_d_b_t : g_example_b \
	, g_sl_function_d_c_t : g_example_c \
	, g_sl_function_d_ss_t : g_example_ss \
	, g_sl_function_d_si_t : g_example_si \
	, g_sl_function_d_sl_t : g_example_sl \
	, g_sl_function_d_ul_t : g_example_ul \
	, g_sl_function_d_f_t : g_example_f \
	, g_sl_function_d_d_t : g_example_d \
	, g_ul_function_b_b_t : g_example_b \
	, g_ul_function_b_c_t : g_example_c \
	, g_ul_function_b_ss_t : g_example_ss \
	, g_ul_function_b_si_t : g_example_si \
	, g_ul_function_b_sl_t : g_example_sl \
	, g_ul_function_b_ul_t : g_example_ul \
	, g_ul_function_b_f_t : g_example_f \
	, g_ul_function_b_d_t : g_example_d \
	, g_ul_function_c_b_t : g_example_b \
	, g_ul_function_c_c_t : g_example_c \
	, g_ul_function_c_ss_t : g_example_ss \
	, g_ul_function_c_si_t : g_example_si \
	, g_ul_function_c_sl_t : g_example_sl \
	, g_ul_function_c_ul_t : g_example_ul \
	, g_ul_function_c_f_t : g_example_f \
	, g_ul_function_c_d_t : g_example_d \
	, g_ul_function_ss_b_t : g_example_b \
	, g_ul_function_ss_c_t : g_example_c \
	, g_ul_function_ss_ss_t : g_example_ss \
	, g_ul_function_ss_si_t : g_example_si \
	, g_ul_function_ss_sl_t : g_example_sl \
	, g_ul_function_ss_ul_t : g_example_ul \
	, g_ul_function_ss_f_t : g_example_f \
	, g_ul_function_ss_d_t : g_example_d \
	, g_ul_function_si_b_t : g_example_b \
	, g_ul_function_si_c_t : g_example_c \
	, g_ul_function_si_ss_t : g_example_ss \
	, g_ul_function_si_si_t : g_example_si \
	, g_ul_function_si_sl_t : g_example_sl \
	, g_ul_function_si_ul_t : g_example_ul \
	, g_ul_function_si_f_t : g_example_f \
	, g_ul_function_si_d_t : g_example_d \
	, g_ul_function_sl_b_t : g_example_b \
	, g_ul_function_sl_c_t : g_example_c \
	, g_ul_function_sl_ss_t : g_example_ss \
	, g_ul_function_sl_si_t : g_example_si \
	, g_ul_function_sl_sl_t : g_example_sl \
	, g_ul_function_sl_ul_t : g_example_ul \
	, g_ul_function_sl_f_t : g_example_f \
	, g_ul_function_sl_d_t : g_example_d \
	, g_ul_function_ul_b_t : g_example_b \
	, g_ul_function_ul_c_t : g_example_c \
	, g_ul_function_ul_ss_t : g_example_ss \
	, g_ul_function_ul_si_t : g_example_si \
	, g_ul_function_ul_sl_t : g_example_sl \
	, g_ul_function_ul_ul_t : g_example_ul \
	, g_ul_function_ul_f_t : g_example_f \
	, g_ul_function_ul_d_t : g_example_d \
	, g_ul_function_f_b_t : g_example_b \
	, g_ul_function_f_c_t : g_example_c \
	, g_ul_function_f_ss_t : g_example_ss \
	, g_ul_function_f_si_t : g_example_si \
	, g_ul_function_f_sl_t : g_example_sl \
	, g_ul_function_f_ul_t : g_example_ul \
	, g_ul_function_f_f_t : g_example_f \
	, g_ul_function_f_d_t : g_example_d \
	, g_ul_function_d_b_t : g_example_b \
	, g_ul_function_d_c_t : g_example_c \
	, g_ul_function_d_ss_t : g_example_ss \
	, g_ul_function_d_si_t : g_example_si \
	, g_ul_function_d_sl_t : g_example_sl \
	, g_ul_function_d_ul_t : g_example_ul \
	, g_ul_function_d_f_t : g_example_f \
	, g_ul_function_d_d_t : g_example_d \
	, g_f_function_b_b_t : g_example_b \
	, g_f_function_b_c_t : g_example_c \
	, g_f_function_b_ss_t : g_example_ss \
	, g_f_function_b_si_t : g_example_si \
	, g_f_function_b_sl_t : g_example_sl \
	, g_f_function_b_ul_t : g_example_ul \
	, g_f_function_b_f_t : g_example_f \
	, g_f_function_b_d_t : g_example_d \
	, g_f_function_c_b_t : g_example_b \
	, g_f_function_c_c_t : g_example_c \
	, g_f_function_c_ss_t : g_example_ss \
	, g_f_function_c_si_t : g_example_si \
	, g_f_function_c_sl_t : g_example_sl \
	, g_f_function_c_ul_t : g_example_ul \
	, g_f_function_c_f_t : g_example_f \
	, g_f_function_c_d_t : g_example_d \
	, g_f_function_ss_b_t : g_example_b \
	, g_f_function_ss_c_t : g_example_c \
	, g_f_function_ss_ss_t : g_example_ss \
	, g_f_function_ss_si_t : g_example_si \
	, g_f_function_ss_sl_t : g_example_sl \
	, g_f_function_ss_ul_t : g_example_ul \
	, g_f_function_ss_f_t : g_example_f \
	, g_f_function_ss_d_t : g_example_d \
	, g_f_function_si_b_t : g_example_b \
	, g_f_function_si_c_t : g_example_c \
	, g_f_function_si_ss_t : g_example_ss \
	, g_f_function_si_si_t : g_example_si \
	, g_f_function_si_sl_t : g_example_sl \
	, g_f_function_si_ul_t : g_example_ul \
	, g_f_function_si_f_t : g_example_f \
	, g_f_function_si_d_t : g_example_d \
	, g_f_function_sl_b_t : g_example_b \
	, g_f_function_sl_c_t : g_example_c \
	, g_f_function_sl_ss_t : g_example_ss \
	, g_f_function_sl_si_t : g_example_si \
	, g_f_function_sl_sl_t : g_example_sl \
	, g_f_function_sl_ul_t : g_example_ul \
	, g_f_function_sl_f_t : g_example_f \
	, g_f_function_sl_d_t : g_example_d \
	, g_f_function_ul_b_t : g_example_b \
	, g_f_function_ul_c_t : g_example_c \
	, g_f_function_ul_ss_t : g_example_ss \
	, g_f_function_ul_si_t : g_example_si \
	, g_f_function_ul_sl_t : g_example_sl \
	, g_f_function_ul_ul_t : g_example_ul \
	, g_f_function_ul_f_t : g_example_f \
	, g_f_function_ul_d_t : g_example_d \
	, g_f_function_f_b_t : g_example_b \
	, g_f_function_f_c_t : g_example_c \
	, g_f_function_f_ss_t : g_example_ss \
	, g_f_function_f_si_t : g_example_si \
	, g_f_function_f_sl_t : g_example_sl \
	, g_f_function_f_ul_t : g_example_ul \
	, g_f_function_f_f_t : g_example_f \
	, g_f_function_f_d_t : g_example_d \
	, g_f_function_d_b_t : g_example_b \
	, g_f_function_d_c_t : g_example_c \
	, g_f_function_d_ss_t : g_example_ss \
	, g_f_function_d_si_t : g_example_si \
	, g_f_function_d_sl_t : g_example_sl \
	, g_f_function_d_ul_t : g_example_ul \
	, g_f_function_d_f_t : g_example_f \
	, g_f_function_d_d_t : g_example_d \
	, g_d_function_b_b_t : g_example_b \
	, g_d_function_b_c_t : g_example_c \
	, g_d_function_b_ss_t : g_example_ss \
	, g_d_function_b_si_t : g_example_si \
	, g_d_function_b_sl_t : g_example_sl \
	, g_d_function_b_ul_t : g_example_ul \
	, g_d_function_b_f_t : g_example_f \
	, g_d_function_b_d_t : g_example_d \
	, g_d_function_c_b_t : g_example_b \
	, g_d_function_c_c_t : g_example_c \
	, g_d_function_c_ss_t : g_example_ss \
	, g_d_function_c_si_t : g_example_si \
	, g_d_function_c_sl_t : g_example_sl \
	, g_d_function_c_ul_t : g_example_ul \
	, g_d_function_c_f_t : g_example_f \
	, g_d_function_c_d_t : g_example_d \
	, g_d_function_ss_b_t : g_example_b \
	, g_d_function_ss_c_t : g_example_c \
	, g_d_function_ss_ss_t : g_example_ss \
	, g_d_function_ss_si_t : g_example_si \
	, g_d_function_ss_sl_t : g_example_sl \
	, g_d_function_ss_ul_t : g_example_ul \
	, g_d_function_ss_f_t : g_example_f \
	, g_d_function_ss_d_t : g_example_d \
	, g_d_function_si_b_t : g_example_b \
	, g_d_function_si_c_t : g_example_c \
	, g_d_function_si_ss_t : g_example_ss \
	, g_d_function_si_si_t : g_example_si \
	, g_d_function_si_sl_t : g_example_sl \
	, g_d_function_si_ul_t : g_example_ul \
	, g_d_function_si_f_t : g_example_f \
	, g_d_function_si_d_t : g_example_d \
	, g_d_function_sl_b_t : g_example_b \
	, g_d_function_sl_c_t : g_example_c \
	, g_d_function_sl_ss_t : g_example_ss \
	, g_d_function_sl_si_t : g_example_si \
	, g_d_function_sl_sl_t : g_example_sl \
	, g_d_function_sl_ul_t : g_example_ul \
	, g_d_function_sl_f_t : g_example_f \
	, g_d_function_sl_d_t : g_example_d \
	, g_d_function_ul_b_t : g_example_b \
	, g_d_function_ul_c_t : g_example_c \
	, g_d_function_ul_ss_t : g_example_ss \
	, g_d_function_ul_si_t : g_example_si \
	, g_d_function_ul_sl_t : g_example_sl \
	, g_d_function_ul_ul_t : g_example_ul \
	, g_d_function_ul_f_t : g_example_f \
	, g_d_function_ul_d_t : g_example_d \
	, g_d_function_f_b_t : g_example_b \
	, g_d_function_f_c_t : g_example_c \
	, g_d_function_f_ss_t : g_example_ss \
	, g_d_function_f_si_t : g_example_si \
	, g_d_function_f_sl_t : g_example_sl \
	, g_d_function_f_ul_t : g_example_ul \
	, g_d_function_f_f_t : g_example_f \
	, g_d_function_f_d_t : g_example_d \
	, g_d_function_d_b_t : g_example_b \
	, g_d_function_d_c_t : g_example_c \
	, g_d_function_d_ss_t : g_example_ss \
	, g_d_function_d_si_t : g_example_si \
	, g_d_function_d_sl_t : g_example_sl \
	, g_d_function_d_ul_t : g_example_ul \
	, g_d_function_d_f_t : g_example_f \
	, g_d_function_d_d_t : g_example_d \
)
#define g_is_eq(x,y) _Generic((x) \
	, bool : _Generic((y) \
		, bool : g_is_eq_b_b \
		, char : g_is_eq_b_c \
		, double : g_is_eq_b_d \
		, float : g_is_eq_b_f \
		, int : g_is_eq_b_si \
		, long : g_is_eq_b_sl \
		, short : g_is_eq_b_ss \
		, unsigned long : g_is_eq_b_ul \
	) \
	, char : _Generic((y) \
		, bool : g_is_eq_c_b \
		, char : g_is_eq_c_c \
		, double : g_is_eq_c_d \
		, float : g_is_eq_c_f \
		, int : g_is_eq_c_si \
		, long : g_is_eq_c_sl \
		, short : g_is_eq_c_ss \
		, unsigned long : g_is_eq_c_ul \
	) \
	, double : _Generic((y) \
		, bool : g_is_eq_d_b \
		, char : g_is_eq_d_c \
		, double : g_is_eq_d_d \
		, float : g_is_eq_d_f \
		, int : g_is_eq_d_si \
		, long : g_is_eq_d_sl \
		, short : g_is_eq_d_ss \
		, unsigned long : g_is_eq_d_ul \
	) \
	, float : _Generic((y) \
		, bool : g_is_eq_f_b \
		, char : g_is_eq_f_c \
		, double : g_is_eq_f_d \
		, float : g_is_eq_f_f \
		, int : g_is_eq_f_si \
		, long : g_is_eq_f_sl \
		, short : g_is_eq_f_ss \
		, unsigned long : g_is_eq_f_ul \
	) \
	, int : _Generic((y) \
		, bool : g_is_eq_si_b \
		, char : g_is_eq_si_c \
		, double : g_is_eq_si_d \
		, float : g_is_eq_si_f \
		, int : g_is_eq_si_si \
		, long : g_is_eq_si_sl \
		, short : g_is_eq_si_ss \
		, unsigned long : g_is_eq_si_ul \
	) \
	, long : _Generic((y) \
		, bool : g_is_eq_sl_b \
		, char : g_is_eq_sl_c \
		, double : g_is_eq_sl_d \
		, float : g_is_eq_sl_f \
		, int : g_is_eq_sl_si \
		, long : g_is_eq_sl_sl \
		, short : g_is_eq_sl_ss \
		, unsigned long : g_is_eq_sl_ul \
	) \
	, short : _Generic((y) \
		, bool : g_is_eq_ss_b \
		, char : g_is_eq_ss_c \
		, double : g_is_eq_ss_d \
		, float : g_is_eq_ss_f \
		, int : g_is_eq_ss_si \
		, long : g_is_eq_ss_sl \
		, short : g_is_eq_ss_ss \
		, unsigned long : g_is_eq_ss_ul \
	) \
	, unsigned long : _Generic((y) \
		, bool : g_is_eq_ul_b \
		, char : g_is_eq_ul_c \
		, double : g_is_eq_ul_d \
		, float : g_is_eq_ul_f \
		, int : g_is_eq_ul_si \
		, long : g_is_eq_ul_sl \
		, short : g_is_eq_ul_ss \
		, unsigned long : g_is_eq_ul_ul \
	) \
)

#define g_is_ge(x,y) _Generic((x) \
	, bool : _Generic((y) \
		, bool : g_is_ge_b_b \
		, char : g_is_ge_b_c \
		, double : g_is_ge_b_d \
		, float : g_is_ge_b_f \
		, int : g_is_ge_b_si \
		, long : g_is_ge_b_sl \
		, short : g_is_ge_b_ss \
		, unsigned long : g_is_ge_b_ul \
	) \
	, char : _Generic((y) \
		, bool : g_is_ge_c_b \
		, char : g_is_ge_c_c \
		, double : g_is_ge_c_d \
		, float : g_is_ge_c_f \
		, int : g_is_ge_c_si \
		, long : g_is_ge_c_sl \
		, short : g_is_ge_c_ss \
		, unsigned long : g_is_ge_c_ul \
	) \
	, double : _Generic((y) \
		, bool : g_is_ge_d_b \
		, char : g_is_ge_d_c \
		, double : g_is_ge_d_d \
		, float : g_is_ge_d_f \
		, int : g_is_ge_d_si \
		, long : g_is_ge_d_sl \
		, short : g_is_ge_d_ss \
		, unsigned long : g_is_ge_d_ul \
	) \
	, float : _Generic((y) \
		, bool : g_is_ge_f_b \
		, char : g_is_ge_f_c \
		, double : g_is_ge_f_d \
		, float : g_is_ge_f_f \
		, int : g_is_ge_f_si \
		, long : g_is_ge_f_sl \
		, short : g_is_ge_f_ss \
		, unsigned long : g_is_ge_f_ul \
	) \
	, int : _Generic((y) \
		, bool : g_is_ge_si_b \
		, char : g_is_ge_si_c \
		, double : g_is_ge_si_d \
		, float : g_is_ge_si_f \
		, int : g_is_ge_si_si \
		, long : g_is_ge_si_sl \
		, short : g_is_ge_si_ss \
		, unsigned long : g_is_ge_si_ul \
	) \
	, long : _Generic((y) \
		, bool : g_is_ge_sl_b \
		, char : g_is_ge_sl_c \
		, double : g_is_ge_sl_d \
		, float : g_is_ge_sl_f \
		, int : g_is_ge_sl_si \
		, long : g_is_ge_sl_sl \
		, short : g_is_ge_sl_ss \
		, unsigned long : g_is_ge_sl_ul \
	) \
	, short : _Generic((y) \
		, bool : g_is_ge_ss_b \
		, char : g_is_ge_ss_c \
		, double : g_is_ge_ss_d \
		, float : g_is_ge_ss_f \
		, int : g_is_ge_ss_si \
		, long : g_is_ge_ss_sl \
		, short : g_is_ge_ss_ss \
		, unsigned long : g_is_ge_ss_ul \
	) \
	, unsigned long : _Generic((y) \
		, bool : g_is_ge_ul_b \
		, char : g_is_ge_ul_c \
		, double : g_is_ge_ul_d \
		, float : g_is_ge_ul_f \
		, int : g_is_ge_ul_si \
		, long : g_is_ge_ul_sl \
		, short : g_is_ge_ul_ss \
		, unsigned long : g_is_ge_ul_ul \
	) \
)

#define g_is_gt(x,y) _Generic((x) \
	, bool : _Generic((y) \
		, bool : g_is_gt_b_b \
		, char : g_is_gt_b_c \
		, double : g_is_gt_b_d \
		, float : g_is_gt_b_f \
		, int : g_is_gt_b_si \
		, long : g_is_gt_b_sl \
		, short : g_is_gt_b_ss \
		, unsigned long : g_is_gt_b_ul \
	) \
	, char : _Generic((y) \
		, bool : g_is_gt_c_b \
		, char : g_is_gt_c_c \
		, double : g_is_gt_c_d \
		, float : g_is_gt_c_f \
		, int : g_is_gt_c_si \
		, long : g_is_gt_c_sl \
		, short : g_is_gt_c_ss \
		, unsigned long : g_is_gt_c_ul \
	) \
	, double : _Generic((y) \
		, bool : g_is_gt_d_b \
		, char : g_is_gt_d_c \
		, double : g_is_gt_d_d \
		, float : g_is_gt_d_f \
		, int : g_is_gt_d_si \
		, long : g_is_gt_d_sl \
		, short : g_is_gt_d_ss \
		, unsigned long : g_is_gt_d_ul \
	) \
	, float : _Generic((y) \
		, bool : g_is_gt_f_b \
		, char : g_is_gt_f_c \
		, double : g_is_gt_f_d \
		, float : g_is_gt_f_f \
		, int : g_is_gt_f_si \
		, long : g_is_gt_f_sl \
		, short : g_is_gt_f_ss \
		, unsigned long : g_is_gt_f_ul \
	) \
	, int : _Generic((y) \
		, bool : g_is_gt_si_b \
		, char : g_is_gt_si_c \
		, double : g_is_gt_si_d \
		, float : g_is_gt_si_f \
		, int : g_is_gt_si_si \
		, long : g_is_gt_si_sl \
		, short : g_is_gt_si_ss \
		, unsigned long : g_is_gt_si_ul \
	) \
	, long : _Generic((y) \
		, bool : g_is_gt_sl_b \
		, char : g_is_gt_sl_c \
		, double : g_is_gt_sl_d \
		, float : g_is_gt_sl_f \
		, int : g_is_gt_sl_si \
		, long : g_is_gt_sl_sl \
		, short : g_is_gt_sl_ss \
		, unsigned long : g_is_gt_sl_ul \
	) \
	, short : _Generic((y) \
		, bool : g_is_gt_ss_b \
		, char : g_is_gt_ss_c \
		, double : g_is_gt_ss_d \
		, float : g_is_gt_ss_f \
		, int : g_is_gt_ss_si \
		, long : g_is_gt_ss_sl \
		, short : g_is_gt_ss_ss \
		, unsigned long : g_is_gt_ss_ul \
	) \
	, unsigned long : _Generic((y) \
		, bool : g_is_gt_ul_b \
		, char : g_is_gt_ul_c \
		, double : g_is_gt_ul_d \
		, float : g_is_gt_ul_f \
		, int : g_is_gt_ul_si \
		, long : g_is_gt_ul_sl \
		, short : g_is_gt_ul_ss \
		, unsigned long : g_is_gt_ul_ul \
	) \
)

#define g_is_le(x,y) _Generic((x) \
	, bool : _Generic((y) \
		, bool : g_is_le_b_b \
		, char : g_is_le_b_c \
		, double : g_is_le_b_d \
		, float : g_is_le_b_f \
		, int : g_is_le_b_si \
		, long : g_is_le_b_sl \
		, short : g_is_le_b_ss \
		, unsigned long : g_is_le_b_ul \
	) \
	, char : _Generic((y) \
		, bool : g_is_le_c_b \
		, char : g_is_le_c_c \
		, double : g_is_le_c_d \
		, float : g_is_le_c_f \
		, int : g_is_le_c_si \
		, long : g_is_le_c_sl \
		, short : g_is_le_c_ss \
		, unsigned long : g_is_le_c_ul \
	) \
	, double : _Generic((y) \
		, bool : g_is_le_d_b \
		, char : g_is_le_d_c \
		, double : g_is_le_d_d \
		, float : g_is_le_d_f \
		, int : g_is_le_d_si \
		, long : g_is_le_d_sl \
		, short : g_is_le_d_ss \
		, unsigned long : g_is_le_d_ul \
	) \
	, float : _Generic((y) \
		, bool : g_is_le_f_b \
		, char : g_is_le_f_c \
		, double : g_is_le_f_d \
		, float : g_is_le_f_f \
		, int : g_is_le_f_si \
		, long : g_is_le_f_sl \
		, short : g_is_le_f_ss \
		, unsigned long : g_is_le_f_ul \
	) \
	, int : _Generic((y) \
		, bool : g_is_le_si_b \
		, char : g_is_le_si_c \
		, double : g_is_le_si_d \
		, float : g_is_le_si_f \
		, int : g_is_le_si_si \
		, long : g_is_le_si_sl \
		, short : g_is_le_si_ss \
		, unsigned long : g_is_le_si_ul \
	) \
	, long : _Generic((y) \
		, bool : g_is_le_sl_b \
		, char : g_is_le_sl_c \
		, double : g_is_le_sl_d \
		, float : g_is_le_sl_f \
		, int : g_is_le_sl_si \
		, long : g_is_le_sl_sl \
		, short : g_is_le_sl_ss \
		, unsigned long : g_is_le_sl_ul \
	) \
	, short : _Generic((y) \
		, bool : g_is_le_ss_b \
		, char : g_is_le_ss_c \
		, double : g_is_le_ss_d \
		, float : g_is_le_ss_f \
		, int : g_is_le_ss_si \
		, long : g_is_le_ss_sl \
		, short : g_is_le_ss_ss \
		, unsigned long : g_is_le_ss_ul \
	) \
	, unsigned long : _Generic((y) \
		, bool : g_is_le_ul_b \
		, char : g_is_le_ul_c \
		, double : g_is_le_ul_d \
		, float : g_is_le_ul_f \
		, int : g_is_le_ul_si \
		, long : g_is_le_ul_sl \
		, short : g_is_le_ul_ss \
		, unsigned long : g_is_le_ul_ul \
	) \
)

#define g_is_lt(x,y) _Generic((x) \
	, bool : _Generic((y) \
		, bool : g_is_lt_b_b \
		, char : g_is_lt_b_c \
		, double : g_is_lt_b_d \
		, float : g_is_lt_b_f \
		, int : g_is_lt_b_si \
		, long : g_is_lt_b_sl \
		, short : g_is_lt_b_ss \
		, unsigned long : g_is_lt_b_ul \
	) \
	, char : _Generic((y) \
		, bool : g_is_lt_c_b \
		, char : g_is_lt_c_c \
		, double : g_is_lt_c_d \
		, float : g_is_lt_c_f \
		, int : g_is_lt_c_si \
		, long : g_is_lt_c_sl \
		, short : g_is_lt_c_ss \
		, unsigned long : g_is_lt_c_ul \
	) \
	, double : _Generic((y) \
		, bool : g_is_lt_d_b \
		, char : g_is_lt_d_c \
		, double : g_is_lt_d_d \
		, float : g_is_lt_d_f \
		, int : g_is_lt_d_si \
		, long : g_is_lt_d_sl \
		, short : g_is_lt_d_ss \
		, unsigned long : g_is_lt_d_ul \
	) \
	, float : _Generic((y) \
		, bool : g_is_lt_f_b \
		, char : g_is_lt_f_c \
		, double : g_is_lt_f_d \
		, float : g_is_lt_f_f \
		, int : g_is_lt_f_si \
		, long : g_is_lt_f_sl \
		, short : g_is_lt_f_ss \
		, unsigned long : g_is_lt_f_ul \
	) \
	, int : _Generic((y) \
		, bool : g_is_lt_si_b \
		, char : g_is_lt_si_c \
		, double : g_is_lt_si_d \
		, float : g_is_lt_si_f \
		, int : g_is_lt_si_si \
		, long : g_is_lt_si_sl \
		, short : g_is_lt_si_ss \
		, unsigned long : g_is_lt_si_ul \
	) \
	, long : _Generic((y) \
		, bool : g_is_lt_sl_b \
		, char : g_is_lt_sl_c \
		, double : g_is_lt_sl_d \
		, float : g_is_lt_sl_f \
		, int : g_is_lt_sl_si \
		, long : g_is_lt_sl_sl \
		, short : g_is_lt_sl_ss \
		, unsigned long : g_is_lt_sl_ul \
	) \
	, short : _Generic((y) \
		, bool : g_is_lt_ss_b \
		, char : g_is_lt_ss_c \
		, double : g_is_lt_ss_d \
		, float : g_is_lt_ss_f \
		, int : g_is_lt_ss_si \
		, long : g_is_lt_ss_sl \
		, short : g_is_lt_ss_ss \
		, unsigned long : g_is_lt_ss_ul \
	) \
	, unsigned long : _Generic((y) \
		, bool : g_is_lt_ul_b \
		, char : g_is_lt_ul_c \
		, double : g_is_lt_ul_d \
		, float : g_is_lt_ul_f \
		, int : g_is_lt_ul_si \
		, long : g_is_lt_ul_sl \
		, short : g_is_lt_ul_ss \
		, unsigned long : g_is_lt_ul_ul \
	) \
)

#define g_is_ne(x,y) _Generic((x) \
	, bool : _Generic((y) \
		, bool : g_is_ne_b_b \
		, char : g_is_ne_b_c \
		, double : g_is_ne_b_d \
		, float : g_is_ne_b_f \
		, int : g_is_ne_b_si \
		, long : g_is_ne_b_sl \
		, short : g_is_ne_b_ss \
		, unsigned long : g_is_ne_b_ul \
	) \
	, char : _Generic((y) \
		, bool : g_is_ne_c_b \
		, char : g_is_ne_c_c \
		, double : g_is_ne_c_d \
		, float : g_is_ne_c_f \
		, int : g_is_ne_c_si \
		, long : g_is_ne_c_sl \
		, short : g_is_ne_c_ss \
		, unsigned long : g_is_ne_c_ul \
	) \
	, double : _Generic((y) \
		, bool : g_is_ne_d_b \
		, char : g_is_ne_d_c \
		, double : g_is_ne_d_d \
		, float : g_is_ne_d_f \
		, int : g_is_ne_d_si \
		, long : g_is_ne_d_sl \
		, short : g_is_ne_d_ss \
		, unsigned long : g_is_ne_d_ul \
	) \
	, float : _Generic((y) \
		, bool : g_is_ne_f_b \
		, char : g_is_ne_f_c \
		, double : g_is_ne_f_d \
		, float : g_is_ne_f_f \
		, int : g_is_ne_f_si \
		, long : g_is_ne_f_sl \
		, short : g_is_ne_f_ss \
		, unsigned long : g_is_ne_f_ul \
	) \
	, int : _Generic((y) \
		, bool : g_is_ne_si_b \
		, char : g_is_ne_si_c \
		, double : g_is_ne_si_d \
		, float : g_is_ne_si_f \
		, int : g_is_ne_si_si \
		, long : g_is_ne_si_sl \
		, short : g_is_ne_si_ss \
		, unsigned long : g_is_ne_si_ul \
	) \
	, long : _Generic((y) \
		, bool : g_is_ne_sl_b \
		, char : g_is_ne_sl_c \
		, double : g_is_ne_sl_d \
		, float : g_is_ne_sl_f \
		, int : g_is_ne_sl_si \
		, long : g_is_ne_sl_sl \
		, short : g_is_ne_sl_ss \
		, unsigned long : g_is_ne_sl_ul \
	) \
	, short : _Generic((y) \
		, bool : g_is_ne_ss_b \
		, char : g_is_ne_ss_c \
		, double : g_is_ne_ss_d \
		, float : g_is_ne_ss_f \
		, int : g_is_ne_ss_si \
		, long : g_is_ne_ss_sl \
		, short : g_is_ne_ss_ss \
		, unsigned long : g_is_ne_ss_ul \
	) \
	, unsigned long : _Generic((y) \
		, bool : g_is_ne_ul_b \
		, char : g_is_ne_ul_c \
		, double : g_is_ne_ul_d \
		, float : g_is_ne_ul_f \
		, int : g_is_ne_ul_si \
		, long : g_is_ne_ul_sl \
		, short : g_is_ne_ul_ss \
		, unsigned long : g_is_ne_ul_ul \
	) \
)

#define g_add(x,y) _Generic((x) \
	, bool : _Generic((y) \
		, bool : g_add_b_b \
		, char : g_add_b_c \
		, double : g_add_b_d \
		, float : g_add_b_f \
		, int : g_add_b_si \
		, long : g_add_b_sl \
		, short : g_add_b_ss \
		, unsigned long : g_add_b_ul \
	) \
	, char : _Generic((y) \
		, bool : g_add_c_b \
		, char : g_add_c_c \
		, double : g_add_c_d \
		, float : g_add_c_f \
		, int : g_add_c_si \
		, long : g_add_c_sl \
		, short : g_add_c_ss \
		, unsigned long : g_add_c_ul \
	) \
	, double : _Generic((y) \
		, bool : g_add_d_b \
		, char : g_add_d_c \
		, double : g_add_d_d \
		, float : g_add_d_f \
		, int : g_add_d_si \
		, long : g_add_d_sl \
		, short : g_add_d_ss \
		, unsigned long : g_add_d_ul \
	) \
	, float : _Generic((y) \
		, bool : g_add_f_b \
		, char : g_add_f_c \
		, double : g_add_f_d \
		, float : g_add_f_f \
		, int : g_add_f_si \
		, long : g_add_f_sl \
		, short : g_add_f_ss \
		, unsigned long : g_add_f_ul \
	) \
	, int : _Generic((y) \
		, bool : g_add_si_b \
		, char : g_add_si_c \
		, double : g_add_si_d \
		, float : g_add_si_f \
		, int : g_add_si_si \
		, long : g_add_si_sl \
		, short : g_add_si_ss \
		, unsigned long : g_add_si_ul \
	) \
	, long : _Generic((y) \
		, bool : g_add_sl_b \
		, char : g_add_sl_c \
		, double : g_add_sl_d \
		, float : g_add_sl_f \
		, int : g_add_sl_si \
		, long : g_add_sl_sl \
		, short : g_add_sl_ss \
		, unsigned long : g_add_sl_ul \
	) \
	, short : _Generic((y) \
		, bool : g_add_ss_b \
		, char : g_add_ss_c \
		, double : g_add_ss_d \
		, float : g_add_ss_f \
		, int : g_add_ss_si \
		, long : g_add_ss_sl \
		, short : g_add_ss_ss \
		, unsigned long : g_add_ss_ul \
	) \
	, unsigned long : _Generic((y) \
		, bool : g_add_ul_b \
		, char : g_add_ul_c \
		, double : g_add_ul_d \
		, float : g_add_ul_f \
		, int : g_add_ul_si \
		, long : g_add_ul_sl \
		, short : g_add_ul_ss \
		, unsigned long : g_add_ul_ul \
	) \
)

#define g_mul(x,y) _Generic((x) \
	, bool : _Generic((y) \
		, bool : g_mul_b_b \
		, char : g_mul_b_c \
		, double : g_mul_b_d \
		, float : g_mul_b_f \
		, int : g_mul_b_si \
		, long : g_mul_b_sl \
		, short : g_mul_b_ss \
		, unsigned long : g_mul_b_ul \
	) \
	, char : _Generic((y) \
		, bool : g_mul_c_b \
		, char : g_mul_c_c \
		, double : g_mul_c_d \
		, float : g_mul_c_f \
		, int : g_mul_c_si \
		, long : g_mul_c_sl \
		, short : g_mul_c_ss \
		, unsigned long : g_mul_c_ul \
	) \
	, double : _Generic((y) \
		, bool : g_mul_d_b \
		, char : g_mul_d_c \
		, double : g_mul_d_d \
		, float : g_mul_d_f \
		, int : g_mul_d_si \
		, long : g_mul_d_sl \
		, short : g_mul_d_ss \
		, unsigned long : g_mul_d_ul \
	) \
	, float : _Generic((y) \
		, bool : g_mul_f_b \
		, char : g_mul_f_c \
		, double : g_mul_f_d \
		, float : g_mul_f_f \
		, int : g_mul_f_si \
		, long : g_mul_f_sl \
		, short : g_mul_f_ss \
		, unsigned long : g_mul_f_ul \
	) \
	, int : _Generic((y) \
		, bool : g_mul_si_b \
		, char : g_mul_si_c \
		, double : g_mul_si_d \
		, float : g_mul_si_f \
		, int : g_mul_si_si \
		, long : g_mul_si_sl \
		, short : g_mul_si_ss \
		, unsigned long : g_mul_si_ul \
	) \
	, long : _Generic((y) \
		, bool : g_mul_sl_b \
		, char : g_mul_sl_c \
		, double : g_mul_sl_d \
		, float : g_mul_sl_f \
		, int : g_mul_sl_si \
		, long : g_mul_sl_sl \
		, short : g_mul_sl_ss \
		, unsigned long : g_mul_sl_ul \
	) \
	, short : _Generic((y) \
		, bool : g_mul_ss_b \
		, char : g_mul_ss_c \
		, double : g_mul_ss_d \
		, float : g_mul_ss_f \
		, int : g_mul_ss_si \
		, long : g_mul_ss_sl \
		, short : g_mul_ss_ss \
		, unsigned long : g_mul_ss_ul \
	) \
	, unsigned long : _Generic((y) \
		, bool : g_mul_ul_b \
		, char : g_mul_ul_c \
		, double : g_mul_ul_d \
		, float : g_mul_ul_f \
		, int : g_mul_ul_si \
		, long : g_mul_ul_sl \
		, short : g_mul_ul_ss \
		, unsigned long : g_mul_ul_ul \
	) \
)

#define g_sub(x,y) _Generic((x) \
	, bool : _Generic((y) \
		, bool : g_sub_b_b \
		, char : g_sub_b_c \
		, double : g_sub_b_d \
		, float : g_sub_b_f \
		, int : g_sub_b_si \
		, long : g_sub_b_sl \
		, short : g_sub_b_ss \
		, unsigned long : g_sub_b_ul \
	) \
	, char : _Generic((y) \
		, bool : g_sub_c_b \
		, char : g_sub_c_c \
		, double : g_sub_c_d \
		, float : g_sub_c_f \
		, int : g_sub_c_si \
		, long : g_sub_c_sl \
		, short : g_sub_c_ss \
		, unsigned long : g_sub_c_ul \
	) \
	, double : _Generic((y) \
		, bool : g_sub_d_b \
		, char : g_sub_d_c \
		, double : g_sub_d_d \
		, float : g_sub_d_f \
		, int : g_sub_d_si \
		, long : g_sub_d_sl \
		, short : g_sub_d_ss \
		, unsigned long : g_sub_d_ul \
	) \
	, float : _Generic((y) \
		, bool : g_sub_f_b \
		, char : g_sub_f_c \
		, double : g_sub_f_d \
		, float : g_sub_f_f \
		, int : g_sub_f_si \
		, long : g_sub_f_sl \
		, short : g_sub_f_ss \
		, unsigned long : g_sub_f_ul \
	) \
	, int : _Generic((y) \
		, bool : g_sub_si_b \
		, char : g_sub_si_c \
		, double : g_sub_si_d \
		, float : g_sub_si_f \
		, int : g_sub_si_si \
		, long : g_sub_si_sl \
		, short : g_sub_si_ss \
		, unsigned long : g_sub_si_ul \
	) \
	, long : _Generic((y) \
		, bool : g_sub_sl_b \
		, char : g_sub_sl_c \
		, double : g_sub_sl_d \
		, float : g_sub_sl_f \
		, int : g_sub_sl_si \
		, long : g_sub_sl_sl \
		, short : g_sub_sl_ss \
		, unsigned long : g_sub_sl_ul \
	) \
	, short : _Generic((y) \
		, bool : g_sub_ss_b \
		, char : g_sub_ss_c \
		, double : g_sub_ss_d \
		, float : g_sub_ss_f \
		, int : g_sub_ss_si \
		, long : g_sub_ss_sl \
		, short : g_sub_ss_ss \
		, unsigned long : g_sub_ss_ul \
	) \
	, unsigned long : _Generic((y) \
		, bool : g_sub_ul_b \
		, char : g_sub_ul_c \
		, double : g_sub_ul_d \
		, float : g_sub_ul_f \
		, int : g_sub_ul_si \
		, long : g_sub_ul_sl \
		, short : g_sub_ul_ss \
		, unsigned long : g_sub_ul_ul \
	) \
)

#define g_add_eq(x,y) _Generic((x) \
	, bool : _Generic((y) \
		, bool : g_add_eq_b_b \
		, char : g_add_eq_b_c \
		, double : g_add_eq_b_d \
		, float : g_add_eq_b_f \
		, int : g_add_eq_b_si \
		, long : g_add_eq_b_sl \
		, short : g_add_eq_b_ss \
		, unsigned long : g_add_eq_b_ul \
	) \
	, char : _Generic((y) \
		, bool : g_add_eq_c_b \
		, char : g_add_eq_c_c \
		, double : g_add_eq_c_d \
		, float : g_add_eq_c_f \
		, int : g_add_eq_c_si \
		, long : g_add_eq_c_sl \
		, short : g_add_eq_c_ss \
		, unsigned long : g_add_eq_c_ul \
	) \
	, double : _Generic((y) \
		, bool : g_add_eq_d_b \
		, char : g_add_eq_d_c \
		, double : g_add_eq_d_d \
		, float : g_add_eq_d_f \
		, int : g_add_eq_d_si \
		, long : g_add_eq_d_sl \
		, short : g_add_eq_d_ss \
		, unsigned long : g_add_eq_d_ul \
	) \
	, float : _Generic((y) \
		, bool : g_add_eq_f_b \
		, char : g_add_eq_f_c \
		, double : g_add_eq_f_d \
		, float : g_add_eq_f_f \
		, int : g_add_eq_f_si \
		, long : g_add_eq_f_sl \
		, short : g_add_eq_f_ss \
		, unsigned long : g_add_eq_f_ul \
	) \
	, int : _Generic((y) \
		, bool : g_add_eq_si_b \
		, char : g_add_eq_si_c \
		, double : g_add_eq_si_d \
		, float : g_add_eq_si_f \
		, int : g_add_eq_si_si \
		, long : g_add_eq_si_sl \
		, short : g_add_eq_si_ss \
		, unsigned long : g_add_eq_si_ul \
	) \
	, long : _Generic((y) \
		, bool : g_add_eq_sl_b \
		, char : g_add_eq_sl_c \
		, double : g_add_eq_sl_d \
		, float : g_add_eq_sl_f \
		, int : g_add_eq_sl_si \
		, long : g_add_eq_sl_sl \
		, short : g_add_eq_sl_ss \
		, unsigned long : g_add_eq_sl_ul \
	) \
	, short : _Generic((y) \
		, bool : g_add_eq_ss_b \
		, char : g_add_eq_ss_c \
		, double : g_add_eq_ss_d \
		, float : g_add_eq_ss_f \
		, int : g_add_eq_ss_si \
		, long : g_add_eq_ss_sl \
		, short : g_add_eq_ss_ss \
		, unsigned long : g_add_eq_ss_ul \
	) \
	, unsigned long : _Generic((y) \
		, bool : g_add_eq_ul_b \
		, char : g_add_eq_ul_c \
		, double : g_add_eq_ul_d \
		, float : g_add_eq_ul_f \
		, int : g_add_eq_ul_si \
		, long : g_add_eq_ul_sl \
		, short : g_add_eq_ul_ss \
		, unsigned long : g_add_eq_ul_ul \
	) \
)

#define g_assign(x,y) _Generic((x) \
	, bool : _Generic((y) \
		, bool : g_assign_b_b \
		, char : g_assign_b_c \
		, double : g_assign_b_d \
		, float : g_assign_b_f \
		, int : g_assign_b_si \
		, long : g_assign_b_sl \
		, short : g_assign_b_ss \
		, unsigned long : g_assign_b_ul \
	) \
	, char : _Generic((y) \
		, bool : g_assign_c_b \
		, char : g_assign_c_c \
		, double : g_assign_c_d \
		, float : g_assign_c_f \
		, int : g_assign_c_si \
		, long : g_assign_c_sl \
		, short : g_assign_c_ss \
		, unsigned long : g_assign_c_ul \
	) \
	, double : _Generic((y) \
		, bool : g_assign_d_b \
		, char : g_assign_d_c \
		, double : g_assign_d_d \
		, float : g_assign_d_f \
		, int : g_assign_d_si \
		, long : g_assign_d_sl \
		, short : g_assign_d_ss \
		, unsigned long : g_assign_d_ul \
	) \
	, float : _Generic((y) \
		, bool : g_assign_f_b \
		, char : g_assign_f_c \
		, double : g_assign_f_d \
		, float : g_assign_f_f \
		, int : g_assign_f_si \
		, long : g_assign_f_sl \
		, short : g_assign_f_ss \
		, unsigned long : g_assign_f_ul \
	) \
	, int : _Generic((y) \
		, bool : g_assign_si_b \
		, char : g_assign_si_c \
		, double : g_assign_si_d \
		, float : g_assign_si_f \
		, int : g_assign_si_si \
		, long : g_assign_si_sl \
		, short : g_assign_si_ss \
		, unsigned long : g_assign_si_ul \
	) \
	, long : _Generic((y) \
		, bool : g_assign_sl_b \
		, char : g_assign_sl_c \
		, double : g_assign_sl_d \
		, float : g_assign_sl_f \
		, int : g_assign_sl_si \
		, long : g_assign_sl_sl \
		, short : g_assign_sl_ss \
		, unsigned long : g_assign_sl_ul \
	) \
	, short : _Generic((y) \
		, bool : g_assign_ss_b \
		, char : g_assign_ss_c \
		, double : g_assign_ss_d \
		, float : g_assign_ss_f \
		, int : g_assign_ss_si \
		, long : g_assign_ss_sl \
		, short : g_assign_ss_ss \
		, unsigned long : g_assign_ss_ul \
	) \
	, unsigned long : _Generic((y) \
		, bool : g_assign_ul_b \
		, char : g_assign_ul_c \
		, double : g_assign_ul_d \
		, float : g_assign_ul_f \
		, int : g_assign_ul_si \
		, long : g_assign_ul_sl \
		, short : g_assign_ul_ss \
		, unsigned long : g_assign_ul_ul \
	) \
)

#define g_mul_eq(x,y) _Generic((x) \
	, bool : _Generic((y) \
		, bool : g_mul_eq_b_b \
		, char : g_mul_eq_b_c \
		, double : g_mul_eq_b_d \
		, float : g_mul_eq_b_f \
		, int : g_mul_eq_b_si \
		, long : g_mul_eq_b_sl \
		, short : g_mul_eq_b_ss \
		, unsigned long : g_mul_eq_b_ul \
	) \
	, char : _Generic((y) \
		, bool : g_mul_eq_c_b \
		, char : g_mul_eq_c_c \
		, double : g_mul_eq_c_d \
		, float : g_mul_eq_c_f \
		, int : g_mul_eq_c_si \
		, long : g_mul_eq_c_sl \
		, short : g_mul_eq_c_ss \
		, unsigned long : g_mul_eq_c_ul \
	) \
	, double : _Generic((y) \
		, bool : g_mul_eq_d_b \
		, char : g_mul_eq_d_c \
		, double : g_mul_eq_d_d \
		, float : g_mul_eq_d_f \
		, int : g_mul_eq_d_si \
		, long : g_mul_eq_d_sl \
		, short : g_mul_eq_d_ss \
		, unsigned long : g_mul_eq_d_ul \
	) \
	, float : _Generic((y) \
		, bool : g_mul_eq_f_b \
		, char : g_mul_eq_f_c \
		, double : g_mul_eq_f_d \
		, float : g_mul_eq_f_f \
		, int : g_mul_eq_f_si \
		, long : g_mul_eq_f_sl \
		, short : g_mul_eq_f_ss \
		, unsigned long : g_mul_eq_f_ul \
	) \
	, int : _Generic((y) \
		, bool : g_mul_eq_si_b \
		, char : g_mul_eq_si_c \
		, double : g_mul_eq_si_d \
		, float : g_mul_eq_si_f \
		, int : g_mul_eq_si_si \
		, long : g_mul_eq_si_sl \
		, short : g_mul_eq_si_ss \
		, unsigned long : g_mul_eq_si_ul \
	) \
	, long : _Generic((y) \
		, bool : g_mul_eq_sl_b \
		, char : g_mul_eq_sl_c \
		, double : g_mul_eq_sl_d \
		, float : g_mul_eq_sl_f \
		, int : g_mul_eq_sl_si \
		, long : g_mul_eq_sl_sl \
		, short : g_mul_eq_sl_ss \
		, unsigned long : g_mul_eq_sl_ul \
	) \
	, short : _Generic((y) \
		, bool : g_mul_eq_ss_b \
		, char : g_mul_eq_ss_c \
		, double : g_mul_eq_ss_d \
		, float : g_mul_eq_ss_f \
		, int : g_mul_eq_ss_si \
		, long : g_mul_eq_ss_sl \
		, short : g_mul_eq_ss_ss \
		, unsigned long : g_mul_eq_ss_ul \
	) \
	, unsigned long : _Generic((y) \
		, bool : g_mul_eq_ul_b \
		, char : g_mul_eq_ul_c \
		, double : g_mul_eq_ul_d \
		, float : g_mul_eq_ul_f \
		, int : g_mul_eq_ul_si \
		, long : g_mul_eq_ul_sl \
		, short : g_mul_eq_ul_ss \
		, unsigned long : g_mul_eq_ul_ul \
	) \
)

#define g_sub_eq(x,y) _Generic((x) \
	, bool : _Generic((y) \
		, bool : g_sub_eq_b_b \
		, char : g_sub_eq_b_c \
		, double : g_sub_eq_b_d \
		, float : g_sub_eq_b_f \
		, int : g_sub_eq_b_si \
		, long : g_sub_eq_b_sl \
		, short : g_sub_eq_b_ss \
		, unsigned long : g_sub_eq_b_ul \
	) \
	, char : _Generic((y) \
		, bool : g_sub_eq_c_b \
		, char : g_sub_eq_c_c \
		, double : g_sub_eq_c_d \
		, float : g_sub_eq_c_f \
		, int : g_sub_eq_c_si \
		, long : g_sub_eq_c_sl \
		, short : g_sub_eq_c_ss \
		, unsigned long : g_sub_eq_c_ul \
	) \
	, double : _Generic((y) \
		, bool : g_sub_eq_d_b \
		, char : g_sub_eq_d_c \
		, double : g_sub_eq_d_d \
		, float : g_sub_eq_d_f \
		, int : g_sub_eq_d_si \
		, long : g_sub_eq_d_sl \
		, short : g_sub_eq_d_ss \
		, unsigned long : g_sub_eq_d_ul \
	) \
	, float : _Generic((y) \
		, bool : g_sub_eq_f_b \
		, char : g_sub_eq_f_c \
		, double : g_sub_eq_f_d \
		, float : g_sub_eq_f_f \
		, int : g_sub_eq_f_si \
		, long : g_sub_eq_f_sl \
		, short : g_sub_eq_f_ss \
		, unsigned long : g_sub_eq_f_ul \
	) \
	, int : _Generic((y) \
		, bool : g_sub_eq_si_b \
		, char : g_sub_eq_si_c \
		, double : g_sub_eq_si_d \
		, float : g_sub_eq_si_f \
		, int : g_sub_eq_si_si \
		, long : g_sub_eq_si_sl \
		, short : g_sub_eq_si_ss \
		, unsigned long : g_sub_eq_si_ul \
	) \
	, long : _Generic((y) \
		, bool : g_sub_eq_sl_b \
		, char : g_sub_eq_sl_c \
		, double : g_sub_eq_sl_d \
		, float : g_sub_eq_sl_f \
		, int : g_sub_eq_sl_si \
		, long : g_sub_eq_sl_sl \
		, short : g_sub_eq_sl_ss \
		, unsigned long : g_sub_eq_sl_ul \
	) \
	, short : _Generic((y) \
		, bool : g_sub_eq_ss_b \
		, char : g_sub_eq_ss_c \
		, double : g_sub_eq_ss_d \
		, float : g_sub_eq_ss_f \
		, int : g_sub_eq_ss_si \
		, long : g_sub_eq_ss_sl \
		, short : g_sub_eq_ss_ss \
		, unsigned long : g_sub_eq_ss_ul \
	) \
	, unsigned long : _Generic((y) \
		, bool : g_sub_eq_ul_b \
		, char : g_sub_eq_ul_c \
		, double : g_sub_eq_ul_d \
		, float : g_sub_eq_ul_f \
		, int : g_sub_eq_ul_si \
		, long : g_sub_eq_ul_sl \
		, short : g_sub_eq_ul_ss \
		, unsigned long : g_sub_eq_ul_ul \
	) \
)

#define g_cmp(x,y) _Generic((x) \
	, bool : _Generic((y) \
		, bool : g_cmp_b_b \
		, char : g_cmp_b_c \
		, double : g_cmp_b_d \
		, float : g_cmp_b_f \
		, int : g_cmp_b_si \
		, long : g_cmp_b_sl \
		, short : g_cmp_b_ss \
		, unsigned long : g_cmp_b_ul \
	) \
	, char : _Generic((y) \
		, bool : g_cmp_c_b \
		, char : g_cmp_c_c \
		, double : g_cmp_c_d \
		, float : g_cmp_c_f \
		, int : g_cmp_c_si \
		, long : g_cmp_c_sl \
		, short : g_cmp_c_ss \
		, unsigned long : g_cmp_c_ul \
	) \
	, double : _Generic((y) \
		, bool : g_cmp_d_b \
		, char : g_cmp_d_c \
		, double : g_cmp_d_d \
		, float : g_cmp_d_f \
		, int : g_cmp_d_si \
		, long : g_cmp_d_sl \
		, short : g_cmp_d_ss \
		, unsigned long : g_cmp_d_ul \
	) \
	, float : _Generic((y) \
		, bool : g_cmp_f_b \
		, char : g_cmp_f_c \
		, double : g_cmp_f_d \
		, float : g_cmp_f_f \
		, int : g_cmp_f_si \
		, long : g_cmp_f_sl \
		, short : g_cmp_f_ss \
		, unsigned long : g_cmp_f_ul \
	) \
	, int : _Generic((y) \
		, bool : g_cmp_si_b \
		, char : g_cmp_si_c \
		, double : g_cmp_si_d \
		, float : g_cmp_si_f \
		, int : g_cmp_si_si \
		, long : g_cmp_si_sl \
		, short : g_cmp_si_ss \
		, unsigned long : g_cmp_si_ul \
	) \
	, long : _Generic((y) \
		, bool : g_cmp_sl_b \
		, char : g_cmp_sl_c \
		, double : g_cmp_sl_d \
		, float : g_cmp_sl_f \
		, int : g_cmp_sl_si \
		, long : g_cmp_sl_sl \
		, short : g_cmp_sl_ss \
		, unsigned long : g_cmp_sl_ul \
	) \
	, short : _Generic((y) \
		, bool : g_cmp_ss_b \
		, char : g_cmp_ss_c \
		, double : g_cmp_ss_d \
		, float : g_cmp_ss_f \
		, int : g_cmp_ss_si \
		, long : g_cmp_ss_sl \
		, short : g_cmp_ss_ss \
		, unsigned long : g_cmp_ss_ul \
	) \
	, unsigned long : _Generic((y) \
		, bool : g_cmp_ul_b \
		, char : g_cmp_ul_c \
		, double : g_cmp_ul_d \
		, float : g_cmp_ul_f \
		, int : g_cmp_ul_si \
		, long : g_cmp_ul_sl \
		, short : g_cmp_ul_ss \
		, unsigned long : g_cmp_ul_ul \
	) \
)

#pragma GCC diagnostic pop                              
#endif
