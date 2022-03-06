#include <bits/stdc++.h>




using namespace std;



ifstream fin("party.in");

ofstream fout("party.out");



void debug_out() { cerr << '\n'; }

template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...);}
typedef pair<int,int> pii;

typedef long long int ll;

typedef long double ld;



const int DMAX = 1e5+10;



class _2sat{

    private:

        int n;

        vector <vector<int>> V,gV;

        vector <bool> uz;

        vector <int> ord,comp;

        vector <bool> ans;



        void dfs1(int node){

            uz[node]=true;

            for(auto& it:V[node])

                if(!uz[it])

                    dfs1(it);

            ord.push_back(node);

        }

        void dfs2(int node,int c){

            comp[node]=c;

            for(auto& it:gV[node])

                if(!comp[it])

                    dfs2(it,c);

        }

    public:

        _2sat(int n){

            this->n=n;

            V.resize(2*n+1);

            gV.resize(2*n+1);

            uz.resize(2*n+1);

            comp.resize(2*n+1);

            ans.resize(n+1);

        }

        void addegde(int x,int y){

            cerr << "x,y" << " ->", debug_out(x,y);

            V[x].push_back(y);

            gV[y].push_back(x);

        }

        void solve(){

            for(int i=1;i<=2*n;i++)

                if(!uz[i])

                    dfs1(i);

            for(int i=1,cates=0;i<=2*n;i++){

                int node=ord[2*n-i];

                if(!comp[node])

                    dfs2(node,++cates);

            }

            for(int i=1;i<=n;i++){

                if(comp[i] == comp[i+n]){

                    fout<<"-1\n";

                    return;

                }

                ans[i]=(comp[i] > comp[i+n]);

            }

            int cate=0;

            for(int i=1;i<=n;i++)

                if(ans[i])

                    cate++;

            fout<<cate<<'\n';

            for(int i=1;i<=n;i++)

                if(ans[i])

                    fout<<i<<'\n';

            return;

        }

};



vector <int> vec;

vector <int> arb[DMAX];



int V[DMAX];



int n,m;



int NOT(int node){

    if(node > n)

        return node-n;

    return node+n;

}



int main(){

    int t,i,j;

    int op,x,y;



    fin>>n>>m;

    _2sat var(n);

    for(i=1;i<=m;i++){

        fin>>x>>y>>op;

        if(op == 1)

            y=NOT(y);

        else if(op == 2)

            x=NOT(x);

        else if(op == 3){

            x=NOT(x);

            y=NOT(y);

        }

        var.addegde(NOT(x),y);

        var.addegde(NOT(y),x);

    }

    var.solve();



    return 0;

}
