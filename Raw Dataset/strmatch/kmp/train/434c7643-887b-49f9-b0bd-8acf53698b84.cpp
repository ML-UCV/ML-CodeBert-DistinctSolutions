#include <fstream>
#include <cstring>
using namespace std;

ifstream cin("strmatch.in");

ofstream cout("strmatch.out");

const int NMAX = 2e6+5;



int n,m,pi[NMAX],pos[(1<<10)];

char a[NMAX],b[NMAX];

void make_prefix()

{

    int q=0,i;

    for(i=2,pi[1]=0;i<=n;++i)

    {

        while(q && a[q+1]!=a[i])

            q=pi[q];

        if(a[q+1]==a[i])

            ++q;

        pi[i]=q;

    }

}

int main()

{

    int q=0,nr=0;

    cin>>a>>b;

    n=strlen(a);

    m=strlen(b);

    for(int i=n;i;i--)

        a[i]=a[i-1];

    a[0]=' ';

    for(int i=m;i;--i)

    b[i]=b[i-1];

    b[0]=' ';

    make_prefix();

    for(int i=1;i<=m;i++)

    {

        while(q && a[q+1]!=b[i])

            q=pi[q];

        if(a[q+1]==b[i])

            q++;

        if(q==n)

        {

            q=pi[n];

            ++nr;

            if(nr<=1000)

                pos[nr]=i-n;

        }

    }

    cout<<nr<<endl;

    for(int i=1;i<=min(nr,1000);++i)

        cout<<pos[i]<<" ";

    return 0;

}
