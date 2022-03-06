#include <iostream>
#include <cstdio>
#include <cstring>


using namespace std;



char s[2000005], p[2000005];

int nr, poz[2000005], lps[2000005], n, m;



void citire()

{

    scanf("%s\n", p);

    scanf("%s\n", s);

    n=strlen(p);

    m=strlen(s);

}



void lps_make()

{

    lps[0]=0;

    int len=0;

    for(int i=1;i<n;i++)

    {

        if(p[i]==p[len])

            lps[i]=++len;

        else

        {

            if(len)

                len=lps[len-1], i--;

            else

                lps[i]=0;

        }

    }

}



void comparare()

{

    int j=0;

    for(int i=0;i<m;i++)

    {

        if(s[i]==p[j])

            j++;

        else

        {

            if(j)

                j=lps[j-1], i--;

        }

        if(j==n)

            poz[nr++]=i-j+1, j=lps[j-1];

    }

}



void afisare()

{

    cout<<nr<<'\n';

    if(nr>1000)

        nr=1000;

    for(int i=0;i<nr;i++)

        cout<<poz[i]<<' ';

}



int main()

{

    freopen("strmatch.in","r", stdin);

    freopen("strmatch.out","w", stdout);

    citire();

    lps_make();

    comparare();

    afisare();

    return 0;

}
