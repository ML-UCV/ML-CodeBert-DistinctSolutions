#include <bits/stdc++.h>


using namespace std;



ifstream in("apm.in");

ofstream out("apm.out");



const int N = 2e5 + 5;

int TT[N];

int RG[N];

long long ans_cost = 0;

int n, m;



struct edge

{

    int x, y, c;

};

vector <edge> graph;

vector <pair<int,int>>ans;



bool cmp(edge A, edge B)

{

    return A.c < B.c;

}



int find_root(int node)

{

    int root = node, aux = node;



    while(TT[root] != 0)

        root = TT[root];



    while(root != node)

    {

        aux = TT[node];

        TT[node] = root;

        node = aux;

    }



    return root;

}



int unite(int x, int y)

{

    x = find_root(x);

    y = find_root(y);



    if(x == y) return 0;



    if(RG[x] < RG[y])

        swap(x, y);



    TT[y] = x;

    RG[x] += RG[y];



    return 1;

}



main()

{

    ios::sync_with_stdio(false);

    in.tie(0);



    in >> n >> m;



    while(m--)

    {

        edge M;

        in >> M.x >> M.y >> M.c;

        graph.push_back(M);

    }



    sort(graph.begin(), graph.end(), cmp);



    for(size_t i = 0; i < graph.size() && ans.size() < n - 1; i++)

        if(unite(graph[i].x,graph[i].y) != 0)

        {

            ans_cost += graph[i].c;

            ans.push_back({graph[i].x, graph[i].y});

        }



    out << ans_cost << '\n' << n - 1 << '\n';



    for(size_t i = 0; i < ans.size(); i++)

        out << ans[i].first << ' ' << ans[i].second << '\n';



    return 0;

}
