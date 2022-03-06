#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>


using namespace std;







ifstream f("apm.in");

ofstream g("apm.out");



struct muchie

{

    int c, x, y;

};



typedef pair<int, int> pereche;



int tata[200005], rang[200005];



bool comp(muchie i, muchie j)

{

    return i.c < j.c;

}



int Find(int x)

{

    while (tata[x] != x)

        x = tata[tata[x]];

    return x;

}
bool Union(int x, int y)

{

    x = Find(x);

    y = Find(y);



    if (x != y)

    {

        if (rang[x] <= rang[y])

        {

            tata[x] = y;

            rang[y] += rang[x];

        }

        else

        {

            tata[y] = x;

            rang[x] += rang[y];

        }



        return true;

    }



    return false;

}



int main()

{

    int n, m, x, y, c;

    int cost = 0;

    vector<pereche> arbore;

    vector<muchie> muchii;

    f >> n >> m;

    muchii.resize(m);

    for (int i = 1; i <= m; i++)

    {

        f >> x >> y >> c;

        muchii.push_back({c,x,y});

    }

    sort(muchii.begin(), muchii.end(), comp);



    for (int i = 1; i <= n; i++)

    {

        tata[i] = i;

        rang[i] = 1;

    }



    for (muchie m : muchii)

    {

        x = m.x;

        y = m.y;

        if (Union(x, y))

        {

            arbore.push_back(make_pair(x,y));

            cost += m.c;

        }

    }

    g << cost << '\n' << arbore.size() << '\n';

    for (size_t i = 0; i < arbore.size(); i++)

        g << arbore[i].first << " " << arbore[i].second << '\n';

    return 0;

}
