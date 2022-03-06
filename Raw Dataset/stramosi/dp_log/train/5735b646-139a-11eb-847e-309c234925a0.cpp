#include <iostream>
#include <fstream>

using namespace std;

const int NMAX = 250000;
const int LOGMAX = 18;

ifstream fin("stramosi.in");
ofstream fout("stramosi.out");

int dp[LOGMAX + 1][NMAX + 1];

int main()
{
    int n,m,i,j,p,q,ans;
    fin >> n >> m;
    for(i=1; i<=n; i++)
        fin >> dp[0][i];
    for(i=1; i<=LOGMAX; i++)
        for(j=1; j<=n; j++)
            dp[i][j] = dp[i-1][dp[i-1][j]];
    while(m--){
        fin >> q >> p;
        ans = q;
        j = 0;
        while(p){
            if(p % 2)
                ans = dp[j][ans];
            p /= 2;
            j++;
        }
        fout << ans << "\n";
    }
    return 0;
}
