#include <fstream>
#include <vector>
using namespace std;

ifstream cin ("ctc.in");

ofstream cout ("ctc.out");

vector <int> lista[100005];

vector <int> lista2[100005];

int viz[100005], k = 0, cnt = 0, st[100005], sol[200005];

void dfs(int nod)

{

    viz[nod] = 1;

    for (int i = 0; i < lista[nod].size(); i++)

    {

        int x = lista[nod][i];

        if(!viz[x])

            dfs(x);

    }

    st[++k] = nod;

}

void dfs2(int nod)

{

    viz[nod] = 2;

    for (int i = 0; i < lista2[nod].size(); i++)

    {

        int x = lista2[nod][i];

        if (viz[x] == 1)

            dfs2(x);

    }

    sol[++cnt] = nod;

}

int main()

{

    int n, m, i, ans = 0;

    cin >> n >> m;

    for (i = 1; i <= m; i++)

    {

        int x, y;

        cin >> x >> y;

        lista[x].push_back(y);

        lista2[y].push_back(x);

    }

    for (i = 1; i <= n; i++)

        if (!viz[i])

            dfs(i);

    while (k)

    {

        if (viz[st[k]] == 1)

        {

            ans++;

            dfs2(st[k]);

            sol[++cnt] = -1;

        }

        k--;

    }

    cout << ans << '\n';

    for (i = 1; i <= cnt; i++)

    {

        if (sol[i] == -1)

            cout << '\n';

        else

            cout << sol[i] << " ";

    }

    return 0;

}
