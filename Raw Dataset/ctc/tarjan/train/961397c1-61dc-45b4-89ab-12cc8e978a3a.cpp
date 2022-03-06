#include <iostream>
#include <fstream>
#include <vector>
#include <stack>

using namespace std;

vector<int> G[100010];
vector<vector<int>> sol;
stack<int> s;
int N,M;
vector<int>lowlink(100010,-1);
vector<int>disc(100010,-1);
vector<bool>onStack(100010,false);


void DFS(int x) {
    static int index = 0;
    disc[x] = lowlink[x] = index;
    index++;
    s.push(x);
    onStack[x] = true;

    for (int elem : G[x]) {
        if (disc[elem] == -1)
            DFS(elem);
        if (onStack[elem])
            lowlink[x] = min(lowlink[x], lowlink[elem]);
    }
    if (disc[x] == lowlink[x]) {
        vector<int> aux;

        while (s.top() != x) {
            aux.push_back(s.top());
            onStack[s.top()] = 0;
            s.pop();
        }

        aux.push_back(s.top());
        onStack[s.top()] = 0;
        s.pop();

        sol.push_back(aux);
    }
}
int main()
{

    ifstream f ("ctc.in");
    ofstream g("ctc.out");

    f>> N >>M;
    int x,y;
    for( int i = 0; i < M; i++ )
    {
        f>>x>>y;
        G[x].push_back(y);

    }




    for(int i = 1; i <=N; i++)
        if ( disc[i] == -1)
            DFS(i);


    g << sol.size() << "\n";
    for (auto vec : sol){
        for (int x : vec)
            g<< x << " ";
        g << "\n";
    }
    return 0;
}
