#include <bits/stdc++.h>
using namespace std;



ifstream fin("apm.in");

ofstream fout("apm.out");



const int N_MAX = 2e5 + 1;



int id[N_MAX], sz[N_MAX];



int dsu_find(int node)

{

    int root = node;



    while(id[root] != 0)

        root = id[root];



    int aux = node;



    while(node != root)

    {

        aux = id[node];

        id[node] = root;

        node = aux;

    }



    return root;

}





bool dsu_union(int x, int y)

{

    int root_x = dsu_find(x);

    int root_y = dsu_find(y);



    if(root_x == root_y) return false;



    if(sz[root_x] < sz[root_y]) swap(root_x, root_y);



    sz[root_x] += sz[root_y];

    id[root_y] = root_x;



    return true;

}





int N, M;



struct Muchie{

    int x, y, c;

};



vector<Muchie> graph;



vector<pair<int, int>> answer;



int main()

{

    fin >> N >> M;



    for(int i = 1; i <= M; ++i)

    {

        Muchie m;

        fin >> m.x >> m.y >> m.c;



        graph.push_back(m);

    }



    sort(graph.begin(), graph.end(), [](Muchie& A, Muchie& B){return A.c < B.c;});



    long long min_cost = 0;



    for(size_t i = 0; i < graph.size() && answer.size() != (size_t)N - 1; ++i)

    {

        if(dsu_union(graph[i].x, graph[i].y) == true)

        {

            min_cost += graph[i].c;

            answer.push_back({graph[i].x, graph[i].y});

        }

    }





    fout << min_cost << '\n';

    fout << N - 1 << '\n';



    for(auto& muchie : answer)

        fout << muchie.first << ' ' << muchie.second << '\n';

}
