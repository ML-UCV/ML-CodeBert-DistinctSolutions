#include <bits/stdc++.h>
using namespace std;

int v[1000005];

int euler(int x){

    int nr=x;

    int d=2;

    while(d*d<=x){

        int ex=0;

        while(x%d==0){

            x/=d;

            ++ex;

        }

        if(ex>0)

            nr=1LL*nr*(d-1)/d;

        ++d;

    }

    if(x>1)

        nr=1LL*nr*(x-1)/x;

    return nr;

}

int lg_pow(long long a,long long b,int MOD){

    long long ans=1,p=a;

    for(long long i=1;i<=b;i<<=1){

        if(i&b)

            ans=ans*p%MOD;

        p=p*p%MOD;

    }

    return ans;

}

int main(){

    freopen("inversmodular.in","r",stdin);

    freopen("inversmodular.out","w",stdout);

    int a,n;

    scanf("%d %d",&a,&n);

    printf("%d\n",lg_pow(a,euler(n)-1,n));

    return 0;

}
