#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
using namespace std;

ifstream ka("cmap.in");
ofstream ki("cmap.out");


vector<std::pair<long long, long long>> V;

void interclasare(int, int, int);

bool cmp(const std::pair<int, int> &p1, const std::pair<int, int> &p2)
{
    return (p1.second < p2.second);
}

long long dist(const pair <long long, long long>& a, const pair <long long, long long>& b)
{
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

long long solve(int st, int dr)
{
    if (dr - st == 1)
    {
        if (V[st].second > V[dr].second)
            swap(V[st], V[dr]);
        return dist(V[st], V[dr]);
    }
    else if (dr - st == 2)
    {
        sort(V.begin() + st, V.begin() + dr + 1, cmp);
        return min(dist(V[st], V[st + 1]), min(dist(V[st], V[st + 2]), dist(V[st + 1], V[st + 2])));
    }

    int mid = (st + dr) / 2;
    int mid_x = V[mid].first;
    long long d = min(solve(st, mid), solve(mid + 1, dr));
    auto delta = static_cast<int>(ceil(sqrt(d)));
    interclasare(st, mid, dr);

    vector<std::pair<int, int>> A;
    for (int i = st; i <= dr; i++)
    {
        if (abs((V[i].first - mid_x)) <= delta)
            A.push_back(V[i]);
    }
    for (int i = 0; i < A.size(); i++)
        for (int j = i + 1; j <= i + 7 && j < A.size(); j++)
            d = min(d, dist(A[i], A[j]));

    return d;
}

void interclasare(int start, int m, int end)
{
    vector<pair<int, int>> Aux;
    int i = start, j = m + 1;

    while ((i <= m) && (j <= end))
        if (V[i].second <= V[j].second)
            Aux.push_back(V[i++]);
        else
            Aux.push_back(V[j++]);

    while (i <= m)
        Aux.push_back(V[i++]);

    while (j <= end)
        Aux.push_back(V[j++]);

    for (i = start; i <= end; i++)
        V[i] = Aux[i - start];
}

int main()
{
    int n;
    ka >> n;

    for (int i = 0; i < n; i++)
    {
        long long a, b;
        ka >> a >> b;
        V.emplace_back(make_pair(a, b));
    }

    sort(V.begin(), V.end());

    ki << fixed << setprecision(6) << sqrt(solve(0, n - 1)) << '\n';
    return 0;
}
