#include <bits/stdc++.h>


using namespace std;



const int maxSize=100005;



ifstream fin("ctc.in");

ofstream fout("ctc.out");



int n, m;

vector<int>nodes[maxSize], transpus[maxSize];

stack<int>s;

vector<int> ctc[maxSize];

int visited[maxSize];

int k;



void read(){

    fin>>n>>m;

    int x, y;

    for(int i=0; i<m; i++){

        fin>>x>>y;

        nodes[x].push_back(y);

        transpus[y].push_back(x);

    }

}



void dfs(int node){

    visited[node] = 1;

    for(auto it:nodes[node])

        if(visited[it] == 0)

            dfs(it);

    s.push(node);

}



void dfst(int node){

    visited[node] = -1;

    for(auto it:transpus[node])

        if(visited[it] > 0)

            dfst(it);

    ctc[k].push_back(node);

}



void da(){

    for(int i=1; i<=n; i++)

        if(visited[i] == 0)

            dfs(i);

}



void da2(){

    while(!s.empty()){

        int v = s.top();

        s.pop();

        if(visited[v] < 0)

            continue;

        k++;

        dfst(v);

    }

}



void print(){

    fout<<k<<'\n';

    for(int i=1; i<=k; i++){

        for(auto it:ctc[i])

            fout<<it<<' ';

        fout<<'\n';

    }

}

int main()

{

    read();

    da();

    da2();

    print();

    return 0;

}
