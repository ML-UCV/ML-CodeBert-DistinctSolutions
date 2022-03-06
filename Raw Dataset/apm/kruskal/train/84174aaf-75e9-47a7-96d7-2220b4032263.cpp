#include <fstream>
#include <algorithm>
#include <vector>


using namespace std;



ifstream f ("apm.in");

ofstream g ("apm.out");



int n, m;



int nrm, sum;



int multime[200005];



pair < int, int > sol[200005];



bool used[200005];



struct muchie {

  int x, y, cost;

}v[400005];



vector < int > padure[200005];



bool Cmp (muchie a, muchie b)

{

    if (a.cost < b.cost)

        return true;

    return false;

}



void Uneste (int x, int y)

{

    if (padure[y].size() <= padure[x].size())

    {

        for (int i=0; i<padure[y].size(); i++)

        {

            int val = padure[y][i];

            padure[x].push_back(val);

            multime[val] = x;

        }

        padure[y].clear();

    }

    else

    {

        for (int i=0; i<padure[x].size(); i++)

        {

            int val = padure[x][i];

            padure[y].push_back(val);

            multime[val] = y;

        }

        padure[x].clear();

    }

}



int main()

{

    f >> n >> m;

    for (int i=1; i<=m; i++)

    {

        f >> v[i].x >> v[i].y;

        f >> v[i].cost;

    }



    for (int i=1; i<=n; i++)

    {

        padure[i].push_back(i);

        multime[i] = i;

    }



    sort(v+1, v+m+1, Cmp);



    for (int i=1; i<=m && nrm < (n-1); i++)

    {

        int a = v[i].x;

        int b = v[i].y;



        if (multime[a] != multime[b])

        {

            sum += v[i].cost;

            Uneste(multime[a], multime[b]);

            nrm ++;

            sol[nrm].first = b;

            sol[nrm].second = a;

        }

    }



    g << sum << "\n" << nrm << "\n";

    for (int i=1; i<=nrm; i++)

        g << sol[i].first << " " << sol[i].second << "\n";



    return 0;

}
