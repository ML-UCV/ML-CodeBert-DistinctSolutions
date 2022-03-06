#include <bits/stdc++.h>
using namespace std;

ifstream fi("strmatch.in");

ofstream fo("strmatch.out");



const int NMAX = 2e6 + 5;

const int MOD1 = 1e9 + 6;

const int SIGMA = 63;



char pat[NMAX], A[NMAX];

int m, n;

int codPat, codSir;



int codCaracter(char x) {

    if ('A' <= x && x <= 'Z')

        return x - 'A' + 1;

    else if ('a' <= x && x <= 'z')

        return x - 'a' + 26 + 1;

    else

        return x - '0' + 26 + 26 + 1;

}



int main()

{

    fi >> pat + 1 >> A + 1;

    m = strlen(pat + 1);

    n = strlen(A + 1);



    codPat = 0;

    for (int i = 1; i <= m; i++) {

        codPat = (1LL * codPat * SIGMA + codCaracter(pat[i])) % MOD1;

    }



    vector <int> ans;

    codSir = 0;

    for (int i = 1; i <= m; i++) {

        codSir = (1LL * codSir * SIGMA + codCaracter(A[i])) % MOD1;

    }



    int putere = 1;

    for (int i = 1; i <= m - 1; i++)

        putere = 1LL * putere * SIGMA % MOD1;



    for (int i = m + 1; i <= n; i++) {



        if (codPat == codSir) {

            ans.push_back(i - m - 1);

        }

        codSir = ((long long)codSir - 1LL * putere * codCaracter(A[i - m]) + 100LL * MOD1) % MOD1;



        codSir = (1LL * codSir * SIGMA + codCaracter(A[i])) % MOD1;



    }

    if (codPat == codSir) {

        ans.push_back(n - m);

    }



    fo << ans.size() << "\n";

    for (int i = 0; i < min((int)ans.size(), 1000); i++)

        fo << ans[i] << " ";





    return 0;

}
