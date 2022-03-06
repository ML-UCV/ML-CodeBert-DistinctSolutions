#include <bits/stdc++.h>


using namespace std;



ifstream fin ("apm.in");

ofstream fout ("apm.out");



void usain_bolt()

{

    ios::sync_with_stdio(false);

    fin.tie(0);

}



const int N = 2e5 + 5;



struct solve

{

    int x, y, w;

    bool operator < (const solve & nxt) const

    {

        return w < nxt.w;

    }

};



vector < solve > edge;

vector < pair < int, int > > sol;



int ans = 0;

int Size[N], parent[N];



void make_set(int k)

{

    Size[k] = 1;

    parent[k] = k;

}



int find_set(int k)

{

    if(parent[k] == k) return k;

    return parent[k] = find_set(parent[k]);

}



void union_sets(int a, int b)

{

    a = find_set(a), b = find_set(b);

    if(a != b) {

        if(Size[b] > Size[a]) swap(a, b);

        Size[a] += Size[b];

        parent[b] = a;

    }

}



int main()

{

    usain_bolt();



    int n, m;



    fin >> n >> m;

    for(int i = 1; i <= m; ++i) {

        int x, y, w;



        fin >> x >> y >> w;

        edge.push_back({x, y, w});

    }

    sort(edge.begin(), edge.end());

    for(int i = 1; i <= n; ++i) make_set(i);

    for(auto v : edge) {

        if(find_set(v.x) != find_set(v.y)) {

            sol.push_back({v.x, v.y}), ans += v.w;

            union_sets(v.x, v.y);

        }

    }

    fout << ans << "\n" << sol.size() << "\n";

    for(auto v : sol) fout << v.first << " " << v.second << "\n";

    return 0;

}
