#include <bits/stdc++.h>
using namespace std;



template <class T>

class closestPoints

{
private:

    std::vector<std::pair<T,T>>v;

    std::vector<std::pair<T,T>>xv,yv;

    long long distance(std::pair<T,T> &a, std::pair<T,T> &b)

    {

        return 1LL * (a.first - b.first) * (a.first - b.first) +

                1LL * (a.second - b.second) * (a.second - b.second);

    }

    long long minnn(T a, T b)

    {

        return ((a)<(b)?(a):(b));

    }

    long long divideEtImpera(int l, int r)

    {

        if (l >= r) return 2223372036854775807LL;

        if (r - l == 1)

        {

            if (yv[l] > yv[l + 1])

                swap(yv[l],yv[l+1]);

            return distance(xv[l], xv[l+1]);

        }

        int m = (l + r) / 2;

        long long bst = minnn(divideEtImpera(l,m-1),divideEtImpera(m,r));

        sort(yv.begin()+l,yv.begin()+r+1);

        int sz = 0;

        for (int i=l; i<=r; ++i)

            if (abs(yv[i].second - xv[m].first) <= bst)

                v[sz++] = yv[i];

        for (int i=0; i<sz-1; ++i)

            for (int j=i+1; j<sz && j - i < 10; ++j)

                bst = minnn(bst, distance(v[i],v[j]));

        return bst;

    }

public:

    closestPoints() {}

    closestPoints(unsigned int expectedMaximumN)

    {

        v.resize(expectedMaximumN);

        xv.resize(expectedMaximumN);

    }

    void addPoint(T a, T b)

    {

        xv.push_back(make_pair(a,b));

    }

    long long computeMinimumDistance()

    {

        sort(xv.begin(), xv.end());

        yv.clear();

        for (int i=0; i<xv.size(); ++i)

            yv.push_back(make_pair(xv[i].second, xv[i].first));

        v.resize(xv.size() + 1);

        return divideEtImpera(0,xv.size()-1);

    }





};



int main()

{

    freopen("cmap.in","r",stdin);

    freopen("cmap.out","w",stdout);

    int n, x, y;

    scanf("%d",&n);

    closestPoints<long long> cmap;

    for (int i=1; i<=n; ++i)

    {

        scanf("%d %d",&x,&y);

        cmap.addPoint((long long)x,(long long)y);

    }

    long long closestD = cmap.computeMinimumDistance();

    cout<<setprecision(10)<<fixed<<sqrt(closestD)<<'\n';

    return 0;

}
