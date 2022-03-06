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

    int n, x, y;

    cin >> n;



    for (int i = 0; i < n; i++)

    {

        cin >> x >> y;

        a.push_back(make_pair(x, y));

    }

}



bool f(pair<long long, long long> x, pair<long long, long long> y)

{

    return x.first < y.first;

}



double dist(pair<long long, long long> x, pair<long long, long long> y)

{

    return sqrt((x.first - y.first) * (x.first - y.first) + (x.second - y.second) * (x.second - y.second));

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
