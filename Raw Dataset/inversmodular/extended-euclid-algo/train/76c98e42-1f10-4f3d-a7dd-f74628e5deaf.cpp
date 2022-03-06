#include <bits/stdc++.h>
using namespace std;

ifstream fin("inversmodular.in");

ofstream fout("inversmodular.out");

int a,n,x,y,d;

int cmmdc(int a,int b,int &x,int &y) {

    if (b==0) {

        x=1, y=0;

        return a;

    }

    else {

        int x0,y0;

        int d=cmmdc(b,a%b,x0,y0);

        x=y0, y=x0-(a/b)*y0;

        return d;

    }

}

int main() {

    fin>>a>>n;

    d=cmmdc(a,n,x,y);

    if (x<0)

        x+=n*(x/n+1);

    fout<<x%n;

    return 0;

}
