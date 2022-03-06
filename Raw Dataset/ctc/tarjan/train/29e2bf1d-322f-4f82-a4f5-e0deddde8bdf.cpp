#include <bits/stdc++.h>




using namespace std;

ifstream fin("ctc.in");

ofstream fout("ctc.out");



const int lmt = 1e5+1;



int n,m,id,ids[lmt], low[lmt], stccCount;

vector<int> aList[lmt], rsp[lmt];

stack<int> stacc;

bool on_stacc[lmt];



void dfs(int nod)

{

    on_stacc[nod]=1;

    ids[nod]=low[nod]=++id;

    stacc.push(nod);



    vector<int>::iterator i;

    for(i=aList[nod].begin();i!=aList[nod].end();++i)

    {

        if(!ids[*i])

            dfs(*i);

        if(on_stacc[*i])

            low[nod]=min(low[nod], low[*i]);

    }

    if(low[nod]==ids[nod])

    {

        ++stccCount;

        while(!stacc.empty())

        {

            int poz = stacc.top();

            rsp[stccCount].push_back(poz);

            on_stacc[stacc.top()]=0;

            stacc.pop();



            if(poz==nod)

                break;

        }

    }

}



int main()

{

    fin>>n>>m;

    for(int i=1;i<=m;++i)

    {

        int x,y;

        fin>>x>>y;

        aList[x].push_back(y);

    }

    for(int i=1;i<=n;++i)

    {

        if(!ids[i])

            dfs(i);

    }

    fout<<stccCount<<'\n';

    for(int i=1;i<=stccCount;++i)

    {



            vector<int>::iterator j;

            for(j=rsp[i].begin();j!=rsp[i].end();++j)

                fout<<*j<<' ';



            fout<<'\n';

    }

    return 0;

}
