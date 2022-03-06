#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
const int INF=0x3f3f3f3f;

int n,poz;
int v[30005],aint[4*30005],sol[30005];

void generator(int node,int val){
    aint[node]=val;
    if(val==1)
        return;
    generator(node*2,val/2);
    if(val&1)
        generator(node*2+1,val/2+1);
    else
        generator(node*2+1,val/2);
}

int solver(int node,int st, int dr,int val){
    aint[node]--;
    if(st==dr)
        return st;
    int middle = (st+dr-1)/2;
    if(aint[node*2]>=val)
        return solver(node*2,st,middle,val);
    else{
        val -= aint[node*2];
        return solver(node*2+1,middle+1,dr,val);
    }
}

int main()
{
    freopen("schi.in","r",stdin);
    freopen("schi.out","w",stdout);
    cin>>n;
    for(int i=(1);i<=(n);++i) cin>>v[i];
    generator(1,n);
    for(int i=n;i>0;--i){
        poz = solver(1,1,n,v[i]);
        sol[poz]=i;
    }
    for(int i=(1);i<=(n);++i)
        cout<<sol[i]<<'\n';

}
