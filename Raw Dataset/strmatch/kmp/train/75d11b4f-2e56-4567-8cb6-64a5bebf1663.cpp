#include <bits/stdc++.h>




using namespace std;



ifstream fin("strmatch.in");

ofstream fout("strmatch.out");



void debug_out() { cerr << '\n'; }

template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...);}
typedef pair<int,int> pii;

typedef long long int ll;

typedef long double ld;



const int DMAX = 2e6+10;



vector <int> sol;



char a[DMAX];

char b[DMAX];



int dp[DMAX];



int ans;



int main(){

    ios_base::sync_with_stdio(false);

    cin.tie(0);



    int t,i,j;

    int lga,lgb,k;



    fin>>(a+1);

    fin>>(b+1);



    lga=strlen(a+1);

    lgb=strlen(b+1);



    k=0;

    for(i=2;i<=lga;i++){

        while(a[k+1] != a[i] && k)

            k=dp[k];

        if(a[k+1] == a[i])

            k++;

        dp[i]=k;

    }



    k=0;

    if(a[1] == b[1])

        k=1;

    for(i=2;i<=lgb;i++){

        while(a[k+1] != b[i] && k)

            k=dp[k];

        if(a[k+1] == b[i])

            k++;

        if(k == lga){

            ans++;

            if(sol.size() < 1000)

                sol.push_back(i-lga);

        }

    }

    fout<<ans<<'\n';

    for(auto& it:sol)

        fout<<it<<' ';

    fout<<'\n';



    return 0;

}
