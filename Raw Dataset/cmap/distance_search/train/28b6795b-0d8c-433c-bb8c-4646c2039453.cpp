#include <cmath>
#include <iomanip>
#include <fstream>
#include <algorithm>




using namespace std;



typedef pair<double, double> Point;



const int maxN = 100000;

Point v[maxN + 5];



ifstream in("cmap.in");

ofstream out("cmap.out");



inline double dist(int i, int j) {

  return sqrt(1.0 * (v[i].first - v[j].first) * (v[i].first - v[j].first) + 1.0 * (v[i].second - v[j].second) * (v[i].second - v[j].second));

}



int main() {

  int N;

  in >> N;



  for(int i = 1; i <= N; ++ i)

    in >> v[i].first >> v[i].second;



  sort(v + 1, v + N + 1);

  double d = dist(1, N);



  for(int i = 1; i <= N; ++ i)

    for(int j = i + 1; j <= N and v[j].first - v[i].first <= d; ++ j)

      d = min(d, dist(i, j));



  out << fixed << setprecision(6) << d << '\n';

  return 0;

}
