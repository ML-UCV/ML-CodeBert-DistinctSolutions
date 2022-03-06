#include <bits/stdc++.h>




using namespace std;



vector<int> h[26];

char a[50005], b[50005];

int P[50005], n, nrInv;





void Interclasare(int p, int m, int q)

{

    int i, j, k;

    int b[50005];

    i = p; j = m + 1; k = 0;

    while (i <= m && j <= q)

        if (P[i] <= P[j]) b[++k] = P[i++];

        else

        {

            nrInv += (m - i + 1);

            b[++k] = P[j++];

        }

    while (i <= m)

        b[++k] = P[i++];

    while (j <= q)

        b[++k] = P[j++];

    j = p;

    for (i = 1; i <= k; i++)

        P[j++] = b[i];

}



void Sch(int i, int j)

{

    int aux;

    if (P[i] > P[j])

    {

        nrInv++;

        aux = P[i];

        P[i] = P[j];

        P[j] = aux;

    }

}



void MergeSort(int p, int q)

{

    int m;

    if (q - p <= 1) Sch(p, q);

    else

    {

        m = (p + q) / 2;

        MergeSort(p, m);

        MergeSort(m + 1, q);

        Interclasare(p, m, q);

    }

}





int main()

{

    int i, j, n, m;

    ifstream fin("swap.in");

    ofstream fout("swap.out");

    fin >> (a + 1);

    fin >> (b + 1);

    fin.close();

    n = strlen(a+1);

    m = strlen(b+1);

    if (n != m)

    {

        fout << "-1\n";

        fout.close();

        return 0;

    }

    for (i = 1; b[i]; ++i)

        h[b[i]-'a'].push_back(i);

    for (i = n; i >= 1; --i)

    {

        j = a[i] - 'a';

        if (h[j].empty())

        {

            fout << "-1\n";

            fout.close();

            return 0;

        }

        m = h[j].size();

        P[i] = h[j][m-1];

        h[j].pop_back();

    }

    MergeSort(1, n);

    fout << nrInv << "\n";

    fout.close();

    return 0;

}
