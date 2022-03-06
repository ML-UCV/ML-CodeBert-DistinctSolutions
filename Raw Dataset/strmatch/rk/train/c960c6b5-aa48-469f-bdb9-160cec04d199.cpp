#include<cstring>
#include<cstdio>
#include<iostream>


using namespace std;

char patt[2000002],s[2000002];

int poz[1010];



int is_prime(int x)

{

    if(x<2||x>2&&x%2==0)return 0;

    for(int d=3;d*d<=x;d+=2)

        if(x%d==0)return 0;

    return 1;

}



int next_prime(int x)

{

    x++;

    while(!is_prime(x))x++;

    return x;

}



int main()

{

    FILE *f=fopen("strmatch.in","r");

    fgets(patt,2000002,f);

    fgets(s,2000002,f);

    f=fopen("strmatch.out","w");

    int lp=strlen(patt),i;

    if(patt[lp-1]=='\n')patt[--lp]=0;

    int ls=strlen(s);

    if(s[ls-1]=='\n')s[--ls]=0;

    if(ls<lp){fprintf(f,"0");return 0;}







    int hn1=2000003,hn2=2000029;





    int h1=0,h2=0,hs1=0,hs2=0,nmatches=0,pow1=1,pow2=1,np=0;

    for(i=0;i<lp;i++)

    {

        h1=((long long)h1*256%hn1+patt[i])%hn1;

        h2=((long long)h2*256%hn2+patt[i])%hn2;

        hs1=((long long)hs1*256%hn1+s[i])%hn1;

        hs2=((long long)hs2*256%hn2+s[i])%hn2;

        if(i)

        {pow1=((long long)pow1%hn1*256)%hn1;

         pow2=((long long)pow2%hn2*256)%hn2;}

    }

    for(i=0;i<=ls-lp;i++)

    {

        if(hs1==h1&&hs2==h2)

        {

            np++;if(np<=1000)poz[np]=i;

        }

        hs1=((long long)(hs1-pow1*s[i])*256%hn1+s[i+lp])%hn1;

        hs1=(hs1+hn1)%hn1;

        hs2=((long long)(hs2-pow2*s[i])*256%hn2+s[i+lp])%hn2;

        hs2=(hs2+hn2)%hn2;

    }

    fprintf(f,"%d\n",np);

    np=min(np,1000);

    for(i=1;i<=np;i++)

        fprintf(f,"%d ",poz[i]);

    return 0;

}
