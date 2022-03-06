#include <fstream>
#include <algorithm>




using namespace std;

ifstream fin("inv.in");

ofstream fout("inv.out");

int n,i,nr,k,sol;

pair<int, int> v[100010];

int w[100010],f[100010];

void update(int p){

    for(;p<=k;p+=(p&-p))

        f[p]++;

}

int query(int p){

    int sol=0;

    for(;p;p-=(p&-p))

        sol+=f[p];

    return sol;

}

int main(){

    fin>>n;

    for(i=1;i<=n;i++){

        fin>>v[i].first;

        v[i].second=i;

    }

    sort(v+1,v+n+1);

    for(i=1;i<=n;i++)

        if(v[i].first!=v[i-1].first)

            w[v[i].second]=i-nr;

        else{

            nr++;

            w[v[i].second]=w[v[i-1].second];

        }

    k=n-nr;

    for(i=1;i<=n;i++){

        sol+=(query(k)-query(w[i]));

        sol%=9917;

        update(w[i]);

    }

    fout<<sol;

    return 0;

}
