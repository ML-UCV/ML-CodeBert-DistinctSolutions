#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include<stdlib.h>
#include<climits>


using namespace std;



ifstream f("cmap.in");

ofstream g("cmap.out");



vector < pair <long long, long long> > banda(100001), X, Y;



long long distanta(pair <long long, long long> &a,pair <long long, long long> &b)

{

    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);

}
long long divide(int S, int D)

{

    if (S >= D-1)

    {

        if (S >= D - 1)return LLONG_MAX;

    }

    else

    {
        if (D - S == 2)

        {

            if (Y[S] > Y[S + 1])

                swap(Y[S], Y[S + 1]);

            return distanta(X[S], X[S + 1]);

        }

    }



    int mij = (S + D) / 2;

    long long dist = min(divide(S, mij), divide(mij, D));



    merge(Y.begin() + S, Y.begin() + mij, Y.begin() + mij, Y.begin() + D, banda.begin());

    copy(banda.begin(), banda.begin() + (D - S), Y.begin() + S);



    int k = 0;

    for (int i = S; i < D; i++ )

        if (abs(Y[i].second - X[mij].first) <= dist)

            banda[k ++] = Y[i];



    for (int i = 0; i < k - 1; i ++)

    {

        for (int j = i + 1; j < k && j - i < 8; j ++)

            dist = min(dist, distanta(banda[i], banda[j]));

    }

    return dist;

}



int main()

{

    int n;



    f>>n;

    X.resize(n),Y.resize(n);

    for (int i = 0; i <(int) X.size(); i++)

        f >> X[i].first >> X[i].second;



    sort(X.begin(), X.end());

    for (int i = 0; i <(int) X.size(); i++)

        Y[i] = make_pair(X[i].second, X[i].first);



    g << fixed << setprecision(6) << sqrt(divide(0,X.size())) << "\n";

    g.close();

    f.close();

    return 0;

}
