#ifndef G_UTIL__________
#define G_UTIL__________

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>


#define G_INCPTR(p) (p = (char*)p + p##_size)
#define G_DECPTR(p) (p = (char*)p - p##_size)
#define G_NEXT(p) ((char*)p + p##_size)
#define G_ADVANCE(p, step) (p = (char*)p + p##_size * step)
#define G_DISTANCE(f, l) (int)(((char*)l - (char*)f)/f##_size)
#define G_IGNORE(x) (void)(x)
#define G_ICE_P(x) _Generic((1? (void *) ((x)*0) : (int *) 0), int*: 1, void*: 0)
#define G_STATIC_ASSERT_(c) ((void)sizeof(int[(c)?1:-1]))
#define G_STATIC_ASSERT(c) ((void)(G_STATIC_ASSERT_((c)), G_STATIC_ASSERT_(G_ICE_P(c))))
#define G_A_T_E(a,b) G_STATIC_ASSERT(g_type_id(a) == g_type_id(b)) // assert types equal
#define G_A_T_E_2(a,b,c) G_STATIC_ASSERT(g_type_id(a) == g_type_id(b) && g_type_id(a) == g_type_id(c)) // assert types equal
#define G_NELEM(a) (sizeof(a)/sizeof(*a))
#define G_PASTE__(a, b) a##b
#define G_PASTE_(a,b) G_PASTE__(a,b)
#define G_PASTE(a,b) G_PASTE_(a,b)
#define G_LOCAL_PAIR(f, s, varname) struct G_PASTE(local_pair_t_, __LINE__) { f first; s second; } varname = {0,0}
#define V_STO_SIZE sizeof(long double _Complex) // largest size of any of the fundamental g_basic data types. 
#define G_ITERARG(name) void* name, const size_t name##_size
#define InputIt(var) void* var, const size_t var##_size
#define OutputIt(var) void* var, const size_t var##_size
#define ForwardIt InputIt
#define RandomIt InputIt
#define G_SUBSCRIPT(pv, v_size, index)  (((char*)pv) + (v_size) * (index))
typedef void (*function_placeholder_t)(void);
typedef void (*forward_placeholder_2_t)(function_placeholder_t, void* , const void* , const void* );
typedef void (*forward_placeholder_1_t)(function_placeholder_t, void* , const void* );
typedef void (*forward_placeholder_0_t)(function_placeholder_t, void* );
typedef void (*forward_placeholder_0_1_t)(function_placeholder_t, const void*);


//                       /no return value, or, ignore return value. 
typedef struct func_spec_0_1_t
{		
	function_placeholder_t func;//placeholder signature.
	//void* arg1src;
	void (*forward)(function_placeholder_t, const void* a);
	void (*a_from_arg1src)(void* r, const void* a);	
	char a_storage[V_STO_SIZE];
	
} func_spec_0_1_t;

#define G_FUNC_SPEC_0_1(func, arg1src)             \
	(func_spec_0_1_t){                                           \
		(function_placeholder_t)func, /*arg1src,*/ (forward_placeholder_0_1_t)g_forward_0_1(func),\
		g_assign(g_function_arg1type(func), *(arg1src)),   \
		{0}\
	}
	
#define G_CALL_FUNC_0_1(fs, arg1src) do{                 \
	(fs)->a_from_arg1src((fs)->a_storage, arg1src);  \
	(fs)->forward((fs)->func, (fs)->a_storage);      \
	}while(0)



typedef struct func_spec_1_t
{		
	function_placeholder_t func;//placeholder signature.
	void (*forward)(function_placeholder_t, void* r, const void* a);
	void (*a_from_arg1src)(void* r, const void* a);
	void (*retdest_from_ret)(void* r, const void* b);
	char a_storage[V_STO_SIZE];
	char ret_storage[V_STO_SIZE];
	
} func_spec_1_t;

#define G_FUNC_SPEC_1(retdest, func, arg1src)             \
	(func_spec_1_t){                                           \
		/*retdest,*/ (function_placeholder_t)func, /*arg1src,*/ (forward_placeholder_1_t)g_forward_1(func),\
		g_assign(g_function_arg1type(func), *(arg1src)),   \
		g_assign(*(retdest), g_function_rettype(func)), {0},{0} \
	}

#define G_FUNC_SPEC_1_D(rettype, func, arg1type)             \
	(func_spec_1_t){                                           \
		(function_placeholder_t)func, (forward_placeholder_1_t)g_forward_1(func),\
		g_assign(g_function_arg1type(func), arg1type),   \
		g_assign(rettype, g_function_rettype(func)), {0},{0} \
	}
	
#define G_CALL_FUNC_1(retdest, fs, arg1src) do{                 \
	(fs)->a_from_arg1src((fs)->a_storage, arg1src);                  \
	(fs)->forward((fs)->func, (fs)->ret_storage, (fs)->a_storage);\
	(fs)->retdest_from_ret(retdest, (fs)->ret_storage);              \
	}while(0)





typedef struct func_spec_0_t // 1 ret value , 0 args. 
{		
	function_placeholder_t func;//placeholder signature.
	void (*forward)(function_placeholder_t, void* r);	
	void (*retdest_from_ret)(void* r, const void* b);	
	char ret_storage[V_STO_SIZE];
	
} func_spec_0_t;

#define G_FUNC_SPEC_0_D(rettype, func)             \
	(func_spec_0_t){                                           \
		(function_placeholder_t)func, (forward_placeholder_0_t)g_forward_0(func),\
		g_assign(rettype, g_function_rettype(func)), {0} \
	}
	
#define G_CALL_FUNC_0(retdest, fs) do{                     \
	(fs)->forward((fs)->func, (fs)->ret_storage);       \
	(fs)->retdest_from_ret(retdest, (fs)->ret_storage);  \
	}while(0)
	
	
typedef struct func_spec_2_t
{	
	//void* retdest;
	function_placeholder_t func;//placeholder signature.
	//void* arg1src;
	//void* arg2src;
	void (*forward)(function_placeholder_t, void* r, const void* a, const void* b);
	void (*a_from_arg1src)(void* r, const void* a);
	void (*b_from_arg2src)(void* r, const void* b) ;
	void (*retdest_from_ret)(void* r, const void* b);
	char a_storage[V_STO_SIZE];
	char b_storage[V_STO_SIZE];
	char ret_storage[V_STO_SIZE];
	
} func_spec_2_t;


//template<class T, class Compare> 
//const T& min(const T& a, const T& b, Compare comp)
//{
 //   return (comp(b, a)) ? b : a;
//}

#define G_FUNC_SPEC_2(retdest, func, arg1src, arg2src)             \
	(func_spec_2_t){                                           \
		/*retdest,*/ (function_placeholder_t)func, /*arg1src, arg2src,*/ (forward_placeholder_2_t)g_forward_2(func),\
		g_assign(g_function_arg1type(func), *(arg1src)),   \
		g_assign(g_function_arg2type(func), *(arg2src)),   \
		g_assign(*(retdest), g_function_rettype(func)), {0},{0},{0} \
	}

#define G_FUNC_SPEC_2_D(rettype, func, arg1type, arg2type)             \
	(func_spec_2_t){                                           \
		(function_placeholder_t)func, (forward_placeholder_2_t)g_forward_2(func),\
		g_assign(g_function_arg1type(func), arg1type),   \
		g_assign(g_function_arg2type(func), arg2type),   \
		g_assign(rettype, g_function_rettype(func)), {0},{0},{0} \
	}

#define G_CALL_FUNC_2(retdest, fs, arg1src, arg2src) do{                 \
	(fs)->a_from_arg1src((fs)->a_storage, arg1src);                  \
	(fs)->b_from_arg2src((fs)->b_storage, arg2src);                  \
	(fs)->forward((fs)->func, (fs)->ret_storage, (fs)->a_storage, (fs)->b_storage);\
	(fs)->retdest_from_ret(retdest, (fs)->ret_storage);              \
	}while(0)
	
#define G_CALL_FUNC_2_RET(retdest, fs, arg1src, arg2src) (                             \
	(fs)->a_from_arg1src((fs)->a_storage, arg1src),                                \
	(fs)->b_from_arg2src((fs)->b_storage, arg2src),                                \
	(fs)->forward((fs)->func, (fs)->ret_storage, (fs)->a_storage, (fs)->b_storage),\
	(fs)->retdest_from_ret(retdest, (fs)->ret_storage),                            \
	*(retdest)                                                                     \
	)
	


#endif

