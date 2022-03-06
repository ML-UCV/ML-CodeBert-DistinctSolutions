#include <cstdio>
#include <cstdlib>
#include <cmath>
struct Point {

 int x;

 int y;

};



int n;

Point pct[100000];

double max;



double calcDist(Point* A, Point* B) {

 double dx = A->x - B->x;

 double dy = A->y - B->y;

 return sqrt(dx*dx + dy*dy);

}



int comparePointsX(const void * a, const void * b) {

 Point * A = ((Point*)a);

 Point * B = ((Point*)b);

 if (A->x > B->x) return 1;

 if (A->x < B->x) return -1;

 return 0;

}



int comparePointsY(const void * a, const void * b) {

 Point * A = *((Point**)a);

 Point * B = *((Point**)b);

 if (A->y > B->y) return 1;

 if (A->y < B->y) return -1;

 return 0;

}



double minDistBrute(int left, int right) {

 double min = max;

 double dist;

 for (int i = left; i < right; i++) {

  for (int j = i + 1; j < right; j++) {

   dist = calcDist(pct + i, pct + j);

   if (dist < min) min = dist;

  }

 }

 return min;

}



double minDist(int left, int right) {

 int nr = right - left;

 if (nr <= 3) {

  return minDistBrute(left, right);

 }

 int mid = left + (nr/2);

 double min = minDist(left, mid);

 double min2 = minDist(mid, right);

 if (min2 < min) {

  min = min2;

 }



 int X = pct[mid].x;

 int j = 0;

 double dist;

 Point** sortY = (Point**)malloc(nr * sizeof(Point*));

 for (int i = left; i < right; i++)

 {

  if (X - pct[i].x < min && X - pct[i].x > -min) {

   sortY[j++] = pct + i;

  }

 }

 qsort(sortY, j, sizeof(Point*), comparePointsY);



 for (int i = 0; i < j; i++)

 {

  for (int k = 1; k < 7 && k+i < j; k++)

  {

   dist = calcDist(sortY[i], sortY[k + i]);

   if (dist < min) min = dist;

  }

 }

 return min;

}



int main() {

 FILE * fin;

 FILE * fout;



 fin = fopen("cmap.in", "r");

 fout = fopen("cmap.out", "w");



 fscanf(fin, "%d", &n);

 for (int i = 0; i < n; ++i) {

  fscanf(fin, "%d%d", &pct[i].x, &pct[i].y);

 }



 qsort(pct, n, sizeof(Point), comparePointsX);

 max = calcDist(pct, pct + n - 1);



 fprintf(fout, "%f", minDist(0, n));



 fclose(fin);

 fclose(fout);

    return 0;

}
