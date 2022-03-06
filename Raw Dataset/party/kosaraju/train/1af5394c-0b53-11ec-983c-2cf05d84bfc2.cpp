#include <bits/stdc++.h>


using namespace std;



ifstream fin ("party.in");

ofstream fout ("party.out");



const int maxval = 300;



int x, y, tip, n, m, i, nrc, where[maxval];

vector<int> v[maxval], vt[maxval], ord, come;

bool fol[maxval];



int no(int x) {return x + n;}



void addEdge(int x, int y)

{

    v[x].push_back(y);

    vt[y].push_back(x);

}



void dfs(int node)

{

    fol[node] = 1;

    for(auto go : v[node])

        if(!fol[go]) dfs(go);

    ord.push_back(node);

}



void dfsinv(int node)

{

    where[node] = nrc;

    for(auto go : vt[node])

        if(!where[go]) dfsinv(go);

}



int main()

{

    fin >> n >> m;

    while(m--)

    {

        fin >> x >> y >> tip;

        if(tip == 0) addEdge(no(x), y), addEdge(no(y), x);

            else if(tip == 1) addEdge(no(x), no(y)), addEdge(y, x);

                else if(tip == 2) addEdge(no(y), no(x)), addEdge(x, y);

                    else if(tip == 3) addEdge(x, no(y)), addEdge(y, no(x));

    }



    for(i=1; i<=2*n; ++i)

        if(!fol[i]) dfs(i);



    reverse(ord.begin(), ord.end());

    for(auto node : ord)

        if(!where[node])

            ++nrc, dfsinv(node);



    for(i=1; i<=n; ++i)

        if(where[i] > where[no(i)]) come.push_back(i);



    fout << come.size() << '\n';

    for(auto who : come) fout << who << '\n';

    return 0;

}
