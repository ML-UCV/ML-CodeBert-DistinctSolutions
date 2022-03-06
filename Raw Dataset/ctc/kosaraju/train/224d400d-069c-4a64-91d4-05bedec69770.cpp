#include <fstream>
#include <vector>
#include <cstring>
using namespace std;

int n, m, i, j, x, y, cnt;

bool viz[100001];

vector <int> gi[100001], go[100001], g[100001];

int lead [100001];

vector <int> discovered;

ifstream fin ("ctc.in");

ofstream fout ("ctc.out");



void DFP (int nod)

{

    viz[nod]=1;

    for (int i=0; i<go[nod].size(); i++) {

        int vec = go[nod][i];

        if (viz[vec]==0)

            DFP(vec);

    }

    discovered.push_back (nod);

}



void DFM (int nod, int nr)

{

    lead[nod]=nr;

    for ( int i=0; i<gi[nod].size(); i++ ) {

        int vec = gi[nod][i];

        if (lead[vec]==-1)

            DFM(vec, nr);

    }

}



int main () {

    fin>>n>>m;

    for (i=1;i<=m;i++) {

        fin>>x>>y;

        go[x].push_back(y);

        gi[y].push_back(x);

    }



    memset(viz, 0, sizeof (viz));

    for (i=1;i<=n;i++) {

        if (viz[i]==0) {

            DFP(i);

        }

    }



    for (i=0;i<=n;i++)

        lead[i]=-1;

    for ( ; discovered.size(); discovered.pop_back() ) {

        if (lead[discovered.back()]==-1) {

            DFM (discovered.back(), cnt);

            cnt++;

        }

    }



    for (i=1;i<=n;i++) {

        g[lead[i]].push_back(i);

    }



    fout<<cnt<<"\n";

    for (i=0;i<cnt;i++) {

        for (j=0;j<g[i].size();j++) {

            fout<<g[i][j]<<" ";

        }

        fout<<"\n";

    }



    return 0;

}
