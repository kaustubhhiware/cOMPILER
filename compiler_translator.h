#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <stack>
#include <stdio.h>
using namespace std;

#define MAX 100000

enum type0f{
	voidType, boolType, charType,
	intType, doubleType, pointerType,
	arrayType, functionType
};

struct node{
	
	type0f type_specifier;
	int size;
	node *next;

	node(type0f t, int s = 1, node *Next = NULL);
	int getSize();
	void print();
};

node *replicate(node *t); 	// copy node type

typedef struct typeOf
{
	string type_specifier;
	string location;
	int size,PC;// pointer count
	string ptrType,arrType;
	int numParam,idx;
	vector<int> typeList;
	struct typeOf *next;
}typeOf;
// change from enum because of erraneous conversions to .s

typedef union declExp{
	int int_val;
	double double_val;
	char char_val;
}typeUnion;


enum operatorType{
	ADD = 1,SUB,MUL,DIV,MOD,				// arithmatic
	SHIFTLEFT,SHIFTRIGHT,					// shift
	BINARYAND,BINARYXOR,BINARYOR,			// relational
	LOGICAL_AND,LOGICAL_OR,
	LT,GT,LE,GE,EQ,NEQ,
	UNARY_ADD,UNARY_SUB,BINARYNOT,NOT,CPY,	// unary operations
	IF_LT,IF_GT,IF_LE,IF_GE,IF_EQ,IF_NEQ,CONDN,NOTCONDN,
	GOTOOP,									// parameter
	RIGHTINDEX,LEFTINDEX,					// indexed copy
	CALL,PARAM,
	RETURN_VOID,RETURN,						// return
	ADDRESS,RTPTR,LTPTR,					// address and pointer eqns
	_FUNC_START,_FUNC_END,
	CHAR2INT,CHAR2DBL,INT2CHAR,DBL2CHAR,INT2DBL,DBL2INT// other necessary operations
	
};

class SymbolTable;

// singular entry in SymbolTable
typedef struct STelement
{
	string name;				// vars are self explanatory
	typeOf type;
	int numParam;
	typeUnion *initVal;
	int size,offset,PC;
	SymbolTable *nextVar;	// used only when var in globalST
}STelement;


class SymbolTable
{
public:
	STelement ST[MAX];
	int count,offset;

	SymbolTable() 
	{
		for(int i=0; i<MAX; i++)
			ST[i].nextVar = NULL;
		count = 0;offset = 0;
	}
							//functions as mentioned 
	STelement* lookup(string s, string lname = "int" , int pc = 0);	// lookup searches for var in ST and returns pointer . Creates a new one if not found
	STelement *search(string name);	// search for var "name" in ST
	void update(STelement *location, node *type, typeUnion initval, SymbolTable *next = NULL);	
									// update different fields of existing entries		
	string gentemp(typeOf type);		// generates a new var with insertion in ST, returns pointer
	void print();			// prints ST
};


class expression;
class expression
{
public:
	string location;
	int instr;
	typeOf type;
	int ifArray;								// stores a[0] in case of array	
	list<int> truelist, falselist, nextlist;	// list replaced by stl
	bool isPointer;								// whether current var is pointer
	int dim;
	string *inner;
	expression()
	{
		dim = 0;
		inner = NULL;
		nextlist = list<int>();
	}
};

struct argumentList{
	vector<expression*> *arguments;		
};

struct identtifierList{
	STelement *location;					
	string *name;					
};

typedef struct functPdef
{
	string name;
	typeOf *type;
}Fdef;


class Qelement;
class Qelement
{
public:
	operatorType op;
	string arg1, arg2, res;
	void print();
};


class Quad;
class Quad
{
	public:
	vector<Qelement> arr;
	int nextinstr;
	Quad(){ nextinstr = 0; }

	void emit(operatorType op, string res, string arg1, string arg2 = 0);
	void emit(operatorType op, string res, int num);
	void emit(operatorType op, string res, double d);
	void emit(operatorType op, string res, char c);

	void convDbl2Int(expression *e1, expression *e2);
	void convDbl2Char(expression *e1, expression *e2);
	void convInt2Dbl(expression *e1, expression *e2);
	void convInt2Char(expression *e1, expression *e2);
	void convChar2Int(expression *e1, expression *e2);
	void convChar2Dbl(expression *e1, expression *e2);
	void backpatch(list<int> p, int i);
	void conv2Bool(expression *e);
};


typedef struct functPlist
{
	list<Fdef*> func_def_list;
}FList;


class declaration
{
public:
	expression *declExp;
	string decl;
	typeOf *type;
	FList *declarationList;
	vector<int> alist;
	int PC;
};


typedef struct init_decl_list
{
	list<declaration*> declist;
}initDecList;

list<int> makelist(int nextinstr);
list<int> merge(list<int> a, list<int> b);


class Translator
{
public:
	string funcName,null,str0;
	int stackSize,flag,ebpMem,gotoCount;
	map<int, string> genGoto;
	STelement *row;
	SymbolTable *nextST;
	Qelement Qcurrent,Qnext;
	stack<vector<string> > paraStack;
	int numParam,memory,stackR,typeFunct,ptrType;
	Translator()
	{
		funcName = "";null="";str0 = ".LC";
		stackSize = 0;ebpMem = 0;gotoCount = 0;
		row = NULL;
		nextST = NULL;
		numParam = 0;memory = 16;typeFunct = 0;	ptrType = 0;

	}
	string genGOTO();
	void genFuncPrologue();
	void genFuncEpilogue();
	void getGlobal();
	void convert2Asm();
	void setStr();
	void setGoto();
	void setMem();
};

void typecheck(expression *e1, expression *e2, bool isAssign = false);	// check if E1.type = E2.type, if isAssign is true also changes it
