#include <bits/stdc++.h>




using namespace std;



ifstream fin("schi.in");

ofstream fout("schi.out");



void debug_out() { cerr << '\n'; }

template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...);}
typedef pair<int,int> pii;

typedef long long int ll;

typedef long double ld;



const int DMAX = 3e4+10;



int V[DMAX];

int ans[DMAX];

int tree[4*DMAX];



int n;



void build(int node,int st,int dr);

void query(int node,int st,int dr,int val,int x);



int main(){

    ios_base::sync_with_stdio(false);

    cin.tie(0);



    int t,i,j;



    fin>>n;

    for(i=1;i<=n;i++)

        fin>>V[i];

    build(1,1,n);

    for(i=n;i>=1;i--)

        query(1,1,n,V[i],i);



    for(i=1;i<=n;i++)

        fout<<ans[i]<<'\n';



    return 0;

}

void build(int node,int st,int dr){

    if(st == dr){

        tree[node]=1;

        return;

    }

    int mij=(st+dr)/2;

    build(2*node,st,mij);

    build(2*node+1,mij+1,dr);

    tree[node]=tree[2*node]+tree[2*node+1];

}

void query(int node,int st,int dr,int val,int x){

    if(st == dr){

        tree[node]=0;

        ans[st]=x;

        return;

    }

    int mij=(st+dr)/2;

    if(val <= tree[2*node])

        query(2*node,st,mij,val,x);

    else

        query(2*node+1,mij+1,dr,val-tree[2*node],x);

    tree[node]=tree[2*node]+tree[2*node+1];

}
