#include <fstream>
#include <algorithm>






using namespace std;

ifstream in("apm.in");

ofstream out("apm.out");



struct muchie

{

    int x, y, c;

    bool operator < (const muchie& other) const

    {

        return c < other.c;

    }

}v[400000 +5];



int sef[200000 +5], n, m, sol[200000 +5];



int sefsuprem(int x)

{

    if(sef[x]==x) return x;

    sef[x] = sefsuprem(sef[x]);

    return sef[x];

}
int main()

{

    in>>n>>m;

    for(int i=1; i<=m; i++) in>>v[i].x>>v[i].y>>v[i].c;

    sort(v+1, v+m+1);



    for(int i=1; i<=n; i++) sef[i]=i;



    int cnt = 0, total = 0;

    for(int i=1; i<=m && cnt<n-1; i++)

    {

        int sefx = sefsuprem(v[i].x);

        int sefy = sefsuprem(v[i].y);

        if(sefx != sefy)

        {

            sef[sefx]=sefy;

            total += v[i].c;

            cnt++;

            sol[cnt]=i;

        }

    }



    out<<total<<'\n'<<cnt<<'\n';

    for(int i=1; i<=cnt; i++)

        out<<v[sol[i]].x<<' '<<v[sol[i]].y<<'\n';

    return 0;

}
