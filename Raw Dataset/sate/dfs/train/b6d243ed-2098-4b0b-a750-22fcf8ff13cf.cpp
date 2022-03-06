#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0);
#define tie cin.tie(0);
#define mp make_pair
#define ll long long
#define PII pair<int, int>
#define PLL pair<ll, ll>
#define inf 1000000000
#define zeros(x) ( (x ^ (x - 1)) & x )

using namespace std;

int n, m, x, y, z, in, sf;

vector < PII > V[100100];
int cost[100100];

void dfs(int x)
{
    for (auto it : V[x])
    {
        if (!cost[it.first])
        {
            cost[it.first] = cost[x] + it.second;
            if (it.first == sf) break;
            dfs(it.first);
        }
    }
}


int main(){
    IOS tie
    ifstream cin("sate.in");
    ofstream cout("sate.out");
    cin >> n >> m >> in >> sf;
    if (in > sf) swap(in, sf);
    for (int i = 1; i <= m; i++)
    {
        cin >> x >> y >> z;
        V[x].push_back(mp(y, z));
        V[y].push_back(mp(x, -z));
    }
    dfs(in);
	cout << cost[sf];
	cerr << "Fucking time elapsed: " << clock() * 1000.0 / CLOCKS_PER_SEC << " ms" << '\n';
    return 0;
}