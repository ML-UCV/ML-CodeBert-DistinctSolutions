#include <cstdio>


struct EuclidExtins {

  int x;

  int y;

};



EuclidExtins euclid_extins(int a, int b, int d) {

  if (b == 0)

    return {d / a, 0};

  else {

    EuclidExtins sol = euclid_extins(b, a % b, d);

    int c = a / b;

    return {sol.y, sol.x - c * sol.y};

  }

}



int main() {

  freopen("inversmodular.in", "r", stdin);

  freopen("inversmodular.out", "w", stdout);



  int a, n;

  scanf("%d%d", &a, &n);



  EuclidExtins sol = euclid_extins(a, n, 1);

  int x = sol.x;

  while (x <= 0)

    x += n;

  printf("%d\n", x);

  return 0;

}
