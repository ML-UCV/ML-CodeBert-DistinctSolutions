#include <bits/stdc++.h>


using namespace std;

ifstream fin("ctc.in");

ofstream fout("ctc.out");

bool vizat1[100005], vizat2[100005];

vector <int> graph1[100005];

vector <int> graph2[100005];

vector <int> ctc[100005];

stack <int> ord;

int n, m, ctc_size;



void dfs1(int nod)

{

    vizat1[nod] = 1;

    unsigned len, i;

    int var;

    len = graph1[nod].size();

    for(i = 0; i < len; i++)

    {

        var = graph1[nod][i];

        if(!vizat1[var])

            dfs1(var);

    }

    ord.push(nod);

}



void dfs2(int nod)

{

    vizat2[nod] = 1;

    unsigned len, i;

    int var;

    len = graph2[nod].size();

    for(i = 0; i < len; i++)

    {

        var = graph2[nod][i];

            if(!vizat2[var])

                dfs2(var);

    }

    ctc[ctc_size].push_back(nod);

}



int main()

{

    int i, x, y;

    unsigned j, len;

    fin >> n >> m;

    for(i = 0; i < m; i++)

    {

        fin >> x >> y;

        graph1[x].push_back(y);

        graph2[y].push_back(x);

    }

    for(i = 1; i <= n; i++)

        if(vizat1[i] == 0)

            dfs1(i);

    while(!ord.empty())

    {

        x = ord.top();

        ord.pop();

        if(!vizat2[x])

        {

            dfs2(x);

            ctc_size++;

        }

    }

    fout << ctc_size << endl;

    for(i = 0; i < ctc_size; i++)

    {

        len = ctc[i].size();

        for(j = 0; j < len; j++)

            fout << ctc[i][j] << ' ';

        fout << '\n';

    }

    return 0;

}
