#include <fstream>


using namespace std;

int n,m,i,x,nr,kmp[4000005];

char c1[2000005],c2[2000005],v[4000005];

int main()

{

    ifstream f("strmatch.in");

    ofstream g("strmatch.out");

    f>>c1;

    f>>c2;

    while(c1[n])

    {

        n++;

        v[n]=c1[n-1];

    }

    while(c2[m])

    {

        m++;

        v[n+m]=c2[m-1];

    }

    kmp[0]=-1;

    for(i=1; i<=n+m; i++)

    {

        x=kmp[i-1];

        while(x>=0&&v[x+1]!=v[i])

        {

            x=kmp[x];

        }

        x++;

        while(x>n) x=kmp[x];

        kmp[i]=x;

        if(i>=2*n&&kmp[i]==n)

        {

            nr++;

        }

    }

    g<<nr<<'\n';

    nr=0;

    for(i=2*n; i<=m+n&&nr<1000; i++)

    {

        if(kmp[i]==n)

        {

            nr++;

            g<<i-2*n<<" ";

        }

    }

    f.close(); g.close();

    return 0;

}
