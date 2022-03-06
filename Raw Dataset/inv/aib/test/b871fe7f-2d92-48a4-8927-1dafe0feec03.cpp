#include <iostream>
#include <cstdio>
#include <algorithm>
#include <fstream>
using namespace std;



ifstream fin("inv.in");

ofstream fout("inv.out");



const int MOD = 9917;

const int N = 100000;



int aib[N + 1];

struct nr{

    int val, index;

} v[N + 1];



int index[N + 1];



bool cmp(nr a, nr b){

    if(a.val > b.val)

        return true;

    else if(a.val == b.val && a.index > b.index)

        return true;

    return false;

}



int sum(int x){

    int ans = 0;

    while(x){

        ans += aib[x];

        x -= (x & (-x));

    }

    return ans;

}



int n;



void add(int x, int val){

    while(x <= n){

        aib[x] += val;

        x += (x & (-x));

    }

}



int main()

{

    int i,ans;

    fin >> n;

    for(i=1; i <= n; i++){

        fin >> v[i].val;

        v[i].index = i;

    }

    sort(v + 1, v + n + 1, cmp);

    ans = 0;

    for(i=1; i<=n; i++){

        ans = (ans + sum(v[i].index - 1)) % MOD;

        add(v[i].index, 1);

    }

    fout << ans << "\n";

    return 0;

}
