#include <iostream>
#include <algorithm>
#include <fstream>
#include <math.h>
#include <iomanip>
using namespace std;



typedef long long llong;



struct Point

{

 int x, y;

};



Point X[100005], candidates[100005];



void interclas(size_t st, size_t mij, size_t dr)

{

 Point* aux = new Point[dr - st + 1];

 size_t i = st, j = mij + 1, k = 0;

 while (i <= mij && j <= dr)

 {

  if (X[i].y < X[j].y)

   aux[k++] = X[i++];

  else

   aux[k++] = X[j++];

 }



 if (i>mij)

  while (j <= dr)

   aux[k++] = X[j++];

 else

  while (i <= mij)

   aux[k++] = X[i++];



 for (size_t i = 0; i < k; i++)

 {

  X[st + i] = aux[i];

 }

 delete[] aux;

}



bool increasingX(const Point a, const Point b)

{

 return a.x < b.x;

}



bool increasingY(const Point a, const Point b)

{

 return a.y < b.y;

}



llong min(const llong &a, const llong &b)

{

 return (a < b) ? a : b;

}



llong distance2(const Point a, const Point b)

{

 llong dx = (b.x - a.x);

 llong dy = (b.y - a.y);

 return dx*dx + dy*dy;

}



llong solveFast(size_t st, size_t dr, Point &first, Point &second)

{

 sort(X + st,X + dr,increasingY);

 llong mind = 0x7fffffffffffffffLL;



 int pos1 = -1, pos2 = -1;

 for (size_t i = st; i < dr; i++)

 {

  for (size_t j = i + 1; j <= dr; j++)

  {

   llong distaux = distance2(X[i], X[j]);

   if (distaux < mind)

   {

    mind = distaux;

    pos1 = i;

    pos2 = j;

   }



  }

 }



 first = X[pos1];

 second = X[pos2];

 return mind;

}



llong closestDistance(size_t st, size_t dr, Point &first, Point &second)

{

 if (dr - st < 3)

 {

  return solveFast(st, dr, first, second);

 }

 else

 {



  llong mij = (st + dr) / 2;



  int elemMij = X[mij].x;



  Point f1, f2, fmin, s1, s2, smin;



  llong d1 = closestDistance(st, mij, f1, s1);

  llong d2 = closestDistance(mij + 1, dr, f2, s2);



  llong delta = min(d1, d2);

  if (d1 == delta)

  {

   fmin = f1;

   smin = s1;

  }

  else

  {

   fmin = f2;

   smin = s2;

  }





  interclas(st, mij, dr);





  size_t nrOfCandidates = 0;

  for (size_t i = st; i <= dr; i++)

   if (pow(X[i].x - elemMij, 2) < delta)

    candidates[nrOfCandidates++] = X[i];





  for (size_t i = 0; i < nrOfCandidates - 1; i++)

  {

   int l = 0;



   for (size_t j = i + 1; l <= 7 && j < nrOfCandidates; j++, l++)

   {

    llong d3 = distance2(candidates[i], candidates[j]);

    if (d3 < delta)

    {

     fmin = candidates[i];

     smin = candidates[j];

     delta = d3;

    }

   }

  }



  first = fmin;

  second = smin;

  return delta;

 }

}



int main()

{

 int n;

 ifstream fin("cmap.in");

 ofstream fout("cmap.out");

 fin >> n;



 int xx, yy;



 for (int i = 0; i < n; i++)

 {

  fin >> xx >> yy;

  X[i].x = xx;

  X[i].y = yy;

 }



 fin.close();



 sort(X, X + n, increasingX);



 Point p1, p2;



 long double result = sqrt(closestDistance(0, n - 1, p1, p2));



 fout << fixed << setprecision(6) << result << endl;





 fout << "(" << p1.x << "," << p1.y << ") , " << "(" << p2.x << "," << p2.y << ")\n";



 return 0;

}
