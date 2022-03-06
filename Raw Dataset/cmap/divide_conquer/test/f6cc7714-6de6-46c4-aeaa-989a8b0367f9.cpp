#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-10;

double minimum (double a, double b) {
    if (a + eps <= b) return a;
    return b;
}

double sq (double x) {
    return x * x;
}

double getDistance (pair <double, double> &A, pair <double, double>& B) {
    return sqrt (sq(A.first - B.first) + sq(A.second - B.second));
}

pair <double, double> points[100005];
pair <double, double> auxiliar[100005];

bool cmp (pair <double, double> A, pair <double, double> B) {
    return A.second + eps <= B.second;
}

double getDistance (int left, int right) {
    if (right - left + 1 <= 3) {
        sort (points + left, points + right + 1, cmp);
        double minim = 1e15;
        for (int i = left; i <= right; ++i) {
            for (int j = i + 1; j <= right; ++j) {
                minim = minimum(minim, getDistance(points[i], points[j]));
            }
        }
        return minim;
    }
    int middle = left + right >> 1;
    double minim = getDistance(left, middle);
    minim = minimum (minim, getDistance(middle + 1, right));
    int leftIt = left;
    int rightIt = middle + 1;
    for (int i = left; i <= right; ++i) {
        if (leftIt == middle + 1 || (rightIt <= right and !cmp (points[leftIt], points[rightIt]))) {
            auxiliar[i] = points[rightIt];
            rightIt += 1;
        }
        else {
            auxiliar[i] = points[leftIt];
            leftIt += 1;
        }
    }
    for (int i = left; i <= right; ++i) {
        points[i] = auxiliar[i];
    }
    for (int i = left; i <= right; ++i) {
        for (int j = i + 1; j <= min(right, i + 7); ++j) {
            minim = minimum(minim, getDistance(points[i], points[j]));
        }
    }
    return minim;
}

int main() {
    ifstream fin ("cmap.in");
    ofstream fout ("cmap.out");
    ios::sync_with_stdio(false);
    fin.tie(nullptr);
    int n;
    fin >> n;
    for (int i = 1; i <= n; ++i) {
        fin >> points[i].first >> points[i].second;
    }
    sort (points + 1, points + n + 1);
    fout << setprecision(7) << fixed << getDistance(1, n);
    return 0;
}
