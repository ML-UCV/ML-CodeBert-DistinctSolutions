#include <fstream>


using namespace std;

ifstream in("schi.in");

ofstream out("schi.out");

int aib[30001],i,n,v[30001],ans[30001],k;

void Add(int x, int quantity)

{

    int i;

    for (i=x; i <= n; i += ( (i ^ (i - 1)) & i ))

    {

        aib[i] += quantity;

    }

}

int Compute(int x)

{

    int i, ret = 0;

    for (i = x; i > 0; i -= ( (i ^ (i - 1)) & i ))

    {

        ret += aib[i];

    }

    return ret;

}

int bs (int val)

{

    int poz = 0;

    for (int i = n - 1; i > 0; i >>=1)

    {

        while (poz + i < n && Compute(poz + i) < val)

        {

            poz += i;

        }

    }

    return poz + 1;

}

int main()

{

    in >> n;

    n+=1;

    for (i = 1; i < n; i++)

    {

        in >> v[i];

        aib[i] = ( (i ^ (i - 1)) & i );

    }

    for (i = n - 1; i > 0; i--)

    {

        k = bs(v[i]);

        ans[k] = i;

        Add(k, -1);

    }

    for (i = 1; i < n; i++)

        {

            if(i%1==0)

            {

                out<<ans[i]<< '\n';

            }

        }

    return 0;

}
