#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll const mod=1000000007;

ll const md=998244353;

ll mypowr(ll a,ll b) {ll res=1;if(b<0)b=0;a%=mod; assert(b>=0);

for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}

ll mypow(ll a,ll b) {ll res=1;if(b<0)b=0;assert(b>=0);

for(;b;b>>=1){if(b&1)res=res*a;a=a*a;}return res;}

ifstream in("cmmdc.in");

ofstream out("cmmdc.out");
int gcd(int a,int b){

if(b!=0){

    return gcd(b,a%b);

}

if(a==1)a=0;

return a;



}





int main()

{

    ios_base::sync_with_stdio(0);

    in.tie(0);out.tie(0);

    out<<fixed<<setprecision(15);



    int a,b;

    in>>a>>b;

    out<<gcd(a,b)<<'\n';
    return 0;

}
