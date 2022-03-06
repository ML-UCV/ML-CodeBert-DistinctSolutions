#include <bits/stdc++.h>


using namespace std;



ifstream fin ("inv.in");

ofstream fout ("inv.out");



int n, a[100007], raspuns;



void Citire()

{

    fin >> n;

    for (int i = 1; i <= n; i++)

        fin >> a[i];

}



void Interclasare(int st, int dr)

{

    int mij, i, j, k = 0, aux[dr - st + 7];

    mij = (st + dr) / 2;

    i = st;

    j = mij + 1;



    while (i <= mij && j <= dr)

    {

        if (a[i] <= a[j])

            aux[++k] = a[i++];

        else

        {

            raspuns += mij - i + 1;

            raspuns %= 9917;

            aux[++k] = a[j++];

        }

    }



    while(i <= mij)

        aux[++k] = a[i++];



    while(j <= dr)

        aux[++k] = a[j++];



    for (i = 1; i <= k; i++)

        a[st + i - 1] = aux[i];

}



void MergeSort(int st, int dr)

{

    int mij;

    if (st < dr)

    {

        mij = (st + dr) / 2;

        MergeSort(st, mij);

        MergeSort(mij + 1, dr);

        Interclasare(st, dr);

    }

}



int main()

{

    Citire();

    MergeSort(1, n);

    fout << raspuns << "\n";

    fin.close();

    fout.close();

    return 0;

}
