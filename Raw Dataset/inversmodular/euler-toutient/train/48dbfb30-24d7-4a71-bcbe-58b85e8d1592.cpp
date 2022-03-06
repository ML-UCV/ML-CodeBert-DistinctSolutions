#include<bits/stdc++.h>
using namespace std;
ifstream fin("inversmodular.in"); ofstream fout("inversmodular.out");
int phi(int x){

int res=x;

int n=x;



for(int i=2; i*i<=x; i++){

    if(n%i==0){

        while(n%i==0){

            n/=i;

        }

        res-=res/i;

    }

}



if(n>1){

    res-=res/n;

}

return res;

}





long long n, a;
long long exp(long long x, long long e){





if(e==1){return x;}



if(e%2==0){return exp( (x*x)%n, e/2 )%n; }

else{return (x*exp( (x*x)%n, e/2 ))%n; }







}
int32_t main(){

ios_base :: sync_with_stdio(0); cin.tie(); cout.tie();mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

fin>>a>>n;



fout<<exp(a, phi(n)-1 );





return 0;

}
