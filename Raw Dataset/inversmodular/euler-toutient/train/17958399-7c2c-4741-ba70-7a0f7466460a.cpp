#include <bits/stdc++.h>
using namespace std;



long long n,a;



long long get_phi(long long n)

{

 int i=2;

 int phi=n;

 for (i=2;i<=sqrt(n);++i)

   {

    if (n%i==0)

    {

     while(n%i==0) n/=i;

  phi=(phi/i)*(i-1);

    }

   }

 if (n>1) phi=(phi/n)*(n-1);

 return phi;

}



long long power(long long baza, long long exp)

{

 long long aux=1;

 while(exp)

  {

   if (exp%2==0)

        {

         baza=(baza*baza)%n;

         exp/=2;

        }

   if (exp%2==1)

        {

         aux=(aux*baza)%n;

         --exp;

  }

  }

 return aux;

}



int main(void)

{

 ifstream cin("inversmodular.in");

 ofstream cout("inversmodular.out");

 cin>>a>>n;

 cout<<1LL*power(a%n,get_phi(n)-1);

 return 0;

}
