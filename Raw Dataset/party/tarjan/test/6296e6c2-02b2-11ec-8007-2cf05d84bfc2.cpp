#include<fstream>


using namespace std;



ifstream in("party.in");

ofstream out("party.out");



int n,m,sol,p[101];

struct

{

    int x,y,z;

} v[1001];



int main()

{

    in>>n>>m;

    for(int i=1; i<=n; i++)

        p[i]=1;

    for(int i=1; i<=m; i++)

        in>>v[i].x>>v[i].y>>v[i].z;

    int x,y,z,sw=0;

    while(!sw)

    {

        sw=1;

        for(int i=1; i<=m; i++)

        {

            x=v[i].x;

            z=v[i].z;

            y=v[i].y;

            if(z==0&&p[x]==0&&p[y]==0)

            {

                p[x]=p[y]=1;

                sw=0;

                break;

            }

            if(z==1&&p[x]==0&&p[y]!=0)

            {

                p[y]=sw=0;

                break;

            }

            if(z==2&&p[x]!=0&&p[y]==0)

            {

                p[x]=sw=0;

                break;

            }

            if(z==3&&p[x]!=0&&p[y]!=0)

            {

                p[y]=sw=0;

                break;

            }



        }

    }

    for(int i=1;i<=n;i++)

        if(p[i])

        sol++;

    out<<sol<<'\n';

    for(int i=1;i<=n;i++)

        if(p[i])

        out<<i<<'\n';

    out.close();

    return 0;

}
