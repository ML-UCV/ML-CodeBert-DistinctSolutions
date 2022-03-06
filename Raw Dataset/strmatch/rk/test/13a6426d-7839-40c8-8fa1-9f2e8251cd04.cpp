#include <bits/stdc++.h>
using namespace std;

const int P = 191;

const int MOD1 = 10000007;

const int MOD2 = 10000021;

ifstream fin("strmatch.in");

ofstream fout("strmatch.out");

string a, b;

int P1 = 1, P2 = 1, hash_a1, hash_a2, hash_b1, hash_b2, cnt, len_a, len_b;

vector<int> sol;



int main() {

    fin >> a >> b;



    len_a = a.length();

    len_b = b.length();



    if (len_a > len_b) {

        fout << 0;

        return 0;

    }



    for (int i = 0; i < len_a; i++) {

        hash_a1 = (hash_a1 * P + a[i] - '0' + 1) % MOD1;

        hash_a2 = (hash_a2 * P + a[i] - '0' + 1) % MOD2;

        if (i) {

            P1 = P1 * P % MOD1;

            P2 = P2 * P % MOD2;

        }

    }



    for (int i = 0; i < len_a; i++) {

        hash_b1 = (hash_b1 * P + b[i] - '0' + 1) % MOD1;

        hash_b2 = (hash_b2 * P + b[i] - '0' + 1) % MOD2;

    }



    if (hash_a1 == hash_b1 && hash_a2 == hash_b2) {

        cnt++;

        sol.push_back(0);

    }



    for (int i = len_a; i < len_b; i++) {

        hash_b1 = ((hash_b1 - ((b[i - len_a] - '0' + 1) * P1 % MOD1) + MOD1) % MOD1 * P + b[i] - '0' + 1) % MOD1;

        hash_b2 = ((hash_b2 - ((b[i - len_a] - '0' + 1) * P2 % MOD2) + MOD2) % MOD2 * P + b[i] - '0' + 1) % MOD2;



        if (hash_a1 == hash_b1 && hash_a2 == hash_b2) {

            cnt++;

            if (cnt <= 1000)

                sol.push_back(i - len_a + 1);

        }

    }



    fout << cnt << '\n';

    for (int i : sol)

        fout << i << ' ';

    return 0;

}
