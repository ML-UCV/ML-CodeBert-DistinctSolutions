#include <bits/stdc++.h>


using namespace std;



ifstream f ("ctc.in");

ofstream g("ctc.out");



int N,M;

const int NMAX = 100005;







vector <int> adj[NMAX], con, idx, lowlink, in_stack;



vector < vector <int> > Solution;



stack <int> S;



int indecs;



void read(vector <int>* adj )

{

    int x, y;

    f>>N>>M;

    for(int i=0;i<M;i++)

        f >> x >> y,

        adj[x - 1].push_back(y - 1);



}



void print(const vector < vector <int> >& G)

{

    g << G.size() << "\n";

    for (int i = 0; i < G.size(); ++ i)

    {

        for (int j = 0; j < G[i].size(); ++ j)

            g << G[i][j] + 1 << " ";

        g << "\n";

    }



}



void tarjan(const int n, const vector <int>* adj)

{

    idx[n] = lowlink[n] = indecs;

    indecs ++;

    S.push(n);

    in_stack[n] = 1;



    vector <int>::const_iterator it;

    for (it = adj[n].begin(); it != adj[n].end(); ++ it)

    {

        if (idx[*it] == -1)

        {

            tarjan(*it, adj);

            lowlink[n] = ((lowlink[n]) < (lowlink[*it]) ? (lowlink[n]) : (lowlink[*it]));

        }

        else if (in_stack[*it])

            lowlink[n] = ((lowlink[n]) < (lowlink[*it]) ? (lowlink[n]) : (lowlink[*it]));

    }

    if (idx[n] == lowlink[n])

    {

        con.clear();

        int node;

        do {

            con.push_back(node = S.top());

            S.pop();

            in_stack[node] = 0;

        }

        while (node != n);

        Solution.push_back(con);

    }

}



int main(void)

{

    read(adj);

    idx.resize(N), lowlink.resize(N), in_stack.resize(N);

    idx.assign(N, -1), in_stack.assign(N, 0);



    for (int i = 0; i < N; ++ i)

        if (idx[i] == -1)

            tarjan(i, adj);



    print(Solution);



    return 0;

}
