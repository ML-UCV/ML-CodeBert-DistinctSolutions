#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>


using namespace std;



const int MAX_N = 100005;

const long long INFINIT = 4e18;



vector < pair <long long, long long> > verticalSection(MAX_N), PointsOX, PointsOY;



long long distEuclid(const pair <long long, long long>& a, const pair <long long, long long>& b)

{

    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);

}



long long retClosPoint(int left, int right)

{

    if (left >= right - 1)

        return INFINIT;

    else

    if (right - left == 2)

    {

        if (PointsOY[left] > PointsOY[left + 1])

            swap(PointsOY[left], PointsOY[left + 1]);

        return distEuclid(PointsOX[left], PointsOX[left + 1]);

    }



    int mid = (left + right) / 2;

    long long dist = min(retClosPoint(left, mid), retClosPoint(mid, right));



    merge(PointsOY.begin() + left, PointsOY.begin() + mid, PointsOY.begin() + mid, PointsOY.begin() + right, verticalSection.begin());

    copy(verticalSection.begin(), verticalSection.begin() + (right - left), PointsOY.begin() + left);



    int vSize = 0;

    for (int i = left; i < right; i++ )

        if (abs(PointsOY[i].second - PointsOX[mid].first) <= dist)

            verticalSection[vSize ++] = PointsOY[i];



    for (int i = 0; i < vSize - 1; i ++)

    {

        for (int j = i + 1; j < vSize && j - i < 8; j ++)

            dist = min(dist, distEuclid(verticalSection[i], verticalSection[j]));

    }

    return dist;

}



int main()

{

    int nrPoints;

    ifstream fileRead("cmap.in");

    ofstream fileWrite("cmap.out");

    fileRead >> nrPoints;



    PointsOX.resize(nrPoints), PointsOY.resize(nrPoints);

    for (int i = 0; i < PointsOX.size(); ++ i)

        fileRead >> PointsOX[i].first >> PointsOX[i].second;

    fileRead.close();



    sort(PointsOX.begin(), PointsOX.end());

    for (int i = 0; i < PointsOX.size(); ++ i)

        PointsOY[i] = make_pair(PointsOX[i].second, PointsOX[i].first);





    fileWrite << fixed << setprecision(6) << sqrt(retClosPoint(0,PointsOX.size())) << "\n";

    fileWrite.close();

    return 0;

}
