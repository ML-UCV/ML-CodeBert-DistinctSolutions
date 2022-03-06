#include <bits/stdc++.h>


using namespace std;



ifstream fin ("schi.in");

ofstream fout ("schi.out");



void usain_bolt()

{

    ios::sync_with_stdio(false);

    fin.tie(0);

}



const int N = 3e4 + 5;



int tree[N * 4], pos[N], a[N];



void build(int left, int right, int node)

{

    if(left == right) {

        tree[node] = 1;

        return ;

    }

    int mid = (left + right) >> 1;

    build(left, mid, node * 2);

    build(mid + 1, right, node * 2 + 1);

    tree[node] = tree[node * 2] + tree[node * 2 + 1];

}



void update(int left, int right, int node, int position)

{

    if(left == right) {

        tree[node] = 0;

        return ;

    }

    int mid = (left + right) >> 1;

    if(position <= mid) {

        update(left, mid, node * 2, position);

    }

    else {

        update(mid + 1, right, node * 2 + 1, position);

    }

    tree[node] = tree[node * 2] + tree[node * 2 + 1];

}



int query(int left, int right, int node, int position)

{

    if(left == right) {

        return left;

    }

    int mid = (left + right) >> 1;

    if(position <= tree[node * 2]) {

        return query(left, mid, node * 2, position);

    }

    else {

        return query(mid + 1, right, node * 2 + 1, position - tree[node * 2]);

    }

}



int main()

{

    usain_bolt();



    int n;



    fin >> n;

    for(int i = 1; i <= n; ++i) {

        fin >> pos[i];

    }

    build(1, n, 1);

    for(int i = n; i >= 1; --i) {

        int place = query(1, n, 1, pos[i]);

        a[place] = i;

        update(1, n, 1, place);

    }

    for(int i = 1; i <= n; ++i) fout << a[i] << "\n";

    return 0;

}
