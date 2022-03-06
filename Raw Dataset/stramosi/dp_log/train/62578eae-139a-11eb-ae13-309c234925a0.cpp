#include <iostream>
#include <fstream>
#include <cmath>


const int MAXN = 25e4 + 5;

const int MAXLOG = log2(MAXN) + 1;



using namespace std;



ifstream in("stramosi.in");

ofstream out("stramosi.out");



int n,m,dp[MAXN][MAXLOG],tata[MAXN];





int query(int nod,int x){

    for(int bit = 0; bit <= MAXLOG; bit++)

        if((x & (1 << bit)) > 0)

            nod = dp[nod][bit];

    return nod;

}



int main()

{

    int querys;

    in>>n>>querys;

    for(int i = 1; i <= n; i++){

        in>>tata[i];

        dp[i][0] = tata[i];

    }

    for(int i = 1; i <= n; i++){

        for(int j = 1; j < MAXLOG; j++){

            dp[i][j] = dp[dp[i][j - 1]][j - 1];

        }

    }

    for(int i = 1; i <= querys; i++){

        int nod,plea_stramos;

        in>>nod>>plea_stramos;

        out<<query(nod,plea_stramos)<<"\n";

    }

    return 0;

}
