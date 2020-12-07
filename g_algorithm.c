#include "g_algorithm.h"
  
 
	
void* g_min_if_impl(void* pa, void* pb, func_spec_2_t funcspec)
{
	int compret;
	G_CALL_FUNC_2(&compret, &funcspec, pa, pb);
	if(compret){
		GC_FREE(pb);
		return pa;
	}else{
		GC_FREE(pa);
		return pb;
	}
}



void* g_max_if_impl(void* pa, void* pb, func_spec_2_t funcspec)
{
	int compret;
	G_CALL_FUNC_2(&compret, &funcspec, pa, pb);
	if(!compret){
		GC_FREE(pb);
		return pa;
	}else{
		GC_FREE(pa);
		return pb;
	}
}




void* g_min_impl(void* pa, void* pb, _Bool(*less)(const void*, const void*))
{
	_Bool result = less(pa, pb);
	if(result)
	{	
		GC_FREE(pb);
		return pa;
	}
	else
	{
		GC_FREE(pa);
		return pb;
	}
}


void g_minmax_impl(void* pfirst, void* psecond, void* pa, void* pb,  _Bool(*is_lt)(const void*, const void*), void (*assign_f_from_a)(void* a, const void* b))
{
	_Bool result = is_lt(pa, pb);
	if(result)
	{
		assign_f_from_a(pfirst, pa);
		assign_f_from_a(psecond, pb);
	}
	else
	{
		assign_f_from_a(pfirst, pb);
		assign_f_from_a(psecond, pa);
	}
	GC_FREE(pa);
	GC_FREE(pb);
}


void g_minmax_f_impl(void* pfirst, void* psecond, void* pa, void* pb,  func_spec_2_t comp, void (*assign_f_from_a)(void* a, const void* b))
{
	int result ;
	G_CALL_FUNC_2(&result, &comp, pa, pb);
	if(result)
	{
		assign_f_from_a(pfirst, pa);
		assign_f_from_a(psecond, pb);
	}
	else
	{
		assign_f_from_a(pfirst, pb);
		assign_f_from_a(psecond, pa);
	}
	GC_FREE(pa);
	GC_FREE(pb);
}




void g_minmax_element_impl(void* ppfirst, void* ppsecond, G_ITERARG(first), G_ITERARG(last), _Bool(*comp)(const void*, const void*))
{
    assert(first_size == last_size);
   
    void* minn = first;
    void* maxx = first;
 
    if (first == last || G_INCPTR(first) == last)
    {
        goto RETURN;
    }
 
    if (comp(first, minn)) {
        minn = first;
    } else {
        maxx = first;
    }
 
    while (G_INCPTR(first) != last) {
        void* i = first;
        if (G_INCPTR(first) == last) {
            if (comp(i, minn)) minn = i;
            else if (!(comp(i, maxx))) maxx = i;
            break;
        } else {
            if (comp(first, i)) {
                if (comp(first, minn)) minn = first;
                if (!(comp(i, maxx))) maxx = i;
            } else {
                if (comp(i, minn)) minn = i;
                if (!(comp(first, maxx))) maxx = first;
            }
        }
    }
   RETURN:
    memcpy(ppfirst, &minn, sizeof(void*));
    memcpy(ppsecond, &maxx, sizeof(void*));
    return ;
}




void g_minmax_element_f_impl(void* ppfirst, void* ppsecond, G_ITERARG(first), G_ITERARG(last), func_spec_2_t comp)
{
    assert(first_size == last_size);
    int compret;
    void* minn = first;
    void* maxx = first;
 
    if (first == last || G_INCPTR(first) == last)
    {
        goto RETURN;
    }
 
    if (G_CALL_FUNC_2_RET(&compret, &comp, first, minn)) {
        minn = first;
    } else {
        maxx = first;
    }
 
    while (G_INCPTR(first) != last) {
        void* i = first;
        if (G_INCPTR(first) == last) {
            if (G_CALL_FUNC_2_RET(&compret,  &comp, i, minn)) minn = i;
            else if (!(G_CALL_FUNC_2_RET(&compret,  &comp,i, maxx))) maxx = i;
            break;
        } else {
            if (G_CALL_FUNC_2_RET(&compret,  &comp,first, i)) {
                if (G_CALL_FUNC_2_RET(&compret,  &comp,first, minn)) minn = first;
                if (!(G_CALL_FUNC_2_RET(&compret,  &comp,i, maxx))) maxx = i;
            } else {
                if (G_CALL_FUNC_2_RET(&compret,  &comp,i, minn)) minn = i;
                if (!(G_CALL_FUNC_2_RET(&compret,  &comp,first, maxx))) maxx = first;
            }
        }
    }
   RETURN:
    memcpy(ppfirst, &minn, sizeof(void*));
    memcpy(ppsecond, &maxx, sizeof(void*));
    return ;
}



void* g_min_element_impl(void*  first, const size_t first_size, void*  last, const size_t last_size, _Bool(*is_lt)(const void*, const void*))
{
    assert(first_size == last_size);
    if (first == last) return last; 
    void* smallest = first;
    G_INCPTR(first);
    for (; first != last; G_INCPTR(first)) {
        if (is_lt(first,smallest)) {
            smallest = first;
        }
    }
    return smallest;
}



void* g_min_element_f_impl(void*  first, const size_t first_size, void*  last, const size_t last_size, func_spec_2_t funcspec)
{
    assert(first_size == last_size);
    int compret;
    if (first == last) return last;
 
    void* smallest = first;
    G_INCPTR(first);
    for (; first != last; G_INCPTR(first)) {
        G_CALL_FUNC_2(&compret, &funcspec, first, smallest);
        if (compret) {
            smallest = first;
        }
    }
    return smallest;
}
//g_ptr_from_void(*(f))(


void* g_max_element_f_impl(void*  first, const size_t first_size, void*  last, const size_t last_size, func_spec_2_t funcspec)
{
    assert(first_size == last_size);
    int compret;
    if (first == last) return last;
 
    void* largest = first;
    G_INCPTR(first);
    for (; first != last; G_INCPTR(first)) {
        G_CALL_FUNC_2(&compret, &funcspec, largest, first);
        if (compret) {
            largest = first;
        }
    }
    return largest;
}



void g_for_each_impl(void*  first, const size_t first_size, void*  last, const size_t last_size, func_spec_0_1_t funcspec)
{
    assert(first_size == last_size);
    for (; first != last; G_INCPTR(first)) {
	G_CALL_FUNC_0_1(&funcspec, first);       
    }
}
//G_FUNC_SPEC_0_1(func, arg1src)


void* g_transform_impl(
void*  first1, const size_t first1_size,
void*  last1, const size_t last1_size,
void*  d_first, const size_t d_first_size,
func_spec_1_t funcspec)
{
    assert(first1_size == last1_size);
    while (first1 != last1) {
	G_CALL_FUNC_1(d_first, &funcspec, first1);
	G_INCPTR(d_first);
	G_INCPTR(first1);	
    }
    return d_first;
}


void*  g_transform_2_impl(
	void*  first1, const size_t first1_size,
	void*  last1, const size_t last1_size,
	void*  first2, const size_t first2_size,
	void*  d_first, const size_t d_first_size,
	func_spec_2_t funcspec
)
{
    assert(first1_size == last1_size);
    while (first1 != last1) {
        G_CALL_FUNC_2(d_first, &funcspec, first1, first2);
        //*d_first++ = binary_op(*first1++, *first2++);
	G_INCPTR(d_first);
	G_INCPTR(first1);
	G_INCPTR(first2);
    }
    return d_first;
}


ptrdiff_t g_count_impl(InputIt(first), InputIt(last), void* value, _Bool(*is_eq)(const void*, const void*))
{
    assert(first_size == last_size);
    ptrdiff_t ret = 0;
    for (; first != last; G_INCPTR(first)) {
        if (is_eq(first, value)) {
            ret++;
        }
    }
    GC_FREE(value);
    return ret;
}


ptrdiff_t g_count_if_impl(InputIt(first), InputIt(last), func_spec_1_t pred)
{
    assert(first_size == last_size);
    ptrdiff_t ret = 0;
    for (; first != last; G_INCPTR(first)) {
	int predval;
	G_CALL_FUNC_1(&predval, &pred, first);
        if (predval) {
            ret++;
        }
    }
    return ret;
}


void  g_mismatch_impl(void* ret_first, void* ret_second, InputIt(first1), InputIt(last1), InputIt(first2), _Bool(*is_eq)(const void*, const void*))
{
    assert(first1_size == last1_size);
    while (first1 != last1 && is_eq(first1,first2)) {
        G_INCPTR(first1); G_INCPTR(first2);
    }
    memcpy(ret_first, &first1, sizeof(void*));
    memcpy(ret_second, &first2, sizeof(void*));
}


void  g_mismatch_2_impl(void* ret_first, void* ret_second, 
	InputIt(first1), InputIt(last1), 
	InputIt(first2), InputIt(last2),
	_Bool(*is_eq)(const void*, const void*))
{
    assert(first1_size == last1_size);
    assert(first2_size == last2_size);
    while (first1 != last1 && first2 != last2 && is_eq(first1,first2)) {
        G_INCPTR(first1); G_INCPTR(first2);
    }
    memcpy(ret_first, &first1, sizeof(void*));
    memcpy(ret_second, &first2, sizeof(void*));
}



 

void  g_mismatch_p_impl(void* ret_first, void* ret_second, InputIt(first1), InputIt(last1), InputIt(first2), func_spec_2_t pred)
{
    assert(first1_size == last1_size);
    int predret;
    while (first1 != last1 && G_CALL_FUNC_2_RET(&predret, &pred, first1,first2)) {
        G_INCPTR(first1); G_INCPTR(first2);
    }
    memcpy(ret_first, &first1, sizeof(void*));
    memcpy(ret_second, &first2, sizeof(void*));
}




void  g_mismatch_p_2_impl(void* ret_first, void* ret_second, InputIt(first1), InputIt(last1), InputIt(first2), InputIt(last2), func_spec_2_t pred)
{
    assert(first1_size == last1_size);
    assert(first2_size == last2_size);
    int predret;
    while (first1 != last1 && first2 != last2 && G_CALL_FUNC_2_RET(&predret, &pred, first1,first2)) {
        G_INCPTR(first1); G_INCPTR(first2);
    }
    memcpy(ret_first, &first1, sizeof(void*));
    memcpy(ret_second, &first2, sizeof(void*));
}




 

void* g_inner_product_impl(
	InputIt(first1), InputIt(last1),
	InputIt(first2), void* init, 
	
	void mul(void*, const void*, const void*),
	void add_eq(void*, const void*)
)
{
    assert(first1_size == last1_size);
    char mul_tmp[V_STO_SIZE] = {0};
    while (first1 != last1) {
        mul(mul_tmp, first1, first2);
	add_eq(init, mul_tmp);
        G_INCPTR(first1);
        G_INCPTR(first2);
    }
    return init;
}



void* g_inner_product_op_impl(
	InputIt(first1), InputIt(last1),
	InputIt(first2), void* init, 	
	func_spec_2_t op1,
	func_spec_2_t op2
)
{
    assert(first1_size == last1_size);    
    char op2_tmp[V_STO_SIZE] = {0};
    while (first1 != last1) {
	G_CALL_FUNC_2(op2_tmp, &op2, first1, first2);
	G_CALL_FUNC_2(init, &op1, init, op2_tmp);        
        G_INCPTR(first1);
        G_INCPTR(first2);
    }
    return init;
}




void* g_find_impl(InputIt(first), InputIt(last), void* value, _Bool(*is_eq)(const void*, const void*))
{
    assert(first_size == last_size);
    for (; first != last; G_INCPTR(first)) {
        if (is_eq(first, value)) {
	    GC_FREE(value);
            return first;
        }
    }
    GC_FREE(value);
    return last;
}



void* g_find_if_impl(InputIt(first), InputIt(last), func_spec_1_t pred)
{
    assert(first_size == last_size);
    for (; first != last;  G_INCPTR(first)) {
        int predret;
	G_CALL_FUNC_1(&predret, &pred, first);
        if (predret) {
            return first;
        }
    }
    return last;
}


void* g_find_if_not_impl(InputIt(first), InputIt(last), func_spec_1_t pred)
{
    assert(first_size == last_size);
    for (; first != last;  G_INCPTR(first)) {
        int predret;
	G_CALL_FUNC_1(&predret, &pred, first);
        if (!predret) {
            return first;
        }
    }
    return last;
}




void g_iota_impl(ForwardIt(first), ForwardIt(last), void* value, void(*assign)(void*, const void*), void(*add_eq)(void*, const void*))
{
    int one = 1;
   
    assert(first_size == last_size);
    
    while(first != last) {       
        
	assign(first, value);
        add_eq(value, &one);
	G_INCPTR(first);	
    }
    GC_FREE(value);
}



void* g_accumulate_impl(InputIt(first), InputIt(last), void* init, void(*add_eq)(void*, const void*))
{
    assert(first_size == last_size);
    for (; first != last; G_INCPTR(first)) {
        add_eq(init, first);
    }
    return init;
}



void* g_accumulate_op_impl(InputIt(first), InputIt(last), void* init, func_spec_2_t op)
{
    assert(first_size == last_size);
    for (; first != last; G_INCPTR(first)) {
        G_CALL_FUNC_2(init, &op, init, first);
       // init = op(std::move(init), *first);  
    }
    return init;
}



void* g_search_impl(ForwardIt(first), ForwardIt(last), ForwardIt(s_first), ForwardIt(s_last), _Bool(*is_eq)(const void*, const void*))
{
    assert(first_size == last_size);
    assert(s_first_size == s_last_size);
    for (; ; G_INCPTR(first)) {
        void* it = first;
	const size_t it_size = first_size;
	void* s_it;
	const size_t  s_it_size = s_first_size;
        for (s_it = s_first; ; G_INCPTR(it), G_INCPTR(s_it)) {
            if (s_it == s_last) {
                return first;
            }
            if (it == last) {
                return last;
            }
            if (!(is_eq(it, s_it))) {
                break;
            }
        }
    }
}

void* g_search_p_impl(ForwardIt(first), ForwardIt(last), ForwardIt(s_first), ForwardIt(s_last), func_spec_2_t pred)
{
    assert(first_size == last_size);
    assert(s_first_size == s_last_size);
    for (; ; G_INCPTR(first)) {
        void* it = first;
	const size_t it_size = first_size;
	void* s_it;
	const size_t  s_it_size = s_first_size;
        for (s_it = s_first; ; G_INCPTR(it), G_INCPTR(s_it)) {
            if (s_it == s_last) {
                return first;
            }
            if (it == last) {
                return last;
            }
	    int predret;
	    G_CALL_FUNC_2(&predret, &pred, it, s_it);
            if (!predret) {
                break;
            }
        }
    }
}


void* g_find_end_impl(ForwardIt(first), ForwardIt(last),
                    ForwardIt(s_first), ForwardIt(s_last), _Bool(*is_eq)(const void*, const void*))
{
    if (s_first == s_last)
        return last;
    void* result = last;
    while (1) {
        void* new_result = g_search_impl(first, first_size, last, last_size, s_first, s_first_size, s_last, s_last_size, is_eq);
        if (new_result == last) {
            break;
        } else {
            result = new_result;
            first = result;
            G_INCPTR(first);
        }
    }
    return result;
}


void* g_find_end_p_impl(ForwardIt(first), ForwardIt(last), ForwardIt(s_first), ForwardIt(s_last), func_spec_2_t pred)
{
    if (s_first == s_last)
        return last;
    void* result = last;
    while (1) {
        void* new_result = g_search_p_impl(first, first_size, last, last_size, s_first, s_first_size, s_last, s_last_size, pred);
        if (new_result == last) {
            break;
        } else {
            result = new_result;
            first = result;
            G_INCPTR(first);
        }
    }
    return result;
}




void g_swap_impl(void* a, const size_t a_size, void* b, void(*assign_a_from_b)(void*, const void*), void(*assign_b_from_a)(void*, const void*))
{
	char temp[a_size];
	memcpy(temp, a, a_size);
	assign_a_from_b(a, b);
	assign_b_from_a(b, temp);	
}


void* g_swap_ranges_impl(ForwardIt (first1), ForwardIt (last1), ForwardIt (first2), void(*assign_a_from_b)(void*, const void*), void(*assign_b_from_a)(void*, const void*))
{
    assert(first1_size == last1_size);
    while (first1 != last1) {
        g_swap_impl(first1, first1_size, first2, assign_a_from_b, assign_b_from_a);
	G_INCPTR(first1);G_INCPTR(first2);
    }
    return first2;
}






void g_random_shuffle_impl( RandomIt(first), RandomIt(last) )
{
    assert(first_size == last_size);
    ptrdiff_t i, n;
    n = ((char*)last - (char*)first)/first_size;
    for (i = n-1; i > 0; --i) {
        size_t rnum = rand() % (i + 1);
        G_SWAP_SAME_TYPE(G_SUBSCRIPT(first, first_size, i), G_SUBSCRIPT(first, first_size, rnum), first_size);        
    }
}


void g_random_shuffle_r_impl( RandomIt(first), RandomIt(last), func_spec_1_t rgen)
{
    assert(first_size == last_size);
    ptrdiff_t i, n;
    n = ((char*)last - (char*)first)/first_size;
    for (i = n-1; i > 0; --i) {
        ptrdiff_t i_plus_1 = i + 1;
	size_t rnum;
        G_CALL_FUNC_1(&rnum, &rgen, &i_plus_1);       
        G_SWAP_SAME_TYPE(G_SUBSCRIPT(first, first_size, i), G_SUBSCRIPT(first, first_size, rnum), first_size);        
    }
}


 


void* g_find_first_of_impl(InputIt(first), InputIt(last), ForwardIt(s_first), ForwardIt(s_last), _Bool(*is_eq)(const void*, const void*))
{
    assert(first_size == last_size);
    assert(s_first_size == s_last_size);
    for (; first != last; G_INCPTR(first)) {
        void* it ;
	const size_t it_size = s_first_size;
        for (it = s_first; it != s_last; G_INCPTR(it)) {
            if (is_eq(first,it)) {
                return first;
            }
        }
    }
    return last;
}



void* g_find_first_of_p_impl(InputIt(first), InputIt(last), ForwardIt(s_first), ForwardIt(s_last), func_spec_2_t pred)
{
    assert(first_size == last_size);
    assert(s_first_size == s_last_size);
    for (; first != last; G_INCPTR(first)) {
        void* it ;
	const size_t it_size = s_first_size;
        for (it = s_first; it != s_last; G_INCPTR(it)) {
	    int predret;
	    G_CALL_FUNC_2(&predret, &pred, first, it);
            if (predret) {
                return first;
            }
        }
    }
    return last;
}


_Bool g_lexicographical_compare_impl(InputIt(first1), InputIt(last1), InputIt(first2), InputIt(last2),  _Bool(*is_lt_12)(const void*, const void*), _Bool(*is_lt_21)(const void*, const void*))
{
    assert(first1_size == last1_size);
    assert(first2_size == last2_size);    
    for ( ; (first1 != last1) && (first2 != last2); G_INCPTR(first1), G_INCPTR(first2) ) {
        if (is_lt_12(first1,first2)) return 1;
        if (is_lt_21(first2,first1)) return 0;
    }
    return (first1 == last1) && (first2 != last2);
}


_Bool g_lexicographical_compare_f_impl(InputIt(first1), InputIt(last1), InputIt(first2), InputIt(last2), func_spec_2_t comp12, func_spec_2_t comp21)
{
    assert(first1_size == last1_size);
    assert(first2_size == last2_size);    
    for ( ; (first1 != last1) && (first2 != last2); G_INCPTR(first1), G_INCPTR(first2) ) {
        int compret;
	G_CALL_FUNC_2(&compret, &comp12, first1, first2);
        if (compret) return 1;
	
	G_CALL_FUNC_2(&compret, &comp21, first2, first1);
        if (compret) return 0;
    }
    return (first1 == last1) && (first2 != last2);
}



void* g_adjacent_find_impl(ForwardIt(first), ForwardIt(last), _Bool(*is_eq)(const void*, const void*))
{
    assert(first_size == last_size);
    if (first == last) {
        return last;
    }
    void* next = first;
    const size_t next_size = first_size;
    G_INCPTR(next);
    for (; next != last; G_INCPTR(next), G_INCPTR(first)) {
        if (is_eq(first,next)) {
            return first;
        }
    }
    return last;
}
 

void* g_adjacent_find_f_impl(ForwardIt(first), ForwardIt(last), func_spec_2_t pred)
{
    assert(first_size == last_size);
    if (first == last) {
        return last;
    }
    void* next = first;
    const size_t next_size = first_size;
    G_INCPTR(next);
    for (; next != last; G_INCPTR(next), G_INCPTR(first)) {
        int predret;
	G_CALL_FUNC_2(&predret, &pred, first, next);
        if (predret) {
            return first;
        }
    }
    return last;
}
 

void* g_search_n_impl(ForwardIt(first), ForwardIt(last), int count, void* value, _Bool(*is_eq)(const void*, const void*) )
{
    assert(first_size == last_size);
    if (count <= 0) {
        GC_FREE(value);
        return first;
    }
    for(; first != last; G_INCPTR(first)) {
        if (!is_eq(first , value)) {
            continue;
        } 
        void* candidate = first;
	
        int cur_count = 0;
        while (1) {
            ++cur_count;
            if (cur_count >= count) {
                // success
		GC_FREE(value);
                return candidate;
            }
            G_INCPTR(first);
            if (first == last) {
                // exhausted the list
		GC_FREE(value);
                return last;
            }
            if (!is_eq(first , value)) {
                // too few in a row
                break;
            }
        }
    }
    GC_FREE(value);
    return last;
}


//#define PFL printf("%s:%d\n", __FILE__, __LINE__)

void* g_search_n_f_impl(ForwardIt(first), ForwardIt(last), int count, void* value, func_spec_2_t func)
{
    int is_eq;
    assert(first_size == last_size);
    if (count <= 0) {
        GC_FREE(value);
        return first;
    }
    for(; first != last; G_INCPTR(first)) {
        G_CALL_FUNC_2(&is_eq, &func, first, value);
        if (!is_eq ) {
            continue;
        } 
        void* candidate = first;
	
        int cur_count = 0;
        while (1) {
            ++cur_count;
            if (cur_count >= count) {
                // success
		GC_FREE(value);
                return candidate;
            }
            G_INCPTR(first);
	    
            if (first == last) {
                // exhausted the list
		GC_FREE(value);
                return last;
            }
	    G_CALL_FUNC_2(&is_eq, &func, first, value);
            if (!is_eq ) {
                // too few in a row
                break;
            }
        }
    }
    GC_FREE(value);
    return last;
}



// // 

void* g_copy_impl(InputIt(first), InputIt(last), OutputIt(d_first), void(*assign)(void*, const void*))
{
    assert(first_size == last_size);
    while (first != last) {
        assign(d_first,first);
	G_INCPTR(d_first);
	G_INCPTR(first);
    }
    return d_first;
}



 
void*  g_copy_backward_impl(InputIt(first), InputIt(last), InputIt(d_last), void(*assign)(void*, const void*))
{
    assert(first_size == last_size);
    while (first != last) {
        G_DECPTR(d_last);
	G_DECPTR(last);
        assign(d_last, last);
    }
    return d_last;
}



void g_fill_impl(ForwardIt(first), ForwardIt(last), void* value, void(*assign)(void*, const void*))
{
    assert(first_size == last_size);
    for (; first != last;  G_INCPTR(first)) {
        assign(first, value);
    }
    GC_FREE(value);
}



void* g_fill_n_impl(OutputIt(first), int count, void* value, void(*assign)(void*, const void*))
{
    for (int i = 0; i < count; i++) {
        assign(first, value);
	G_INCPTR(first);
    }
    return first;
}



void g_generate_impl(ForwardIt(first), ForwardIt(last), func_spec_0_t gen)
{
    assert(first_size == last_size);
    while (first != last) {
        //*first++ = g();
	G_CALL_FUNC_0(first, &gen);
	G_INCPTR(first);
    }
}



void* g_generate_n_impl( OutputIt(first), int count, func_spec_0_t gen )
{
    for( int i = 0; i < count; i++ ) {
        G_CALL_FUNC_0(first, &gen);
	G_INCPTR(first);
    }
    return first;
}




void* g_remove_impl(ForwardIt(first), ForwardIt(last), void* value, _Bool(*is_eq)(const void*, const void*), void(*assign)(void*, const void*))
{
    first = g_find_impl(first, first_size, last, last_size, value, is_eq);
    if (first != last){
        void* i;
	const size_t i_size = first_size;
        for(i = first; G_INCPTR(i) != last; ){
            if (!is_eq(i, value)){                
		assign(first, i);
		G_INCPTR(first);
            }
        }
    }
    return first;
}



void* g_remove_if_impl(ForwardIt(first), ForwardIt(last), func_spec_1_t is_eq, void(*assign)(void*, const void*))
{
    first = g_find_if_impl(first, first_size, last, last_size, is_eq);
    if (first != last){
        void* i;
	const size_t i_size = first_size;
        for(i = first; G_INCPTR(i) != last; ){
	    int eqret;
	    G_CALL_FUNC_1(&eqret, &is_eq, i);
            if (!eqret){                
		assign(first, i);
		G_INCPTR(first);
            }
        }
    }
    return first;
}



void g_replace_impl(ForwardIt(first), ForwardIt(last), void* old_value, void* new_value, _Bool(*is_eq)(const void*, const void*), void(*assign)(void*, const void*))
{
    assert(first_size == last_size);
    for (; first != last; G_INCPTR(first)) {
        if (is_eq(first,  old_value)) {
            assign(first, new_value);
        }
    }
    GC_FREE(old_value);
    GC_FREE(new_value);    
}



void g_reverse_impl(ForwardIt(first), ForwardIt(last))
{
    assert(first_size == last_size);
    while ((first != last) && (first != G_DECPTR(last))) {
        G_SWAP_SAME_TYPE(first, last, first_size);
	G_INCPTR(first);
    }
}


_Bool g_next_permutation_impl(ForwardIt(first), ForwardIt(last), _Bool(*is_lt)(const void*, const void*))
{
    assert(first_size == last_size);
    if (first == last) return false;
    void* i = last;
    const size_t i_size = last_size;
    if (first == G_DECPTR(i)) return false;
 
    while (true) {
        void* i1;
	void* i2;
	const size_t i1_size = i_size;
        const size_t i2_size = last_size;
	
        i1 = i;
        if (is_lt(G_DECPTR(i) , i1)) {
            i2 = last;
            while (!is_lt(i , G_DECPTR(i2)))
                ;
            G_SWAP_SAME_TYPE(i, i2, i_size);
            g_reverse_impl(i1, i1_size, last, last_size);
            return true;
        }
        if (i == first) {
            g_reverse_impl(first, first_size, last, last_size);
            return false;
        }
    }
}


void* g_partition_impl(ForwardIt(first), ForwardIt(last), func_spec_1_t pred)
{
    assert(first_size == last_size);
    first = g_find_if_not_impl(first, first_size,  last, last_size, pred);
    if (first == last) return first;
    void* i = G_NEXT(first);
    const size_t i_size = first_size;
    for (; i != last; G_INCPTR(i)) {
        int predret;
	G_CALL_FUNC_1(&predret, &pred, i);
        if (predret) {
            G_SWAP_SAME_TYPE(i, first, i_size);
            G_INCPTR(first);
        }
    }
    return first;
}


void* g_rotate_impl(ForwardIt(first), ForwardIt(n_first), ForwardIt(last))
{
   if(first == n_first) return last;
   if(n_first == last) return first;
 
   void* read      = n_first;
   void* write     = first;
   void* next_read = first; // read position for when "read" hits "last"
   const size_t read_size = n_first_size;
   const size_t write_size = first_size;
   const size_t next_read_size = first_size;
 
   while(read != last) {
      if(write == next_read) next_read = read; // track where "first" went
      G_SWAP_SAME_TYPE(write, read, write_size);
      G_INCPTR(write);
      G_INCPTR(read);      
   }
 
   // rotate the remaining sequence into place
   g_rotate_impl(write, write_size, next_read, next_read_size, last, last_size);
   return write;
}


void* g_lower_bound_impl(ForwardIt(first), ForwardIt(last), void* value, _Bool(*is_lt)(const void*, const void*))
{
    assert(first_size == last_size);
    void* it;
    const size_t it_size = first_size;
    int count, step;
    count = G_DISTANCE(first, last); 
    while (count > 0) {
        it = first; 
        step = count / 2; 
        G_ADVANCE(it, step);
        if (is_lt(it,value)) {
            first = G_INCPTR(it); 
            count -= step + 1; 
        }
        else
            count = step;
    }
    GC_FREE(value);
    return first;
}


void* g_lower_bound_f_impl(ForwardIt(first), ForwardIt(last), void* value, func_spec_2_t comp)
{
    assert(first_size == last_size);
    int compret;
    void* it;
    const size_t it_size = first_size;
    int count, step;
    count = G_DISTANCE(first, last); 
    while (count > 0) {
        it = first; 
        step = count / 2; 
        G_ADVANCE(it, step);
	G_CALL_FUNC_2(&compret, &comp, it, value);
        if (compret) {
            first = G_INCPTR(it); 
            count -= step + 1; 
        }
        else
            count = step;
    }
    GC_FREE(value);
    return first;
}


void* g_upper_bound_f_impl(ForwardIt(first), ForwardIt(last), void* value, func_spec_2_t comp)
{
    assert(first_size == last_size);
    int compret;
    void* it;
    const size_t it_size = first_size;
    int count, step;
    count = G_DISTANCE(first, last); 
    while (count > 0) {
        it = first; 
        step = count / 2; 
        G_ADVANCE(it, step);
	G_CALL_FUNC_2(&compret, &comp, value, it);
        if (!compret) {
            first = G_INCPTR(it); 
            count -= step + 1; 
        }
        else
            count = step;
    }
    GC_FREE(value);
    return first;
}


void* g_clamp_impl(void* val, void* minn, void* maxx, _Bool(*is_lt)(const void* a, const void* b))
{
	if(is_lt(val, minn))
	{
		GC_FREE(val);
		GC_FREE(maxx);
		return minn;
	}
	if(is_lt(maxx, val))
	{
		GC_FREE(val);
		GC_FREE(minn);
		return maxx;
	}
	GC_FREE(minn);
	GC_FREE(maxx);
	return val;
}


void* g_clamp_f_impl(void* val, void* minn, void* maxx, func_spec_2_t comp)
{
	int compret;
	G_CALL_FUNC_2(&compret, &comp, val, minn);
	if(compret)
	{
		GC_FREE(val);
		GC_FREE(maxx);
		return minn;
	}
	G_CALL_FUNC_2(&compret, &comp, maxx, val);
	if(compret)
	{
		GC_FREE(val);
		GC_FREE(minn);
		return maxx;
	}
	GC_FREE(minn);
	GC_FREE(maxx);
	return val;
}


void* g_adjacent_difference_impl(InputIt(first), InputIt(last), OutputIt(d_first), void (*assign_f_f)(void*, const void*), void (*assign_d_f)(void*, const void*), 
	void (*sub_f_f)(void*, const void*, const void*))
{
    char acc[first_size];
    char val[first_size];
    char diff[first_size];
    assert(first_size == last_size);
    if (first == last) return d_first;
   // typedef typename std::iterator_traits<InputIt>::value_type value_t;
    //value_t acc = *first;
    assign_f_f(acc, first);
    //*d_first = acc;
    assign_d_f(d_first, acc);
    while (G_INCPTR(first) != last) {
        //value_t val = *first;
	assign_f_f(val, first); 
	 
	G_INCPTR(d_first);
	sub_f_f(diff, val, acc);
	assign_d_f(d_first, diff);
	assign_f_f(acc, val);
	
        //*++d_first = val - std::move(acc); // std::move since C++20
        //acc = std::move(val);
    }
    G_INCPTR(d_first);
    return d_first;
}


void* g_adjacent_difference_f_impl(InputIt(first), InputIt(last), OutputIt(d_first), void (*assign_f_f)(void*, const void*), void (*assign_d_f)(void*, const void*), 
	func_spec_2_t func)
{
    char acc[first_size];
    char val[first_size];
    char diff[first_size];
    assert(first_size == last_size);
    if (first == last) return d_first;
    assign_f_f(acc, first);
    assign_d_f(d_first, acc);
    while (G_INCPTR(first) != last) {
	assign_f_f(val, first); 
	G_INCPTR(d_first);	
	G_CALL_FUNC_2(diff, &func, val, acc);
	assign_d_f(d_first, diff);
	assign_f_f(acc, val);
    }
    G_INCPTR(d_first);
    return d_first;
}




 

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

