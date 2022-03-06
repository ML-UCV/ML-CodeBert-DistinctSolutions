#include <iostream>
#include <bits/stdc++.h>
#include <iostream>


using namespace std;

ifstream in ("ctc.in");

ofstream out("ctc.out");

vector<int> graf[100005];

int low[100005],id[100005];

bool onstack[100005];

vector<vector<int>> sol;

stack<int> s;

int n,m,a,b;

int idc = 0;

void dfs(int x)

{

    id[x] = idc;

    low[x] = idc++;

    s.push(x);

    onstack[x] = 1;

    for(auto it:graf[x]){

        if(id[it]==-1)

            dfs(it);

        if(onstack[it])

            low[x] = min(low[x],low[it]);

    }

    if(id[x] == low[x]){

        int node;

        vector<int> aux;

        do{

            node = s.top();

            aux.push_back(node);

            low[node] = id[x];

            onstack[node] = 0;

            s.pop();

        }while(node != x);

        sol.push_back(aux);

    }

}

int main()

{

    in>>n>>m;

    for(int i=0;i<m;i++){

        in>>a>>b;

        graf[a-1].emplace_back(b-1);

    }

    for(int i=0;i<n;i++)

    {

        low[i] = 0;

        id[i] = -1;

        onstack[i] = 0;

    }



    for(int i=0;i<n;i++)

        if(id[i]==-1)

            dfs(i);

    out<<sol.size()<<'\n';

    for(auto it:sol){

        for(auto j:it)

            out<<j+1<<' ';

        out<<'\n';

    }

    return 0;

}
