#include <fstream>
#include <cstdlib>


using namespace std;



struct muchie

    {

        int x,y,z;

    }

    v[1005];

bool a[105];



int check(int i)

{

    if(v[i].z==0)

        return a[v[i].x] || a[v[i].y];

    if(v[i].z==1)

        return a[v[i].x] || !a[v[i].y];

    if(v[i].z==2)

        return a[v[i].y] || !a[v[i].x];

    if(v[i].z==3)

        return a[v[i].x]+a[v[i].y]!=2;

    return 0;

}



int main()

{

    int n,m;

    ifstream in("party.in");

    ofstream out("party.out");

    in>>n>>m;

    for(int i=1;i<=m;i++)

    in>>v[i].x>>v[i].y>>v[i].z;

    for(int i=1;i<=n;i++)

        a[i]=true;

        for(int i=1;i<=m;i++)

            if(!check(i))

            {

                bool r = rand()%2;

                if(r)

                    a[v[i].y] = !a[v[i].y];

                else

                    a[v[i].x] = !a[v[i].x];

                i=0;

            }

    m=0;

    for(int i=1;i<=n;i++)

        if(a[i])

            m++;

    out<<m<<"\n";

    for(int i=1;i<=n;i++)

        if(a[i])

            out<<i<<"\n";

    return 0;

}
