#include <iostream>
#include <bits/stdc++.h>
#include <limits>
#include <vector>
#include <algorithm>
#include <fstream>
#include <climits>


using namespace std;



ifstream fin("cmap.in");

ofstream fout("cmap.out");



vector <pair<long long,long long> > v;



long long get_distance(pair <long long,long long> a,pair<long long,long long> b)

{

    return (a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second);

}





long long divide(long long st,long long dr)

{

    long long m, dist_min;



    if(dr-st<=3)

    {

        long long dist = LLONG_MAX ;

        for(int i=st; i<=dr; i++)

            for(int j=i+1; j<=dr; j++)

                dist = min(dist,get_distance(v[i],v[j]));



        return dist;

    }



    m = st + (dr - st) / 2;



    long long dist_s = divide(st,m);

    long long dist_d = divide(m+1,dr);



    dist_min = min(dist_s,dist_d);



    vector < pair<long long,long long> > band;

    for(int i=st; i<=dr; i++)

        if(abs(v[m].first-v[i].first)<dist_min)

            band.push_back({v[i].second,v[i].first});



    sort(band.begin(),band.end());



    for(int i=0; i<band.size(); i++)

    {

        for(int j=i+1; j<band.size() && j < i + 8; j++)

        {

            long long dist = get_distance(band[i],band[j]);

            if(dist < dist_min)

                dist_min = dist;

        }

    }



    return dist_min;

}

int main()

{

    int n;

    long long x,y,dist_min;



    fin>>n;

    for(int i = 1; i <= n; i++)

    {

        fin>>x>>y;

        v.push_back({x,y});

    }



    sort(v.begin(),v.end());



    dist_min = divide(0,n-1);



    fout<<fixed<<setprecision(6)<<sqrt((double)dist_min);



    fin.close();

    fout.close();



    return 0;

}
