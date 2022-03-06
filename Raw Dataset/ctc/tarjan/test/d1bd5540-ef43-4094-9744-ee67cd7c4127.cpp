#include <bits/stdc++.h>


using namespace std;



vector<vector<int>> graph(100000 + 1, vector<int>());

int N, M;

stack<int> node_stack;

bool viz[100000 + 1];

bool onStack[100000 + 1];



int id[100000 + 1], low[100000 + 1], counter = 0;



vector<vector<int>> ctcs;



void dfs(int node)

{

    id[node] = low[node] = ++counter;

    viz[node] = onStack[node] = true;



    node_stack.push(node);



    for(auto& next : graph[node])

    {

        if(viz[next] == false)

            dfs(next);





        if(onStack[next] == true)

            low[node] = min(low[node], low[next]);

    }



    if(low[node] == id[node])

    {

        vector<int> ctc;

        int x;

        do {

            x = node_stack.top();

            node_stack.pop();

            onStack[x] = false;

            ctc.push_back(x);



        }while(x != node);





        ctcs.push_back(ctc);

    }

}



int main()

{

    ifstream fin("ctc.in");

    ofstream fout("ctc.out");



    fin >> N >> M;



    for(int i = 1; i <= M; ++i){

        int x, y;

        fin >> x >> y;

        graph[x].push_back(y);

    }



    for(int i = 1; i <= N; ++i)

    {

        if(viz[i] == false)

            dfs(i);

    }



    fout << ctcs.size() << '\n';



    for(auto& ctc : ctcs){

        for(auto& node : ctc)

            fout << node << ' ';



        fout << '\n';

    }

}
