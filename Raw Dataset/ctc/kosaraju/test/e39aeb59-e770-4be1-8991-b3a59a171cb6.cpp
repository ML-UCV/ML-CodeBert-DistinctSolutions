#include <iostream>
#include <fstream>
#include <stack>
#include <vector>


using namespace std;



ifstream f("ctc.in");

ofstream g("ctc.out");



int n, m, nrc, viz[100005];

vector<int> graph[100005], gt[100005];

stack<int> S;

vector<int> cc[100005];



void read()

{

    int x, y;



    f>>n>>m;

    for(int i = 0; i < m; ++i)

    {

        f>>x>>y;

        graph[x].push_back(y);

        gt[y].push_back(x);

    }

}



void DFS(int vf)

{

    viz[vf] = -1;

    for(auto &v:graph[vf])

        if(viz[v] == 0)

            DFS(v);

    S.push(vf);

}



void DFSt(int vf, int nrc)

{

    viz[vf] = 1;

    for(auto &v:gt[vf])

        if(viz[v] < 0)

            DFSt(v, nrc);

    cc[nrc].push_back(vf);

}



void write()

{

    g<<nrc<<'\n';

    for(int i = 1; i <= nrc; ++i)

    {

        for(auto &v:cc[i])

            g<<v<<' ';

        g<<'\n';

    }

}







int main()

{

    read();

    for(int i = 1; i <= n; ++i)

        if(viz[i] == 0)

            DFS(i);

    while(!S.empty())

    {

        int vf = S.top();

        S.pop();

        if(viz[vf] > 0)

            continue;

        nrc++;

        DFSt(vf, nrc);

    }

    write();

    return 0;

}
