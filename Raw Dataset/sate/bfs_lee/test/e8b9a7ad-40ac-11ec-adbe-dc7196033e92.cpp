#include <bits/stdc++.h>
#define fi first
#define se second

using namespace std;


int n,m,x,y,a,b,c, dist_x[30010];
bool viz[30010];

queue< int > q;

vector < pair < int, int > > v[30010];

int main(){

    ifstream cin("sate.in");
    ofstream cout("sate.out");

    cin>>n>>m>>x>>y;

    for(int i=1;i<=m;i++){
        cin>>a>>b>>c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});

    }

    q.push(x);
    viz[x] = 1;
    dist_x[x] = 0;
    while(!q.empty()){

        int curr = q.front();
        q.pop();
        for(auto it : v[curr]){
            if(!viz[it.fi]){

                if(it.fi > curr)
                    dist_x[it.fi] = dist_x[curr] + it.se;
                else
                    dist_x[it.fi] = dist_x[curr] - it.se;
                if(it.fi == y) {
                    cout<<dist_x[y];
                    return 0;
                }
                viz[it.fi] = 1;
                q.push(it.fi);
            }
        }

    }

    cout<<-1;

    return 0;
}
