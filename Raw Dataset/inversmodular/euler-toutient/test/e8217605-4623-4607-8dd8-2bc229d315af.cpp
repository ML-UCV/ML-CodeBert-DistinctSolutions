#include <bits/stdc++.h>


using namespace std;



ifstream in("inversmodular.in");

ofstream out("inversmodular.out");



int a,n;



int logpow2(int a,int p)

{

    int rez=1,inm=a;



    while(p)

    {

        if(p%2)

            rez*=inm;



        p/=2;

        inm=inm*inm;

    }



    return rez;

}



int coprime(int nr)

{

    int fact[101],nrFact[101],t=0;

    int sum=1;



    int radNr=sqrt(nr);

    for(int d=2;d<=radNr && nr!=1;d++)

        if(nr%d==0)

        {

            fact[++t]=d;

            nrFact[t]=0;



            while(nr%d==0)

            {

                nrFact[t]++;

                nr/=d;

            }

        }



    if(nr!=1)

    {

        fact[++t]=nr;

        nrFact[t]=1;

    }



    for(int i=1;i<=t;i++)

        sum*=logpow2(fact[i],nrFact[i]-1)*(fact[i]-1);



    return sum;

}



int logpow(int a,int p)

{

    long long rez=1;

    long long inm=a;



    while(p)

    {

        if(p%2)

            rez=(rez*inm)%n;



        p/=2;

        inm=(inm*inm)%n;

    }



    return rez;

}



int main()

{

    in>>a>>n;



    int p=coprime(n);

    int rez=logpow(a,p-1);



    out<<rez;



    return 0;

}
