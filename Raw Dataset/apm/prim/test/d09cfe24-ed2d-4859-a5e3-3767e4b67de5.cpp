#include <bits/stdc++.h>




using namespace std;



ifstream fin("apm.in");

ofstream fout("apm.out");



void debug_out() { cerr << '\n'; }

template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...);}
typedef pair<int,int> pii;

typedef long long int ll;

typedef long double ld;



const int DMAX = 2e5+10;



struct nume{

    int x,y,val;

};



vector <pii> vec;

priority_queue <nume> heap;



int tata[DMAX];



int n,m;

int ans;



inline bool operator<(nume x,nume y){

    return x.val>y.val;

}



int comp(int x);

void unire(int x,int y);



int main(){

    ios_base::sync_with_stdio(false);

    cin.tie(0);



    int t,i,j;

    int x,y,z;



    fin>>n>>m;

    for(i=1;i<=m;i++){

        fin>>x>>y>>z;

        heap.push({x,y,z});

    }

    for(i=1;i<n;){

        nume node=heap.top();

        heap.pop();

        if(comp(node.x) != comp(node.y)){

            i++;

            ans+=node.val;

            unire(node.x,node.y);

            vec.push_back({node.x,node.y});

        }

    }

    fout<<ans<<'\n';

    fout<<n-1<<'\n';

    for(auto& it:vec)

        fout<<it.first<<' '<<it.second<<'\n';



    return 0;

}

int comp(int x){

    int ans=x,aux;

    while(tata[ans])

        ans=tata[ans];

    while(tata[x]){

        aux=x;

        x=tata[x];

        tata[aux]=ans;

    }

    return ans;

}

void unire(int x,int y){

    x=comp(x);

    y=comp(y);

    tata[x]=y;

}
