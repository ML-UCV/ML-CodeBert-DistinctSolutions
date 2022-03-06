#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
#include <cstdio>





using namespace std;


typedef pair<long long,long long> punct;
vector<punct> v,vnou;
long long n;
bool cmpy(punct a, punct b){ return a.second > b.second; }
bool cmpx(punct a, punct b){ return a.first > b.first; }
long long dist(punct a, punct b){ return (long long)(a.first-b.first)*(a.first-b.first) + 0LL + (a.second-b.second)*(a.second-b.second); }

long long divide(long long st, long long dr){
    long long m = (st+dr)/2;
    long long n = dr-st+1;
    if(n == 1) return 10000000000000;
    else if( n==2) return dist(v[st],v[dr]);
    else {
        long long dmin = min(divide(st,m), divide(m,dr));
        long long mij = (v[st].second + v[dr].second)/2;
        vnou.clear();
        for(long long i = st; i<=dr; i++){
            if(mij - dmin <= v[i].second || mij + dmin >= v[i].second ){
                vnou.push_back(v[i]);
            }
        }
        sort(vnou.begin(), vnou.end(), cmpx);
        long long dmin_banda = 10000000000000;
        if(!vnou.empty()) {
            for (long long j = 0; j < vnou.size() - 1; ++j) {
                for (long long k = j + 1; k < min((long long) vnou.size(), j + 8); k++) {
                    dmin_banda = min(dmin_banda, dist(vnou[j], vnou[k]));
                }
            }
        }
        return min(dmin,dmin_banda);

    }
}

int main(){
    FILE *f, *g;
    f = fopen("cmap.in","r");
    g = fopen("cmap.out","w");
    fscanf(f,"%lld", &n);
    v.resize(n);
    for(long long i=0;i<n;++i)
        fscanf(f,"%lld%lld",&v[i].first,&v[i].second);
    sort(v.begin(),v.end(),cmpy);

    long double k = sqrtl(divide(0,n-1));
    fprintf(g,"%Lf", k);
    return 0;
}
