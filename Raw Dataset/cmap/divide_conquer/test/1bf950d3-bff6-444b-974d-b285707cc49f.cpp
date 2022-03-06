#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <vector>


using namespace std;
ifstream in("cmap.in");

ofstream out("cmap.out");



pair<long long, long long> v[100001];



long long dist_calc(long long x1, long long x2, long long y1, long long y2)

{

 return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);

}



long long dist_pair(unsigned int first, unsigned int second)

{

 return dist_calc(v[first].first, v[second].first, v[first].second, v[second].second);

}



long long div_et_imp(unsigned int st, unsigned int fin)

{

 if (fin - st <= 3)

 {

  long long d = dist_pair(0, 1);

  if (fin - st == 3)

  {

   d = min(d, dist_pair(1, 2));

   d = min(d, dist_pair(0, 2));

  }

  return d;

 }



 unsigned long long med = st + (fin - st) / 2;



 long long d = min(div_et_imp(st, med), div_et_imp(med, fin));



 vector <pair<long long, long long>> p;



 for (unsigned int i = st; i < fin; i++)

 {

  p.emplace_back(v[i].second, v[i].first);

 }

 sort(p.begin(), p.end());



 for (unsigned int i = 0; i < p.size(); i++)

 {

  for (unsigned int j = i + 1; j < i + 8 && j < p.size(); j++)

  {

   d = min(d, dist_calc(p[i].first, p[j].first, p[i].second, p[j].second));

  }

 }

 return d;

}



int main() {

 int n;

 in >> n;

 for (unsigned int i = 0; i < n; i++)

 {

  in >> v[i].first >> v[i].second;

 }

 sort(v, v + n);







 out << fixed << setprecision(6) << sqrt(div_et_imp(0, n));

 return 0;

}
