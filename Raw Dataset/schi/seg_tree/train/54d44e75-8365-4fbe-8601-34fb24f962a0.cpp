#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef signed long long ll;
typedef unsigned int uint;
typedef unsigned short ush;
const int nmax = 30001;

struct node_t {
    short lower, mini, pos;
};
node_t arbint[nmax * 4 + 66];
short v[nmax];

void build(uint nodei, uint lefti, uint righti) {
    if (lefti == righti) {
        arbint[nodei].lower = 0;
        arbint[nodei].mini = v[lefti];
        arbint[nodei].pos = lefti;
        return ;
    }

    uint midi = (lefti + righti) / 2;
    build(2 * nodei + 1, lefti, midi);
    build(2 * nodei + 2, midi + 1, righti);

    arbint[nodei].mini = arbint[2 * nodei + 1].mini;
    arbint[nodei].pos = arbint[2 * nodei + 1].pos;

    if (arbint[nodei].mini >= arbint[2 * nodei + 2].mini) {
        arbint[nodei].mini = arbint[2 * nodei + 2].mini;
        arbint[nodei].pos = arbint[2 * nodei + 2].pos;

    }
}

void update(uint nodei, uint lefti, uint righti) {
    if (lefti == righti) {
        arbint[nodei].mini = 31000;
        return ;
    }

    uint midi = (lefti + righti) / 2;

    if (arbint[2 * nodei + 1].mini < arbint[2 * nodei + 2].mini) {
        arbint[2 * nodei + 2].lower++;
        arbint[2 * nodei + 2].mini--;
        update(2 * nodei + 1, lefti, midi);
    } else {
        update(2 * nodei + 2, midi + 1, righti);
    }

    arbint[nodei].mini = arbint[2 * nodei + 1].mini;
    arbint[nodei].pos = arbint[2 * nodei + 1].pos;

    if (arbint[nodei].mini >= arbint[2 * nodei + 2].mini) {
        arbint[nodei].mini = arbint[2 * nodei + 2].mini;
        arbint[nodei].pos = arbint[2 * nodei + 2].pos;

    }
    arbint[nodei].mini -= arbint[nodei].lower;
}

int main() {
    freopen("schi.in", "r", stdin);
    freopen("schi.out", "w", stdout);

    uint n;
    scanf("%u", &n);
    for (uint i =0;i<n;i++){
        scanf("%u", &v[i]);
    }
    build(0, 0, n - 1);

    for (uint i = 0; i < n; i++) {
        printf("%u\n", arbint[0].pos + 1);
        update(0, 0, n - 1);
    }

    return 0;
}
