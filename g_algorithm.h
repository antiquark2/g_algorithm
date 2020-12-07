#ifndef G_ALGORITHM_H__________
#define G_ALGORITHM_H__________

#ifdef G_BASIC_FULL
#include "g_basic.h"
#endif

#ifdef G_BASIC_ABBREV
#include "g_basic_abbrev.h"
#endif 

#ifndef G_BASIC_FULL
#ifndef G_BASIC_ABBREV
#error Must define either G_BASIC_FULL or G_BASIC_ABBREV
#endif
#endif

#include "g_util.h"


#define g_min_f(a, b, func)                                \
	g_value_from_void_free(a)                           \
	((G_A_T_E(a,b),                                                  \
	g_min_if_impl(g_malloc_value(a)(a), g_malloc_value(b)(b), \
	G_FUNC_SPEC_2((int*){0}, func, &g_example(a), &g_example(b))) \
	))

#define g_max_f(a, b, func)                                \
	g_value_from_void_free(a)                           \
	((G_A_T_E(a,b),                                                  \
	g_max_if_impl(g_malloc_value(a)(a), g_malloc_value(b)(b), \
	G_FUNC_SPEC_2((int*){0}, func, &g_example(a), &g_example(b)))             \
	))
 
 
 
 
#define g_min(a, b) g_value_from_void_free(a)((G_A_T_E(a,b), g_min_impl(g_malloc_value(a)(a), g_malloc_value(b)(b), g_is_lt(a, b))))
#define g_max(a, b) g_value_from_void_free(a)((G_A_T_E(a,b), g_min_impl(g_malloc_value(a)(a), g_malloc_value(b)(b), g_is_gt(a, b))))

#define g_minmax(pp, a, b) do{                                                                                                             \
	G_A_T_E(a,b);                                                                                                                      \
	G_A_T_E((pp)->first, (pp)->second);                                                                                                \
	g_minmax_impl(&((pp)->first), &((pp)->second), g_malloc_value(a)(a), g_malloc_value(b)(b), g_is_lt(a,b), g_assign((pp)->first, a)); \
	}while(0)

#define g_minmax_f(pp, a, b, comp) do{                                                                                                             \
	G_A_T_E(a,b);                                                                                                                      \
	G_A_T_E((pp)->first, (pp)->second);                                                                                                \
	g_minmax_f_impl(&((pp)->first), &((pp)->second), g_malloc_value(a)(a), g_malloc_value(b)(b),      G_FUNC_SPEC_2_D((int){0}, comp, a, b)      , g_assign((pp)->first, a)); \
	}while(0)
	
#define g_minmax_element(pp, f, l) do{\
	_Static_assert(g_type_id(*(f)) == g_type_id( *((pp)->first) ), "Types are not the same");\
	_Static_assert(g_type_id(*(f)) == g_type_id( *((pp)->second) ), "Types are not the same");\
	g_minmax_element_impl(&((pp)->first), &((pp)->second), f, sizeof(*(f)), l, sizeof(*(l)), g_is_lt(*(f),*(f)));\
	}while(0)

#define g_minmax_element_f(pp, f, l, comp) do{\
	_Static_assert(g_type_id(*(f)) == g_type_id( *((pp)->first) ), "Types are not the same");\
	_Static_assert(g_type_id(*(f)) == g_type_id( *((pp)->second) ), "Types are not the same");\
	g_minmax_element_f_impl(&((pp)->first), &((pp)->second), f, sizeof(*(f)), l, sizeof(*(l)),      G_FUNC_SPEC_2_D((int){0}, comp, *(f),*(f))     );\
	}while(0)

#define g_min_element(f, l) g_ptr_from_void(*(f))(g_min_element_impl(f, sizeof(*(f)), l, sizeof(*(l)), g_is_lt(*(f), *(f))))
#define g_max_element(f, l) g_ptr_from_void(*(f))(g_min_element_impl(f, sizeof(*(f)), l, sizeof(*(l)), g_is_gt(*(f), *(f))))

#define g_min_element_f(f, l, func) g_ptr_from_void(*(f))(g_min_element_f_impl(f, sizeof(*(f)), l, sizeof(*(l)),G_FUNC_SPEC_2((int*){0}, func, &g_example(*(f)), &g_example(*(f)))))

#define g_max_element_f(f, l, func) g_ptr_from_void(*(f))(g_max_element_f_impl(f, sizeof(*(f)), l, sizeof(*(l)),G_FUNC_SPEC_2((int*){0}, func, &g_example(*(f)), &g_example(*(f)))))

#define g_for_each(f, l, func) g_for_each_impl(f, sizeof(*(f)), l, sizeof(*(l)), G_FUNC_SPEC_0_1(func, f))

#define g_transform(f, l, d, func) g_ptr_from_void(*(f))( \
	g_transform_impl(f, sizeof(*(f)), l, sizeof(*(l)), d, sizeof(*(d)), \
	G_FUNC_SPEC_1(d, func, f) ))

#define g_transform_2(f, l, f2, d, func) g_ptr_from_void(*(f))( \
	g_transform_2_impl(f, sizeof(*(f)), l, sizeof(*(l)), f2, sizeof(*(f2)),d, sizeof(*(d)), \
	G_FUNC_SPEC_2(d, func, f, f2) ))
	
#define g_count(f, l, v) g_count_impl(f, sizeof(*(f)), l, sizeof(*(l)), g_malloc_value(v)(v), g_is_eq(*(f), v))

#define g_count_if(f, l, pred) g_count_if_impl(f, sizeof(*(f)), l, sizeof(*(l)),  G_FUNC_SPEC_1((int*){0}, pred, f) )

#define g_enforce_type(t1, t2, val) (G_A_T_E(t1, t2), val)

#define g_mismatch(ret, f1, l1, f2) g_mismatch_impl(\
	g_enforce_type(f1, (ret)->first, &((ret)->first)), \
	g_enforce_type(f2, (ret)->second, &((ret)->second)), \
	f1, sizeof(*(f1)), \
	l1, sizeof(*(l1)), \
	f2, sizeof(*(f2)), \
	g_is_eq(*(f1), *(f2)) \
	)
	
#define g_mismatch_2(ret, f1, l1, f2, l2) g_mismatch_2_impl(\
	g_enforce_type(f1, (ret)->first, &((ret)->first)), \
	g_enforce_type(f2, (ret)->second, &((ret)->second)), \
	f1, sizeof(*(f1)), \
	l1, sizeof(*(l1)), \
	f2, sizeof(*(f2)), \
	l2, sizeof(*(l2)), \
	g_is_eq(*(f1), *(f2)) \
	)

#define g_mismatch_f(ret, f1, l1, f2, pred) g_mismatch_p_impl(\
	g_enforce_type(f1, (ret)->first, &((ret)->first)), \
	g_enforce_type(f2, (ret)->second, &((ret)->second)), \
	f1, sizeof(*(f1)), \
	l1, sizeof(*(l1)), \
	f2, sizeof(*(f2)), \
	G_FUNC_SPEC_2((int*){0}, pred, f1, f2) \
	)

#define g_mismatch_f_2(ret, f1, l1, f2, l2,  pred) g_mismatch_p_2_impl(\
	g_enforce_type(f1, (ret)->first, &((ret)->first)), \
	g_enforce_type(f2, (ret)->second, &((ret)->second)), \
	f1, sizeof(*(f1)), \
	l1, sizeof(*(l1)), \
	f2, sizeof(*(f2)), \
	l2, sizeof(*(l2)), \
	G_FUNC_SPEC_2((int*){0}, pred, f1, f2) \
	)
	
#define g_inner_product(f1, l1, f2, init) g_value_from_void_free(init)(g_inner_product_impl(              \
					f1, sizeof(*(f1)),                                                \
					l1, sizeof(*(l1)),                                                \
					f2, sizeof(*(f2)),                                                \
					g_malloc_value(init)(init),                                       \
					g_mul(*(f1), *(f2)),                                              \
					g_add_eq(init, (*(f1) * *(f2) )                                   \
					)))


#define g_inner_product_f(f1, l1, f2, init, op1, op2) g_value_from_void_free(init)(g_inner_product_op_impl( \
					f1, sizeof(*(f1)),                                                \
					l1, sizeof(*(l1)),                                                \
					f2, sizeof(*(f2)),                                                \
					g_malloc_value(init)(init),                                       \
					G_FUNC_SPEC_2_D(init, op1, init, g_function_rettype(op2)),        \
					G_FUNC_SPEC_2_D(g_function_rettype(op2), op2, *(f1), *(f2))       \
					))

#define g_find(f, l, value) g_ptr_from_void(*(f))(g_find_impl(f, sizeof(*(f)), l, sizeof(*(l)), g_malloc_value(value)(value), g_is_eq(*(f), value)))

#define g_find_if(f, l, pred) g_ptr_from_void(*(f))(g_find_if_impl(f, sizeof(*(f)), l, sizeof(*(l)), G_FUNC_SPEC_1_D((int){0}, pred, *(f))))

#define g_find_if_not(f, l, pred) g_ptr_from_void(*(f))(g_find_if_not_impl(f, sizeof(*(f)), l, sizeof(*(l)), G_FUNC_SPEC_1_D((int){0}, pred, *(f))))
 

#define g_all_of(f, l, p)  ((l) == g_find_if_not(f, l, p))
#define g_any_of(f, l, p)  ((l) != g_find_if(f, l, p))
#define g_none_of(f, l, p)  ((l) == g_find_if(f, l, p))

#define g_iota(f, l, v) g_iota_impl(f, sizeof(*(f)), l, sizeof(*(l)), g_malloc_value(v)(v), g_assign(*(f), v), g_add_eq(v, (int){0}))

#define g_accumulate(f, l, init) g_value_from_void_free(init)(g_accumulate_impl(f, sizeof(*(f)), l, sizeof(*(l)), g_malloc_value(init)(init), g_add_eq(init, *(f))))

#define g_accumulate_f(f, l, init, op) g_value_from_void_free(init)(\
	g_accumulate_op_impl(f, sizeof(*(f)), l, sizeof(*(l)), g_malloc_value(init)(init), G_FUNC_SPEC_2_D(init, op, init, *(f))))


#define g_search(f, l, sf, sl) g_ptr_from_void(*(f))(g_search_impl(f, sizeof(*(f)), l, sizeof(*(l)), sf, sizeof(*(sf)), sl, sizeof(*(sl)), g_is_eq(*(f), *(sf))))

#define g_search_f(f, l, sf, sl, pred) g_ptr_from_void(*(f))(g_search_p_impl(f, sizeof(*(f)), l, sizeof(*(l)), sf, sizeof(*(sf)), sl, sizeof(*(sl)), \
G_FUNC_SPEC_2_D((int){0}, pred, *(f), *(sf))\
))

#define g_find_end(f, l, sf, sl)  g_ptr_from_void(*(f))(g_find_end_impl(f, sizeof(*(f)), l, sizeof(*(l)), sf, sizeof(*(sf)), sl, sizeof(*(sl)), g_is_eq(*(f), *(sf))))

#define g_find_end_f(f, l, sf, sl, p)  g_ptr_from_void(*(f))(g_find_end_p_impl(f, sizeof(*(f)), l, sizeof(*(l)), sf, sizeof(*(sf)), sl, sizeof(*(sl)), \
	G_FUNC_SPEC_2_D((int){0}, p, *(f), *(sf))))

#define G_SWAP_SAME_TYPE(a, b, size) do{\
	char temp[size];        \
	memcpy(temp, a, size);  \
	memcpy(a, b, size);     \
	memcpy(b,temp,size);    \
	}while(0)

#define g_swap_ranges(f1, l1, f2)  g_ptr_from_void(*(f2))(g_swap_ranges_impl(f1, sizeof(*(f1)), l1, sizeof(*(l1)), f2, sizeof(*(f2)), g_assign(*(f1),*(f2)), g_assign(*(f2),*(f1))))

#define g_random_shuffle(f1, l1) g_random_shuffle_impl(f1, sizeof(*(f1)), l1, sizeof(*(l1)))

#define g_random_shuffle_f(f1, l1, rgen) g_random_shuffle_r_impl(f1, sizeof(*(f1)), l1, sizeof(*(l1)), G_FUNC_SPEC_1_D((size_t){0}, rgen, (ptrdiff_t){0}))

#define g_find_first_of(f, l, sf, sl)  g_ptr_from_void(*(f))(g_find_first_of_impl(f, sizeof(*(f)), l, sizeof(*(l)), sf, sizeof(*(sf)), sl, sizeof(*(sl)), g_is_eq(*(f), *(sf))))

#define g_find_first_of_f(f, l, sf, sl, pred)  g_ptr_from_void(*(f))(g_find_first_of_p_impl(f, sizeof(*(f)), l, sizeof(*(l)), sf, sizeof(*(sf)), sl, sizeof(*(sl)), G_FUNC_SPEC_2_D((int){0}, pred, *(f), *(sf))))

#define g_lexicographical_compare(f1, l1, f2, l2) \
    g_lexicographical_compare_impl(f1, sizeof(*(f1)), l1, sizeof(*(l1)), f2, sizeof(*(f2)), l2, sizeof(*(l2)), g_is_lt(*(f1),*(f2)), g_is_lt(*(f2),*(f1)))

#define g_lexicographical_compare_f(f1, l1, f2, l2, comp) \
    g_lexicographical_compare_f_impl(f1, sizeof(*(f1)), l1, sizeof(*(l1)), f2, sizeof(*(f2)), l2, sizeof(*(l2)), G_FUNC_SPEC_2_D((int){0}, comp, *(f1),*(f2)), G_FUNC_SPEC_2_D((int){0}, comp, *(f2),*(f1)))

#define g_adjacent_find(f, l) g_ptr_from_void(*(f))(g_adjacent_find_impl(f, sizeof(*(f)), l, sizeof(*(l)), g_is_eq(*(f), *(f))))

#define g_adjacent_find_f(f, l, pred) g_ptr_from_void(*(f))(g_adjacent_find_f_impl(f, sizeof(*(f)), l, sizeof(*(l)), G_FUNC_SPEC_2_D((int){0}, pred, *(f), *(f) )))

#define g_search_n(f, l, count, value)  g_ptr_from_void(*(f))(g_search_n_impl(f, sizeof(*(f)), l, sizeof(*(l)), count, g_malloc_value(value)(value), g_is_eq(*(f), value)))

#define g_search_n_f(f, l, count, value, pred)  g_ptr_from_void(*(f))(g_search_n_f_impl(f, sizeof(*(f)), l, sizeof(*(l)), count, g_malloc_value(value)(value), \
	G_FUNC_SPEC_2_D((int){0}, pred, *(f), value )))

#define g_copy(f, l, d) g_ptr_from_void(*(d))(g_copy_impl(f, sizeof(*(f)), l, sizeof(*(l)), d, sizeof(*(d)), g_assign(*(d), *(f))))

#define g_copy_backward(f, l, d) g_ptr_from_void(*(d))(g_copy_backward_impl(f, sizeof(*(f)), l, sizeof(*(l)), d, sizeof(*(d)), g_assign(*(d), *(f))))

#define g_fill(f, l, value) g_fill_impl(f, sizeof(*(f)), l, sizeof(*(l)), g_malloc_value(value)(value), g_assign(*(f), value))

#define g_fill_n(f, c, value) g_fill_n_impl(f, sizeof(*(f)), c, g_malloc_value(value)(value), g_assign(*(f), value))


#define g_generate(f, l, gen) g_generate_impl(f, sizeof(*(f)), l, sizeof(*(l)), G_FUNC_SPEC_0_D(*(f), gen))

#define g_generate_n(f, c, gen) g_generate_n_impl(f, sizeof(*(f)), c, G_FUNC_SPEC_0_D(*(f), gen))

#define g_remove(f, l, value) g_ptr_from_void(*(f))(g_remove_impl(f, sizeof(*(f)), l, sizeof(*(l)), g_malloc_value(value)(value), g_is_eq(*(f),value), g_assign(*(f),*(f)))) 

#define g_remove_if(f, l, pred) g_ptr_from_void(*(f))(g_remove_if_impl(f, sizeof(*(f)), l, sizeof(*(l)), G_FUNC_SPEC_1_D((int){0}, pred, *(f)), g_assign(*(f),*(f)))) 

#define g_replace(f, l, value, nvalue) g_replace_impl(f, sizeof(*(f)), l, sizeof(*(l)), (g_malloc_value(value)(value)), (g_malloc_value(nvalue)(nvalue)), g_is_eq(*(f),value), g_assign(*(f),nvalue))

#define g_reverse(f, l) g_reverse_impl(f, sizeof(*(f)), l, sizeof(*(l)))

#define g_next_permutation(f,l) g_next_permutation_impl(f, sizeof(*(f)), l, sizeof(*(l)), g_is_lt(*(f),*(f)))

#define g_prev_permutation(f,l) g_next_permutation_impl(f, sizeof(*(f)), l, sizeof(*(l)), g_is_gt(*(f),*(f)))

#define g_sort(f,l) qsort(f, l - f, sizeof(*(f)), g_cmp(*(f),*(f)))

#define g_partition(f, l, pred) g_ptr_from_void(*(f))(g_partition_impl(f, sizeof(*(f)), l, sizeof(*(l)), G_FUNC_SPEC_1_D((int){0}, pred, *(f))))

#define g_rotate(f, n, l) g_ptr_from_void(*(f))(g_rotate_impl(f, sizeof(*(f)), n, sizeof(*(n)), l, sizeof(*(l))))

#define g_lower_bound(f, l, value) g_ptr_from_void(*(f))(g_lower_bound_impl(f, sizeof(*(f)), l, sizeof(*(l)), g_malloc_value(value)(value), g_is_lt(*(f), value)))

#define g_upper_bound(f, l, value) g_ptr_from_void(*(f))(g_lower_bound_impl(f, sizeof(*(f)), l, sizeof(*(l)), g_malloc_value(value)(value), g_is_le(*(f), value)))

#define g_lower_bound_f(f, l, value, comp) g_ptr_from_void(*(f))(g_lower_bound_f_impl(f, sizeof(*(f)), l, sizeof(*(l)), g_malloc_value(value)(value),     G_FUNC_SPEC_2_D((int){0}, comp, *(f), value)    ))

#define g_upper_bound_f(f, l, value, comp) g_ptr_from_void(*(f))(g_upper_bound_f_impl(f, sizeof(*(f)), l, sizeof(*(l)), g_malloc_value(value)(value),     G_FUNC_SPEC_2_D((int){0}, comp, value, *(f))    ))

#define g_clamp(val, minn, maxx) (G_A_T_E_2(val,minn,maxx), g_value_from_void_free(val)(g_clamp_impl(g_malloc_value(val)(val), g_malloc_value(minn)(minn), g_malloc_value(maxx)(maxx), g_is_lt(val, val))))

#define g_clamp_f(val, minn, maxx, comp) (G_A_T_E_2(val,minn,maxx), g_value_from_void_free(val)\
(g_clamp_f_impl(g_malloc_value(val)(val), g_malloc_value(minn)(minn), g_malloc_value(maxx)(maxx),     G_FUNC_SPEC_2_D((int){0}, comp, val, val)    )))

#define g_adjacent_difference(f, l, d) g_ptr_from_void(*(d))(g_adjacent_difference_impl(f, sizeof(*(f)), l, sizeof(*(l)), d, sizeof(*(d)), g_assign(*(f),*(f)), g_assign(*(d), *(f)), g_sub(*(f),*(f))))

#define g_adjacent_difference_f(f, l, d, func) \
g_ptr_from_void(*(d))(g_adjacent_difference_f_impl(f, sizeof(*(f)), l, sizeof(*(l)), d, sizeof(*(d)), g_assign(*(f),*(f)), g_assign(*(d), *(f)),       G_FUNC_SPEC_2_D(*(f),func,*(f),*(f))    ))


void* g_min_if_impl(void* pa, void* pb, func_spec_2_t funcspec);
void* g_max_if_impl(void* pa, void* pb, func_spec_2_t funcspec);
void* g_min_impl(void* pa, void* pb, _Bool(*less)(const void*, const void*));
void g_minmax_impl(void* pfirst, void* psecond, void* pa, void* pb,  _Bool(*is_lt)(const void*, const void*), void (*assign_f_from_a)(void* a, const void* b));
void g_minmax_f_impl(void* pfirst, void* psecond, void* pa, void* pb,  func_spec_2_t comp, void (*assign_f_from_a)(void* a, const void* b));
void g_minmax_element_impl(void* ppfirst, void* ppsecond, G_ITERARG(first), G_ITERARG(last), _Bool(*comp)(const void*, const void*));
void g_minmax_element_f_impl(void* ppfirst, void* ppsecond, G_ITERARG(first), G_ITERARG(last), func_spec_2_t comp);
void* g_min_element_impl(void*  first, const size_t first_size, void*  last, const size_t last_size, _Bool(*is_lt)(const void*, const void*));
void* g_min_element_f_impl(void*  first, const size_t first_size, void*  last, const size_t last_size, func_spec_2_t funcspec);
void* g_max_element_f_impl(void*  first, const size_t first_size, void*  last, const size_t last_size, func_spec_2_t funcspec);
void g_for_each_impl(void*  first, const size_t first_size, void*  last, const size_t last_size, func_spec_0_1_t funcspec);
void*  g_transform_2_impl(
	void*  first1, const size_t first1_size,
	void*  last1, const size_t last1_size,
	void*  first2, const size_t first2_size,
	void*  d_first, const size_t d_first_size,
	func_spec_2_t funcspec
);
ptrdiff_t g_count_impl(InputIt(first), InputIt(last), void* value, _Bool(*is_eq)(const void*, const void*));

ptrdiff_t g_count_if_impl(InputIt(first), InputIt(last), func_spec_1_t pred);
void  g_mismatch_impl(void* ret_first, void* ret_second, InputIt(first1), InputIt(last1), InputIt(first2), _Bool(*is_eq)(const void*, const void*));
void  g_mismatch_2_impl(void* ret_first, void* ret_second, 
	InputIt(first1), InputIt(last1), 
	InputIt(first2), InputIt(last2),
	_Bool(*is_eq)(const void*, const void*)); 
void  g_mismatch_p_impl(void* ret_first, void* ret_second, InputIt(first1), InputIt(last1), InputIt(first2), func_spec_2_t pred);
void  g_mismatch_p_2_impl(void* ret_first, void* ret_second, InputIt(first1), InputIt(last1), InputIt(first2), InputIt(last2), func_spec_2_t pred);
void* g_inner_product_impl(
	InputIt(first1), InputIt(last1),
	InputIt(first2), void* init, 
	
	void mul(void*, const void*, const void*),
	void add_eq(void*, const void*)
);
void* g_inner_product_op_impl(
	InputIt(first1), InputIt(last1),
	InputIt(first2), void* init, 	
	func_spec_2_t op1,
	func_spec_2_t op2
);
void* g_find_impl(InputIt(first), InputIt(last), void* value, _Bool(*is_eq)(const void*, const void*));
void* g_find_if_impl(InputIt(first), InputIt(last), func_spec_1_t pred);
void* g_find_if_not_impl(InputIt(first), InputIt(last), func_spec_1_t pred);
void g_iota_impl(ForwardIt(first), ForwardIt(last), void* value, void(*assign)(void*, const void*), void(*add_eq)(void*, const void*));
void* g_accumulate_impl(InputIt(first), InputIt(last), void* init, void(*add_eq)(void*, const void*));
void* g_accumulate_op_impl(InputIt(first), InputIt(last), void* init, func_spec_2_t op);
void* g_search_impl(ForwardIt(first), ForwardIt(last), ForwardIt(s_first), ForwardIt(s_last), _Bool(*is_eq)(const void*, const void*));
void* g_search_p_impl(ForwardIt(first), ForwardIt(last), ForwardIt(s_first), ForwardIt(s_last), func_spec_2_t pred);
void* g_find_end_impl(ForwardIt(first), ForwardIt(last),
                    ForwardIt(s_first), ForwardIt(s_last), _Bool(*is_eq)(const void*, const void*));
void* g_find_end_p_impl(ForwardIt(first), ForwardIt(last), ForwardIt(s_first), ForwardIt(s_last), func_spec_2_t pred);
void g_swap_impl(void* a, const size_t a_size, void* b, void(*assign_a_from_b)(void*, const void*), void(*assign_b_from_a)(void*, const void*));
void* g_swap_ranges_impl(ForwardIt (first1), ForwardIt (last1), ForwardIt (first2), void(*assign_a_from_b)(void*, const void*), void(*assign_b_from_a)(void*, const void*));
void g_random_shuffle_impl( RandomIt(first), RandomIt(last) );
void g_random_shuffle_r_impl( RandomIt(first), RandomIt(last), func_spec_1_t rgen);
void* g_find_first_of_impl(InputIt(first), InputIt(last), ForwardIt(s_first), ForwardIt(s_last), _Bool(*is_eq)(const void*, const void*));
void* g_find_first_of_p_impl(InputIt(first), InputIt(last), ForwardIt(s_first), ForwardIt(s_last), func_spec_2_t pred);
_Bool g_lexicographical_compare_impl(InputIt(first1), InputIt(last1), InputIt(first2), InputIt(last2),  _Bool(*is_lt_12)(const void*, const void*), _Bool(*is_lt_21)(const void*, const void*));
_Bool g_lexicographical_compare_f_impl(InputIt(first1), InputIt(last1), InputIt(first2), InputIt(last2), func_spec_2_t comp12, func_spec_2_t comp21);
void* g_adjacent_find_impl(ForwardIt(first), ForwardIt(last), _Bool(*is_eq)(const void*, const void*));
void* g_adjacent_find_f_impl(ForwardIt(first), ForwardIt(last), func_spec_2_t pred);
void* g_search_n_impl(ForwardIt(first), ForwardIt(last), int count, void* value, _Bool(*is_eq)(const void*, const void*) );
void* g_search_n_f_impl(ForwardIt(first), ForwardIt(last), int count, void* value, func_spec_2_t func);
void* g_copy_impl(InputIt(first), InputIt(last), OutputIt(d_first), void(*assign)(void*, const void*));
void*  g_copy_backward_impl(InputIt(first), InputIt(last), InputIt(d_last), void(*assign)(void*, const void*));
void g_fill_impl(ForwardIt(first), ForwardIt(last), void* value, void(*assign)(void*, const void*));
void* g_fill_n_impl(OutputIt(first), int count, void* value, void(*assign)(void*, const void*));
void g_generate_impl(ForwardIt(first), ForwardIt(last), func_spec_0_t gen);
void* g_generate_n_impl( OutputIt(first), int count, func_spec_0_t gen );
void* g_remove_impl(ForwardIt(first), ForwardIt(last), void* value, _Bool(*is_eq)(const void*, const void*), void(*assign)(void*, const void*));
void* g_remove_if_impl(ForwardIt(first), ForwardIt(last), func_spec_1_t is_eq, void(*assign)(void*, const void*));
void g_replace_impl(ForwardIt(first), ForwardIt(last), void* old_value, void* new_value, _Bool(*is_eq)(const void*, const void*), void(*assign)(void*, const void*));
void g_reverse_impl(ForwardIt(first), ForwardIt(last));
_Bool g_next_permutation_impl(ForwardIt(first), ForwardIt(last), _Bool(*is_lt)(const void*, const void*));
void* g_partition_impl(ForwardIt(first), ForwardIt(last), func_spec_1_t pred);
void* g_rotate_impl(ForwardIt(first), ForwardIt(n_first), ForwardIt(last));
void* g_lower_bound_impl(ForwardIt(first), ForwardIt(last), void* value, _Bool(*is_lt)(const void*, const void*));
void* g_lower_bound_f_impl(ForwardIt(first), ForwardIt(last), void* value, func_spec_2_t comp);
void* g_upper_bound_f_impl(ForwardIt(first), ForwardIt(last), void* value, func_spec_2_t comp);
void* g_clamp_impl(void* val, void* minn, void* maxx, _Bool(*is_lt)(const void* a, const void* b));
void* g_clamp_f_impl(void* val, void* minn, void* maxx, func_spec_2_t comp);
void* g_adjacent_difference_impl(InputIt(first), InputIt(last), OutputIt(d_first), void (*assign_f_f)(void*, const void*), void (*assign_d_f)(void*, const void*), 
	void (*sub_f_f)(void*, const void*, const void*)) ;
void* g_adjacent_difference_f_impl(InputIt(first), InputIt(last), OutputIt(d_first), void (*assign_f_f)(void*, const void*), void (*assign_d_f)(void*, const void*), 
	func_spec_2_t func) ;
 
void* g_transform_impl(
void*  first1, const size_t first1_size,
void*  last1, const size_t last1_size,
void*  d_first, const size_t d_first_size,
func_spec_1_t funcspec);





#endif


