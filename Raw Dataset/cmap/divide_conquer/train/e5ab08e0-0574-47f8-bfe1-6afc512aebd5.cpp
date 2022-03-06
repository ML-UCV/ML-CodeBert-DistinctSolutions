#include<fstream>
#include<vector>
#include<bitset>
#include<string.h>
#include<algorithm>
#include<map>
#include<cmath>
#include<queue>
#include<string>
#include<iomanip>
#include <iterator> 
using namespace std;



ifstream in("cmap.in");

ofstream out("cmap.out");



typedef pair<long long, long long> Point;



int N;



Point points[100010], points_copy[100010];



vector<Point> mrg;



double distance(const Point& p1, const Point& p2)

{

 return sqrt((p1.first - p2.first)*(p1.first - p2.first) + (p1.second - p2.second)*(p1.second - p2.second));

}



double closest_pair_of_points(int x,int y)

{



 if (y - x > 3)

 {

  int mid = (x + y) / 2;

  double d1 = closest_pair_of_points(x, mid);



  double d2 = closest_pair_of_points(mid + 1, y);



  merge(points_copy + x, points_copy + mid + 1, points_copy + mid + 1, points_copy + y + 1, back_inserter(mrg));



  double d = min(d1, d2);

  vector<Point> vec;



  for (int i=0;i<mrg.size();++i)

  {



   if (abs(points[mid].first - mrg[i].second) <= d)

     vec.push_back(make_pair(mrg[i].second, mrg[i].first));



  }





  double f_d = 1LL<<60;

  for(int i=0;i<vec.size();++i)

   for (int j = i + 1; j < min(i + 8, (int)vec.size()); ++j)

   {

    f_d = min(f_d, distance(vec[i], vec[j]));

   }

  for (int i = x; i <= y; ++i)

  {

   points_copy[i] = mrg[i - x];

  }

  mrg.clear();

  return min(d,f_d);

 }

 else

 {





  sort(points_copy + x, points_copy + y + 1);



  double dist =1ll<<60;

  for(int i=x;i<=y;i++)

   for (int j = i + 1; j <= y; ++j)

   {

    dist = min(dist, distance(points[i], points[j]));

   }

  return dist;

 }

}





int main()

{

 in.sync_with_stdio(false);

 in.tie(NULL);



 in >> N;



 for (int i = 1; i <= N; ++i)

 {

  int x, y;



  in >> x >> y;



  points[i] = { x,y };



 }



 mrg.reserve(100000);



 sort(points + 1, points + N + 1);



 for (int i = 1; i <= N; ++i)

  points_copy[i] = make_pair(points[i].second, points[i].first);



 out << fixed << setprecision(6) << closest_pair_of_points(1, N);



 return 0;

}
