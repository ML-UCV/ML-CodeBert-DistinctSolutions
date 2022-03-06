#include<bits/stdc++.h>
using namespace std;

ifstream f("inversmodular.in");

ofstream g("inversmodular.out");

int a,n;

int phi(int nr)

{

    int ret=1;

    if(nr%2==0)

        ret/=2;

    while(nr%2==0)

    {

        nr/=2;

        ret*=2;

    }

    for(int d=3; d*d<=nr; d+=2)

        if(nr%d==0)

        {

            nr/=d;

            ret*=(d-1);

            while(nr%d==0)

            {

                nr/=d;

                ret*=d;

            }

        }

    if(nr>1)

        ret*=nr-1;

    return ret;

}

int putere(int b,int e)

{

    if(e==0)

        return 1;

    int r=putere(b,e/2);

    r=1LL*r*r%n;

    if(e%2)

        r=1ll*r*b%n;

    return r;

}

int main(void)

{

    f>>a>>n;

    g<<putere(a,phi(n)-1);



    return 0;

}
