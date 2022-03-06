#include <cstdio>
#include <cstring>
#include <algorithm>



using namespace std;

const int NMAX = 2000003;

char s[NMAX];
char w[NMAX];

int pi[NMAX];

int mch=0;
bool poz[NMAX];

int main(){
 freopen("strmatch.in","r",stdin);
 freopen("strmatch.out","w",stdout);

 scanf("%s\n%s",w,s);

 int n=strlen(s);
 int m=strlen(w);


 int q=0;
 for(int i=1;i<m;++i){
  while(q && w[i]!=w[q])
   q=pi[q-1];
  if(w[i]==w[q])
   ++q;
  pi[i]=q;
 }


 q=0;
 for(int i=0;i<n;++i){
  while(q && s[i]!=w[q])
   q=pi[q-1];

  if(s[i]==w[q])
   ++q;

  if(q==m){
   q=pi[q-1];
   mch++;
   poz[i-m+1]=1;
  }
 }


 printf("%d\n",mch);
 int cnt=0;
 for(int i=0;i<n && cnt<1000;++i)
  if(poz[i])
   printf("%d ",i),cnt++;

 return 0;
}
