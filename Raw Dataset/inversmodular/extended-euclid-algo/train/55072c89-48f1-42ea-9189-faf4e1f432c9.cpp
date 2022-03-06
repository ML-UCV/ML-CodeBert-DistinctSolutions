#include <bits/stdc++.h>


using namespace std;

ifstream in("inversmodular.in");

ofstream out("inversmodular.out");

long long plmplmplmpl(long long a, long long b, long long &x, long long &y){

    if(!b){

        x=1;

        y=0;

        return a;

    }

    long long t=plmplmplmpl(b, a%b, x, y);

    long long aux=x;

    x=y;

    y=aux-y*(a/b);

    return t;

}

int main(){

    long long a, n,x,y;

    in>>a>>n;

    plmplmplmpl(a, n, x, y);

    out<<(x+n)%n;

    return 0;

}
