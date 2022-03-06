#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>




using namespace std;



FILE *fin=fopen("dmin.in","r");

FILE *fout=fopen("dmin.out","w");



const double eps=1e-6;

vector <int> v[1510];

vector <double> cost[1510];

int i,j,n,m,nrd[1510];

double dmin[1510];

queue <int> q;

bool inq[1510];



int main()

{

    fscanf(fin,"%d%d",&n,&m);

    for (i=1; i<=m; i++)

    {

        int a,b,c;

        fscanf(fin,"%d%d%d",&a,&b,&c);

        v[a].push_back(b);

        v[b].push_back(a);

        cost[a].push_back(log(c));

        cost[b].push_back(log(c));

    }

    q.push(1);

    nrd[1]=1;

    while (!q.empty())

    {

        int x=q.front();

        inq[x]=0;

        q.pop();

        for (i=0; i<v[x].size(); i++)

        {

            int vecin=v[x][i];

            double pret=cost[x][i];

            if (vecin!=1)

            {if (dmin[vecin]==0)

            {

                dmin[vecin]=dmin[x]+pret;

                nrd[vecin]=nrd[x];

                inq[vecin]=1;

                q.push(vecin);

            }

            else

            {





                if (dmin[x]+pret-dmin[vecin]<eps&&dmin[x]+pret-dmin[vecin]>-eps)

                {

                    nrd[vecin]=(nrd[vecin]+nrd[x])%104659;

                }

                else if (dmin[x]+pret+eps<dmin[vecin])

                {

                    dmin[vecin]=dmin[x]+pret;

                    if (inq[vecin]==0)

                    q.push(vecin),inq[vecin]=1;

                    nrd[vecin]=nrd[x];

                }

            }

            }

        }

    }

    for (i=2; i<=n; i++)

        fprintf(fout,"%d ",nrd[i]%104659);

    fprintf(fout,"\n");

}
