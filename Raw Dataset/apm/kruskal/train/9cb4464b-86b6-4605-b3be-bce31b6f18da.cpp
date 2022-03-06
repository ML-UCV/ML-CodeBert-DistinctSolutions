#include <fstream>
#include <vector>
#include <algorithm>


using namespace std;



ifstream fin("apm.in");

ofstream fout("apm.out");



const int MMAX = 400000;

const int NMAX = 200000;



struct Edge

{

    int x, y, z;

};



struct Parents

{

    int root, siz;

}p[NMAX + 4];



inline bool cmp(const Edge &a, const Edge &b)

{

    if(a.z == b.z)

        return a.x < b.x;

    return a.z < b.z;

}



vector <Edge>v;

Edge a[NMAX + 5];



struct Padure

{

    int Find(int x)

    {

        if(p[x].root == x)

            return x;

        p[x].root = Find(p[p[x].root].root);

        return p[x].root;

    }



    void Unite(int x, int y)

    {

        y = Find(y);

        x = Find(x);

        if(p[x].siz > p[y].siz)

            p[x].root = y;

        else if (p[x].siz < p[y].siz)

            p[y].root = x;

        else

        {

            p[x].root = y;

            p[x].siz++;

        }

    }



}Pad;



int main()

{

    int n, m;

    fin >> n >> m;

    for(int i = 1; i <= m; i++)

    {

        int x, y, z;

        fin >> x >> y >> z;

        v.push_back({x, y, z});

    }

    sort(v.begin(), v.end(), cmp);



    for(int i = 1; i <= n; i++)

    {

        p[i].root = i;

        p[i].siz = 1;

    }



    int r = 0;

    for(int i = 0; i < m; i++)

        if(Pad.Find(v[i].x) != Pad.Find(v[i].y))

        {

            Pad.Unite(v[i].x, v[i].y);

            a[++r] = v[i];

        }



    int cost = 0;



    for(int i = 1; i <= r; i++)

    {

        cost += a[i].z;

    }



    fout << cost << '\n' << r << '\n';



    for(int i = 1; i <= r; i++)

        fout << a[i].y << ' ' << a[i].x << '\n';

    return 0;

}
