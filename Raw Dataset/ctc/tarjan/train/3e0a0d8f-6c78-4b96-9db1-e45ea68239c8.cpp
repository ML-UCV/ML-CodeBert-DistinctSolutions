#include <fstream>
#include <vector>


using namespace std;



ifstream cin("ctc.in");

ofstream cout("ctc.out");



vector<int>adj[100002];

vector<int>stiva;

vector<int>scc[100002];

int nrc,disc[100002],low[100002],cc[100002],t;



void dfs(int n1)

{

    disc[n1]=low[n1]=++t;

    stiva.push_back(n1);

    for(vector<int>::iterator it=adj[n1].begin();it!=adj[n1].end();it++)

    {

        int n2=*it;

        if(!cc[n2])

        {

            if(!disc[n2])

                dfs(n2);

            low[n1]=min(low[n1],low[n2]);

        }

    }

    if(disc[n1]==low[n1])

    {

        nrc++;

        while(stiva.back()!=n1)

        {

            scc[nrc].push_back(stiva.back());

            cc[stiva.back()]=nrc;

            stiva.pop_back();

        }

        scc[nrc].push_back(n1);

        cc[n1]=nrc;

        stiva.pop_back();

    }

}



int main()

{

    int n,m,i,x,y;

    cin>>n>>m;

    for(i=1; i<=m; i++)

    {

        cin>>x>>y;

        adj[x].push_back(y);

    }

    for(i=1; i<=n; i++)

    {

        if(!disc[i])

            dfs(i);

    }

    cout<<nrc<<'\n';

    for(i=1;i<=nrc;i++)

    {

        for(vector<int>::iterator it=scc[i].begin();it!=scc[i].end();it++)

            cout<<*it<<' ';

        cout<<'\n';

    }

    return 0;

}
