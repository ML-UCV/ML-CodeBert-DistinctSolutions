#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;
ifstream fin("inv.in");
ofstream fout("inv.out");
struct numar {
    int poz, val;
};
int n;
numar v[100001];
int a[100005];
void citire() {
    fin >> n;
    int va;
    for (int i = 0; i < n; ++i) {
        fin >> va;
        v[i].val = va;
        v[i].poz = i + 1;
    }
}
bool comp(numar a, numar b) {
    if (a.val == b.val) {
        return a.poz > b.poz;
    }
    return a.val > b.val;
}
void update(int poz, int val) {
    for (int i = poz; i <= n; i += i & -i) {
        a[i] = (a[i] + val) % 9917;
    }
}
long query(int poz) {
    long s = 0;
    for (int i = poz; i >= 1; i -= i & -i) {
        s += a[i] % 9917;
    }
    return s % 9917;
}
int main()
{
    long inv = 0;
    citire();
    sort(v, v + n, comp);
    for (int i = 0; i < n; ++i) {
        inv = (inv + query(v[i].poz)) % 9917;
        update(v[i].poz, 1);
    }
    fout << inv << "\n";
    return 0;
}
