#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;



ifstream cin ("cmap.in");

ofstream cout("cmap.out");



vector <pair <long long, long long> > a;



void read()

{

    int n, first, second;

    cin >> n;

    a.resize(n);



    for (int i = 0; i < a.size(); i++)

        cin >> a[i].first >> a[i].second;

}



bool f(pair <long long, long long> a, pair <long long, long long> b)

{

    return a.first < b.first;

}



double dist(pair <long long, long long> a, pair <long long, long long> b)

{

    return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));

}



double solve()

{

    sort(a.begin(), a.end(), f);



    double d = dist(a[0], a[1]);



    for (int i = 0; i < a.size(); i++)

        for (int j = i + 1; a[j].first - a[i].first < d && j < a.size(); j++)

            d = min(d, dist(a[i], a[j]));



    return d;

}



int main()

{

    read();



    cout << fixed << setprecision(10) << solve() ;



    return 0;

}
