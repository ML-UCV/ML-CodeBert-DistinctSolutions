#include <bits/stdc++.h>


using namespace std;

const int NMAX=100005;

ifstream in("ctc.in");

ofstream out("ctc.out");

vector <int>g[NMAX],c;

stack<int>s;

vector<vector<int>>ans;

int n,m,f,low[NMAX],in_stack[NMAX],val[NMAX];

int idx=1;

void tarjan(int node){

    val[node]=low[node]=idx;

    s.push(node), in_stack[node]=1;

    idx++;

    for(auto y:g[node]){

        if(!val[y])

            tarjan(y),low[node]=min(low[node],low[y]);

       else if(in_stack[y])

             low[node]=min(low[node],low[y]);

    }

    if(val[node]==low[node]){

         c.clear();

         int n;

         do{

            c.push_back(n=s.top());

            in_stack[n]=0;

            s.pop();

         }while(n!=node);

         ans.push_back(c);

       }

}

int main()

{

    in>>n;

    int x,y;

    for(in>>m;m>0;m--){

        in>>x>>y;

        g[x].push_back(y);

    }

    for(int i=1;i<=n;i++){

        if(!val[i])

            tarjan(i);

    }

    out<<ans.size()<<'\n';

    for(int i=0;i<ans.size();i++){

        for(auto y:ans[i])

            out<<y<<" ";

        out<<'\n';

    }

    return 0;

}
