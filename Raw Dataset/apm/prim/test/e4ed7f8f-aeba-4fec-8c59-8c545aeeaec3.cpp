#include<fstream>
#include<vector>
#include<set>
using namespace std;

ifstream in("apm.in");

ofstream out("apm.out");

struct muc{

    int a,cost;

    bool operator<(const muc &other)const{

        return cost<other.cost;

    }

};

struct rez{

    int x,y;

}sol[200002];

vector<muc>lis[200002];

multiset<muc> s;

int v[200002],cor[200002],used[200002];

int n,m;

void insertie(int nod)

{

    for(int i=0;i<lis[nod].size();i++)

    {

        int x=lis[nod][i].a;

        int c=lis[nod][i].cost;

        if(c<v[x])

        {

            v[x]=c;

            s.insert({x,c});

            cor[x]=nod;

        }

    }

}

int main()

{

    int x,y,c,i,ct=0;

    in>>n>>m;

    for(i=1;i<=m;i++)

    {

        in>>x>>y>>c;

        lis[x].push_back({y,c});

        lis[y].push_back({x,c});

    }

    for(i=1;i<=n;i++)

    {

        v[i]=1001;

    }

    insertie(1);

    used[1]=1;

    for(i=2;i<=n;i++)

    {

        x=s.begin()->a;

        while(used[x]==1)

            s.erase(s.begin()),x=s.begin()->a;

        used[x]=1;

        insertie(x);

        ct+=v[x];

        sol[i-1]={x,cor[x]};

    }

    out<<ct<<'\n'<<n-1<<'\n';

    for(i=1;i<n;i++)

        out<<sol[i].x<<" "<<sol[i].y<<'\n';

    return 0;

}
