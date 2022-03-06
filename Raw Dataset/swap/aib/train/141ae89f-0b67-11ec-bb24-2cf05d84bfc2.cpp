#include<cstdio>
#include<cstring>
using namespace std;

int i,j,nr,n,ap[300],pr[50009][30],aib[50009],cr[50009],dr[50009];

char A[50009],B[50009];

void U(int p,int v){while(p<=n){aib[p]+=v;p+=p-(p&(p-1));}}

int Q(int p){int s=0;while(p){s+=aib[p];p&=p-1;}return s;}

int main()

{

freopen("swap.in","r",stdin);

freopen("swap.out","w",stdout);

fgets(A, 50001, stdin);

fgets(B, 50001, stdin);

n=strlen(A+1);

for(i=1;i<=n;i++)

    ap[A[i]]++;

for(i=1;i<=n;i++)

    ap[B[i]]--;

for(i='a';i<='z';i++)

    if(ap[i]!=0)

    {

        printf("-1\n");

        return 0;

    }

for(i=n;i>=1;i--)

{

    for(j='a';j<='z';j++)

        pr[i][j-'a']=pr[i+1][j-'a'];

    pr[i][A[i]-'a']=i;

}

for(i=1;i<=n;i++)

{

    cr[B[i]]=pr[cr[B[i]]+1][B[i]-'a'];

    dr[cr[B[i]]]=i;

}

for(i=1;i<=n;i++)

{

    nr+=dr[i]-i+(i-1-Q(dr[i]));

    U(dr[i],1);

}

printf("%d\n",nr);

return 0;

}
