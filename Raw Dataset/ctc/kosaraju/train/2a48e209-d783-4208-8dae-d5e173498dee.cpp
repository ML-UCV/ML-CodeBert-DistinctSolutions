#include <fstream>
#include <iostream>
#include <vector>



using namespace std;

vector<int> adj_list[200005], adj_list_transpus[200005], ordered_list, comp[200005];

int visited[200005], comp_nod[200005];
int nrcomp;

void dfs(int nod) {
    if (visited[nod])
        return ;

    visited[nod] = 1;

    for (auto &vec : adj_list[nod]) {
        dfs(vec);
    }
    ordered_list.push_back(nod);
}

void dfs_comp(int nod, int index)
{
    if(comp_nod[nod])
        return;

    comp_nod[nod] = index;
    comp[index].push_back(nod);

    for(auto it: adj_list_transpus[nod])
    {
        dfs_comp(it, index);
    }
}

int main()
{
    ifstream f("ctc.in");
    ofstream g("ctc.out");

    int n, m;
    f >> n >> m;
    while(m--)
    {
        int a, b;
        f >> a >> b;
        adj_list[a].push_back(b);
        adj_list_transpus[b].push_back(a);
    }

    for(int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }






    for(int i = n - 1; i >= 0; i--)
    {
        if(!comp_nod[ordered_list[i]]) {
            dfs_comp(ordered_list[i], ++nrcomp);
        }
    }
    g<< nrcomp << "\n";
    for(int i = 1; i <= nrcomp; i++)
    {
        for(auto it: comp[i])
        {
            g << it << " ";
        }
        g<< '\n';
    }
}
