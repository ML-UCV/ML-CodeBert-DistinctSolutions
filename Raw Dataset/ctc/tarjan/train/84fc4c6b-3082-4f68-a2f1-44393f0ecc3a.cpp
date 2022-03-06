#include <bits/stdc++.h>


int c, N, M;

std::vector <std::vector <int>> graph;

inline void addEdge(int u, int v) {

    graph[u].push_back(v);

}



class SCCCalculator {

public:

    SCCCalculator (std::vector <std::vector <int>> &graph) { calculate(graph); }

    void calculate(std::vector <std::vector <int>> &graph) {

        _time = 0;

        N = graph.size();

        low .resize(graph.size(), 0);

        disc .resize(graph.size(), 0);

        inStack.resize(graph.size(), false);

        for (int i=0; i<graph.size(); ++i)

            if (!disc[i]) DFS(graph, i);

    }



    int getSize() { return components.size(); }

    std::vector <std::vector <int>> getComponents() { return components; }



    std::vector <std::vector <int>> getSCCGraph(std::vector <std::vector <int>>& graph) {

        std::vector <std::vector <int>> SCCGraph;

        SCCGraph.resize(components.size());

        std::vector <bool> seen(components.size(), false);

        for (int i=0; i<components.size(); ++i) {

            for (auto &u:components[i]) {

                for (auto &it:graph[u])

                    if (comp[it] != i && !seen[comp[it]])

                        SCCGraph[i].push_back(comp[it]), seen[comp[it]] = true;

            }

            for (auto &it:SCCGraph[i]) seen[it] = false;

        } return SCCGraph;

    }



private:

    void DFS(std::vector <std::vector <int>> &graph, int vertex) {

        disc[vertex] = low[vertex] = ++_time;

        inStack[vertex] = true;

        stack.push(vertex);

        for (auto &it:graph[vertex]) {

            if (!disc[it]) { DFS(graph, it);

                low[vertex] = std::min(low[vertex], low[it]);

            } else

            if (inStack[it]) low[vertex] = std::min(low[vertex], low[it]);

        }

        if (low[vertex] == disc[vertex]) addComponent(vertex);

    }



    void addComponent(int vertex) {

        components.push_back(std::vector <int>());

        while (!stack.empty() && stack.top() != vertex) {

            components.back().push_back(stack.top());

            inStack[stack.top()] = false;

            stack.pop();

        } components.back().push_back(stack.top());

            inStack[stack.top()] = false;

            stack.pop();

    }



    int _time;

    int N;

    std::vector <int> low, disc, comp;

    std::vector <std::vector <int>> components;

    std::vector <bool> inStack;

    std::stack <int> stack;

};



std::ifstream input ("ctc.in");

std::ofstream output("ctc.out");



int main()

{

    input >> N >> M;

    graph.resize(N, std::vector <int>());

    for (int i=0, u, v; i<M; ++i) input >> u >> v, addEdge(u-1, v-1);



    SCCCalculator calc(graph);

    output << calc.getSize() << '\n';

    for (auto &it:calc.getComponents()) {

        for (auto &it2:it) output << it2+1 << ' ';

        output << '\n';

    }



    return 0;

}
