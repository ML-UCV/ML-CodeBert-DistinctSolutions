#include<fstream>
#include<iostream>
#include<queue>
using namespace std;

ifstream fin ("apm.in");

ofstream fout ("apm.out");

pair<int, pair<int,int> > elem, aux;

priority_queue<pair<int,pair<int,int> >, vector<pair<int,pair<int,int> > >, greater<pair<int,pair<int,int> > > > pq;

queue<pair<int,int> > q2;

pair<int,int> elem2;

int n, m, t[200005], cost, nrm, viz[200005], auxx;

struct nod { int et,ct;

             nod *urm;

           } *l[200005];

void add_nod (int x, int y, int c)

{

    nod *q;

    q=new nod;

    q->et=y;

    q->ct=c;

    q->urm=l[x];

    l[x]=q;

}

void citire ()

{

    int x, y, co;

    fin>>n>>m;

    for (int i=1; i<=m; i++)

    {

        fin>>x>>y>>co;

        add_nod(y, x, co);

        add_nod(x, y, co);

    }

}

int main ()

{

    int i;

    citire();

    nod *q;

    q=l[1];

    while (q!=NULL)

    {

        elem.first=q->ct;

        elem.second.first=1;

        elem.second.second=q->et;

        pq.push(elem);

        q=q->urm;

    }

    i=1; nrm=0;

    viz[1]=1;

    t[1]=0;

    while (i<n)

    {

        elem=pq.top();

        pq.pop();

        if (viz[elem.second.second]==1)

            while (viz[elem.second.second]==1)

                 elem=pq.top(), pq.pop();

        cost+=elem.first;

        nrm++;

        viz[elem.second.second]=1;

        t[elem.second.second]=elem.second.first;

        int x;

        x=elem.second.second;

        q=l[x];

        while (q!=NULL)

        {

            aux.first=q->ct;

            aux.second.first=x;

            aux.second.second=q->et;

            pq.push(aux);

            q=q->urm;

        }

        elem2.first=elem.second.first;

        elem2.second=elem.second.second;

        q2.push(elem2);

        i++;

    }

    fout<<cost<<'\n'<<nrm<<'\n';

    for(i=1; i<=nrm; i++)

    {

        elem2=q2.front();

        q2.pop();

        fout<<elem2.first<<' '<<elem2.second<<'\n';

    }

}
