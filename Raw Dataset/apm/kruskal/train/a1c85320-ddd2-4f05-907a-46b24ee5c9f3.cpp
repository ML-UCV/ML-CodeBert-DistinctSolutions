#include <fstream>
#include <algorithm>




using namespace std;



struct edge

{

    int x, y, cost;

};



pair < int, int > sol[200003];

int t[200003], n, m, k;

edge a[2 * 200003];



void Union(int x, int y)

{

    t[x] = y;

}



int Find(int x)

{

    int root, y;

    root = x;

    while(t[root])

        root = t[root];

    while(x != root)

    {

        y = t[x];

        t[x] = root;

        x = y;

    }

    return root;

}



inline bool Compare(edge A, edge B)

{

    return A.cost < B.cost;

}



int main()

{

    ifstream fin("apm.in");

    ofstream fout("apm.out");

    int p, q, cnt, minimum = 0;

    fin >> n >> m;

    for(int i = 1; i <= m; i++)

        fin >> a[i].x >> a[i].y >> a[i].cost;

    fin.close();

    sort(a + 1, a + m + 1, Compare);

    for(int i = 1; i <= m; i++)

    {

        p = Find(a[i].x);

        q = Find(a[i].y);

        if(p != q)

        {

            minimum += a[i].cost;

            sol[++k].first = a[i].x;

            sol[k].second = a[i].y;

            Union(p, q);

        }

    }

    fout << minimum << "\n" << k << "\n";

    for(int i = 1; i <= k; i++)

        fout << sol[i].first << " " << sol[i].second << "\n";

    fout.close();

    return 0;

}
