#include <iostream>
#include <fstream>
#include <stack>
#include <vector>


using namespace std;



ifstream f("ctc.in");

ofstream g("ctc.out");



int index = 1;

int n, m, nrc;

int isInStack[100005], viz[100005], lowlink[100005], idx[100005];

vector<int> graph[100005];

vector<int> CC[100005];

stack<int> S;



void read()

{

    int x, y;



    f>>n>>m;

    for(int i = 0; i < m; ++i)

    {

        f>>x>>y;

        graph[x].push_back(y);

    }

}





void addCC()

{

    nrc++;

    int top;

    do{

        top = S.top();

        CC[nrc].push_back(top);

        S.pop();

        isInStack[top] = 0;

    }while(lowlink[top] != idx[top]);



}
void solve(int nod)

{

    S.push(nod);

    isInStack[nod] = 1;

    viz[nod] = 1;

    idx[nod] = index;

    lowlink[nod] = index;

    index ++;



    for(auto &v:graph[nod])

    {

        if(viz[v] == 0)

        {

            solve(v);

            lowlink[nod] = min(lowlink[nod], lowlink[v]);

        }

        else{

            if(isInStack[v] == 1)

                lowlink[nod] = min(lowlink[nod], lowlink[v]);

        }

    }



    if(lowlink[nod] == idx[nod])

    {

        addCC();

    }



}
void tarjan()

{

    for(int i = 1; i <= n; ++i)

        if(viz[i] == 0)

            solve(i);

}





void write()

{

    g<<nrc<<"\n";

    for(int i = 1; i <= nrc; ++i)

    {

        for(auto &v:CC[i])

            g<<v<<" ";

        g<<'\n';

    }

}
int main()

{

    read();

    tarjan();

    write();

    return 0;

}
