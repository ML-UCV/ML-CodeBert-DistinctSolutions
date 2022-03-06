#include <bits/stdc++.h>
std::ifstream input (std::string("ctc")+".in");

std::ofstream output(std::string("ctc")+".out");



int N, M;

std::vector <int> ADC[100005];

inline void addEdge(int u, int v) {

    ADC[u].push_back(v);

}



std::stack <int> stack;

std::vector <int> cnx[100005];

int disc[100005], low[100005], _time, cnxCount;

bool inStack[100005];



void DFS(int vertex = 1) {

    stack.push(vertex);

    inStack[vertex] = true;

    disc[vertex] = low[vertex] = ++_time;



    for (auto &it:ADC[vertex]) {

        if (disc[it]) {

            if (inStack[it]) low[vertex] = std::min(low[vertex], low[it]);

        }

        else {

            DFS(it);

            low[vertex] = std::min(low[vertex], low[it]);

        }

    }



    if (disc[vertex] == low[vertex]) {

        while (!stack.empty() && stack.top() != vertex) {

            inStack[stack.top()] = false;

            cnx[cnxCount].push_back(stack.top());

            stack.pop();

        }

            inStack[stack.top()] = false;

            cnx[cnxCount].push_back(stack.top());

            stack.pop();

        ++ cnxCount;

    }

}



int main()

{

    input >> N >> M;

    for (int i=0, x, y; i<M; ++i)

        input >> x >> y, addEdge(x, y);



    for (int i=1; i<=N; ++i)

        if (!disc[i]) DFS(i);



    output << cnxCount << '\n';

    for (int i=0; i<cnxCount; ++i, output << '\n')

        for (auto &it:cnx[i])

            output << it << ' ';



    return 0;

}
