#include <stdio.h>
#include <algorithm>


using namespace std;

int sum,b,p,i,x,n,aib[101*1001];



int sol(int x){

int i;

int rez=0;

for(i=x;i>0;i-=(i&(-i)))

    rez+=aib[i];

return rez;



}



void add(int x,int n){

int i;

for(i=x;i<=n;i+=(i&(-i))) aib[i]++;



}

int ok=0;

struct mch{

int val,ord;

} a[101*1001];

int compare( mch a,mch b){

if(a.val==b.val) return a.ord<b.ord;

return a.val<b.val;



}



int main()

{



   freopen("inv.in","r",stdin);

   freopen("inv.out","w",stdout);

   int n,m;

   scanf("%d",&n);

   for(i=1;i<=n;i++){scanf("%d",&x);



    a[i].val=x;

    a[i].ord=i;

   }

   sort(a+1,a+n+1,compare);

   long long ssol=1LL*n*(n-1)/2;



   for(i=1;i<=n;i++){



   int x=a[i].ord;

   ssol-=1LL*sol(x);

   add(x,n);





   }

   printf("%lld\n",ssol%9917);

    return 0;

}
