#include <bits/stdc++.h>


using namespace std;



ifstream fin ("party.in");

ofstream fout ("party.out");



const int Nmax = 300;



int x, y, tip, n, m, i, nrc, where[Nmax];

vector<int> v[Nmax], vt[Nmax], ord, come;

bool used[Nmax];



int no(int x) {return x + n;}



void add_edge(int x, int y)

{

    v[x].push_back(y);

    vt[y].push_back(x);

}



void dfs1(int node)

{

    used[node] = 1;

    for(auto go : v[node])

        if(!used[go]) dfs1(go);

    ord.push_back(node);

}



void dfs2(int node)

{

    where[node] = nrc;

    for(auto go : vt[node])

        if(!where[go]) dfs2(go);

}



int main()

{

    fin >> n >> m;

    while(m--)

    {

        fin >> x >> y >> tip;

        if(tip == 0) add_edge(no(x), y), add_edge(no(y), x);

            else if(tip == 1) add_edge(no(x), no(y)), add_edge(y, x);

                else if(tip == 2) add_edge(no(y), no(x)), add_edge(x, y);

                    else if(tip == 3) add_edge(x, no(y)), add_edge(y, no(x));

    }



    for(i=1; i<=2*n; ++i)

        if(!used[i]) dfs1(i);



    reverse(ord.begin(), ord.end());

    for(auto node : ord)

        if(!where[node])

            ++nrc, dfs2(node);



    for(i=1; i<=n; ++i)

        if(where[i] > where[no(i)]) come.push_back(i);



    fout << come.size() << '\n';

    for(auto who : come) fout << who << '\n';

    return 0;

}
