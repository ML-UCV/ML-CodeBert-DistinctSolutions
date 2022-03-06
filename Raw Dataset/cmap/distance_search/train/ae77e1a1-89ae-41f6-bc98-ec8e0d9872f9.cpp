#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;







struct punct{

 double x, y;

};



int N;

double distMin;



bool cmp(punct a, punct b){

 if (a.x!=b.x)

  return a.x<b.x;

 return a.y<b.y;

}



double distanta(punct a, punct b){

 return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));

}



int main(){

 fstream f;



 f.open("cmap.in", ios_base::in);

 f >> N;

 vector<punct> P(N);

 for (int i=0; i<N; i++)

  f >> P[i].x >> P[i].y;

 f.close();



 sort(P.begin(), P.end(), cmp);



 double dist;

 distMin=distanta(P[0], P[1]);

 for (int i=0; i<N-1; i++)

  for (int j=i+1; j<N && fabs(P[j].x-P[i].x)<=distMin; j++){

   dist=distanta(P[i], P[j]);

   distMin=min(distMin, dist);

  }



 f.open("cmap.out", ios_base::out);

 f << fixed << setprecision(6) << distMin << '\n';

 f.close();



 return 0;

}
