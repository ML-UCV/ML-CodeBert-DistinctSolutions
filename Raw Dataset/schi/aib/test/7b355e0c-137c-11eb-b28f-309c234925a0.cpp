#include <stdio.h>
using namespace std;

int j,b,p,a,i,v[1001*1001],n,aib[1001*1001];

int ssol[30001];

int sol(int x){

int i;

int rez=0;

for(i=x;i>0;i-=(i&(-i)))

    rez+=aib[i];

return rez;



}

void add(int x,int val){

int i;

for(i=x;i<=n;i+=(i&(-i))) aib[i]+=val;



}

int ok=0;

int cautbin(int x){

    int valoare,st=1,dr=n;

int mij;

while(st<=dr){

        mij=(st+dr)/2;

        int ssol=sol(mij);

        if(ssol==x) valoare=mij;

        if(ssol>=x) dr=mij-1;

        else st=mij+1;





}

return valoare;



}

int main()

{



   freopen("schi.in","r",stdin);

   freopen("schi.out","w",stdout);





   scanf("%d",&n);

    for(i=1;i<=n;i++) aib[i]=(i&(-i));

   for(i=1;i<=n;i++)scanf("%d",&v[i]);

   int k;

for(j=n;j>=1;j--){

k=cautbin(v[j]); ssol[k]=j;

add(k,-1);





}

for(i=1;i<=n;i++) printf("%d\n",ssol[i]);

    return 0;

}
