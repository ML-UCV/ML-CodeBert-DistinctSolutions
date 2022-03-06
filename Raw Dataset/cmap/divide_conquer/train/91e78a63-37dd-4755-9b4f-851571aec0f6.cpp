#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cmath>
using namespace std;







struct Point {







 long long x, y;



 long long dist_sq(Point& b)



 {



  return (x - b.x) * (x - b.x) + (y - b.y) * (y - b.y);



 }



};







bool sort_x(Point& a, Point& b)



{



 if (a.x < b.x)



  return true;



 else



  return false;



}
bool sort_y(Point& a, Point& b)



{



 if (a.y < b.y)



  return true;



 else



  return false;



}







long long get_min_dist(long long d_min, vector<Point>& a)



{



 for (unsigned int i = 0; i < a.size() - 1; i++)



 {



  for (unsigned int j = i + 1; j < a.size() and j < i + 8; j++)



   if (a[i].dist_sq(a[j]) < d_min)



    d_min = a[i].dist_sq(a[j]);



 }



 return d_min;



}







long long find_closest_points(vector<Point>& a, vector<Point>& b, int st, int dr) {



 if (dr - st <= 3) {



  long long d_min = a[st].dist_sq(a[st + 1]);



  for (int i = st; i < dr; i++)



   for (int j = i + 1; j <= dr; j++)



    if (a[i].dist_sq(a[j]) < d_min)



     d_min = a[i].dist_sq(a[j]);



  return d_min;



 }



 else {



  int mijloc = (st + dr) / 2;



  vector<Point> ord_st, ord_dr;



  for (unsigned int i = 0; i < b.size(); i++)



   if (b[i].x <= a[mijloc].x)



    ord_st.push_back(b[i]);



   else



    ord_dr.push_back(b[i]);







  long long dist_st = find_closest_points(a, ord_st, st, mijloc);



  long long dist_dr = find_closest_points(a, ord_dr, mijloc + 1, dr);



  long long d_min;







  if (dist_st < dist_dr)



   d_min = dist_st;



  else



   d_min = dist_dr;







  vector<Point> fasie;



  for (unsigned int i = 0; i < b.size(); i++) {



   if (b[i].x > a[mijloc].x - sqrt(d_min) and b[i].x < a[mijloc].x + sqrt(d_min))



    fasie.push_back(b[i]);



  }



  return get_min_dist(d_min, fasie);



 }







}







int main()



{



 ifstream in("cmap.in");



 ofstream out("cmap.out");



 int n;



 in >> n;



 vector<Point> X(n), Y(n);



 for (int i = 0; i < n; i++)



 {



  in >> X[i].x >> X[i].y;



  Y[i].x = X[i].x;



  Y[i].y = X[i].y;



 }



 sort(X.begin(), X.end(), sort_x);



 sort(Y.begin(), Y.end(), sort_y);



 out << fixed << setprecision(6) << sqrt(find_closest_points(X, Y, 0, n - 1));



}
