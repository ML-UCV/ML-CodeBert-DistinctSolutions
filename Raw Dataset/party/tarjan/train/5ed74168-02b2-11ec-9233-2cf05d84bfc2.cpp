#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;

int n,m,x[1001],y[1001],z[1001],Z,i,t[202],cnt;

int main(){

    srand(time(0));

    freopen("party.in","r",stdin);

    freopen("party.out","w",stdout);

    scanf("%d%d",&n,&m);

    for(i=1;i<=m;i++)scanf("%d%d%d",&x[i],&y[i],&z[i]);

    for(i=0;i-m-1;)

    {

        for(i=1;i<=m;i++)

        {

            Z=(t[x[i]]<<1)|t[y[i]];if(Z-z[i])continue;

            if(rand()&1)t[x[i]]=1-t[x[i]];else t[y[i]]=1-t[y[i]];break;

        }

    }

    for(i=1;i<=n;i++)cnt+=t[i];printf("%d\n",cnt);

    for(i=1;i<=n;i++)if(t[i]&1)printf("%d\n",i);

    return 0;

}
