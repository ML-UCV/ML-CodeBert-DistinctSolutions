#include<cstdio>


int p[1001],n,m,i,a,b,j,w[1001],c[1001],nr,k,z,d[1001],f[1001][1001],g[1001][1001],e[1001],h[1001];



void D(int x)

{int i;

c[x]=1;

for(i=0;i<e[x];i++)

if(!c[f[x][i]])

       D(f[x][i]);

w[++nr]=x;}



void T(int x)

{int i;

c[x]=0;

if(p[x]==2)

       {p[x]=0;

       if(x>n)

               p[x-n]=1;

       else

               p[x+n]=1;}

for(i=0;i<h[x];i++)

if(c[g[x][i]])

       T(g[x][i]);}



int main()

{FILE *f1=fopen("party.in","r"),*f2=fopen("party.out","w");

fscanf(f1,"%d%d",&n,&m);

while(m--)

       {fscanf(f1,"%d%d%d",&a,&b,&z);

       if(!z)

              f[a+n][e[a+n]++]=b,f[b+n][e[b+n]++]=a,g[b][h[b]++]=a+n,g[a][h[a]++]=b+n;

       else

              if(z==1)

                     f[a+n][e[a+n]++]=b+n,f[b][e[b]++]=a,g[b+n][h[b+n]++]=a+n,g[a][h[a]++]=b;

              else

                     if(z==2)

                            f[a][e[a]++]=b,f[b+n][e[b+n]++]=a+n,g[b][h[b]++]=a,g[a+n][h[a+n]++]=b+n;

                     else

                            f[a][e[a]++]=b+n,f[b][e[b]++]=a+n,g[b+n][h[b+n]++]=a,g[a+n][h[a+n]++]=b;}

for(j=1;j<=2*n;j++)

       {p[j]=2;

       if(!c[j])

                D(j);}

for(i=nr;i;i--)

if(c[i])

       T(w[i]);

for(j=1,k=0;j<=n;j++)

if(p[j]==1)

       d[++k]=j;

fprintf(f2,"%d\n",k);

for(i=1;i<=k;i++)

       fprintf(f2,"%d\n",d[i]);

return 0;}
