#include <bits/stdc++.h>
using namespace std;

long long rid_put(int nr,int exp,int mod)

{

    long long rez=1,val=nr;

    while(exp)

    {

        if(exp&1)rez=rez*val;

        val=val*val;

        rez%=mod;

        val%=mod;

        exp=exp>>1;

    }

    return rez;

}

int main()

{

    freopen("inversmodular.in","r",stdin);

    freopen("inversmodular.out","w",stdout);

    int n,k;

    scanf("%d%d",&n,&k);

    int d=2,e=0;

    int prim=k;

    int l=k;

    while(d*d<=k)

    {

        e=0;

        while(k%d==0)

        {

            k/=d;

            e++;

        }

        if(e)

            prim/=d,prim*=d-1;

        d++;

    }

    if(k>1)prim/=k,prim*=k-1;



    cout<<rid_put(n,prim-1,l);

    return 0;

}
