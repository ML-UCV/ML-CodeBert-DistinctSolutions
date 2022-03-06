#include <bits/stdc++.h>
using namespace std;

ifstream in("schi.in");

ofstream out("schi.out");



int bit[30000],v[30000],v2[30000];

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

int bs(int k) {

    int l=0,h=n;

    while(l<h) {

        int mid =(l+h)/2;

        if (k<=see(mid))

            h=mid;

        else

            l=mid+1;

    }

    return l;

}

int main() {

    int i,j,r,ans;

    in>>n;

    for(i=1; i<=n; i++)

        in>>v[i],upt(i,1);

    for(i=n; i>=1; i--) {

        ans=bs(v[i]);

        upt(ans,-1);

        v2[ans]=i;

    }

    for(i=1; i<=n; i++)

        out<<v2[i]<<'\n';

    return 0;

}
