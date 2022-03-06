#include <fstream>
#include <algorithm>


using namespace std;



ifstream f("apm.in");

ofstream g("apm.out");





int tata[200005], c, ct, n, m;



struct nod

{

    int x, y, cost;

} v[400005], w[400005];



bool cmp(nod a, nod b)

{

    return a.cost < b.cost;

}



int rad(int x)

{

    if(tata[x] != x)

        tata[x] = rad(tata[x]);

    return tata[x];

}



void unire(int x, int y)

{

    x = rad(x);

    y = rad(y);

    if(x != y)

        if(x < y)

            tata[y] = x;

        else

            tata[x] = y;

}



int main()

{

    f >> n >> m;



    for(int i = 1; i <= n; i++)

        tata[i] = i;



    for(int i = 1; i <= m; i++)

        f >> v[i].x >> v[i].y >> v[i].cost;



    sort(v + 1, v + m + 1, cmp);



    for(int i = 1; i <= m; i++)

        if(rad(v[i].x) != rad(v[i].y))

        {

            unire(v[i].x, v[i].y);

            c += v[i].cost;

            w[++ct].x = v[i].x, w[ct].y = v[i].y;

        }



    g << c << '\n' << ct << '\n';



    for(int i = 1; i <= ct; i++)

        g << w[i].x << ' ' << w[i].y << '\n';



    return 0;

}
