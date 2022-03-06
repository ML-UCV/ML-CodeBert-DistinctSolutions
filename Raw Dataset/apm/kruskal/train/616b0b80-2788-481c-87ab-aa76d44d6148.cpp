#include <bits/stdc++.h>





using namespace std;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}







const int nax=1e5+10;

vector<pair<int,pair<int,int>>> edge;
vector<int> p(nax,-1);

int get_parent(int v){
    if(p[v]==-1)return v;
    return p[v]=get_parent(p[v]);
}

int main(){
    ifstream in("apm.in");
    ofstream out("apm.out");
    int n,m;
    in>>n>>m;
    int u,v,w;
    for(int i=0;i<m;i++){
        in>>u>>v>>w;
        u--,v--;
        edge.push_back(make_pair(w,make_pair(u,v)));
    }
    sort(edge.begin(),edge.end());
    int p1,p2;
    int c=0;
    vector<pair<int,int>> ans;
    for(int i=0;i<m;i++){
        u=edge[i].second.first;
        v=edge[i].second.second;
        w=edge[i].first;
        p1=get_parent(u);
        p2=get_parent(v);
        if(p1!=p2){
            p[p2]=p1;
            c+=w;
            ans.push_back(edge[i].second);
        }
    }
    out<<c<<"\n";
    out<<ans.size()<<"\n";
    for(auto x:ans)out<<x.first+1<<" "<<x.second+1<<"\n";
    return 0;
}
