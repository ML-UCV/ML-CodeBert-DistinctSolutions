#include <bits/stdc++.h>




using namespace std;

ifstream fin("inversmodular.in");

ofstream fout("inversmodular.out");

long long A, N, mod;

long long phi(long long n){

    long long ans=n;

for(long long i=2;i*i<=n;i++){

    if(n%i==0)

        {

            ans=ans/i*(i-1);

            while(n%i==0) n/=i;

        }

}

if(n!=1)

    ans=ans/n*(n-1);

return ans;

}

long long put(long long n, long long p){

long long ans=1;

while(p>0){

    if(p%2==1)

        ans=(ans*n)%mod;

      n=(n*n)%mod;

    p/=2;

}

return ans;

}

int main()

{

    fin>>A>>N;

    mod=N;

    long long p=phi(N)-1;

     long long sol=1;





    fout<<put(A,p);

    return 0;

}
