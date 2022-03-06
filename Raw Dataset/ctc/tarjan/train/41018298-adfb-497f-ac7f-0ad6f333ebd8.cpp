#include<bits/stdc++.h>
using namespace std;

ifstream fin("ctc.in");
ofstream fout("ctc.out");

const int oo=INT_MAX/2;

typedef vector<int> vi;

int n,m,k;
vector<vi> g;

vi lowlink, idx, inStk;
vi stk;

vector<vi> ctcs;

int _index=1;
void tarjan(int nd){
    lowlink[nd]=idx[nd]=_index++;
    inStk[nd]=1;
    stk.push_back(nd);

    for(auto vc:g[nd]){
        if(idx[vc]==0){
            tarjan(vc);
            lowlink[nd]=min(lowlink[nd],lowlink[vc]);
        }
        else if(inStk[vc]){
            lowlink[nd]=min(lowlink[nd],lowlink[vc]);
        }
    }
    if(lowlink[nd]==idx[nd]){

        ctcs.push_back(vi());
        int aux;
        do {
            ctcs.back().push_back(aux=stk.back());
            inStk[stk.back()]=0;
            stk.pop_back();
        }
        while(aux!=nd);
    }
}

int main(){
    fin>>n>>m;
    g.resize(n+1), lowlink.resize(n+1), idx.resize(n+1,0), inStk.resize(n+1,0);
    for(int i=m;i--;){
        int x,y; fin>>x>>y;
        g[x].push_back(y);
    }
    for(int i=1;i<=n;++i)
        if(idx[i]==0) tarjan(i);
    fout<<ctcs.size()<<"\n";
    for(int i=0;i<ctcs.size();++i){
        for(int j=0; j<ctcs[i].size(); ++j)
            fout<<ctcs[i][j]<<" ";
        fout<<"\n";
    }

}
