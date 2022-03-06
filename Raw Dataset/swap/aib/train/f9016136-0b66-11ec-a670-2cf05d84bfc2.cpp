#include <bits/stdc++.h>


using namespace std;



ifstream fin("swap.in");

ofstream fout("swap.out");



int N;

vector < int > BIT;



void update(int index) {

    for(int i = index; i <= N; i += i & -i)

        ++BIT[i];

}



int query(int index) {

    int ans = 0;

    for(int i = index; i > 0; i -= i & -i)

        ans += BIT[i];

    return ans;

}



int main() {

    string s, t;

    fin >> s >> t;

    vector < int > fs(26), ft(26);

    for(char x : s)

        ++fs[x - 'a'];

    for(char x : t)

        ++ft[x - 'a'];

    bool ok = true;

    for(int i = 0; i < 26 && ok; ++i)

        if(fs[i] != ft[i])

            ok = false;

    if(!ok) {

        fout << -1;

        return 0;

    }

    vector < int > from_s[26], from_t[26];

    N = s.size();

    s = '0' + s, t = '0' + t;

    for(int i = 1; i <= N; ++i)

        from_s[s[i] - 'a'].emplace_back(i);

    for(int i = 1; i <= N; ++i)

        from_t[t[i] - 'a'].emplace_back(i);

    vector < int > perm(N + 1);

    for(int i = 0; i < 26; ++i)

        for(int j = 0; j < (int)from_t[i].size(); ++j) {

            int poz = from_t[i][j];

            perm[poz] = from_s[i][j];

        }

    int ans = 0;

    BIT.resize(N + 1);

    for(int i = N; i > 0; --i) {

        ans += query(perm[i]);

        update(perm[i]);

    }

    fout << ans;

}
