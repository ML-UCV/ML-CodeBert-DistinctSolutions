#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <cmath>
using namespace std;



const int N = 25e4;

const int LOG = 17;



int dp[5 + LOG][5 + N];



int main()

{

    freopen("stramosi.in", "r", stdin);

    freopen("stramosi.out", "w", stdout);

    int n, m;

    scanf("%d%d", &n, &m);

    for(int i = 1; i <= n; i++) scanf("%d", &dp[0][i]);



    for(int i = 1; i <= LOG; i++)

        for(int j = 1; j <= n; j++)

            dp[i][j] = dp[i - 1][dp[i - 1][j]];



    while(m--){

        int x, y;

        scanf("%d%d", &x, &y);

        for(int i = 0; (1 << i) <= y; i++)

            if(y & (1 << i))

                x = dp[i][x];

        printf("%d\n", x);

    }

    return 0;

}
