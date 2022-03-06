#include <fstream>
#include <iostream>
#include <vector>






using namespace std;



ifstream f("stramosi.in");

ofstream g("stramosi.out");



int n, m, top, stiva[250000 +10], ans[300000 +10];

bool b[250000 +10];

vector <int> nod[250000 +10];

vector <pair <int, int> > query[250000 +10];



void DFS(int x)

{

    b[x] = 1;

    stiva[++top] = x;

    for(int i=0; i<query[x].size(); i++)

        { if(top <= query[x][i].first) ans[query[x][i].second] = 0;

            else ans[query[x][i].second] = stiva[top-query[x][i].first];

        }

    for(int i=0; i<nod[x].size(); i++)

        if(!b[nod[x][i]])

            DFS(nod[x][i]);

    top--;

}



int main()

{

    f >> n >> m;

    for(int i=1; i<=n; i++)

        { int x;

            f >> x;

            if(x)

                { nod[i].push_back(x);

                    nod[x].push_back(i);

                }

        }

    for(int i=1; i<=m; i++)

        { int x, y;

            f >> x >> y;

            query[x].push_back(make_pair(y, i));

        }

    for(int i=1; i<=n; i++) if(!b[i]) DFS(i);

    for(int i=1; i<=m; i++) g << ans[i] << '\n';

    return 0;

}
