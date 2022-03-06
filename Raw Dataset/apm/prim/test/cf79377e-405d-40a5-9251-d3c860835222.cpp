#include <fstream>
#include <set>
#include <vector>
using namespace std;

ifstream in("apm.in");

ofstream out("apm.out");

struct ura

{

    int nod,cost;

    bool operator<(const ura &other) const{

        return cost<other.cost;

    }

};

struct ura2

{

    int x,y;

};

ura2 sol[200001];

multiset <ura> s;

vector <ura> lista[200001];

int v[2000001];

int cor[200002];

bool used[200002];

void intro_apm(int nod)

{

    int i;

    for(i=0;i<lista[nod].size();i++)

    {

        int x=lista[nod][i].nod;

        int cst=lista[nod][i].cost;

        if(cst<v[x])

        {

            v[x]=cst;

            s.insert({x,cst});

            cor[x]=nod;

        }

    }

}

int main()

{

    int n,m,cost,i,n1,n2;

    in>>n>>m;

    for(i=1;i<=m;i++)

    {

        in>>n1>>n2>>cost;

        lista[n2].push_back({n1,cost});

        lista[n1].push_back({n2,cost});

    }

    for(i=1;i<=n;i++)

    {

        v[i]=10001;

    }

    intro_apm(1);

    used[1]=1;

    int nr,costotal=0;

    for(i=2;i<=n;i++)

    {

        nr=s.begin()->nod;

        while(used[nr]==1)

        {

            s.erase(s.begin());

            nr=s.begin()->nod;

        }

        used[nr]=1;

        intro_apm(nr);

        costotal+=v[nr];

        sol[i-1]={nr,cor[nr]};

    }

    out<<costotal<<'\n'<<n-1<<'\n';

    for(i=1;i<n;i++)

    {

        out<<sol[i].x<<" "<<sol[i].y<<"\n";

    }

    return 0;

}
