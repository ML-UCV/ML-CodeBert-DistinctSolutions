#include <bits/stdc++.h>


using namespace std;

ifstream fin("inversmodular.in");

ofstream fout("inversmodular.out");

long long int n,a,x,y,d;

void cmmdc(long long int,long long int,long long int&,long long int&);

int main()

{

    fin>>a>>n;

    long long int x,y;

    cmmdc(a,n,x,y);

    x=x%n;

    if(x<0)x+=n;

    fout<<x;

    return 0;

}

void cmmdc(long long int a,long long int b,long long int &x,long long int &y)

{

    if(b==0){x=1;y=0;return;}

    long long int x0,y0;

    cmmdc(b,a%b,x0,y0);

    x=y0;

    y=x0-a/b*y0;

}
