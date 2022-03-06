#include <stdio.h>
#include <vector>
#include <string.h>


using namespace std;



int n, m, x, y, t;

vector<int> G[220], GT[220], v;

bool uz[220], sol[220];



inline int neg(int x) {

    return (x <= n)?(x + n):(x - n);

}



void DFSP(int u) {

    uz[u] = 1;

    for(auto x: G[u])

        if(!uz[x])

            DFSP(x);

    v.push_back(u);

}



void DFST(int p) {

    uz[p] = 1;

    sol[neg(p)] = 1;



    for(auto x: GT[p])

        if(!uz[x])

            DFST(x);

}



int main()

{

    freopen("party.in", "r", stdin);

    freopen("party.out", "w", stdout);



    scanf("%d %d", &n, &m);

    for(int i = 1; i <= m; i++) {

        scanf("%d %d %d", &x, &y, &t);

        switch(t) {

            case 0: x = neg(x); break;

            case 1: swap(x, y); break;

            case 3: y = neg(y);

        }

        G[x].push_back(y);

        G[neg(y)].push_back(neg(x));

        GT[y].push_back(x);

        GT[neg(x)].push_back(neg(y));

    }



    for(int i = 1; i <= 2 * n; i++)

        if(!uz[i])

            DFSP(i);



    memset(uz, 0, sizeof(uz));

    for(int i = v.size() - 1; i >= 0; i--) {

        if(!uz[v[i]] && !uz[neg(v[i])])

            DFST(v[i]);

    }



    int cnt = 0;

    for(int i = 1; i <= n; i++)

        cnt += sol[i];

    printf("%d\n", cnt);

    for(int i = 1; i <= n; i++)

        if(sol[i])

            printf("%d\n", i);



    return 0;

}
