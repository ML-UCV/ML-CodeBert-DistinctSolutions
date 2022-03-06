#include <fstream>
#include <algorithm>


using namespace std;



ifstream fin("apm.in");

ofstream fout("apm.out");



int n,m,i,sol[200005],tata[200005];



struct muchie{

    int x;

    int y;

    int cost;

} v[400005];



bool cmp(muchie a, muchie b)

{

    return a.cost < b.cost;

}



int rad(int nod)

{

    while (tata[nod] > 0)

        nod = tata[nod];

    return nod;

}



int main()

{

    fin >> n >> m;

    for (i=1; i<=m; i++)

        fin >> v[i].x >> v[i].y >> v[i].cost;

    sort(v+1, v+m+1, cmp);

    for (i=1; i<=n; i++)

        tata[i] = -1;

    int costmin = 0; int k = 0;

    for (i=1; i<=m; i++)

    {

        int rx = rad(v[i].x); int ry = rad(v[i].y);

        if (rx != ry)

        {

            sol[++k] = i; costmin += v[i].cost;

            if (tata[rx] < tata[ry])

            {

                tata[rx] += tata[ry];

                tata[ry] = rx;

            }

            else

            {

                tata[ry] += tata[rx];

                tata[rx] = ry;

            }

        }

    }

    fout << costmin << "\n" << n-1 << "\n";

    for (i=1; i<n; i++)

        fout << v[sol[i]].x << " " << v[sol[i]].y << "\n";

    return 0;

}
