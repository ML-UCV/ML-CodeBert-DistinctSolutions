#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>


using namespace std;



ifstream in("cmap.in");

ofstream out("cmap.out");



struct pct{

    long double x,y;

    bool operator < (pct p1) const{

        return x<p1.x;

    }

};

int n;

vector<pct> PCT;



void read(){

    int x,y;

    in>>n;

    for(int i=1;i<=n;i++){

        in>>x>>y;

        PCT.push_back({x,y});

    }

}

inline long double dist(pct p1, pct p2){

    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));

}

void solve(){

    long double dmin=10000000000;

    sort(PCT.begin(),PCT.end());

    for(auto it1=PCT.begin();it1!=PCT.end();it1++){

        for(auto it2=it1+1;it2!=PCT.end();it2++){

            if((it2->x)-(it1->x)>dmin)

                break;

            dmin=min(dmin,dist(*it1,*it2));

        }

    }

    out<<setprecision(6)<<fixed<<dmin;

}

int main(){

    read();

    solve();

    return 0;

}
