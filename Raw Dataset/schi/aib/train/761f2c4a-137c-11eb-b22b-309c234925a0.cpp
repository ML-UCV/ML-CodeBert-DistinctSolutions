#include <fstream>
#include <iostream>
using namespace std;
ifstream fin("schi.in");
ofstream fout("schi.out");
int v[30005], o[30005], aj[30005];
int n;
void read() {
    fin >> n;
    for (int i = 1; i <= n; ++i) {
        fin >> v[i];
    }
}
void update(int p, int val) {
    for (int i = p; i <= n; i += i & -i) {
        aj[i] += val;
    }
}
void setToOne() {
    for (int i = 1; i <= n; ++i) {
        update(i, 1);
    }
}
long query(int p) {
    long s = 0;
    for (int i = p; i > 0; i -= i & -i) {
        s += aj[i];
    }
    return s;
}
int searchSum(int sum) {
    int pos = n + 1, p;
    int st = 0, dr = n + 1;
    p = n;
    int s = query(p);
    if (s == sum) {
        pos = n;
    }
    while (p && p > st && p < dr) {
        p = (st + dr) / 2;
        s = query(p);
        if (s > sum)
        {
            if (dr > p)
                dr = p;
            p -= 1;
        }
        else if (s == sum) {
            pos = min(pos, p);
            dr = p;
            p -= 1;
        }
        else
        {
            if (st < p) {
                st = p;
            }
            p += 1;
        }
    }
    if (pos == n + 1)
        return -1;
    return pos;
}
int main()
{
    read();
    setToOne();
    o[v[n]] = n;
    update(v[n], -1);
    for (int i = n - 1; i >= 1; --i) {
        int loc = searchSum(v[i]);
        o[loc] = i;
        update(loc, -1);
    }
    for (int i = 1; i <= n; ++i) {
        fout << o[i] << "\n";
    }
    return 0;
}
