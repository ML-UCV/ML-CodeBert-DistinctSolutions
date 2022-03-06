#include <fstream>
#include <cstdio>
#include <cstring>
using namespace std;

ifstream in ("strmatch.in");

ofstream out ("strmatch.out");

char pattern[2000001], text[2000001];

bool match[2000001];

int m,n,nr,hashp1,hashp2,d1,d2,i;

int hasht1,hasht2;



void f()

{

    n=strlen(pattern);

    m=strlen(text);

    d1=d2=1;

    hashp1=hashp2=0;

    for(i=0;i<n;++i)

    {

        hashp1=(hashp1*73 +pattern[i])%100007;

        hashp2=(hashp2*73 +pattern[i])%100021;

        if(i)

        {

            d1=(d1*73)%100007;

            d2=(d2*73)%100021;

        }

    }

    for (i=0;i<n;++i)

    {

        hasht1=(hasht1*73 +text[i])%100007,

        hasht2=(hasht2*73 +text[i])%100021;

    }

    if(hasht1==hashp1&&hasht2==hashp2)

    {

        match[0]=true;

        nr++;

    }

    for (i=n;i<m;++i)

    {

        hasht1=((hasht1-(text[i-n]*d1)%100007 +100007)*73 +text[i])%100007;

        hasht2=((hasht2-(text[i-n]*d2)%100021 +100021)*73 +text[i])% 100021;



        if (hasht1==hashp1&&hasht2==hashp2)

        {

            match[i-n+1]=true;

            nr++;

        }

    }

    out<<nr<<'\n';

    nr=0;

    for (int i=0;nr<1000&&i<m;++i)

    {

        if(match[i])

        {

            out<<i<<" ";

            nr++;

        }

    }

 }

int main()

{

    in>>pattern>>text;

    if (n > m)

    {

        printf("0");

        return 0;

    }

    f();

    return 0;

 }
