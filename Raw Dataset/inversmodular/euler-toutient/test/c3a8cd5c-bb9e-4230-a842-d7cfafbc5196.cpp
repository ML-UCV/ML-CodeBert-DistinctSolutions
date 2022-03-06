#include <bits/stdc++.h>


using namespace std;

ifstream f("inversmodular.in");

ofstream g("inversmodular.out");

long long po(long long nr,long long g){

 long long t=1;

 for(long long i=1;i<=g;i++){

   t*=nr;

 }

 return t;

}

long long phi(long long nr){

long long phi=nr;

for(long long i=2;i*i<=nr;i++){

    if(nr%i==0){

        while(nr%i==0)nr/=i;

        phi=phi/i*(i-1);

    }

}

if(nr!=1)phi=phi/nr*(nr-1);

return phi;

}

int main()

{long long n,m;

 long long phinr,s=1;

 f>>n>>m;

 phinr=phi(m)-1;

 while(phinr){

    if(phinr&1)s=(s*n)%m;

    n=(n*n)%m;

    phinr>>=1;

 }

 g<<s;

}
