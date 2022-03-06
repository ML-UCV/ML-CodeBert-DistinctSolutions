#include <bits/stdc++.h>


using namespace std;



ifstream inf("ctc.in");

ofstream outf("ctc.out");



const int N=100010;



int n, m, disc[N], low[N], t;

bitset<N> b, vis;

vector<int> v[N];

stack<int> s;

vector<vector<int>> sol;



void ctc(int );



int main()

{

    inf>>n>>m;

    for(int i=1; i<=m; i++)

    {

        int x, y;

        inf>>x>>y;

        v[x].push_back(y);

    }

    for(int i=1; i<=n; i++)

        disc[i]=low[i]=-1;

    for(int i=1; i<=n; i++)

        if(!vis[i])

            ctc(i);

    outf<<sol.size()<<'\n';

    for(auto c:sol)

    {

        for(auto it:c)

            outf<<it<<' ';

        outf<<'\n';

    }

    return 0;

}



void ctc(int nod)

{

    vis[nod]=true;

    disc[nod]=low[nod]=++t;

    s.push(nod);

    b[nod]=1;

    for(auto it:v[nod])

    {

        if(disc[it]==-1)

        {

            ctc(it);

            low[nod]=min(low[nod], low[it]);

        }

        else if(b[it])

        {

            low[nod]=min(low[nod], disc[it]);

        }

    }



    if(low[nod]==disc[nod])

    {

        int tp=-1;

        vector<int> cctc;

        do

        {

            tp=s.top();

            s.pop();

            b[tp]=0;

            cctc.push_back(tp);

        }while(tp!=nod);

        sol.push_back(cctc);

    }

}
