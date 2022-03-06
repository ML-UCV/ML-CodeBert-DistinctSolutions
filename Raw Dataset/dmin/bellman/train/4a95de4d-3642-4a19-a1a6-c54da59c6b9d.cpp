#include<fstream>
#include<cmath>
#include<vector>
#include<set>
#include<utility>







using namespace std;

ifstream first("dmin.in");
ofstream g("dmin.out");

int n, m, nr[1510], vz[1510];
double d[1510];

struct muchie
{
    int nod;
    double cost;
};

vector<muchie> a[1510];

set< pair<double, int> > second;

void Citeste()
{
    int i, x, y;
    muchie r;

    first>>n>>m;

    for (i=1; i<=m; ++i)
    {
        first>>x>>y>>r.cost;

        r.nod=y; a[x].push_back(r);
        r.nod=x; a[y].push_back(r);
    }
}

void Initializeaza()
{
    int i;

    for (i=1; i<=n; ++i) d[i]=2500000000000.0;

    d[1]=0.0; nr[1]=1;

    second.insert( make_pair(0.0, 1) );
}

void Solve()
{
    int i, gata;
    double val;
    muchie r;
    pair<double, int> pr;
    set<pair<double, int> > :: iterator is;

    do
    {
        gata=0;

        while (!second.empty() && !gata)
        {
            is=second.begin();
            pr=*is;
            if (!vz[pr.second]) gata=1;
            second.erase(is);
        }

        if (gata)
        {
            vz[pr.second]=1;
            for (i=0; i<a[pr.second].size(); ++i)
            {
                r=a[pr.second][i];

                if (!vz[r.nod])
                {
                    val=log(r.cost)+pr.first;

                    if (d[r.nod]-val>0.0000000001)
                    {
                        d[r.nod]=val;
                        second.insert(make_pair(val, r.nod));
                        nr[r.nod]=nr[pr.second];
                    }
                    else
                        if (fabs(d[r.nod]-val)<0.0000000001) nr[r.nod]=(nr[r.nod]+nr[pr.second])%104659;
                }
            }
        }

    }while (gata);

    for (i=2; i<=n; ++i) g<<nr[i]<<" ";
}

int main()
{
    Citeste();

    Initializeaza();

    Solve();

    first.close();
    g.close();
    return 0;
}
