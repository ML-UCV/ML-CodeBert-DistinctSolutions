#include <bits/stdc++.h>






using namespace std;

int n, x, y;

vector<pair<int,int>>xs, ys;

vector<pair<int,int>>v(100005);

long long distance(pair<int,int> &a, pair<int,int> &b)

{

    return 1LL*(a.first - b.first)*(a.first - b.first) + 1LL*(a.second - b.second)*(a.second - b.second);

}

long long minn(long long a, long long b)

{

    if (a < b) return a;

    return b;

}

long long di(int st, int dr)

{

    if (st >= dr)

        return 9223372036854775806LL;

    if (dr - st == 1)

    {

        if (ys[st] > ys[st+1])

            swap(ys[st],ys[st+1]);

        return distance(xs[st], xs[st+1]);

    }

    int m = (st + dr)/2;

    long long bst = minn(di(st, m-1),di(m,dr));

    sort(ys.begin() + st, ys.begin() + dr + 1);



    int sz = 0;

    for (int i=st;i<=dr;++i)

        if (abs(ys[i].second-xs[m].first)<=bst)

            v[sz++] = ys[i];

    for (int i=0;i<sz-1;++i)

        for (int j=i+1;j<sz && j - i < 8;++j)

            bst = minn(bst, distance(v[i],v[j]));

    return bst;

}



int main()

{

    freopen("cmap.in","r",stdin);

    freopen("cmap.out","w",stdout);

    scanf("%d",&n);

    xs.reserve(n);

    ys.reserve(n);

    for (int i=1;i<=n;++i)

    {

        scanf("%d %d",&x,&y);

        xs.push_back(make_pair(x,y));

    }

    sort(xs.begin(), xs.end());

    for (int i=0;i<xs.size();++i)

        ys.push_back(make_pair(xs[i].second, xs[i].first));

    long long ans = di(0,n-1);

    cout<<setprecision(6)<<fixed<<sqrt(ans)<<'\n';

    fclose(stdin);

    fclose(stdout);

    return 0;

}
