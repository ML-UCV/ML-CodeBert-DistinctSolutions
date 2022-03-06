#include <fstream>
#include <vector>
#include <set>
using namespace std;

ifstream fin ("apm.in");

ofstream fout ("apm.out");

struct ura1

{

    int nod,cost;

    bool operator <(const ura1 &other)const

    {

        return cost<other.cost;

    };

};

struct ura2

{

    int x,y;

};

vector <ura1> l[200005];

multiset <ura1> s;

ura2 sol[200005];

int v[200005],cor[200005],vc[200005];

void apm (int x)

{

    int i,y,c;

    for (i=0;i<l[x].size();i++)

    {

        y=l[x][i].nod;

        c=l[x][i].cost;

        if (v[y]>c)

        {

            v[y]=c;

            s.insert(l[x][i]);

            cor[y]=x;

        }

    }

}

int main ()

{

    int rez=0,n,m,i,x,y,c,nod;

    fin>>n>>m;

    for (i=1;i<=m;i++)

    {

        fin>>x>>y>>c;

        l[x].push_back({y,c});

        l[y].push_back({x,c});

    }

    for (i=2;i<=n;i++)

    {

        v[i]=2000000000;

        s.insert({i,v[i]});

    }

    apm(1);

    vc[1]=1;

    for (i=1;i<n;i++)

    {

        nod=s.begin()->nod;

        while (vc[nod])

        {

            s.erase(s.begin());

            nod=s.begin()->nod;

        }

        s.erase(s.begin());

        vc[nod]=1;

        apm(nod);

        rez+=v[nod];

        sol[i]={nod,cor[nod]};

    }

    fout<<rez<<'\n'<<n-1<<'\n';

    for (i=1;i<n;i++)

        fout<<sol[i].x<<" "<<sol[i].y<<'\n';

    return 0;

}
