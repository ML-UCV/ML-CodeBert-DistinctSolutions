#include <stdio.h>
#include <float.h>
#include <stdlib.h>
#include <math.h>



struct Point
{
    long long x, y;
};





long double distanta(Point p1, Point p2)
{
 long long x = (p1.x - p2.x), y = (p1.y - p2.y);
 x = x *x; y = y*y;
    return sqrt( x + y);
}


long double bruteForce(Point P[], long long n)
{
    long double min = LDBL_MAX;
    for (long long i = 0; i < n; ++i)
        for (long long j = i+1; j < n; ++j)
            if (distanta(P[i], P[j]) < min)
                min = distanta(P[i], P[j]);
    return min;
}


long double min(long double x, long double y)
{
    return (x < y)? x : y;
}


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

long double rezolvaMediana(Point aux[], long long size, long double d)
{
    long double min = d;
    qsort(aux, size, sizeof(Point), compareY);


    for (long long i = 0; i < size; ++i)
        for (long long j = i+1; j < size && (aux[j].y - aux[i].y) < min; ++j)
            if (distanta(aux[i],aux[j]) < min)
                min = distanta(aux[i], aux[j]);

    return min;
}


long double partitionare(Point P[], long long n)
{

    if (n <= 3)
        return bruteForce(P, n);

    long long mid = n/2;
    Point midPoint = P[mid];

    long double solLeft = partitionare(P, mid), solRight = partitionare(P + mid, n-mid), sol;
    sol = min(solLeft, solRight);


    Point aux[n];
    long long j = 0;
    for (long long i = 0; i < n; i++)
        if (abs(P[i].x - midPoint.x) < sol)
            aux[j] = P[i], j++;


    return min(sol, rezolvaMediana(aux, j, sol) );
}


long double rezolva(Point P[], int n)
{
    qsort(P, n, sizeof(Point), compareX);


    return partitionare(P, n);
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
    double d=rezolva(P, n);
    fprintf(fout,"%lf\n", d);

    free(P);
    return 0;
}
