#include <vector>
#include <algorithm>
#include <fstream>
#include <limits>
#include <cmath>
#include <iomanip>
#include <iostream>

using point = std::pair<double, double>;
using pointArr = std::vector<point>;

double squaredDistance(const point& p1, const point& p2) {
    return std::pow(p1.first - p2.first, 2) + std::pow(p1.second - p2.second, 2);
}

double solve(const pointArr& points, int left, int right) {
    static pointArr pointsCopy = points;
    if (left >= right) {
        return std::numeric_limits<double>::max();
    }
    else if (right - left == 1) {
        if (pointsCopy[left].second > pointsCopy[right].second) {
            std::swap(pointsCopy[left], pointsCopy[right]);
        }
        return squaredDistance(points[left], points[right]);
    }
    auto middle = (left + right) >> 1;
    auto minLeft = solve(points, left, middle);
    auto minRight = solve(points, middle + 1, right);
    auto delta = std::min(minLeft, minRight);
    pointArr candidates(right - left + 1);
    std::merge(pointsCopy.begin() + left, pointsCopy.begin() + middle + 1, pointsCopy.begin() + middle + 1, pointsCopy.begin() + right + 1, candidates.begin(),
        [](const point& p1, const point& p2) {
            return p1.second < p2.second;
        });
    std::copy(candidates.begin(), candidates.end(), pointsCopy.begin() + left);
    candidates.clear();
    for (auto it = left; it <= right; ++it) {
        if (std::abs(pointsCopy[it].first - points[middle].first) <= delta) {
            candidates.push_back(pointsCopy[it]);
        }
    }
    for(auto it = 0u; it < candidates.size(); ++it) {
        for (auto it2 = it + 1; it2 < candidates.size() && it2 - it < 6; ++it2) {
            delta = std::min(delta, squaredDistance(candidates[it], candidates[it2]));
        }
    }
    return delta;
}

int main()
{
    pointArr points;
    std::ifstream fin("cmap.in");
    auto n = 0; fin >> n;
    for (auto it = 0; it < n; ++it) {
        point currentPoint;
        fin >> currentPoint.first >> currentPoint.second;
        points.push_back(currentPoint);
    }
    fin.close();
    std::sort(points.begin(), points.end());
    std::ofstream fout("cmap.out");
    fout << std::fixed << std::setprecision(6) << std::pow(solve(points, 0, points.size() - 1), 0.5);;
    fout.close();
    return 0;
}
