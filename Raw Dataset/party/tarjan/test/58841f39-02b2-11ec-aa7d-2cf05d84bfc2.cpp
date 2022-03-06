#include <bits/stdc++.h>
using namespace std;



int n, m, k, nr, NR;

int st[2005], val[2005], d[2005], id[2005];

int r[2005];

bool f[2005];

vector <int> v[2005];

vector <int> ctc[2005];

inline int neg(int x){

    if(x > 0) return x + n;

    else return abs(x);

}

inline int ret(int x){

    if(x <= n) return x;

    else return x - n;

}

inline void dfs(int nod){

    st[++NR] = nod;

    f[nod] = 1;

    d[nod] = id[nod] = ++k;

    for(auto it : v[nod]){

        if(d[it] == 0){

            dfs(it);

            d[nod] = min(d[nod], d[it]);

        }

        else if(f[it]) d[nod] = min(d[nod], d[it]);

    }

    if(d[nod] == id[nod]){

        ++nr;

        while(st[NR] != nod){

            int x = st[NR--];

            f[x] = 0;

            ctc[nr].push_back(x);

        }

        int x = st[NR--];

        f[x] = 0;

        ctc[nr].push_back(x);

    }

}

int main()

{

    freopen("party.in", "r", stdin);

    freopen("party.out", "w", stdout);

    scanf("%d%d", &n, &m);

    int x, y, nx, ny, t;

    for(int i = 1; i <= m ; ++i){

        scanf("%d%d%d", &x, &y, &t);

        if(t == 1) y = -y;

        else if(t == 2) x = -x;

        else if(t == 3) x = -x, y = -y;

        nx = -x; ny = -y;

        x = neg(x); ny = neg(ny);

        nx = neg(nx); y = neg(y);

        v[nx].push_back(y);

        v[ny].push_back(x);

    }

    for(int i = 1; i <= n * 2 ; ++i){

        if(d[i]) continue ;

        NR = 0; dfs(i);

    }

    for(int i = 1; i <= n ; ++i) val[i] = -1;

    bool ok = 1;

    int sol = 0;

    for(int i = nr; i >= 1 ; --i){

        for(auto it : ctc[i]){

            int x = it;

            x = ret(it);

            r[x] = i;

            if(val[x] != -1) continue ;

            if(it <= n) val[x] = 1, ++sol;

            else val[x] = 0;

        }

    }

    printf("%d\n", sol);

    for(int i = 1; i <= n ; ++i)

        if(val[i]) printf("%d\n", i);

    return 0;

}
