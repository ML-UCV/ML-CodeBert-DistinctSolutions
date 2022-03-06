#include <bits/stdc++.h>


using namespace std;



const int m1=100007;

const int m2=100021;

const int p=101;



string A;

string B;



int nA;

int nB;



int hash1,hash2,h1,h2;



int rasp;



int p1=1,p2=1;



bool nuVerifica=false;



int v[2000001];





ifstream f("strmatch.in");

ofstream g("strmatch.out");



int main()

{

     f>>A>>B;

    nA=A.length();

    nB=B.length();



    for(int i=0;i<nA;i++)

    {

        hash1=(hash1*p+ A[i])%m1;

        hash2=(hash2*p+ A[i])%m2;

        if(i!=0)

        {

            p1=p1*p%m1;

            p2=p2*p%m2;

        }

    }

    if(nA>nB)

    {

        g<<"0"<<"\n";

        return 0;

    }



    for(int i=0;i<nA;i++)

    {

        h1 = (h1 * p + B[i]) %m1;

        h2 = (h2 * p + B[i]) %m2;

    }

    if(hash1==h1 && hash2==h2)

    {

        rasp++;

        v[0]=1;

    }



    for(int i=nA;i<nB;i++)

    {

        h1 = ((h1 - (B[i - nA] * p1) % m1 + m1) * p + B[i]) % m1;

        h2 = ((h2 - (B[i - nA] * p2) % m2 + m2) * p + B[i]) % m2;



        if(hash1==h1 && hash2==h2)

        {

            rasp++;

            v[i- nA+ 1] =1;

        }

    }



    g<<rasp<<"\n";



    rasp = 0;

    for(int i=0;i< nB && rasp < 1000 ; i++)

    {

        if(v[i])

        {

          g<<i<<" ";

          rasp++;

        }

    }



    return 0;

}
