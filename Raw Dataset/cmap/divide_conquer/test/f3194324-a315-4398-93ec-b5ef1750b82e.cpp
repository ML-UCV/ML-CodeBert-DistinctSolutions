#include <stdio.h>
#include <float.h>
#include <stdlib.h>
#include <math.h>





struct Point
{
    long long x, y;
};





int compareX(const void* a, const void* b)
{
    Point *p1 = (Point *)a, *p2 = (Point *)b;
    return (p1->x - p2->x);
}

int compareY(const void* a, const void* b)
{
    Point *p1 = (Point *)a, *p2 = (Point *)b;
    return (p1->y - p2->y);
}


long double dist(Point p1, Point p2)
{
    return sqrt( (p1.x - p2.x)*(p1.x - p2.x) +
                 (p1.y - p2.y)*(p1.y - p2.y)
               );
}



long double bruteForce(Point P[], long long n)
{
    long double min = LDBL_MAX;
    for (long long i = 0; i < n; ++i)
        for (long long j = i+1; j < n; ++j)
            if (dist(P[i], P[j]) < min)
                min = dist(P[i], P[j]);
    return min;
}


long double min(long double x, long double y)
{
    return (x < y)? x : y;
}







long double stripClosest(Point strip[], long long size, long double d)
{
    long double min = d;

    qsort(strip, size, sizeof(Point), compareY);




    for (long long i = 0; i < size; ++i)
        for (long long j = i+1; j < size && (strip[j].y - strip[i].y) < min; ++j)
            if (dist(strip[i],strip[j]) < min)
                min = dist(strip[i], strip[j]);

    return min;
}



long double closestUtil(Point P[], long long n)
{

    if (n <= 3)
        return bruteForce(P, n);


    long long mid = n/2;
    Point midPoint = P[mid];




    long double dl = closestUtil(P, mid);
    long double dr = closestUtil(P + mid, n-mid);


    long double d = min(dl, dr);



    Point strip[n];
    long long j = 0;
    for (long long i = 0; i < n; i++)
        if (abs(P[i].x - midPoint.x) < d)
            strip[j] = P[i], j++;



    return min(d, stripClosest(strip, j, d) );
}



long double closest(Point P[], int n)
{
    qsort(P, n, sizeof(Point), compareX);


    return closestUtil(P, n);
}


int main()
{
    Point *P;
    int n ;
 FILE *fin=fopen("cmap.in","r");
 FILE *fout=fopen("cmap.out","w");
    fscanf(fin , "%d",&n);
 P = (Point*) calloc(n, sizeof(Point));
 long long i;
 for(i=0;i<n;++i){
  long long x,y;
  fscanf(fin,"%lld %lld",&x,&y);
  P[i].x = x;
  P[i].y = y;
 }
 double d= closest(P, n);
    fprintf(fout,"%lf", d);
 free(P);
    return 0;
}
