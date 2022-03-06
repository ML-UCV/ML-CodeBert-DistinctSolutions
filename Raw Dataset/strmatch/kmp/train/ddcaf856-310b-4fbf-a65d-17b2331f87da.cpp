#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

ifstream f("strmatch.in");
ofstream g("strmatch.out");

int p[2000005];
char a[2000005], b[2000005];
int sol[1005];


void rez() {
    int k = 0, m = strlen(a + 1);
    p[1] = 0;
    for (int j = 2; j <= m; j++) {
        while (k > 0 && a[k + 1] != a[j])
            k = p[k];
        if (a[k + 1] == a[j]) {
            k++;
        }
        p[j] = k;
    }
}

void afisare(int nr) {
    g << nr << '\n';
    nr = min(nr, 1000);
    for (int i = 1; i <= nr; i++)
        g << sol[i] << ' ';
}

int match() {
    int k = 0, nr = 0, n = strlen(b + 1), m = strlen(a + 1);

    for (int i = 1; i <= n; i++) {
        while (k > 0 && a[k + 1] != b[i])
            k = p[k];
        if (b[i] == a[k + 1])
            k++;
        if (k == m) {
            nr++;
            if (nr <= 1000)
                sol[nr] = i - m;
            k = p[k];
        }
    }
    return nr;
}

int main() {
    f.getline(a + 1, 2000005);
    f.getline(b + 1, 2000005);
    rez();
    afisare(match());
    return 0;
}
