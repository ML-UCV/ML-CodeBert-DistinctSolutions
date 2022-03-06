#include<cstdio>
#include<cstdlib>
const int N=200001,M=400001;

int d[N],x[M],y[M],c[M],n,m,e,p[M],l[N],i,j;

int E(int x)

{

    if(d[x]==x)

        return x;

    d[x]=E(d[x]);

    return d[x];

}

void R(int x,int y)

{

    d[E(x)]=E(y);

}

int F(const void *a,const void *b)

{

    return c[*(int*)a]-c[*(int*)b];

}

int main()

{

    freopen("apm.in","r",stdin),freopen("apm.out","w",stdout),scanf("%d%d",&n,&m);

    for(i=0;i<m;i++)

        scanf("%d%d%d",x+i,y+i,c+i),d[i]=p[i]=i;

    qsort((void*)p,m,4,F);

    for(i=0;i<m;i++)

        if(E(x[p[i]])!=E(y[p[i]]))

            e+=c[p[i]],R(x[p[i]],y[p[i]]),l[j++]=p[i];

    printf("%d\n%d\n",e,n-1);

    for(i=0;i<n-1;++i)

        printf("%d %d\n",x[l[i]],y[l[i]]);

}
