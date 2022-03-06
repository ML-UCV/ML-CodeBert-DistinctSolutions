#include <fstream>
#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;
int n;
struct punct {
    double x, y;
} p[100005], p1[100005];

inline bool cmpx(punct A, punct B) {
    return A.x < B.x;
}

inline bool cmpy(punct A, punct B) {
    return A.y < B.y;
}

double dist(punct A, punct B) {
    return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
}

double Dist(int st, int dr) {
    int i, j, ct = 0;
    int mid = (st + dr) / 2;
    if (st == dr - 1)return dist(p[st], p[dr]);
    if(st==dr)return 4000000000;
    double drx = (p[mid].x + p[mid + 1].x) / 2;
    double D = min(Dist(st, mid), Dist(mid + 1, dr));
    for (i = st; i <= mid; i++)
        if (drx - p[i].x < D) {
            ct++;
            p1[ct] = p[i];
        }
    for (i = mid + 1; i <= dr; i++)
        if (p[i].x - drx < D) {
            ct++;
            p1[ct] = p[i];
        }
    sort(p1 + 1, p1 + ct + 1, cmpy);
    for (i = 1; i <= ct; i++) {
        for (j = i + 1; j <= ct; j++) {
            if (p1[j].y - p1[i].y >= D)break;
            D = min(D, dist(p1[i], p1[j]));
        }
    }
    return D;
}

int main() {
    int i;
    ifstream fin("cmap.in");
    ofstream fout("cmap.out");
    fin >> n;
    for (i = 1; i <= n; i++)
        fin >> p[i].x >> p[i].y;
    sort(p + 1, p + n + 1, cmpx);
    fout <<setprecision(6)<<fixed<< Dist(1, n);
}
