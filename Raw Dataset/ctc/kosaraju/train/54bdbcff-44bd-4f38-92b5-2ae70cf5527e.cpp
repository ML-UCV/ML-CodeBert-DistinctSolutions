#include <fstream>
#include <deque>
#include <vector>


using namespace std;



ifstream in ("ctc.in");

ofstream out ("ctc.out");



int n,m,cnt;

bool ok[100001];

vector <int> dir[100001],inv[100001],v[200001];

deque <int> d;



void dfs(int x)

{

    ok[x]=1;

    for (int i=0;i<dir[x].size();i++)

    {

        if (!ok[dir[x][i]])

            dfs(dir[x][i]),d.push_front(dir[x][i]);

    }

}



void dfs2(int x)

{

    ok[x]=1;

    for (int i=0;i<inv[x].size();i++)

    {

        if (!ok[inv[x][i]])

            dfs2(inv[x][i]),v[cnt].push_back(inv[x][i]);

    }

}



int main()

{

    int a,b;

    in>>n>>m;

    for (int i=1;i<=m;i++)

        in>>a>>b,dir[a].push_back(b),inv[b].push_back(a);



    for (int i=1;i<=n;i++)

    {

        if (!ok[i])

            dfs(i),d.push_front(i);

    }

    for (int i=1;i<=n;i++)

        ok[i]=0;

    for (int i : d)

    {

        if (!ok[i])

        {

            cnt++;

            dfs2(i);

            v[cnt].push_back(i);

        }

    }

    out<<cnt<<'\n';

    for (int i=1;i<=cnt;i++)

    {

        for (int j=0;j<v[i].size();j++)

            out<<v[i][j]<<" ";

        out<<'\n';

    }

    return 0;

}
