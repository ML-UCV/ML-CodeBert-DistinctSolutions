#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>






using namespace std;



ifstream f("cmap.in");

ofstream g("cmap.out");

const int MAXN = 100002;

const long long inf = 3e18;



pair <int, int> a[MAXN], b[MAXN], aux[MAXN];



long long getDistance( pair <int, int> A, pair <int, int> B ) {

 return 1LL * (A.first-B.first) * (A.first-B.first) + 1LL * (A.second-B.second) * (A.second-B.second);

}



long long get ( int begin, int end ) {

 if (begin == end)

  return inf;

 if (end - begin == 1) {

  if (b[end] < b[begin])

   swap(b[end], b[begin]);

  return getDistance(b[begin], b[end]);

 }



 int middle = (begin+end)>>1;

 long long minDistance = min(get(begin, middle), get(middle+1, end));



 merge(b + begin, b + middle + 1, b + middle + 1, b + end + 1, aux);

 copy(aux, aux + (end - begin + 1), b + begin);



 int k = 0;

 for(int i=begin; i<=end; ++i)

  if (abs(b[i].second - a[middle].first) <= minDistance)

   aux[k++] = b[i];



 for(int i=0; i<k; ++i)

  for(int j=i+1; j<k && j <= i + 8; ++j)

   minDistance = min(minDistance, getDistance(aux[i], aux[j]));





 return minDistance;

}



int main()

{

 int i, n;

 f>>n;

 for (i=1; i<=n; ++i)

  f >> a[i].first >> a[i].second;

 sort(a + 1, a + n + 1);

 for (i=1; i<=n; ++i)

  b[i] = make_pair(a[i].second, a[i].first);



    g.setf(ios::fixed, ios::floatfield);

 g.precision(6);

 g << sqrt( get(1, n) ) << "\n";

 return 0;

}
