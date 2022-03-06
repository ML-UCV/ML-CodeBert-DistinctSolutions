#include <fstream>
#include <vector>
#include <cstring>
#include <queue>


using namespace std;



ifstream cin ("swap.in");

ofstream cout ("swap.out");
vector< queue<int> > x;

vector<int> arb;



char a[50001];

int n, nr[50001], rez;



void createarb(int node, int st, int dr)

{

    if (st == dr)

    {

        arb[node] = 1;

        return;

    }



    int mijl = (st + dr) / 2;

    createarb(2 * node, st, mijl);

    createarb(2 * node + 1, mijl + 1, dr);

    arb[node] = arb[2 * node] + arb[2 * node + 1];

}



void setpos(int node,int st, int dr, int pos)

{

    if (st == dr)

    {

        arb[node] = 0;

        return;

    }



    int mijl = (st + dr) /2;

    if (pos <= mijl)setpos(2 * node, st, mijl, pos);

    else setpos(2 * node + 1, mijl + 1, dr, pos);

    arb[node] = arb[2 * node] + arb[2 * node + 1];

}

int query(int node,int st, int dr, int L, int R)

{

    if (L <= st && dr <= R) return arb[node];



    int mijl = (st + dr) / 2, s = 0;

    if (L <= mijl)s += query(2 * node, st, mijl, L, R);

    if (R > mijl) s += query(2 * node + 1, mijl + 1, dr, L, R);

    return s;

}

int main()

{

    cin >> a;

    n = strlen(a);



    x = vector< queue<int> >(31);



    for (int i = 0; i < n; ++ i)

        x[a[i] - 'a'].push(i);



    cin >> a;

    n = strlen(a);

    for (int i = 0; i < n; ++ i)

        nr[a[i] - 'a'] ++;



    for (int i = 0; i < 31; ++ i)

        if (nr[i] != x[i].size())

        {

            cout << -1;

            return 0;

        }



    arb = vector<int>(4 * n + 1);



    createarb(1, 1, n);

    for (int i = 0, pos; i < n; ++ i)

    {

        pos = x[a[i] - 'a'].front() + 1;

        x[a[i] - 'a'].pop();

        setpos(1, 1, n, pos);

        rez += query(1, 1, n, 1, pos);

    }



    cout << rez;

    return 0;

}
