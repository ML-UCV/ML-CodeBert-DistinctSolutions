#include<bits/stdc++.h>


using namespace std;

int m[200][50005],v[200],nr[50005],f[200],perm[50005];

char s1[50005],s2[50005];

int AIB[50005],l;

long long sol;

void update(int pos)

{

    for(int i=pos;i<=l;i+=(i&(-i)))

        AIB[i]++;

}

int query(int pos)

{

    int s=0;

    for(int i=pos;i>=1;i-=(i&(-i)))

    {

        s+=AIB[i];

    }

    return s;

}

int main()

{

    freopen("swap.in","r",stdin);

    freopen("swap.out","w",stdout);

    scanf("%s",&s1);

    scanf("\n");

    l=strlen(s1);

    fread(s2,1,l,stdin);





    for(int i=0;i<l;i++)

    {

        nr[i]=f[s1[i]]+1;

        f[s1[i]]++;

    }

    for(int i=0;i<l;i++)

    {

        v[s2[i]]++;

        m[s2[i]][v[s2[i]]]=i;

    }

    for(int i=0;i<l;i++)

    {

        perm[i]=m[s1[i]][nr[i]];

    }

    for(int i=0;i<l;i++)

    {

        if(v[s2[i]]!=f[s2[i]])

        {

            printf("-1\n");

            return 0;

        }

    }



    int x,y;

    for(int i=0;i<l;i++)

    {

        x=perm[i]+1;

        y=query(x);

        sol=sol+1LL*(i-y);

        update(x);

    }

    printf("%lld\n",sol);

    return 0;

}
