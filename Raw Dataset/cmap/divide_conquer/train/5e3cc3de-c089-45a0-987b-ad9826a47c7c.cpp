#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;



struct Point {

    int x, y;

};



bool cmp(Point a, Point b) {

    return a.x < b.x;

}



long long sqlong(long long x) {

    return x*x;

}



long long dist(Point a, Point b) {

    return sqlong(a.x-b.x)+sqlong(a.y-b.y);

}



long long minDist(vector<Point>::iterator a, vector<Point>::iterator b) {

    long long d;

    vector<Point>::iterator i, j;

    int n = (b-a)/2;

    if (b-a<=3) {

        d = dist(*a, *(b-1));

    } else {

        d = min(minDist(a, a+n), minDist(a+n, b));

    }

    for (i = a; i<a+n; i++) {

        for (j = a+n; j<b && sqlong((*i).x-(*j).x)<d; j++) {

            d = min(d, dist(*i, *j));

        }

    }

    return d;

}



main() {

    ifstream cin("cmap.in");

    ofstream cout("cmap.out");

    int n;

    cin>>n;

    vector<Point> a(n);

    for (int i = 0; i < n; i++) {

        cin>>a[i].x>>a[i].y;

    }

    sort(a.begin(), a.end(), cmp);

    cout<<fixed;

    cout<<setprecision(9)<<sqrt(minDist(a.begin(), a.end()));



}
