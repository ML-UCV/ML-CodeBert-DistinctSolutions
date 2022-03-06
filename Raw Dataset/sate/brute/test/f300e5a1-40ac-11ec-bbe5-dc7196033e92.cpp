#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

const int NMAX=100100;
int n,m,x,y,dist[NMAX],A[NMAX],B[NMAX],C[NMAX];
void citire()
{
    scanf("%d%d%d%d",&n,&m,&x,&y);
    int a,b,c;
    for(int i=1;i<=m;i++)
        scanf("%d%d%d",&A[i],&B[i],&C[i]);
}
void rezolv()
{
    dist[x]=1;
    if(x==y) return ;
    while(!dist[y])
    {
        for(int i=1;i<=m;i++)
            if(dist[A[i]]!=0 && dist[B[i]]==0)      dist[B[i]]=dist[A[i]]+C[i];
            else if(dist[A[i]]==0 && dist[B[i]]!=0) dist[A[i]]=dist[B[i]]-C[i];
    }
}
int main()
{
    freopen("sate.in","r",stdin);
    freopen("sate.out","w",stdout);
    citire();
    rezolv();
    printf("%d",dist[y]-1);
    return 0;
}
