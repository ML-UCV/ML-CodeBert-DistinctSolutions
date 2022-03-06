#include<fstream>


using namespace std;

ifstream fi("inversmodular.in");

ofstream fo("inversmodular.out");

long long a,n,p;

long long phi_n(long long n)

{

long long sol=n,d;

for(d=2;d*d<=n;d++)

if (n%d==0)

{

while(n%d==0)n/=d;

sol= (sol/d)*(d-1);

}

if (n!=1) sol=sol/n*(n-1);

return sol;

}
long long putere(long long n,long long p,long long MOD)

{

long long r=1;

while(p){

     if(p%2)r=(1LL*r*n)%MOD;

     n=(1LL*n*n)%MOD;

     p/=2;

    }

return r;

}

int main()

{

fi>>a>>n;

p=phi_n(n)-1;

fo<<putere(a,p,n);

return 0;

}
