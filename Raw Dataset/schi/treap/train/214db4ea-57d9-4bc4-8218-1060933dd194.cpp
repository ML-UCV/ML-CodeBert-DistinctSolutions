#include <bits/stdc++.h>
using namespace std;

mt19937 rnd(time(0));

typedef struct Treap * Arbore;
typedef pair <Arbore, Arbore> Paa;
Arbore NIL;

struct Treap
{
    int prio, val, g;
    Treap *st, *dr;

    void recalc()
    {
        g = 1 + st->g + dr->g;
    }
    Treap(int val) : prio(rnd()), val(val), g(1), st(NIL), dr(NIL) { }
    ~Treap()
    {
        if (st != NIL)
            delete st;
        if (dr != NIL)
            delete dr;
    }
};

Paa split(Arbore a, int size_st)
{
    if (a == NIL)
        return { NIL, NIL };

    if (a->st->g >= size_st) {
        Paa s = split(a->st, size_st);
        a->st = s.second;
        a->recalc();
        return { s.first, a };
    }

    Paa s = split(a->dr, size_st - a->st->g - 1);
    a->dr = s.first;
    a->recalc();
    return { a, s.second };
}

Arbore join(Arbore a, Arbore b)
{
    if (a == NIL)
        return b;
    if (b == NIL)
        return a;

    if (a->prio > b->prio) {
        a->dr = join(a->dr, b);
        a->recalc();
        return a;
    }

    b->st = join(a, b->st);
    b->recalc();
    return b;
}

Arbore insert(Arbore a, int where, int val)
{
    Paa s = split(a, where);
    return join(s.first, join(new Treap(val), s.second));
}

void dfs(Arbore a, vector <int> & v)
{
    if (a == NIL)
        return;
    dfs(a->st, v);
    v.push_back(a->val);
    dfs(a->dr, v);
}


int main()
{
    ifstream in("schi.in");
    ofstream out("schi.out");

    NIL = new Treap(0);
    NIL->g = 0;

    Arbore root = NIL;

    int n, poz;
    in >> n;

    for (int i = 1; i <= n; i++) {
        int poz;
        in >> poz;
        root = insert(root, poz - 1, i);
    }

    vector <int> ans;
    dfs(root, ans);

    for (auto i : ans)
        out << i << '\n';

    return 0;
}
