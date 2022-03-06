#include <bits/stdc++.h>


using namespace std;



ifstream fin ("apm.in");

ofstream fout ("apm.out");



const int DIM = 200000 + 5;



int Size[DIM], parent[DIM];



vector < pair < int, int > > sol;



void make_set(int k)

{

    Size[k] = 1;

    parent[k] = k;

}



int find_set(int k)

{

    if(k == parent[k]) return k;

    return parent[k] = find_set(parent[k]);

}



void union_sets(int a, int b)

{

    a = find_set(a);

    b = find_set(b);

    if(a != b) {

        if(Size[b] > Size[a]) {

            swap(a, b);

        }

        Size[a] += Size[b];

        parent[b] = a;

    }

}



struct solve

{

    int x, y, w;



    bool operator < (const solve & nxt) const

    {

        return w < nxt.w;

    }

};



vector < solve > edges;



int main()

{

    int n, m;



    fin >> n >> m;

    for(int i = 1; i <= m; ++i) {

        int x, y, w;



        fin >> x >> y >> w;

        edges.push_back({x, y, w});

    }

    int ans = 0;

    for(int i = 1; i <= n; ++i) make_set(i);

    sort(edges.begin(), edges.end());

    for(auto v : edges) {

        if(find_set(v.x) != find_set(v.y)) {

            union_sets(v.x, v.y);

            ans += v.w;

            sol.push_back({v.x, v.y});

        }

    }

    fout << ans << "\n";

    fout << sol.size() << "\n";

    for(auto v : sol) {

        fout << v.first << " " << v.second << "\n";

    }

    return 0;

}
