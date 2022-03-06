#include<fstream>
#include <cstdlib>
using namespace std;

struct cerinta

{

    int x,y,z;

} str[1001];

bool v[101];

inline bool check(int i)

{

    if(str[i].z==0)

        return v[str[i].x] || v[str[i].y];

    if(str[i].z==1)

        return v[str[i].x] || !v[str[i].y];

    if(str[i].z==2)

        return v[str[i].y] || !v[str[i].x];

    if(str[i].z==3)

        return v[str[i].x]+v[str[i].y]!=2;

    return false;

}

int main()

{

    int n,m,i;

    ifstream q("party.in");

    ofstream w("party.out");

    q>>n>>m;

    for(i=1; i<=m; i++)

        q>>str[i].x>>str[i].y>>str[i].z;

    for(i=1; i<=n; i++)

        v[i]=true;

    for(i=1; i<=m; i++)

        if(!check(i))

        {

            bool ii = rand()%2;

            if(ii)

                v[str[i].y] = !v[str[i].y];

            else

                v[str[i].x] = !v[str[i].x];

            i=0;

        }

    m = 0;

    for(i=1; i<=n; i++)

        if(v[i])

            m++;

    w<<m<<"\n";

    for(i=1; i<=n; i++)

        if(v[i])

            w<<i<<"\n";

    return 0;

}
