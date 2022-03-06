#include <bits/stdc++.h>

using namespace std;
const int NMAX = 1e6;

vector <int> ans;

int pi[NMAX * 2 + 1];
char a[NMAX * 2 + 2], b[NMAX * 2 + 1];

int main() {
    freopen("strmatch.in", "r", stdin);
    freopen("strmatch.out", "w", stdout);

    int n, m, nr = 0;
    scanf("%s\n", (a + 1));
    n = strlen(a + 1);
    a[++n] = '#';
    scanf("%s", (b + 1));
    m = strlen(b + 1);


    pi[1] = 0;
    int k = 0;
    for (int i = 2; i <= n; i++) {
        while (k!= 0 && a[ i ] != a[k + 1]) {
            k = pi[k];
        }
        if (a[ i ] == a[k + 1]) {
            k++;
        }
        pi[ i ] = k;
    }

    k = 0;
    for (int i = 1; i <= m; i++) {
        while (k != 0 && b[ i ] != a[k + 1]) {
            k = pi[ k ];
        }
        if (b[ i ] == a[k + 1]) {
            k++;
        }
        if (k == n-1) {
            nr++;
            if (ans.size() < 1000) {
                ans.push_back(i - n + 1);
            }
        }
    }

    cout << nr << '\n';
    for (auto idx: ans) {
        cout << idx << " ";
    }

}
