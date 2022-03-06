#include <bits/stdc++.h>

using namespace std;

ifstream fin ("sate.in");
ofstream fout("sate.out");

const int N_MAX = 30000 + 5;

int x, y, n,m;

vector<pair<int,int> > vec[N_MAX];

bitset<N_MAX> viz;

void dfs(int nod, int sum){

    if(viz[nod])
        return;

    viz[nod] = true;


    if(nod == y){
        fout << sum;
        exit(0);
    }else{
        for(auto v : vec[nod]){
            dfs(v.first, sum + v.second);
        }
    }

}

int main()
{

    fin >> n >> m >> x >> y;

    while(m--){
        int a,b,d;
        fin >> a >> b >> d;
        if(a > b)
            swap(a,b);
        vec[a].push_back({b,d});
        vec[b].push_back({a,-d});
    }

    dfs(x, 0);

    return 0;
}
