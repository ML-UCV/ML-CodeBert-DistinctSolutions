#include <bits/stdc++.h> //Andrei Alexandru a.k.a Sho10



using namespace std;

long long a,n,inv=0;

long long pw(long long a,long long b){

    if(b==0) return 1;

    long long x=pw(a,b/2);

    if(b%2==1){

            return (((x*x)%n)*a)%n;

    }else return (x*x)%n;

}

long long phi(long long x){

long long ans=x;

for(long long i=2;i*i<=n;i++)

{

    if(x%i==0){

        ans=(ans/i);

     ans=ans*(i-1LL);

     while(x%i==0){

        x=x/i;

     }

     }

}

if(x>1){

    ans=ans/x;

    ans=ans*(x-1LL);

}

return ans;

}

int32_t main(){

ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);;

ifstream cin("inversmodular.in");

ofstream cout("inversmodular.out");

cin>>a>>n;

phi(n);

cout<<pw(a,phi(n)-1LL)%n<<'\n';

}
