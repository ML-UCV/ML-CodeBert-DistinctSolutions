#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>

using namespace std;

ifstream fin("cmap.in");
ofstream fout("cmap.out");
const long long INF = 4e18;
struct Punct {
    long long x, y;
};

void readInput(int &n, vector<Punct> &P) {
    fin >> n;
    long long x, y;
    Punct p;
    for (int i = 0; i < n; i++) {
        fin >> x >> y;
        p.x = x, p.y = y;
        P.push_back(p);
    }


}

void merge(vector<Punct> &Py, int st, int m, int dr) {
    int i = st, j = m + 1;
    vector<Punct> temp;
    while (i <= m && j <= dr) {
        if (Py[i].y < Py[j].y)
            temp.push_back(Py[i++]);
        else temp.push_back(Py[j++]);

    }
    while (i <= m)
        temp.push_back(Py[i++]);
    while (j <= dr)
        temp.push_back(Py[j++]);

    for (int i = 0; i < temp.size(); i++)
        Py[st + i] = temp[i];
}

long long distanta(const Punct &a, const Punct &b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

long long compute_strip(vector<Punct> &strip, long long d) {
    long long minim = d;
    int len = strip.size();
    for (int i = 0; i < len - 1; i++)
        for (int j = i + 1; j < len && j <= i + 7; j++)
            minim = min(minim, distanta(strip[i], strip[j]));
    return minim;
}

long long closestTwoPoints(vector<Punct> &Px, vector<Punct> &Py, int st, int dr) {

    if (dr - st == 1) {
        if (Px[st].y > Px[dr].y)
            swap(Px[st], Px[dr]);
        return distanta(Px[st], Px[dr]);
    } else if (dr - st == 2) {
        merge(Py, st, st, st + 1);
        merge(Py, st, st + 1, dr);
        return min(distanta(Px[st], Px[dr]),
                   min(distanta(Px[st + 1], Px[st]), distanta(Px[st + 1], Px[dr])));

    } else {
        int m = (st + dr) / 2;
        long long dLeft = closestTwoPoints(Px, Py, st, m);
        long long dRight = closestTwoPoints(Px, Py, m + 1, dr);

        long long d = min(dLeft, dRight);

        merge(Py, st, m, dr);
        vector<Punct> strip;

        for (int i = st; i <= dr; i++)
            if (abs(Py[i].x - Px[m].x) <= d)
                strip.push_back(Py[i]);


        return compute_strip(strip, d);

    }

}

bool cmp(const Punct &a, const Punct &b) {
    return (a.x < b.x) || (a.x == b.x && a.y < b.y);
}

int main() {
    int n;
    vector<Punct> Px;
    readInput(n, Px);


    sort(Px.begin(), Px.end(), cmp);
    vector<Punct> Py = Px;
    fout << fixed << setprecision(6) << sqrt(closestTwoPoints(Px, Py, 0, n - 1));
    return 0;
}
