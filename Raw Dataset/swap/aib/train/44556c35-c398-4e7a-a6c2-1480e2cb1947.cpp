#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;






int n, i;
char a[50011], b[50011];
int perm[50011];
int id[26][50011];
int pos[26], act[26];

int aib[50011];
long long ans;

int zrs(int x) {
    return (x ^ (x - 1)) & x;
}

void add(int pos) {
    while (pos <= n) {
        aib[pos]++;
        pos += zrs(pos);
    }
}

int sum(int pos) {
    int ans = 0;
    while (pos) {
        ans += aib[pos];
        pos -= zrs(pos);
    }
    return ans;
}

int main()
{
    freopen("swap.in","r",stdin);
    freopen("swap.out","w",stdout);

    scanf("%s\n%s", a + 1, b + 1);
    n = strlen(a + 1);

    for (i = 1; i <= n; i++)
        id[ b[i] - 'a' ][pos[ b[i] - 'a' ]++] = i;

    for (i = 1; i <= n; i++) {
        int go = a[i] - 'a';
        if (pos[go] == act[go]) {
            printf("-1");
            return 0;
        }
        perm[i] = id[go][ act[go]++ ];
    }

    ans = 1LL * n * (n - 1);
    ans /= 2;

    for (i = 1; i <= n; i++) {
        ans -= sum(perm[i]);
        add(perm[i]);
    }

    printf("%lld", ans);

    return 0;
}
