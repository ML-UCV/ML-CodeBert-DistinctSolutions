#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

ifstream in("cmap.in");

ofstream out("cmap.out");



struct Point

{

 int x, y;

};



bool compareX(Point p1, Point p2)

{

 return (p1.x < p2.x);

}





bool compareY(Point p1, Point p2)

{

 return (p1.y < p2.y);

}



double dist(Point p1, Point p2)

{



 double dist = sqrt(pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2));

 return dist;

}



double bruteForce(Point P[], int n)

{

 double mini = 9999999999.0;

 for (int i = 0; i < n; ++i)

  for (int j = i + 1; j < n; ++j)

   if (dist(P[i], P[j]) < mini)

    mini = dist(P[i], P[j]);

 return mini;

}





double ClosestMid(Point midarr[], int size, double d)

{

 double mini = d;



 sort(midarr, midarr + size, compareY);



 for (int i = 0; i < size; ++i)

  for (int j = i + 1; j < size && (midarr[j].y - midarr[i].y) < mini; ++j)

   if (dist(midarr[i], midarr[j]) < mini)

    mini = dist(midarr[i], midarr[j]);



 return mini;

}



double closestUtil(Point P[], int n)

{

 if (n <= 3)

  return bruteForce(P, n);



 int mid = n / 2;

 Point midPoint = P[mid];



 double dl = closestUtil(P, mid);

 double dr = closestUtil(P + mid, n - mid);



 double d = min(dl, dr);



 Point* midarr = new Point[n];

 int j = 0;

 for (int i = 0; i < n; i++)

  if (abs(P[i].x - midPoint.x) < d)

  {

   midarr[j] = P[i];

   j++;

  }





 return min(d, ClosestMid(midarr, j, d));

}



double closest(Point P[], int n)

{

 sort(P, P + n, compareX);

 return closestUtil(P, n);

}



int main()

{

 int n,i;



 in >> n;

 Point * P = new Point[n];

 for (i = 0;i < n;i++)

 {

  in >> P[i].x >> P[i].y;

 }

 double r = closest(P, n);

 out <<fixed<<setprecision(6)<<r;

 return 0;

}
