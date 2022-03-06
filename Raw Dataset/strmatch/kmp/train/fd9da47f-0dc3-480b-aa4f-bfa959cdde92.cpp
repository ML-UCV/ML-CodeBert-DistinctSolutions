#include <fstream>
#include <cstring>
#include <iostream>


using namespace std;

ifstream f("strmatch.in");

ofstream g("strmatch.out");



char a[2000004],b[2000004];

int pi[2000004],v[1004],nr,aa,bb;



void kmp1()

{

    int k=0;

    for(int i=1;i<=bb;++i)

    {

        while(k && a[k+1]!=b[i])

            k=pi[k];

        if(a[k+1]==b[i]) ++k;

        if(k==aa)

        {

            ++nr;

            if(nr<=1000)

                v[nr]=i;

        }

    }

}

void kmp()

{

    int k=0;

    for(int i=2;i<=aa;++i)

    {

        while(k && a[k+1]!=a[i])

            k=pi[k];

        if(a[k+1]==a[i])++k;

        pi[i]=k;

    }

}

int main()

{

    f>>(a+1);

    f>>(b+1);

    aa=strlen(a+1);

    bb=strlen(b+1);

    kmp();

    kmp1();

    g<<nr<<'\n';

    if(nr>1000) nr=1000;

    for(int i=1;i<=nr;++i)

        g<<v[i]-aa<<' ';

    return 0;

}
