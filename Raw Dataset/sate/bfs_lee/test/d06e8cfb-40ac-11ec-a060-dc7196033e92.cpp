#include<bits/stdc++.h>
using namespace std;
#define INIT  ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define mp make_pair
#define pb push_back
#define ft first
#define sc second
#define ll long long
#define pii pair<int, int>
#define count_bits __builtin_popcount
#define int ll

ifstream fin("sate.in"); ofstream fout("sate.out");
#define cin fin
#define cout fout



int n, m;
vector<pii> g[30010];
int x, y;
int dx[30010];
bool v[30010];

int32_t main(){
INIT
cin>>n>>m>>x>>y;
if(y<x){swap(x, y);}
for(int i=1; i<=m;i++){
    int a, b, d; cin>>a>>b>>d;
    g[a].pb(mp(b, d)); g[b].pb(mp(a, -d));
}


multiset<pii> q;
q.insert(mp(0, x) );
dx[x]=0;

while(!q.empty()){
    pii f=(*(q.begin())); q.erase(q.begin());
    int nd=f.sc;
    v[nd]=true;

    for(int i=0; i<g[nd].size(); i++){
        if(!v[g[nd][i].ft] ){
            auto it=q.find(mp(dx[g[nd][i].ft ], g[nd][i].ft) );

            if(it!=q.end()){
                q.erase(it);
            }

            if(dx[g[nd][i].ft ]==0){
                q.insert(mp( dx[nd]+g[nd][i].sc ,g[nd][i].ft)  );
                dx[g[nd][i].ft ]=dx[nd]+g[nd][i].sc;
            }
            else{
                q.insert(mp(min(dx[nd]+g[nd][i].sc, dx[g[nd][i].ft ]) ,g[nd][i].ft) );
                dx[g[nd][i].ft ]=min(dx[nd]+g[nd][i].sc, dx[g[nd][i].ft ]);
            }



        }
    }

}

cout<<dx[y];


return 0;
}

