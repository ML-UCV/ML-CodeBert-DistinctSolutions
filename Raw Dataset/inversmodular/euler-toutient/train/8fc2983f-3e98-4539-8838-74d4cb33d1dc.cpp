#include<bits/stdc++.h>
using namespace std;



long long MOD;



long long fastPow(long long nr, long long p){

    long long aux=1;

    while(p){

        if(p%2)

            aux=(aux*nr)%MOD;

        nr=(nr*nr)%MOD;

        p/=2;

    }

    return aux%MOD;

}



long long getPhi(long long n){

    long long sol=n,d=2;

    while(d*d<=n){

        if(n%d==0){

            while(n%d==0)

                n/=d;

            sol=(sol/d)*(d-1);

        }

        d++;

    }

    if(n>1)

        sol=(sol/n)*(n-1);

    return sol;

}



int main(){

    freopen("inversmodular.in","r",stdin);

    freopen("inversmodular.out","w",stdout);

    long long n;

    scanf("%lld%lld", &n, &MOD);

    printf("%lld", fastPow(n, getPhi(MOD)-1));

    return 0;

}
