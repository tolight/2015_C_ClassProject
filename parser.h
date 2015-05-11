#include "scanner.h"
#include <list>
#include <set>
using namespace std;

/*
Func     ->  ID                |
			 NUM               |
			 (FuncName Params) |
			 (Params)

Params   ->  Func Params       |
			 null

*///LL(1)

/*
	E        ->  Func
	Func     ->  ID                |
			     NUM               |
			     (FuncName Params) |
			     (params)           
	
	params   ->  Func Params       |
			     null
	
	FuncName ->  ID
*///LR(1)

#define _list_     1
#define _cons_     2
#define _cdr_      3
#define _car_      4
#define _let_      5
#define _if_       6
#define _eql_      7
#define _smaller_  8
#define _greater_  9
#define _and_     10
#define _or_      11
#define _not_     12
#define _plus_    13
#define _minus_   14
#define _times_   15
#define _divide_  16
#define _defun_   17
#define _NUM_     18
#define _ID_      19
#define _lambda_  20


typedef int FuncDef;
extern int funcNum;
extern vector<string> funcNameList;
extern hash_map<string, size_t> keyWordMap;

struct SyntaxTree
{
	FuncDef funcHead;
	string funcContext;
	list<SyntaxTree*> paramsList;
	SyntaxTree()
	{
		funcHead = 0;
		paramsList.clear();
	}
};

SyntaxTree LR_parser(char* src);

SyntaxTree LL_parser(char* src);