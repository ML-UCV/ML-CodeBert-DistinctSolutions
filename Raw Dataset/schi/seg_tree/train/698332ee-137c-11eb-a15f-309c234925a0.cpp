#include <fstream>

using namespace std;

ifstream f("schi.in");
ofstream g("schi.out");

int arb[3000001], v[3000001], rasp[3000001], sol, n;

void update(int nod, int st, int dr, int index, int val) {
    if(st > dr)
        return;

    if(st == dr) {
        arb[nod] = val;
        return;
    }

    int mid = (st + dr) / 2;
    if(index <= mid)
        update(2*nod, st, mid, index, val);
    else
        update(2*nod+1, mid+1, dr, index, val);
    arb[nod] = arb[2*nod] + arb[2*nod+1];
}

void query(int nod, int st, int dr, int val)
{
    if (st == dr)
    {
        sol = st;
        return;
    }
    int mij = (st + dr)/2;
    if (arb[2 * nod] < val)
    { val = val - arb[2 * nod];
        query(2 * nod + 1, mij + 1, dr, val);

    }
    else
        query(2 * nod, st, mij, val);
}

int main() {
    f >> n;

    for(int i = 1; i <= n; i++) {
        f >> v[i];
        update(1, 1, n, i, 1);
    }

    for(int i = n; i > 0; i--) {
        sol = 0;
        query(1, 1, n, v[i]);
        rasp[sol] = i;
        update(1, 1, n, sol, 0);
    }

    for(int i = 1; i <= n; i++)
        g << rasp[i] << "\n";
    return 0;
}
