#include <bits/stdc++.h>


using namespace std;

ifstream fin("stramosi.in");
ofstream fout("stramosi.out");

int dp[21][250005];

int main() {
    int n, m;
    fin >> n >> m;
    for(int i = 1;i <= n; ++i){
        fin >> dp[0][i];
    }
    for(int j = 1;(1 << j) <= n; ++j)
    for(int i = 1;i <= n; ++i)
            dp[j][i] = dp[j-1][dp[j - 1][i]];
    while(m--){
        int q, p;
        fin >> q >> p;
        int ans = q;
        for(int j = 0;j <= 20; ++j){
            if((p & (1 << j)) != 0)
              ans = dp[j][ans];
        }
        fout << ans << "\n";
    }
    return 0;
}
