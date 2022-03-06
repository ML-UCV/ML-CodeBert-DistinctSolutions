#include <bits/stdc++.h>






using namespace std;

ifstream fin("inv.in");

ofstream fout("inv.out");



long long n, q, x;

unsigned long long r;

pair<long long, long long> v[100005];

long long stree[400050];



long long query(long long x, long long y, long long st, long long dr, long long node)

{

    if(y<x) return 0;

    if(x<=st && y>=dr) return stree[node];

    long long mid = (st+dr)/2, s1=0, s2=0;

    if(x<=mid) s1 = query(x, y, st, mid, node*2);

    if(y>mid) s2 = query(x, y, mid+1, dr, node*2+1);

    return s1+s2;

}





void update(long long pos, long long st, long long dr, long long node)

{

    if(st==dr)

        stree[node]=1;

    else{

        long long mid = (st+dr)/2;

        if(pos<=mid) update(pos, st, mid, node*2);

        else update(pos, mid+1, dr, node*2+1);

        stree[node] = stree[node*2]+stree[node*2+1];

    }

}



int main()

{

    fin>>n;

        r = 0;

        for(long long i=1; i<=n; i++)

        {

            fin>>v[i].first;

            v[i].second = i;

        }

        sort(v+1, v+n+1);



        for(long long i=1; i<=n; i++)

        {

            r+=query(v[i].second+1, n, 1, n, 1);

            r=r%9917;



            update(v[i].second, 1, n, 1);

        }

        fout<<r<<'\n';

    return 0;

}
