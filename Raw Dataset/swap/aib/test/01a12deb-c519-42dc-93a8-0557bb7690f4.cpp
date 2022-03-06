#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;

vector<int>poz[30];

int f[30],f2[30];

int v[50005];

char a[50005];

int aib[50005];

int update(int poz,int nr){

int i;

for(i=poz;i<=50000;i=i+(i&(-i)))

aib[i]+=nr;}

int query(int poz){

int i,s=0;

for(i=poz;i>0;i=i-(i&(-i)))

s=s+aib[i];

return s;}

int main(){

freopen("swap.in","r",stdin);

freopen("swap.out","w",stdout);

int n,rez=0,i;

char ch;

fgets(a+1,50003,stdin);

n=strlen(a+1);

n--;

for(i=1;i<=n;i++)

f[a[i]-96]++;

for(i=1;i<=n;i++)

scanf("%c",&ch),f2[ch-96]++,poz[ch-96].push_back(i);

for(i=1;i<=26;i++)

if (f[i]!=f2[i]){

printf("-1\n");

return 0;}

for(i=n;i>=1;i--)

v[i]=poz[a[i]-96].back(),poz[a[i]-96].pop_back();

for(i=1;i<=n;i++)

update(i,1);

for(i=1;i<=n;i++){

rez=rez+query(v[i]-1);

update(v[i],-1);}

printf("%d\n",rez);

return 0;}
