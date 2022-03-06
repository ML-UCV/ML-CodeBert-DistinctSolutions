#include <bits/stdc++.h>




using namespace std;

ifstream fin ("apm.in");

ofstream fout ("apm.out");

struct muchie

{

    int x, y, c;

};

muchie m[2*200005];

int viz[2*200005], n, e, t[200005], sz[200005], s;

bool criteriu(muchie a, muchie b)

{

    return a.c<b.c;

}

int tata(int x)

{

    if(x!=t[x])

        t[x]=tata(t[x]);

    return t[x];

}

void uneste(int x, int y)

{

    if(sz[x]>sz[y])

    {

        t[y]=x;

        sz[x]+=sz[y];

    }

    else

    {

        t[x]=y;

        sz[y]+=sz[x];

    }

}

int main()

{

    fin >> n >> e;

    for(int i=1;i<=e;i++)

        fin >> m[i].x >> m[i].y >> m[i].c;



    sort(m+1, m+e+1, criteriu);

    for(int i=1;i<=n;i++)

    {

        t[i]=i;

        sz[i]=1;

    }

    for(int i=1;i<=e;i++)

    {

        int x, y;

        x=tata(m[i].x);

        y=tata(m[i].y);

        if(x!=y)

        {

            viz[i]=1;

            s+=m[i].c;

            uneste(x, y);

        }

    }

    fout << s << '\n' << n-1 << '\n';

    for(int i=1;i<=e;i++)

        if(viz[i])

            fout << m[i].x << ' ' << m[i].y << '\n';



    return 0;

}
