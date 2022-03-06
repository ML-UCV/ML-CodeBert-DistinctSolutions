#include <iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;



ifstream fin("apm.in");

ofstream fout("apm.out");



const int N_MAX = 2e5 + 5;

struct ura {

    int x, y, c;

    bool operator<(const ura &other)const {

        return c<other.c;

    };

};

int n, m;



int t[N_MAX], p[N_MAX];



vector<ura>v, r;



int tata(int nodd) {

    if(nodd==t[nodd])

        return nodd;

    return t[nodd]=tata(t[nodd]);

}



void tacpac(int x, int y) {

    x=tata(x);

    y=tata(y);

    if(p[x]==p[y]) {

        p[x]++;

        t[y]=x;

    }

    else

        if(p[x]>p[y])

            t[y]=x;

        else

            t[x]=y;

}

int main() {

    fin>>n>>m;

    for(int i=1; i<=n; i++) {

        t[i]=i;

    }

    for(int i=1; i<=m; i++) {

        int x, y, c;

        fin>>x>>y>>c;

        v.push_back({x, y, c});

    }



    sort(v.begin(), v.end());

     long long coost=0;

    for(auto it : v) {

        if(tata(it.x)!=tata(it.y)) {

            tacpac(it.x, it.y);

            coost+=it.c;

            r.push_back(it);

        }

    }

    fout<<coost<<"\n"<<n-1<<"\n";

    for(auto it : r) {

        fout<<it.x<<" "<<it.y<<"\n";

    }

    return 0;

}
