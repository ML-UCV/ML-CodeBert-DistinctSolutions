#include <cstdio>
#include <deque>
#include <cstring>
using namespace std;
char s[50001], c[50001];

deque<int> list[256];


int perm[50001], w[50001];
int n, m, nr;

void merge(int v[], int l, int r){
    int m = (l + r) / 2, k = l - 1, i = 0, j = 0;
    for(i = l, j = m + 1; i <= m && j <= r;){
        if(v[i] <= v[j])
            w[++k] = v[i++];
        else{
            w[++k] = v[j++];
            nr += m - i + 1;
        }
    }
    for(; i <= m;)
        w[++k] = v[i++];
    for(; j <= r;)
        w[++k] = v[j++];
    for(i = l; i <= r; ++i)
        v[i] = w[i];
}
void sortare(int v[], int l, int r){
    if(l>=r)
    return;
    int m = (l + r) / 2;
    sortare(v, l, m);
    sortare(v, m + 1, r);
    merge(v, l, r);
}
void read(){
    freopen("swap.in", "r", stdin);
    scanf("%s %s", &s, &c);
    n = strlen(s);
    m = strlen(c);
}

int cnt[256];

void solve(){
    int i, j;
    for (i = 0; i < m ; ++i)
        cnt[ int(c[i]) ]++;

    for (i = 0; i < n; ++i)
        list[ int(s[i]) ].push_back(i + 1);

    for (i = 0; i < 256; ++i)
        if (cnt[i] != list[i].size()) {
            printf ("-1\n");
            return ;
        }

int nperm;


    for (i = 0; i < m; ++i) {
        perm[i + 1] = list[ int(c[i]) ][0];
        list[ int(c[i]) ].pop_front();
    }

    sortare(perm, 1, m);
    printf("%d\n",nr);
}
int main(){
    freopen("swap.out", "w", stdout);
    read();
    solve();
}
