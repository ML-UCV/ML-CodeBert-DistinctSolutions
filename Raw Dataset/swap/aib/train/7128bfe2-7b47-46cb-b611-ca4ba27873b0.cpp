#include <bits/stdc++.h>




using namespace std;

ifstream f("swap.in");

ofstream g("swap.out");

char s1[50005];

char s2[50005];

int fr1[26];

int fr2[26];

int v[50005];

int app[26][50005];

int p[50005];

int AIB[50005];

int n;

void update(int i)

{

    while(i<=n)

    {

        AIB[i]++;

        i+=(i&(-i));

    }

}

int query(int i)

{

    int s=0;

    while(i>0)

    {

        s+=AIB[i];

        i-=(i&(-i));

    }

    return s;

}

int main()

{

    f>>(s1+1);

    int i;

    for(i=1;s1[i];i++)

    {

        ++n;

        v[i]=++fr1[s1[i]-'a'];

    }

    f>>(s2+1);

    for(i=1;s2[i];i++)

        app[s2[i]-'a'][++fr2[s2[i]-'a']]=i;

    for(i=0;i<26;i++)

        if(fr1[i]!=fr2[i])

        {

            g<<-1;

            return 0;

        }

    for(i=1;i<=n;i++)

        p[i]=app[s1[i]-'a'][v[i]];

    int ans=0;

    for(i=n;i;i--)

    {

        ans+=query(p[i]);

        update(p[i]);

    }

    g<<ans;



    return 0;

}
