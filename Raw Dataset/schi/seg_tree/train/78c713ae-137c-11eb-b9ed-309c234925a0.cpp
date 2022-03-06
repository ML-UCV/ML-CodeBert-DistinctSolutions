#include <fstream>


using namespace std;



ifstream in("schi.in");

ofstream out("schi.out");



int n, i;

int cate[30001 << 2], rez[30001], v[30001];



inline void build(int nod, int st, int dr)

{

    if (st == dr)

    {

        cate[nod] = 1;

        return;

    }

    int mid = (st + dr) / 2;

    build(2 * nod, st, mid);

    build(2 * nod + 1, mid + 1, dr);

    cate[nod] = cate[2 * nod] + cate[2 * nod + 1];

}



inline void update(int nod, int st, int dr, int val)

{

    if (st == dr)

    {

        rez[st] = i;

        cate[nod] = 0;

        return;

    }

    int mid = (st + dr) / 2;

    if (cate[2 * nod] >= val)

        update(2 * nod, st, mid, val);

    else

        update(2 * nod + 1, mid + 1, dr, val - cate[2 * nod]);

    cate[nod] = cate[2 * nod] + cate[2 * nod + 1];

}



int main()

{

    in >> n;

    for (i = 1; i <= n; ++i)

        in >> v[i];

    build(1, 1, n);

    for (i = n; i >= 1; --i)

        update(1, 1, n, v[i]);

    for (i = 1; i <= n; ++i)

        out << rez[i] << '\n';

    return 0;

}
