#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef signed long long ll;
typedef unsigned int uint;
typedef unsigned char uchar;
template <typename T>
void printarray(T v[], uint n) {for(uint i = 0; i < n; i ++){cout << v[i] << " ";}cout << endl;}
template <typename T>
void printvector(vector<T> v){for (uint i = 0; i < v.size(); i ++){cout << v[i] << " ";}cout << endl;}
#define dbg(x) cout << #x " = " << x << " | ";
#define dbgnl(x) cout << #x " = " << x << endl;

const int nmax = 30005;
struct edge_t {
    int finish;
    int dist;
};
vector<edge_t> G[nmax];
int dists[nmax];
bitset<nmax> visited;
int n, m, X, Y;

void read() {
    cin >> n>>m>>X>>Y;
    for (int i = 0; i < m; i++) {
        int s, f, d;
        cin >> s >> f >>d;
        G[s].push_back({f,d});
        G[f].push_back({s,d});
    }
}

void solve() {
    queue<int> q;
    q.push(X);

    while (!q.empty() && !visited[Y]) {
        int node = q.front();
        q.pop();
        
        for (auto edge: G[node]) {
            if (!visited[edge.finish]){ 
                visited[edge.finish] = true;
                q.push(edge.finish);

                if (node > edge.finish) {
                    dists[edge.finish] = dists[node] - edge.dist;
                } else if (node < edge.finish) {
                    dists[edge.finish] = dists[node] + edge.dist;
                }     
            }
        }
    }
}

void write() {
    cout << dists[Y] << "\n";
}

int main() {
    //freopen("input", "r", stdin);
    freopen("sate.in", "r", stdin); 
    freopen("sate.out", "w", stdout); 
      
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    read();
    solve();
    write();

    return 0;
}
