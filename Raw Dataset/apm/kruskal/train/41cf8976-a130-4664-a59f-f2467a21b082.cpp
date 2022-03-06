#include <fstream>
#include <algorithm>


using namespace std;

ifstream fin ("apm.in");

ofstream fout ("apm.out");

struct muchie {

    int x;

    int y;

    int c;

};

muchie v[2*200001], sol[200001];

int n, m, t[200001], i, S, dim;

bool cmp (muchie i, muchie j)

{

    return i.c<j.c;

}

int rad (int nod)

{

    while (t[nod]>0)

        nod=t[nod];

    return nod;

}

int main()

{

    fin>>n>>m;

    for (i=1; i<=m; i++)

        fin>>v[i].x>>v[i].y>>v[i].c;

    sort (v+1, v+m+1, cmp);

    for (i=1; i<=n; i++)

        t[i]=-1;



    for (i=1; i<=m; i++)

    {

        int rx=rad(v[i].x);

        int ry=rad(v[i].y);

        if (rx!=ry)

        {

            if (-t[rx]>-t[ry])

            {

                t[rx]+=t[ry];

                t[ry]=rx;

            }

            else

            {

                t[ry]+=t[rx];

                t[rx]=ry;

            }

            S+=v[i].c;

            sol[++dim].x=v[i].x;

            sol[dim].y=v[i].y;

        }

        if (dim==n-1)

            break;

    }

    fout<<S<<"\n"<<n-1<<"\n";

    for (i=1; i<=dim; i++)

        fout<<sol[i].x<<" "<<sol[i].y<<"\n";

}
