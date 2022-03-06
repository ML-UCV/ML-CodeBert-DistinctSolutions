#include <bits/stdc++.h>


using namespace std;

ifstream in("strmatch.in");

ofstream out("strmatch.out");

const int NMAX=2000004;

const int P=73;

const int mod1=100007;

const int mod2=100021;

char a[NMAX],b[NMAX];

long long amod1,bmod1,amod2,bmod2,powm1=1,powm2=1,cnt,rasp[NMAX],la,lb;

int main()

{

    in>>a>>b;

    la=strlen(a);

    lb=strlen(b);

        if(la>lb){

        out<<0;

        return 0;

    }

    for(int i=0;i<la;i++){

        bmod1=(bmod1*P+b[i])%mod1;

        bmod2=(bmod2*P+b[i])%mod2;

        amod1=(amod1*P+a[i])%mod1;

        amod2=(amod2*P+a[i])%mod2;

        if(i)

            powm1=(powm1*P)%mod1,

            powm2=(powm2*P)%mod2;



    }

   if(amod1==bmod1 && amod2==bmod2)

     rasp[cnt++]=0;

   for(int i=la;i<lb;i++){

   bmod1=((bmod1-(b[i-la]*powm1)%mod1+mod1)*P+b[i])%mod1;

   bmod2=((bmod2-(b[i-la]*powm2)%mod2+mod2)*P+b[i])%mod2;

    if(amod1==bmod1 && amod2==bmod2)

        rasp[cnt++]=i-la+1;

   }

   out<<cnt<<'\n';

   for(int i=0;i<cnt && i<1000;i++)

    out<<rasp[i]<<" ";

    return 0;

}
