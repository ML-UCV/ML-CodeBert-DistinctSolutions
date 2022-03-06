#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>


using namespace std;



ifstream f("apm.in");

ofstream g("apm.out");



const int maxn = 2e5+5, maxm = 4e5+5;



struct muchie {

    int x, y, cost;

};

muchie mc[maxm], mcans[maxn];



int n, m, x, y, cost, ans, k;



vector <int> nod[maxn];



int cmp(muchie a, muchie b) {

    return a.cost < b.cost;

}



int tt[maxn];



int rad(int x) {

    int r, y;

    for(r = x; tt[r] != r; r = tt[r]);

    while(tt[x] != x) {

        y = tt[x];

        tt[x] = r;

        x = y;

    }

    return r;

}



void unite(int x, int y) {

    tt[y] = x;

}



int main()

{

    int i;

    f >> n >> m;

    for(i = 1; i <= n; i ++) {

        tt[i] = i;

    }

    for(i = 1; i <= m; i ++) {

        f >> x >> y >> cost;

        nod[x].push_back(y);

        nod[y].push_back(x);

        mc[i] = {x, y, cost};

    }

    sort(mc + 1, mc + m + 1, cmp);



    for(i = 1; i <= m; i ++) {

        x = mc[i].x;

        y = mc[i].y;

        cost = mc[i].cost;

        if((rad(x) != rad(y))) {

            unite(rad(x), rad(y));

            ans += cost;

            mcans[++k] = {x, y, 0};

        }

    }



    g << ans << '\n';

    g << k << '\n';

    for(i = 1; i <= k; i ++) {

        g << mcans[i].x << ' ' << mcans[i].y << '\n';

    }



    f.close();

    g.close();

    return 0;

}
