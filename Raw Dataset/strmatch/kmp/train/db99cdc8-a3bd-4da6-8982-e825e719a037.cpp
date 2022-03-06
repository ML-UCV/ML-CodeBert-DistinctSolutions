#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int SMAX = 2000005;

char a[SMAX],b[SMAX];

int pi[SMAX];

int n,m;

void make_prefix(){
 pi[1]=0;
 int q=0;
 for(int i=2;i<=m;++i){
  while(q && a[q+1]!=a[i])
   q=pi[q];
  if(a[q+1]==a[i])
   q++;
  pi[i]=q;
 }
}

int cnt;
int poz[1024];

void kmp(){
 int q=0;
 for(int i=1;i<=n;++i){
  while(q && a[q+1]!=b[i])
   q=pi[q];
  if(a[q+1]==b[i])
   q++;

  if(q==m){
   q=pi[m];
   cnt++;
   if(cnt<=1000)
    poz[cnt]=i-m;
  }
 }
}

int main(){
 freopen("strmatch.in","r",stdin);
 freopen("strmatch.out","w",stdout);

 scanf("%s\n%s\n",a+1,b+1);

 a[0]=' ';
 b[0]=' ';

 n=strlen(b)-1;
 m=strlen(a)-1;

 make_prefix();

 kmp();

 printf("%d\n",cnt);

 for(int i=1;i<=min(cnt,1000);++i)
  printf("%d ",poz[i]);

 return 0;
}
