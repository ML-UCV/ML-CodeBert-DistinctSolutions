#include<stdio.h>
#include<algorithm>
using namespace std;

int v[200001];

struct eu{

    int x,y,cn;

};

eu d[400001],sol[200001];

bool cmp(eu a,eu b){

    return a.cn<b.cn;

}

int sefsuprem(int nr){

    if(v[nr]==nr)

        return nr;

    else

        return v[nr]=sefsuprem(v[nr]);

}

void unire(int a,int b){

    int sefx=sefsuprem(a);

    int sefy=sefsuprem(b);

    v[sefy]=sefx;

}

int main(){

    freopen("apm.in","r",stdin);

    freopen("apm.out","w",stdout);

    int n,m,i,s,k;

    scanf("%d%d",&n,&m);

    for(i=1;i<=n;i++)

        v[i]=i;

    for(i=1;i<=m;i++)

        scanf("%d%d%d",&d[i].x,&d[i].y,&d[i].cn);

    sort(d+1,d+m+1,cmp);

    k=1;

    s=0;

    for(i=1;i<=m&&k<=n-1;i++){

        if(sefsuprem(d[i].x)!=sefsuprem(d[i].y)){

            sol[k]=d[i];

            unire(d[i].x,d[i].y);

            s=s+d[i].cn;

            k++;

        }

    }

    printf("%d\n%d\n",s,n-1);

    for(i=1;i<n;i++)

        printf("%d %d\n",sol[i].x,sol[i].y);

    return 0;

}
