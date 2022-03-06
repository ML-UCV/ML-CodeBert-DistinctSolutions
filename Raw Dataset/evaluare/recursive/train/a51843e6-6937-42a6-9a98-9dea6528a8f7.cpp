#include <iostream>
#include <fstream>



using namespace std;

ifstream f("evaluare.in");
ofstream g("evaluare.out");

int n,ind;
char s[100000 +1];

int eval();
int inm_sau_imp();
int termen();

int eval(){
    int rez=inm_sau_imp();
    while(s[ind]=='+'||s[ind]=='-'){
        if(s[ind]=='+'){
            ind++;
            rez=rez+inm_sau_imp();
        }else{
            ind++;
            rez=rez-inm_sau_imp();
        }
    }
    return rez;
}

int inm_sau_imp(){
    int rez=termen();
    while(s[ind]=='*'||s[ind]=='/'){
        if(s[ind]=='*'){
            ind++;
            rez=rez*termen();
        }else{
            ind++;
            rez=rez/termen();
        }
    }
    return rez;
}

int termen(){
    int rez=0;
    if(s[ind]=='('){
        ind++;
        rez=eval();
        ind++;
    }else{
        while(s[ind]<='9'&&s[ind]>='0'){
            rez=rez*10+s[ind]-'0';
            ind++;
        }
    }
    return rez;
}

int main(){
    f>>s;
    g<<eval();
    f.close();
    g.close();
}
