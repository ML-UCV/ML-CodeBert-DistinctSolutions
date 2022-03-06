#include <bits/stdc++.h>


using namespace std;

ifstream f("strmatch.in");

ofstream g("strmatch.out");

vector<int> rez;

int main()

{

    string pat, txt;

    f >> pat >> txt;

    vector<int> lps(pat.size(), 0);

    int i = 1, len = 0;

    while (i < pat.size())

        if (pat[i] == pat[len])

            len++, lps[i] = len, i++;

        else if (len)

            len = lps[len - 1];

        else

            i++;

    i = 0;

    int j = 0;

    while (i < txt.size())

    {

        if (txt[i] == pat[j])

            i++, j++;

        if (j == pat.size())

            rez.push_back(i - j), j = lps[j - 1];

        else if (i < txt.size() && pat[j] != txt[i])

            if (j)

                j = lps[j - 1];

            else

                i++;

    }

    g << rez.size() << '\n';

    for (int i = 0; i < min(int(rez.size()), 1000); i++)

        g << rez[i] << " ";

    return 0;

}
