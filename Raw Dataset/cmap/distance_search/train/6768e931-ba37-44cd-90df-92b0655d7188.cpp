#include <iomanip>
#include <fstream>
#include <algorithm>
#include <cmath>
using namespace std;

ifstream in("cmap.in");

ofstream out("cmap.out");

double maxim(double a, double b)

{

    if(a<b) return a;

    return b;

}

struct pereche

{

    int x,y;

};

pereche v[100001];

bool sortare(pereche a, pereche b)

{

    if(a.x<=b.x) return true;

    return false;

}

double calcdist(int a, int b)

{

    double dist = sqrt(1.0*(v[a].x-v[b].x)*(v[a].x-v[b].x)+1.0*(v[a].y-v[b].y)*(v[a].y-v[b].y));

    return dist;

}

int main()

{

    int n;

    in>>n;

    for(int i=1;i<=n;i++)

    {

        in>>v[i].x>>v[i].y;

    }

    sort(v+1,v+n+1,sortare);

    double d = calcdist(1,n);

    for(int i=1;i<=n;i++)

        for(int j=i+1;j<=n && v[j].x-v[i].x<=d; j++)

    {

        d = maxim(d,calcdist(i,j));

    }

    out << fixed << setprecision(6) << d;

    return 0;

}
