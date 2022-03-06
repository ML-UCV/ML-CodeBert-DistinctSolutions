#include <bits/stdc++.h>
int N, M;

std::vector <int> ADC[100005];

inline void addEdge(int u, int v) {

    ADC[u].push_back(v);

}



int nctc;

int low[100005], disc[100005], _time;

std::vector <int> ctc[100005];

bool inStack[100005];

std::stack <int> stack;

void DFS(int vertex) {

    disc[vertex] = low[vertex] = ++_time;

    inStack[vertex] = true;

    stack.push(vertex);



    for (auto &it:ADC[vertex]) {

        if (disc[it]) {

            if (inStack[it]) low[vertex] = std::min(low[vertex], low[it]);

        }

        else {

            DFS(it);

            low[vertex] = std::min(low[vertex], low[it]);

        }

    }



    if (low[vertex] == disc[vertex]) {

        while (!stack.empty() && stack.top() != vertex) {

            ctc[nctc].push_back(stack.top());

            inStack[stack.top()] = false;

            stack.pop();

        }

            ctc[nctc].push_back(stack.top());

            inStack[stack.top()] = false;

            stack.pop();

        ++ nctc;

    }

}



std::ifstream input (std::string("ctc")+".in");

std::ofstream output(std::string("ctc")+".out");



int main()

{

    input >> N >> M;

    for (int i=1, u, v; i<=M; ++i) input >> u >> v, addEdge(u, v);

    for (int i=1; i<=N; ++i)

        if (!disc[i]) DFS(i);

    output << nctc << '\n';

    for (int i=0; i<nctc; ++i, output << '\n')

        for (auto &it:ctc[i])

            output << it << ' ';



    return 0;

}
