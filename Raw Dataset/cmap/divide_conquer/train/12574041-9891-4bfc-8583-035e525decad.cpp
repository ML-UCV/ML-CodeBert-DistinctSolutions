#include <stdio.h>
#include <algorithm>
#include <math.h>


const int dmax = 100000;

unsigned const long long INF = (1ULL << 64) - 1;



struct point

{

    long long x,y;

};



int n;

point pointsY[dmax];

point pointsL[dmax];



bool cmpX(point a, point b)

{

    if (a.x == b.x)

        return a.y < b.y;

    return a.x < b.x;

}



bool cmpY(point a, point b)

{

    if (a.y == b.y)

        return a.x < b.x;

    return a.y < b.y;

}



double distance(point a, point b)

{

    return (b.x - a.x)*(b.x - a.x) + (b.y - a.y)*(b.y - a.y);

}



double min_dist(int first, int last)

{

    double best_distance = INF;

    double dist;

    int point_nr, mid, i, j;





    point_nr = last - first + 1;

    if (point_nr == 2)

        return distance(pointsY[first],pointsY[last]);





    mid = first + (last - first)/2;

    best_distance = std::min(min_dist(first,mid), min_dist(mid,last));







    int u_bound = pointsY[mid].y + (int)sqrt(best_distance);

    int l_bound = pointsY[mid].y - (int)sqrt(best_distance);



    int Lsize = 0;

    for (i = first; i<=last; i++)

    {

        if (pointsY[i].y <= u_bound && pointsY[i].y >= l_bound)

            pointsL[Lsize++] = pointsY[i];

    }

    std::sort(pointsL,pointsL+Lsize,cmpX);

    for (i = 0; i < Lsize - 1; i++)

    {

        j = i + 1;

        int count = 1;

        while (j < Lsize && count < 8)

        {

            dist = distance(pointsL[i],pointsL[j]);

            if (dist < best_distance)

                best_distance = dist;

            count++;

            j++;

        }

    }



    return best_distance;

}



int main()

{

    FILE *f;

    int i;



    f=fopen("cmap.in","r");

    fscanf(f,"%d",&n);

    for (i=0; i<n; i++)

        fscanf(f,"%lld%lld",&pointsY[i].x,&pointsY[i].y);

    fclose(f);



    std::sort(pointsY,pointsY+n,cmpY);



    double ans = min_dist(0,n - 1);

    ans = sqrt(ans);

    f=fopen("cmap.out","w");

    fprintf(f,"%f",ans);

    fclose(f);



    return 0;

}
