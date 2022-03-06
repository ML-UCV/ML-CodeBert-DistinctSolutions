#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>






using namespace std;



ifstream cin ("cmap.in");

ofstream cout("cmap.out");



vector <pair<int, int> > a;



void read()

{

    int n, first, second;

    cin >> n;

    a.resize(n);



    for (int i = 0; i < a.size(); i++)

        cin >> a[i].first >> a[i].second;

}



bool f(pair<long long, long long> first, pair<long long, long long> second)

{

    return first.first < second.first;

}



double dist(pair<long long, long long> first, pair<long long, long long> second)

{

    return sqrt((first.first - second.first) * (first.first - second.first) + (first.second - second.second) * (first.second - second.second));

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
