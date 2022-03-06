#include <fstream>
#include <algorithm>
#include <cmath>
#include <set>
#include <iomanip>


using namespace std;



ifstream fin("cmap.in");

ofstream fout("cmap.out");



const int N = 1e5 + 7;

const double INF = 1e10;



struct Point {

    double x, y;



    bool operator < (const Point &a) const {

        if (x == a.x)

            return y < a.y;

        return x < a.x;

    }

};



double dist(Point a, Point b) {

    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));

}



Point v[N];



struct Elm {

    int poz;



    bool operator < (const Elm &a) const {

        if (v[poz].y == v[a.poz].y)

            return poz < a.poz;

        return v[poz].y < v[a.poz].y;

    }

};



int main()

{

    int n;

    fin >> n;

    for (int i = 1; i <= n; ++i)

        fin >> v[i].x >> v[i].y;

    sort(v, v + n);

    int st(1);

    set < Elm > s;

    double mind(INF);

    for (int i = 1; i <= n; ++i) {

        while (s.size() && v[s.begin()->poz].x + mind <= v[i].x)

            s.erase(s.begin());

        v[i].y -= mind;

        auto top = s.lower_bound((Elm){i});

        v[i].y += 2 * mind;

        auto bottom = s.upper_bound((Elm){i});

        v[i].y -= mind;

        while (top != bottom)

            mind = min(mind, dist(v[i], v[top->poz])),

            top++;

        s.insert((Elm){i});

    }

    fout << fixed << setprecision(7);

    fout << mind;

    return 0;

}
