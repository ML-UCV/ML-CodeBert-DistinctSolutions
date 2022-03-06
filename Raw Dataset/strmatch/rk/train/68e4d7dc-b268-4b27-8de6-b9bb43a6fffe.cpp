#include <bits/stdc++.h>


using namespace std;



ifstream fin("strmatch.in");

ofstream fout("strmatch.out");



typedef long long ll;



const int baza = 543217;

const int mod = 100000007;



string n, m;

int N, M;

vector <int> ans;



void read(){

    fin >> n >> m;

    N = n.length();

    M = m.length();

}



void solve(){

    ll hashN = 0, hashM = 0, bazaN = 1;



    for(int i = 1; i < N; i++)

        bazaN = (1LL * bazaN * baza) % mod;



    for(int i = 0; i < N; i++){

        hashN = (hashN * baza * 1LL + n[i] - '0')%mod;

        hashM = (hashM * baza * 1LL + m[i] - '0')%mod;

    }



    if(hashN == hashM)

        ans.push_back(0);



    for(int i = N; i < M; i++){

        hashM = hashM - (m[i - N] - '0') * bazaN * 1LL;

        hashM %= mod;



        hashM = hashM * baza * 1LL + (m[i] - '0');

        hashM %= mod;



        if(hashM < 0)

            hashM += mod;



        if(hashM == hashN)

            ans.push_back(i - N + 1);

    }



    fout << ans.size() << "\n";



    for(int i = 0; i < ans.size(); i++){

        fout << ans[i] << " ";



        if(i == 999)

            break;

    }

}



int main()

{

    read();

    solve();



    return 0;

}
