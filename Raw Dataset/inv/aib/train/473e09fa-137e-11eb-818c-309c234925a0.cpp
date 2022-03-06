#include <bits/stdc++.h>
using namespace std;

ifstream in("inv.in");

ofstream out("inv.out");



int bit[100009],v[100009],v1[100009];

int n;

int upt(int i,int add) {

    for(; i<=n; i+=(i&-i))

        bit[i]+=add;

}

int see(int i) {

    int ans=0;

    for(; i>0; i-=(i&-i))

        ans+=bit[i];

    return ans;

}

int main() {

    int i,c=0;

    in>>n;

    for(i=1; i<=n; i++)

        in>>v[i],v1[i]=v[i];

    sort(v1+1,v1+n+1);

    for(i=1; i<=n; i++)

        v[i]=lower_bound(v1,v1+n,v[i])-v1+1;

    for (i=n; i>=1; i--) {

        c+=see(v[i]-1);

        c%=9917;

        upt(v[i],1);

    }

    out<<c;

    return 0;

}
