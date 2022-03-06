#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int NMAX = 2000003;

char s[NMAX];
char w[NMAX];

int mch=0;
bool poz[NMAX];

int main(){
 freopen("strmatch.in","r",stdin);
 freopen("strmatch.out","w",stdout);


 scanf("%s%s",w,s);

 int n=strlen(s);
 int m=strlen(w);

 if(m>n){
  printf("0\n");
  return 0;
 }

 int hashw1=0,hashw2=0;
 int hashs1=0,hashs2=0;

 int p1=1,p2=1;


 for(int i=0;i<m;++i){
  hashw1=(hashw1*113 +(w[i]-'0'+1))%10007;
  hashw2=(hashw2*113 +(w[i]-'0'+1))%10009;


  if(i){
   p1=(p1*113)%10007;
   p2=(p2*113)%10009;
  }
 }


 for(int i=0;i<m;++i){
  hashs1=(hashs1*113 +(s[i]-'0'+1))%10007;
  hashs2=(hashs2*113 +(s[i]-'0'+1))%10009;
 }


 if(hashs1==hashw1 && hashs2==hashw2)
  ++mch,poz[0]=1;


 for(int i=m;i<n;++i){
  hashs1=((hashs1-((s[i-m]-'0'+1)*p1)%10007 +10007)*113 +(s[i]-'0'+1))%10007;
  hashs2=((hashs2-((s[i-m]-'0'+1)*p2)%10009 +10009)*113 +(s[i]-'0'+1))%10009;


  if(hashs1==hashw1 && hashs2==hashw2)
   ++mch,poz[i-m+1]=1;
 }


 printf("%d\n",mch);
 int cnt=0;
 for(int i=0;i<n && cnt<1000;++i)
  if(poz[i])
   printf("%d ",i),cnt++;

 return 0;
}
