#include <bits/stdc++.h>
using namespace std;

ifstream in("ctc.in");

ofstream out("ctc.out");

const int MAX=100006;

vector<int>graf1[MAX];

vector<int>graf2[MAX];

vector<int>cc[MAX];

int n,m,st,dr,cnt,nr,v[MAX];

bool vizs[MAX],vizp[MAX];



void dfss(int x)

{

    vizs[x]=true;

    for(int i=0;i<graf1[x].size();i++)

    {

        int y=graf1[x][i];

        if(vizs[y]==false) dfss(y);

    }

    v[++nr]=x;

}



void dfsp(int x)

{

    cc[cnt].push_back(x);

    vizp[x]=true;

    for(int i=0;i<graf2[x].size();i++)

    {

        int y=graf2[x][i];

        if(vizp[y]==false) dfsp(y);

    }



}

int main()

{

    in>>n>>m;

    for(int i=1;i<=m;i++)

    {

        in>>st>>dr;

        graf1[st].push_back(dr);

        graf2[dr].push_back(st);

    }



    for(int i=1;i<=n;i++)

    {

        if(vizs[i]==false) dfss(i);

    }



    for(int i=nr;i>=1;i--)

    {

        if(vizp[v[i]]==false)

        {

            cnt++;

            dfsp(v[i]);

        }

    }



    out<<cnt<<"\n";

    for(int i=1;i<=cnt;i++)

    {

        for(int j=0;j<cc[i].size();j++) out<<cc[i][j]<<" ";

        out<<'\n';

    }

    return 0;

}
