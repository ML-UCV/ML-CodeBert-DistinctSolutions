#include <fstream>
#include <vector>


using namespace std;

ifstream fin("schi.in");

ofstream fout("schi.out");

int n,v[30001],sol[30001],aib[30001];

int suma(int poz1)

{

    int S=0;

    for (int i=poz1;i>0;i-=(i&(-i)))

    {

        S+=aib[i];

    }

    return S;

}

void update(int poz1)

{

    for (int i=poz1;i<=n;i+=(i&(-i))){

        aib[i]--;

    }

}

int cautare(int p,int u,int val)

{

    int min1=1000001;

    while (p<=u)

    {

        int m=(p+u)/2;

        int S=suma(m);

        if (val==S && m<min1)

            min1=m;

        if (val<=S)

            u=m-1;

        else

            p=m+1;

    }

    return min1;

}

int main()

{

    int i,a;

    fin>>n;

    for (i=1;i<=n;i++)

    {

        fin>>v[i];

        aib[i]=i&(-i);

    }

    for (i=n;i>=1;i--)

    {

       int q=cautare(1,n,v[i]);

       update(q);

       sol[q]=i;

    }

    for (i=1;i<=n;i++)

        fout<<sol[i]<<"\n";

    return 0;

}
