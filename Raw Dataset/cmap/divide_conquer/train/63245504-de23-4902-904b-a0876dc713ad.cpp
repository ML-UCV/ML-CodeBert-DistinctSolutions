#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>

std::ifstream fin("cmap.in");
std::ofstream fout("cmap.out");

int n;
std::pair<int, int> V[100010];

void citire() {
    fin >> n;
    for (int i = 1; i <= n; i++)
        fin >> V[i].first >> V[i].second;
}

bool cmp(const std::pair<int, int> &p1, const std::pair<int, int> &p2) {
    return (p1.second < p2.second);
}

long long distanta_euclidiana_la_patrat(const std::pair<int, int> &p1, const std::pair<int, int> &p2) {
    return (long long) (p1.first - p2.first) * (long long) (p1.first - p2.first) +
           (long long) (p1.second - p2.second) * (long long) (p1.second - p2.second);
}


long long Solve(int st, int dr) {

    if (dr - st == 1) {
        return distanta_euclidiana_la_patrat(V[st], V[dr]);
    } else if (dr - st == 2) {
        return std::min(distanta_euclidiana_la_patrat(V[st], V[st + 1]),
                        std::min(distanta_euclidiana_la_patrat(V[st], V[st + 2]),
                                 distanta_euclidiana_la_patrat(V[st + 1], V[st + 2])));
    }

    int mij = (st + dr) / 2;

    long long d = std::min(Solve(st, mij), Solve(mij + 1, dr));

    std::vector<std::pair<int, int> > A;

    int delta = static_cast<int>(std::ceil(std::sqrt(d)));
    for (int i = st; i <= dr; i++) {
        if (std::abs(V[i].first - V[mij].first) <= delta) {
            A.push_back(V[i]);
        }
    }

    sort(A.begin(), A.end(), cmp);

    for (int i = 0; i < A.size(); i++) {
        for (int j = i + 1; j <= i + 7 && j < A.size(); j++) {
            d = std::min(d, distanta_euclidiana_la_patrat(A[i], A[j]));
        }
    }
    return d;
}

int main() {
    citire();

    sort(V + 1, V + 1 + n);

    fout << std::fixed << std::setprecision(6) << sqrt(Solve(1, n)) << '\n';
    return 0;
}
