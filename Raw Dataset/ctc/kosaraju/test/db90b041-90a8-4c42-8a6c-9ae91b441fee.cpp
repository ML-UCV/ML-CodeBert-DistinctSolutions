#include <iostream>
#include <map>
#include <vector>
#include <fstream>
using namespace std;



ifstream f("ctc.in");

ofstream g("ctc.out");



int n, m;

int n_dfs_forest;

int n_scc;



vector <int> * lvg;

vector <int> * lvgt;



vector <vector <int>> dfs_forest;

int * visited;





vector <vector<int>> scc;



void DFS(int node){



    for (int i = 0; i < lvg[node].size(); i++)



        if (!visited[lvg[node][i]]){



            visited[lvg[node][i]] = visited[node];

            DFS(lvg[node][i]);

        }



    dfs_forest[n_dfs_forest - 1].push_back(node);

}



void DFS_transposed(int node){



    scc[n_scc - 1].push_back(node);



    for (int i = 0; i < lvgt[node].size(); i++){



        if (visited[lvgt[node][i]] > 0){



            visited[lvgt[node][i]] = -1;

            DFS_transposed(lvgt[node][i]);

        }

    }

}





int main(){



    f >> n >> m;



    lvg = new vector <int> [n + 1];

    lvgt = new vector <int> [n + 1];



    visited = new int[n + 1];



    for(int i = 0; i <= n; i++){



        visited[i] = 0;

    }



    int x, y;

    for (int cnt = 0; cnt < m; cnt++){



        f >> x >> y;



        lvg[x].push_back(y);

        lvgt[y].push_back(x);

    }
    for (int i = 1; i <= n; i++){



        if (!visited[i]){



            n_dfs_forest = dfs_forest.size() + 1;

            dfs_forest.resize(n_dfs_forest);



            visited[i] = i;

            DFS(i);



            while (dfs_forest[n_dfs_forest - 1].size() > 0){



                int current_node = dfs_forest[n_dfs_forest - 1].back();

                dfs_forest[n_dfs_forest - 1].pop_back();



                if (visited[current_node] > 0){



                    n_scc = scc.size() + 1;

                    scc.resize(n_scc);



                    visited[current_node] = -1;

                    DFS_transposed(current_node);

                }

            }

        }

    }



    g << scc.size() << '\n';

    for (int i = 0; i < scc.size(); i++){



        for (int j = 0; j < scc[i].size(); j++){



            g << scc[i][j] << " ";

        }

        g << '\n';

    }
    return 0;

}
