#include <bits/stdc++.h>


using namespace std;



ifstream f("inversmodular.in");

ofstream g("inversmodular.out");



int a,n;

long long inv,ins;



void gcd(int u,int n)

{

  if(n==0) inv=1,ins=0;

  else

  {

    gcd(n,u%n);

    long long aux=inv;

    inv=ins;

    ins=aux-ins*(u/n);

  }

}



int main()

{



    f>>a>>n;

    inv=0;

    gcd(a,n);

    if(inv<=0) inv=n+inv%n;

    g<<inv;

    return 0;

}
