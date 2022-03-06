#include<bits/stdc++.h>
using namespace std;
ifstream fin("stramosi.in");ofstream fout("stramosi.out");







long long t, n, m;

long long a[20][250010];



int32_t main(){

ios_base :: sync_with_stdio(false); fin.tie(NULL); fout.tie(NULL);mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

fin>>n>>m;

for(long long i=1; i<=n; i++){

    fin>>a[0][i];

}

for(long long j=1; j<=19; j++){

    for(long long i=1; i<=n; i++){

        a[j][i]=a[j-1][a[j-1][i]];

    }

}



while(m--){

    long long p, q;

    fin>>q>>p;

    while(p>0){

        for(long long j=0; j<=19; j++){

            if(p<(((long long)1)<<j) ){

                q=a[j-1][q]; p-=(((long long)1)<<(j-1) ); break;

            }

        }

    }

    fout<<q<<"\n";

}
return 0;

}
