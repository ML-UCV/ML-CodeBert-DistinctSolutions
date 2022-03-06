#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

const long long INF = 1e18;

vector<pair<long long, long long>> points;

void read() {
    ifstream fin("cmap.in");

    int n;
    fin >> n;
    for (int i = 0; i < n; ++i) {
        long long x, y;
        fin >> x >> y;
        points.emplace_back(make_pair(x, y));
    }

    fin.close();
}

long long dist(const pair<long long, long long> &A, const pair<long long, long long> &B) {
    return (A.first - B.first) * (A.first - B.first) + (A.second - B.second) * (A.second - B.second);
}

void merge(int left_idx, int mid_idx, int right_idx) {
    int i = left_idx;
    int j = mid_idx + 1;

    vector<pair<long long, long long>> temp;
    while (i <= mid_idx && j <= right_idx)
        if (points[i].second < points[j].second)
            temp.push_back(points[i++]);
        else
            temp.push_back(points[j++]);

    while (i <= mid_idx)
        temp.push_back(points[i++]);

    while (j <= right_idx)
        temp.push_back(points[j++]);

    for (int idx = 0; idx < (int)temp.size(); ++idx)
        points[left_idx + idx] = temp[idx];
}


long long closest_points(int left_idx, int right_idx) {
    if (right_idx - left_idx < 2) {
        if (left_idx == right_idx) {
            return INF;
        }
        else {
            merge(left_idx, left_idx, right_idx);
            return dist(points[left_idx], points[right_idx]);
        }
    }

    int mid_index = left_idx + (right_idx - left_idx) / 2;

    long long current_best = min(closest_points(left_idx, mid_index), closest_points(mid_index + 1, right_idx));

    merge(left_idx, mid_index, right_idx);

    for (int i = left_idx; i <= right_idx; ++i)
        for (int j = i - 1; j >= left_idx && i - j < 8; --j)
            current_best = min(current_best, dist(points[i], points[j]));

    return current_best;
}

void print() {
    ofstream fout("cmap.out");
    fout << fixed << setprecision(6) << sqrt(closest_points(0, (int)points.size() - 1));
    fout.close();
}

int main() {
    read();
    sort(points.begin(), points.end());
    print();
    return 0;
}
