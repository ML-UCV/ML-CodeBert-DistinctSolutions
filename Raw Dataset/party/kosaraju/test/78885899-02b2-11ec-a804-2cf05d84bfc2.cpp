#include <cstdio>
#include <vector>
using namespace std;

const int N = 205;

int v[N], n, m, post[N], nr, value[N], ok;

vector<int> a[N], at[N];



inline int neg(int a){

    if(a > n)

        return a - n;

    return a + n;

}



void dfs(int k) {

    int i;

    v[k] = 1;

    for(i = 0 ; i < a[k].size(); ++i)

        if(!v[a[k][i]])

            dfs(a[k][i]);

     post[++nr] = k;

}



void dfst(int k) {

    int i;

    v[k] = 0;



    if(value[k])

        ok = 0;

    value[k] = 0; value[neg(k)] = 1;

    for(i = 0; i < at[k].size(); ++i)

        if(v[at[k][i]])

            dfst(at[k][i]);

}



int main() {

    freopen("party.in", "r", stdin);

    freopen("party.out", "w", stdout);

    int i, x, y, op;

    scanf("%d %d", &n, &m);

    for(i = 1; i <= m; ++i){

        scanf("%d %d %d", &x, &y, &op);

        if(op == 0){

            a[neg(x)].push_back(y);

            a[neg(y)].push_back(x);

            at[y].push_back(neg(x));

            at[x].push_back(neg(y));

        }



        if(op == 2) {

            a[x].push_back(y);

            at[y].push_back(x);

            a[neg(y)].push_back(neg(x));

            at[neg(x)].push_back(neg(y));

        }



        if(op == 1) {

            a[neg(x)].push_back(neg(y));

            at[neg(y)].push_back(neg(x));

            a[y].push_back(x);

            at[x].push_back(y);

        }



        if(op == 3) {

            a[x].push_back(neg(y));

            at[neg(y)].push_back(x);

            a[y].push_back(neg(x));

            at[neg(x)].push_back(y);

        }

    }



    for(i = 1; i <=2 * n; ++i)

        if(!v[i])

            dfs(i);





    ok = 1;

    for(i = nr; i >= 1; --i)

        if(v[post[i]] && v[neg(post[i])])

            dfst(post[i]);

    nr = 0;

    if(ok)

        for(i = 1; i <= n; ++i)

            if(value[i])

                post[++nr] = i;

    printf("%d\n", nr);

    for(i = 1; i <= nr; ++i)

        printf("%d\n", post[i]);

    return 0;

}
