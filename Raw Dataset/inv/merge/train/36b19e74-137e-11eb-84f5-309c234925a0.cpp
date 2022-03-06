#include <iostream>
#include <fstream>
using namespace std;



int nr=0;



void interclasare(int v[], int st, int dr)

{

    int mij = (st + dr) / 2;

    int i = st;

    int j = mij + 1;

    int k = 0;

    int n = dr - st + 1;

    int c[n];

    while (i <= mij && j <= dr)

    {

        if (v[i] <= v[j])

        {

            c[k] = v[i];

            k++;

            i++;

        }

        else

        {

            nr += mij - i + 1;

            nr = nr % 9917;

            c[k] = v[j];

            k++;

            j++;

        }

    }

    while (i <= mij)

    {

        c[k] = v[i];

        k++;

        i++;

    }

    while (j <= dr)

    {

        c[k] = v[j];

        k++;

        j++;

    }

    for (i=0; i<k; i++)

    {

        v[st+i] = c[i];

    }

}



void mergeSort(int v[], int st, int dr)

{

    int mij;

    if (st < dr)

    {

        mij = (st+dr) / 2;

        mergeSort(v,st,mij);

        mergeSort(v,mij+1,dr);

        interclasare(v,st,dr);

    }

}



int main()

{

    ifstream f("inv.in");

    ofstream g("inv.out");

    int n, v[100001];

    f>>n;

    for(int i=0; i<n; ++i)

        f>>v[i];

    f.close();

    mergeSort(v, 0, n-1);

    g << nr;

    g.close();

    return 0;

}
