#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>


using namespace std;

const long long NMAX = 100005;

const double INF = 4e18;



vector< pair<long long, long long> > Points;

vector< pair<long long, long long> > PointsOY;

vector< pair<long long, long long> > sol(NMAX);



long long returnDist(pair<long long, long long>& P1,pair<long long, long long>& P2)

{

    return (P2.first - P1.first) * (P2.first - P1.first) +

             (P2.second - P1.second) * (P2.second - P1.second);

}



long long d;



long long divideClosPoints(long long left, long long right)

{

    if( left >= right -1)

        return INF;

    else if(right - left == 2)

    {

        if(PointsOY[left].second == PointsOY[left + 1].second)

            if(PointsOY[left].first > PointsOY[left + 1].first)

                swap(PointsOY[left],PointsOY[left + 1]);

        else

            if(PointsOY[left].second > PointsOY[left + 1].second)

                swap(PointsOY[left],PointsOY[left + 1]);

        return returnDist(Points[left], Points[left + 1]);

    }



    long long middle = (left + right) / 2;

    d = min(divideClosPoints(left, middle),divideClosPoints(middle, right));

    int i, j;



    merge(PointsOY.begin() + left, PointsOY.begin() + middle, PointsOY.begin() + middle, PointsOY.begin() + right, sol.begin());

    copy(sol.begin(), sol.begin() + (right - left), PointsOY.begin() + left);





    int k = 0;

    for(i = left; i < right; ++i)

    {

        if(abs(PointsOY[i].second - Points[middle].first) <= d)

            sol[k++] = PointsOY[i];

    }

    for(i = 0; i < k - 1 ; ++i)

        for(j = i + 1; j - i < 8 && j < k ; ++j)

        {

            d = min(d, returnDist(sol[i],sol[j]));

        }

    return d;

}



long long x, y;



int main()

{

    ifstream fileRead("cmap.in");

    ofstream fileWrite("cmap.out");

    long long nrPoints, i;



    fileRead >> nrPoints;

    Points.resize(nrPoints);

    PointsOY.resize(nrPoints);



    for(i = 0 ; i < nrPoints; i++)

    {

        fileRead >> Points[i].first >> Points[i].second;

    }



     sort(Points.begin(),Points.end());



     for(i = 0 ; i < nrPoints; i++)

     {

        PointsOY[i] = make_pair(Points[i].first,Points[i].second);

     }



    fileWrite << fixed << setprecision(6) << sqrt(divideClosPoints(0,Points.size()));



    fileRead.close();

    fileWrite.close();

}
