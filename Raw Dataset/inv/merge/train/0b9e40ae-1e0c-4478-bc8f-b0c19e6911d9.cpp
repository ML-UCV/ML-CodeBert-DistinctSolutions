#include <bits/stdc++.h>


using namespace std;



ifstream fin("inv.in");

ofstream fout("inv.out");



int n, v[100002], inter[100002], inv;



void Interclasare(int v[], int st, int dr)

{

    int j, k, i, mij;

    mij = (st + dr) / 2;

    j = mij + 1;

    i = st;

    k = 0;

    while(i <= mij && j <= dr)

    {

        if(v[i] <= v[j])

           inter[++k] = v[i++];

        else

        {

            inv += mij - i + 1;

            inv = inv % 9917;

            inter[++k] = v[j++];

        }

    }



    while(i <= mij)

        inter[++k] = v[i++];

    while(j <= dr)

        inter[++k] = v[j++];

    for(i = 1; i <= k; i++)

        v[st + i - 1] = inter[i];

}



void Mergesort(int v[], int st, int dr)

{

    if(st < dr)

    {

        int mij = (st + dr) / 2;

        Mergesort(v, st, mij);

        Mergesort(v, mij + 1, dr);

        Interclasare(v, st, dr);

    }

}



int main()

{

    int i, j;

    fin >> n;

    for(i = 1; i <= n; i++)

        fin >> v[i];

    Mergesort(v, 1, n);

    fout << inv;

    return 0;

}
