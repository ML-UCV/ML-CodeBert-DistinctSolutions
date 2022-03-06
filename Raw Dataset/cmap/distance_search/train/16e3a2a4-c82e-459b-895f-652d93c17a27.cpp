#include <bits/stdc++.h>


using namespace std;







typedef pair<int, int> pii;

typedef long double LD;



struct cmpr

{

    bool operator() (const pii &A, const pii &B) const

    {

        if(A.second == B.second) return A.first < B.first;

        return A.second < B.second;

    }

};



LD D;

int N;

vector<pii> p;

set<pii, cmpr> st;



LD dist(int x, int y, int xx, int yy)

{

    LD d = (LD)(x - xx) * (x - xx) + (LD)(y - yy) * (y - yy);

    return sqrt(d);

}



int main()

{



    freopen("cmap.in", "r", stdin);

    freopen("cmap.out", "w", stdout);





    scanf("%d", &N);

    for(int i = 1; i <= N; i++)

    {

        int x, y;

        scanf("%d%d", &x, &y);

        p.push_back({x, y});

    }



    sort(begin(p), end(p));



    D = 2e9;

    int j = 0;

    for(int i = 0; i < p.size(); i++)

    {

        int x = p[i].first, y = p[i].second;

        while(j < i)

        {

            if(x - p[j].first > D) st.erase(p[j]);

            j++;

        }



        int d = ceil(D);

        auto it1 = st.lower_bound({x - d, y - d});

        auto it2 = st.upper_bound({x, y + d});



        if(it1 != st.end() && !st.empty())

        {

            for(auto it = it1; it != it2; it++)

            {

                LD dd = dist(x, y, (*it).first, (*it).second);

                D = min(D, dd);

            }

        }



        st.insert(p[i]);

    }



    cout << fixed << setprecision(10) << D;



    return 0;

}
