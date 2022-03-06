#include <bits/stdc++.h>


using namespace std;



const int NMAX = 4000005;

string s, t;

int z[NMAX];



int main()

{

    ifstream fin("strmatch.in");

    ofstream fout("strmatch.out");

    fin >> s >> t;

    int sz = s.length();

    s = s + "#" + t;

    int left = 0, right = 0;

    for (int i = 1;i < s.length();++i)

    {

        if (i > right)

        {

            left = right = i;

            while (right < s.length() && s[right] == s[right - left])

                ++right;

            z[i] = right - left;

            --right;

        }

        else

        {

            if (i + z[i - left] - 1 < right)

                z[i] = z[i - left];

            else

            {

                left = i;

                while (right < s.length() && s[right] == s[right - left])

                    ++right;

                z[i] = right - left;

                --right;

            }

        }

    }

    int cnt = 0;

    vector <int> answer;

    for (int i = sz;i < s.length();++i)

        if (z[i] == sz)

        {

            ++cnt;

            if (cnt <= 1000)

                answer.push_back(i - sz - 1);

        }

    fout << cnt << "\n";

    for (auto& i : answer)

        fout << i << " ";

    fin.close();

    fout.close();

    return 0;

}
