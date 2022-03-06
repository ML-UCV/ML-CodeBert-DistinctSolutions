#include <stdio.h>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
#include <map>
#include <string>
#include <cctype>
#include <iomanip>
using namespace std;


ifstream cin("schi.in");
ofstream cout("schi.out");

const int MAXN = 3e4 + 5;
int n, v[MAXN], ans[MAXN], tree[4 * MAXN];

void Update (int nod, int st, int dr, int pos, int val){
    if (st == dr){
        tree[nod] = val;
        return;
    }
    int mij = (st + dr) / 2;
    if (pos <= mij){
        Update(nod * 2, st, mij, pos, val);
    }
    else{
        Update(nod * 2 + 1, mij + 1, dr, pos, val);
    }
    tree[nod] = tree[nod * 2] + tree[nod * 2 + 1];
}


void read() {
    cin>>n;
   for (int i=1; i<=n; i++){
       Update (1, 1, n, i, 1);
       cin>>v[i];
   }
}

void Querry (int nod, int st, int dr, int pos, int val){
    if (st == dr){
        ans[st] = val;
        Update (1, 1, n, st, 0);
        return;
    }
    int mij = (st + dr) / 2;
    if (tree[nod * 2] >= pos){
        Querry(nod * 2, st, mij, pos, val);
    }
    else{
        Querry(nod * 2 + 1, mij + 1, dr, pos - tree[nod * 2], val);
    }
}

void solve() {
    read();
    for (int i=n; i>=1; i--)
        Querry(1, 1, n, v[i], i);

    for (int i=1; i<=n; i++)
        cout<<ans[i]<<'\n';

}

int main() {

    solve();

    return 0;
}
