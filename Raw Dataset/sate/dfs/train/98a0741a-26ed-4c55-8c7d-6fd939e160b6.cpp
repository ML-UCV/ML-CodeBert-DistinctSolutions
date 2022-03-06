#include <bits/stdc++.h>
using namespace std;
#define pb push_back

int n,m,X,Y,D[30010];
vector <pair<int,int> > V[30010];
bool u[30010];

void dfs(int q, int c){
    D[q]=c;
    u[q]=true;
    for (int i=0; i<V[q].size(); i++){
        if (!u[V[q][i].first]) dfs(V[q][i].first,(V[q][i].first<q?c-V[q][i].second:c+V[q][i].second));
    }
}

int main(){
    ifstream cin ("sate.in");
    ofstream cout ("sate.out");
    cin>>n>>m>>X>>Y;
    for (int i=1; i<=m; i++){
        int x,y,c;
        cin>>x>>y>>c;
        V[x].pb(make_pair(y,c));
        V[y].pb(make_pair(x,c));
    }
    dfs(X,0);
    cout<<D[Y];
    return 0;
}
