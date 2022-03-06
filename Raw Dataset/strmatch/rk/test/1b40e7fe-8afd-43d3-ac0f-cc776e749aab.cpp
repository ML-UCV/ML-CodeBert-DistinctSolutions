#include <bits/stdc++.h>
using namespace std;

char s1[2000005],s2[2000005];

int ap[2000005];

const int mod1=1e9+7;

const int mod2=1e9+9;

const int baza=97;

int main()

{

    freopen("strmatch.in","r",stdin);

    freopen("strmatch.out","w",stdout);

    fgets(s1+1,2000005,stdin);

    fgets(s2+1,2000005,stdin);

    int n=strlen(s1+1),m=strlen(s2+1);

    long long put1=1,put2=1,rez1=0,rez2=0;

    --n;--m;

    int i,j,cnt=0;

    for(i=1;i<n;i++)put1*=baza,put2*=baza,put1%=mod1,put2%=mod2;

    for(i=1;i<=n;i++)

    {

        rez1=rez1*baza+(s1[i]-'0'+1);rez1%=mod1;

        rez2=rez2*baza+(s1[i]-'0'+1);rez2%=mod2;

    }

    long long calc1=0,calc2=0;

    for(i=1;i<=m;i++)

    {

        if(i<=n)

        {

            calc1=calc1*baza+(s2[i]-'0'+1);calc1%=mod1;

            calc2=calc2*baza+(s2[i]-'0'+1);calc2%=mod2;

        }

        else

        {

            calc1-=put1*(s2[i-n]-'0'+1);calc2-=put2*(s2[i-n]-'0'+1);

            calc1%=mod1;calc2%=mod2;

            if(calc1<0)calc1+=mod1;if(calc2<0)calc2+=mod2;

            calc1=calc1*baza+(s2[i]-'0'+1);calc1%=mod1;

            calc2=calc2*baza+(s2[i]-'0'+1);calc2%=mod2;

        }

        if(calc1==rez1&&calc2==rez2&&i>=n)

            ap[++cnt]=i;

    }

        printf("%d\n",cnt);

        for(i=1;i<=min(1000,cnt);++i)printf("%d ",ap[i]-n);

    return 0;

}
