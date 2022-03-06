#include <iostream>
#include <fstream>


using namespace std;



int interclasare(int v[], int t[], int left, int mid, int right)

{

    int i=left, j=mid, k=left, nrInversiuni=0;

    while (i <= mid - 1 && j <= right)

    {

        if (v[i] <= v[j])

            t[k++] = v[i++];

        else

        {

            t[k++] = v[j++];

            nrInversiuni += mid - i;

        }

    }

    while (i <= mid - 1)

        t[k++] = v[i++];

    while (j <= right)

        t[k++] = v[j++];

    for (i = left; i <= right; i++)

        v[i] = t[i];

    return nrInversiuni%9917;

}



int inversiuni(int v[], int t[], int left, int right)

{

    int nrInversiuni{0};

    if (right > left)

    {

        int mid = (right + left) / 2;

        nrInversiuni = inversiuni(v, t, left, mid);

        nrInversiuni += inversiuni(v, t, mid + 1, right);

        nrInversiuni += interclasare(v, t, left, mid + 1, right);

    }

    return nrInversiuni%9917;

}



int main()

{

    ifstream fin("inv.in");

    int n;

    fin >> n;

    int v[n];

    for(int i=0; i<n; ++i)

        fin >> v[i];

    int t[n];

    ofstream fout("inv.out");

    fout << inversiuni(v, t, 0, n-1);

    return 0;

}
