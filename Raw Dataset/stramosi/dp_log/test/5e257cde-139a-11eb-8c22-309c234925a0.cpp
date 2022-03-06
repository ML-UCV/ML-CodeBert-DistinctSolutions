#include<cstdio>
using namespace std;
int a[22][250010];
int main()
{
    freopen("stramosi.in","r",stdin);
    freopen("stramosi.out","w",stdout);
    int n,m,i,j,nod,grad,mask;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
        scanf("%d",&a[0][i]);
    for(i=1;i<=19;i++)
        for(j=1;j<=n;j++)
            a[i][j]=a[i-1][a[i-1][j]];
    for(i=1;i<=m;i++)
    {
        scanf("%d%d",&nod,&grad);
        while(grad)
        {
            mask=0;
            while((1<<mask)<=grad)
                mask++;
            mask--;
            grad-=(1<<mask);
            nod=a[mask][nod];
        }
        printf("%d\n",nod);
    }
    return 0;
}
