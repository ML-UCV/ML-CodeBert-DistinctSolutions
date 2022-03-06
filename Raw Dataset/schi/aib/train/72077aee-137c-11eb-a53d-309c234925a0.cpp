#include <fstream>
using namespace std;

ifstream fin ("schi.in");

ofstream fout ("schi.out");

struct ura

{

    int nr,a,sol;

};

ura v[30001];

int len (int x)

{

    return x-(x&(x-1));

}

int main ()

{

    int n,i,cnr,r,p;

    fin>>n;

    for (i=1;i<=n;i++)

    {

        fin>>v[i].nr;

        v[i].a=len(i);

    }

    for (i=n;i>=1;i--)

    {

        cnr=v[i].nr;

        r=0;

        p=1<<15;

        while (p!=0)

        {

            if (p+r<=n && v[p+r].a<cnr)

            {

                r+=p;

                cnr-=v[r].a;

            }

            p/=2;

        }

        r++;

        v[r].sol=i;

        while (r<=n)

        {

            v[r].a--;

            r+=len(r);

        }

    }

    for (i=1;i<=n;i++)

        fout<<v[i].sol<<'\n';

    return 0;

}
