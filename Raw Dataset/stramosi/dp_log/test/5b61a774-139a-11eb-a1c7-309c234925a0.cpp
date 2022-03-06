#include <bits/stdc++.h>


FILE *in = fopen("stramosi.in", "r"), *out = fopen("stramosi.out", "w") ;



const int MV = 25e4 ;



int dp[19][MV + 5] ;



void pre(int n) {

        for (int i = 1 ; (1 << i) <= n ; ++ i) {

                for (int j = 1 ; j <= n ; ++ j) {

                        dp[i][j] = dp[i - 1][dp[i - 1][j]] ;

                }

        }

}



int eval(int val, int start) {

        int ret(start) ;

        int lg(0) ;

        for ( ; (1 << lg) <= val ; ++ lg) {

                if (((val >> lg) & 1) == 1) {

                        ret = dp[lg][ret] ;

                }

        }

        return ret ;

}



int main() {

        int n, m ;

        fscanf(in, "%d %d", &n, &m) ;

        for (int i = 1 ; i <= n ; ++ i) {

                fscanf(in, "%d", &dp[0][i]) ;

        }

        pre(n) ;

        int p, q ;

        for (int i = 1 ; i <= m ; ++ i) {

                fscanf(in, "%d %d", &q, &p) ;

                int ans = eval(p, q) ;

                fprintf(out, "%d\n", ans) ;

        }

}
