#include <iostream>
#include <fstream>


using namespace std;



ifstream f("inv.in");

ofstream g("inv.out");



const int MOD = 9917;

int N, S[100001], T[100001], nrInv;



void Interclasare(int p, int u, int m)

{

    int i = p, j = m + 1, k = 0;

    while(i <= m && j <= u)

        if(S[i] <= S[j])

            T[++k] = S[i++];

        else

        {

            T[++k] = S[j++];

            nrInv = (nrInv + m - i + 1) % MOD;

        }

    while(i <= m)

        T[++k] = S[i++];

    while(j <= u)

        T[++k] = S[j++];

    for(int i = p, k = 1; i <= u; i++, k++)

        S[i] = T[k];

}



void Mergesort(int p, int u)

{

    if(p < u)

    {

        int m = p + (u - p) / 2;

        Mergesort(p, m);

        Mergesort(m + 1, u);

        Interclasare(p, u, m);

    }

}



int main()

{

    f>>N;

    for(int i=1;i<=N;i++)

        f>>S[i];

    Mergesort(1,N);

    g<<nrInv;

    return 0;

}
