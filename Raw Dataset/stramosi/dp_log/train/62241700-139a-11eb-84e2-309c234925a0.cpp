#include <fstream>




using namespace std;

ifstream fin("stramosi.in");

ofstream fout("stramosi.out");



int n,q,dp[20][(int)(25e4+5)],lg[(int)(25e4+5)];



void read();

void solve();

int lsb(int&);



int main(){

    read();

    solve();

    return 0;

}

void solve(){

    int a,b,ancestor;

    while(q--){

        fin>>a>>b;

        ancestor=a;



        while(b){

            ancestor=dp[lg[lsb(b)]-1][ancestor];

            b-=lsb(b);

        }

        fout<<ancestor<<'\n';

    }

}

void read(){

    int i,j;

    fin>>n>>q;

    for(i=1;i<=n;++i)

        fin>>dp[0][i];



    for(i=1;i<=n;++i)

        lg[i]=lg[i/2]+1;



    for(i=1;i<20;++i){

        for(j=1;j<=n;++j){

            dp[i][j]=dp[i-1][dp[i-1][j]];

        }

    }

}

int lsb(int& x){

    return x&(-x);

}
