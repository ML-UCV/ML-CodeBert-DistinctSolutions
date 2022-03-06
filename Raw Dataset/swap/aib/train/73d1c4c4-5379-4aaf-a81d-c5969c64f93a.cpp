#include <bits/stdc++.h>
using namespace std;

int n,i,j,sol,aux,l;

vector<int> poz[30];

int p[30];

int aib[50005];

char s1[50005],s2[50005];

void update(int pos)

{

    int i;

    for(i=pos;i<=n;i+=((i)&(-i)))

        aib[i]++;

}

int query(int pos)

{

    int i;

    int sum=0;

    for(i=pos;i>0;i-=((i)&(-i)))

        sum+=aib[i];

    return sum;

}

int main()

{

    freopen("swap.in","r",stdin);

    freopen("swap.out","w",stdout);

    scanf("%s\n%s",s1+1,s2+1);

    n=strlen(s1+1);

    if(strlen(s1+1)!=strlen(s2+1))

    {

        printf("-1");

        return 0;

    }

    for(i=1;i<=n;i++)

        poz[((s1[i])-'a')].push_back(i);

    for(i=1;i<=n;i++)

    {

        l=((s2[i])-'a');

        if(p[l]>=(int)poz[l].size())

        {

            printf("-1");

            return 0;

        }

        sol+=abs(i-(poz[l][p[l]]+query(n)-query(poz[l][p[l]])));

        update(poz[l][p[l]]);

        p[l]++;

    }

    printf("%d",sol);

    return 0;

}
