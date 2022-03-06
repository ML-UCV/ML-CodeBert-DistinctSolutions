#include <iostream>
#include <fstream>
#include <vector>


using namespace std;



ifstream fin("ctc.in");

ofstream fout("ctc.out");



const int N = 100005;



int n, m;

int cc[N];

vector<int> g[N], gt[N], compConexa[N], ord;

bool viz[N];



void dfs1(int x)

{

    viz[x] = true;

    for(int y : g[x])

        if(!viz[y])

            dfs1(y);



    ord.push_back(x);

}



void dfs2(int x, int ccx)

{

    cc[x] = ccx;

    compConexa[ccx].push_back(x);



    for(int y : gt[x])

        if(!cc[y])

            dfs2(y, ccx);

}



int main()

{

    fin >> n >> m;

    for(int i = 0; i < m; i++)

    {

        int x, y;

        fin >> x >> y;



        g[x].push_back(y);

        gt[y].push_back(x);

    }



    for(int i = 1; i <= n; i++)

        if(!viz[i])

            dfs1(i);



    int cci = 1;

    for(int i = ord.size() - 1; i >= 0; i--)

        if(cc[ord[i]] == 0)

            dfs2(ord[i], cci++);



    fout << cci-1 << '\n';

    for(int i = 1; i < cci; i++)

    {

        for(int x : compConexa[i])

            fout << x << ' ';

        fout << '\n';

    }



    fin.close();

    fout.close();

    return 0;

}
