#include <bits/stdc++.h>
using namespace std;

ifstream fin("schi.in");

ofstream fout("schi.out");

typedef pair <int, int> pairINT;

typedef long long ll;

class SegmentTree{

    public:

        int n;

        int query(int poz){

           return qry(1,1,n,poz);

        }

    private:

        int segm[(int)(3e4+4)*4];

        int qry(int node,int l,int r, int poz){

            if(l == r){

                segm[node]=1;

                return l;

            }

            int ans,mid=(l+r)>>1,amm=(mid-l+1)-segm[node<<1];

            if(amm >= poz)

                ans=qry(node<<1,l,mid,poz);

            else

                ans=qry(node<<1|1,mid+1,r,poz-amm);

            segm[node]=segm[node<<1]+segm[node<<1|1];

            return ans;

        }

};



int n,v[(int)(3e4+4)],sol[(int)(3e4+4)];

SegmentTree Arb;



int main(){

    fin>>n;

    Arb.n=n;;

    for(int i=1;i<=n;++i)

        fin>>v[i];

    for(int i=n;i>0;--i)

        sol[Arb.query(v[i])]=i;

    for(int i=1;i<=n;++i)

        fout<<sol[i]<<'\n';

    return 0;

}
