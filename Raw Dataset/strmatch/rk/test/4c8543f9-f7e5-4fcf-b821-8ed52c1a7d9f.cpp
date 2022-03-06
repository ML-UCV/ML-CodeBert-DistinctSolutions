#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int NMAX = 2000005;

const int P = 73;
const int MOD1 = 1e5+7;
const int MOD2 = 1e5+21;

char a[NMAX],b[NMAX];
int n,m;

int cnt;
int poz[1024];

int main(){
 freopen("strmatch.in","r",stdin);
 freopen("strmatch.out","w",stdout);

 scanf("%s\n%s",a+1,b+1);

 a[0]=' ';
 b[0]=' ';

 m=strlen(a)-1;
 n=strlen(b)-1;

 int A1=0,A2=0;
 int PA1=1,PA2=1;

 for(int i=1;i<=m;++i){
  A1=(A1*P+(a[i]-'0'))%MOD1;

  A2=(A2*P+(a[i]-'0'))%MOD2;
 }

 int B1=0,B2=0;

 for(int i=1;i<=m;++i){
  B1=(B1*P+(b[i]-'0'))%MOD1;
  if(i!=m)
  PA1=(PA1*P)%MOD1;

  B2=(B2*P+(b[i]-'0'))%MOD2;
  if(i!=m)
  PA2=(PA2*P)%MOD2;
 }

 if(B1==A1 && B2==A2){
  ++cnt;
  poz[cnt]=0;
 }

 for(int i=m+1;i<=n;++i){
  B1=((B1-((b[i-m]-'0')*PA1%MOD1)+MOD1)*P+(b[i]-'0'))%MOD1;

  B2=((B2-((b[i-m]-'0')*PA2%MOD2)+MOD2)*P+(b[i]-'0'))%MOD2;

  if(B1==A1 && B2==A2){
   ++cnt;
   if(cnt<=1000)
    poz[cnt]=i-m;

  }
 }

 printf("%d\n",cnt);

 for(int i=1;i<=min(cnt,1000);++i)
  printf("%d ",poz[i]);

 return 0;
}
