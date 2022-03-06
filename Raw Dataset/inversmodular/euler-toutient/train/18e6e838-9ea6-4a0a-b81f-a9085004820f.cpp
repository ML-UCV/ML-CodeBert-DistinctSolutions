#include <fstream>


using namespace std;

ifstream fin("inversmodular.in");

ofstream fout("inversmodular.out");

long long lg_put(long long base, long long exp, long long mod)

{

   long long p =1;

   while(exp>0)

   {

       if(exp&1)

           p = (p*(base%mod))%mod;

      base = ((base%mod) * (base%mod))%mod;

      exp = exp >>1;

   }

   return p;

}
long long phi(long long n)

{

   long long phi = n, d =2, e;

   while(d*d<=n and d >1)

   {

       e =0;

       while(n%d==0)

       {

          n = n/d;

          e++;

       }

       if(e>0)

           phi = phi/d*(d-1);

       d++;

   }

   if(n>1)

    phi = phi/n*(n-1);

  return phi;

}

int main()

{

    long long n, m;

    fin>>n>>m;

    fout<<lg_put(n, phi(m)-1, m)<<"\n";

    return 0;

}
