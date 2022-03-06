#include <bits/stdc++.h>


using namespace std;

ifstream f("party.in");

ofstream g("party.out");

bool a[101];

struct cer

{

    int x,y,op;

};

cer v[1001];

int main()

{

    int n,m,i;

    f>>n>>m;

    fill(a+1,a+n+1,true);

    for(i=1;i<=m;i++)

        f>>v[i].x>>v[i].y>>v[i].op;

    bool ok=false;

    while(!ok)

    {

        ok=true;

        for(i=1;i<=m;i++)

        {

            switch (v[i].op)

            {

                case 0:

                    if(!a[v[i].x] and !a[v[i].y])

                    {

                        a[v[i].x]=a[v[i].y]=true;

                        ok=false;

                    }

                break;



                case 1:

                    if(!a[v[i].x] and a[v[i].y])

                    {

                        a[v[i].y]=false;

                        ok=false;

                    }

                break;



                case 2:

                    if(a[v[i].x] and !a[v[i].y])

                    {

                        a[v[i].x]=false;

                        ok=false;

                    }

                break;



                case 3:

                    if(a[v[i].x] and a[v[i].y])

                    {

                        a[v[i].y]=false;

                        ok=false;

                    }



                break;

            }

        }

    }

    int nr=0;

    for(i=1;i<=n;i++)

        if(a[i]) nr++;

    g<<nr<<'\n';

    for(i=1;i<=n;i++)

        if(a[i]) g<<i<<'\n';



    return 0;

}
