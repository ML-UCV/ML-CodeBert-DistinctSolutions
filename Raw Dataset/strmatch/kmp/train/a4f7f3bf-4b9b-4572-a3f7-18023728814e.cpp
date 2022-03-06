#include <fstream>
#include <cstring>




using namespace std;

ifstream f("strmatch.in");

ofstream g("strmatch.out");



char A[2000002],B[2000002];

int pi[2000002],a,b,nr=0,sol[1002];



void kmp()

{

    int k=0;

    for(int i=1;i<=b;++i)

    {

        while(k && A[k+1]!=B[i]) k=pi[k];

        if(A[k+1]==B[i]) ++k;

        if(k==a)

        {

            ++nr;

            if(nr<=1000)

                sol[nr]=i;

        }

    }

}

void kmp1()

{

    int k=0;

    for(int i=2;i<=a;++i)

    {

        while(k && A[k+1]!=A[i]) k=pi[k];

        if(A[k+1]==A[i]) ++k;

        pi[i]=k;

    }

}

int main()

{

    f>>A+1;

    f>>B+1;

    a=strlen(A+1);

    b=strlen(B+1);

    kmp1();

    kmp();

    g<<nr<<'\n';

    for(int i=1;i<=min(nr,1000);++i)

        g<<sol[i]-a<<' ';

    f.close();

    g.close();

    return 0;

}
