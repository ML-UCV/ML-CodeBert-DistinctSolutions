#include <bits/stdc++.h>
using namespace std;



ifstream fin("strmatch.in");

ofstream fout("strmatch.out");



int main() {

    string s, t; fin >> s >> t;

    string str = s + '#' + t;



    vector<int> pi(str.size());

    int k = 0;

    for (int i = 1; i < (int) str.size(); i++) {

        while (k && str[i] != str[k])

            k = pi[k - 1];

        if (str[i] == str[k])

            k++;

        pi[i] = k;

    }



    int cnt = 0;

    vector<int> ans;

    for (int i = s.size() + 1; i < (int) str.size(); i++)

        if (pi[i] == (int) s.size() && ++cnt <= 1000)

            ans.push_back(i - 2 * s.size());



    fout << cnt << '\n';

    for (int pos : ans)

        fout << pos << ' ';

    fout << '\n';



    fout.close();

    return 0;

}
