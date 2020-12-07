#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <fstream>
#include <map>
#include <vector>
#include <set>
using namespace std;

bool contains(const string big, const string small)
{
	return big.find(small) != string::npos;
}

bool has(map<string, vector<string> >& m, string s)
{
	return m.find(s) != m.end();
}

void replace(char* s, char before, char after)
{
	for(unsigned i = 0 ; i < strlen(s) ; i ++ )
	{
		if(s[i] == before)s[i] = after;
	}
}

bool find_in_file(const char* filename, const string text)
{
	static map<string, vector<string>> cache;
	if(!has(cache, filename))
	{
		ifstream is(filename);
		string line;
		while(getline(is, line))
		{
			cache[filename].push_back(line);
		}
	}

	for(auto & l : cache[filename])
	{
		if(contains(l, text))
		{
			return true;
		}
	}
	return false;

}

struct op_t
{
	const char* n;
	const char* o;
	
};

op_t cmp_op[] ={
 { "is_eq", "==" },
 { "is_ne", "!=" },
 { "is_gt", ">" },
 { "is_lt", "<" },
 { "is_ge", ">=" },
 { "is_le", "<=" },
 //{ "and",  "&&" },
 //{ "or" , "||" },
};
/* 
a + b
a - b
a * b
a / b
a % b 
a & b
a | b
a ^ b
a << b
a >> b*/

op_t arith_op[] ={
 { "add"   , "+" },
 { "sub"   , "-" },
 { "mul"   , "*" },
 //{ "div"   , "/" },
 //{ "mod"   , "%" },
 //{ "bitand", "&" },
 //{ "bitor" , "|" },
 //{ "bitxor", "^" },
 //{ "shl"   , "<<" },
 //{ "shr"   , ">>" },
};

op_t unary_op[]={
 //{ "neg"   , "-"},
 //{ "bitnot", "~"},
 { "not"   , "!"},
};

/*
a =   b
a +=  b
a -=  b
a *=  b
a /=  b
a %=  b
a &=  b
a |=  b
a ^=  b
a <<= b
a >>= b 
a = - b
a = ~ b
a = ! b */
op_t assign_op[]={
   { "assign"    , "="   },
   { "add_eq"    , "+="  },
   { "sub_eq"    , "-="  },
   { "mul_eq"    , "*="  },
   //{ "div_eq"    , "/="  },
   //{ "mod_eq"    , "%="  },
   //{ "and_eq"    , "&="  },
   //{ "or_eq"     , "|="  },
   //{ "xor_eq"    , "^="  },
   //{ "shl_eq"    , "<<=" },
   //{ "shr_eq"    , ">>=" },
   //{ "eq_neg"    , "= -" },
   //{ "eq_bitnot" , "= ~" },
   //{ "eq_not"    , "= !" }, 
};

struct type_nick_t
{
	const char* t;
	const char* n;
};

#ifdef ABBREV
type_nick_t type_nick[] = {
 {"bool" , "b"                   },
 {"char" , "c"                    }, 
 {"short" , "ss"           },
 {"int" , "si"             }, 
 {"long" , "sl"            }, 
 {"unsigned long" , "ul"          },
 //{"long long" , "sll"      },
 //{"unsigned long long" , "ull"    },
 {"float" , "f"                   },
 {"double" , "d"                  }, 
 //{"long double" , "ld"            },
};
#else
type_nick_t type_nick[] = {
 {"bool" , "b"                   },
 {"char" , "c"                    },
 {"signed char" , "sc"            },
 {"unsigned char" , "uc"          },
 {"signed short" , "ss"           },
 {"unsigned short" , "us"         },
 {"signed int" , "si"             },
 {"unsigned int" , "ui"           },
 {"signed long" , "sl"            },
 {"unsigned long" , "ul"          },
 {"signed long long" , "sll"      },
 {"unsigned long long" , "ull"    },
 {"float" , "f"                   },
 {"double" , "d"                  },
 {"long double" , "ld"            },
 {"float complex" , "fc"         },
 {"double complex" , "dc"        },
 {"long double complex" , "ldc"  },
};
#endif

struct type_format_t
{
	const char* t;
	const char* f;
};

type_format_t type_format[] = {
 {"bool" ,               "%d"   },
 {"char" ,                "%c"   },
 {"signed char" ,         "%c"   },
 {"unsigned char" ,       "%c"   },
 {"signed short" ,        "%hd"  },
 {"unsigned short" ,      "%hu"  },
 {"signed int" ,          "%d"   },
 {"unsigned int" ,        "%u"   },
 {"signed long" ,         "%ld"  },
 {"unsigned long" ,       "%lu"  },
 {"signed long long" ,    "%lld" },
 {"unsigned long long" ,  "%llu" },
 {"float" ,               "%g"   },
 {"double" ,              "%g"   },
 {"long double" ,         "%Lg"  },
 {"float complex" ,      "?"    },
 {"double complex"    ,  "??"   },
 {"long double complex" ,"???"  },
};

#define NELEM(a) (sizeof(a)/sizeof(*a))

int main()
{	
#ifdef ABBREV
	const char* outfile = "g_basic_abbrev.h";
#else
	const char* outfile = "g_basic.h";
#endif
	map<string, string> t2n;
	for(unsigned i = 0 ; i < NELEM(type_nick) ; i ++)
	{
		const char* t1 = type_nick[i].t;		
		const char* n1 = type_nick[i].n;
		t2n[t1] = n1;
	}	
	
	map<string, map<string, set<string> > >  boolcmps;
	map<string, map<string, set<string> > >  arithops;
	map<string, map<string, set<string> > >  assignops;
	map<string, map<string, set<string> > >  cmpcmps;
	
	FILE* f = fopen(outfile, "w");
	fprintf(f, "#ifndef G_BASIC_H__________\n");
	fprintf(f, "#define G_BASIC_H__________\n");
	fprintf(f, "#ifndef GC_MALLOC\n");
	fprintf(f, "#define GC_MALLOC malloc\n");
	fprintf(f, "#endif\n");
	fprintf(f, "#ifndef GC_FREE\n");
	fprintf(f, "#define GC_FREE free\n");
	fprintf(f, "#endif\n");

	fprintf(f,   "#pragma GCC diagnostic push                              \n"  );
	fprintf(f,   "#pragma GCC diagnostic ignored \"-Wbool-operation\"      \n"  );
	fprintf(f,   "#pragma GCC diagnostic ignored \"-Wint-in-bool-context\" \n"  );
	//fprintf(f,   "#pragma GCC diagnostic ignored \"-Wpedantic\"            \n"  );
 	fprintf(f,   "#pragma GCC diagnostic ignored \"-Wsign-compare\"        \n"  );
	//fprintf(f,   "#pragma GCC diagnostic ignored \"-Wunused-value\"        \n"  );
	//fprintf(f,   "#pragma GCC diagnostic ignored \"-Wuninitialized\"       \n"  );
	
	fprintf(f, "#include <stdlib.h>\n");
	fprintf(f, "#include <stdio.h>\n");
	fprintf(f, "#include <string.h>\n");
	fprintf(f, "#include <stdbool.h>\n");
	fprintf(f, "#include <complex.h>\n");
	
	// EXAMPLE VALUES
	for(unsigned i = 0 ; i < NELEM(type_nick) ; i ++)
	{
		const char* t1 = type_nick[i].t;		
		const char* n1 = type_nick[i].n;
		fprintf(f, "static __attribute__((unused)) %s g_example_%s;\n", t1, n1);
	}	
	fprintf(f, "\n#define g_example(x) _Generic((x) \\\n");
	for(unsigned i = 0 ; i < NELEM(type_nick) ; i ++)
	{
		const char* t1 = type_nick[i].t;		
		const char* n1 = type_nick[i].n;
		fprintf(f, "\t, %s : g_example_%s \\\n", t1, n1);
	}
	fprintf(f, ")\n");
	
	// PRINTF FORMATS	
	fprintf(f, "\n#define g_format_str(x) _Generic((x) \\\n");
	for(unsigned i = 0 ; i < NELEM(type_format) ; i ++)
	{
		const char* t = type_format[i].t;		
		const char* fmt = type_format[i].f;
		fprintf(f, "\t, %s : \"%s\" \\\n", t, fmt);
	}
	fprintf(f, "\t, char * : \"%%s\" \\\n");
	fprintf(f, ")\n");
	
	// POINTER FROM VOID
	for(unsigned i = 0 ; i < NELEM(type_nick) ; i ++)
	{
		const char* t1 = type_nick[i].t;		
		const char* n1 = type_nick[i].n;
		fprintf(f, "static __attribute__((unused)) %s * g_ptr_from_void_%s(void* p){return (%s *)p;}\n", t1, n1, t1);
	}	
	fprintf(f, "\n#define g_ptr_from_void(x) _Generic((x) \\\n");
	for(unsigned i = 0 ; i < NELEM(type_nick) ; i ++)
	{
		const char* t1 = type_nick[i].t;		
		const char* n1 = type_nick[i].n;
		fprintf(f, "\t, %s : g_ptr_from_void_%s \\\n", t1, n1);
	}
	fprintf(f, ")\n");
	
	// CONST POINTER FROM VOID
	for(unsigned i = 0 ; i < NELEM(type_nick) ; i ++)
	{
		const char* t1 = type_nick[i].t;		
		const char* n1 = type_nick[i].n;
		fprintf(f, "static __attribute__((unused)) const %s * g_cptr_from_void_%s(const void* p){return (const %s *)p;}\n", t1, n1, t1);
	}	
	fprintf(f, "\n#define g_cptr_from_void(x) _Generic((x) \\\n");
	for(unsigned i = 0 ; i < NELEM(type_nick) ; i ++)
	{
		const char* t1 = type_nick[i].t;		
		const char* n1 = type_nick[i].n;
		fprintf(f, "\t, %s : g_cptr_from_void_%s \\\n", t1, n1);
	}
	fprintf(f, ")\n");
	
	// VALUE FROM VOID
	for(unsigned i = 0 ; i < NELEM(type_nick) ; i ++)
	{
		const char* t1 = type_nick[i].t;		
		const char* n1 = type_nick[i].n;
		//fprintf(f, "static __attribute__((unused)) %s g_value_from_void_%s(void* p){return *((%s *)p);}\n", t1, n1, t1);
		fprintf(f, "static __attribute__((unused)) %s g_value_from_void_%s(void* p){return *((%s *)p);}\n", t1, n1, t1);
	}	
	fprintf(f, "\n#define g_value_from_void(x) _Generic((x) \\\n");
	for(unsigned i = 0 ; i < NELEM(type_nick) ; i ++)
	{
		const char* t1 = type_nick[i].t;		
		const char* n1 = type_nick[i].n;
		fprintf(f, "\t, %s : g_value_from_void_%s \\\n", t1, n1);
	}
	fprintf(f, ")\n");
	
	// VALUE FROM VOID FREE
	for(unsigned i = 0 ; i < NELEM(type_nick) ; i ++)
	{
		const char* t1 = type_nick[i].t;		
		const char* n1 = type_nick[i].n;
		//fprintf(f, "static __attribute__((unused)) %s g_value_from_void_free_%s(void* p){printf(\"%%s %%p\\n\", __func__, p);%s ret = *((%s *)p);GC_FREE(p);return ret;}\n", 
		fprintf(f, "static __attribute__((unused)) %s g_value_from_void_free_%s(void* p){%s ret = *((%s *)p);GC_FREE(p);return ret;}\n", 
		                                           t1,                       n1,         t1,         t1);
	}	
	fprintf(f, "\n#define g_value_from_void_free(x) _Generic((x) \\\n");
	for(unsigned i = 0 ; i < NELEM(type_nick) ; i ++)
	{
		const char* t1 = type_nick[i].t;		
		const char* n1 = type_nick[i].n;
		fprintf(f, "\t, %s : g_value_from_void_free_%s \\\n", t1, n1);
	}
	fprintf(f, ")\n");
	
	
	// MALLOC VALUE
	for(unsigned i = 0 ; i < NELEM(type_nick) ; i ++)
	{
		const char* t1 = type_nick[i].t;		
		const char* n1 = type_nick[i].n;
		//fprintf(f, "static __attribute__((unused)) void* g_malloc_value_%s(%s x){void* p=GC_MALLOC(sizeof(x));printf(\"%%s malloc(%%u) -> %%p\\n\", __func__, sizeof(x), p);memcpy(p, &x, sizeof(x));return p;}\n", 
		fprintf(f, "static __attribute__((unused)) void* g_malloc_value_%s(%s x){void* p=GC_MALLOC(sizeof(x));memcpy(p, &x, sizeof(x));return p;}\n", 
		                                                                n1, t1);
	}	
	
	fprintf(f, "\n#define g_malloc_value(x) _Generic((x) \\\n");
	for(unsigned i = 0 ; i < NELEM(type_nick) ; i ++)
	{
		const char* t1 = type_nick[i].t;		
		const char* n1 = type_nick[i].n;
		fprintf(f, "\t, %s : g_malloc_value_%s \\\n", t1, n1);
	}
	fprintf(f, ")\n");
	
	// TYPE ID
	fprintf(f, "\n#define g_type_id(x) _Generic((x) \\\n");
	for(unsigned i = 0 ; i < NELEM(type_nick) ; i ++)
	{
		const char* t1 = type_nick[i].t;		
		//const char* n1 = type_nick[i].n;
		fprintf(f, "\t, %s   : %d \\\n", t1, 3*i + 1);
		fprintf(f, "\t, %s * : %d \\\n", t1, 3*i + 2);
		fprintf(f, "\t, %s **: %d \\\n", t1, 3*i + 3);
	}
	fprintf(f, ")\n");
	
	fprintf(f, "\n#define g_type_str(x) _Generic((x) \\\n");
	for(unsigned i = 0 ; i < NELEM(type_nick) ; i ++)
	{
		const char* t1 = type_nick[i].t;		
		//const char* n1 = type_nick[i].n;
		fprintf(f, "\t, %s   : \"%s\" \\\n", t1, t1);
		fprintf(f, "\t, %s * : \"%s *\" \\\n", t1, t1);
	}
	fprintf(f, ")\n");

	// PAIR TYPES
	/*for(unsigned i = 0 ; i < NELEM(type_nick) ; i ++)
	{
		const char* t = type_nick[i].t;
		char tnos[80];
		strcpy(tnos, t);
		replace(tnos, ' ', '_');
		
		fprintf(f, "typedef struct pair_%s_t { %s first ; %s second ; } pair_%s_t; \n",
				                tnos,  t,         t,                 tnos);
	}*/

	// BOOL COMPARISONS
	//map<string, map<string, set<string> > >  boolcmps;
	for(unsigned i = 0 ; i < NELEM(cmp_op) ; i ++)
	for(unsigned j = 0 ; j < NELEM(type_nick) ; j ++)
	for(unsigned k = 0 ; k < NELEM(type_nick) ; k ++)
	{
		const char* n = cmp_op[i].n;
		const char* o = cmp_op[i].o;
		const char* t1 = type_nick[j].t;
		const char* t2 = type_nick[k].t;		
		const char* n1 = type_nick[j].n;
		const char* n2 = type_nick[k].n;
		char line[1000];
		sprintf(line, "static __attribute__((unused)) bool g_%s_%s_%s(const void* a, const void* b){return *((%s*)a) %s *((%s*)b);}",
		                                                      n, n1, n2,                                       t1,    o,    t2);
		
		if(!find_in_file("errors.txt", line))
		{
			boolcmps[n][t1].insert(t2);
			fprintf(f, "%s\n", line);		
		}
	}
	
	// CMP (spaceship) COMPARISONS
	//map<string, map<string, set<string> > >  boolcmps;
	
	for(unsigned j = 0 ; j < NELEM(type_nick) ; j ++)
	for(unsigned k = 0 ; k < NELEM(type_nick) ; k ++)
	{		
		const char* t1 = type_nick[j].t;
		const char* t2 = type_nick[k].t;		
		const char* n1 = type_nick[j].n;
		const char* n2 = type_nick[k].n;
		char line[1000];
		sprintf(line, "static __attribute__((unused)) int g_cmp_%s_%s(const void* a, const void* b){if(*((%s*)a) < *((%s*)b))return -1; if(*((%s*)a) > *((%s*)b))return 1; return 0;}",
		                                                         n1, n2,                                  t1,        t2,                      t1,         t2);
		
		if(!find_in_file("errors.txt", line))
		{
			cmpcmps["cmp"][t1].insert(t2);
			fprintf(f, "%s\n", line);		
		}
	}
	
	
	// ARITH OPS
	for(unsigned i = 0 ; i < NELEM(arith_op) ; i ++)
	for(unsigned j = 0 ; j < NELEM(type_nick) ; j ++)
	for(unsigned k = 0 ; k < NELEM(type_nick) ; k ++)
	{
		const char* n = arith_op[i].n;
		const char* o = arith_op[i].o;
		const char* t1 = type_nick[j].t;
		const char* t2 = type_nick[k].t;		
		const char* n1 = type_nick[j].n;
		const char* n2 = type_nick[k].n;
		char line[1000];
sprintf(line, "static __attribute__((unused)) \
void g_%s_%s_%s(void* r, const void* a, const void* b){*(g_ptr_from_void((%s){0} %s (%s){0})(r)) = *((%s*)a) %s *((%s*)b);}",
	n, n1, n2,                                                        t1,     o, t2,              t1,    o,   t2);
		
		if(!find_in_file("errors.txt", line))
		{
			arithops[n][t1].insert(t2);
			fprintf(f, "%s\n", line);		
		}
	}
	
	// ASSIGN OPS
	for(unsigned i = 0 ; i < NELEM(assign_op) ; i ++)
	for(unsigned j = 0 ; j < NELEM(type_nick) ; j ++)
	for(unsigned k = 0 ; k < NELEM(type_nick) ; k ++)
	{
		const char* n = assign_op[i].n;
		const char* o = assign_op[i].o;
		const char* t1 = type_nick[j].t;
		const char* n1 = type_nick[j].n;
		const char* t2 = type_nick[k].t;	
		const char* n2 = type_nick[k].n;
		char line[1000];
		
sprintf(line, "static __attribute__((unused)) \
void g_%s_%s_%s(void* r, const void* a){*((%s*)r) %s (*((%s*)a));}",
       n, n1, n2 ,                         t1,     o,   t2);
		
		if(!find_in_file("errors.txt", line))
		{
			assignops[n][t1].insert(t2);
			fprintf(f, "%s\n", line);		
		}
	}
	set<string> all_func_typedefs;
	// FUNCTION(0) TYPEDEFS
	for(unsigned i = 0 ; i < NELEM(type_nick) ; i ++)	
	{
		const char* t1 = type_nick[i].t;			
		const char* n1 = type_nick[i].n;		
				
		fprintf(f, "typedef %s (*g_%s_function_t)(void);\n",	t1, n1);
		
		all_func_typedefs.insert(string("g_") + n1 +  "_function_t");
		
	}	
	// FORWARDING (0)
	for(unsigned i = 0 ; i < NELEM(type_nick) ; i ++)	
	{
		const char* t1 = type_nick[i].t;			
		const char* n1 = type_nick[i].n;						
		fprintf(f, "static __attribute__((unused)) void g_%s_forward(g_%s_function_t f, void* r){*((%s*)r) = f();}\n",	
		                                                  n1,          n1,                          t1);		
	}	
	fprintf(f, "\n#define g_forward_0(x) _Generic((x) \\\n");
	for(unsigned i = 0 ; i < NELEM(type_nick) ; i ++)	
	{
		//const char* t1 = type_nick[i].t;			
		const char* n1 = type_nick[i].n;						
		fprintf(f, "\t, g_%s_function_t : g_%s_forward \\\n",
		               n1,               n1 );
		//fprintf(f, "static __attribute__((unused)) void g_%s_forward(g_%s_function_t f, void* r){*((%s*)r) = f();}\n",	
		//                                                  n1,          n1,                          t1);		
	}
	fprintf(f, ")\n");
	
	
	
	// FUNCTION(0_1) TYPEDEFS no return, one arg
	for(unsigned i = 0 ; i < NELEM(type_nick) ; i ++)	
	{
		const char* t1 = type_nick[i].t;			
		const char* n1 = type_nick[i].n;		
				
		fprintf(f, "typedef void (*g_function_%s_t)(%s);\n",	n1, t1);
		
		//all_func_typedefs.insert(string("g_") + n1 +  "_function_t");
		
	}	
	
	// FUNCTION(x) TYPEDEFS
	for(unsigned i = 0 ; i < NELEM(type_nick) ; i ++)
	for(unsigned j = 0 ; j < NELEM(type_nick) ; j ++)	
	{
		const char* t1 = type_nick[i].t;
		const char* t2 = type_nick[j].t;		
		const char* n1 = type_nick[i].n;
		const char* n2 = type_nick[j].n;
				
		fprintf(f, "typedef %s (*g_%s_function_%s_t)(%s);\n",
				t1, n1, n2, t2);
		all_func_typedefs.insert(string("g_") + n1 +  "_function_"+ n2 +"_t");
		
	}	
	
	// FUNCTION(2) TYPEDEFS
	for(unsigned i = 0 ; i < NELEM(type_nick) ; i ++)
	for(unsigned j = 0 ; j < NELEM(type_nick) ; j ++)
	for(unsigned k = 0 ; k < NELEM(type_nick) ; k ++)
	{
		const char* t1 = type_nick[i].t;
		const char* t2 = type_nick[j].t;
		const char* t3 = type_nick[k].t;
		const char* n1 = type_nick[i].n;
		const char* n2 = type_nick[j].n;
		const char* n3 = type_nick[k].n;
		
		fprintf(f, "typedef %s (*g_%s_function_%s_%s_t)(%s, %s);\n",
				t1, n1, n2, n3, t2, t3);
		all_func_typedefs.insert(string("g_") + n1 +  "_function_"+ n2 +"_" +n3+ "_t");
		
	}	
	
	// FORWARDING (0_1 ) no return, one arg
	for(unsigned i = 0 ; i < NELEM(type_nick) ; i ++)	
	{
		const char* t1 = type_nick[i].t;			
		const char* n1 = type_nick[i].n;						
		fprintf(f, "static __attribute__((unused)) void g_forward_%s(g_function_%s_t f, const void* a){f(*((%s*)a));}\n",	
		                                                         n1,            n1,                         t1);		
	}	
	
	// FORWARDING (1_1) via (0_1) no return, one arg (return ignored)
	for(unsigned i = 0 ; i < NELEM(type_nick) ; i ++)	
	for(unsigned j = 0 ; j < NELEM(type_nick) ; j ++)	
	{
				
		const char* n1 = type_nick[i].n;	
		const char* t2 = type_nick[j].t;			
		const char* n2 = type_nick[j].n;	
		fprintf(f, "static __attribute__((unused)) void g_0%s_forward_%s(g_%s_function_%s_t f, const void* a){f(*((%s*)a));}\n",	
		                                                   n1,        n2,  n1,         n2,                         t2);		
	}	
	// FORWARDING (1_1) via (0_1) generic
	fprintf(f, "\n#define g_forward_0_1(x) _Generic((x) \\\n");
	for(unsigned i = 0 ; i < NELEM(type_nick) ; i ++)	
	{
		//const char* t1 = type_nick[i].t;			
		const char* n1 = type_nick[i].n;						
		fprintf(f, "\t, g_function_%s_t : g_forward_%s \\\n",
		               n1,                         n1 );
	}
	for(unsigned i = 0 ; i < NELEM(type_nick) ; i ++)	
	for(unsigned j = 0 ; j < NELEM(type_nick) ; j ++)	
	{			
		const char* n1 = type_nick[i].n;				
		const char* n2 = type_nick[j].n;
		fprintf(f, "\t, g_%s_function_%s_t : g_0%s_forward_%s \\\n",
		                  n1,         n2,       n1,         n2 );
	}
	fprintf(f, ")\n");
	
	
	
	
	
	
	// FORWARDING (1 arg)
	for(unsigned i = 0 ; i < NELEM(type_nick) ; i ++)
	for(unsigned j = 0 ; j < NELEM(type_nick) ; j ++)	
	{
		const char* t1 = type_nick[i].t;
		const char* t2 = type_nick[j].t;		
		const char* n1 = type_nick[i].n;
		const char* n2 = type_nick[j].n;				
		fprintf(f, "static __attribute__((unused)) void g_%s_forward_%s(g_%s_function_%s_t f, void* r, const void* a){*((%s*)r) = f(*((%s*)a));}\n",	
		                                                  n1,        n2,  n1,         n2,                                t1,           t2);		
	}	
	// FORWARDING (1 arg) generic
	fprintf(f, "\n#define g_forward_1(x) _Generic((x) \\\n");
	for(unsigned i = 0 ; i < NELEM(type_nick) ; i ++)
	for(unsigned j = 0 ; j < NELEM(type_nick) ; j ++)	
	{		
		const char* n1 = type_nick[i].n;	
		const char* n2 = type_nick[j].n;	
		fprintf(f, "\t, g_%s_function_%s_t : g_%s_forward_%s \\\n",
		                 n1,           n2,     n1,         n2);  
	}
	fprintf(f, ")\n");
	
	/*for(unsigned i = 0 ; i < NELEM(type_nick) ; i ++)
	for(unsigned j = 0 ; j < NELEM(type_nick) ; j ++)	
	{
		const char* t1 = type_nick[i].t;
		const char* t2 = type_nick[j].t;		
		const char* n1 = type_nick[i].n;
		const char* n2 = type_nick[j].n;
				
		fprintf(f, "typedef %s (*g_%s_function_%s_t)(%s);\n",
				t1, n1, n2, t2);
		
	}	*/
	
		
	// FORWARDING(2)
	for(unsigned i = 0 ; i < NELEM(type_nick) ; i ++)
	for(unsigned j = 0 ; j < NELEM(type_nick) ; j ++)
	for(unsigned k = 0 ; k < NELEM(type_nick) ; k ++)
	{
		const char* t1 = type_nick[i].t;
		const char* t2 = type_nick[j].t;
		const char* t3 = type_nick[k].t;
		const char* n1 = type_nick[i].n;
		const char* n2 = type_nick[j].n;
		const char* n3 = type_nick[k].n;
		
		fprintf(f, "static __attribute__((unused)) void g_%s_forward_%s_%s(g_%s_function_%s_%s_t f, void* r, const void* a, const void* b){*((%s*)r) = f(*((%s*)a),*((%s*)b));}\n",	
		                                                  n1,        n2, n3, n1,         n2, n3,                                              t1,           t2,       t3);
		
	}	
	// FORWARDING (2 args)
	fprintf(f, "\n#define g_forward_2(x) _Generic((x) \\\n");
	for(unsigned i = 0 ; i < NELEM(type_nick) ; i ++)
	for(unsigned j = 0 ; j < NELEM(type_nick) ; j ++)	
	for(unsigned k = 0 ; k < NELEM(type_nick) ; k ++)
	{		
		const char* n1 = type_nick[i].n;	
		const char* n2 = type_nick[j].n;
		const char* n3 = type_nick[k].n;
		fprintf(f, "\t, g_%s_function_%s_%s_t : g_%s_forward_%s_%s \\\n",
		                 n1,          n2,n3,      n1,        n2,n3);  
	}
	fprintf(f, ")\n");
	
	// FUNCTION RETURN TYPES
	fprintf(f, "\n#define g_function_rettype(x) _Generic((x) \\\n");
	for(unsigned i = 0 ; i < NELEM(type_nick) ; i ++)	
	{
		//const char* t1 = type_nick[i].t;		
		const char* n1 = type_nick[i].n;		
				
		fprintf(f, "\t, g_%s_function_t : g_example_%s \\\n",	n1, n1);		
	}	
	for(unsigned i = 0 ; i < NELEM(type_nick) ; i ++)
	for(unsigned j = 0 ; j < NELEM(type_nick) ; j ++)	
	{
		//const char* t1 = type_nick[i].t;
		//const char* t2 = type_nick[j].t;		
		const char* n1 = type_nick[i].n;
		const char* n2 = type_nick[j].n;
				
		fprintf(f, "\t, g_%s_function_%s_t : g_example_%s \\\n",	n1, n2, n1);		
	}	
	for(unsigned i = 0 ; i < NELEM(type_nick) ; i ++)
	for(unsigned j = 0 ; j < NELEM(type_nick) ; j ++)	
	for(unsigned k = 0 ; k < NELEM(type_nick) ; k ++)
	{
		//const char* t1 = type_nick[i].t;
		//const char* t2 = type_nick[j].t;
		//const char* t3 = type_nick[k].t;
		const char* n1 = type_nick[i].n;
		const char* n2 = type_nick[j].n;
		const char* n3 = type_nick[k].n;
				
		fprintf(f, "\t, g_%s_function_%s_%s_t : g_example_%s \\\n",	n1, n2, n3, n1);		
	}	
	fprintf(f, ")\n");
	
	fprintf(f, "\n#define g_function_arg1type(x) _Generic((x) \\\n");
	for(unsigned i = 0 ; i < NELEM(type_nick) ; i ++)	
	{		
		const char* n1 = type_nick[i].n;			
		fprintf(f, "\t, g_function_%s_t : g_example_%s \\\n",	n1, n1);		
	}	
	
	for(unsigned i = 0 ; i < NELEM(type_nick) ; i ++)
	for(unsigned j = 0 ; j < NELEM(type_nick) ; j ++)	
	{
		//const char* t1 = type_nick[i].t;
		//const char* t2 = type_nick[j].t;		
		const char* n1 = type_nick[i].n;
		const char* n2 = type_nick[j].n;
				
		fprintf(f, "\t, g_%s_function_%s_t : g_example_%s \\\n",	n1, n2, n2);		
	}	
	for(unsigned i = 0 ; i < NELEM(type_nick) ; i ++)
	for(unsigned j = 0 ; j < NELEM(type_nick) ; j ++)	
	for(unsigned k = 0 ; k < NELEM(type_nick) ; k ++)
	{
		//const char* t1 = type_nick[i].t;
		//const char* t2 = type_nick[j].t;
		//const char* t3 = type_nick[k].t;
		const char* n1 = type_nick[i].n;
		const char* n2 = type_nick[j].n;
		const char* n3 = type_nick[k].n;
				
		fprintf(f, "\t, g_%s_function_%s_%s_t : g_example_%s \\\n",	n1, n2, n3, n2);		
	}	
	fprintf(f, ")\n");
	
	fprintf(f, "\n#define g_function_arg2type(x) _Generic((x) \\\n");
		
	for(unsigned i = 0 ; i < NELEM(type_nick) ; i ++)
	for(unsigned j = 0 ; j < NELEM(type_nick) ; j ++)	
	for(unsigned k = 0 ; k < NELEM(type_nick) ; k ++)
	{
		//const char* t1 = type_nick[i].t;
		//const char* t2 = type_nick[j].t;
		//const char* t3 = type_nick[k].t;
		const char* n1 = type_nick[i].n;
		const char* n2 = type_nick[j].n;
		const char* n3 = type_nick[k].n;
				
		fprintf(f, "\t, g_%s_function_%s_%s_t : g_example_%s \\\n",	n1, n2, n3, n3);		
	}	
	fprintf(f, ")\n");
	
	fflush(f);
	fclose(f);

	// GENERATE _Generics for CMP FUNCS
	//map<string, map<string, set<string> > >  boolcmps;
	ofstream good_h(outfile, ios_base::app);
	for(auto f : boolcmps)
	{
		
		good_h << "#define g_" << f.first << "(x,y) _Generic((x) \\\n";
		for(auto a : f.second)
		{
			string na = t2n[a.first];
			if(a.second.size() > 1)
			{
				good_h << "\t, " << a.first << " : _Generic((y) \\\n" ;
				for(auto b : a.second)
				{
					
					string nb = t2n[b];
					good_h << "\t\t, " << b << " : g_" << f.first << "_" << na << "_" << nb << " \\\n";
				}
				good_h << "\t) \\\n";
			}
			else
			{
				good_h << "\t, " << a.first << " : g_"<<f.first<<"_"<<na<<" \\\n" ;
				
			}
		}
		good_h << ")\n\n";
	}
	
	for(auto f : arithops)
	{
		
		good_h << "#define g_" << f.first << "(x,y) _Generic((x) \\\n";
		for(auto a : f.second)
		{
			string na = t2n[a.first];
			if(a.second.size() > 1)
			{
				good_h << "\t, " << a.first << " : _Generic((y) \\\n" ;
				for(auto b : a.second)
				{
					
					string nb = t2n[b];
					good_h << "\t\t, " << b << " : g_" << f.first << "_" << na << "_" << nb << " \\\n";
				}
				good_h << "\t) \\\n";
			}
			else
			{
				good_h << "\t, " << a.first << " : g_"<<f.first<<"_"<<na<<" \\\n" ;
				
			}
		}
		good_h << ")\n\n";
	}
	
	for(auto f : assignops)
	{
		
		good_h << "#define g_" << f.first << "(x,y) _Generic((x) \\\n";
		for(auto a : f.second)
		{
			string na = t2n[a.first];
			if(a.second.size() > 1)
			{
				good_h << "\t, " << a.first << " : _Generic((y) \\\n" ;
				for(auto b : a.second)
				{
					
					string nb = t2n[b];
					good_h << "\t\t, " << b << " : g_" << f.first << "_" << na << "_" << nb << " \\\n";
				}
				good_h << "\t) \\\n";
			}
			else
			{
				good_h << "\t, " << a.first << " : g_"<<f.first<<"_"<<na<<" \\\n" ;
				
			}
		}
		good_h << ")\n\n";
	}
		
	for(auto f : cmpcmps)
	{
		
		good_h << "#define g_" << f.first << "(x,y) _Generic((x) \\\n";
		for(auto a : f.second)
		{
			string na = t2n[a.first];
			if(a.second.size() > 1)
			{
				good_h << "\t, " << a.first << " : _Generic((y) \\\n" ;
				for(auto b : a.second)
				{
					
					string nb = t2n[b];
					good_h << "\t\t, " << b << " : g_" << f.first << "_" << na << "_" << nb << " \\\n";
				}
				good_h << "\t) \\\n";
			}
			else
			{
				good_h << "\t, " << a.first << " : g_"<<f.first<<"_"<<na<<" \\\n" ;
				
			}
		}
		good_h << ")\n\n";
	}
	
	good_h << "#pragma GCC diagnostic pop                              \n" ;
	good_h << "#endif\n";
}


