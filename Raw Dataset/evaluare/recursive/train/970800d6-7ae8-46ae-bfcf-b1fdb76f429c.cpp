#include <bits/stdc++.h>
using namespace std;

ifstream fin ("evaluare.in");
ofstream fout("evaluare.out");

const int NMAX=100004;

char E[NMAX];
int I;

int factor(),eval(),produs();
int eval(){

    int sum=produs();
    for(;E[I]=='+' or E[I]=='-';){

        if(E[I]=='+')
            ++I,sum+=produs();
        else
            ++I,sum-=produs();
    }
    return sum;
}

int produs(){
    int prod=factor();
    for(;E[I]=='*' or E[I]=='/';)
    {
        if(E[I]=='*')
            ++I,prod*=factor();
        if(E[I]=='/')
            ++I,prod/=factor();
    }
    return prod;
}

int factor(){

    if(E[I]=='('){
        ++I;
        int r=eval();
        ++I;
        return r;
    }

    int nr=0;
    for(;E[I]<='9' and E[I]>='0';)
        nr=nr*10+E[I]-'0',++I;

    return nr;
}


int main(){
    fin>>E;
    fout<<eval();
}
