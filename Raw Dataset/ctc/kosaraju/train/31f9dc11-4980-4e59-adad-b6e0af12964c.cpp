#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;





vector <bool> d(100005 +1, 0);
vector <int> LIST[100005], LISTT[100005], O, C[100005];
int n, m, c;

ofstream fout ("ctc.out");

void DFS (int x)
{
    d[x] = 1;
    for (unsigned i = 0; i < LIST[x].size(); ++i)
        if (!d[LIST[x][i]])
            DFS (LIST[x][i]);
    O.push_back (x);
}

void DFST (int x)
{
    d[x] = 0;
    C[c].push_back (x);
    for (unsigned i = 0; i < LISTT[x].size(); ++i)
        if (d[LISTT[x][i]])
            DFST (LISTT[x][i]);
}

int main ()
{
    ifstream fin ("ctc.in");
    fin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int x, y;
        fin >> x >> y;
        LIST[x].push_back (y);
        LISTT[y].push_back (x);
    }
    fin.close();
    for (int i = 1; i <= n; ++i) {
        sort (LIST[i].begin(), LIST[i].end());
        sort (LISTT[i].begin(), LISTT[i].end());
    }
    for (int x = 1; x <= n; ++x)
        if (!d[x])
            DFS (x);
    for (int x = n-1; x >= 0; --x)
        if (d[O[x]]) {
            DFST (O[x]);
            c++;
        }
    ofstream fout ("ctc.out");
    fout << c << "\n";
    for (int i = 0; i < c; ++i) {
        for (unsigned j = 0; j < C[i].size(); ++j)
            fout << C[i][j] << " ";
        fout << "\n";
    }
    return 0;
}
