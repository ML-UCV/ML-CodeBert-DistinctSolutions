#include <bits/stdc++.h>

std::ifstream fin("apm.in");
std::ofstream fout("apm.out");

std::pair<int, std::pair<int, int> > edges[400001];
int d[200001], sol[200001];
int n, m;

int get_root(int node){
    while(d[node] > 0)
        node = d[node];
    return node;
}

int main()
{
    int i, x, y, cost, total_cost = 0, found = 0;
    fin >> n >> m;
    for(i = 0; i < n; i++)
        d[i] = -1;
    for(i = 0; i < m; i++){
        fin >> x >> y >> cost;
        edges[i].first = cost;
        edges[i].second = std::make_pair(x, y);
    }
    sort(edges, edges + m);

    for(i = 0; i < m && found != n; i++){
        int node_1 = edges[i].second.first, node_2 = edges[i].second.second;
        int r1 = get_root(node_1), r2 = get_root(node_2);
        cost = edges[i].first;

        if(r1 != r2){
            if(d[r1] < d[r2]){
                d[r1] += d[r2];
                d[r2] = r1;
            }
            else{
                d[r2] += d[r1];
                d[r1] = r2;
            }

        sol[found++] = i;
        total_cost += cost;
        }
    }

    fout << total_cost << std::endl << found << std::endl;
    for(i = 0; i < found; i++)
        fout << edges[sol[i]].second.first << " " << edges[sol[i]].second.second << std::endl;





    return 0;
}
