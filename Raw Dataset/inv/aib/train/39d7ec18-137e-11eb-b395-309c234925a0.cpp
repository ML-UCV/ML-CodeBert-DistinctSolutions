#include <bits/stdc++.h>




using namespace std;

typedef long long ll;



const int MOD = 9917;



int aib[100005],n;



int sum(int x){

    int s = 0;

    for(int i = x;i > 0;i -= i&(-i))

        s += aib[i];

    return s;

}



void update(int x){

    for(int i = x;i <= n;i += i&(-i))

        aib[i]++;

}

vector <pair <int,int> > v;

int main()

{

    int i;

    ll rez = 0;

    ifstream cin("inv.in");

    ofstream cout("inv.out");

    cin >> n;

    for(i = 1;i <= n;i++){

        int x;

        cin >> x;

        v.push_back({x,i});

    }

    sort(v.begin(),v.end());

     i = 1;

    for(auto x : v){

        rez += 1LL * (i - 1 - sum(x.second - 1));

        rez %= MOD;

        update(x.second);

        i++;

    }

    cout << rez;

    return 0;

}
