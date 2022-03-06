#include <bits/stdc++.h>




using namespace std;



ifstream fin("inv.in");

ofstream fout("inv.out");



void debug_out() { cerr << '\n'; }

template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...);}
typedef pair<int,int> pii;

typedef long long int ll;

typedef long double ld;



const int DMAX = 1e5+10;

const int MOD = 9917;



struct nume{

    int node,ind;

};



vector <nume> vec;



int V[DMAX];

int tree[4*DMAX];



int n,cate;

ll ans;



inline bool operator<(nume x,nume y){

    return x.node<y.node;

}



void update(int node,int st,int dr,int pos);

int query(int node,int st,int dr,int pos);



int main(){

    ios_base::sync_with_stdio(false);

    cin.tie(0);



    int t,i,j,dif=0;

    int x;



    fin>>n;

    for(i=1;i<=n;i++){

        fin>>V[i];

        vec.push_back({V[i],i});

    }

    sort(vec.begin(),vec.end());

    int prec=-1e9;

    for(auto& it:vec){

        if(it.node == prec){

            V[it.ind]=dif;

            continue;

        }

        dif++;

        prec=it.node;

        V[it.ind]=dif;

    }

    for(i=n;i>=1;i--){

        if(V[i] > 1)

            ans+=query(1,1,n,V[i]-1);

        update(1,1,n,V[i]);

    }

    fout<<ans%MOD<<'\n';



    return 0;

}

void update(int node,int st,int dr,int pos){

    if(st == dr){

        tree[node]++;

        return;

    }

    int mij=(st+dr)/2;

    if(pos <= mij)

        update(2*node,st,mij,pos);

    else

        update(2*node+1,mij+1,dr,pos);

    tree[node]=tree[2*node]+tree[2*node+1];

}

int query(int node,int st,int dr,int pos){

    if(dr <= pos)

        return tree[node];

    int mij=(st+dr)/2;

    int ans=0;

    if(mij < pos){

        ans+=query(2*node,st,mij,pos);

        ans+=query(2*node+1,mij+1,dr,pos);

    }

    if(mij >= pos)

        ans+=query(2*node,st,mij,pos);

    return ans;

}
