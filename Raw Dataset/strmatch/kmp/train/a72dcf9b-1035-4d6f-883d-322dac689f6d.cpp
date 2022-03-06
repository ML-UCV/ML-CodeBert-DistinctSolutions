#include <fstream>
#include <cstring>
using namespace std;

ifstream f("strmatch.in");

ofstream g("strmatch.out");

char a[2000005],b[2000005];

int i,j,n,m,PI[2000005],k,sol[2000005];

int main()

{

    f>>b+1>>a+1;

    n=strlen(a+1);

    m=strlen(b+1);

    i=2;

    j=0;

    while(i<=m)

    {

        while (j&&b[j+1]!=b[i])

            j=PI[j];

        if (b[j+1]==b[i])

            j++;

        PI[i]=j;

        i++;

    }

    i=1;

    j=0;

    while(i<=n)

    {

        while(a[i]!=b[j+1]&&j!=0)

            j=PI[j];

        if(a[i]==b[j+1])

            j++;

        if(j==m)

            {

                sol[++k]=i-m;

                j=PI[j];

            }

        i++;

    }

    g<<k<<'\n';

    for(i=1; i<=min(k,1000); i++)

        g<<sol[i]<<' ';

    return 0;

}
