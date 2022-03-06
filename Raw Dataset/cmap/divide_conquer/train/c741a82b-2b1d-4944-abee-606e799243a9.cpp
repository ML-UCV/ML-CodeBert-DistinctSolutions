#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <fstream>
using namespace std;



ifstream fin("cmap.in");

ofstream fout("cmap.out");



pair < int, int > temp[100003];



int partition_x(pair < int, int > P[100003], int lo, int hi){

    int pivot = lo + (rand() % (hi - lo + 1));

    (P[0] = (P[pivot]), (P[pivot]) = (P[hi]), (P[hi]) = P[0]);

    pivot = hi;

    while(lo < pivot){

        if(P[lo].first >= P[pivot].first){

            (P[0] = (P[lo]), (P[lo]) = (P[pivot - 1]), (P[pivot - 1]) = P[0]);

            (P[0] = (P[pivot - 1]), (P[pivot - 1]) = (P[pivot]), (P[pivot]) = P[0]);

            -- pivot;

        }

        else{

            ++ lo;

        }

    }

    return pivot;

}



void qsort_x(pair < int, int > P[100003], int lo, int hi){

    if(lo >= hi){

        return;

    }

    int pivot = partition_x(P, lo, hi);

    qsort_x(P, lo, pivot - 1);

    qsort_x(P, pivot + 1, hi);

    return;

}



bool cmp_y(pair < int, int > a, pair < int, int > b){

    return a.second < b.second;

}



long long closest_dist(pair < int, int > P[100003], int lo, int hi){

    if(hi - lo == 0){

        return 1e18;

    }

    if(hi - lo == 1){

        if(P[lo].second > P[hi].second){

            (P[0] = (P[lo]), (P[lo]) = (P[hi]), (P[hi]) = P[0]);

        }

        return (1ll * (1ll *(P[lo].first - P[hi].first) * (P[lo].first - P[hi].first) + 1ll *(P[lo].second - P[hi].second) * (P[lo].second - P[hi].second)));

    }

    int mid = (lo + hi) / 2,

        xmid = P[mid].first;

    long long left = closest_dist(P, lo, mid),

                right = closest_dist(P, mid + 1, hi),

                d = ((left) < (right) ? (left) : (right));

    merge(P + lo, P + mid + 1, P + mid + 1, P + hi + 1, temp, cmp_y);

    copy(temp, temp + hi - lo + 1, P + lo);

    int nl = 0, nr = 0;

    for(int i = 0, n = hi - lo + 1; i < n; i ++){

        P[lo + i] = temp[i];

        if((1ll * (xmid - temp[i].first) * (xmid - temp[i].first)) < d){

            temp[nr ++] = temp[i];

        }

    }



    for(int i = 0; i < nr; i ++)

        for(int j = i + 1; j < nr && (1ll * (temp[i].second - temp[j].second) * (temp[i].second - temp[j].second)) < d; j ++)

            d = min(d, (1ll * (1ll *(temp[i].first - temp[j].first) * (temp[i].first - temp[j].first) + 1ll *(temp[i].second - temp[j].second) * (temp[i].second - temp[j].second))));

    return d;

}



int main(){

    int n;

    pair < int, int > P[100003];

    fin>>n;

    for(int i = 1; i <= n; i ++){

        fin>>P[i].first>>P[i].second;

    }

    qsort_x(P, 1, n);

    fout<<fixed<<setprecision(6)<<sqrt(closest_dist(P, 1, n))<<"\n";

 return 0;

}
