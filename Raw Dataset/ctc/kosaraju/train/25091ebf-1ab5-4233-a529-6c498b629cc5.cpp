#include <bits/stdc++.h>
using namespace std;



ifstream f("ctc.in");

ofstream g("ctc.out");

int n, m, x, y, nr;

vector<int> graf[100005], transpus[100005];

vector<int> topologic;

vector<int> componente[100005];

bool viz[100005];



void Read()

{

    f>>n>>m;

    for(int i = 1;i <= m;++i)

    {

        f>>x>>y;

        graf[x].push_back(y);

        transpus[y].push_back(x);

    }

}



void dfs(int nod)

{

    viz[nod] = true;

    for(vector<int>::iterator it = graf[nod].begin();it != graf[nod].end();++it)

        if(!viz[*it])

            dfs(*it);

    topologic.push_back(nod);

}



void dfst(int nod)

{

    viz[nod] = false;

    componente[nr].push_back(nod);

    for(vector<int>::iterator it = transpus[nod].begin();it != transpus[nod].end();++it)

        if(viz[*it])

            dfst(*it);

}



int main()

{

    Read();

    for(int i = 1;i <= n;++i)

        if(!viz[i])

            dfs(i);

    for(int i = topologic.size() - 1;i >= 0;--i)

        if(viz[topologic[i]])

        {

            ++nr;

            dfst(topologic[i]);

        }

    g<<nr<<'\n';

    for(int i = 1;i <= nr;++i)

    {

        for(vector<int>::iterator it = componente[i].begin();it != componente[i].end();++it)

            g<<*it<<" ";

        g<<'\n';

    }

    return 0;

}
