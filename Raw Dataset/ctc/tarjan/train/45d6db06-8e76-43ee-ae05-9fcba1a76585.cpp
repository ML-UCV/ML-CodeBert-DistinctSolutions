#include <bits/stdc++.h>
using namespace std;



ifstream fin("ctc.in");

ofstream fout("ctc.out");



const int N_MAX = 1e5 + 1;





int N, M;

vector<vector<int>> graph(N_MAX, vector<int>());





vector<vector<int>> answer;

int id[N_MAX], low[N_MAX], t;

bool onStack[N_MAX];

stack<int> node_stack;



void dfs_scc(int node)

{

    ++t;

    id[node] = t;

    low[node] = t;

    onStack[node] = true;

    node_stack.push(node);



    for(auto& next : graph[node])

    {

        if(id[next] == 0)

            dfs_scc(next);



        if(onStack[next])

            low[node] = min(low[node], low[next]);

    }



    if(id[node] == low[node])

    {

        answer.push_back(vector<int>());



        while(node_stack.top() != node)

        {

            answer.back().push_back(node_stack.top());

            onStack[node_stack.top()] = false;

            node_stack.pop();

        }



        answer.back().push_back(node_stack.top());

        onStack[node_stack.top()] = false;

        node_stack.pop();

    }

}



int main()

{

    fin >> N >> M;



    for(int x, y, i = 1; i <= M; ++i)

    {

        fin >> x >> y;

        graph[x].push_back(y);

    }



    for(int i = 1; i <= N; ++i)

    {

        if(id[i] == 0)

        {

            dfs_scc(i);

        }

    }





    fout << answer.size() << '\n';



    for(auto& ctc : answer)

    {

        for(auto& node : ctc)

        {

            fout << node << ' ';

        }



        fout << '\n';

    }

}
