#include <fstream>
#include <algorithm>


using namespace std;

ifstream f("inv.in");

ofstream g("inv.out");

int i, n, m, k, x[100001], aint[300001], s, a, b, pos;

struct meme{

    int value, pos;

}v[100001];

int cmp(meme a, meme b){

    return a.value < b.value;

}

void update(int node, int st, int dr){

    if(st == dr){

        aint[node] = (aint[node] + 1) % 9917;

        return;

    }

    int mid = (st + dr) / 2;

    if(mid < pos)

        update(2 * node + 1, mid + 1, dr);

    else

        update(2 * node, st, mid);

    aint[node] = (aint[node] + 1) % 9917;

}

void quary(int node, int st, int dr){

    if(st >= a && dr <= b){

        s = (s + aint[node]) % 9917;

        return;

    }

    int mid = (st + dr) / 2;

    if(mid + 1 <= b)

        quary(2 * node + 1, mid + 1, dr);

    if(mid >= a)

        quary(2 * node, st, mid);

}

int main()

{ f >> n;

    for(i = 1; i <= n; i++){

        f >> v[i].value;

        v[i].pos = i;

    }

    sort(v + 1, v + n + 1, cmp);

    k = 1;

    x[v[1].pos] = 1;

    for(i = 2; i <= n; i++){

        if(v[i].value != v[i - 1].value)

            k++;

        x[v[i].pos] = k;

    }

    b = k;

    for(i = 1; i <= n; i++){

        if(x[i] + 1 <= n){

            a = x[i] + 1;

            quary(1, 1, k);

        }

        pos = x[i];

        update(1, 1, k);

    }

    g << s;

    return 0;

}
