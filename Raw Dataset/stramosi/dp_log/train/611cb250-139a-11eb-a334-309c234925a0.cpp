#include <bits/stdc++.h>


using namespace std;



ifstream f("stramosi.in");

ofstream g("stramosi.out");



const int NMAX = 250005;

const int LMAX = 30;

int dp[LMAX][NMAX],lg[NMAX];

int n,q;



int main(){

    int i,x,y,j;

    f >> n >> q;

    for(i = 1 ; i <= n ; i++)

        f >> dp[0][i];

    for(i = 2 ; i <= n ; i++)

        lg[i] = lg[i / 2] + 1;



    j = 1;

    while((1 << j) <= n){

        for(i = 1 ; i <= n ; i++)

            dp[j][i] = dp[j - 1][dp[j - 1][i]];

        j++;

    }



    while(q--){

        f >> x >> y;

        while(y && x != 0){

            x = dp[lg[y]][x];

            y = y - (1 << lg[y]);

        }

        g << x << "\n";

    }



    return 0;

}
