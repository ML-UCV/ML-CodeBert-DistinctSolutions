#include<bits/stdc++.h>


using namespace std;



int n,m;

int dp[250010][25];

int rs;

int b[250010];



int main() {

    ifstream cin("stramosi.in");

    ofstream cout("stramosi.out");



    cin>>n>>m;

    for (int i=1; i<=n; ++i) {

        int x; cin>>x;

        b[i]=x;

    }



    for (int i=1; i<=n; ++i) dp[i][0]=b[i];

    for (int i=1; i<=n; ++i) {

        for (int j=1; (1<<j)<=n; ++j) dp[i][j]=dp[dp[i][j-1]][j-1];

    }



    while (m--) {

        int a,p; cin>>a>>p; rs=a;

        for (int i=0; i<=20; ++i) {

            if ((1<<i) & p) rs=dp[rs][i];

        }

        cout<<rs<<'\n';



    }



    return 0;

}
