#include "g_algorithm.h"

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>

double myhypot(double a, double b) { return a * a + b * b;}


int less(double a, double b)
{
	return a < b;
}

int more(double a, double b)
{
	return a > b;
}

int abs_less(double a, double b)
{
	return fabs(a) < fabs(b);
}

_Bool abs_more(double a, double b)
{
	return fabs(a) > fabs(b);
}

 

void print_d(double x)
{
	printf("%g ", x);
}

double d_plus(double a, double b)
{
	return a + b;
}

double d_mul(double a, double b)
{
	return a * b;
}

_Bool a_is_sqrt_of_b(int a, int b)
{
	return a * a == b;
}

double sin_a_times_cos_b_plus_1(float a, float b)
{
	return 1 + sin(a) * cos(b);
}

double a_plus_b_div_2(double a, double b)
{
	return a + b/2;
}

int same_as_upper(char a, char b)
{
	return toupper(a) == toupper(b);
}

char lame_rand(char c)
{
	static unsigned x = 0;
	return ++x % c;
}

_Bool is_eq_mod_10(int a, int b)
{	
	return a % 10 == b % 10;
}

_Bool is_lt_mod_10(int a, int b)
{
	return a % 10 < b % 10;
}

int subtract_mod_1000(int a, int b)
{
	return (a % 1000) - (b % 1000);
}

int mod_3_counter(void)
{
	static int count = 0;
	count %= 3;
	return count ++ ;
}

int is_square(int x)
{	
	int r = sqrt(x);
	return x == r * r;
}

int is_even(int x)
{
	return x % 2 == 0;
}

int main()
{	
	{
		float a[] = { 4.8, 100.97, 1.147, 91.80, 2.180 };
		G_LOCAL_PAIR(float*, float*, ret);
		g_minmax_element(&ret, a, a + G_NELEM(a));
		printf("g_minmax_element %d %d -> %g %g\n", (int)(ret.first - a), (int)(ret.second - a), *ret.first, *ret.second);
		
	}
	{
		float a[] = { 23,71,14,81,25,89,12,86,25,84 };
		G_LOCAL_PAIR(float*, float*, ret);
		g_minmax_element_f(&ret, a, a + G_NELEM(a), is_lt_mod_10);
		printf("g_minmax_element_f %d %d -> %g %g\n", (int)(ret.first - a), (int)(ret.second - a), *ret.first, *ret.second);
		
	}
	
	{
	    {
		float a[] = { 48, 97, 147, 180, 180};// Diffs = "012!"
		char b[G_NELEM(a)] = {0};
		char* ret = g_adjacent_difference(a, a + G_NELEM(a), b);
		printf("g_adjacent_difference %d [%s]\n", (int)(ret - b), b);
	    }
	    {
		float aa[] = { 48, 10097, 1147, 9180, 2180};
		char b[G_NELEM(aa)] = {0};
		char* ret = g_adjacent_difference_f(aa, aa + G_NELEM(aa), b, subtract_mod_1000);
		printf("g_adjacent_difference_f %d [%s]\n", (int)(ret - b), b);
	    }
	}
	{
		G_LOCAL_PAIR(double, double, result);
		char a = 55;
		char b = 66;
		g_minmax(&result, a, b);
		printf("g_minmax %g %g\n", result.first, result.second);
		a = 77;
		b = 70;
		g_minmax(&result, a, b);
		printf("g_minmax %g %g\n", result.first, result.second);
		
		a = 51;
		b = 42; 
		g_minmax_f(&result, a, b, is_lt_mod_10);
		printf("g_minmax_f %g %g\n", result.first, result.second);
		
		a = 53;
		b = 42; 
		g_minmax_f(&result, a, b, is_lt_mod_10);
		printf("g_minmax_f %g %g\n", result.first, result.second);
	}
	
	
	{
		int a[] = {100, 31, 41, 82, 13, 93, 73, 24, 35};
		int* ret = g_lower_bound_f(a, a + G_NELEM(a), 1003, is_lt_mod_10);
		printf("g_lower_bound_f %d [%d]\n", (int)(ret - a), *ret);	
		ret = g_upper_bound_f(a, a + G_NELEM(a), 1003, is_lt_mod_10);
		printf("g_upper_bound_f %d [%d]\n", (int)(ret - a), *ret);	
	}
	
	{
		int val = 205;
		val = g_clamp_f(val, 102, 7, is_lt_mod_10);
		printf("g_clamp_f %d\n", val);
		val = 1001;
		val = g_clamp_f(val, 102, 7, is_lt_mod_10);
		printf("g_clamp_f %d\n", val);
		val = 108;
		val = g_clamp_f(val, 102, 7, is_lt_mod_10);
		printf("g_clamp_f %d\n", val);
	}
	
	{
		int val = 100;
		val = g_clamp(val, 1, 255);
		printf("g_clamp %d\n", val);
		val = -1;
		val = g_clamp(val, 1, 255);
		printf("g_clamp %d\n", val);
		val = 300;
		val = g_clamp(val, 1, 255);
		printf("g_clamp %d\n", val);
	}
	
	{
		char a[] = "abcccddee";
		char* ret = g_lower_bound(a, a + strlen(a), 'c');
		printf("g_lower_bound %d [%c]\n", (int)(ret - a), *ret);
		ret = g_upper_bound(a, a + strlen(a), 'c');
		printf("g_upper_bound %d [%c]\n", (int)(ret - a), *ret);
	}

 	
	{
		char a[] = "abcdefghilklmnopqrstuvwxyz";
		char* ret = g_rotate(a, a + 13, a + strlen(a));
		printf("g_rotate %d [%s]\n", (int)(ret - a), a);
	}


	{
		int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
		int* ret = g_partition(a, a + G_NELEM(a), is_even);
		int ret_index = (int)(ret - a);
		printf("g_partition ");
		for(int i = 0 ; i <  (int)G_NELEM(a) ; i ++ )
		{
			if(i == ret_index)printf("/ ");
			printf("%d ", a[i]);
		}
		printf("\n");
		
	}
	{
		double a[] = { 56322.5,760.736,1.59174, 21.3941,5401.75, 1e-9, 1e9};
		g_sort(a, a + G_NELEM(a));
		printf("g_sort ");
		for(unsigned i = 0 ; i <  G_NELEM(a) ; i ++ )
		{
			printf("%g ", a[i]);
		}
		printf("\n");
		
	}
	{
		char a[] = "abc";
		printf("g_next_permutation\n");
		do
		{
			printf("%s\n", a);
		}while(g_next_permutation(a, a + strlen(a)));
		
		
	}
	{
		char a[] = "cba";
		printf("g_prev_permutation\n");
		do
		{
			printf("%s\n", a);
		}while(g_prev_permutation(a, a + strlen(a)));
	}

	{	
		float a[] = {11,22,33,44};
		g_reverse(a, a + G_NELEM(a));
		printf("g_reverse ");
		for(unsigned i = 0 ; i <  G_NELEM(a) ; i ++ )
		{
			printf("%g ", a[i]);
		}
		printf("\n");	
		
		g_reverse(a, a + G_NELEM(a) - 1);
		printf("g_reverse ");
		for(unsigned i = 0 ; i <  G_NELEM(a) ; i ++ )
		{
			printf("%g ", a[i]);
		}
		printf("\n");	
	}
	
	{
		double a[] = {1,2,1,2,3,1,2,3,4,1,2,3,4,5};
		g_replace(a,  a + G_NELEM(a), 2, 99);
		printf("g_replace -> ");
		for(unsigned i = 0 ; i <  G_NELEM(a) ; i ++ )
		{
			printf("%g ", a[i]);
		}
		printf("\n");
	}

	{
		double a[] = {1,2,3,4,5,6,7,8,9,14,16,18,25,30};
		double* end = g_remove_if(a,  a + G_NELEM(a), is_square);
		*end = -999;
		printf("g_remove_if %d -> ", (int)(end - a));
		for(unsigned i = 0 ; i <  G_NELEM(a) ; i ++ )
		{
			printf("%g ", a[i]);
		}
		printf("\n");
	}
	
	{
		double a[] = {1,2,1,2,3,1,2,3,4,1,2,3,4,5};
		double* end = g_remove(a,  a + G_NELEM(a), 2);
		*end = -999;
		printf("g_remove %d -> ", (int)(end - a));
		for(unsigned i = 0 ; i <  G_NELEM(a) ; i ++ )
		{
			printf("%g ", a[i]);
		}
		printf("\n");
	}
	
	{
		double a[10] = {99,99,99,99,99,99,99,99,99,99};
		g_generate_n(a,  5, mod_3_counter);
		printf("g_generate_n ");
		for(unsigned i = 0 ; i <  G_NELEM(a) ; i ++ )
		{
			printf("%f ", a[i]);
		}
		printf("\n");
	}
	
	{
		double a[10] = {0};
		g_generate(a, a + G_NELEM(a), mod_3_counter);
		printf("g_generate ");
		for(unsigned i = 0 ; i <  G_NELEM(a) ; i ++ )
		{
			printf("%f ", a[i]);
		}
		printf("\n");
	}
	
	{
		float a[10] = {0};
		g_fill(a, a + 5, (double)2.2);
		printf("g_fill_n ");
		for(unsigned i = 0 ; i <  G_NELEM(a) ; i ++ )
		{
			printf("%f ", a[i]);
		}
		printf("\n");
	}
	
	{
		float a[5];
		g_fill(a, a + G_NELEM(a), (double)1.1);
		printf("g_fill ");
		for(unsigned i = 0 ; i <  G_NELEM(a) ; i ++ )
		{
			printf("%f ", a[i]);
		}
		printf("\n");
	}
	{
		double a[5] = {48,49,50,51,0};
		char b[10] = {99,99,99,99,99,99,99,99,99,99};
		char* end = g_copy_backward(a, a + G_NELEM(a), b + G_NELEM(b));
		printf("g_copy_backward %d [%c]\n", (int)(end - b), *end);
		printf("g_copy_backward -> [%s]\n", end);
		
	}
	
	{
		double a[] = {48,49,50,51,52,53,54,0};
		char b[G_NELEM(a)];
		char* end = g_copy(a, a + G_NELEM(a), b);
		printf("g_copy -> [%s]\n", b);
		printf("g_copy %d [%c]\n", (int)(end - b), *end);
	}
	
	
	{
		double a[] = {11,12,32,42,21,82,92,52,12,21};
		double* found = g_search_n_f(a, a + G_NELEM(a), 4, 2, is_eq_mod_10);
		printf("g_search_n_f %d %f\n", (int)(found - a), *found);
	}
	
	{
		float a[] = {11,22,22,22,11,22,22,22,22,11};
		float* found = g_search_n(a, a + G_NELEM(a), 4, 22);
		printf("g_search_n %d %f\n", (int)(found - a), *found);
	}
 
	{
		float a[] = {11, 22, 33, 43, 54 };
		float* found = g_adjacent_find_f(a, a + G_NELEM(a), is_eq_mod_10);
		printf("g_adjacent_find_f %d %f\n", (int)(found - a), *found);
	}
	
	{
		int a[] = {11, 22, 33, 44, 55, 55, 66, 77};
		int* found = g_adjacent_find(a, a + G_NELEM(a));
		printf("g_adjacent_find %d %d\n", (int)(found - a), *found);
	}




	{
		char a[4] = {11,2,23,14};
		int b[4]  = {1,42,33,25};
		double c[4]= {91,12,23,34};
		double d[5]= {91,12,23,34,34};
		printf("a={11,2,23,14}  b={1,42,33,25}  c={91,12,23,34} d={91,12,23,34,34} f=is_lt_mod_10\n");
		printf("g_lexicographical_compare_f a b %d\n", g_lexicographical_compare_f(a, a + 4, b, b + 4, is_lt_mod_10));
		printf("g_lexicographical_compare_f b a %d\n", g_lexicographical_compare_f(b, b + 4, a, a + 4, is_lt_mod_10));
		printf("g_lexicographical_compare_f a c %d\n", g_lexicographical_compare_f(a, a + 4, c, c + 4, is_lt_mod_10));
		printf("g_lexicographical_compare_f c a %d\n", g_lexicographical_compare_f(c, c + 4, a, a + 4, is_lt_mod_10));
		printf("g_lexicographical_compare_f b c %d\n", g_lexicographical_compare_f(b, b + 4, c, c + 4, is_lt_mod_10));
		printf("g_lexicographical_compare_f c b %d\n", g_lexicographical_compare_f(c, c + 4, b, b + 4, is_lt_mod_10));
		printf("g_lexicographical_compare_f c d %d\n", g_lexicographical_compare_f(c, c + 4, d, d + 5, is_lt_mod_10));
		printf("g_lexicographical_compare_f d c %d\n", g_lexicographical_compare_f(d, d + 5, c, c + 4, is_lt_mod_10));
		
	}
	
	
	{
		char a[4] = {1,2,3,4};
		int b[4]  = {1,2,3,5};
		double c[4]= {1,2,3,4};
		printf("a={1,2,3,4}  b={1,2,3,5}  c={1,2,3,4}\n");
		printf("g_lexicographical_compare a b %d\n", g_lexicographical_compare(a, a + 4, b, b + 4));
		printf("g_lexicographical_compare b a %d\n", g_lexicographical_compare(b, b + 4, a, a + 4));
		printf("g_lexicographical_compare a c %d\n", g_lexicographical_compare(a, a + 4, c, c + 4));
		printf("g_lexicographical_compare c a %d\n", g_lexicographical_compare(c, c + 4, a, a + 4));
		printf("g_lexicographical_compare b c %d\n", g_lexicographical_compare(b, b + 4, c, c + 4));
		printf("g_lexicographical_compare c b %d\n", g_lexicographical_compare(c, c + 4, b, b + 4));
		
	}
	{
		float a[] = { 11,22,33,44,55,66, 55};
		int b[]  = {97, 86, 75};
		float* found = g_find_first_of_f(a, a + G_NELEM(a), b, b+ G_NELEM(b), is_eq_mod_10);
		printf("g_find_first_of_p %d [%f]\n", (int)(found - a), *found);
	}
	{
		float a[] = { 11,22,33,44,55,66,77, 66, 55};
		int b[]  = {99, 88, 77};
		float* found = g_find_first_of(a, a + G_NELEM(a), b, b+ G_NELEM(b));
		printf("g_find_first_of %d [%f]\n", (int)(found - a), *found);
	}
	{
		char a[] = "one two three one two one";
		char b[] = "ONE";
		char* found = g_find_end_f(a, a + strlen(a), b, b+ strlen(b), same_as_upper);
		printf("g_find_end_p %d [%c]\n", (int)(found - a), *found);
	}
	{
		double a[] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9};
		g_random_shuffle_f(a, a + G_NELEM(a), lame_rand);
		printf("g_random_shuffle_r { ");
		for(unsigned i = 0 ; i < G_NELEM(a) ; i ++ )printf("%g ", a[i]);
		printf("}\n");
	}
	{
		double a[] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9};
		g_random_shuffle(a, a + G_NELEM(a));
		printf("g_random_shuffle { ");
		for(unsigned i = 0 ; i < G_NELEM(a) ; i ++ )printf("%g ", a[i]);
		printf("}\n");
	}
	{
		char a[] = "012345";
		double b[] = {65,66,67,68,69,70};
		double * ret = g_swap_ranges(a, a + strlen(a), b);
		printf("g_swap_ranges ret %d\n", (int)(ret - b));
		printf("g_swap_ranges {%s} { ", a);
		for(unsigned i = 0 ; i < G_NELEM(b) ; i ++ )printf("%f ", b[i]);
		printf("}\n");
		
	}
	{
		char a[] = "one two three one two one";
		char b[] = "one";
		char* found = g_find_end(a, a + strlen(a), b, b+ strlen(b));
		printf("g_find_end %d [%c]\n", (int)(found - a), *found);
	}
	{
		char a[] = "this is a test.";
		char b[] = "TEST";
		char* found = g_search_f(a, a + strlen(a), b, b+ strlen(b), same_as_upper);
		printf("g_search %d [%c]\n", (int)(found - a), *found);
	}
	{
		double a[] = { 45, 46, 47, 48, 49, 50, 51};
		char b[] = "0123";
		double* found = g_search(a, a + G_NELEM(a), b, b + strlen(b));
		printf("g_search %d %f\n", (int)(found - a), *found);
	}
	{
		int a[] = {1,2,3,4,5};
		double sum = g_accumulate_f(a, a + G_NELEM(a), 1.01, d_mul);
		printf("g_accumulate_op %f\n", sum);//121.2
	}
	
	{
		int a[] = {10,20,30,40,50};
		double sum = g_accumulate(a, a + G_NELEM(a), 0.01);
		printf("g_accumulate %f\n", sum);
	}
	{
		float a[5];
		g_iota(a, a + G_NELEM(a), 1.1);
		printf("g_iota ");
		for(unsigned i = 0 ; i < G_NELEM(a) ; i ++ )
		{
			printf("%f ", a[i]);
		}
		printf("\n");
	}
	{
		char a[] = "abcDEF";
		printf("[%s]\n", a);
		printf("g_all_of isalpha %d\n",   g_all_of(a, a + strlen(a), isalpha));
		printf("g_all_of isupper %d\n",   g_all_of(a, a + strlen(a), isupper));
		printf("g_any_of ispunct %d\n",   g_any_of(a, a + strlen(a), ispunct));
		printf("g_any_of isupper %d\n",   g_any_of(a, a + strlen(a), isupper));
		printf("g_none_of ispunct %d\n",  g_none_of(a, a + strlen(a), ispunct));
		printf("g_none_of isupper %d\n",  g_none_of(a, a + strlen(a), isupper));
		
	}
	{
		char a[] = "abc123 ! 456 ";
		char* found = g_find_if_not(a, a + strlen(a), isalpha);
		printf("g_find_if_not isalpha %d [%c]\n", (int)(found - a), *found);
	}
	{
		char a[] = "abc 123 ! 456 ";
		char* found = g_find_if(a, a + strlen(a), ispunct);
		printf("g_find_if ispunct %d [%c]\n", (int)(found - a), *found);
	}
	
	{
		char a[] = "ABCDEF";
		char* found = g_find(a, a + strlen(a), (double)'C');
		printf("g_find %d [%c]\n", (int)(found - a), *found);
	}
	{
		char a[]   = { 1,    2,    3};
		double b[] = {1.1, 2.02, 3.003};
		float r = g_inner_product_f(a, a + G_NELEM(a), b, (float)3.14, a_plus_b_div_2, sin_a_times_cos_b_plus_1);
		printf("g_inner_product_op %f\n", r);//4.563530

		
	}
	{
		char a[]   = { 1,    2,    3,     4};
		double b[] = {1.1, 2.02, 3.003, 4.0004};
		float r = g_inner_product_f(a, a + G_NELEM(a), b, (float)3.14, d_plus, d_mul);
		printf("g_inner_product_op %f\n", r);//33.2906
		
	}
	
	{
		char a[]   = { 1,    2,    3,     4};
		double b[] = {1.1, 2.02, 3.003, 4.0004};
		float r = g_inner_product(a, a + G_NELEM(a), b, (float)3.14);
		printf("g_inner_product %f\n", r);//33.2906
		
	}
	{
		int a[] = {1,  2,  3,  4,  5,  6,  7};
		int b[] = {1,  4,  9};
		G_LOCAL_PAIR(int* , int*, ret); 
		g_mismatch_f_2(&ret, a, a + G_NELEM(a), b, b + G_NELEM(b), a_is_sqrt_of_b);
		printf("g_mismatch_p_2 pair %d %d\n", (int)(ret.first - a), (int)(ret.second - b));
		printf("g_mismatch_p_2 val %d\n", *ret.first);
	}

	{
		int a[] = {1,  2,  3,  4,  5,  6,  7};
		int b[] = {1,  4,  9, 16, 24, 36, 49};
		G_LOCAL_PAIR(int* , int*, ret); 
		g_mismatch_f(&ret, a, a + G_NELEM(a), b, a_is_sqrt_of_b);
		printf("g_mismatch_p pair %d %d\n", (int)(ret.first - a), (int)(ret.second - b));
		printf("g_mismatch_p vals %d %d\n", *ret.first, *ret.second);
	}
	
	{
		char a[] = "0123456";
		char b[] = "01234";
		G_LOCAL_PAIR(char* , char*, ret); 
		g_mismatch_2(&ret, a, a + strlen(a), b, b + strlen(b));
		printf("g_mismatch_2 pair %d %d\n", (int)(ret.first - a), (int)(ret.second - b));
	}
	{
		char a[] = "012345789";
		double b[] = { 48, 49, 50, 51, 52,  53, 54, 55, 56 };
		G_LOCAL_PAIR(char* , double*, ret); 
		
		g_mismatch(&ret, a, a + strlen(a), b);
		
		printf("g_mismatch pair %d %d\n", (int)(ret.first - a), (int)(ret.second - b));
		printf("g_mismatch vals '%c' %f\n", *ret.first, *ret.second);
	}
	{
		char a[]="ABC 123 .;?\r\n 456 D";
		int cnt = g_count_if(a, a + strlen(a), isdigit);
		printf("g_count isdigit %d\n", (int)cnt);
		cnt = g_count_if(a, a + strlen(a), isalpha);
		printf("g_count isalpha %d\n", (int)cnt);
	}
	{
		float a[] = {1.1, 2.2, 3, 4, 3, 3.2, 1.1, 3, 3};
		int cnt  = g_count(a, a + G_NELEM(a), (char)3);
		printf("g_count %d\n", (int)cnt);
	}
	{
		char a[8] = "ABCDEFGH";
		int  b[8] = {0,0,1,1,2,2,3,4};
		char c[8];
		
		g_transform_2(a, a + strlen(a), b, c, d_plus);
		printf("g_transform_2 d_plus ");
		for(unsigned i = 0 ; i < G_NELEM(c) ; i ++ )
		{
			printf("%c", c[i]);
		}
		printf("\n");
	}
	{
		char a[] = "ABC 123 .;?\r\n";
		
		double b[G_NELEM(a)] = {0};
		
		g_transform(a, a + strlen(a), b, isalpha);
		printf("g_tranform isalpha ");
		for(unsigned i = 0 ; i < G_NELEM(b) ; i ++ )
		{
			printf("%g ", b[i]);
		}
		printf("\n");
		g_transform(a, a + strlen(a), b, isdigit);
		printf("g_tranform isdigit ");
		for(unsigned i = 0 ; i < G_NELEM(b) ; i ++ )
		{
			printf("%g ", b[i]);
		}
		printf("\n");
		
		g_transform(a, a + strlen(a), b, isspace);
		printf("g_tranform isspace ");
		for(unsigned i = 0 ; i < G_NELEM(b) ; i ++ )
		{
			printf("%g ", b[i]);
		}
		printf("\n");
	}
	{
		double a[] = {1.1, 2.2, 3.3, 4.4};
		printf("g_for_each print_d ");
		g_for_each(a, a + G_NELEM(a), print_d);		
		printf("\n");
	}
	{
		double r = g_min((char)64, (char)3);
		printf("g_min %g\n", r);	
		
		r = g_max(64.0, 3.141);
		printf("g_max %g\n", r);	
	}
	{
		double r = g_min_f('0', '1', less);
		printf("g_min_if %g\n", r);
	}
	
	{
		float a[] = {22.2, 33.3, 11.1, 66.6, 44.4, 55.5};
		float* r = g_min_element(a, a + G_NELEM(a));
		printf("g_min_element %d %g\n", (int)(r - a), *r);
		r = g_max_element(a, a + G_NELEM(a));
		printf("g_max_element %d %g\n", (int)(r - a), *r);		
	}
	
	{
		float a[] = { 8.8, -10.1,-6.6, 4.4, -2.2, 1.1, -3.3, 5.5};
		float* r ;
		r = g_min_element_f(a, a + G_NELEM(a), abs_less);
		printf("g_min_element_f abs_less %d %g\n", (int)(r - a), *r);
		r = g_min_element_f(a, a + G_NELEM(a), abs_more);
		printf("g_min_element_f abs_more %d %g\n", (int)(r - a), *r);
		
		r = g_max_element_f(a, a + G_NELEM(a), abs_less);
		printf("g_max_element_f abs_less %d %g\n", (int)(r - a), *r);
		r = g_max_element_f(a, a + G_NELEM(a), abs_more);
		printf("g_max_element_f abs_more %d %g\n", (int)(r - a), *r);
		
	}
#if 0
#endif 

}
