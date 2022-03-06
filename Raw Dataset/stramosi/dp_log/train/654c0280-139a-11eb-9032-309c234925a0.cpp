#include <bits/stdc++.h>


using namespace std;



ifstream fin ("stramosi.in");

ofstream fout("stramosi.out");



const int N_MAX = 250000 + 5;



int dp[50][N_MAX], n, m;



int stramosi(int i, int n){

    int pow = 0;

    int ans = i;

    while(n){

        if(n%2)

            ans = dp[pow][ans];

         pow ++;

        n /= 2;

    }

    return ans;

}



int main()

{

    fin >> n >> m;

    for(int i = 1; i<=n; ++i)

        fin >> dp[0][i];

    for(int pow = 1; pow <= 30; ++pow)

        for(int i = 1; i <=n; ++i)

            dp[pow][i] = dp[pow-1][dp[pow-1][i]];



    while(m--){

        int a, b;

        fin >> a >> b;

        fout << stramosi(a, b) << "\n";

    }



    return 0;

}
