#include <bits/stdc++.h>
using namespace std;



const int DIM = 2e6 + 5;

const int MOD1 = 1e9 + 7;

const int MOD2 = 1e9 + 9;

const int P = 66;



int n, m;

char A[DIM], B[DIM];

int f[260];



void add(int &H1, int &H2, int cif) {

    H1 = (1LL * H1 * P + cif) % MOD1;

    H2 = (1LL * H2 * P + cif) % MOD2;

}



int P1, P2;

void scoate(int &H1, int &H2, int cif) {

    H1 = (H1 - 1LL * cif * P1) % MOD1;

    if (H1 < 0) H1 += MOD1;



    H2 = (H2 - 1LL * cif * P2) % MOD2;

    if (H2 < 0) H2 += MOD2;

}



bool checkEqual(int H1, int H2, int h1, int h2) {

    if (H1 == h1 && H2 == h2) return true;

    return false;

}



int main() {

    freopen("strmatch.in", "r", stdin);

    freopen("strmatch.out", "w", stdout);



    scanf("%s", A + 1);

    scanf("%s", B + 1);



    n = strlen(A + 1);

    m = strlen(B + 1);



    int nr = 0;

    for (char i = 'a'; i <= 'z' ; ++i) f[i] = ++nr;

    for (char i = 'A'; i <= 'Z' ; ++i) f[i] = ++nr;

    for (char i = '0'; i <= '9' ; ++i) f[i] = ++nr;



    int hashA1 = 0, hashA2 = 0;

    for (int i = 1; i <= n ; ++i)

        add(hashA1, hashA2, f[A[i]]);



    int hashB1 = 0, hashB2 = 0;

    for (int i = 1; i <= n ; ++i)

        add(hashB1, hashB2, f[B[i]]);



    vector <int> v;

    if (checkEqual(hashA1, hashA2, hashB1, hashB2)) v.push_back(0);



    P1 = P2 = 1;

    for (int i = 1; i <= n - 1 ; ++i) {

        P1 = 1LL * P1 * P % MOD1;

        P2 = 1LL * P2 * P % MOD2;

    }



    for (int i = n + 1; i <= m ; ++i) {

        scoate(hashB1, hashB2, f[B[i - n]]);

        add(hashB1, hashB2, f[B[i]]);



        if (checkEqual(hashA1, hashA2, hashB1, hashB2)) v.push_back(i - n);

    }



    printf("%d\n", (int)v.size());

    while ((int)v.size() > 1000) v.pop_back();

    for (auto it : v) printf("%d ", it);



    return 0;

}
