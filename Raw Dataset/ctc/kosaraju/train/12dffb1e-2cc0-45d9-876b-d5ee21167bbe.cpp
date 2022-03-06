#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;



ifstream f("ctc.in");

ofstream g("ctc.out");



int n, m;

vector <int> v[100005], in[100005];

vector <int> sol[100005];

bool u1[100005], u2[100005];

int st[100005], top, ctc;



void dfs1(int x)

{

    u1[x]=1;

    for (auto y:v[x])

    {

        if (u1[y] == 1) continue;

        dfs1(y);

    }

    st[++top]=x;

}



void dfs2(int x)

{

    u2[x]=1;

    for (auto y:in[x])

    {

        if (u2[y] == 1) continue;

        dfs2(y);

    }

    sol[ctc].push_back(x);

}



int main()

{

    f >> n >> m;

    for (int i = 1, x, y; i <= m; i++)

    {

        f >> x >> y;

        v[x].push_back(y);

        in[y].push_back(x);

    }



    for (int i = 1; i <= n; i++)

        if (u1[i] == 0) dfs1(i);





    while (top > 0)

    {

        if (u2[st[top]] == 1) top--;

        else

        {

            dfs2(st[top]);

            top--;

            ctc++;

        }

    }



    g << ctc << '\n';

    for (int i = 0; i < ctc; i++)

    {

        for (auto y:sol[i])

            g << y << ' ';

        g << '\n';

    }





    return 0;

}
