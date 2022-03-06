#include <iostream>
#include <fstream>
using namespace std;

ifstream f("inv.in");

ofstream g("inv.out");

const int MOD = 9917;

int N, S[100001], T[100001], nrinv;

void interclasare(int p, int u, int m)

{

    int i = p, j = m + 1, k = 0;

    while(i <= m && j <= u)

        if(S[i] <= S[j])

            T[++k] = S[i++];

        else

        {

            T[++k] = S[j++];

            nrinv = (nrinv + m - i + 1) % MOD;

        }

    while(i <= m)

        T[++k] = S[i++];

    while(j <= u)

        T[++k] = S[j++];

    for(i = p, k = 1; i <= u; i++, k++)

        S[i] = T[k];

}

void MergeSort(int p, int u)

{

    if(p < u)

    {

        int m = p + (u - p) / 2;

        MergeSort(p, m);

        MergeSort(m + 1, u);

        interclasare(p, u, m);

    }

}

int main()

{

    f >> N;

    for(int i = 1; i <= N; i++)

        f >> S[i];

    MergeSort(1,N);

    g << nrinv;

    return 0;

}
