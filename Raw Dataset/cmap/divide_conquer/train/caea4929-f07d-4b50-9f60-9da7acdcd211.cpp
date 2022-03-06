#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
typedef long long int int64;



using namespace std;



ifstream in("cmap.in");

ofstream out("cmap.out");



const int64 lookup = 7;



bool cmpX(pair <int64, int64> &a, pair <int64, int64> &b) {

    if (a.first < b.first)

        return true;

    return false;

}



bool cmpY(pair <int64, int64> &a, pair <int64, int64> &b) {

    if (a.second < b.second)

        return true;

    return false;

}



int64 get_dist(pair <int64, int64> &a, pair <int64, int64> &b) {

    return (b.first - a.first) * (b.first - a.first) + (b.second - a.second) * (b.second - a.second);

}



inline int64 square(int64 a) {

    return a * a;

}



int64 cmap(vector <pair <int64, int64> > &pct, int left, int right) {

    if (right - left + 1 <= 3) {

        int64 d1, d2, d3;

        d1 = get_dist(pct[0], pct[1]);

        d2 = get_dist(pct[1], pct[2]);

        d3 = get_dist(pct[0], pct[2]);

        if (d1 <= d2 && d1 <= d3)

            return d1;

        if (d2 <= d1 && d2 <= d3)

            return d2;

        return d3;

    }

    int mid = left + (right - left) / 2;

    int64 d1, d2;

    d1 = cmap(pct, left, mid);

    d2 = cmap(pct, mid, right);

    if (d1 > d2)

        d1 = d2;



    vector <pair <int64, int64> > val_pct;

    int64 midx = pct[mid].first;

    val_pct.push_back(pct[mid]);



    int search_left = mid - 1, search_right = mid + 1;

    while (search_left >= left && square(midx - pct[search_left].first) < d1) {

        val_pct.push_back(pct[search_left]);

        search_left--;

    }

    while (search_right <= right && square(pct[search_right].first - midx) < d1) {

        val_pct.push_back(pct[search_right]);

        search_right++;

    }



    sort(val_pct.begin(), val_pct.end(), cmpY);



    for (int i = 0; i < val_pct.size(); i++) {

        for (int j = i + 1; j < val_pct.size() && j - i <= lookup; j++) {

            d2 = get_dist(val_pct[i], val_pct[j]);

            if (d1 > d2) {

                d1 = d2;

                continue;

            }

            if (square(val_pct[j].second - val_pct[i].second) >= d1)

                break;

        }

    }



    return d1;

}



int main() {

    int64 n;

    in >> n;

    vector <pair <int64, int64> > pct(n);

    for (int64 i = 0; i < n; i++) {

        in >> pct[i].first >> pct[i].second;

    }

    sort(pct.begin(), pct.end(), cmpX);

    out << setprecision(20) << sqrt(cmap(pct, 0, n - 1)) << '\n';

    return 0;

}
