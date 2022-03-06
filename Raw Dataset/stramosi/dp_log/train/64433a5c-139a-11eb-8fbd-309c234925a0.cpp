#include <bits/stdc++.h>


using namespace std;



int tati[250005];

int dp[250005][30];



int main()

{

    ifstream fin("stramosi.in");

    ofstream fout("stramosi.out");

    int n, m;

    fin >> n >> m;

    for(int i = 1; i <= n; ++i){

        fin >> tati[i];

        dp[i][0] = tati[i];

    }

    for(int i = 1; i <= n; ++i){

        for(int j = 1; j <= 20; ++j)

            dp[i][j] = dp[dp[i][j - 1]][j - 1];

    }

    while(m){

        int x, y;

        fin >> x >> y;

        int curent = x;

        for(int p = 20; p >= 0; p--){

            if((1 << p) <= y){

                curent = dp[curent][p];

                y -= (1 << p);

            }

        }

        fout << curent << "\n";

        m--;

    }

    return 0;

}
