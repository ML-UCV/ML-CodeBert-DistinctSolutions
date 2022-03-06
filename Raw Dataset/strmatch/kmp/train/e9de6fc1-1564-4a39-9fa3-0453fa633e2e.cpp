#include <bits/stdc++.h>


using namespace std;

ifstream f("strmatch.in");

ofstream g("strmatch.out");

string pat, s;

vector<int> lps;

void preproc()

{

    lps.resize(pat.size(), 0);

    for (int j = 1, len = 0; j < pat.size();)

        if (pat[j] == pat[len])

            len++, lps[j] = len, j++;

        else if (len)

            len = lps[len - 1];

        else

            j++;

}

int main()

{

    f >> pat >> s;

    preproc();

    vector<int> rez;

    for (int i = 0, j = 0; i < s.size();)

    {

        if (s[i] == pat[j])

            i++, j++;

        if (j == pat.size())

            rez.push_back(i - j), j = lps[j - 1];

        else if (i < s.size() && pat[j] != s[i])

            if (j)

                j = lps[j - 1];

            else

                i++;

    }

    g << rez.size() << '\n';

    if (rez.size() > 1000)

        rez.resize(1000);

    for (auto i : rez)

        g << i << " ";

    return 0;

}
