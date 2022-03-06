#include <fstream>
#include <bitset>
#include <vector>


using namespace std;

const int NMAX = 100000;



ifstream fin("ctc.in");

ofstream fout("ctc.out");



vector<vector<int> > ad(NMAX + 5);

vector<vector<int> > ad_t(NMAX + 5);

vector<vector<int> > ans(NMAX + 5);



bitset<NMAX + 5> viz;



int postordine[NMAX + 5], cnt;



void DFS(int node)

{

    int i;

    viz[node] = 1;

    for(i = 0; i < ad[node].size(); i++)

        if(!viz[ad[node][i]])

            DFS(ad[node][i]);

    postordine[++cnt] = node;

}



void DFS_t(int node, int comp)

{

    int i;

    viz[node] = 0;

    ans[comp].push_back(node);

    for(i = 0; i < ad_t[node].size(); i++)

        if(viz[ad_t[node][i]])

            DFS_t(ad_t[node][i],comp);

}



int main()

{

    ios_base::sync_with_stdio(false);

    fin.tie(NULL);
    int n,m,i,j,a,b,tconx = 0;

    fin >> n >> m;

    while(m--)

    {

        fin >> a >> b;

        ad[a].push_back(b);

        ad_t[b].push_back(a);

    }

    for(i = 1; i <= n; i++)

        if(!viz[i])

            DFS(i);

    for(i = n; i > 0; i--)

        if(viz[postordine[i]])

            DFS_t(postordine[i],++tconx);

    fout << tconx << "\n";

    for(i = 1; i <= tconx; i++)

    {

        for(j = 0; j < ans[i].size(); j++)

            fout << ans[i][j] << " ";

        fout << "\n";

    }

    return 0;

}
