#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

const int NMAX = 100010;
int aib[NMAX];
int n;

void update(int poz)
{
    while (poz <= n)
        aib[poz]++, poz += ((poz) & -(poz));
}
int query(int poz)
{
    int ans = 0;
    while (poz)
        ans += aib[poz], poz -= ((poz) & -(poz));
    return ans;
}

int v[NMAX];

int main()
{
    FILE * in = fopen("inv.in", "r");
    FILE * out = fopen("inv.out", "w");

    vector <int> nrz;

    fscanf(in, "%d", &n);

    for (int i = 1; i <= n; i++) {
        fscanf(in, "%d", v + i);
        nrz.push_back(v[i]);
    }

    sort(nrz.begin(), nrz.end());
    nrz.resize(unique(nrz.begin(), nrz.end()) - nrz.begin());

    for (int i = 1; i <= n; i++)
        v[i] = lower_bound(nrz.begin(), nrz.end(), v[i]) - nrz.begin() + 1;

    long long ans = 0;

    for (int i = 1; i <= n; i++) {
        update(v[i]);
        ans += i - query(v[i]);
    }

    fprintf(out, "%lld\n", ans % 9917);

    return 0;
}
