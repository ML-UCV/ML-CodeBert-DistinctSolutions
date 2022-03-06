#include <bits/stdc++.h>


using namespace std;



ifstream in("ctc.in");

ofstream out("ctc.out");



const int N = 1e5 + 5;

int n, m, i, j, scc, nod;

int viz[N], stk[N];

vector <int> ans[N];

vector <int> Gx[N];

vector <int> Gy[N];



void dfs1(int x)

{

    viz[x] = 1;

    vector<int>::iterator it;

    for(it = Gx[x].begin(); it < Gx[x].end(); it++)

        if(viz[*it] == 0) dfs1(*it);

    stk[++m] = x;

}



void dfs2(int x, int scc)

{

    viz[x] = 2;

    ans[scc].push_back(x);

    vector<int>::iterator it;

    for(it = Gy[x].begin(); it < Gy[x].end(); it++)

        if(viz[*it] == 1) dfs2(*it, scc);

}



int main()

{

    in >> n >> m;



    for(i = 1; i <= m; i++)

    {

        int x, y;

        in >> x >> y;

        Gx[x].push_back(y);

        Gy[y].push_back(x);

    }



    m = 0;



    for(i = 1; i <= n; i++)

        if(viz[i] == 0) dfs1(i);



    scc = 0;



    while(m > 0)

    {

        nod = stk[m];

        m--;

        if(viz[nod] == 1) dfs2(nod, ++scc);

    }



    out << scc << '\n';



    for(i = 1; i <= scc; i++)

    {

        for(j = 0; j < ans[i].size(); j++)

            out << ans[i][j] << ' ';

        out << '\n';

    }



    return 0;

}
