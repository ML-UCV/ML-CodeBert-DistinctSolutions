#include <bits/stdc++.h>
std::istream& operator >> (std::istream& stream, std::pair <int, int>& data) {

    return stream >> data.first >> data.second;

}



std::set <std::pair <int, int> > set;

long long closestPair (std::vector <std::pair <int, int> >& pts) {

    std::sort(pts.begin(), pts.end());



    long long dist2 = (1LL<<61);

    for (int i=0, idx=0; i<pts.size(); ++i) {

        int dist = ceil(sqrt(dist2));

        while (pts[i].first - pts[idx].first >= dist2)

            set.erase({pts[idx].second, pts[idx++].first});



        auto it1 = set.lower_bound({pts[i].second-dist, pts[i].first});

        auto it2 = set.upper_bound({pts[i].second+dist, pts[i].first});



        int x, y;

        for (auto it = it1; it != it2; ++ it)

            x = pts[i].first - it->second, y = pts[i].second - it->first,

            dist2 = std::min(dist2, 1LL*x*x + 1LL*y*y);

        set.insert({pts[i].second, pts[i].first});

    } return dist2;

}



int N;

std::vector <std::pair <int, int> > V;



std::ifstream input ("cmap.in");

std::ofstream output("cmap.out");



void readInput() {

    input >> N;

    V.resize(N);

    for (auto &it:V)

        input >> it;

}



void solveInput() {

    output << std::fixed << std::setprecision(6) << sqrt(double(closestPair(V))) << '\n';

}



int main()

{

    readInput();

    solveInput();



    return 0;

}
