#include <iostream>
#include <fstream>


using namespace std;



ifstream in("inv.in");

ofstream out("inv.out");

int aux[100001];

int n;

void afisare(int v[])

{

    int i;

    for(i=1; i<=n; i++)

        out<<v[i]<<" ";

    out<<endl;

}

long long interclasare(int v[], int st, int dr)

{

    int i, j, k, m = (st + dr) / 2;

    i = k = st;

    j = m + 1;

    long long r = 0;

    while (i <= m && j <= dr)

    {

        if (v[i] <= v[j])

        {

            aux[k++] = v[i++];

        }

        else

        {

            aux[k++] = v[j++];

            r += m - i + 1;

        }

    }

    while (i <= m)

    {

        aux[k++] = v[i++];

    }

    while (j <= dr)

    {

        aux[k++] = v[j++];

    }

    for (k = st; k <= dr; k++)

    {

        v[k] = aux[k];

    }

    return r;

}



long long sortare(int v[], int st, int dr)

{

    if (st == dr)

    {

        return 0;

    }

    int m = (st + dr) / 2;

    long long r = 0;

    r += sortare(v, st, m);

    r += sortare(v, m + 1, dr);

    r += interclasare(v, st, dr);



    return r;

}



int main()

{

    int v[100001],i;

    in>>n;

    for(i=1; i<=n; i++)

        in>>v[i];

    out << sortare(v,1,n)%9917;

    return 0;

}
