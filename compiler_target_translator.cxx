#include "compiler_translator.h"

extern Quad quadlist;
extern SymbolTable globalST;
extern SymbolTable *St,*currST;
extern typeOf *g;
extern int w;
extern vector<string> literals;
extern int yyparse();

//
// author - Kaustubh Hiware, 14CS30011
//

void printLiner(int lim){
    for(int k=0;k<lim;k++) cout<<"-";
    cout<<"\n";
}

void printHeadr(int lim){
    for(int k=0;k<lim;k++) cout<<"=";
    cout<<"\n";
}

string Translator::genGOTO(){
    string t = ".L"+to_string(gotoCount);
    gotoCount++;
    return t;
}

void Translator::genFuncPrologue(){

    stackR = 16*((stackSize/16)+1); 

    cout<<".globl "<<funcName<<"\n"<<" .type "<<funcName<<", @function\n";	
    cout<<funcName<<":\n";
    //cout<<".cfi_startproc\n";
    cout<<"pushq %rbp\n";
    cout<<"movq %rsp, %rbp\n";
    cout<<"subq $"<<stackR<<", %rsp\n";	
}


void Translator::genFuncEpilogue(){
    cout << " " << "ret"<<endl;
   // cout<<".cfi_endproc\n";
}

void Translator::getGlobal(){

    STelement *p;
    int i;
    for(i = 0 ; i < (&globalST)->count; i++){

        STelement elem = (&globalST)->ST[i];
        if(elem.name[0] != 't'){
            string typer = elem.type.type_specifier;

            if(elem.initVal==NULL){
                if(typer=="char"){      cout<<"comm "<<elem.name<<",1,1\n";}
                else if(typer=="int"){  cout<<"comm "<<elem.name<<",4,4\n";}
            }
            else{
                cout << " .globl "<<elem.name<<"\n";
                cout << " .data"<<endl;
                cout << " .type "<<elem.name<<", @object"<<"\n";

                if(typer=="char"){      cout << " .size "<<elem.name<<", 1"<<"\n";}
                else if(typer=="int"){  cout << " .size "<<elem.name<<", 4"<<"\n";}

                cout << elem.name<< ":" << "\n";
                if(typer=="char"){      cout << " .byte "<<elem.initVal->int_val<<"\n";}
                else if(typer=="int"){  cout << " .long "<<elem.initVal->int_val<<"\n";}
            }
        } 
    }
}


void Translator::convert2Asm()
{
    int arg1b=0, arg2b=0, resb=0,i;

    STelement *arg1G, *arg2G, *resG;    
    arg1G = NULL;arg2G = NULL;resG = NULL;

    STelement* arg1x = currST->lookup(Qcurrent.arg1);
    STelement* arg2x = currST->lookup(Qcurrent.arg2);
    STelement* resx = currST->lookup(Qcurrent.res);
    
   int lim = (&globalST)->count;
    for(i = 0;i < lim;i++){
        string naam = (&globalST)->ST[i].name;

        if(naam == Qcurrent.arg1){      arg1G = &((&globalST)->ST[i]);} 
        else if(naam == Qcurrent.arg2){ arg2G = &((&globalST)->ST[i]);}
        else if(naam == Qcurrent.res){  resG = &((&globalST)->ST[i]);}

    }
    string arg1Gen = null,arg2Gen = null,resGen = null;

    if(Qcurrent.res[0] <= '0' || Qcurrent.res[0] >= '9'){

        if(resG == NULL){
            resb = resx->offset;
            resGen = to_string(resb) + "(%rbp)";
        }
        else
            resGen = Qcurrent.res;
    }
    
    if(Qcurrent.arg1[0] <= '0' || Qcurrent.arg1[0] >= '9'){
        
        if(arg1G == NULL){
            arg1b = arg1x->offset;
            arg1Gen = to_string(arg1b) + "(%rbp)";
        }
        else {
            if(arg1G->type.type_specifier == "function")
                typeFunct = 1;     
            else
                arg1Gen = Qcurrent.arg1;
        }

    }            

    if(Qcurrent.arg2[0] <= '0' || Qcurrent.arg2[0] >= '9'){

        if(arg2G == NULL){
            arg2b = arg2x->offset;
            arg2Gen = to_string(arg2b) + "(%rbp)";
        }
        else
            arg2Gen = Qcurrent.arg2; 
    }
    
    // handle operations now
    switch(Qcurrent.op){
        case UNARY_SUB: {
                            cout << " " << "movq" << " " <<arg1Gen<< ", %rax" << endl; 
                            cout << " " << "negq  %rax"<< endl;
                            cout << " " << "movq" << " " << "%rax, " << resGen << " "  << endl; 
                            break;
                        }

        case CPY:       {
                            if(typeFunct==1){
                                cout<<"movl %eax, "<<resGen<<endl;
                                typeFunct = 0;
                            }
                            else if(Qcurrent.arg1[0]>='0' && Qcurrent.arg1[0]<='9'){

                                    cout<<"movl $"<<Qcurrent.arg1<<", "<<resGen<<"\n";
                            }
                            else{
                                cout<<"movl "<<arg1Gen<<", %eax\n"; 
                                cout<<"movl "<<"%eax, "<<resGen<<"\n"; 
                            }
                            break;                            
                        }
        
        case ADD:        {
                            
                            cout<<"movl " <<arg1Gen<<", %edx\n";
                            if(Qcurrent.arg2[0]>='0' && Qcurrent.arg2[0]<='9')
                                cout<<"movl $" <<Qcurrent.arg2<<", %eax\n";
                            else
                                cout << " movl " <<arg2Gen << ", %eax\n";
                            cout<<"addl  %edx, %eax\n";
                            cout<<"movl  %eax, "<<resGen<<"\n";     
                            break;
                        }

        case SUB:       {
                            cout<< " movl " <<arg1Gen<< ", %edx\n";
                            cout<< " movl " <<arg2Gen << ", %eax\n";
                            cout<< " subl %eax, %edx\n";
                            cout<< " movl %edx, %eax\n";
                            cout<< " movl  %eax, " << resGen<<"\n";       
                            break;
                        }
        
        case MUL:       {
                            cout<< " movl " <<arg1Gen << ", %eax\n";
                            if(Qcurrent.arg2[0]>='0' && Qcurrent.arg2[0]<='9')
                                cout<< " imull $" << Qcurrent.arg2 << ",%eax\n";
                            else
                                cout<< " imull " <<arg2Gen << ",%eax\n";
                            cout<< " movl %eax, "<< resGen<< "\n";           
                            break;
                        }

        case DIV:       {
                            cout << " movl " <<arg1Gen << ", %eax\n";
                            cout << " cltd\n";
                            cout << " idivl "<< arg2Gen << "\n";
                            cout << " movl %eax, " << resGen<< "\n";       
                            break;
                        }

        case MOD:       {
                            cout << " movl " <<arg1Gen << ", %eax\n";
                            cout << " cltd\n";
                            cout << " idivl "<< arg2Gen << "\n";
                            cout << " movl %edx, "  << resGen << "\n";          
                            break;
                        }    
    
        case IF_LT:     {
                            cout << " movl " <<arg1Gen << ", %eax\n";
                            cout << " cmpl " <<arg2Gen << ", %eax\n";
                            cout << " jge .L" << gotoCount <<"\n";
                            cout << " jmp " <<Qcurrent.res <<"\n";
                            cout << ".L" << gotoCount++  << ":\n";
                            break;
                        }

        case IF_GT:     {
                            //  if a > b goto .L1
                            cout<< " movl " <<arg1Gen << ", %eax\n";
                            cout<< " cmpl " <<arg2Gen << ", %eax\n";
                            //jump on less
                            cout<< " jle .L" << gotoCount << "\n";
                            cout<< " jmp " <<Qcurrent.res << "\n";
                            cout<< ".L"<< gotoCount++  << ":\n";
                            break;
                        }

        case IF_EQ:     {     
                            cout << " movl " <<arg1Gen << ", %eax\n";
                            cout << " cmpl " <<arg2Gen << ", %eax\n";
                            cout << " jne .L" << gotoCount << "\n";
                            cout << " jmp " <<Qcurrent.res << "\n";
                            cout << ".L" << gotoCount++  << ":\n";
                            break;
                        }

        case IF_NEQ:    {
                            cout << " movl " <<arg1Gen << ", %eax\n";
                            cout << " cmpl " <<arg2Gen << ", %eax\n";
                            cout << " je .L" << gotoCount << "\n";
                            cout << " jmp " <<Qcurrent.res << "\n";
                            cout << ".L" << gotoCount++  << ":\n";
                            break;
                        }
        
        case NOTCONDN:  {
                            cout<< " cmpl $0, "<<arg1Gen<< "\n"; 
                            cout<< " jne .L"<< gotoCount<<"\n"; 
                            cout<< " jmp "<<Qcurrent.res<<endl;
                            cout<< ".L"<<gotoCount++<<" : \n";  
                            break;
                        }

        case CONDN:     {  
                            cout<< " cmpl $0, "<<arg1Gen<< endl; 
                            cout<< " je .L"<< gotoCount<<endl; 
                            cout<< " jmp "<<Qcurrent.res<<endl;
                            cout<< ".L" <<gotoCount++<<" : \n" ;  
                            break;
                        }
   
        case GOTOOP:
                        {
                            cout<<"jmp " <<Qcurrent.res<<"\n";
                            break;
                        }


        case PARAM:     {
                            if(Qnext.res=="printi"|| Qnext.res=="prints" || Qnext.res=="readi"){

                                if(Qcurrent.res[0]=='.'){
                                    cout<<"movq $"<<Qcurrent.res<<", %rdi\n";
                                }
                                else if(Qcurrent.res[0]>='0' && Qcurrent.res[0]<='9')
                                        cout<<"movq $"<<Qcurrent.res<<", %rdi\n";
                                    else
                                        cout<<"movq "<<resGen<<", %rdi\n";
                                    numParam++;
                            }
                            else
                            {
                                string s;
                                std::vector<string> strr;
                                int flag = 0;

                                if(Qcurrent.res[0]>='0' && Qcurrent.res[0]<='9')
                                    s = s + " movq $" + Qcurrent.res + ", %rax\n";
                                else{

                                    for(int i=0;i<nextST->count;i++){
                                        
                                        if(Qcurrent.res==nextST->ST[i].name && nextST->ST[i].type.arrType=="array"){
                                            if(resb>0)  {s = s + " movq " + resGen + ", %rax\n";flag = 1;}
                                            else        {s = s + " leaq " + resGen + ", %rax\n";flag = 1;}
                                        }
                                    }
                                    if(flag == 0)
                                        s = s + " movq " + resGen + ", %rax\n";
                                    strr.push_back(s);
                                    strr.push_back(" pushq %rax\n");
                                    paraStack.push(strr);
                                }
                            }
                            break;
                        }

        case CALL:      {
                            if(Qcurrent.res=="printi"|| Qcurrent.res=="prints"|| Qcurrent.res=="readi"){

                                int n = atoi((Qcurrent.arg1).c_str())*4;
                                cout << " " << "call "<<Qcurrent.res << endl;
                                if(Qcurrent.arg2 != "")
                                    cout << " " << "movq %rax, "<<arg2Gen<< endl;
                            }
                            else{
                                int n= atoi((Qcurrent.arg1).c_str())*8;
                                while(paraStack.size()){

                                    vector<string> str; 
                                    str = paraStack.top();
                                    for(int i = 0; i<str.size(); i++){
                                        cout<<str[i];
                                    }
                                    paraStack.pop(); 
                                }
                                cout << " call "<<Qcurrent.res << "\n";
                                cout << " addq $"<<n<<", %rsp"<< "\n";
                                cout<<"#--"<<Qcurrent.arg2<<"\n";
                            }
                            break;
                        }

        case RETURN:    {
                            if(Qcurrent.res!=null)
                                cout<<"movq "<<resGen<< ", %rax"<< endl;
                            cout <<" leave\n ret\n";
                            numParam = 0;            
                            break;
                        }

        case RTPTR:     {
                            cout<<"movq "<<arg1Gen<<", %rax\n";
                            cout<<"movl (%rax),  %ecx\n";
                            cout<<"movl %ecx, "<<resGen<<"\n";
                            break;
                        }

        case ADDRESS:   {
                            cout<<"leaq "<<arg1Gen<<", %rax\n";
                            cout<<"movq %rax, "<<resGen<<"\n";
                            break;
                        }

        case RIGHTINDEX:{
                            cout<<"movslq "<<arg2Gen<<", %rdx"<< endl;
                            if(arg1b>0){
                                cout<<"movq "<<arg1b<<"(%rbp), %rdi\n";
                                cout<<"addq %rdi, %rdx\n";
                                cout<<"movl (%rdx), %eax\n";  
                            }
                            else
                                cout<<"movl "<<arg1b<<"(%rbp,%rdx,1), %eax\n";
                            
                            cout<<"movl %eax, "<<resGen<<"\n";
                            break;
                        }

        case LEFTINDEX: {
                            cout<<"movslq "<<arg2Gen<<", %rdx\n";
                            if(resb>0) {
                                cout<<"movl "<<arg1Gen<<", %eax\n";
                                cout<<"movq "<<resb<<"(%rbp), %rdi\n";
                                cout<<"addq %rdi, %rdx\n";
                                cout<<"movl %eax, (%rdx)\n";
                            }
                            else{
                                cout<<"movslq "<<arg1Gen<<", %rax\n";
                                cout<<"movq %rax, "<<resb<<"(%rbp,%rdx,1)\n";
                            }
                            break;
                        }
    }//switch
}//function


void Translator::setStr(){

    int countStr = 0;
    cout<<".section .rodata\n";
    for(vector<string>::iterator it = literals.begin(); it != literals.end(); it++){
        cout<<str0<<countStr++<<":\n";
        cout<<".string "<<*it<<"\n";
    }
}

void Translator::setGoto(){
    vector<Qelement>::iterator it;
    for(it = quadlist.arr.begin(); it != quadlist.arr.end(); it++){

        if(it->op >= IF_LT && it->op <= GOTOOP){

            int res_bp = atoi(((*it).res).c_str());
            if(genGoto.count(res_bp)==0){
                string label = genGOTO();
                genGoto[res_bp] = label;
            }
            (*it).res = genGoto[res_bp];
        }
    }
}



void Translator::setMem(){
    setStr();
    getGlobal();
    setGoto();

    int qsize = quadlist.arr.size(),i,j;
    for(i = 0;i < qsize;i++){

       cout<<" # "; quadlist.arr[i].print();
        
        if(genGoto.count(i)>0)
            cout<<genGoto[i]<<":\n";

        Qcurrent = quadlist.arr[i];
       if(i<qsize-1)
            Qnext = quadlist.arr[i+1];	
        if(quadlist.arr[i].op == _FUNC_START){
            if(quadlist.arr[i+1].op != _FUNC_END){
                  
                ptrType=0;
                STelement *p=NULL;
                for(j = 0;j < (&globalST)->count; j++){

                    if(((&globalST)->ST[j].name)==quadlist.arr[i].res)
                        p = &((&globalST)->ST[j]);
                }
                funcName = quadlist.arr[i].res;
                row = p;
                nextST = p->nextVar;
                currST = nextST;
                flag = 1;
                int COUNT; 
                COUNT = row->type.numParam;

                for(j = 0;j < COUNT;j++){
                    nextST->ST[j].offset = memory;
                    memory += 8;
                }
                ebpMem = 0;
                for(j = COUNT;j < nextST->count;j++){
                    if(nextST->ST[j].name!="retVal"){

                        ebpMem = ebpMem - nextST->ST[j].size;
                        nextST->ST[j].offset = ebpMem;
                    }
                }
                cout<<"#"<<ebpMem<<"\n";
                stackSize = memory - ebpMem;
        		for(j = 0;j< nextST->count;j++)
                {
        			if(nextST->ST[j].name==Qcurrent.res||nextST->ST[j].name!=Qcurrent.arg1||nextST->ST[j].name!=Qcurrent.arg2)
        			{
        				if(nextST->ST[j].type.ptrType=="ptr")
        					ptrType = 1;
        			}
        		}
                genFuncPrologue();
            }
            else{
                    i++;
            		numParam = 0;ebpMem = 0;
            		memory = 16;
                    continue;
            }
        }
        else if(quadlist.arr[i].op == _FUNC_END){
            St = &globalST;
            currST = &globalST;
	    cout<<"leave\n ret\n";
        cout << " .size "<<funcName<<", .-"<<funcName<<endl;
	    funcName = "";ebpMem = 0;
        numParam = 0;
	    memory = 16;
	    continue;
        }

        if(funcName!=null){     convert2Asm();}
    }
}


int main(int argc, char *argv[])
{   
    bool parseStatus = yyparse();
    int asize = quadlist.arr.size();
    
    string out = "a.out";
    if(argc==2) out = string(argv[1]);
    string quad_file = "tests/quads_" + out + ".out";
    ofstream outf1(quad_file.c_str());
    streambuf *coutbuf1 = cout.rdbuf();
    cout.rdbuf(outf1.rdbuf());
    
    printLiner(80);
    cout << "Quads" <<endl;
    for(int i = 0; i<asize;i++){
        cout<<i<<" : "; 
        quadlist.arr[i].print();
    }

    printHeadr(80);
    cout<<"\tSymbol Table (ST.gbl)\n";
    SymbolTable *g = &globalST;
    g->print();
    printLiner(80);

    for(int i = 0; i< g->count; i++){
        if(g->ST[i].nextVar){
            printHeadr(80);
            cout<<"\tSymbol Table \t"<<g->ST[i].name<<endl;
            g->ST[i].nextVar->print();
            printLiner(80);
        }
    }
    printLiner(80);
    if(!parseStatus) {cout<<"Compiled successfully\n";}
    else            {cout<<"Compile failure\n";}
    printLiner(80);
    cout.rdbuf(coutbuf1);

    string tmp = "tests/" + out + ".s";
    ofstream outfile(tmp.c_str());
    streambuf *coutbuf = cout.rdbuf();
    cout.rdbuf(outfile.rdbuf());
    
     //cout<<argv[3]<<endl;
    //freopen(argv[3],"w",stdout);
    currST = St;
    Translator c;
    c.setMem();
    
    cout.rdbuf(coutbuf);
    return 0;

}