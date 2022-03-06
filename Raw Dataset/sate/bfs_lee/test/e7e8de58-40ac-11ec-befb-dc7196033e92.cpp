#include <bits/stdc++.h>

#define fi first
#define se second

//typedef unsigned int ui;
//typedef long long ll;
using namespace std;

int N, M, X, Y, a, b, c;
int dist[30010];
bool viz[30010];
vector < pair <int, int> > V[30010];
//vector <int> D[30010];
queue <int> Q;

int main(){

ifstream cin("sate.in");
ofstream cout("sate.out");
 ios_base::sync_with_stdio(false);
    cin.tie(NULL);
cin >> N >> M >> X >> Y;

for (int i = 0; i < M; i++)
{
    cin >> a >> b >> c;
    V[a].push_back({b, c});
    V[b].push_back({a, c});
  //  D[a].push_back(c);
    //D[b].push_back(c);
}

Q.push(X);
viz[X] = 1;
dist[X] = 0;

while(!Q.empty())
{
    int curr = Q.front();
    Q.pop();

    for (auto it : V[curr]){
        if(!viz[it.fi]){

            if (it.fi > curr)
            {
                dist[it.fi] = dist[curr] + it.se;
            }
            else
            {
                dist[it.fi] = dist[curr] - it.se;
            }
            if (it.fi == Y)
            {
                cout << dist[Y];
                return 0;
            }
            Q.push(it.fi);
            viz[it.fi] = 1;
        }
    }


    }

return 0;
}
