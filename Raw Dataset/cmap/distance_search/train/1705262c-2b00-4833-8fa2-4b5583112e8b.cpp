#include <cstdio>
#include <algorithm>
#include <cmath>
#include <utility>

using namespace std;

const int N = 100005;
const int inf = 0x3f3f3f3f;

int n;
pair<double, double> puncte[N];

double dist(pair<double, double> x1, pair<double, double> x2)
{
 return sqrt((x1.first - x2.first) * (x1.first - x2.first) + (x1.second - x2.second) * (x1.second - x2.second));
}

void citire()
{
 scanf("%d", &n);

 double tmp1, tmp2;

 for(int i = 0; i < n; i++)
 {
  scanf("%lf %lf", &tmp1, &tmp2);
  puncte[i] = make_pair(tmp1, tmp2);
 }

 sort(puncte, puncte + n);
}

void solve()
{
 double distanta = inf;

 for(int i = 1; i < n; i++)
 {
  for(int j = i - 1; j >= 0 && (puncte[i].first - puncte[j].first) < distanta; j--)
  {
   double distx = dist(puncte[i], puncte[j]);

   if(distx < distanta)
   {
    distanta = distx;
   }
  }
 }

 printf("%lf", distanta);
}

int main()
{
 freopen("cmap.in", "r", stdin);
 freopen("cmap.out", "w", stdout);

 citire();
 solve();

 return 0;
}
