#include <iostream>
#include <fstream>
#include <deque>
using namespace std;

const int Q_sze=30;

const int Maxx=5e4+1;

deque <int> Q[Q_sze];

ifstream fin("swap.in");

ofstream fout("swap.out");

int aint[4*Maxx],vis[4*Maxx];

int i,n,ans,len,m;

string s;

void build(int node,int left,int right);

int query(int node,int tot);

int main()

{

    fin>>s;

    n=s.size();

    for (i=n-1;i>=0;--i) Q[s[i]-96].push_back(i);

    build(1,1,n);

    fin>>s;

    for (i=0;i<n;++i){

        if (Q[s[i]-96].empty()){

            fout<<"-1\n";

            return 0;

        }

        ans+=(Q[s[i]-96].back()+1)-query(aint[Q[s[i]-96].back()+1],0)-1;

        Q[s[i]-96].pop_back();

    }

    fout<<ans;

    return 0;

}

void build(int node,int left,int right){

    if (left==right){

        aint[++len]=node;

        return;

    }

    int mid=(left+right)/2;

    build(2*node,left,mid);

    build(2*node+1,mid+1,right);

}

int query(int node,int poz){

    if (node==1) return poz;

    if (node%2==0) ++vis[node+1];

    return query(node/2,poz+vis[node]);

}
