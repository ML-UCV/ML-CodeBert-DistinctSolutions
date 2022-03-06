#include <iostream>
#include <fstream>
using namespace std;

int nr;

void merges(long long int v[],int l,int m,int r)

{

    int i, j, k;

    int n1 = m - l + 1;

    int n2 = r - m;

    int L[n1], R[n2];



     for (i = 0; i < n1; i++)

        L[i] = v[l + i];

    for (j = 0; j < n2; j++)

        R[j] = v[m + 1+ j];

    i = 0;

    j = 0;

    k = l;

    while (i < n1 && j < n2)

    {

        if (L[i] <= R[j])

        {

            v[k] = L[i];

            i++;

        }

        else

        {nr += n1-i;

            nr = nr % 9917;

            v[k] = R[j];

            j++;

        }

        k++;

    }

  while (i < n1)

    {

        v[k] = L[i];

        i++;

        k++;

    }



    while (j < n2)

    {

        v[k] = R[j];

        j++;

        k++;

    }



}





void mergesort(long long int v[],int l,int r)

{

    if(l<r)

    {

        int m=l+(r-l)/2;

        mergesort(v,l,m);

        mergesort(v,m+1,r);

        merges(v,l,m,r);

    }

}



int main()

{

  ifstream f("inv.in");

  ofstream g("inv.out");

  long long int v[100001];

    int n, i;

    f>> n;

    for (i=1;i<=n;i++)

        f>>v[i];

mergesort(v,1,n);





g<<nr;

return 0;

}
