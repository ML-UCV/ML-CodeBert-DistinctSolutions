#include <cstdio>


using namespace std;



struct EuclidExtins {

  int x;

  int y;

};



EuclidExtins euclid_extins(int a, int b) {

  if (b == 0)

    return {1, 0};



  EuclidExtins lst;

  lst = euclid_extins(b, a % b);



  return {lst.y, lst.x - (a / b) * lst.y};

}



int main() {

  freopen("inversmodular.in", "r", stdin);

  freopen("inversmodular.out", "w", stdout);



  int a, n;

  scanf("%d%d", &a, &n);





  EuclidExtins e;

  e = euclid_extins(a, n);



  int ans;

  ans = e.x;

  while (ans < 0)

    ans += n;

  printf("%d\n", ans);



  return 0;

}
