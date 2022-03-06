#include <bits/stdc++.h>
using namespace std;

ifstream si("party.in");

ofstream so("party.out");

bool a[105];

struct cer

{

    int x,y,op;

};

cer v[1005];

int main()

{

    int n,m;

    si>>n>>m;

    fill(a+1,a+n+1,true);

    for(int i=1;i<=m;i++)

        si>>v[i].x>>v[i].y>>v[i].op;

    bool ok=false;

    while(!ok)

    {

        ok=true;

        for(int i=1;i<=m;i++)

        {

            switch(v[i].op)

            {

                case 0:

                    if(!a[v[i].x]&&!a[v[i].y])

                    {

                        a[v[i].x]=a[v[i].y]=true;

                        ok=false;

                    }

                break;



                case 1:

                    if(!a[v[i].x]&&a[v[i].y])

                    {

                        a[v[i].y]=false;

                        ok=false;

                    }

                break;



                case 2:

                    if(a[v[i].x]&&!a[v[i].y])

                    {

                        a[v[i].x]=false;

                        ok=false;

                    }

                break;



                case 3:

                    if(a[v[i].x]&&a[v[i].y])

                    {

                        a[v[i].y]=false;

                        ok=false;

                    }

                break;

            }

        }

    }

    int nr=0;

    for(int i=1;i<=n;i++)

        if(a[i])

            nr++;

    so<<nr<<'\n';

    for(int i=1;i<=n;i++)

        if(a[i])

            so<<i<<'\n';

    return 0;

}
