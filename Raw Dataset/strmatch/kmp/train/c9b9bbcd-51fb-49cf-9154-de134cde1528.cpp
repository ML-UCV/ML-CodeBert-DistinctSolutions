#include <bits/stdc++.h>


using namespace std;



ifstream fin("strmatch.in");

ofstream fout("strmatch.out");



int n, m, nsol;

int pi[2000001], sol[1001];

char pat[2000001], str[2000001];



void make_prefix()

{

    pi[1] = 0;

    int k = 0;

    for(int q = 2; q <= m; ++q)

    {

        while(k > 0 && pat[k + 1] != pat[q]) k = pi[k];

        if(pat[k + 1] == pat[q]) ++k;

        pi[q] = k;

    }

}



int main()

{

    fin >> (pat + 1);

    fin >> (str + 1);

    m = strlen(pat + 1);

    n = strlen(str + 1);



    make_prefix();



    int q = 0;

    for(int i = 1; i <= n; ++i)

    {

        while(q > 0 && pat[q + 1] != str[i]) q = pi[q];

        if(pat[q + 1] == str[i]) ++q;

        if(q == m)

        {

            ++nsol;

            q = pi[m];

            if(nsol <= 1000) sol[nsol] = i - m;

        }

    }



    fout << nsol << "\n";

    for(int i = 1; i <= min(nsol, 1000); ++i) fout << sol[i] << " ";

    return 0;

}
