#include <algorithm>
#include <bitset>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <cstring>
#include <string>
#include <cstdlib>
#include <fstream>
#include <iostream>
using namespace std;


ifstream fin ("cmap.in");
ofstream fout ("cmap.out");



const int INF = 2000000000;
const int Nmax = 100000 + 10;
const double EPS = 0.000001;
using int64 = long long;
using PointTemp = pair <int64, int64>;

int N;
vector <PointTemp> Px, Py;
double res = 9999999999999;

void Input();
inline double Dist(const PointTemp&, const PointTemp&);
inline int64 Solve(int, int, vector <PointTemp>&, vector <PointTemp>&);

int main()
{
    Input();
    sort(Px.begin(), Px.end());
    for (int i = 0; i < N; ++i)
        for (int j = i+1, rng = 10; j < N && rng; ++j, --rng)
        {
            res = min(res, Dist(Px[i], Px[j]));
        }
    fout << fixed << setprecision(6) << res << '\n';
}
void Input()
{
    fin >> N;
    for (int i = 1, x, y; i <= N; ++i)
    {
        fin >> x >> y;
        Px.push_back({x, y});
    }
};





inline double Dist(const PointTemp& A, const PointTemp& B)
{
    return sqrt( 1LL * (B.second - A.second) * (B.second - A.second) + 1LL * (B.first - A.first) * (B.first - A.first) );
};
