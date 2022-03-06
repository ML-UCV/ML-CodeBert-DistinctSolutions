#include <iostream>
#include <fstream>

using namespace std;

ifstream fin ("ctc.in");
ofstream fout ("ctc.out");

const int N = 100001;
const int M = 200001;

int stiva[N], cnt, inv_stiva[N];
int lst[N], vf[2*M], urm[2*M], n, nr, viz[N];
int inv_lst[N], inv_vf[2*M], inv_urm[2*M], inv_viz[N];
int ans[2*N+1], anspos;

void topological_sort_dfs(int x) {
    viz[x] = true;
    int y;
    for ( int p = lst[x]; p != 0; p = urm[p] ) {
        y = vf[p];
        if ( !viz[y] )
            topological_sort_dfs(y);
    }
    stiva[++cnt] = x;
}

void inverse_topological_sort_dfs(int x) {
    inv_viz[x] = true;
    ans[anspos++] = x;
    int y;
    for ( int p = inv_lst[x]; p != 0; p = inv_urm[p] ) {
        y = inv_vf[p];
        if ( !inv_viz[y] )
            inverse_topological_sort_dfs(y);
    }
    inv_stiva[++cnt] = x;
}

void adauga (int x, int y) {
    ++nr;

    vf[nr] = y;
    urm[nr] = lst[x];
    lst[x] = nr;

    inv_vf[nr] = x;
    inv_urm[nr] = inv_lst[y];
    inv_lst[y] = nr;
}

int main () {
    int n, m, x, y;
    fin>>n>>m;

    for ( int i = 0; i < m; i++ ) {
        fin>>x>>y;
        adauga(x,y);
    }

    for (int i = 1; i <= n; i++ ) {
        if ( !viz[i] )
            topological_sort_dfs(i);
    }

    cnt = 0;
    int nrof = 0;
    for (int i = n; i > 0; i-- ) {
        if ( !inv_viz[stiva[i]] )
        {
            inverse_topological_sort_dfs(stiva[i]);
            ans[anspos++] = -1;
            ++nrof;
        }
    }

    fout<<nrof<<'\n';
    for (int i = 0; i < anspos; i++ ) {
        if ( ans[i] == -1 )
            fout<<'\n';
        else
            fout<<ans[i]<<" ";
    }

    return 0;
}
