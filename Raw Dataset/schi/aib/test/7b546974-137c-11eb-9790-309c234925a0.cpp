#include <iostream>
#include <fstream>
#include <cstdio>


using namespace std;



ifstream f("schi.in");

ofstream g("schi.out");



int n, x, a[30001], v[30001], s[30001];



void arb(int p)

{

    for (int i = p; i <= n; i += (i & (-i)))

        a[i] --;

}



int sum(int p)

{

    int y = 0;

    for (int i = p; i > 0; i -= (i & (-i)))

        y += a[i];

    return y;

}



int ctb(int x)

{

    int st = 1, dr = n, mij = 0, ss = 0, mini = 30010;

    while (st <= dr)

    {

        mij = (st + dr) / 2;

        ss = sum(mij);

        if (ss == x && mij < mini) mini = mij;

            else if (ss >= x) dr = mij - 1;

            else st = mij + 1;

    }

    return mini;

}



int main()

{

    freopen("schi.in","r",stdin);

 freopen("schi.out","w",stdout);

    scanf("%d",&n);

    for (int i = 1; i <= n; i ++)

        scanf("%d",&v[i]);

    for (int i = 1; i <= n; i ++)

        a[i] = i & (-i);



    for (int i = n; i >= 1; i --)

    {

        x = ctb(v[i]);

        s[x] = i;

        arb(x);

    }



    for (int i = 1; i <= n; i ++)

         printf("%d\n",s[i]);

}
