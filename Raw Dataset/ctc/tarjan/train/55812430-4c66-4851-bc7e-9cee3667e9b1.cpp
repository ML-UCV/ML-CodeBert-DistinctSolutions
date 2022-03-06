#include <iostream>
#include <fstream>
#include <stack>
#include <vector>




using namespace std;



ifstream f("ctc.in");

ofstream g("ctc.out");



int cnt, nrctc, n, m, mini[100000 +10], idx[100000 +10], inStack[100000 +10];

stack <int> stiva;

vector <int> nod[100000 +10], ctc[100000 +10];



void dfs(int x)

{ cnt++;

    mini[x] = idx[x] = cnt;

    stiva.push(x);

    inStack[x] = 1;

    for(int i=0; i<nod[x].size(); i++)

        { if(!idx[nod[x][i]])

                { dfs(nod[x][i]);

                    mini[x] = min(mini[x], mini[nod[x][i]]);

                }

            else if(inStack[nod[x][i]])

                mini[x] = min(mini[x], mini[nod[x][i]]);

        }

    if(idx[x] == mini[x])

        { nrctc++;

            while(stiva.top() != x)

                { inStack[stiva.top()] = 0;

                    ctc[nrctc].push_back(stiva.top());

                    stiva.pop();

                }

            ctc[nrctc].push_back(x);

            inStack[x] = 0;

            stiva.pop();

        }

}



int main()

{

    f >> n >> m;

    for(int i=1; i<=m; i++)

        { int nod1, nod2;

            f >> nod1 >> nod2;

            nod[nod1].push_back(nod2);

        }

    for(int i=1; i<=n; i++)

        if(!idx[i]) dfs(i);

    g << nrctc << '\n';

    for(int i=1; i<=nrctc; i++)

        { for(int j=0; j<ctc[i].size(); j++) g << ctc[i][j] << ' ';

            g << '\n';

        }

    return 0;

}
