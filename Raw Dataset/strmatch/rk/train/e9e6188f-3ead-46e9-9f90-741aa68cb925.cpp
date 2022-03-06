#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

const int NMAX = 2000005;

const long long MOD1 = 1000000007;

const long long MOD2 = 1000000009;

const long long BAZA = 62;

char a[NMAX], b[NMAX];

long long kkt(char ch) {

    int ad = 0;

    if('0' <= ch && ch <= '9') {

        return ch - '0' + 1;

    }

    ad += ('9' - '0' + 1);

    if('A' <= ch && ch <= 'Z') {

        return ad + ch - 'A' + 1;

    }

    ad += ('Z' - 'A' + 1);

    return ad + ch - 'a' + 1;

}

vector <int> sol;



int main() {

    freopen("strmatch.in", "r", stdin);

    freopen("strmatch.out", "w", stdout);

    scanf("%s", a + 1);

    int n = (int)strlen(a + 1);

    long long c1 = 0, c2 = 0, p1 = 1, p2 = 1;

    for(int i = 1; i <= n; i++) {

        c1 = ((c1 * BAZA) + kkt(a[i])) % MOD1;

        c2 = ((c2 * BAZA) + kkt(a[i])) % MOD2;

        if(i < n) {

            p1 = (p1 * BAZA) % MOD1;

            p2 = (p2 * BAZA) % MOD2;

        }

    }

    scanf("%s", b + 1);

    int m = (int)strlen(b + 1);

    long long a1 = 0, a2 = 0;

    for(int i = 1; i <= m; i++) {

        if(i > n) {

            a1 = (a1 - (kkt(b[i - n]) * p1) % MOD1 + MOD1) % MOD1;

            a2 = (a2 - (kkt(b[i - n]) * p2) % MOD2 + MOD2) % MOD2;

        }

        a1 = ((a1 * BAZA) + kkt(b[i])) % MOD1;

        a2 = ((a2 * BAZA) + kkt(b[i])) % MOD2;

        if(i >= n) {

            if(a1 == c1 && a2 == c2) {

                sol.push_back(i - n);

            }

        }

    }

    printf("%d\n", sol.size());

    for(int i = 1; i <= 1000 && i <= sol.size(); i++) {

        printf("%d ", sol[i - 1]);

    }

    printf("\n");

    return 0;

}
