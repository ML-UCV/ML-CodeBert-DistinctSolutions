#include <bits/stdc++.h>
using namespace std;

ifstream fi("strmatch.in");

ofstream fo("strmatch.out");

int val1,val2,rhash1,rhash2,lgt,lgp,putere1=1,putere2=1;

char A[2000000 +1],B[2000000 +1];

vector <int> V;



void Rabin_Karp(char T[], char P[])

{

    lgt=strlen(T);

    lgp=strlen(P);

    for(int i=1; i<=lgp-1; i++)

    {

        putere1*=75;

        putere2*=75;

        putere1%=100007;

        putere2%=100021;

    }

    for(int i=0; i<lgp; i++)

    {

        val1=(val1*75%100007 +(P[i]-'0'))%100007;

        val2=(val2*75%100021 +(P[i]-'0'))%100021;

    }

    for(int i=0; i<lgp; i++)

    {

        rhash1=(rhash1*75%100007 +(T[i]-'0'))%100007 ;

        rhash2=(rhash2*75%100021 +(T[i]-'0'))%100021 ;

    }

    if(rhash1==val1 && rhash2==val2)

        V.push_back(0);

    for(int i=lgp; i<lgt; i++)

    {

        rhash1=(((rhash1-putere1*(T[i-lgp]-'0'))%100007 +100007)*75 +(T[i]-'0'))%100007;

        rhash2=(((rhash2-putere2*(T[i-lgp]-'0'))%100021 +100021)*75 +(T[i]-'0'))%100021;

        if(rhash1==val1 && rhash2==val2)

            V.push_back(i-lgp+1);

    }

}



void afisare(void)

{

    int nr=V.size();

    fo<<nr<<"\n";

    for(int i=0; i<min(nr,1000); i++)

        fo<<V[i]<<" ";

}



int main()

{

    fi>>A;

    fi>>B;

    Rabin_Karp(B,A);

    afisare();

    fi.close();

    fo.close();

    return 0;

}
