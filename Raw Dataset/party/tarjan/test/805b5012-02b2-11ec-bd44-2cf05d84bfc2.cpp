#include<cstdio>
#include<cstdlib>
int n,m,i,nr,x,a[1001][3],v[101];

inline int ver(int i)

{

 switch(a[i][2])

 {

 case 0:

  return v[a[i][0]] || v[a[i][1]];

  break;

 case 1:

  return v[a[i][0]] || !v[a[i][1]];

  break;

 case 2:

  return v[a[i][1]] || !v[a[i][0]];

  break;

 case 3:

  return v[a[i][0]]+v[a[i][1]]!=2;

  break;

 }

 return 1;

}

inline void correct(int i)

{

 x=rand()%2;

 v[a[i][x]]=!v[a[i][x]];

}

int main()

{

 freopen("party.in","r",stdin);

 freopen("party.out","w",stdout);

 scanf("%d %d",&n,&m);

 for(i=1;i<=m;i++)

 {

  scanf("%d %d %d",&a[i][0],&a[i][1],&a[i][2]);

 }

 for(i=1;i<=n;i++) v[i]=1;

 while(1)

 {

  for(i=1;i<=m;i++)

   if(!ver(i))

   {

    correct(i);

    break;

   }

  if(i==m+1) break;

 }

 for(i=1;i<=n;i++)

  if(v[i]) nr++;

 printf("%d\n",nr);

 for(i=1;i<=n;i++)

  if(v[i]) printf("%d\n",i);

 fclose(stdout);

 return 0;

}
