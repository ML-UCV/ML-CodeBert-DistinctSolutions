#include <bits/stdc++.h>


using namespace std;



ifstream fin("strmatch.in");

ofstream fout("strmatch.out");

const int MAXN = 2000005, BASE = 256, MOD[2] = {2000003, 2000029}, MAX = 1000;



char sub[MAXN], str[MAXN];

int res[MAX + 5], subH[2], strH[2], s, n, power[2], nr;



void getHash()

{

    power[0] = power[1] = 1;

    for (int i = 0; i < s; ++i) {

        for (int k = 0; k < 2; ++k)

            subH[k] = (subH[k] * BASE + sub[i]) % MOD[k],

            strH[k] = (strH[k] * BASE + str[i]) % MOD[k];

        if (i)

            for (int k = 0; k < 2; ++k)

                power[k] = (power[k] * BASE) % MOD[k];

    }

}



void solve()

{

    if (subH[0] == strH[0] && subH[1] == strH[1])

        res[nr++] = 0;

    for (int i = s; i < n; ++i) {

        strH[0] = ((strH[0] - (power[0] * str[i - s]) % MOD[0] + MOD[0]) * BASE + str[i]) % MOD[0];

        strH[1] = ((strH[1] - (power[1] * str[i - s]) % MOD[1] + MOD[1]) * BASE + str[i]) % MOD[1];

        if (subH[0] == strH[0] && subH[1] == strH[1]) {

            if (nr >= MAX)

                ++nr;

            else

                res[nr++] = i - s + 1;

        }

    }

}



void print()

{

    fout << nr << '\n';

    nr = min(nr, MAX);

    for (int i = 0; i < nr; ++i)

        fout << res[i] << ' ';

}



int main()

{

    fin >> sub >> str;

    n = strlen(str);

    s = strlen(sub);

    getHash();

    solve();

    print();

    return 0;

}
