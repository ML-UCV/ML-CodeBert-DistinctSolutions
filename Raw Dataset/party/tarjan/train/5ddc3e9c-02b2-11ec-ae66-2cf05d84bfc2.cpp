#include <iostream>
#include <cstdio>
#include <vector>


using namespace std;

struct rel
{
    int y, tip;
    rel(int _y, int _tip) : y(_y), tip(_tip) { }
};
int n, m;
vector<rel> graf[150];
int sol[150];

void citire()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i <= n; i++) sol[i] = -1;
    int x, y, tip;
    for (int i = 1; i <= m; i++) {
        scanf("%d %d %d", &x, &y, &tip);
        graf[x].push_back(rel(y, tip));
        if (tip == 0 || tip == 3)
            graf[y].push_back(rel(x, tip));
        else
            graf[y].push_back(rel(x, 3-tip));
    }
}

int undoState[150];

int expected(int val, int tip)
{
    if (tip == 0 && val == 1)
        return -1;
    if (tip == 0 && val == 0)
        return 1;
    if (tip == 1 && val == 1)
        return -1;
    if (tip == 1 && val == 0)
        return 0;
    if (tip == 2 && val == 1)
        return 1;
    if (tip == 2 && val == 0)
        return -1;
    if (tip == 3 && val == 1)
        return 0;
    if (tip == 3 && val == 0)
        return -1;
    cerr << "ERROR";
    return -1;
}


int setVal(int ind, int val)
{
    sol[ind] = val;
    int ok = 1;
    for (int i = 0, t = graf[ind].size(); i < t && ok; i++) {
        rel r = graf[ind][i];
        int exp = expected(val, r.tip);
        if (sol[r.y] == -1) {
            if (exp != -1)
                ok = setVal(r.y, exp);
        }
        else if (exp == -1 || exp == sol[r.y])
            continue;
        else
            ok = 0;
    }
    if (!ok) sol[ind] = -1;
    return ok;
}

void solve()
{
    for (int i = 1; i <= n; i++) {
        if (sol[i] == -1) {
            for (int i = 0; i <= n; i++)
                undoState[i] = sol[i];
            if (!setVal(i, 1)) {
                for (int i = 0; i <= n; i++)
                    sol[i] = undoState[i];
                setVal(i, 0);
            }
        }
    }
}

void afisare()
{
    int cate = 0;
    for (int i = 1; i <= n; i++)
        if (sol[i] == 1)
            cate++;
    printf("%d\n", cate);
    for (int i = 1; i <= n; i++)
        if (sol[i])
            printf("%d\n", i);
}

int main()
{
    freopen("party.in", "r", stdin);
    freopen("party.out", "w", stdout);

    citire();
    solve();
    afisare();

    return 0;
}
