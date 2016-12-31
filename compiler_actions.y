%{ /* C Declarations and Definitions */
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
extern int yylex();
void yyerror(string s);
//extern int yydebug;
extern int yyparse();


#include "compiler_translator.h"

Quad quadlist;
SymbolTable globalST;
SymbolTable *St = &globalST;
SymbolTable *currST = &globalST;
typeOf *g;
int w;
vector<string> literals;
int literal_count = 0;
%}


%union {
  int intval;
  float floatval;
  char charval;
  string *str;
  expression *expressionList;
  declaration *decList;
  initDecList *initDeclist;
  typeOf *type_;
  Fdef *fDef;
  FList *fList;
}


%token RESTRICT_KEYWORD;
%token UNSIGNED_KEYWORD;
%token AUTO_KEYWORD;
%token ENUM_KEYWORD;
%token BREAK_KEYWORD;
%token EXTERN_KEYWORD;
%token RETURN_KEYWORD;
%token VOID_KEYWORD;
%token CASE_KEYWORD;
%token FLOAT_KEYWORD;
%token SHORT_KEYWORD;
%token VOLATILE_KEYWORD;
%token CHAR_KEYWORD;
%token FOR_KEYWORD;
%token SIGNED_KEYWORD;
%token WHILE_KEYWORD;
%token CONST_KEYWORD;
%token GOTO_KEYWORD;
%token SIZEOF_KEYWORD;
%token BOOL_KEYWORD;
%token CONTINUE_KEYWORD;
%token IF_KEYWORD;
%token STATIC_KEYWORD;
%token COMPLEX_KEYWORD;
%token DEFAULT_KEYWORD;
%token INLINE_KEYWORD;
%token STRUCT_KEYWORD;
%token IMAGINARY_KEYWORD;
%token DO_KEYWORD;
%token INT_KEYWORD;
%token SWITCH_KEYWORD;
%token DOUBLE_KEYWORD;
%token LONG_KEYWORD;
%token TYPEDEF_KEYWORD;
%token ELSE_KEYWORD;
%token REGISTER_KEYWORD;
%token UNION_KEYWORD;

%token <str> IDENTIFIER;

%token  <intval> INT_CONSTANT;
%token  <floatval> FLOAT_CONSTANT;
%token  <charval> CHAR_CONSTANT;

%token <str> STRING_LITERAL;

%token POINTER;
%token INCREMENT;
%token DECREMENT;
%token LEFT_SHIFT;
%token RIGHT_SHIFT;
%token LESS_EQUAL;
%token GREATER_EQUAL;
%token IS_EQUAL;
%token NOT_EQUAL;
%token LOGICALL_AND;
%token LOGICALL_OR;
%token ELLIPSIS;
%token MULTIPLY_BY;
%token DIVIDE_BY;
%token MOD_BY;
%token AND_EQUAL;
%token SUB_BY;
%token LEFT_SHIFT_EQUAL;
%token RIGHT_SHIFT_EQUAL;
%token ADD_BY;
%token XOR_EQUAL;
%token OR_EQUAL;

%type<expressionList> primary_expression postfix_expression unary_expression
%type<charval> unary_operator
%type<expressionList> cast_expression multiplicative_expression additive_expression shift_expression
%type<expressionList> relational_expression equality_expression and_expression
%type<expressionList> exclusive_or_expression inclusive_or_expression LOGICAL_AND_expression
%type<expressionList> logical_or_expression conditional_expression assignment_expression
%type<expressionList> assignment_expression_opt assignment_operator expression
%type<expressionList> constant_expression declaration
%type<type_> declaration_specifiers
%type<initDeclist> init_declarator_list
%type<decList> init_declarator direct_declarator declarator
%type<type_> constant specifier_qualifier_list
%type<expressionList> initializer
%type<decList> initializer_list
%type<type_> type_specifier pointer
%type<fList> parameter_list parameter_type_list parameter_type_list_opt
%type<fDef> parameter_declaration
%type<expressionList> jump_statement compound_statement block_item block_item_list
%type<expressionList> selection_statement iteration_statement
%type<expressionList> M N
%type<expressionList> statement expression_statement expression_opt
%type<fList> argument_expression_list
%type<decList> function_definition

%start translation_unit

%%
//Expressions
M: {
    $$ = new expression;
    $$->instr = quadlist.nextinstr;
};

N: {
    $$ = new expression;
    $$->nextlist = makelist(quadlist.nextinstr);
    quadlist.emit(GOTOOP,"","","");
};

primary_expression:     IDENTIFIER{
                                $$ = new expression;
                                string t = (*($1));     
                                STelement *h = currST->lookup(t);
                                $$->location = t;
                            }
                        | INT_CONSTANT{
                                $$ = new expression;
                                typeOf type;
                                type.type_specifier = "int";
                                operatorType op = CPY;
                                $$->location = currST->gentemp(type);
                                quadlist.emit(op,$$->location, $1);
                                typeUnion *declExp = new typeUnion;
                                declExp->int_val = $1;                     
                                currST->lookup($$->location)->initVal = declExp;
                                $$->isPointer = 0;

                            }
                    	| FLOAT_CONSTANT{
                                $$ = new expression;
                                typeOf type;
                                type.type_specifier = "double";
                                operatorType op = CPY;
                                $$->location = currST->gentemp(type);
                                quadlist.emit(op,$$->location, $1);
                                typeUnion *declExp = new typeUnion;
                                declExp->double_val = $1;
                                currST->lookup($$->location)->initVal = declExp;
                                $$->isPointer = 0;
                            }
                    	| CHAR_CONSTANT	{
                                $$ = new expression;
                                typeOf type;
                                type.type_specifier = "char";
                                operatorType op = CPY;
                                $$->location = currST->gentemp(type);
                                quadlist.emit(op,$$->location, $1);
                                typeUnion *declExp = new typeUnion;
                                declExp->char_val = $1;
                                currST->lookup($$->location)->initVal = declExp;
                                $$->isPointer = 0;
                            }
                        | STRING_LITERAL {
                                $$ = new expression;
                                string s = ".LC";
                                string temp = to_string(literal_count);
                                s = s + temp;
                                $$->location = s;
                                literal_count++;
                                literals.push_back(*$1);
                            }
                        | '(' expression ')'{   $$ = $2;}
                        ;

postfix_expression:     primary_expression{     $$ = $1;}
                        | postfix_expression '[' expression ']'	{
                                typeOf t = currST->lookup($1->location)->type;
                                string s;
                                typeOf t1;
                                t1.type_specifier = "int";
                            	int idx;
                            	string s1;
                            	idx = t.idx;
                            	s = currST->gentemp(t1);
                                quadlist.emit(CPY, s, 0);
                                $1 -> inner = new string(s);    
                            	s = *($1->inner);
                            	s1 = to_string(idx);
                                
                                quadlist.emit(MUL, s, s, s1);
                                quadlist.emit(ADD, s, s, $3->location);
                                quadlist.emit(MUL, s, s, string("4"));
                                $$ = $1;
                            }
                        | postfix_expression '(' ')'	{}
                        | postfix_expression '(' argument_expression_list ')' {
                                string f = $1->location;
                                SymbolTable *fsym = globalST.lookup(f)->nextVar;
                                FList *flist = ($3);
                                list<Fdef*>::iterator it;
                                int c = 0;
                                for(it = flist->func_def_list.begin(); it!=flist->func_def_list.end();it++){
                                    Fdef *f = *it;
                                    c++;
                                    quadlist.emit(PARAM, f->name,"","");
                                }
                                string s = to_string(c);
                        	    quadlist.emit(CALL,f,s,"");
                    		
                            }
                        | postfix_expression '.' IDENTIFIER	{}
                        | postfix_expression POINTER IDENTIFIER	{}
                        | postfix_expression INCREMENT {
                        
                                $$ = new expression;
                                string s = $1->location;
                                STelement * f = currST->lookup($1->location);
                                $$->location = currST->gentemp(f->type);

                                if(f->type.arrType=="array"){
                                    string temp = currST->gentemp(f->type);
                                    quadlist.emit(RIGHTINDEX, temp, $1->location, *($1->inner));
                                    quadlist.emit(CPY, $$->location, temp, "");
                                    quadlist.emit(ADD, temp, temp, "1");
                                    quadlist.emit(LEFTINDEX, $1->location, temp, *($1->inner));
                                }
                                else {
                                    quadlist.emit(CPY, $$->location, $1->location, "");
                                    quadlist.emit(ADD, $1->location, $1->location, "1");  
                                }   
                            }
                        | postfix_expression DECREMENT {

                                // same as above
                                $$ = new expression;
                                STelement * f = currST->lookup($1->location);
                                $$->location = currST->gentemp(f->type);
                                if(f->type.arrType=="array"){
                                    string temp = currST->gentemp(f->type);
                                    quadlist.emit(RIGHTINDEX, temp, $1->location, *($1->inner));
                                    quadlist.emit(CPY, $$->location, temp, "");
                                    quadlist.emit(SUB, temp, temp, "1");
                                    quadlist.emit(LEFTINDEX, $1->location, temp, *($1->inner));
                                }
                                else
                                {
                                    quadlist.emit(CPY, $$->location, $1->location, "");
                                    quadlist.emit(SUB, $1->location, $1->location, "1");    
                                }
                            }
                        | '(' type_specifier ')' '{' initializer_list '}'	{}
                        | '(' type_specifier ')' '{' initializer_list ',' '}'	{}
                        ;


argument_expression_list:    assignment_expression {
                                    Fdef *f = new Fdef;
                                    f->name = $1->location;
                                    $$ = new FList;
                                    f->type = &(currST->lookup(f->name)->type);
                                    $$->func_def_list.push_back(f);
                                }
                            | argument_expression_list ',' assignment_expression {
                                    Fdef *f = new Fdef;
                                    f->name = $3->location;
                                    $$ = new FList;
                                    f->type = &(currST->lookup(f->name)->type);
                                    $$ = $1;
                                    $$->func_def_list.push_back(f);
                                }
                            ;

unary_expression:   postfix_expression	{}
                    | INCREMENT unary_expression	 {
                            operatorType op = ADD;
                            $$ = new expression;
                            typeOf type;
                            type = currST->lookup($2->location)->type;
                            if(type.arrType=="array"){
                                string temp = currST->gentemp(type);
                                quadlist.emit(RIGHTINDEX, temp, $2->location, *($2->inner));
                                quadlist.emit(ADD, temp, temp, "1");
                                quadlist.emit(LEFTINDEX, $2->location, temp, *($2->inner));
                            }
                            else
                                quadlist.emit(op, $$->location, $2->location, "1");

                            type = currST->lookup($2->location)->type;
                            $$->location = currST->gentemp(type);
                            op = CPY;
                            quadlist.emit(op, $2->location, $$->location, "");
                        }
                    | DECREMENT unary_expression {
                            operatorType op = SUB;
                            $$ = new expression;
                            typeOf type;
                            type = currST->lookup($2->location)->type;
                            $$->location = currST->gentemp(type);
                            if(type.arrType=="array"){
                                string temp = currST->gentemp(type);
                                quadlist.emit(RIGHTINDEX, temp, $2->location, *($2->inner));
                                quadlist.emit(SUB, temp, temp, "1");
                                quadlist.emit(LEFTINDEX, $2->location, temp, *($2->inner));
                            }
                            else
                                quadlist.emit(op, $$->location, $2->location, "1");

                            type = currST->lookup($2->location)->type;
                            $$->location = currST->gentemp(type);
                            op = CPY;
                            quadlist.emit(op, $2->location, $$->location, "");        
                        }
                    | unary_operator cast_expression{
		                    $$ = new expression;
		                    typeOf type;
		                    type.type_specifier = string("int");
		                    if($1 == '-'){
		                        $$ = new expression; 
		                        $$->location = currST->gentemp(type);
		                        quadlist.emit(UNARY_SUB,$$->location,$2->location,"");
		                    }
		                    else if($1 == '&'){
		                        $$ = new expression;
				        	    type.ptrType = "ptr";
				        	    type.PC = 1;
				        	    type.size = 8;
				                $$->location = currST->gentemp(type);
				                quadlist.emit(ADDRESS,$$->location,$2->location,"");
		                    }
		                    else if($1 == '*'){
		                        $$ = new expression; 
		                        $$->location = currST->gentemp(type);
		                        quadlist.emit(RTPTR,$$->location,$2->location,"");
		                    }
		                    else{	$$ = $2;}
		                }
                    | SIZEOF_KEYWORD unary_expression	{}
                    | SIZEOF_KEYWORD '(' type_specifier ')'	{}
                    ;

unary_operator:		'&'	{	$$ = '&';}
					| '*'{	$$ = '*';}
					| '+'{	$$ = '+';}
					| '-'{	$$ = '-';}
					| '~'{	$$ = '~';}
					| '!'{	$$ = '!';}
					;

cast_expression: 	unary_expression	{}
					| '(' type_specifier ')' cast_expression	{}
					;
				

multiplicative_expression:	 cast_expression	{}
							| multiplicative_expression '*' cast_expression	{
								$$ = new expression;
								typeOf type1, type2, type;
								type1 = currST->lookup($1->location)->type;
								type2 = currST->lookup($3->location)->type;


								if(type2.arrType=="array"){
									string temp = currST->gentemp(type2);
									quadlist.emit(RIGHTINDEX, temp, $3->location, *($3->inner));
									$3->location = temp;
									$3->type.arrType = ""; 
								}
								if(type1.arrType=="array"){
									string temp = currST->gentemp(type1);
									quadlist.emit(RIGHTINDEX, temp, $1->location, *($1->inner));
									$1->location = temp;
									$1->type.arrType = ""; 
								}
				
								int flag = 0;
								if(type1.type_specifier == type2.type_specifier){
									type.type_specifier = type1.type_specifier;
									flag = 1;
								}
								if(type1.type_specifier=="double" && type2.type_specifier=="int"){   
									string t = currST->gentemp(type1);
									STelement *s = currST->lookup(t, type1.type_specifier);
									expression *e = new expression;
									e->location = t;
									e->type = type1;
									quadlist.convInt2Dbl(e,$3);
									type.type_specifier = type1.type_specifier;
								}
								else if(type1.type_specifier=="int"&&type2.type_specifier=="double"){   
									string t = currST->gentemp(type2);
									STelement *s = currST->lookup(t, type2.type_specifier);
									expression *e = new expression;
									e->location = t;
									e->type = type2;
									quadlist.convInt2Dbl(e,$1);
									type.type_specifier = type2.type_specifier;
								}
								if(type1.type_specifier=="double"&& type2.type_specifier=="char"){   
									string t = currST->gentemp(type1);
									STelement *s = currST->lookup(t, type1.type_specifier);
									expression *e = new expression;
									e->location = t;
									e->type = type1;
									quadlist.convChar2Dbl(e,$3);
									type.type_specifier = type1.type_specifier;
						
								}
								if(type1.type_specifier=="char"&& type2.type_specifier=="double"){   
									string t = currST->gentemp(type2);
									STelement *s = currST->lookup(t, type2.type_specifier);
									expression *e = new expression;
									e->location = t;
									e->type = type2;
									quadlist.convChar2Dbl(e,$1);
									type.type_specifier = type2.type_specifier;
						
								}
								if(type1.type_specifier=="char" && type2.type_specifier=="int"){   
									string t = currST->gentemp(type2);
									STelement *s = currST->lookup(t, type2.type_specifier);
									expression *e = new expression;
									e->location = t;
									e->type = type1;
									quadlist.convChar2Int(e,$1);
									type.type_specifier = type2.type_specifier;
						
								}
								if(type1.type_specifier=="int" && type2.type_specifier=="char"){   
									string t = currST->gentemp(type1);
									STelement *s = currST->lookup(t, type1.type_specifier);
									expression *e = new expression;
									e->location = t;
									e->type = type1;
									quadlist.convChar2Int(e,$3);
									type.type_specifier = type1.type_specifier;
						
								}
								$$->location = currST->gentemp(type);
								quadlist.emit(MUL, $$->location, $1->location, $3->location);

								}
							| multiplicative_expression '/' cast_expression	{

								 $$ = new expression;
									typeOf type1, type2, type;
									type1 = currST->lookup($1->location)->type;
									type2 = currST->lookup($3->location)->type;

									if(type2.arrType=="array"){
										string temp = currST->gentemp(type2);
										quadlist.emit(RIGHTINDEX, temp, $3->location, *($3->inner));
										$3->location = temp;
										$3->type.arrType = ""; 
									}
									if(type1.arrType=="array"){
										string temp = currST->gentemp(type1);
										quadlist.emit(RIGHTINDEX, temp, $1->location, *($1->inner));
										$1->location = temp;
										$1->type.arrType = ""; 
									}
									int flag = 0;
									if(type1.type_specifier == type2.type_specifier){
										type.type_specifier = type1.type_specifier;
										flag = 1;
									}
									if(type1.type_specifier=="double" && type2.type_specifier=="int"){   
										string t = currST->gentemp(type1);
										STelement *s = currST->lookup(t, type1.type_specifier);
										expression *e = new expression;
										e->location = t;
										e->type = type1;
										quadlist.convInt2Dbl(e,$3);
										type.type_specifier = type1.type_specifier;

									}
									else if(type1.type_specifier=="int" && type2.type_specifier=="double"){   
										string t = currST->gentemp(type2);
										STelement *s = currST->lookup(t, type2.type_specifier);
										expression *e = new expression;
										e->location = t;
										e->type = type2;
										quadlist.convInt2Dbl(e,$1);
										type.type_specifier = type2.type_specifier;
									}
									if(type1.type_specifier=="double" && type2.type_specifier=="char"){   
										string t = currST->gentemp(type1);
										STelement *s = currST->lookup(t, type1.type_specifier);
										expression *e = new expression;
										e->location = t;
										e->type = type1;
										quadlist.convChar2Dbl(e,$3);
										type.type_specifier = type1.type_specifier;
									}
									if(type1.type_specifier=="char" && type2.type_specifier=="double"){   
										string t = currST->gentemp(type2);
										STelement *s = currST->lookup(t, type2.type_specifier);
										expression *e = new expression;
										e->location = t;
										e->type = type2;
										quadlist.convChar2Dbl(e,$1);
										type.type_specifier = type2.type_specifier;
									}
									if(type1.type_specifier=="char" && type2.type_specifier=="int"){   
										string t = currST->gentemp(type2);
										STelement *s = currST->lookup(t, type2.type_specifier);
										expression *e = new expression;
										e->location = t;
										e->type = type1;
										quadlist.convChar2Int(e,$1);
										type.type_specifier = type2.type_specifier;
						
									}
									if(type1.type_specifier=="int" && type2.type_specifier=="char"){   
										string t = currST->gentemp(type1);
										STelement *s = currST->lookup(t, type1.type_specifier);
										expression *e = new expression;
										e->location = t;
										e->type = type1;
										quadlist.convChar2Int(e,$3);
										type.type_specifier = type1.type_specifier;
									}
									$$->location = currST->gentemp(type);
									quadlist.emit(DIV, $$->location, $1->location, $3->location);
								}
							| multiplicative_expression '%' cast_expression	{

									$$ = new expression;
									typeOf type1, type2, type;
									type1 = currST->lookup($1->location)->type;
									type2 = currST->lookup($3->location)->type;

									if(type2.arrType=="array") {
										string temp = currST->gentemp(type2);
										quadlist.emit(RIGHTINDEX, temp, $3->location, *($3->inner));
										$3->location = temp;
										$3->type.arrType = ""; 
									}  
									if(type1.arrType=="array"){
										string temp = currST->gentemp(type1);
										quadlist.emit(RIGHTINDEX, temp, $1->location, *($1->inner));
										$1->location = temp;
										$1->type.arrType = ""; 
									}
									int flag = 0;
									if(type1.type_specifier == type2.type_specifier){
										type.type_specifier = type1.type_specifier;
										flag = 1;
									}
									if(type1.type_specifier=="double" && type2.type_specifier=="int"){   
										string t = currST->gentemp(type1);
										STelement *s = currST->lookup(t, type1.type_specifier);
										expression *e = new expression;
										e->location = t;
										e->type = type1;
										quadlist.convInt2Dbl(e,$3);
										type.type_specifier = type1.type_specifier;
									}
									else if(type1.type_specifier=="int" && type2.type_specifier=="double"){   
										string t = currST->gentemp(type2);
										STelement *s = currST->lookup(t, type2.type_specifier);
										expression *e = new expression;
										e->location = t;
										e->type = type2;
										quadlist.convInt2Dbl(e,$1);
										type.type_specifier = type2.type_specifier;
									}
									if(type1.type_specifier=="double" && type2.type_specifier=="char"){   
										string t = currST->gentemp(type1);
										STelement *s = currST->lookup(t, type1.type_specifier);
										expression *e = new expression;
										e->location = t;
										e->type = type1;
										quadlist.convChar2Dbl(e,$3);
										type.type_specifier = type1.type_specifier;
									}
									if(type1.type_specifier=="char" && type2.type_specifier=="double") {   
										string t = currST->gentemp(type2);
										STelement *s = currST->lookup(t, type2.type_specifier);
										expression *e = new expression;
										e->location = t;
										e->type = type2;
										quadlist.convChar2Dbl(e,$1);
										type.type_specifier = type2.type_specifier;
									}
									if(type1.type_specifier=="char" && type2.type_specifier=="int"){   
										string t = currST->gentemp(type2);
										STelement *s = currST->lookup(t, type2.type_specifier);
										expression *e = new expression;
										e->location = t;
										e->type = type1;
										quadlist.convChar2Int(e,$1);
										type.type_specifier = type2.type_specifier;
									}
									if(type1.type_specifier=="int" && type2.type_specifier=="char"){   
										string t = currST->gentemp(type1);
										STelement *s = currST->lookup(t, type1.type_specifier);
										expression *e = new expression;
										e->location = t;
										e->type = type1;
										quadlist.convChar2Int(e,$3);
										type.type_specifier = type1.type_specifier;
									}
									$$->location = currST->gentemp(type);

									quadlist.emit(MOD, $$->location, $1->location, $3->location);
							}
							;

additive_expression: 	multiplicative_expression	{$$ = $1;}
						| additive_expression '+' multiplicative_expression	{

									$$ = new expression;
									typeOf type1, type2, type;
									type1 = currST->lookup($1->location)->type;
									type2 = currST->lookup($3->location)->type;

									if(type2.arrType=="array"){
										string temp = currST->gentemp(type2);
										quadlist.emit(RIGHTINDEX, temp, $3->location, *($3->inner));
										$3->location = temp;
										$3->type.arrType = ""; 
									}    
									if(type1.arrType=="array"){
										string temp = currST->gentemp(type1);
										quadlist.emit(RIGHTINDEX, temp, $1->location, *($1->inner));
										$1->location = temp;
										$1->type.arrType = ""; 
									}   
									int flag = 0;
									if(type1.type_specifier == type2.type_specifier){
										type.type_specifier = type1.type_specifier;
										flag = 1;
									}
									if(type1.type_specifier=="double" && type2.type_specifier=="int"){   
										string t = currST->gentemp(type1);
										STelement *s = currST->lookup(t, type1.type_specifier);
										expression *e = new expression;
										e->location = t;
										e->type = type1;
										quadlist.convInt2Dbl(e,$3);
										type.type_specifier = type1.type_specifier;

									}
									else if(type1.type_specifier=="int" && type2.type_specifier=="double") {   
										string t = currST->gentemp(type2);
										STelement *s = currST->lookup(t, type2.type_specifier);
										expression *e = new expression;
										e->location = t;
										e->type = type2;
										quadlist.convInt2Dbl(e,$1);
										type.type_specifier = type2.type_specifier;
									}
									if(type1.type_specifier=="double" && type2.type_specifier=="char"){   
										string t = currST->gentemp(type1);
										STelement *s = currST->lookup(t, type1.type_specifier);
										expression *e = new expression;
										e->location = t;
										e->type = type1;
										quadlist.convChar2Dbl(e,$3);
										type.type_specifier = type1.type_specifier;
									}
									if(type1.type_specifier=="char" && type2.type_specifier=="double"){   
										string t = currST->gentemp(type2);
										STelement *s = currST->lookup(t, type2.type_specifier);
										expression *e = new expression;
										e->location = t;
										e->type = type2;
										quadlist.convChar2Dbl(e,$1);
										type.type_specifier = type2.type_specifier;
									}
									if(type1.type_specifier=="char" && type2.type_specifier=="int"){   
										string t = currST->gentemp(type2);
										STelement *s = currST->lookup(t, type2.type_specifier);
										expression *e = new expression;
										e->location = t;
										e->type = type1;
										quadlist.convChar2Int(e,$1);
										type.type_specifier = type2.type_specifier;
									}
									if(type1.type_specifier=="int" && type2.type_specifier=="char"){   
										string t = currST->gentemp(type1);
										STelement *s = currST->lookup(t, type1.type_specifier);
										expression *e = new expression;
										e->location = t;
										e->type = type1;
										quadlist.convChar2Int(e,$3);
										type.type_specifier = type1.type_specifier;
									}
									$$->location = currST->gentemp(type);
									quadlist.emit(ADD, $$->location, $1->location, $3->location);

							}
						| additive_expression '-' multiplicative_expression{

								$$ = new expression;
								typeOf type1, type2, type;
								type1 = currST->lookup($1->location)->type;
								type2 = currST->lookup($3->location)->type;

								if(type2.arrType=="array"){
									string temp = currST->gentemp(type2);
									quadlist.emit(RIGHTINDEX, temp, $3->location, *($3->inner));
									$3->location = temp;
									$3->type.arrType = ""; 
								}
				
								if(type1.arrType=="array") {
									string temp = currST->gentemp(type1);
									quadlist.emit(RIGHTINDEX, temp, $1->location, *($1->inner));
									$1->location = temp;
									$1->type.arrType = ""; 
								}
				
								int flag = 0;
								if(type1.type_specifier == type2.type_specifier){
									type.type_specifier = type1.type_specifier;
									flag = 1;
								}
								if(type1.type_specifier=="double" && type2.type_specifier=="int")  {   
									string t = currST->gentemp(type1);
									STelement *s = currST->lookup(t, type1.type_specifier);
									expression *e = new expression;
									e->location = t;
									e->type = type1;
									quadlist.convInt2Dbl(e,$3);
									type.type_specifier = type1.type_specifier;
									}
								else if(type1.type_specifier=="int" && type2.type_specifier=="double")  {   
									string t = currST->gentemp(type2);
									STelement *s = currST->lookup(t, type2.type_specifier);
									expression *e = new expression;
									e->location = t;
									e->type = type2;
									quadlist.convInt2Dbl(e,$1);
									type.type_specifier = type2.type_specifier;
								}
								if(type1.type_specifier=="double" && type2.type_specifier=="char") {   
									string t = currST->gentemp(type1);
									STelement *s = currST->lookup(t, type1.type_specifier);
									expression *e = new expression;
									e->location = t;
									e->type = type1;
									quadlist.convChar2Dbl(e,$3);
									type.type_specifier = type1.type_specifier;
						
								}
								if(type1.type_specifier=="char" && type2.type_specifier=="double")  {   
									string t = currST->gentemp(type2);
									STelement *s = currST->lookup(t, type2.type_specifier);
									expression *e = new expression;
									e->location = t;
									e->type = type2;
									quadlist.convChar2Dbl(e,$1);
									type.type_specifier = type2.type_specifier;
						
								}
								if(type1.type_specifier=="char" && type2.type_specifier=="int")  {   
									string t = currST->gentemp(type2);
									STelement *s = currST->lookup(t, type2.type_specifier);
									expression *e = new expression;
									e->location = t;
									e->type = type1;
									quadlist.convChar2Int(e,$1);
									type.type_specifier = type2.type_specifier;
						
								}
								if(type1.type_specifier=="int" && type2.type_specifier=="char") {   
									string t = currST->gentemp(type1);
									STelement *s = currST->lookup(t, type1.type_specifier);
									expression *e = new expression;
									e->location = t;
									e->type = type1;
									quadlist.convChar2Int(e,$3);
									type.type_specifier = type1.type_specifier;
						
								}
								$$->location = currST->gentemp(type);
								quadlist.emit(SUB, $$->location, $1->location, $3->location);
						}
						;

shift_expression: 	additive_expression	{}
					| shift_expression LEFT_SHIFT additive_expression{
							$$ = new expression;
							typeOf type1, type2, type;
							type1 = currST->lookup($1->location)->type;
							type2 = currST->lookup($3->location)->type;

							if(type2.arrType=="array"){
								string temp = currST->gentemp(type2);
								quadlist.emit(RIGHTINDEX, temp, $3->location, *($3->inner));
								$3->location = temp;
								$3->type.arrType = ""; 
							}
				
							if(type1.arrType=="array") {
								string temp = currST->gentemp(type1);
								quadlist.emit(RIGHTINDEX, temp, $1->location, *($1->inner));
								$1->location = temp;
								$1->type.arrType = ""; 
							}
							int flag = 0;
				
						   if(type1.type_specifier=="double"){
									type1.type_specifier = "int";
									string t = currST->gentemp(type1);
									STelement *s = currST->lookup(t, "int");
									expression *e = new expression;
									e->location = t;
									e->type.type_specifier = "int";
									quadlist.convDbl2Int(e,$3);

						   }
						   else if(type1.type_specifier=="char"){
									type1.type_specifier = "int";
									string t = currST->gentemp(type1);
									STelement *s = currST->lookup(t, "int");
									expression *e = new expression;
									e->location = t;
									e->type.type_specifier = "int";
									quadlist.convChar2Int(e,$3);
									//type.type_specifier = type1.type_specifier;
						  }
						  type1.type_specifier = "int";
						  $$->location = currST->gentemp(type1);
						  quadlist.emit(SHIFTLEFT, $$->location, $1->location, $3->location);
						}
					| shift_expression RIGHT_SHIFT additive_expression{
							$$ = new expression;
							typeOf type1, type2, type;
							type1 = currST->lookup($1->location)->type;
							type2 = currST->lookup($3->location)->type;

							if(type2.arrType=="array"){
								string temp = currST->gentemp(type2);
								quadlist.emit(RIGHTINDEX, temp, $3->location, *($3->inner));
								$3->location = temp;
								$3->type.arrType = ""; 
							}
							if(type1.arrType=="array") {
								string temp = currST->gentemp(type1);
								quadlist.emit(RIGHTINDEX, temp, $1->location, *($1->inner));
								$1->location = temp;
								$1->type.arrType = ""; 
							}
							int flag = 0;
							if(type1.type_specifier=="double"){
								type1.type_specifier = "int";
								string t = currST->gentemp(type1);
								STelement *s = currST->lookup(t, "int");
								expression *e = new expression;
								e->location = t;
								e->type.type_specifier = "int";
							   quadlist.convDbl2Int(e,$3);

							}
							else if(type1.type_specifier=="char") {
								type1.type_specifier = "int";
								string t = currST->gentemp(type1);
								STelement *s = currST->lookup(t, "int");
								expression *e = new expression;
								e->location = t;
								e->type.type_specifier = "int";
								quadlist.convChar2Int(e,$3);

							}
							type1.type_specifier = "int";
							$$->location = currST->gentemp(type1);
							quadlist.emit(SHIFTRIGHT, $$->location, $1->location, $3->location);
					}
					;
					

relational_expression: 	shift_expression	{}
						| relational_expression '<' shift_expression{
								typeOf type1, type2, type;
								type1 = currST->lookup($1->location)->type;
								type2 = currST->lookup($3->location)->type;

								if(type2.arrType=="array"){
									string temp = currST->gentemp(type2);
									quadlist.emit(RIGHTINDEX, temp, $3->location, *($3->inner));
									$3->location = temp;
									$3->type.arrType = ""; 	
								}  
								if(type1.arrType=="array") {
									string temp = currST->gentemp(type1);
									quadlist.emit(RIGHTINDEX, temp, $1->location, *($1->inner));
									$1->location = temp;
									$1->type.arrType = ""; 
								}
								$$ = new expression;
								$$->type.type_specifier = "bool";
								$$->location = currST->gentemp($$->type);
								$$->truelist = makelist(quadlist.nextinstr);
								$$->falselist = makelist(quadlist.nextinstr + 1);
								quadlist.emit(IF_LT, "", $1->location, $3->location);
								quadlist.emit(GOTOOP,"","","");
							}
						| relational_expression '>' shift_expression{
								typeOf type1, type2, type;
								type1 = currST->lookup($1->location)->type;
								type2 = currST->lookup($3->location)->type;

								if(type2.arrType=="array"){
									string temp = currST->gentemp(type2);
									quadlist.emit(RIGHTINDEX, temp, $3->location, *($3->inner));
									$3->location = temp;
									$3->type.arrType = ""; 
								}
								if(type1.arrType=="array") {
									string temp = currST->gentemp(type1);
									quadlist.emit(RIGHTINDEX, temp, $1->location, *($1->inner));
									$1->location = temp;
									$1->type.arrType = ""; 
								}
								$$ = new expression;
								$$->type.type_specifier = "bool";
								$$->location = currST->gentemp($$->type);
								$$->truelist = makelist(quadlist.nextinstr);
								$$->falselist = makelist(quadlist.nextinstr + 1);
								quadlist.emit(IF_GT, "", $1->location, $3->location);
								quadlist.emit(GOTOOP,"","","");
							}
						| relational_expression LESS_EQUAL shift_expression	{
								typeOf type1, type2, type;
								type1 = currST->lookup($1->location)->type;
								type2 = currST->lookup($3->location)->type;

								if(type2.arrType=="array"){
									string temp = currST->gentemp(type2);
									quadlist.emit(RIGHTINDEX, temp, $3->location, *($3->inner));
									$3->location = temp;
									$3->type.arrType = ""; //check
								}    
								if(type1.arrType=="array") {
									string temp = currST->gentemp(type1);
									quadlist.emit(RIGHTINDEX, temp, $1->location, *($1->inner));
									$1->location = temp;
									$1->type.arrType = ""; 
								}
								$$ = new expression;
								$$->type.type_specifier = "bool";
								$$->location = currST->gentemp($$->type);
								$$->truelist = makelist(quadlist.nextinstr);
								$$->falselist = makelist(quadlist.nextinstr + 1);
								quadlist.emit(IF_LE, "", $1->location, $3->location);
								quadlist.emit(GOTOOP,"","","");
							}
						| relational_expression GREATER_EQUAL shift_expression{
								typeOf type1, type2, type;
								type1 = currST->lookup($1->location)->type;
								type2 = currST->lookup($3->location)->type;

								if(type2.arrType=="array"){
									string temp = currST->gentemp(type2);
									quadlist.emit(RIGHTINDEX, temp, $3->location, *($3->inner));
									$3->location = temp;
									$3->type.arrType = ""; 
								}       
								if(type1.arrType=="array") {
									string temp = currST->gentemp(type1);
									quadlist.emit(RIGHTINDEX, temp, $1->location, *($1->inner));
									$1->location = temp;
									$1->type.arrType = ""; 
								}       
								$$ = new expression;
								$$->type.type_specifier = "bool";
								$$->location = currST->gentemp($$->type);
								$$->truelist = makelist(quadlist.nextinstr);
								$$->falselist = makelist(quadlist.nextinstr + 1);
								quadlist.emit(IF_GE, "", $1->location, $3->location);
								quadlist.emit(GOTOOP,"","","");
							}
						;
						

equality_expression: relational_expression	{}
					| equality_expression IS_EQUAL relational_expression{
							typeOf type1, type2, type;
							type1 = currST->lookup($1->location)->type;
							type2 = currST->lookup($3->location)->type;

							if(type2.arrType=="array"){
								string temp = currST->gentemp(type2);
								quadlist.emit(RIGHTINDEX, temp, $3->location, *($3->inner));
								$3->location = temp;
								$3->type.arrType = ""; 	
							}   
							if(type1.arrType=="array") {
								string temp = currST->gentemp(type1);
								quadlist.emit(RIGHTINDEX, temp, $1->location, *($1->inner));
								$1->location = temp;
								$1->type.arrType = ""; 
							}
				
							$$ = new expression;
							$$->type.type_specifier = "bool";
							$$->location = currST->gentemp($$->type);
							$$->truelist = makelist(quadlist.nextinstr);
							$$->falselist = makelist(quadlist.nextinstr + 1);
							quadlist.emit(IF_EQ,"",$1->location, $3->location);
							quadlist.emit(GOTOOP,"","","");
				   		}
					| equality_expression NOT_EQUAL relational_expression{
							typeOf type1, type2, type;
							type1 = currST->lookup($1->location)->type;
							type2 = currST->lookup($3->location)->type;

							if(type2.arrType=="array"){
								string temp = currST->gentemp(type2);
								quadlist.emit(RIGHTINDEX, temp, $3->location, *($3->inner));
								$3->location = temp;
								$3->type.arrType = ""; //check
							}
				
							if(type1.arrType=="array") {
								string temp = currST->gentemp(type1);
								quadlist.emit(RIGHTINDEX, temp, $1->location, *($1->inner));
								$1->location = temp;
								$1->type.arrType = ""; //check
							}
				
							$$ = new expression;
							$$->type.type_specifier = "bool";
							$$->location = currST->gentemp($$->type);
							$$->truelist = makelist(quadlist.nextinstr);
							$$->falselist = makelist(quadlist.nextinstr + 1);
							quadlist.emit(IF_NEQ,"",$1->location, $3->location);
							quadlist.emit(GOTOOP,"","","");
							}
					;

and_expression: equality_expression	{}
				| and_expression '&' equality_expression{
						typeOf type1, type2, type;
						type1 = currST->lookup($1->location)->type;
						type2 = currST->lookup($3->location)->type;

						if(type2.arrType=="array"){
							string temp = currST->gentemp(type2);
							quadlist.emit(RIGHTINDEX, temp, $3->location, *($3->inner));
							$3->location = temp;
							$3->type.arrType = ""; //check
						}
				
						if(type1.arrType=="array") {
							string temp = currST->gentemp(type1);
							quadlist.emit(RIGHTINDEX, temp, $1->location, *($1->inner));
							$1->location = temp;
							$1->type.arrType = ""; //check
						}
				
						$$ = new expression;
						STelement *f = currST->lookup($1->location);//check
						typeOf t;
						t = f->type;
						$$->location = currST->gentemp(t);
						quadlist.emit(LOGICAL_AND, $$->location, $1->location, $3->location);
			   	 }
				;
				

exclusive_or_expression: and_expression{}
						| exclusive_or_expression '^' and_expression{
							typeOf type1, type2, type;
							type1 = currST->lookup($1->location)->type;
							type2 = currST->lookup($3->location)->type;

							if(type2.arrType=="array"){
								string temp = currST->gentemp(type2);
								quadlist.emit(RIGHTINDEX, temp, $3->location, *($3->inner));
								$3->location = temp;
								$3->type.arrType = ""; 
							}
							if(type1.arrType=="array") {
								string temp = currST->gentemp(type1);
								quadlist.emit(RIGHTINDEX, temp, $1->location, *($1->inner));
								$1->location = temp;
								$1->type.arrType = ""; 
							}
				
							$$ = new expression;
							STelement *f = currST->lookup($1->location);
							typeOf t;
							t = f->type;
							$$->location = currST->gentemp(t);
							quadlist.emit(BINARYXOR, $$->location, $1->location, $3->location);
						}
						;
						
inclusive_or_expression: exclusive_or_expression{}
						| inclusive_or_expression '|' exclusive_or_expression{
							typeOf type1, type2, type;
							type1 = currST->lookup($1->location)->type;
							type2 = currST->lookup($3->location)->type;

							if(type2.arrType=="array"){
								string temp = currST->gentemp(type2);
								quadlist.emit(RIGHTINDEX, temp, $3->location, *($3->inner));
								$3->location = temp;
								$3->type.arrType = ""; 
							}
							if(type1.arrType=="array") {
								string temp = currST->gentemp(type1);
								quadlist.emit(RIGHTINDEX, temp, $1->location, *($1->inner));
								$1->location = temp;
								$1->type.arrType = ""; 
							}
				
							$$ = new expression;
							STelement *f = currST->lookup($1->location);
							typeOf t;
							t = f->type;
							$$->location = currST->gentemp(t);
							quadlist.emit(BINARYOR, $$->location, $1->location, $3->location);
						}
						;
						
LOGICAL_AND_expression: inclusive_or_expression	{}
						| LOGICAL_AND_expression N LOGICALL_AND M inclusive_or_expression	N{
							typeOf type1, type2;
							type1 = currST->lookup($1->location)->type;
							type2 = currST->lookup($5->location)->type;

							if(type2.arrType=="array"){
								string temp = currST->gentemp(type2);
								quadlist.emit(RIGHTINDEX, temp, $5->location, *($5->inner));
								$5->location = temp;
								$5->type.arrType = "";
							}
							if(type1.arrType=="array") {
								string temp = currST->gentemp(type1);
								quadlist.emit(RIGHTINDEX, temp, $1->location, *($1->inner));
								$1->location = temp;
								$1->type.arrType = ""; 
							}
				
							typeOf type;
							type.type_specifier = "bool";
							$$ = new expression;
							$$->type = type;

							quadlist.backpatch($2->nextlist, quadlist.nextinstr);
							quadlist.conv2Bool($1);

							quadlist.backpatch($6->nextlist, quadlist.nextinstr);
							quadlist.conv2Bool($5);

							quadlist.backpatch($1->truelist, $4->instr);
							$$->truelist = $5->truelist;
							$$->falselist = merge($1->falselist, $5->falselist);

						}
						;

logical_or_expression: 	LOGICAL_AND_expression	{}
						| logical_or_expression N LOGICALL_OR M LOGICAL_AND_expression N{
							typeOf type1, type2;
							type1 = currST->lookup($1->location)->type;
							type2 = currST->lookup($5->location)->type;

							if(type2.arrType=="array"){
								string temp = currST->gentemp(type2);
								quadlist.emit(RIGHTINDEX, temp, $5->location, *($5->inner));
								$5->location = temp;
								$5->type.arrType = ""; //check
							}    
							if(type1.arrType=="array") {
								string temp = currST->gentemp(type1);
								quadlist.emit(RIGHTINDEX, temp, $1->location, *($1->inner));
								$1->location = temp;
								$1->type.arrType = ""; //check
							}
				
							typeOf type;
							type.type_specifier = "bool";
							$$ = new expression;
							$$->type = type;
							quadlist.backpatch($2->nextlist, quadlist.nextinstr);
							quadlist.conv2Bool($1);

							quadlist.backpatch($6->nextlist, quadlist.nextinstr);
							quadlist.conv2Bool($5);

							quadlist.backpatch($1->falselist, $4->instr);
							$$->truelist = merge($1->truelist, $5->truelist);
							$$->falselist = $5->falselist;
						}
						;
						

conditional_expression: logical_or_expression	{}
						| logical_or_expression N '?' M expression N ':' M conditional_expression{
							typeOf type1, type2;
							type1 = currST->lookup($5->location)->type;
							type2 = currST->lookup($9->location)->type;

							if(type2.arrType=="array"){
								string temp = currST->gentemp(type2);
								quadlist.emit(RIGHTINDEX, temp, $9->location, *($9->inner));
								$9->location = temp;
								$9->type.arrType = ""; 
							}	
							if(type1.arrType=="array") {
								string temp = currST->gentemp(type1);
								quadlist.emit(RIGHTINDEX, temp, $5->location, *($5->inner));
								$9->location = temp;
								$9->type.arrType = "";
							}
				
							$$ = new expression;
							list<int> I;
							typeOf type;
							type = currST->lookup($5->location)->type;
							$$->location = currST->gentemp(type);
							quadlist.emit(CPY, $$->location, $9->location,"");
							I = makelist(quadlist.nextinstr);
							quadlist.emit(GOTOOP,"","","");
							quadlist.backpatch($6->nextlist, quadlist.nextinstr);
							quadlist.emit(CPY, $$->location, $5->location, "");
							I = merge(I, makelist(quadlist.nextinstr));
							quadlist.emit(GOTOOP,"", "", "");
							quadlist.backpatch($2->nextlist, quadlist.nextinstr);
							quadlist.conv2Bool($1);
							quadlist.backpatch($1->truelist, $4->instr);
							quadlist.backpatch($1->falselist, $8->instr);
							quadlist.backpatch(I, quadlist.nextinstr);
						}
						;
						


assignment_expression: 	conditional_expression {}
						| unary_expression assignment_operator assignment_expression {

							typeOf type1, type2, type;
							type1 = currST->lookup($1->location)->type;
							type2 = currST->lookup($3->location)->type;

							if(type2.arrType=="array"){
								string temp = currST->gentemp(type2);
								quadlist.emit(RIGHTINDEX, temp, $3->location, *($3->inner));
								$3->location = temp;
								$3->type.arrType = ""; 
							}
							if(type1.arrType=="array") 
								quadlist.emit(LEFTINDEX, $1->location, $3->location, *($1->inner));
							else
								quadlist.emit(CPY, $1->location, $3->location, "");
							$$ = $1;
						}
						;
						

assignment_operator: 	'='	{}
						| MULTIPLY_BY	{}
						| DIVIDE_BY	{}
						| MOD_BY	{}
						| AND_EQUAL	{}
						| SUB_BY	{}
						| LEFT_SHIFT_EQUAL	{}
						| RIGHT_SHIFT_EQUAL	{}
						| ADD_BY	{}
						| XOR_EQUAL	{}
						| OR_EQUAL	{}
						;
						
expression: assignment_expression {	$$ = $1;}
			| expression ',' assignment_expression{ }
			;

constant_expression: conditional_expression	{}
    				;


// Declarations
declaration:	 declaration_specifiers ';'{}
				| declaration_specifiers init_declarator_list ';'{

					initDecList *new_dec = new initDecList;
					new_dec = $2;
					int size = 0;
					typeOf *type = $1;
					if(type->type_specifier=="int") size = 4;
					if(type->type_specifier=="double") size = 8;
					if(type->type_specifier=="char") size = 1;

					list<declaration*>::iterator it;
					for(it = $2->declist.begin(); it != $2->declist.end(); it++)
					{
						declaration *new_dec = *it;
						if(new_dec->type!=NULL){
							if(new_dec->type->type_specifier.compare("function")==0)
							{
								string name = new_dec->decl;

								currST = &globalST;
								quadlist.emit(_FUNC_END,name,"","");

							}
						
							STelement *ret, *f;
							SymbolTable *nest;
							if(new_dec->type->type_specifier.compare("function")==0)
							{
								f = currST->lookup(new_dec->decl, type->type_specifier);
								nest = f->nextVar;
								ret = nest->lookup("retVal", type->type_specifier, new_dec->PC);
								f->offset = currST->offset;
								f->size = size;
								f->initVal = NULL;
								continue;
							}
						}
						STelement *f1 = currST->lookup(new_dec->decl, type->type_specifier);

						f1->nextVar = NULL;

						if(new_dec->alist == vector<int>() && new_dec->PC == 0)
						{
						    f1->offset = currST->offset;
						    f1->type = *type;
						    f1 = currST->lookup(new_dec->decl, type->type_specifier);
						    if(new_dec->declExp){
						        string x = new_dec->declExp->location;
						        quadlist.emit(CPY, new_dec->decl, x, "");
						        f1->initVal = currST->lookup(x,f1->type.type_specifier)->initVal;
						    }
						    else
						        new_dec->declExp = NULL;
						}
						else if(new_dec -> PC > 0)
						{
						    STelement *sp;
						    for(sp = currST->ST; sp < &currST->ST[currST->count]; sp++){
						        if(!sp->name.empty() && sp->name!=new_dec->decl){
						            sp->offset = currST->offset-4;
						            sp->PC = new_dec->PC;
						            sp->type = *type;
						            sp->type.ptrType = "ptr";
						            sp->size = 4;
						        }
						    }
						}

						else if(new_dec->alist!=vector<int>()){
						    STelement *sp;
						    for(sp = currST->ST; sp < &currST->ST[currST->count]; sp++){
						        if(!sp->name.empty() && !sp->name.compare(new_dec->decl)){
						            int temp_size = size;
						            sp->offset = currST->offset-4;
						            sp->type = *type;
									sp->type.type_specifier = type->type_specifier;
						            sp->type.arrType = "array";
						            sp->type.ptrType = "";

						            for(int i = 0; i < new_dec->alist.size(); i++){
						                sp->type.typeList.push_back(new_dec->alist[i]);
						            }
						            for (int i = 0; i < sp->type.typeList.size(); ++i){
						                temp_size = temp_size * sp->type.typeList[i];
						            }
						            sp->size = temp_size;
						            currST->offset = currST->offset + temp_size;
						        }
						    }
						}
					}
				}
				;
				

declaration_specifiers: storage_class_specifier{}
						| storage_class_specifier declaration_specifiers{}
						| constant{	$$ = $1;}
						| constant declaration_specifiers{}
						| type_qualifier{}
						| type_qualifier declaration_specifiers	 {}
						| function_specifier{}
						| function_specifier declaration_specifiers	 {}
						;
						


init_declarator_list: 	init_declarator{ 
								$$ = new initDecList;
								$$->declist.push_back($1);
							}
						| init_declarator_list ',' init_declarator{
								$1->declist.push_back($3);
								$$ = $1;
							}
						;
						


init_declarator: declarator {
						$$ = $1;
						$$->declExp = NULL;
					}
				| declarator '=' initializer{
						$$ = $1;
						$$->declExp = $3;
					}
				;
				

storage_class_specifier: EXTERN_KEYWORD	
						| STATIC_KEYWORD
						| AUTO_KEYWORD	
						| REGISTER_KEYWORD	
						{}
						;

constant  : VOID_KEYWORD{
						$$ = new typeOf;
						$$->type_specifier = string("void"); 
				}
			| CHAR_KEYWORD	{
				    $$ = new typeOf;
					$$->type_specifier = string("char");
					$$->next = NULL;

				}
			| SHORT_KEYWORD	{ }
			| INT_KEYWORD	{
				    $$ = new typeOf;
					$$->type_specifier = string("int");
					$$->next = NULL;
				}
			| LONG_KEYWORD	{ }
			| FLOAT_KEYWORD	{ }
			| DOUBLE_KEYWORD {
					$$ = new typeOf;
					$$->type_specifier = string("double");
					$$->next = NULL;
				}
			| SIGNED_KEYWORD	{}
			| UNSIGNED_KEYWORD	{}
			| BOOL_KEYWORD	{}
			| COMPLEX_KEYWORD	{}
			| IMAGINARY_KEYWORD	{}
			| enum_specifier {}
			;

specifier_qualifier_list: constant {	$$ = $1;}
						| constant specifier_qualifier_list {}
						| type_qualifier	{}
						| type_qualifier specifier_qualifier_list	{ }
						;
						

enum_specifier: ENUM_KEYWORD '{' enumerator_list '}'	
				| ENUM_KEYWORD IDENTIFIER '{' enumerator_list '}'	
				| ENUM_KEYWORD '{' enumerator_list ',' '}'	
				| ENUM_KEYWORD IDENTIFIER '{' enumerator_list ',' '}'	
				| ENUM_KEYWORD IDENTIFIER	{}
				{}
				;
				
enumerator_list: enumerator	
				| enumerator_list ',' enumerator	
				{}
				;
				
enumerator: enumeration_constant	
			| enumeration_constant '=' constant_expression
			{}
			;
			
enumeration_constant: IDENTIFIER {}
					;
					
type_qualifier: CONST_KEYWORD	
				| RESTRICT_KEYWORD	
				| VOLATILE_KEYWORD	
				{}
				;
				
function_specifier: INLINE_KEYWORD	
					{}
					;
					
declarator: pointer direct_declarator	{
				$$ = $2;
				$$->PC = $1->PC;
			}
			| direct_declarator	{
				$$ = $1;
				$$->PC = 0;

			}
			;
			


direct_declarator : IDENTIFIER	{
							$$ = new declaration; 
							$$->decl = *($1);
						}
					| '(' declarator ')' {	$$ = $2;}
					| direct_declarator '[' type_qualifier_list_opt assignment_expression_opt ']' {
							$$ = $1;
							int idx = currST->lookup($4->location)->initVal->int_val;
							$$->alist.push_back(idx);
						}
					| direct_declarator '[' STATIC_KEYWORD type_qualifier_list_opt assignment_expression ']'{}
					| direct_declarator '[' type_qualifier_list STATIC_KEYWORD assignment_expression ']'{}
					| direct_declarator '[' type_qualifier_list_opt '*' ']'	{}
					| direct_declarator '(' parameter_type_list_opt')'{

							list<Fdef*> l = $3->func_def_list;
							SymbolTable *nextST = new SymbolTable;
							$$ = $1;
							string name = $$->decl;
							$$->type = new typeOf;
							$$->type->type_specifier = string("function");
							$$->type->numParam = l.size();
							STelement *func_lookup = St->lookup($$->decl, $$->type->type_specifier);

							for(int i=0; i < St->count; i++){
								if(St->ST[i].name==$$->decl){
									St->ST[i].type.type_specifier = "function";
									St->ST[i].type.numParam = l.size();
								}
							}

							func_lookup -> nextVar = nextST;
							list<Fdef*>::iterator it;
							for(it = l.begin(); it != l.end(); it++) {
								Fdef *temp = *it;
								nextST -> lookup(temp->name, temp->type->type_specifier);
								for(int i = 0; i<nextST->count; i++){
									if(nextST->ST[i].name==temp->name){
										if(temp->type->arrType=="array"){
											nextST->ST[i].type.arrType = "array";
											nextST->ST[i].type.idx = temp->type->idx;
										}
									}
								}
							}

							STelement *sp;
							for(sp = St->ST; sp < &St->ST[St->count]; sp++){
								if(!sp->name.empty() && !sp->name.compare($$->decl)) {
									sp->nextVar = nextST;
								}
							}
							currST = nextST;
							quadlist.emit(_FUNC_START, name,"","");
						}
					| direct_declarator '(' identifier_list')'{}
					;
	/*				
identifier_list_opt: identifier_list	
				   	|
					{}
				   	;
*/
assignment_expression_opt: assignment_expression	
						   |
							{}
						   ;
						   
type_qualifier_list_opt: type_qualifier_list	
						|
						{}
						;
						

pointer: '*' {
					$$ = new typeOf;
					$$->type_specifier = string("ptr");
					$$->next = NULL;
					$$->ptrType = string("ptr");
					$$->PC = 1;
		   	 }
		| '*' type_qualifier_list {}
		| '*' pointer{
					$$ = new typeOf;
					$$->type_specifier = string("ptr");
					$$->next = NULL;
					$$->ptrType = string("ptr");
					$$->PC = $2->PC + 1; 
				}
		| '*' type_qualifier_list pointer{}
		;

type_qualifier_list: type_qualifier	
					| type_qualifier_list type_qualifier	
					{}
					;
					
parameter_type_list_opt:parameter_type_list
						|   
						{ 	$$ = new FList; }
						;

parameter_type_list: parameter_list{
						$$ = new FList;
						$$ = $1;
					}
					| parameter_list ',' ELLIPSIS {}
					;
					
parameter_list: parameter_declaration {
						$$ = new FList;
						$$->func_def_list.push_back($1);
					}
				| parameter_list ',' parameter_declaration	{
						$1->func_def_list.push_back($3);
						$$ = $1;
					}
				;
				
parameter_declaration: declaration_specifiers declarator	{
									$$ = new Fdef;
									$$->type = $1;
								if($2->alist.size()>0)
									{$$->type->arrType = "array";$$->type->idx = $2->alist[0];$$->type->type_specifier = $1->type_specifier;
								}
								for(int i=0; i<currST->count; i++){
									if(currST->ST[i].name.compare($2->decl)==0){
										if($2->type->arrType=="array" || currST->ST[i].type.arrType=="array"){
											currST->ST[i].type.arrType = "array";
											$$->type->arrType = "array";
										}
									}
								}
								$$->name = $2->decl;
							}
						| declaration_specifiers {}
						;
						

identifier_list: IDENTIFIER	
				| identifier_list ',' IDENTIFIER	
				{}
				;
				

type_specifier: specifier_qualifier_list	{	 $$ = $1;}
				;
				

initializer: assignment_expression	 {	 $$ = $1;}
			| '{' initializer_list '}' {}
			| '{' initializer_list ',' '}'  { }
			;
			

initializer_list: initializer {}	
				| designation initializer{}	
				| initializer_list ',' initializer{}	
				| initializer_list ',' designation initializer{}	
				;
				

designation: designator_list '='	
			{}
			;
			

designator_list: designator	
				| designator_list designator	
				{}
				;
				
designator: '[' constant_expression ']'	
			| '.' IDENTIFIER	
			{}
			;
			
// Statements
statement: labeled_statement{}	
			| compound_statement{}
			| expression_statement{}	
			| selection_statement{}	
			| iteration_statement{}	
			| jump_statement	{}
			;
			
labeled_statement: IDENTIFIER ':' statement	
					| CASE_KEYWORD constant_expression ':' statement	
					| DEFAULT_KEYWORD ':' statement	
					{}
					;
					

compound_statement:'{' '}' {}
					|'{' block_item_list '}' {	$$ = $2;}
					;

block_item_list: block_item {
					$$ = $1;
					quadlist.backpatch($1->nextlist, quadlist.nextinstr);
					}
				| block_item_list M block_item {
					quadlist.backpatch($1->nextlist, $2->instr);
					$$ = new expression;
					$$->nextlist = $3->nextlist;

				}
				;
				
block_item: declaration { 	$$ = new expression; }
			| statement	
			{ }
			;
			
expression_statement: ';' { 	 $$ = new expression; }
					| expression ';' { }
					;
					
selection_statement: IF_KEYWORD '(' expression N')' M statement N {
							$$ = new expression;
							quadlist.backpatch($4->nextlist, quadlist.nextinstr);

							quadlist.conv2Bool($3);
				
							quadlist.backpatch($3->truelist, $6->instr);

							$$->nextlist = merge($8->nextlist, $7->nextlist);
							$$->nextlist = merge($$->nextlist, $3->falselist);
						}
					| IF_KEYWORD '(' expression N')' M statement N ELSE_KEYWORD M statement	N{
							$$ = new expression;
							quadlist.backpatch($4->nextlist , quadlist.nextinstr);

							quadlist.conv2Bool($3);

							$$->nextlist = merge($7->nextlist, $8->nextlist);
							quadlist.backpatch($3->truelist, $6->instr);
							quadlist.backpatch($3->falselist, $10->instr);
							$$->nextlist = merge($$->nextlist, $12->nextlist);
							$$->nextlist = merge($$->nextlist, $11->nextlist);
						}
					| SWITCH_KEYWORD '(' expression ')' statement { }
					;
					
iteration_statement: WHILE_KEYWORD M '(' expression N ')' M statement	{
							quadlist.emit(GOTOOP,"","","");
							quadlist.backpatch(makelist(quadlist.nextinstr-1),$2->instr);    

							quadlist.backpatch($5->nextlist,quadlist.nextinstr);
							quadlist.conv2Bool($4);

							$$ = new expression;
							quadlist.backpatch($8->nextlist, $2->instr);
							quadlist.backpatch($4->truelist, $7->instr);
							$$->nextlist = $4->falselist;
						}
					| DO_KEYWORD M statement M WHILE_KEYWORD '(' expression ')' ';'	 {
							$$ = new expression;
							quadlist.conv2Bool($7);
							quadlist.backpatch($3->nextlist, $4->instr);
							quadlist.backpatch($7->truelist, $2->instr);
							$$->nextlist = $7->falselist;
						}
					| FOR_KEYWORD '(' expression_opt ';' M expression_opt N ';' M expression_opt N ')' M statement	{
							$$ = new expression;
		
							quadlist.emit(GOTOOP,"","","");
							quadlist.backpatch(makelist(quadlist.nextinstr-1),$9->instr);    
							quadlist.backpatch($7->nextlist, quadlist.nextinstr);
							quadlist.conv2Bool($6);

							quadlist.backpatch($11->nextlist,$5->instr);
							quadlist.backpatch($6->truelist,$13->instr);
							quadlist.backpatch($14->nextlist,$9->instr);
		
							$$->nextlist = $6->falselist;
						}
					| FOR_KEYWORD '(' declaration expression_opt ';' expression_opt ')' statement	{ }
					;
					
expression_opt:expression	
				{}
				|{}
				;
				
jump_statement: GOTO_KEYWORD IDENTIFIER ';' {}
				| CONTINUE_KEYWORD ';' { }
				| BREAK_KEYWORD ';' {}
				| RETURN_KEYWORD ';'	{
						$$ = new expression;

						if(currST->lookup("retVal")->type.type_specifier=="void"){
							quadlist.emit(RETURN_VOID,"","","");
						}
			   		}
				| RETURN_KEYWORD expression ';'	 {
						$$ = new expression;
						typeOf type1, type2, type3;
						type1 = currST->lookup("retVal")->type;
						type2 = currST->lookup($2->location)->type;
						for(int i=0; i<St->count;i++) {
							if(St->ST[i].name==$2->location)
								type3 = St->ST[i].type;
						}
						if(type3.type_specifier=="function"){	
							string t = currST->gentemp(type1);
							quadlist.emit(CPY, t, $2->location, "");
							quadlist.emit(RETURN,t,"","");
						}
						else if(type1.type_specifier == type2.type_specifier)
								quadlist.emit(RETURN, $2->location, "", "");
				}
				;
				


// External Definitions
translation_unit: external_declaration {}
				| translation_unit external_declaration	  { }
				;
				

external_declaration: function_definition {}
					| declaration {}
					;
					

function_definition: declaration_specifiers declarator declaration_list compound_statement	{ }
					| declaration_specifiers declarator compound_statement {
						declaration *new_dec = $2;
							int size = 0;
							typeOf *type = $1;
							if(type->type_specifier=="int") size = 4;
							if(type->type_specifier=="double") size = 8;
							if(type->type_specifier=="char") size = 1;
							if(type->type_specifier=="void") size = 0;

							SymbolTable *gt = &globalST;
							quadlist.emit(_FUNC_END,new_dec->decl,"","");
							STelement *func = gt->lookup($2->decl);

							if(func->nextVar) {
								if($2->PC>0)
									type->ptrType = "ptr";
								STelement *ret = func->nextVar->lookup("retVal", type->type_specifier, $2->PC);
							
								if($2->PC>0) {
									ret->PC = $2->PC;
									ret->type.ptrType = "ptr";
								}
								ret->offset = currST->offset;
								ret->size = size;
								ret->initVal = NULL;
							}
							currST = gt;
							$$ = $2;
					}
					
    ;
declaration_list:declaration {}
				|declaration_list declaration {}
				;
				
%%
void yyerror(string s) 
{
	cout << s << endl;
}
