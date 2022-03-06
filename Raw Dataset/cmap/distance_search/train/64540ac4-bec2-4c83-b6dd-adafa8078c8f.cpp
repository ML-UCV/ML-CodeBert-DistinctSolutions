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

    long long d = dist(a[0], a[1]);

    for (int i = 1; i < n-1; i++) {

        d = min(d, dist(a[i], a[i+1]));

    }

    for (int i = 0; i < n; i++) {

        for (int j = i+1; j < n && sqlong(abs(a[i].x-a[j].x)) < d; j++) {

            d = min(d, dist(a[i], a[j]));

        }

    }



    cout<<fixed;

    cout<<setprecision(9)<<sqrt(d);



}
