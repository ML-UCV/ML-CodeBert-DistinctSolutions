#include <bits/stdc++.h>


using namespace std;

ifstream f("inversmodular.in");

ofstream g("inversmodular.out");

int n,a,x;

int putere(int b,int e)

{

    if(e==0)return 1;

    int r=putere(b,e/2);

    r=1LL*r*r%n;

    if(e%2==1)r=1LL*r*b%n;

    return r;

}

int euler(int m)

{

    int phi=1;

    if(m%2==0){m/=2;while(m%2==0){m/=2;phi*=2;}}

    for(int d=3;d*d<=m;d+=2)

        if(m%d==0){m/=d;phi*=d-1;while(m%d==0){m/=d;phi*=d;}}

    if(m>1)phi*=m-1;

    return phi;

}

int main()

{

    f>>a>>n;

    g<<putere(a,euler(n)-1);

    return 0;

}
