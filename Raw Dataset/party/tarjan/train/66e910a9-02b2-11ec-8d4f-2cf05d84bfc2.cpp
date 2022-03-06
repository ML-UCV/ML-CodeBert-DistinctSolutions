#include <fstream>
#include <vector>
#include <stack>




using namespace std;



ifstream f("party.in");

ofstream g("party.out");



vector<int> L[205];



stack<int> s;



int n, m, nivel, x, y, op;



int Niv[205], Low[205], R[205];



int sol, Sol[205];



void DFS (int nod) {

    Niv[nod] = Low[nod] = ++nivel;

    s.push(nod);

    for (vector<int>::iterator it=L[nod].begin(); it!=L[nod].end(); ++it) {

        if (Niv[*it] == 0)

            DFS(*it);

        if (Niv[*it]>0 && Low[nod]>Low[*it])

            Low[nod] = Low[*it];

    }

    if (Low[nod] == Niv[nod]) {

        int nnod;

        do {

            nnod = s.top();

            s.pop();

            Niv[nnod] *= -1;

            if (R[nnod] == 0) {

                R[nnod] = 1;

                if (nnod <= n)

                    R[nnod + n] = -1;

                else

                    R[nnod - n] = -1;

            }

        } while (nnod != nod);

    }

}



int main () {

    f >> n >> m;

    for (int i=1; i<=m; ++i) {

        f >> x >> y >> op;

        if (op == 1) {

            L[y].push_back(x);

            L[x+n].push_back(y+n);

        }

        else

        if (op == 2) {

            L[x].push_back(y);

            L[y+n].push_back(x+n);

        }

        else

        if (op == 3) {

            L[x].push_back(y+n);

            L[y].push_back(x+n);

        }

        else

        if (op == 0) {

            L[x+n].push_back(y);

            L[y+n].push_back(x);

        }

    }

    for (int i=1; i<=n; ++i)

        if (Niv[i] == 0)

            DFS (i);

    for (int i=1; i<=n; ++i)

        if (R[i] == 1)

            Sol[++sol] = i;

    g << sol << "\n";

    for (int i=1; i<=sol; ++i)

        g << Sol[i] << "\n";

    return 0;

}
