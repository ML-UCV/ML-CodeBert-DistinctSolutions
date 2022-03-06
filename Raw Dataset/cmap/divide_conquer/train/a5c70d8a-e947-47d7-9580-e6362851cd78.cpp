#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <limits.h>


using namespace std;
ifstream f("cmap.in");

ofstream g("cmap.out");



int n;

struct point{

    int x,y;

    point(const int a,const int b){ x=a; y=b; }

    point(){x=0;y=0;}



    bool operator<(const point ref)const {

        if( x < ref.x )

            return true;

        if( x > ref.x )

            return false;

        if( y < ref.y )

            return true;

        return false;

    }



};

point points[100000], pointsY[100000], aux[100000];



long long d(const point a,const point b){

    return 1LL * (a.x - b.x) * (a.x - b.x) + 1LL * (a.y - b.y) * (a.y - b.y);

}



long long minDist(int left, int right){



    if(right == left )

        return 1e18;

    else if(right - left == 1){

        if( pointsY[right] < pointsY[left] )

            swap(pointsY[left], pointsY[right]);

        return d(pointsY[left], pointsY[right]);

    }





    int mid = (left + right) >> 1;

    long long minD = min( minDist(left, mid), minDist(mid + 1, right));





    merge(pointsY + left, pointsY + mid + 1, pointsY + mid + 1, pointsY + right + 1, aux);

    copy(aux, aux + (right - left + 1), pointsY + left);





    int k = 0;

    for(int i = left; i <= right; i++)

        if(abs(points[mid].x - pointsY[i].y) <= minD && i != mid)

            aux[k++] = pointsY[i];





    for(int i = 0; i < k; i++)

        for(int j = i + 1; j < k && j <= i + 8; j++)

            minD = min(minD, d(aux[i], aux[j]));





    return minD;

}



int main()

{

    f >> n;

    for(int i = 0; i < n; i++)

        f >> points[i].x >> points[i].y;





    sort(points, points + n);





    for(int i = 0; i < n; i++)

        pointsY[i] = point(points[i].y, points[i].x);



    g << fixed << setprecision(6) << sqrt(minDist(0, n - 1));

    return 0;

}
