#include <bits/stdc++.h>


using namespace std;

int n, m, i, j, v, cnt, out;

int ctc[201], sol[201];

stack<int> s;

bool check[201], ins[201], done[201];

vector<int> graph[201], ctclist[201];

pair<int, int> p[201];



void read();

void solve();

void write();

int nt(int node);

void dfs(int node);

int main()

{

    read();

    solve();

    write();

    return 0;

}

void read(){

    freopen("party.in", "r", stdin);

    scanf("%d%d", &n, &m);

    for(i=1; i<=m; ++i){

        int x, y, z;

        scanf("%d%d%d", &x, &y, &z);

        switch(z){

            case 0:{graph[nt(x)].push_back(y); graph[nt(y)].push_back(x); break;}

            case 1:{graph[nt(x)].push_back(nt(y)); graph[y].push_back(x); break;}

            case 2:{graph[nt(y)].push_back(nt(x)); graph[x].push_back(y); break;}

            default:{

                graph[x].push_back(nt(y));

                graph[y].push_back(nt(x));

            }

        }

    }

    return;

}

void solve(){

    for(i=1; i<=2*n; ++i) if(!check[i]) dfs(i);

    for(i=v; i>=1; --i) if(!done[i]){

        int ch=ctc[nt(ctclist[i][0])];

        done[i]=done[ch]=true;

        for(auto j:ctclist[i]) sol[j]=0;

        for(auto j:ctclist[ch]) sol[j]=1;

    }

    for(i=1; i<=n; ++i) if(sol[i]) ++out;

    return;

}

void write(){

    freopen("party.out", "w", stdout);

    printf("%d\n", out);

    for(i=1; i<=n; ++i) if(sol[i]) printf("%d\n", i);

}

int nt(int node){

    if(node<=n) return node+n;

    return node-n;

}

void dfs(int node){

    ++cnt; s.push(node);

    p[node]={cnt, cnt};

    check[node]=ins[node]=true;

    for(auto i:graph[node]){

        if(!check[i]){

            dfs(i);

            p[node].second=min(p[node].second, p[i].second);

        }

        else if(ins[i]) p[node].second=min(p[node].second, p[i].first);

    }

    if(p[node].first==p[node].second){

        ++v;

        while(s.top()!=node){

            ctclist[v].push_back(s.top());

            ctc[s.top()]=v;

            ins[s.top()]=false;

            s.pop();

        }

        ctclist[v].push_back(s.top());

        ctc[s.top()]=v;

        ins[s.top()]=false;

        s.pop();

    }

    return;

}
