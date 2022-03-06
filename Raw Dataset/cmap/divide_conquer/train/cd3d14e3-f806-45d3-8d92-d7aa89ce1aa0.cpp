#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <math.h>


using namespace std;







struct point

{

 double x, y;

};



point puncte[99999], aux[99999], inter[99999], a, b;



double distance(point a, point b)

{

 return sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));

}



bool cmpX(point a, point b)

{

 return a.x < b.x;

}



bool cmpY(point a, point b)

{

 return a.y < b.y;

}



double dist_min(int left, int right)

{

 if (right - left + 1 == 3)

 {

  sort(puncte + left, puncte + right, cmpY);

  double d1 = distance(puncte[left], puncte[left + 1]);

  double d2 = distance(puncte[left + 1], puncte[left + 2]);

  double d3 = distance(puncte[left], puncte[left + 2]);

  double minim = d1;

  a = puncte[left];

  b = puncte[left + 1];

  if (d2 < minim)

  {

   minim = d2;

   a = puncte[left + 1];

   b = puncte[left + 2];

  }

  if (d3 < minim)

  {

   a = puncte[left];

   b = puncte[left + 2];

   minim = d3;

  }

  return minim;

 }

 if (right - left + 1 == 2)

 {

  if (puncte[left].y > puncte[left + 1].y)

   swap(puncte[left], puncte[left + 1]);

  a = puncte[left];

  b = puncte[left + 1];

  return distance(puncte[left], puncte[left + 1]);

 }

 else

 {

  int mijloc = (left + right) / 2;

  double mediana = puncte[mijloc].x;

  double delta = min(dist_min(left, mijloc), dist_min(mijloc + 1, right));

  int nr = 0, i, j, k;





  i = left;

  k = left;

  j = mijloc + 1;

  while (i <= mijloc && j <= right)

   if (puncte[i].y < puncte[j].y)

    aux[k++] = puncte[i++];

   else aux[k++] = puncte[j++];

  while (i <= mijloc)

   aux[k++] = puncte[i++];

  while (j <= right)

   aux[k++] = puncte[j++];



  for (i = left; i <= right; i++)

  {

   puncte[i] = aux[i];

   if (puncte[i].x - mediana <= delta && puncte[i].x - mediana >= -delta)

    inter[++nr] = puncte[i];

  }



  for (i = 1; i <= nr; i++)

  {

   int nr_vecini = min(nr, i + 7);

   for (j = i + 1; j <= nr_vecini; j++)

    if (distance(inter[i], inter[j]) < delta)

    {

     delta = distance(inter[i], inter[j]);

     a = inter[i];

     b = inter[j];

    }

  }

  return delta;

 }

}



int main()

{

 ifstream fin("cmap.in");

 ofstream fout("cmap.out");

 int n, index;

 fin >> n;

 for (index = 1; index <= n; index++)

  fin >> puncte[index].x >> puncte[index].y;

 sort(puncte + 1, puncte + n + 1, cmpX);





 fout << setprecision(6) << fixed << dist_min(1, n);

 return 0;

}
