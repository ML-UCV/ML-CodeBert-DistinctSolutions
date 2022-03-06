#include <bits/stdc++.h>
using namespace std;



int x,y,a[100050],b[100051],dist[30002],c[100051],n,m;
int main(){

    freopen("sate.in","r",stdin);
    freopen("sate.out","w",stdout);

    scanf("%d%d%d%d",&n,&m,&x,&y);

    for(int i=1;i<=m;i++)
        scanf("%d%d%d",&a[i],&b[i],&c[i]);

    dist[x]=1;
    while(!dist[y]){
        for(int i=1;i<=m;i++)
        {
            if(dist[a[i]] && !dist[b[i]])
                 dist[b[i]]=dist[a[i]]+c[i];
            else if(!dist[a[i]] && dist[b[i]])
                 dist[a[i]]=dist[b[i]]-c[i];


        }
    }
    printf("%d\n",abs(dist[y])-1);
    return 0;
}
