#include <fstream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

ifstream cin("ctc.in");

ofstream cout("ctc.out");

int n, m;

int use[100001];

vector<int> g[100001];

vector<int> gt[100001];

vector<int> s;

vector<vector<int>>ans;

vector<int> v;

void dfs1(int nod)

{

    use[nod] = 1;



    for(int i=0;i<g[nod].size();i++)

    {

        if(use[g[nod][i]]==0)

            dfs1(g[nod][i]);

    }

    s.push_back(nod);

}

void dfs2(int nod)

{

    use[nod] = -1;

    v.push_back(nod);

    for (int i = 0; i < gt[nod].size(); i++)

    {

        if (use[gt[nod][i]] == 1)

            dfs2(gt[nod][i]);

    }

}

int main()

{

    ios_base::sync_with_stdio(false);

    cin >> n >> m;

    for (int i = 1; i <= m; i++)

    {

        int x, y;

        cin >> x >> y;

        g[x].push_back(y);

        gt[y].push_back(x);

    }

    for (int i = 1; i <= n; i++)

    {

        if (use[i] == 0)

            dfs1(i);

    }

    for(int i=s.size()-1;i>=0;i--)

    {

        if (use[s[i]] == 1)

        {

            v.clear();

            dfs2(s[i]);

            ans.push_back(v);

        }

    }

    cout << ans.size() << "\n";

    for (auto i : ans)

    {

        for (auto j : i)

            cout << j << " ";

        cout << "\n";

    }

    return 0;

}
