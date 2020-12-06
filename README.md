# g_algorithm v0.0

This is a proof of concept to show how C++ `<algorithm>` functions can be implemented in C11. 

The underlying technique is to use an exhaustive list of pre-generated **_Generic** functions to create a sort of "generic infrastructure" for 
supported types, along with void pointers and macros. 

## Limitations

The g_algorithm library can only be compiled with C11 with VLAs.

The container-oriented algorithms only work on C-style arrays. 

The g_algorithm library only implements a subset of the C++ `<algorithm>` library. 

These algorithms are most likely slower than custom written code. 

These algorithms only support fundamental types. If G_BASIC_FULL is defined, then all the fundamental non-pointer
types **{ _Bool, char, ... , long double _Complex }** are supported. If G_BASIC_ABBREV is defined, then 
only a subset of the fundamental types are supported:
*  _Bool 
*  char 
*  short 
*  int 
*  long 
*  unsigned long 
*  float 
*  double 

Due to the combinations of types, there's a sort of "combinatorial explosion" of _Generic macros, as more types are used. 
Thus, the abbreviated **g_basic_abbrev.h** header is over 5000 lines long, but the non-abbreviated **g_basic.h** is over
46,000 lines long. This has a huge impact on compilation times, and takes 100 times as long to compile with the full 
**g_basic.h** file. 

## Instructions

To build and run a test, type:

```
./maketest.sh  
./dotest.sh
```

The output should say "SUCCESS" if all is well. 

If you want to generate new **g_basic.h** and **g_basic_abbrev.h** files, then type:

```
cd codegen
./makegen.sh  
./gen_full  
./gen_abbrev  
```

The gen_* executables make use of the file **errors.txt** to avoid erroneous code generation. If a line of code is found in **errors.txt**, 
the generator will not write that line to the corresponding g_basic file.  

## Function Listing

The g_algorithm functions attempt to emulate their C++ counterparts somewhat closely, as far as the limitations of 
C11 will allow. 

C++ functions which previously returned a pair now put the result in a pointer argument. For example, in C++, the function **minmax** returns a 
pair with two values. However, in g_algorithm, the **g_minmax** function actually returns void, but takes a pointer to a pair as the
first argument. 

C11 doesn't readily allow function overloading based on different numbers of arguments. Thus, a "wart" is attached 
to the function name to indicate which function is being used. For example, the C++ **mismatch** function has numerous variants
based on the number of iterators passed, and whether a predicate is provided. In g_algorithm, these variants are distinguished
by appending _2 or _p (or both) to the function name. 

Below is a list of all the functions implemented in g_algorithm. Each one links to the pertinent C++ entry at cppreference.com. 

[`T g_accumulate(T* first, T* last, T init)                                                              `](https://en.cppreference.com/w/cpp/algorithm/accumulate)     
[`T g_accumulate_f(T* first, T* last, T init, Function op)                                               `](https://en.cppreference.com/w/cpp/algorithm/accumulate)     
[`T* g_adjacent_difference(T* first, T* last, T* dest)                                                   `](https://en.cppreference.com/w/cpp/algorithm/adjacent_difference)     
[`T* g_adjacent_difference_f(T* first, T* last, T* dest, Function func)                                  `](https://en.cppreference.com/w/cpp/algorithm/adjacent_difference)     
[`T* g_adjacent_find(T* first, T* last)                                                                  `](https://en.cppreference.com/w/cpp/algorithm/adjacent_find)     
[`T* g_adjacent_find_f(T* first, T* last, Function pred)                                                 `](https://en.cppreference.com/w/cpp/algorithm/adjacent_find)     
[`bool g_all_of(T* first, T* last, Function pred)                                                        `](https://en.cppreference.com/w/cpp/algorithm/all_of)     
[`bool g_any_of(T* first, T* last, Function pred)                                                        `](https://en.cppreference.com/w/cpp/algorithm/any_of)     
[`T g_clamp(T val, T minn, T maxx)                                                                       `](https://en.cppreference.com/w/cpp/algorithm/clamp)     
[`T g_clamp_f(T val, T minn, T maxx, Function comp)                                                      `](https://en.cppreference.com/w/cpp/algorithm/clamp)     
[`T* g_copy(T* first, T* last, T* dest)                                                                  `](https://en.cppreference.com/w/cpp/algorithm/copy)     
[`T* g_copy_backward(T* first, T* last, T* dest)                                                         `](https://en.cppreference.com/w/cpp/algorithm/copy_backward)     
[`int g_count(T* first, T* last, T value)                                                                `](https://en.cppreference.com/w/cpp/algorithm/count)     
[`int g_count_if(T* first, T* last, Function pred)                                                       `](https://en.cppreference.com/w/cpp/algorithm/count_if)     
[`void g_fill(T* first, T* last, T value)                                                                `](https://en.cppreference.com/w/cpp/algorithm/fill)     
[`void g_fill_n(T* first, int count, T value)                                                            `](https://en.cppreference.com/w/cpp/algorithm/fill_n)     
[`T* g_find(T* first, T* last, T value)                                                                  `](https://en.cppreference.com/w/cpp/algorithm/find)     
[`T* g_find_end(T* first, T* last, T* sfirst, T* slast)                                                  `](https://en.cppreference.com/w/cpp/algorithm/find_end)     
[`T* g_find_end_f(T* first, T* last, T* sfirst, T* slast, Function pred)                                 `](https://en.cppreference.com/w/cpp/algorithm/find_end)     
[`T* g_find_first_of(T* first, T* last, T* sfirst, T* slast)                                             `](https://en.cppreference.com/w/cpp/algorithm/find_first_of)     
[`T* g_find_first_of_f(T* first, T* last, T* sfirst, Function pred)                                      `](https://en.cppreference.com/w/cpp/algorithm/find_first_of)     
[`T* g_find_if(T* first, T* last, Function pred)                                                         `](https://en.cppreference.com/w/cpp/algorithm/find_if)     
[`T* g_find_if_not(T* first, T* last, Function pred)                                                     `](https://en.cppreference.com/w/cpp/algorithm/find_if_not)     
[`void g_for_each(T* first, T* last, Function func)                                                      `](https://en.cppreference.com/w/cpp/algorithm/for_each)     
[`void g_generate(T* first, T* last, Function gen)                                                       `](https://en.cppreference.com/w/cpp/algorithm/generate)     
[`void g_generate_n(T* first, int count, Function gen)                                                   `](https://en.cppreference.com/w/cpp/algorithm/generate_n)     
[`T g_inner_product(T* first1, T* last1, T* first2, T init)                                              `](https://en.cppreference.com/w/cpp/algorithm/inner_product)     
[`T g_inner_product_f(T* first1, T* last1, T* first2, T init, Function op1, Function op2)                `](https://en.cppreference.com/w/cpp/algorithm/inner_product)     
[`void g_iota(T* first, T* last, T value)                                                                `](https://en.cppreference.com/w/cpp/algorithm/iota)     
[`bool g_lexicographical_compare(T* first1, T* last1, T* first2, T* last2)                               `](https://en.cppreference.com/w/cpp/algorithm/lexicographical_compare)     
[`T* g_lower_bound(T* first, T* last, T value)                                                           `](https://en.cppreference.com/w/cpp/algorithm/lower_bound)     
[`bool g_lexicographical_compare_f(T* first1, T* last1, T* first2, T* last2, Function comp)              `](https://en.cppreference.com/w/cpp/algorithm/lexicographical_compare)     
[`T* g_lower_bound_f(T* first, T* last, T value, Function comp)                                          `](https://en.cppreference.com/w/cpp/algorithm/lower_bound)     
[`T g_max(T a, T b)                                                                                      `](https://en.cppreference.com/w/cpp/algorithm/max)     
[`T* g_max_element(T* first, T* last)                                                                    `](https://en.cppreference.com/w/cpp/algorithm/max_element)     
[`T* g_max_element_f(T* first, T* last, Function func)                                                   `](https://en.cppreference.com/w/cpp/algorithm/max_element)     
[`T g_max_f(T a, T b, Function func)                                                                     `](https://en.cppreference.com/w/cpp/algorithm/max)     
[`T g_min(T a, T b)                                                                                      `](https://en.cppreference.com/w/cpp/algorithm/min)     
[`T* g_min_element(T* first, T* last)                                                                    `](https://en.cppreference.com/w/cpp/algorithm/min_element)     
[`T* g_min_element_f(T* first, T* last, Function func)                                                   `](https://en.cppreference.com/w/cpp/algorithm/min_element)     
[`T g_min_f(T a, T b, Function func)                                                                     `](https://en.cppreference.com/w/cpp/algorithm/min)     
[`void g_minmax(struct pair{T,T} *ret, T a, T b)                                                         `](https://en.cppreference.com/w/cpp/algorithm/minmax)     
[`void g_minmax_element(struct pair{T*,T*} *ret, T* first, T* last)                                      `](https://en.cppreference.com/w/cpp/algorithm/minmax_element)     
[`void g_minmax_element_f(struct pair{T*,T*} *ret, T* first, T* last, Function comp)                     `](https://en.cppreference.com/w/cpp/algorithm/minmax_element)     
[`void g_minmax_f(struct pair{T,T} *ret, T a, T b, Function comp)                                        `](https://en.cppreference.com/w/cpp/algorithm/minmax)     
[`void g_mismatch(struct pair{T*,T*} *ret, T* first1, T* last1, T* first2)                               `](https://en.cppreference.com/w/cpp/algorithm/mismatch)     
[`void g_mismatch_2(struct pair{T*,T*} *ret, T* first1, T* last1, T* first2, T* last2)                   `](https://en.cppreference.com/w/cpp/algorithm/mismatch)     
[`void g_mismatch_f(struct pair{T*,T*} *ret, T* first1, T* last1, T* first2, Function pred)              `](https://en.cppreference.com/w/cpp/algorithm/mismatch)     
[`void g_mismatch_f_2(struct pair{T*,T*} *ret, T* first1, T* last1, T* first2, T* last2, Function pred)  `](https://en.cppreference.com/w/cpp/algorithm/mismatch)     
[`bool g_next_permutation(T* first, T* last)                                                             `](https://en.cppreference.com/w/cpp/algorithm/next_permutation)     
[`bool g_none_of(T* first, T* last, Function pred)                                                       `](https://en.cppreference.com/w/cpp/algorithm/none_of)     
[`T* g_partition(T* first, T* last, Function pred)                                                       `](https://en.cppreference.com/w/cpp/algorithm/partition)     
[`bool g_prev_permutation(T* first, T* last)                                                             `](https://en.cppreference.com/w/cpp/algorithm/prev_permutation)     
[`void g_random_shuffle(T* first, T* last)                                                               `](https://en.cppreference.com/w/cpp/algorithm/random_shuffle)     
[`void g_random_shuffle_f(T* first, T* last, Function rgen)                                              `](https://en.cppreference.com/w/cpp/algorithm/random_shuffle)     
[`T* g_remove(T* first, T* last, T value)                                                                `](https://en.cppreference.com/w/cpp/algorithm/remove)     
[`T* g_remove_if(T* first, T* last, Function pred)                                                       `](https://en.cppreference.com/w/cpp/algorithm/remove_if)     
[`void g_replace(T* first, T* last, T value, T newvalue)                                                 `](https://en.cppreference.com/w/cpp/algorithm/replace)     
[`void g_reverse(T* first, T* last)                                                                      `](https://en.cppreference.com/w/cpp/algorithm/reverse)     
[`T* g_rotate(T* first, T* n_first, T* last)                                                             `](https://en.cppreference.com/w/cpp/algorithm/rotate)     
[`T* g_search(T* first, T* last, T* sfirst, T* slast)                                                    `](https://en.cppreference.com/w/cpp/algorithm/search)     
[`T* g_search_f(T* first, T* last, T* sfirst, T* slast, Function pred)                                   `](https://en.cppreference.com/w/cpp/algorithm/search)     
[`T* g_search_n(T* first, T* last, int count, T value)                                                   `](https://en.cppreference.com/w/cpp/algorithm/search_n)     
[`T* g_search_n_f(T* first, T* last, int count, T value, Function pred)                                  `](https://en.cppreference.com/w/cpp/algorithm/search_n)     
[`void g_sort(T* first, T* last)                                                                         `](https://en.cppreference.com/w/cpp/algorithm/sort)     
[`T* g_swap_ranges(T* first1, T* last1, T* first2)                                                       `](https://en.cppreference.com/w/cpp/algorithm/swap_ranges)     
[`T* g_transform(T* first, T* last, T* dfirst, Function func)                                            `](https://en.cppreference.com/w/cpp/algorithm/transform)     
[`T* g_transform_2(T* first, T* last, T* first2, T* dest, Function func)                                 `](https://en.cppreference.com/w/cpp/algorithm/transform)     
[`T* g_upper_bound(T* first, T* last, T value)                                                           `](https://en.cppreference.com/w/cpp/algorithm/upper_bound)     
[`T* g_upper_bound_f(T* first, T* last, T value, Function comp)                                          `](https://en.cppreference.com/w/cpp/algorithm/upper_bound)     

## Future Work

* Explain what's going on in the various header files. 
* Clean up some inconsistent naming conventions. 
* Implement more functions from `<algorithm>`. 

