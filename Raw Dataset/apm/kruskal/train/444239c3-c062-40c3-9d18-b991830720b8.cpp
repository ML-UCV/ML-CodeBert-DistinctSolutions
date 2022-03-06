#include <fstream>
#include <algorithm>


using namespace std;



ifstream fin("apm.in");

ofstream fout("apm.out");



struct muchie

{

    int x,y,c;

};



muchie v[400005],w[400005];

int t[400005];



bool cmp(muchie a, muchie b)

{

    if (a.c<b.c) return 1;

    else return 0;

}



int rad(int x)

{

    while(t[x]!=0) x=t[x];

    return x;

}



int n,m,i,x,y,rx,ry,nr,s;



int main()

{

    fin >> n >> m;

    for (i=1;i<=m;i++) fin >> v[i].x >> v[i].y >> v[i].c;

    sort (v+1,v+m+1,cmp);

    for (i=1;i<=m;i++)

    {

        x=v[i].x;

        y=v[i].y;

        rx=rad(x);

        ry=rad(y);

        if (rx<ry)

        {

            s+=v[i].c;

            t[ry]=rx;

            nr++;

            w[nr].x=x;

            w[nr].y=y;

        }

        else if (rx>ry)

        {

            s+=v[i].c;

            t[rx]=ry;

            nr++;

            w[nr].x=x;

            w[nr].y=y;

        }

    }

    fout << s << "\n" << nr << "\n";

    for (i=1;i<=nr;i++) fout << w[i].y << " " << w[i].x << "\n";



    return 0;

}
