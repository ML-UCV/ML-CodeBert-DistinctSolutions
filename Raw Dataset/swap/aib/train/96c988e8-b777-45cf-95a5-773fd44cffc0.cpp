#include <stdio.h>#include <cstring>
#include <vector>


using namespace std;

int n,i,nr,sol,u[27],a[50005],AI[200000];

char ch,s1[50005],s2[50005];

vector <int> f[27];



void update(int nod,int l,int r,int x){

  if (l==r){AI[nod]=1;return;}

 int m=(l+r)>>1;

 if (x<=m)update(nod<<1,l,m,x);

 else update((nod<<1)|1,m+1,r,x);

 AI[nod]=AI[nod<<1]+AI[(nod<<1)|1];

}

void query(int nod,int l,int r,int x){

 if (l>0&&r<=x){nr+=AI[nod];return;}

 int m=(l+r)>>1;

 if (m)query(nod<<1,l,m,x);

 if (m<x)query((nod<<1)|1,m+1,r,x);

}



int main(){

 freopen("swap.in","r",stdin);freopen("swap.out","w",stdout);

 scanf("%s\n",s1+1);

 scanf("%s\n",s2+1);

 n=strlen(s1+1);

 for (i=1;i<=n;++i) f[s2[i]-'a'].push_back(i);

 for (i=1;i<=n;++i){

  ch=s1[i]-'a';

  if (f[ch].size()-u[ch]>0)

    a[i]=f[ch][u[ch]++];

  else {printf("-1\n");return 0;}

 }

 for (i=1;i<=n;++i){

   update(1,1,n,a[i]);

   nr=0;

   query(1,1,n,a[i]);

   sol+=a[i]-nr;

 }

 printf("%d\n",sol);

return 0;

}
