#include<cstdio>
int const NMAX = 250000;

int const MAXLOG = 17;

int log[5 + NMAX];

int dp[5 + MAXLOG][5 + NMAX];

int n;

int afis(int &node ,int &p){

  while(0 < p && 0 < node){

    node = dp[log[p]][node];

    p -= (1 << log[p]);

  }

  return node;

}



int main()

{

  freopen("stramosi.in" , "r" , stdin);

  freopen("stramosi.out" , "w" , stdout);

  int k;

  scanf("%d%d" , &n , &k);

  for(int i = 1 ; i <= n ;i++){

    scanf("%d" , &dp[0][i]);

  }

  log[1] = 0;

  for(int i = 2 ; i <= n ;i++){

    log[i] = log[(i >> 1)] + 1;

  }

  for(int h = 1 ; h <= MAXLOG ;h++){

    for(int i = 1 ; i <= n ;i++){

      dp[h][i] = dp[h - 1] [dp[h - 1][i]];

    }

  }

  int a , b;

  for(int i = 1 ; i <= k ;i++){

    scanf("%d%d" , &a , &b);

    printf("%d\n" , afis(a , b));

  }

  return 0;

}
