#include <bits/stdc++.h>
  
using namespace std;
const int MAXN = 30005;
  
int N, M, X, Y;
vector <pair<int, int> > g[MAXN];
  
ifstream fin("sate.in");
ofstream fout("sate.out");
  
int main() {
    fin >> N >> M >> X >> Y;
    while(M --) {
        int x, y, z;
        fin >> x >> y >> z;
        g[x].push_back(make_pair(y, z));
        g[y].push_back(make_pair(x, -z));
    }
    vector <int> dp(N + 1, 1 << 30);
    dp[X] = 0;
    queue <int> q;
    q.push(X);
    while(!q.empty()) {
        int nr,node = q.front();
        nr=g[node].size();
        for(int i=0;i<nr;i++) {
            if(dp[g[node][i].first] > dp[node] + g[node][i].second) {
                dp[g[node][i].first] = dp[node] + g[node][i].second;
                q.push(g[node][i].first);
            }
        }
        q.pop();
    }
    fout << dp[Y] << '\n';
}
