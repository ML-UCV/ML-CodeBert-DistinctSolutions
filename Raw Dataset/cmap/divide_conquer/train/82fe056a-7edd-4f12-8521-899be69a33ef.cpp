#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <bits/stdc++.h>
#include <math.h>
#include<climits>
using namespace std;

vector<pair<long long, long long>> x;

long long get_dist(pair<long long, long long> a, pair<long long, long long> b)
{
    return (a.first - b.first)*(a.first - b.first) + (a.second - b.second)*(a.second - b.second);
}

long long distanta(int st, int dr)
{
    int i,j;

    if(dr - st<=3)
    {
        long long dist = LLONG_MAX;

        for(i=st; i<=dr-1; i++)
            for(j=i+1; j<=dr; j++)
            {
                long long d_puncte = get_dist(x[i], x[j]);
                dist = min(dist, d_puncte);
            }

        return dist;
    }
    else
    {
        int middle = st + (dr - st)/2;
        vector<pair<long long, long long>> band;

        long long ds, dd, d;

        ds = distanta(st, middle);
        dd = distanta(middle, dr);

        d = min(dd, ds);

        for(i = st; i <= dr; i++)
            if(x[i].first>=(x[middle].first-d) && x[i].first<=(x[middle].first + d))
                band.push_back(make_pair(x[i].second, x[i].first));

        sort(band.begin(), band.end());

        for(i=0; i<(int)band.size()-7; i++)
            for( j=i+1; j<=i+7; j++)
            {
                long long dist = get_dist(band[i], band[j]);
                d = min(d, dist);
            }

        return d;
    }
}

int main()
{
    int n, i;
    long long a, b, dmin;

    ifstream inFile;
    inFile.open("cmap.in");
    if (!inFile)
    {
        cout << "Unable to open file";
        exit(1);
    }

    inFile >> n;

    for (i = 0; i < n; i++)
    {
        inFile >> a >> b;
        x.push_back(make_pair(a, b));
    }
    inFile.close();

    sort(x.begin(), x.end());

    dmin = distanta(0, n-1);

    ofstream outFile;

    outFile.open("cmap.out");
    if (!outFile)
    {
        cout << "Unable to open file";
        exit(1);
    }

    outFile<<fixed<<setprecision(6)<<sqrt((double)dmin);

    outFile.close();

    return 0;
}
