#include <fstream>
#include <iomanip>
#include <algorithm>
#include <complex>
#include <cmath>

using namespace std;

typedef complex <double> Point;

const int NMAX = 100000 + 5;
Point points[NMAX];

const double PI = acos(-1);
const double ANG = 7 * PI / 6;

class PointCmp {
public:
    bool operator()(const Point &a, const Point &b) {
        return a.real() < b.real();
    }
};

int main()
{
    ifstream cin("cmap.in");
    ofstream cout("cmap.out");

    int n;
    cin >> n;

    for (int i = 1; i <= n; ++ i) {
        int x, y;
        cin >> x >> y;
        points[i] = Point(x, y) * polar(1.0, ANG);
    }

    sort(points + 1, points + n + 1, PointCmp());

    double ans = abs(points[1] - points[2]);
    for (int i = 1; i <= n; ++ i)
        for (int j = i + 1; j <= n && points[i].real() + ans > points[j].real() - 1e-8; ++ j) {
            double aux = abs(points[i] - points[j]);
            if (aux < ans)
                ans = aux;
        }

    cout << fixed << setprecision(6) << ans << '\n';

    cin.close();
    cout.close();
    return 0;
}
