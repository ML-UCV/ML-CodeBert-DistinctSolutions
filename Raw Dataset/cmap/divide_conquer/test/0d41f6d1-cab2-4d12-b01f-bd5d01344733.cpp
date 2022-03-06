#include <bits/stdc++.h>


using namespace std;



    ifstream fin("cmap.in");

    ofstream fout("cmap.out");



vector <pair<long long,long long> > v, w, rez, aux;

const int INF = 4e18;



long long get_dist(pair<long long, long long> a, pair<long long, long long> b)

{

    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);

}



long long rezolva(int st, int dr)

{

    if (st == dr)

        return INF;

    else if (dr - st == 1)

        return get_dist(v[st], v[dr]);



    int mid = (st+dr)/2;



    long long sol = min(rezolva(st, mid), rezolva(mid, dr));



    rez.clear();

    rez.resize(dr + 1 - st + 1);

    aux.clear();

    merge(w.begin() + st, w.begin() + mid, w.begin() + mid, w.begin() + dr + 1, rez.begin());



    vector <pair<long long , long long> > ::iterator it;



    for (it = rez.begin(); it != rez.end(); ++it)

    {

        if (abs(it->second - v[mid].first) <= sol)

            aux.push_back(make_pair(it->second, it->first));

    }



    for (int i = 0; i < aux.size(); ++i)

        for (int j = i + 1; j < aux.size() && j - i < 8; ++j) {

            sol = min(sol, get_dist(aux[i], aux[j]));

        }



    return sol;

}



int main()

{

    int x,y,n;



    fin>>n;



    for(int i = 0; i < n; i++)

    {

        fin>>x>>y;

        v.push_back(make_pair(x,y));

        w.push_back(make_pair(y,x));

    }



    sort(v.begin(),v.end());

    w.push_back(make_pair(INF,INF));

    sort(w.begin(),w.end());



    fout<<fixed<<setprecision(6)<<sqrt(rezolva(0,v.size()-1));

}
