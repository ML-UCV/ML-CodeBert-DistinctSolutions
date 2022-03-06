#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;





class PointSet {
    public:
        PointSet(const vector<pair<int, int> >& points) : points_(points) {}

        double FindClosestPair() {
            sort(points_.begin(), points_.end());

            set<pair<int, int>, YComparator> interesting_points;
            double closest_pair = kMaxInf;

            for (int left_p = 0, right_p = 0; right_p < (int)points_.size(); right_p++) {
                long long current_solution = (long long)closest_pair + 1;

                while (left_p < right_p
                        && current_solution + points_[left_p].first < 1LL * points_[right_p].first) {
                    interesting_points.erase(points_[left_p++]);
                }

                pair<int, int> aux = {0,
                             (int)max(1LL * kMinCoordinate, 1LL * points_[right_p].second - current_solution)
                            };
                for (auto it = interesting_points.lower_bound(aux); it != interesting_points.end()
                        && 1LL * it->second <= current_solution + points_[right_p].second; it++) {
                    closest_pair = min(closest_pair, GetDistance(*it, points_[right_p]));
                }

                interesting_points.insert(points_[right_p]);
            }

            return closest_pair;
        }

    private:
        const int kMinCoordinate = -1e9;
        const double kMaxInf = 1e10;
        vector<pair<int, int> > points_;

        static double GetDistance(const pair<int, int>& a, const pair<int, int>& b) {
            return sqrt(1.0 * (a.first - b.first) * (a.first - b.first) + 1.0 * (a.second - b.second) * (a.second - b.second));
        }

        struct YComparator {
            bool operator () (const pair<int, int> &a, const pair<int, int>& b) const {
                return a.second < b.second;
            }
        };
};

int main() {
    cin.sync_with_stdio(false);

    ifstream cin("cmap.in");
    ofstream cout("cmap.out");

    int n;
    cin >> n;

    vector<pair<int, int> > points;
    for (int i = 0; i < n; i++) {
        int first, second;
        cin >> first >> second;
        points.emplace_back(first, second);
    }

    PointSet s(points);
    cout << fixed << setprecision(7) << s.FindClosestPair() << '\n';

    return 0;
}
