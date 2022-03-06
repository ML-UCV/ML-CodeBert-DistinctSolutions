#include <fstream>
#include <algorithm>
#include <vector>
#include <float.h>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <limits.h>


using namespace std;



ifstream in("cmap.in");

ofstream out("cmap.out");



struct punct

{

 int x;

 int y;

};



int comparare_x(punct a, punct b)

{

 return a.x < b.x;

}



int comparare_y(punct a, punct b)

{

 return a.y < b.y;

}



double distanta_euclidiana(punct a, punct b)

{

 double x = a.x - b.x;

 double y = a.y - b.y;

 double distanta;

 distanta = pow(x, 2) + pow(y, 2);

 distanta = sqrt(distanta);

 return distanta;

}



int citire(vector <punct> &vx, vector <punct> &vy)

{

 int n;

 in >> n;

 for (int i = 0; i < n; i++)

 {

  punct aux;

  in >> aux.x;

  in >> aux.y;

  vx.push_back(aux);

 }

 sort(vx.begin(), vx.end(), comparare_x);

 vy = vx;

 return 1;

}



int afisare(vector <punct> vx)

{

 for (auto it : vx)

 {

  out << it.x << " " << it.y << endl;

 }

 return 1;

}



double calculare_distanta_minima(vector <punct> &vx, int left, int right, vector <punct> &vy)

{

 if (right - left == 1)

 {

  return INT_MAX;

 }

 if (right - left == 2)

 {

  if (vy.at(left).y > vy.at(left + 1).y)

  {

   swap(vy.at(left), vy.at(left + 1));

  }

  return distanta_euclidiana(vx.at(0), vx.at(1));

 }



 int mij = (left + right) / 2;



 double distanta_minima_stanga = calculare_distanta_minima(vx, left, mij, vy);

 double distanta_minima_dreapta = calculare_distanta_minima(vx, mij, right, vy);

 double distanta_minima_temporara = min(distanta_minima_stanga, distanta_minima_dreapta);



 vector<punct> puncte_auxiliare(right - left);



 merge(vy.begin() + left, vy.begin() + mij, vy.begin() + mij, vy.begin() + right, puncte_auxiliare.begin(), comparare_y);

 copy(puncte_auxiliare.begin(), puncte_auxiliare.begin() + (right - left), vy.begin() + left);





 vector <punct> aux;



 for (int i = left; i < right; i++)

 {

  if (abs(vy.at(i).x - vx.at(mij).x) <= distanta_minima_temporara)

  {

   aux.push_back(vy.at(i));

  }

 }



 double distanta_minima_finala = distanta_minima_temporara;



 for (int i = 0; i < aux.size(); i++)

 {

  for (int j = i + 1; j < aux.size() && aux.at(j).y - aux.at(i).y <= distanta_minima_temporara; j++)

  {

   double distanta_auxiliara = distanta_euclidiana(aux.at(i), aux.at(j));

   if (distanta_auxiliara < distanta_minima_finala)

   {

    distanta_minima_finala = distanta_auxiliara;

   }

  }

 }

 return distanta_minima_finala;

}







int main()

{

 vector <punct> vx;

 vector <punct> vy;

 citire(vx, vy);



 out << fixed;

 out << setprecision(6) << calculare_distanta_minima(vx, 0, vx.size(), vy);

 return 0;

}
