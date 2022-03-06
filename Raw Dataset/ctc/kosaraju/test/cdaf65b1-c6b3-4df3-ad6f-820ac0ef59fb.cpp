#include <iostream>
#include <math.h>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <iomanip>
#include <stdlib.h>
#include <fstream>
#include <algorithm>
#include <string>
#include <set>
#include <cstring>
#include <map>


using namespace std;
ifstream f("ctc.in");
ofstream g("ctc.out");
vector<int> G[100001];
vector<int> drumuri_intoare[100001];
int viz[100001];
stack<int> stiva;
int N , M;
int nrctc;
vector<int>ctc[100001];
void dfs(int nod)
{
    viz[nod] = 1;
    for(auto it = G[nod].begin(); it!=G[nod].end();it++)
    {
        if(!viz[*it])
            dfs(*it);
    }
    stiva.push(nod);
}
void dfs2(int nod)
{
    viz[nod] = 2;
    ctc[nrctc].push_back(nod);
    for(auto it = drumuri_intoare[nod].begin(); it!=drumuri_intoare[nod].end();it++)
    {
        if(viz[*it] == 1)
        {

            dfs2(*it);
        }
    }
}
int main()
{
    f>>N>>M;
    for(int i=1;i<=M;i++)
    {
        int a , b;
        f>>a>>b;
        G[a].push_back(b);
        drumuri_intoare[b].push_back(a);
    }
    for(int i=1;i<=N;i++)
    {
        if(!viz[i])
            dfs(i);
    }
    while(!stiva.empty())
    {
        int nod = stiva.top();
        if(viz[nod] == 1)
        {
            nrctc++;
            dfs2(nod);
        }
        stiva.pop();
    }
    g<<nrctc<<endl;
    for(int i=1;i<=nrctc;i++)
    {for(int j=0;j<ctc[i].size();j++)
    g<<ctc[i][j]<<" ";
    g<<'\n';}
    return 0;
}
