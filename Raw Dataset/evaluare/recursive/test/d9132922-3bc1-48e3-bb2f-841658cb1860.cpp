#include <iostream> 
#include <fstream>
#include <vector>
#include <cstring>

using namespace std;

ifstream in("evaluare.in");
ofstream out("evaluare.out");

const long MAX = 100010;
char S[MAX], *p=S;

long termen();
long factor();

long eval(){
    long rez = termen();
    while( *p == '+' || *p == '-'){
        switch( *p ){
            case '+':
                ++p;
                rez += termen();
                break;
            case '-':
                ++p;
                rez -= termen();
                break;
        }
    }
    return rez;
}

long factor(){
    long rez = 0;
    if( *p == '('){
        ++p;
        rez = eval();
        ++p;
    }else{
        while(isdigit(*p)){
            rez = rez * 10 + *p - '0';
            ++p;
        }
    }
    return rez;
}

long termen(){
    long rez = factor();
    while( *p == '*' || *p == '/'){
        switch( *p ){
            case '*':
                ++p;
                rez *= factor();
                break;
            case '/':
                ++p;
                rez /= factor();
                break;
        }
    }
    return rez;
}


int main(){
    in >> S;
    out << eval();
    return 0;
}
