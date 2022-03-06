#include <bits/stdc++.h>


using namespace std;



const int NMAX = 4000005;

int pi[NMAX];

string s, t;



int main()

{

    ifstream fin("strmatch.in");

    ofstream fout("strmatch.out");

    fin >> s >> t;

    int sz = s.length();

    s = s + "#" + t;

    for (int i = 1, k = 0;i < s.length();++i)

    {

        for (;k > 0 && s[k] != s[i];k = pi[k - 1]);

        if (s[k] == s[i])

            ++k;

        pi[i] = k;

    }

    int cnt = 0;

    vector <int> answer;

    for (int i = sz;i < s.length();++i)

    {

        if (pi[i] == sz)

        {

            ++cnt;

            if (cnt <= 1000)

                answer.push_back(i - 2 * sz);

        }

    }

    fout << cnt << "\n";

    for (auto& i : answer)

        fout << i << " ";

    fin.close();

    fout.close();

    return 0;

}
