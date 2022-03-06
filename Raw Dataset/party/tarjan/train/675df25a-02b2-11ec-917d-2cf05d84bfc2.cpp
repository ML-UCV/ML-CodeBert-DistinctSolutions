#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
using namespace std;
ifstream fin("party.in");

ofstream fout("party.out");



const int MAXN = 105;

vector<int> G[2 * MAXN], actual_component;

vector< vector<int> > Components;

stack<int> S;

int N, M, indexCount, indx[2 * MAXN], level[2 * MAXN];

bool in_stack[2 * MAXN], TruthValue[MAXN];
inline int non(int x) {

    return x > N ? x - N : x + N;

}



void Read() {

    fin >> N >> M;

    int x, y, cod;

    for (int i = 0; i < M; ++i) {

        fin >> x >> y >> cod;

        switch (cod) {

            case 1:

                y = non(y);

                break;

            case 2:

                x = non(x);

                break;

            case 3:

                x = non(x);

                y = non(y);

                break;

            default:

                break;

        }

        G[ non(x) ].push_back(y);

        G[ non(y) ].push_back(x);

    }

}



void Tarjan(int father) {

    indx[father] = level[father] = indexCount++;

    S.push(father); in_stack[father] = true;

    vector<int>::iterator it;

    for (it = G[father].begin(); it != G[father].end(); ++it) {

        if (indx[*it] == -1) {

            Tarjan(*it);

            level[father] = min(level[father], level[*it]);

        }else if (in_stack[*it]) {

            level[father] = min(level[father], level[*it]);

        }

    }

    if (indx[father] == level[father]) {

        actual_component.clear();

        int node;

        do {

            node = S.top();

            S.pop(); in_stack[node] = false;

            actual_component.push_back(node);

        }while (father != node);

        Components.push_back( actual_component );

    }

}



void Solve() {

    for (int i = 1; i <= 2 * N; ++i)

        indx[i] = -1;

    for (int i = 1; i <= 2 * N; ++i) {

        if (indx[i] == -1)

            Tarjan(i);

    }

    for (int i = Components.size() - 1; i >= 0; --i) {

        for (size_t j = 0; j < Components[i].size(); ++j) {

            if (not TruthValue[ Components[i][j] ] && not TruthValue[ non(Components[i][j]) ]) {

                TruthValue[ Components[i][j] ] = false;

                TruthValue[ non(Components[i][j]) ] = true;

            }

        }

    }

}



void Write() {

    int Sol = 0;

    for (int i = 1; i <= N; ++i)

        if (TruthValue[i] == true)

            ++Sol;

    fout << Sol << '\n';

    for (int i = 1; i <= N; ++i)

        if (TruthValue[i] == true)

            fout << i << '\n';

}



int main() {

    Read();

    Solve();

    Write();

    fin.close();

    fout.close();

    return 0;

}
