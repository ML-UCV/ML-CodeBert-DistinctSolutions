#include <iostream>
#include <fstream>


using namespace std;

ifstream f("schi.in");

ofstream g("schi.out");

int aib[30005],n,v[30005],a[30005];

void update(int poz,int val)

{

    int i;

    for(i=poz;i<=n;i=i+( i & (-i) ))

    {

        aib[i]+=val;

    }

}

int suma(int poz)

{

    int i,s=0;

    for(i=poz;i>=1;i=i-( i & (-i) ))

    {

        s=s+aib[i];

    }

    return s;

}

int main()

{

    int i,st,dr,mij,val,s;

    f>>n;

    for(i=1;i<=n;i++)

    {

        f>>a[i];

        update(i,1);

    }

    for(i=n;i>=1;i--)

    {

        st=1;

        dr=n;

        val=0;

        while(st<=dr)

        {

            mij=(st+dr)/2;

            s=suma(mij);

            if(s==a[i])

            {

                val=mij;

                dr=mij-1;

            }

            else

            {

                if(s<a[i])

                {

                    st=mij+1;

                }

                else

                {

                    dr=mij-1;

                }

            }

        }

        v[val]=i;

        update(val,-1);

    }

    for(i=1;i<=n;i++)

        g<<v[i]<<"\n";

    return 0;

}
