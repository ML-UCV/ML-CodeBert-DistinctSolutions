#include<bits/stdc++.h>
using namespace std;

ifstream f("schi.in");

ofstream g("schi.out");

int n,i;

int v[30005], fin[30005], tree[4 * 30005];



void update(int l, int r, int node)

{

    if(l == r)

        tree[node] = 1;

    else{

        int mid = (l + r) / 2;

        update(l, mid, 2 * node);

        update(mid + 1, r, 2 * node + 1);

        tree[node] = tree[2 * node] + tree[2 * node + 1];

    }

}



void clasament(int l, int r, int node ,int pos){

    if(l == r){

        tree[node] = 0;

        fin[l] = i;

    }

    else{

        int mid = (l + r) / 2;

        if(tree[2 * node] >= pos){

            clasament(l ,mid ,2 * node, pos);

        }

        else{

            clasament(mid + 1, r ,2 * node + 1,pos - tree[2 * node]);

        }

        tree[node] = tree[2 * node] + tree[2 * node + 1];

    }

}



int main(){

    f>>n;

    for(int i=1;i<=n;i++){

        f>>v[i];

    }

    update (1, n, 1);

    for(i = n; i >= 1; i--)

        clasament(1, n, 1, v[i]);

    for(i = 1; i <= n; i++)

        g<<fin[i]<<"\n";

    return 0;

}
