#include <bits/stdc++.h>


using namespace std;



const int NMAX = 100;

int N, M;

vector <vector <int>> graph, revgraph;

bitset <2 * NMAX> seen;



int neg(int x){

    if (x < N){

        return x + N;

    }

    else{

        return x - N;

    }

}



void AddEdge(int x, int y){

    int negx = neg(x);

    int negy = neg(y);

    graph[negx].push_back(y);

    graph[negy].push_back(x);

    revgraph[y].push_back(negx);

    revgraph[x].push_back(negy);

}



vector <int> topo;

vector <bool> color;



void dfs1(int node){

    seen[node] = 1;

    for (auto& x : graph[node]){

        if (seen[x] == 0){

            dfs1(x);

        }

    }

    topo.push_back(node);

}



void dfs2(int node){

    seen[node] = seen[neg(node)] = 0;

    color[neg(node)] = true;

    for (auto& x : revgraph[node])

        if (seen[x] == 1)

            dfs2(x);

}



int main()

{

    ifstream fin("party.in");

    ofstream fout("party.out");

    fin >> N >> M;

    graph = vector <vector <int>>(2 * N, vector <int>());

    revgraph = vector <vector <int>>(2 * N, vector <int>());

    color = vector <bool>(2 * N, false);

    for (int i = 0;i < M;++i){

        int t, x, y;

        fin >> x >> y >> t;

        --x; --y;

        if (t == 0)

            AddEdge(x, y);

        else if (t == 1)

            AddEdge(x, neg(y));

        else if (t == 2)

            AddEdge(neg(x), y);

        else

            AddEdge(neg(x), neg(y));

    }

    for (int i = 0;i < 2 * N;++i)

        if (seen[i] == 0)

            dfs1(i);

    reverse(topo.begin(), topo.end());

    for (auto& i : topo)

        if (seen[i] == 1 && seen[neg(i)] == 1)

            dfs2(i);

    vector <int> answer;

    for (int i = 0;i < N;++i)

        if (color[i] == true)

            answer.push_back(i);

    fout << answer.size() << "\n";

    for (auto& i : answer)

        fout << i + 1 << "\n";

    fin.close();

    fout.close();

    return 0;

}
