#include <fstream>


using namespace std;

ifstream in("inversmodular.in");

ofstream out("inversmodular.out");

long long a,n;

long long putere(long long a,long long e)

{ long long p=1;

  while(e>0)

  { if(e%2==0)

       a*=a,a%=n,e/=2;

    else

       p*=a,p%=n,e--;

  }

  return p;

}

long long phi(long long x)

{ long long p=1;

  for(long long i=2;i*i<=x;i++)

  { if(x%i!=0)

       continue;

    long long e=0,k=1;

    while(x%i==0)

        x/=i,e++,k*=i;

    k/=i;

    p=(i-1)*k;

  }

  if(x!=1)

     p*=(x-1);

  return p;

}

int main()

{ in>>a>>n;

  out<<putere(a,phi(n)-1);

  in.close();

  out.close();

  return 0;

}
