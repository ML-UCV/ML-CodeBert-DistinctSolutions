#include <fstream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iomanip>






using namespace std;



ifstream f("cmap.in");

ofstream g("cmap.out");



int n;

pair<int,int> P[100002];



bool comp(pair<int,int> a,pair<int,int> b){if (a.first==b.first) return a.second<b.second; return a.first<b.first;}

bool comp2(pair<int,int> a,pair<int,int> b){if (a.second==b.second) return a.first<b.first; return a.second<b.second;}





long double dist(pair<int,int> a,pair<int,int> b){

    return sqrt(1LL * (a.first-b.first) * (a.first-b.first) + 1LL * (a.second-b.second) * (a.second-b.second));

}



long double solve(int st,int dr){

    long double mn = 1e13;

    if (st==dr) return 1e13;

    if (st+1==dr) return dist(P[st],P[dr]);



    int mid = (st+dr)/2;

    mn = min(solve(st,mid),solve(mid+1,dr));



    vector<pair<int,int> > V;

    long double VMID = (P[mid].first+P[mid+1].first)/2;

    for(int i=mid;i>=st && abs(VMID-P[i].first)<=mn;i--) V.push_back(P[i]);

    for(int i=mid+1;i<=dr && abs(VMID-P[i].first)<=mn;i++) V.push_back(P[i]);



    sort(V.begin(),V.end(),comp2);



    for (int i=0;i<V.size();i++)

        for (int j=i+1;j<=i+4 && j<V.size();j++)

            mn = min(mn,dist(V[i],V[j]));



    return mn;

}



int main()

{

    f>>n;

    for (int i=1;i<=n;i++) f>>P[i].first>>P[i].second;

    sort(P+1,P+n+1,comp);



    g<<fixed<<setprecision(12)<<solve(1,n);



    return 0;

}
