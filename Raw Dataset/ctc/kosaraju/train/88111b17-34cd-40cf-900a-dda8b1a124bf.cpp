#include <bits/stdc++.h>


using namespace std;

ifstream fin("ctc.in");

ofstream fout("ctc.out");



const int NMAX = 1e5 + 3;

int n, m, nrSCCs;

array<vector<int>, NMAX> graph, tranGraph, SCC;

array<int, NMAX> nrVis;

stack<int> st;



void read()

{

    fin >> n >> m;

    for (int i = 1; i <= m; i++)

    {

        int x, y;

        fin >> x >> y;

        graph[x].push_back(y);

        tranGraph[y].push_back(x);

    }

}



void dfs(int start)

{

    nrVis[start] = 1;

    for (auto nei : graph[start])

        if (!nrVis[nei])

            dfs(nei);

    st.push(start);

}



void dfsTran(int start)

{

    nrVis[start] = 2;

    SCC[nrSCCs].push_back(start);



    for (auto nei : tranGraph[start])

        if (nrVis[nei] == 1)

            dfsTran(nei);

}



void solve()

{

    for (int i = 1; i <= n; i++)

        if (!nrVis[i])

            dfs(i);



    while (!st.empty())

    {

        if (nrVis[st.top()] == 1)

        {

            nrSCCs++;

            dfsTran(st.top());

        }

        st.pop();

    }

}



void display()

{

    fout << nrSCCs << '\n';

    for (int i = 1; i <= nrSCCs; i++)

    {

        for (auto node : SCC[i])

            fout << node << ' ';

        fout << '\n';

    }

}



int main()

{

    read();

    solve();

    display();

    fout.close();

    return 0;

}
