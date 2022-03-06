#include <iostream>
#include <fstream>
#include <stack>
#include <vector>
#include <algorithm>


using namespace std;
const int N_MAX = 1e5 + 1;



struct TarjanVertex{

    int index, tarjanIndex = -1, lowlink;

    bool onStack = false;

};



vector <int> graph[N_MAX];

stack <int> stk;

vector <TarjanVertex> graphVertexes;

vector <vector <int>> solutions;



int nextAvailableIndex = 1;



ifstream fin("ctc.in");

ofstream fout("ctc.out");



void Tarjan(int nodeIndex)

{

    graphVertexes[nodeIndex].tarjanIndex = nextAvailableIndex;

    graphVertexes[nodeIndex].lowlink = nextAvailableIndex;

    nextAvailableIndex++;

    stk.push(nodeIndex);

    graphVertexes[nodeIndex].onStack = true;



    for(auto neighborIndex: graph[graphVertexes[nodeIndex].index])

    {

        if(graphVertexes[neighborIndex].tarjanIndex == -1)

        {

            Tarjan(graphVertexes[neighborIndex].index);

            graphVertexes[nodeIndex].lowlink = min(graphVertexes[neighborIndex].lowlink, graphVertexes[nodeIndex].lowlink);

        }

        else if (graphVertexes[neighborIndex].onStack == true)

        {

            graphVertexes[nodeIndex].lowlink = min(graphVertexes[neighborIndex].tarjanIndex, graphVertexes[nodeIndex].lowlink);

        }

    }



    if(graphVertexes[nodeIndex].tarjanIndex == graphVertexes[nodeIndex].lowlink)

    {

        vector <int> sol;

        int neighborIndex;

        do

        {

            neighborIndex = stk.top();

            sol.push_back(neighborIndex);

            stk.pop();

            graphVertexes[neighborIndex].onStack = false;

        } while (neighborIndex != nodeIndex);



        solutions.push_back(sol);

    }

}



int main()

{

    int n, m;



    fin >> n >> m;



    graphVertexes.resize(n + 1);

    for(int i = 1; i <= n; i++)

    {

        graphVertexes[i].index = i;

    }



    for(int i = 0, st, dr; i < m; i++)

    {

        fin >> st >> dr;

        graph[st].push_back(dr);

    }



    for(int i = 1; i <= n; i++)

    {

        if(graphVertexes[i].tarjanIndex != -1)

            continue;



        Tarjan(i);

    }





    fout << solutions.size() << '\n';



    for(auto sol: solutions)

    {

        for(auto val: sol)

        {

            fout << val << ' ';

        }



        fout << '\n';

    }



    return 0;

}
