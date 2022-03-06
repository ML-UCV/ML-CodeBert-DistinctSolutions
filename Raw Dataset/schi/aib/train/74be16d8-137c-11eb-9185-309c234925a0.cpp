#include <bits/stdc++.h>
using namespace std;


int n,v[500005],AIB[500005],ans[500005];

void add(int pos, int val){
    for (;pos<=n;pos += pos & (-pos)) AIB[pos] += val;
}

int find(int val){
    int p = 1, st = 0;
    for (;p<=n;p<<=1);
    for (;p>=1;p>>=1){
        if (st + p <= n && AIB[st + p] < val){
            st += p;
            val -= AIB[st];
        }
    }
    return st + 1;
}

int main(){
    ios::sync_with_stdio(false);
    freopen("schi.in","r",stdin);
    freopen("schi.out","w",stdout);
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&v[i]), add(i,1);

    for (int i=n;i>=1;i--){
        int x = find(v[i]);
        ans[x] = i;
        add(x, -1);
    }

    for (int i=1;i<=n;i++) cout << ans[i] << '\n';
    return 0;
}
