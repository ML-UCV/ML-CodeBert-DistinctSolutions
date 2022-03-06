#include <bits/stdc++.h> //Andrei Alexandru a.k.a Sho10



using namespace std;

long long n,a[3000005],bit[3000005],ans[300005];

long long query(long long pos){

long long rs=0;

for(;pos>=1;pos-=pos&(-pos)){

    rs+=bit[pos];

}

return rs;

}

void update(long long pos,long long val){

for(;pos<=n;pos+=pos&(-pos)){

    bit[pos]+=val;

}

}

int32_t main(){

ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);;

ifstream cin("schi.in");

ofstream cout("schi.out");

cin>>n;

for(long long i=1;i<=n;i++)

{

    cin>>a[i];

    update(i,1);

}

for(long long i=n;i>=1;i--)

{

    long long x=a[i];

    long long l=1,r=n;

    while(l<=r){

        long long mid=(l+r)/2;

        if(query(mid)>=x){

            r=mid-1;

        }else l=mid+1;

    }

    ans[l]=i;

    update(l,-1);

}

for(long long i=1;i<=n;i++)

{

    cout<<ans[i]<<'\n';

}

}
