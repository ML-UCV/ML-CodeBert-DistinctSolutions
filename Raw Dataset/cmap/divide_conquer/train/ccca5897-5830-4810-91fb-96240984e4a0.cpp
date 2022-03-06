#include <cmath>
#include <vector>
#include <iomanip>
#include <fstream>
#include <algorithm>






typedef std::pair<int, int> Point;
const int OFFSET = 8;
const double INF = 1e18;

std::vector<Point> points, aux;

std::ifstream fin("cmap.in"); std::ofstream fout("cmap.out");


long long get_dist(Point a, Point b) {
    return 1LL * (a.first - b.first) * (a.first - b.first) + 1LL * (a.second - b.second) * (a.second - b.second);
}


void merge(int left, int right, int mid) {
    int p1 = left, p2 = mid + 1, id = 0;

    while (p1 <= mid && p2 <= right) {
        if (points[p1].second < points[p2].second) {
            aux[id++] = points[p1++];
        } else {
            aux[id++] = points[p2++];
        }
    }

    while (p1 <= mid) {
        aux[id++] = points[p1++];
    }
    while (p2 <= right) {
        aux[id++] = points[p2++];
    }

    for (int i = 0; i < id; i++) {
        points[left + i] = aux[i];
    }
}

long long divide(int left, int right) {
    if (right - left < 2) {
        if (left == right) {
            return INF;
        } else {
            merge(left, right, left);
            return get_dist(points[left], points[right]);
        }
    }

    int mid = (left + right) / 2;
    long long dist = std::min(divide(left, mid), divide(mid + 1, right));
    merge(left, right, mid);

    for (int i = left; i <= right; i++) {
        for (int j = i - 1; j >= left && i - j < OFFSET; j--) {
            dist = std::min(dist, get_dist(points[i], points[j]));
        }
    }

    return dist;
}


int main() {
    int n; fin >> n;
    points.resize(n); aux.resize(n);

    for (auto& point: points) {
        fin >> point.first >> point.second;
    }
    std::sort(points.begin(), points.end());

    fout << std::fixed << std::setprecision(10) << std::sqrt((double)divide(0, n - 1)) << "\n";
    return 0;
}
