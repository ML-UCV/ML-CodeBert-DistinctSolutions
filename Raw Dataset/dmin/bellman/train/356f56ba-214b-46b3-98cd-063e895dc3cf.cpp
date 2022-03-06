# include <fstream>
# include <algorithm>
# include <cmath>
# include <vector>
# include <queue>
using namespace std;

ifstream f("dmin.in");

ofstream g("dmin.out");

vector <pair <int, double> > v[1505];

queue <int> q;

int i,j,n,m,x,y;

int drumuri[1505], ap[1505];

double dist[1505], cost;

void BF ()

{

    int i,j,k,urm;

    double cost;



    for (i=2; i<=n; ++i) dist[i]=999999999;

    q.push(1); drumuri[1]=1;

    while (! q.empty()) {

        k=q.front(); q.pop(); ap[k]=0;



        for (i=0; i<v[k].size(); ++i) {

            urm=v[k][i].first;

            cost=v[k][i].second;



            if (dist[k] + cost + 1e-10 <= dist[urm]) {

                dist[urm]=dist[k] + cost;

                drumuri[urm]=drumuri[k];



                if (!ap[urm]) {ap[urm]=1; q.push(urm);}

            }

            else if (fabs(dist[k] + cost - dist[urm]) < 1e-10) {

                drumuri[urm]+=drumuri[k];



                if (!ap[urm]) {ap[urm]=1; q.push(urm);}

            }



            if (drumuri[urm]>=104659) drumuri[urm]-=104659;

        }

    }

}

int main ()

{

    f>>n>>m;

    for (i=1; i<=m; ++i) {

        f>>x>>y>>cost; int Q=cost;

        cost=log(cost);



        v[x].push_back(make_pair(y, cost));

        v[y].push_back(make_pair(x, cost));

    }

    BF ();



    for (i=2; i<=n; ++i)

        g<<drumuri[i]<<" ";

    g<<"\n";



    return 0;

}
