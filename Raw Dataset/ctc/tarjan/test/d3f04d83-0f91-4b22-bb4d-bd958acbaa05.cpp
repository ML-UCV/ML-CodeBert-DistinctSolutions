#include <bits/stdc++.h>


using namespace std;

const int NMAX = 100005;

ifstream fin("ctc.in");

ofstream fout("ctc.out");

int lowlink[NMAX];

int ids[NMAX];

bool inStack[NMAX];

int groupCounter = 1;





int n, m;

vector<int> graf[NMAX];

stack<int> stac;

vector<vector<int>> components;

void ctc(int node)

{

    lowlink[node] = groupCounter++;

    ids[node] = lowlink[node];

    inStack[node] = true;

    stac.push(node);

    for(auto i:graf[node])

    {

        if(ids[i]==0) ctc(i);

        if(inStack[i]) lowlink[node]=min(lowlink[node], lowlink[i]);

    }

    if(lowlink[node]==ids[node])

    {

        vector<int> component;

        while(stac.top()!=node)

        {

            component.push_back(stac.top());

            lowlink[stac.top()]=lowlink[node];

            inStack[stac.top()]=false;

            stac.pop();

        }

        component.push_back(node);

        inStack[node]=false;

        stac.pop();

        components.push_back(component);

    }

}

int main()

{

    fin>>n>>m;

    while(m--)

    {

        int a, b;

        fin>>a>>b;

        graf[a].push_back(b);

    }

    for(int i = 1;i<=n;i++)

    {

        if(ids[i]==0)

            ctc(i);

    }

    fout<<components.size()<<'\n';

    for(auto c:components)

    {

        for(auto i:c)

            fout<<i<<" ";

        fout<<'\n';

    }

    return 0;

}
