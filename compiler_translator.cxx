#include "compiler_translator.h"
//#include "y.tab.h"

//original declarations shifted to translator

/* formatting printers */
void printHead(int lim){
	for(int k=0;k<lim;k++) cout<<"=";
	cout<<"\n";
}


void printLine(int lim){
	for(int k=0;k<lim;k++) cout<<"-";
	cout<<"\n";
}

node *replicate(node *t){
	//return pointer to replica of given type
	if(t==NULL){
		return t;
	}

	node *ret ;
	ret->size = t->size;
	ret->type_specifier = t->type_specifier;

	ret->next = replicate(t->next);
	return ret;
}

//additional function for getting size
int getSize(string type){

	if(type=="int")	{			return 4;}
	else if(type=="double")	{	return 8;}
	else if(type=="char") {		return 1;}
	else {						return 0;}

}

//print any type
void node::print(){
	///print recursively if needed for arrays
	switch(type_specifier)
	{
		case voidType:		printf("void");break;
		case intType:		printf("int");break;
		case doubleType:	printf("double");break;
		case charType:		printf("char");break;
		case boolType:		printf("bool");	break;
		case arrayType:
			printf("array(%d, ", size);
			if(this->next !=NULL){	
				next->print();
			}
			printf(")");
			break;

		case pointerType:
			printf("ptr(");
			if(this->next !=NULL){
				this->next->print();
			}
			printf(")");
			break;

		case functionType:	printf("function");break;
		default:			printf("Invalid type found.Exitting...\n");exit(-1);
	}
}

node::node(type0f t, int s, node *n)
:type_specifier(t), size(s), next(n)
{}


STelement* SymbolTable::lookup(string s, string type, int pc){

	STelement *sp;
	for(sp = ST; sp < &ST[MAX]; sp++){

		if(!sp->name.empty() && !sp->name.compare(s)){
			return sp;
		}
		// insert a new one 
		if(sp->name.empty()){
			sp = new STelement;
			sp->name = s;
			typeOf t;
			
			t.type_specifier = type;
			int t_size = 0;
			if(pc == 0){
				t_size = getSize(type);
				t.size = t_size;sp->size = t.size;
				sp->type = t;
				sp->offset = offset;
				sp->initVal = NULL;
				offset += t_size;
				
				ST[count] = *sp;
			}
			else if(pc>0){
				sp->size = 8;
				sp->type.type_specifier = type;
				cout<<type<<"\n";

				sp->PC = pc;
				sp->offset = offset;
				sp->initVal = NULL;
				
				offset += 8;
				ST[count] = *sp;
			}
			count++;
			break;
			
		}
	}
	return sp;
}

STelement *SymbolTable::search(string naam){
	for(int i=0;i<MAX;i++){
		if(ST[i].name == naam)
			return &ST[i];
	}
	return NULL;// return NULL => not found
}

string SymbolTable::gentemp(typeOf type){

	static int temp = 0;
	string s = "t";
	s = s + to_string(temp);
	temp++;
	ST[count].name = s;
	ST[count].type = type;
	int t_size = getSize(type.type_specifier);

	if(type.ptrType.compare("ptr")==0)
		t_size = 8;
	
	ST[count].size = t_size;
	ST[count].initVal = NULL;
	ST[count].offset = offset;
	ST[count].nextVar = NULL;
	offset = offset + t_size;
	count++;
	return s;
}

void SymbolTable::print(){
	// just print the ST
	int i;
	printHead(80);
	cout<<"NAME\tVARTYPE\tSIZE\tOFFSET\tINITVAL\n";
	printLine(80);
	for(i=0;i<count;i++){

		int flag = 0;
		cout<<ST[i].name<<"\t";
		if(ST[i].PC == 0 && ST[i].type.arrType=="array"){

			string type = ST[i].type.type_specifier;
			if(type=="function")
				{cout<<"function\t";cout<<ST[i].type.numParam<<"\t";}
			else cout<<type<<"\t";
		}
		else if(ST[i].type.ptrType=="ptr"){
			ST[i].size = 8;
			for (int j = 0; j < ST[i].PC; ++j)
				cout<<"*";
			cout<<"\t";
		}
		else if(ST[i].type.arrType=="array"){
			cout<<ST[i].type.type_specifier;
			if(ST[i].type.idx!=0 && ST[i].type.type_specifier!="")
				{cout<<" ["<<ST[i].type.idx<<"]";flag = 1;}
			else
				for (int j = 0; j < ST[i].type.typeList.size(); ++j)
					cout<<"["<<ST[i].type.typeList[j]<<"]";
				
			cout<<"\t";
		}
		if(flag==1){
			cout<<"\t"<<ST[i].size*ST[i].type.idx<<"\t";
			ST[i].size = ST[i].size*ST[i].type.idx;
		}
		if(flag==0)
			cout<<"\t"<<ST[i].size<<"\t";
        if(i>=1)
		    ST[i].offset = ST[i-1].offset + ST[i-1].size;
		cout<<ST[i].offset<<"\t";

		if(ST[i].initVal == NULL)
			cout<<"NULL";
		else{
			string typer = ST[i].type.type_specifier;
			if(typer=="int")
				cout<<ST[i].initVal->int_val;
			else if(typer=="char")
				cout<<ST[i].initVal->char_val;
			else if(typer=="double")
				cout<<ST[i].initVal->double_val;
		}
		cout<<"\n";
	}
	printLine(80);

}

void Quad::emit(operatorType op, string res, string arg1, string arg2)
{
	Qelement new_quad;
	new_quad.op = op;
	new_quad.res = res;
	new_quad.arg1 = arg1;new_quad.arg2 = arg2;
	arr.push_back(new_quad);
	nextinstr++;
}

void Quad::emit(operatorType op, string res, int num)
{
	Qelement new_quad;
	new_quad.op = op;
	new_quad.res = res;
	string s = to_string(num);
	new_quad.arg1 = s;
	arr.push_back(new_quad);
	nextinstr++;
}

void Quad::emit(operatorType op, string res, double d)
{
	Qelement new_quad;
	new_quad.op = op;
	new_quad.res = res;
	string s = to_string(d);
	new_quad.arg1 = s;
	arr.push_back(new_quad);
	nextinstr++;
}

void Quad::emit(operatorType op, string res, char c)
{
	Qelement new_quad;
	new_quad.op = op;
	new_quad.res = res;
	string s = "";
	s = s + c;
	new_quad.arg1 = s;
	arr.push_back(new_quad);
	nextinstr++;
}

// changing to cout for writing to file
void Qelement::print()
{

	if(res.compare("")==1)
		cout<<res<<" = "<<arg1;

	switch(op)
	{
		//arithmetic
		case ADD:			cout<<arg1<<"+"<<arg2<<endl; break;
		case SUB:			cout<<arg1<<"-"<<arg2<<endl; break;
		case MUL:			cout<<arg1<<"*"<<arg2<<endl; break;
		case DIV:			cout<<arg1<<"/"<<arg2<<endl; break;
		case MOD:			cout<<arg1<<"%"<<arg2<<endl; break;   

		//shift
		case SHIFTLEFT:		cout<<arg1<<"<<"<<arg2<<endl; break;
		case SHIFTRIGHT:	cout<<arg1<<">>"<<arg2<<endl; break;

		// relational
		case LT:			cout<<arg1<<"<"<<arg2<<endl; break;
		case LE:			cout<<arg1<<"<="<<arg2<<endl; break;
		case GT:			cout<<arg1<<">"<<arg2<<endl; break;
		case GE:			cout<<arg1<<">="<<arg2<<endl; break;
		case EQ:			cout<<arg1<<"=="<<arg2<<endl; break;
		case NEQ:			cout<<arg1<<"!="<<arg2<<endl;  break;

		//bit
		case BINARYAND:		cout<<arg1<<"&"<<arg2<<endl; break;
		case BINARYOR:		cout<<arg1<<"|"<<arg2<<endl; break;
		case BINARYXOR:		cout<<arg1<<"^"<<arg2<<endl; break;
		case BINARYNOT:		cout<<res<<" = "<<"~"<<arg1;break;

		//unary
		case LOGICAL_AND:	cout<<arg1<<"&&"<<arg2<<endl;  break;
		case LOGICAL_OR:	cout<<arg1<<"||"<<arg2<<endl; break;
		case UNARY_ADD:		cout<<res<<" = "<<"+"<<arg1;break;
		case UNARY_SUB:		cout<<res<<" = "<<"-"<<arg1;break;
		case CPY:			cout<<res<<" = "<<arg1<<"\n";break;		
		case CONDN:			cout<<"if "<<arg1<<" "<<"!= 0"<<arg2<<" goto "<<res<<"\n";break;
		case NOTCONDN:		cout<<"if "<<arg1<<" "<<"== 0"<<arg2<<" goto "<<res<<"\n";break;
		
		case NOT:			cout<<res<<" = "<<"!"<<arg1;break; 
		case IF_LT:			cout<<"if "<<arg1<<" "<<"<"<<arg2<<" goto "<<res<<"\n";break;
		case IF_GT:			cout<<"if "<<arg1<<" "<<">"<<arg2<<" goto "<<res<<"\n";break;
		case IF_LE:			cout<<"if "<<arg1<<" "<<"<="<<arg2<<" goto "<<res<<"\n";break;
		case IF_GE:			cout<<"if "<<arg1<<" "<<">="<<arg2<<" goto "<<res<<"\n";break;
		case IF_EQ:			cout<<"if "<<arg1<<" "<<"=="<<arg2<<" goto "<<res<<"\n";break;
		case IF_NEQ:		cout<<"if "<<arg1<<" "<<"!="<<arg2<<" goto "<<res<<"\n";break;

		//parameter
		case CALL:			cout<<"call "<<res<<" "<<arg1<<"\n";break;
		case PARAM:			cout<<"param "<<res<<"\n";break;
		case GOTOOP:		cout<<"goto "<<res<<endl;break;

		//return
		case RETURN:		cout<<"return "<<res<<"\n";break;
		case RETURN_VOID:	cout<<"return\n";break;

		//indexed copy
		case RIGHTINDEX:	cout<<res<<" = "<<arg1<<"["<<arg2<<"]\n";break;
		case LEFTINDEX:		cout<<res<<"["<<arg2<<"] = "<<arg1<<"\n";break;

		// address and pointer eqns	
		case ADDRESS:		cout<<res<<"= &"<<arg1<<"\n";break;	
		case RTPTR:			cout<<res<<"= *"<<arg1<<"\n";break;															
		case LTPTR:			cout<<"*"<<res<<"= "<<arg1<<"\n";break;	

		//others
		case CHAR2INT:		cout<<res<<" = "<<" Char2Int(" <<arg1<<")" <<endl;break; 
		case CHAR2DBL:		cout<<res<<" = "<<" Char2Double(" <<arg1<<")" <<endl; break;
		case INT2CHAR:		cout<<res<<" = "<<" Int2Char("<<arg1<<")"<<endl; break;
		case DBL2CHAR:		cout<<res<<" = "<<" Double2Char("<<arg1<<")"<<endl;break;
		case INT2DBL:		cout<<res<<" = "<<" Int2Double("<<arg1<<")"<<endl; break;
		case DBL2INT:		cout<<res<<" = "<<" Double2Int("<<arg1<<")"<<endl; break;
		case _FUNC_START:	cout<<"function "<<res<<" start\n";break;
		case _FUNC_END:	cout<<"function "<<res<<" end\n";break;

		default:			cout<<"Unexpected Instruction!";
	}
}


list<int> makelist(int nextinstr){
// A global function to create a new list containing only i, an index into the array
// of quad’s, and to return a pointer to the newly created list.	

    list<int> temp;
    temp.push_back(nextinstr);
    return temp;
}

list<int> merge(list<int> a, list<int> b){
	// A global function to concatenate two lists pointed
	// to by l1 and l2 and to return a pointer to the concatenated list.
    list<int> temp;
    temp.merge(a);
    temp.merge(b);
    return temp;
}

void Quad::backpatch(list<int> p, int i)
{
	string s = to_string(i);
	list<int>::iterator it;
	for(it = p.begin(); it != p.end(); it++){
		arr[*it].res = s; 
	}
}

void Quad::convDbl2Int(expression * e1, expression *e2)
{
	if(e2->type.type_specifier=="int"){
		e1 = e2;
		e1->type.type_specifier = "int";
		emit(DBL2INT, e1->location, e2->location, "");
	}
}

void Quad::convDbl2Char(expression * e1, expression *e2)
{
	if(e2->type.type_specifier=="char"){
		e1 = e2;
		e1->type.type_specifier = "char";
		emit(DBL2CHAR, e1->location, e2->location, "");
	}
}

void Quad::convInt2Dbl(expression * e1, expression *e2)
{
	if(e2->type.type_specifier=="double"){
		e1 = e2;
		e1->type.type_specifier = "double";
		emit(INT2DBL, e1->location, e2->location, "");
	}
}

void Quad::convInt2Char(expression * e1, expression *e2)
{
	if(e2->type.type_specifier=="char"){
		e1 = e2;
		e1->type.type_specifier = "char";
		emit(INT2CHAR, e1->location, e2->location, "");
	}
}

void Quad::convChar2Dbl(expression * e1, expression *e2)
{
	if(e2->type.type_specifier=="double"){
		e1 = e2;
		e1->type.type_specifier = "double";
		emit(CHAR2DBL, e1->location, e2->location, "");
	}
}

void Quad::convChar2Int(expression * e1, expression *e2)
{
	if(e2->type.type_specifier=="int")
		return;
	else
	{
		e1 = e2;
		e1->type.type_specifier = "int";
		emit(CHAR2INT, e1->location, e2->location, "");
	}
}


void Quad::conv2Bool(expression *exp)
{
	typeOf bool_type;
	bool_type.type_specifier = "bool";
	if(exp->type.type_specifier!="bool"){
		backpatch(exp->truelist, nextinstr);
		backpatch(exp->falselist,nextinstr);
		exp->falselist = makelist(nextinstr);
		emit(NOTCONDN,"",exp->location,"");
		exp->truelist = makelist(nextinstr);
		emit(GOTOOP,"","","");
	}
	exp->type.type_specifier = "bool";
}


void typecheck(expression *e1, expression *e2, bool isAssign){

	// check if E1.type = E2.type, if isAssign is true also changes it
	if(e1->type.type_specifier == e2->type.type_specifier || (e1->type.type_specifier == "pointer" && e2->type.type_specifier == "int"))
		return;
	Quad q;
	SymbolTable ST;
	typeOf temp;
	if(isAssign){
		temp.location = ST.gentemp(e1->type);
		// int and double
		if(e1->type.type_specifier == "int" && e2->type.type_specifier == "double"){
			q.emit(DBL2INT, e2->location, temp.idx);
		}
		// double and int
		else if(e1->type.type_specifier == "double" && e2->type.type_specifier == "int"){
			q.emit(INT2DBL, e2->location, temp.idx);
		}
		// int and char
		else if(e1->type.type_specifier == "char" && e2->type.type_specifier == "int"){
			q.emit(INT2CHAR, e2->location, temp.idx);
		}
		// char and int
		else if(e1->type.type_specifier == "int" && e2->type.type_specifier == "char"){
			q.emit(CHAR2INT, e2->location, temp.idx);
		}
		else{
			cout <<e1->location<<" "<<e2->location<<"Cannot convert this pair\n";
			exit(-1);
		}
		e2->location = temp.location;
		e2->type = temp;
	}
	else if(e1->type.type_specifier > e2->type.type_specifier){
			
		temp.location = ST.gentemp(e1->type);
		// char and int
		if(e1->type.type_specifier == "int" && e2->type.type_specifier == "char"){
			q.emit(CHAR2INT, e2->location, temp.idx);
		}
		//int and double
		else if(e1->type.type_specifier == "double" && e2->type.type_specifier == "int"){
			q.emit(INT2DBL, e2->location, temp.idx);
		}
		e2->location = temp.location;
		e2->type = temp;
	}
	else{
		temp.location = ST.gentemp(e2->type);
		// int and char
		if(e2->type.type_specifier == "int" && e1->type.type_specifier == "char"){
			q.emit(CHAR2INT, e1->location, temp.idx);
		}
		// int and double
		else if(e2->type.type_specifier == "double" && e1->type.type_specifier == "int"){
				q.emit(INT2DBL, e1->location, temp.idx);	
		}
		e1->location = temp.location;
		e1->type = temp;
	}
}

// commented to use from target_translator only
/*int main()
{
	yyparse();
	cout<<"\n+--- SymbolTables for the given program\n";
    SymbolTable *g = &globalST;
    g->print();
    for (int i = 0; i < globalST->table.size(); ++i){
		globalST->table[i]->nextVar->print();
	}

	cout<<"\n+--- Quads for the given program\n");
    int size = quadlist.arr.size();
    for(int i = 0; i<size;i++)
    {
        cout<<i<<": "; quadlist.arr[i].print();
    }

    return 0;

}*/