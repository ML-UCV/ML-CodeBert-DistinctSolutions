#include <bits/stdc++.h>
using namespace std;
typedef pair <int,int> pii;



const int N = 100010;
int n, bit[N], ans;
pii a[N];

void update(int idx){
    for (;idx <= n; idx += (idx & -idx))
        bit[idx]++;
}

int query(int idx){
    int rs = 0;
    for(;idx;idx -= (idx & -idx))
        rs += bit[idx];
    return rs;
}

int main(){
    freopen("inv.in", "r", stdin);
    freopen("inv.out", "w", stdout);
    scanf("%d", &n);
    for (int i=1; i<=n; i++) scanf("%d", &a[i].first), a[i].second = i;
    sort(a+1, a+1+n);
    for(int i=1; i<=n; i++){
        update(a[i].second);
        ans = (ans + query(n) - query(a[i].second))%9917;
    }
    printf("%d", ans);
    return 0;
}
