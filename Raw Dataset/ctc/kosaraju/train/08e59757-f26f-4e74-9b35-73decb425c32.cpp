#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update





using namespace std;

using namespace __gnu_pbds;

auto random_address = [] { char *p = new char; delete p; return uint64_t(p); };

const uint64_t SEED = chrono::steady_clock::now().time_since_epoch().count() * (random_address() | 1);

mt19937_64 rng(SEED);

typedef tree<

int,

null_type,

less<int>,

rb_tree_tag,

tree_order_statistics_node_update>

ordered_set;

typedef long long ll;

typedef unsigned long long ull;

typedef long double ld;

typedef pair<int,int> pii;

typedef pair<ll,ll> pll;

ifstream fin("ctc.in");

ofstream fout("ctc.out");

int n,m;

vector<int> muchii[100001],st,v;

vector<vector<int>> sol;

pii G[200001];

bool use[200001];

void dfs1(int nod)

{

    use[nod]=1;

    for(auto i:muchii[nod])

        if(!use[i])

        {

            use[i]=1;

            dfs1(i);

        }

    st.push_back(nod);

}

void dfs(int nod)

{

    use[nod]=1;

    v.push_back(nod);

    for(auto i:muchii[nod])

        if(!use[i])

            dfs(i);

}

int main()

{

    ios_base::sync_with_stdio(false);

    cin.tie(0);

    cout.tie(0);

    fin>>n>>m;

    for(int i=1;i<=m;i++)

    {

        int a,b;

        fin>>a>>b;

        G[i]={a,b};

        muchii[a].push_back(b);

    }

    for(int i=1;i<=n;i++)

        if(!use[i])

            dfs1(i);







    reverse(st.begin(),st.end());

    for(int i=1;i<=n;i++)

    {

        muchii[i].clear();

        use[i]=0;

    }

    for(int i=1;i<=m;i++)

        muchii[G[i].second].push_back(G[i].first);

    for(auto i:st)

        if(!use[i])

        {

            v.clear();

            dfs(i);

            sol.push_back(v);

        }

    fout<<sol.size()<<'\n';

    for(auto w:sol)

    {

        for(auto i:w)

            fout<<i<<" ";

        fout<<'\n';

    }

    return 0;

}
