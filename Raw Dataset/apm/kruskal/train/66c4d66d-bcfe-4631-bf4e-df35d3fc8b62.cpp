#include <cstdio>
#include <algorithm>




using namespace std;



struct MUCHIE{

  int x, y, ct, sol;

}v[400005];



int t[200005], h[200005];



bool cmp(MUCHIE a, MUCHIE b){

  return a.ct < b.ct;

}



int FindSet(int x){

    while(x != t[x]){

      x = t[x];

    }

    return x;

}



void UnionSet(int x, int y){

  if(h[x] <= h[y]){

    if(h[x] == h[y])

      h[y]++;

    t[x] = y;

  }

  else

    t[y] = x;

}



int main()

{

    freopen("apm.in", "r", stdin);

    freopen("apm.out", "w", stdout);

    int n, m, x, y, ct, s, ma, tx, ty, i;

    scanf("%d%d", &n, &m);

    for(i = 1;i <= m;i++){

      scanf("%d%d%d", &x, &y, &ct);

      v[i].x = x;

      v[i].y = y;

      v[i].ct = ct;

    }

    sort(v + 1, v + m + 1, cmp);

    for(i = 1;i < n;i++){

      h[i] = 1;

      t[i] = i;

    }

    s = ma = 0;

    i = 1;

    while(i <= m && ma < n - 1){

      tx = FindSet(v[i].x);

      ty = FindSet(v[i].y);

      if(tx != ty){

        ma++;

        s += v[i].ct;

        UnionSet(tx, ty);

        v[i].sol = 1;

      }

      i++;

    }

    printf("%d\n", s);

    printf("%d\n", ma);

    for(i = 1;i <= m;i++){

      if(v[i].sol == 1)

        printf("%d %d\n", v[i].x, v[i].y);

    }

    return 0;

}
