#include <bits/stdc++.h>
using namespace std;



ifstream f("strmatch.in");

ofstream g("strmatch.out");



const int MAX = 2e6 + 10;



char A[MAX], B[MAX];

int pi[MAX], ans[1010], a, b, sol;



void PI()

{

    int q = 0;

    for(int i = 2; i <= a; ++i)

    {

        while(q && A[q + 1] != A[i])

            q = pi[q];

        if(A[q + 1] == A[i])

            ++q;

        pi[i] = q;

    }

}



int main()

{

    f >> (A + 1); a = strlen(A + 1);

    f >> (B + 1); b = strlen(B + 1);



    PI();



    int q = 0;

    for(int i = 1; i <= b; ++i)

    {

        while(q && A[q + 1] != B[i])

            q = pi[q];

        if(A[q + 1] == B[i])

            ++q;

        if(q == a)

        {

            ++sol;

            q = pi[q];

            if(sol <= 1000)

                ans[sol] = i - a;

        }

    }



    g << sol << "\n";

    for(int i = 1; i <= min(sol, 1000); ++i)

        g << ans[i] << " ";

    return 0;

}
