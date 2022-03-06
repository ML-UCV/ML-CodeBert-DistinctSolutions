#include <bits/stdc++.h>


using namespace std;

ifstream f("stramosi.in");

ofstream g("stramosi.out");

int n,m,x,y;

vector<int> graf[250001];

vector<int> s;

int parinti[250001][20];

bool viz[250001];

void Read()

{

    f>>n>>m;

    for(int i = 1;i <= n;++i)

        {

            f>>x;

            if(x != 0)

                graf[x].push_back(i);

        }

}



void DFS(int nod)

{

    viz[nod] = nod;

    s.push_back(nod);

    for(vector<int>::iterator it = graf[nod].begin();it != graf[nod].end();++it)

        if(!viz[*it])

        {

            for(int i = 0;(1 << i) <= s.size();++i)

                parinti[*it][i] = s[s.size() - (1 << i)];

            DFS(*it);

        }

    s.pop_back();

}



void Solve()

{

    for(int i = 1;i <= n;++i)

        if(!viz[i])

            {

                s.clear();

                DFS(i);

            }

    for(int i = 1;i <= m;++i)

    {

        f>>x>>y;

        while(y)

        {

            int i = 0;

            for(i = 0;(1 << i) <= y;++i);

            y -= (1 << (i - 1));

            x = parinti[x][i - 1];

        }

        g<<x<<'\n';

    }

}



int main()

{

    Read();

    Solve();

    return 0;

}
