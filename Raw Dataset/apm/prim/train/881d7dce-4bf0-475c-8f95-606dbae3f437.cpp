#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
const int INF=0x3f3f3f3f;

int n, m;
int h[4*200005], poz[200005],dep, father[200005],ans, cost[200005];
VPII g[200005];
VPII vans;

void push (int node) {
    int x, y = poz[node];
    while (y != x) {
        x = y;
        if (((x << 1) <= dep) && cost[h[y]] > cost[h[(x << 1)]]) {
            y = (x << 1);
        }
        if ((((x << 1) + 1) <= dep) && cost[h[y]] > cost[h[(x << 1) + 1]]) {
            y = (x << 1) + 1;
        }

        swap(h[x], h[y]);
        swap(poz[h[x]], poz[h[y]]);
    }
}

int read_head() {
    int node = h[1];
    h[1] = h[dep];
    poz[h[1]] = poz[node];
    --dep;
    push(h[1]);
    return node;
}

void repair_heap (int node) {
    while (poz[node] > 1 && cost[h[poz[node]]] < cost[h[poz[node] / 2]]) {
        int p = poz[node];
        swap(poz[h[p]], poz[h[p / 2]]);
        swap(h[p], h[p / 2]);
    }
}

void put_in_heap (int node) {
    h[++dep] = node;
    poz[node] = dep;
    repair_heap(node);
}

void put_in_apm (int node) {
    for(auto it: g[node]) {
        if (cost[it.first] >= it.second) {

            cost[it.first] = it.second;
            father[it.first] = node;
            repair_heap(it.first);
        }
    }
}

int main()
{
    freopen("apm.in","r",stdin);
    freopen("apm.out","w",stdout);
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int x, y, c;
    cin >> n >> m;

    for(int i=(1);i<=(m);++i) {
        cin >> x >> y >> c;
        g[x].push_back({y,c});
        g[y].push_back({x,c});
    }
    for(int i=(1);i<=(n);++i) {
        cost[i] = INF;
    }
    cost[1] = 0;
    put_in_apm(1);
    for(int i=(2);i<=(n);++i) {
        put_in_heap(i);
    }
    for(int i=(1);i<(n);++i) {
        int node = read_head();
        put_in_apm(node);
        ans += cost[node];
        vans.push_back({node, father[node]});
    }
    cout << ans << '\n' << ((int)(vans).size()) <<'\n';
    for (auto it: vans) {
        cout << it.first <<' ' << it.second << '\n';
    }

}
