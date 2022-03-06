#include <bits/stdc++.h>
using namespace std;

ifstream f("strmatch.in");

ofstream g("strmatch.out");

string pat, txt;

vector<int> rez;

void computeLPSArray(int M, int *lps)

{

    int len = 0, i = 1;

    lps[0] = 0;

    while (i < M)

        if (pat[i] == pat[len])

            len++, lps[i] = len, i++;

        else if (len != 0)

            len = lps[len - 1];

        else

            lps[i] = 0, i++;

}

void KMPSearch()

{

    int M = pat.size(), N = txt.size(), lps[M], i = 0, j = 0;

    computeLPSArray(M, lps);

    while (i < N)

    {

        if (pat[j] == txt[i])

            j++, i++;

        if (j == M)

            rez.push_back(i - j), j = lps[j - 1];

        else if (i < N && pat[j] != txt[i])

            if (j != 0)

                j = lps[j - 1];

            else

                i = i + 1;

    }

}

int main()

{

    f >> pat >> txt;

    KMPSearch();

    g << rez.size() << '\n';

    for (int i = 0; i < min(int(rez.size()), 1000); i++)

        g << rez[i] << ' ';

    return 0;

}
