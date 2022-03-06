#include <fstream>


using namespace std;



ifstream cin("ctc.in");

ofstream cout("ctc.out");



const int N = 100001, M = 200001;



int vf[M], urm[M], lst[N], viz[N], st[N], vf1[M], urm1[M], lst1[N], viz1[N], st1[N], nrst1, nrst, nr, nr1, c;



void adauga(int x, int y)

{

    vf[++nr] = y;

    urm[nr] = lst[x];

    lst[x] = nr;

}



void adauga1(int x, int y)

{

    vf1[++nr1] = y;

    urm1[nr1] = lst1[x];

    lst1[x] = nr1;

}



void dfs(int x)

{

    viz[x] = true;

    for(int p = lst[x]; p != 0; p = urm[p])

        {

            int y = vf[p];

            if(!viz[y])

                dfs(y);

        }

    st[++nrst] = x;

}



void dfs1(int x)

{

    viz1[x] = true;

    for(int p = lst1[x]; p != 0; p = urm1[p])

        {

            int y = vf1[p];

            if(!viz1[y])

                dfs1(y);

        }

}



void dfs2(int x)

{

    viz1[x] = true;



    for(int p = lst1[x]; p != 0; p = urm1[p])

        {

            int y = vf1[p];

            if(!viz1[y])

                cout << y << " ", dfs2(y);

        }

}



int main()

{

    int n, m, x, y;

    cin >> n >> m;

    for(int i = 1; i <= m; i++)

    {

        cin >> x >> y;

        adauga(x, y);

        adauga1(y, x);

    }

    for(int i = 1; i <= n; i++)

    {

        if(!viz[i])

            dfs(i);

    }



    for(int i = nrst; i >= 1; i--)

    {

        if(!viz1[st[i]])

            c++, dfs1(st[i]);

    }

    cout << c << "\n";

    for(int i = 1; i <= nrst; i++)

        viz1[st[i]] = false;

    for(int i = nrst; i >= 1; i--)

    {

        if(!viz1[st[i]])

            {

            cout << st[i] << " ";

            dfs2(st[i]);

            cout << "\n";

            }

    }

    return 0;

}
