#include<stdio.h>
#include<vector>
#include<cstdlib>
#include<ctime>
using namespace std;

vector<bool> a;

struct Propozitie

{

    int x,y,z;

};

vector<Propozitie> p;

bool sat(const Propozitie &p)

{

    if(p.z==0)

        return a[p.x] || a[p.y];

    if(p.z==1)

        return a[p.x] || !a[p.y];

    if(p.z==2)

        return !a[p.x] || a[p.y];

    return !a[p.x] || !a[p.y];

}

int main()

{

    freopen("party.in","r",stdin);

    freopen("party.out","w",stdout);

    int n,m; srand(time(0));

    scanf("%d%d",&n,&m);

    for(int i=1;i<=n;i++)

        a.push_back(rand()%2);

    p.resize(m);

    for(int i=0;i<m;i++)

        scanf("%d%d%d",&p[i].x,&p[i].y,&p[i].z),

        p[i].x--,p[i].y--;

    bool flag;

    do

    {

        flag=true;

        for(int i=0;i<m;i++)

            if(!sat(p[i]))

            {

                if(rand()%2)

                    a[p[i].x]=1-a[p[i].x];

                else

                    a[p[i].y]=1-a[p[i].y];

                flag=false;

                break;

            }

    }while(!flag);

    vector<int> sol;

    for(int i=0;i<n;i++)

        if(a[i])

            sol.push_back(i+1);

    printf("%d\n",(int)sol.size());

    for(int i=0;i<(int)sol.size();i++)

        printf("%d\n",sol[i]);

    return 0;

}
