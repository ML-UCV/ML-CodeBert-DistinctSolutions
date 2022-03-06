#include <bits/stdc++.h>




using namespace std;



ifstream in("cmap.in");

ofstream out("cmap.out");



struct lol {

 long long x, y;

};



int n, vf;

lol a[100100], wek[100100];



long long dist(lol a, lol b) {

 return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);

}



bool cmp(lol a, lol b) {

 return a.x < b.x;

}



bool cmp2(lol a, lol b) {

 return a.y < b.y;

}



long long get(int st, int dr) {

 if (dr - st < 3) {

  long long ans = 1e18;

  for (int i = st; i < dr; i++)

   for (int j = i + 1; j <= dr; j++)

    ans = min(ans, dist(a[i], a[j]));

  return ans;

 }

 int mid = st + dr >> 1;

 long long bst = min(get(st, mid), get(mid, dr));

 vf = 0;

 for (int i = st; i <= dr; i++)

  if ((a[i].x - a[mid].x) * (a[i].x - a[mid].x) <= bst)

   wek[++vf] = a[i];

 sort(wek + 1, wek + vf + 1, cmp2);

 for (int i = 1; i <= vf; i++)

  for (int j = i + 1; j <= vf && j - i < 8; j++)

   bst = min(bst, dist(wek[i], wek[j]));

 return bst;

}



int main() {

 in >> n;

 for (int i = 1; i <= n; i++)

  in >> a[i].x >> a[i].y;

 sort(a + 1, a + n + 1, cmp);

 out << fixed << setprecision(6) << sqrt((double) get(1, n));

 return 0;

}
