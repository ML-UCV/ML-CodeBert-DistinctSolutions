#include <bits/stdc++.h>




using namespace std;



ifstream fin("ctc.in");

ofstream fout("ctc.out");



void debug_out() { cerr << '\n'; }

template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...);}
typedef pair<int,int> pii;

typedef long long int ll;

typedef long double ld;



const int DMAX = 1e5+10;



vector <int> ans[DMAX];

vector <int> arb[DMAX];

stack <int> s;



int uz[DMAX];

int lowlink[DMAX];



int n,m,comp,cnt;



void dfsT(int node);



int main(){

    ios_base::sync_with_stdio(false);

    cin.tie(0);



    int t,i,j;

    int x,y;



    fin>>n>>m;

    for(i=1;i<=m;i++){

        fin>>x>>y;

        arb[x].push_back(y);

    }

    for(i=1;i<=n;i++)

        if(!uz[i])

            dfsT(i);

    fout<<comp<<'\n';

    for(i=1;i<=comp;i++){

        for(auto& it:ans[i])

            fout<<it<<' ';

        fout<<'\n';

    }

    return 0;

}

void dfsT(int node){

    uz[node]=++cnt;

    lowlink[node]=cnt;

    s.push(node);

    for(auto& it:arb[node]){

        if(!uz[it])

            dfsT(it);

        if(uz[it] > 0)

            lowlink[node]=min(lowlink[node],lowlink[it]);

    }

    if(uz[node] == lowlink[node]){

        comp++;

        int node2;

        do{

            node2=s.top();

            ans[comp].push_back(node2);

            s.pop();

            uz[node2]=-1;

            if(node2 == node)

                break;

        }while(true);

    }

}
