#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>


using namespace std;



long long returnDist(const pair<int ,int> &P1,const pair<int, int> &P2)

{

    return (long long) (P2.first - P1.first) * (long long) (P2.first - P1.first) +

            (long long) (P2.second - P1.second) * (long long) (P2.second - P1.second);

}



bool compByX(const pair<int,int> &P1,const pair<int,int> &P2)

{

    return P1.first < P2.first;

}



bool compByY(const pair<int,int> &P1,const pair<int,int> &P2)

{

    return P1.second < P2.second;

}



vector< pair<int, int> > Points;



long long divideClosPoints(long left,long right)

{

    if(right - left == 1)

        return returnDist(Points[left], Points[right]);



    if(right - left == 2)

        return min(returnDist(Points[left], Points[left+1]),

            min(returnDist(Points[left+1], Points[right]),

                returnDist(Points[left], Points[right])));



    long middle = (left + right) / 2;

    long long dLeft = divideClosPoints(left, middle);

    long long dRight = divideClosPoints(middle + 1, right);



    long long d = min(dLeft, dRight);



    long i, j;



    vector< pair<int, int> > verticalSec;



    auto delta = ceil( sqrt(d) );



    for(i = left ; i <= right; i++)

    {

        if( abs(Points[i].first - Points[middle].first) <= delta)

           verticalSec.push_back(Points[i]);

    }

    sort(verticalSec.begin(),verticalSec.end(),compByY);



    long long sizeV = verticalSec.size();



    for(i = 0; i < sizeV ; i++)

        for(j = i + 1; j <= i + 7 && j < sizeV ; j++)

        {

            d = min(d, returnDist(verticalSec[i],verticalSec[j]) );

        }

    return d;

}



int main()

{

    ifstream fileRead("cmap.in");

    ofstream fileWrite("cmap.out");

    long long nrPoints, i;



    pair<int, int> P;

    fileRead >> nrPoints;



    for(i = 0 ; i < nrPoints; i++)

    {

        fileRead >> P.first >> P.second;

        Points.push_back(P);

    }

    sort(Points.begin(),Points.end(),compByX);

    fileWrite << fixed << setprecision(6) << sqrt(divideClosPoints(0,Points.size() - 1));



    fileRead.close();

    fileWrite.close();

}
