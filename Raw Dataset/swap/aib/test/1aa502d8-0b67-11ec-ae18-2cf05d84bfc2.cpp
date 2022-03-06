#include <cstdio>
#include <cstring>
#include <queue>


using namespace std;



char a[50002],b[50002];

int v[50001],aux[26],aib[50001];

queue <int> ind[26];



int main()

{

    int n,i,j,sol=0;

    freopen("swap.in","r",stdin);

    freopen("swap.out","w",stdout);

    fgets(a,sizeof(a),stdin);

    fgets(b,sizeof(b),stdin);

    n=strlen(a)-1;

    for (i=0;i<n;++i)

    {

        ++aux[a[i]-'a'];

        --aux[b[i]-'a'];

    }

    for (i=0;i<26;++i)

        if (aux[i])

        {

            printf("-1\n");

            return 0;

        }

    for (i=0;i<n;++i)

        ind[a[i]-'a'].push(i+1);

    for (i=1;i<=n;++i)

    {

        v[i]=ind[b[i-1]-'a'].front();

        ind[b[i-1]-'a'].pop();

    }

    for (i=1;i<=n;++i)

    {

        sol+=i-1;

        for (j=v[i];j;j-=j&-j)

            sol-=aib[j];

        for (j=v[i];j<=n;j+=j&-j)

            ++aib[j];

    }

    printf("%d",sol);

    return 0;

}
