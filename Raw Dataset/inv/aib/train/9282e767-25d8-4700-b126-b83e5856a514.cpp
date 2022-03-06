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







struct fenwick_tree{
    vector<int> tr;
    int n;
    void build(vector<int> &arr){
        for(int i=1;i<=n;i++){
            tr[i]+=arr[i-1];
            if(i+(i&-i)<=n){
                tr[i+(i&-i)]+=tr[i];
            }
        }

    }
    void update(int pos,int val){
        while(pos<=n){
            tr[pos]+=val;
            pos=pos+(pos&-pos);
        }

    }
    int query(int l,int r){
        int s1=0;
        while(l>0){
            s1+=tr[l];
            l=l-(l&-l);
        }
        int s2=0;
        while(r>0){
            s2+=tr[r];
            r=r-(r&-r);
        }

        return s2-s1;
    }
};

int main(){
    ifstream in("inv.in");
    ofstream out("inv.out");
    int n;
    in>>n;
    vector<int> a(n);
    for(auto &x:a)in>>x;
    int mod=9917;
    int ans=0;
    auto temp=a;
    temp.push_back((int)-1e9);
    sort(temp.begin(),temp.end());
    temp.erase(unique(temp.begin(),temp.end()),temp.end());
    for(int i=0;i<n;i++){
        a[i]=lower_bound(temp.begin(),temp.end(),a[i])-temp.begin();
    }
    fenwick_tree ft;
    ft.tr.resize((int)temp.size()+1);
    ft.n=(int)temp.size()+1;
    for(int i=n-1;i>=0;i--){
        ans=ans+ft.query(0,a[i]-1);
        ft.update(a[i],1);
        ans%=mod;
    }
    out<<ans<<"\n";
    return 0;
}
