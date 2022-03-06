#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <limits>
using namespace std;

long long INF = numeric_limits<long long>::max();
typedef pair<long long,long long> PLL;
typedef vector<PLL> VPLL;

int n;
VPLL x,y,tmp;



long long d2(PLL a, PLL b){
    long long df = a.first-b.first, ds = a.second - b.second;
    return df*df + ds*ds;
}




long long dmin(int st, int dr){
    if(st>=dr-1) return INF;
    else if(st==dr-2){
        if(y[st]>y[st+1]) y[st].swap(y[st+1]);
        return d2(x[st],x[st+1]);
    }
    else{

        int mid = (st+dr)/2;

        long long bst = min( dmin(st,mid), dmin(mid,dr) );

        merge(y.begin() + st, y.begin() + mid, y.begin() + mid, y.begin() + dr, tmp.begin());
        copy(tmp.begin(), tmp.begin() + (dr - st), y.begin() + st);

        int ind=0;

        for(int i=st; i<dr; ++i)
            if(abs(y[i].second - x[mid].first)<bst)
                tmp[ind++]=y[i];

        for(int i=0;i<ind-1;++i)
            for(int j=i+1; j<ind && j-i<8; ++j)
                bst = min(bst, d2(tmp[i],tmp[j]) );

        return bst;
    }
}




int main(){
    ifstream fin("cmap.in");
    ofstream fout("cmap.out");

    fin>>n;
    x.resize(n);
    y.resize(n);
    tmp.resize(n);


    for(auto &p : x) fin>>p.first>>p.second;
    sort(x.begin(),x.end());
    for(int i=0;i<n;++i){
        y[i].first = x[i].second;
        y[i].second = x[i].first;
    }

    fout<<fixed<<setprecision(8);
    fout<< sqrt( dmin(0,n) ) << '\n';
}
