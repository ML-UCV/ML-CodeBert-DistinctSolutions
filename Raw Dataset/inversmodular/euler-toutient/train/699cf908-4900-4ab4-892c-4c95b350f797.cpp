#include <bits/stdc++.h>
long long N,A;

using namespace std;

ifstream fin("inversmodular.in");

ofstream fout("inversmodular.out");



long long Phi(long long n)

{

 long long c=n;

 for(long long i=2;i*i<=n;++i)

 {

  if (n%i==0)

  {

   while(n%i==0) n/=i;

   c=(c/i)*(i-1);

  }

 }

    if(n!=1) c=c/n*(n-1);

 return c;

}



int main()

{

 fin>>A>>N;

    long long p=Phi(N)-1;

 long long n=A;

 long long c=1;

    for(long long i=1;i<=p;i<<=1)

    {

   if(i&p)c=(c*n)%N;

    n=(n*n)%N;

 }

 fout<<c;

 return 0;

}
