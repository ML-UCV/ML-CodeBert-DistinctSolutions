#include <bits/stdc++.h>






using namespace std;

ifstream fin("cmap.in");

ofstream fout("cmap.out");

typedef long long ll;

typedef pair <ll, ll> pairINT;



ll n,lastX,dmin;

pairINT p[(int)(1e5+4)];

set <pairINT> sweep;



bool upd(int);

void pass(int);

ll dist(pairINT,pairINT);



int main(){

    fin>>n;

    for(int i=0;i<n;++i)

        fin>>p[i].first>>p[i].second;

    sort(p, p+n);

    sweep.insert({p[0].second, p[0].first});

    lastX=0;

    dmin=2e18;



    for(int i=1;i<n;++i){

        while(upd(i));

        sweep.insert({p[i].second, p[i].first});

        pass(i);

    }

    fout<<fixed<<setprecision(7)<<sqrt(1.0*dmin);

    return 0;

}

void pass(int k){

    ll sq=sqrt(1.0 * dmin);

    while(p[lastX].first < p[k].first - sq){

        sweep.erase({p[lastX].second, p[lastX].first});

        ++lastX;

    }

}

bool upd(int k){

    set <pairINT>::iterator it;

    bool ok=0;

    ll sq=sqrt(1.0 * dmin);

    ll temp = p[k].second - sq;

    it=sweep.lower_bound({temp, 0LL});



    while(it != sweep.end()){

        temp=dist(p[k], {it->second, it->first});

        if(dmin > temp){

            dmin=temp;

            sq=sqrt(1.0 * dmin);

            ok=1;

        }

        if(temp > dmin)

            break;

        ++it;

    }

    return ok;

}

ll dist(pairINT A,pairINT B){

    return (B.first - A.first) * (B.first - A.first) +

            (B.second - A.second) * (B.second - A.second);

}
