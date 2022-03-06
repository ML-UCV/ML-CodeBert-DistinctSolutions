#include <bits/stdc++.h>


using namespace std;



template <typename T>

struct Compare {

    bool operator()(const pair<T,T>& a, const pair<T,T>&b){

        return a.second < b.second;

    }

};



template <typename T>

struct ClosestPoints{

    vector<pair <T, T> > P;

    set<pair <T, T>, Compare<T> > S;

    queue<typename set<pair <T, T>, Compare<T> >::iterator> Q;

    T h;

    pair<T, T> fi, se;



    void addPoint(T x, T y){

        P.emplace_back(x, y);

    }



    T dist(const pair<T,T>& a, const pair<T,T>& b){

        return sqrt((a.first - b.first)*(a.first - b.first) + (a.second - b.second)*(a.second - b.second));

    }



    T build(){

        sort(P.begin(), P.end());

        h = dist(P[0], P[1]);

        pair<T, T> tmp;

        for(auto it = P.begin(); it != P.end(); it++){

            while(Q.size() and Q.front()->first < it->first - h) {

                S.erase(Q.front());

                Q.pop();

            }

            tmp.first = it->first;

            tmp.second = it->second - h;

            auto low = S.lower_bound(tmp);

            tmp.second = it->second + h;

            auto upp = S.upper_bound(tmp);

            for( ; low != upp; low++)

                if(dist(*low, *it) < h){

                    h = dist(*low, *it);

                    fi = *low;

                    se = *it;

                }

            auto ret = S.emplace(*it);

            Q.push(ret.first);

        }

        return h;

    }

};



ClosestPoints<double> C;

ifstream f("cmap.in");

ofstream g("cmap.out");

int n;



int main()

{

    f>>n;

    double x, y;

    while(n--) {

        f >> x >> y;

        C.addPoint(x, y);

    }

    g<<setprecision(6)<<fixed<<C.build()<<"\n";

    return 0;

}
