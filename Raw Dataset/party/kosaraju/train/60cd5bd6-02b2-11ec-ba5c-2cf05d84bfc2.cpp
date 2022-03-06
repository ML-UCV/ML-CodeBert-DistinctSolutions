#include <fstream>


using namespace std;



ifstream in("party.in");

ofstream out("party.out");
int n, m, dublun;

int lst[2 * 101], vf[4 * 1001], urm[4 * 1001], nvf = 0;

bool intoarcere[4 * 1001];

bool ok1[2 * 101];

int st[2 * 101], nst = 0;

bool ok2[2 * 101];

bool sol[2 * 101];

int nsol = 0;



inline void dfs1(int x)

{

    ok1[x] = 1;

    for(int i = lst[x]; i; i = urm[i])

        if(!intoarcere[i] && !ok1[vf[i]])

            dfs1(vf[i]);

    st[++nst] = x;

}



inline void dfs2(int x)

{

    ok2[x] = 1;

    sol[dublun - x] = 1;

    if(dublun - x <= n)

        nsol++;

    for(int i = lst[x]; i; i = urm[i])

        if(intoarcere[i] && !ok2[vf[i]])

            dfs2(vf[i]);

}



inline void adaugaMuchie(int x, int y)

{

    vf[++nvf] = y;

    urm[nvf] = lst[x];

    lst[x] = nvf;

    vf[++nvf] = x;

    urm[nvf] = lst[y];

    intoarcere[nvf] = 1;

    lst[y] = nvf;

}



int main()

{

    in >> n >> m;

    dublun = 2 * n + 1;

    while(m--)

    {

        int x, y, op;

        in >> x >> y >> op;

        int notx = dublun - x, noty = dublun - y;

        if(op == 0)

        {

            adaugaMuchie(notx, y);

            adaugaMuchie(noty, x);

        }

        else if(op == 1)

        {

            adaugaMuchie(y, x);

            adaugaMuchie(notx, noty);

        }

        else if(op == 2)

        {

            adaugaMuchie(x, y);

            adaugaMuchie(noty, notx);

        }

        else

        {

            adaugaMuchie(x, noty);

            adaugaMuchie(y, notx);

        }

    }



    for(int i = 1; i < dublun; i++)

        if(!ok1[i])

            dfs1(i);



    for(int i = nst; i >= 1; i--)

        if(!ok2[st[i]] && !ok2[dublun - st[i]])

            dfs2(st[i]);



    out << nsol << '\n';

    for(int i = 1; i <= n; i++)

        if(sol[i])

            out << i << '\n';

    return 0;

}
