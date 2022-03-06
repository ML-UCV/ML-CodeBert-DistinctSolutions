#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>







typedef std::pair<int, int> Point;
FILE *fin = freopen("cmap.in", "r", stdin); FILE *fout = freopen("cmap.out", "w", stdout);

const long long INF = 1e18;
const long long OFFSET = 8;
int n;
std::vector<Point> pts, aux;


void read_input() {
    scanf("%d", &n);
    pts.resize(n); aux.resize(n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &pts[i].first, &pts[i].second);
    }
}


long long get_dist(Point a, Point b) {
    return 1LL * (a.first - b.first) * (a.first - b.first) + 1LL * (a.second - b.second) * (a.second - b.second);
}


void merge(int left, int right, int mid) {
    int p1 = left, p2 = mid + 1, id = 0;

    while (p1 <= mid && p2 <= right) {
        if (pts[p1].second < pts[p2].second) {
            aux[id++] = pts[p1++];
        } else {
            aux[id++] = pts[p2++];
        }
    }

    while (p1 <= mid) {
        aux[id++] = pts[p1++];
    }

    while (p2 <= mid) {
        aux[id++] = pts[p2++];
    }

    for (int i = 0; i < id; i++) {
        pts[left + i] = aux[i];
    }
}


long long divide(int left, int right) {
    if (right - left < 2) {
        if (left == right) {
            return INF;
        } else {
            merge(left, right, left);
            return get_dist(pts[left], pts[right]);
        }
    }

    int mid = (left + right) / 2;
    long long dist_1 = divide(left, mid), dist_2 = divide(mid + 1, right);
    long long d = std::min(dist_1, dist_2);

    merge(left, right, mid);
    for (int i = left; i <= right; i++) {
        for (int j = i - 1; j >= left && i - j < OFFSET; j--) {
            d = std::min(d, get_dist(pts[i], pts[j]));
        }
    }

    return d;
}


int main(int argc, char const *argv[]) {
    read_input();

    std::sort(pts.begin(), pts.end());

    printf("%.10f\n", std::sqrt((double)divide(0, n - 1)));
    return 0;
}
