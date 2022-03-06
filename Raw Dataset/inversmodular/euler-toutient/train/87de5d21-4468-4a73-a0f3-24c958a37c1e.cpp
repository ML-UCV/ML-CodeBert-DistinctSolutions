#include <bits/stdc++.h>


using namespace std;



ifstream f("inversmodular.in");

ofstream g("inversmodular.out");

long long int n,P;

long long int InversModular(long long int x,long long int k)

{

    long long int rez=1;

    while(k)

    {

        if(k&1)

            rez=(rez*x)%P;

        x=(x*x)%P;

        k>>=1;

    }

    return rez;

}

int main()

{

    f>>n>>P;

    long long int copie=P,phi=P,d=2;

    while(copie>1)

    {

        if(!(copie%d))

        {

            phi*=(d-1),phi/=d;

            while(!(copie%d))

                copie/=d;

        }

        d++;

        if(d*d>copie&&copie>1)

            d=copie;

    }

    g<<InversModular(n,phi-1);





    return 0;

}
