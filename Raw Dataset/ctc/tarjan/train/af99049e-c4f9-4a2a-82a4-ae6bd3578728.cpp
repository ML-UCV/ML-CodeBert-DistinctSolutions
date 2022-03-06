#include <bits/stdc++.h>




using namespace std;



ifstream fin("ctc.in");

ofstream fout("ctc.out");



int noduri, muchii, componente_tari, a, b, ind = 1, ids[100005];

bool instack[100005];

int lowkey[100005];

vector<int> mat[100005];

vector<int> componente[100005];

stack<int> s;



void dfs(int node)

{

    s.push(node);

    instack[node] = 1;

    ids[node] = ind;

    lowkey[node] = ind;

    ++ind;

    for(int i = 0; i < mat[node].size(); ++i)

    {

        int next_node = mat[node][i];

        if(!ids[next_node])

        {

            dfs(next_node);

        }

        if(instack[next_node])

        {

            lowkey[node] = min(lowkey[node], lowkey[next_node]);

        }

    }

    if(ids[node] == lowkey[node])

    {

        while(!s.empty())

        {

            int next = s.top();

            componente[componente_tari].push_back(next);

            s.pop();

            instack[next] = 0;

            lowkey[next] = ids[node];

            if(node == next) break;

        }

        componente_tari++;

    }

}



int main()

{

    fin >> noduri >> muchii;

    for(int i = 1; i <= muchii; ++i)

    {

        fin >> a >> b;

        mat[a].push_back(b);

    }

    for(int node = 1; node <= noduri; ++node)

    {

        if(!ids[node])

        {

            dfs(node);

        }

    }

    fout << componente_tari << "\n";

    for(int i = 0; i < componente_tari; ++i)

    {

        for(int j = 0; j < componente[i].size(); ++j)

        {

            fout << componente[i][j] << " ";

        }

        fout << "\n";

    }

    return 0;

}
