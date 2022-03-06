#include <bits/stdc++.h>

using namespace std;

ifstream f("sate.in");
ofstream g("sate.out");

const int INF = 1e9;

vector <pair <int, int>> adj[30001];

bitset <30001> u;

int d[30001];
int N, M, X, Y;

void SPFA(int s){
    queue <int> q;
    for(int i = 1;i <= N;i++)
        d[i] = INF;
    
    d[s] = 0, u[s] = 1;
    q.push(s);
    while(!q.empty()){
        int v = q.front();
        q.pop();
        u[v] = 0;
        for(auto edge : adj[v]){
            int to = edge.first;
            int len = edge.second;

            if(d[v] + len < d[to]){
                d[to] = d[v] + len;
                if(!u[to]){
                    q.push(to);
                    u[to] = 1;
                }
            }
        }
    }

    g << d[Y];
}

int main(){

	f >> N >> M >> X >> Y;
	while(M--){
		int x, y, c;
		f >> x >> y >> c;
		adj[x].emplace_back(y, c);
		adj[y].emplace_back(x, -c);
	}

	SPFA(X);
}