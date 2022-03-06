#include <bits/stdc++.h>


using namespace std;



typedef long long i64;



set <pair <int, int>> sline;

vector <pair <int, int>> points;

i64 distact = 1e18;

int until;



inline void pass(int poz)

{

    while (1) {

        int dist = points[poz].first - points[until].first;

        if (1LL * (dist) * (dist) >= distact) {

            sline.erase({ points[until].second, until });

            until++;

        }

        else

            break;

    }

}



int main()

{

    FILE *in = fopen("cmap.in", "r");

    ofstream out("cmap.out");



    int n;

    fscanf(in, "%d", &n);



    points.resize(n);



    for (auto & i : points)

        fscanf(in, "%d%d", &i.first, &i.second);



    sort(points.begin(), points.end());

    until = 0;

    sline.insert({ points[0].second, 0 });



    for (int i = 1; i < n; i++) {

        auto x = sline.lower_bound({ points[i].second, 0 });

        while (x != sline.end()) {

            i64 d = 1LL * (points[i].second - x->first) * (points[i].second - x->first);

            if (d > distact)

                break;

            d += 1LL * (points[i].first - points[x->second].first) * (points[i].first - points[x->second].first);

            distact = min(distact, d);

            x++;

        }

        x = sline.lower_bound({ points[i].second, 0 });

        while (x != sline.begin()) {

            x--;

            i64 d = 1LL * (points[i].second - x->first) * (points[i].second - x->first);

            if (d > distact)

                break;

            d += 1LL * (points[i].first - points[x->second].first) * (points[i].first - points[x->second].first);

            distact = min(distact, d);

        }

        sline.insert({ points[i].second, i });

        pass(i);

    }



    out << setprecision(9) << fixed << sqrt(distact) << '\n';



    return 0;

}
