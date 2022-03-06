#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>


using namespace std;



const int N = 200005;



ifstream fin("apm.in");

ofstream fout("apm.out");



vector<int> t;



int find(int x)

{

    if(t[x] == 0)

        return x;

    t[x] = find(t[x]);

    return t[x];

}



void unite(int x, int y)

{

    int tx = find(x);

    int ty = find(y);

    t[tx] = ty;

}



int main()

{

    int n, m;

    fin >> n >> m;





    vector< pair<int, pair<int, int>> > muchii;

    muchii.resize(m);

    t.resize(n+1);

    for(int i = 0; i < m; i++)

    {

        int c, x, y;

        fin >> x >> y >> c;

        muchii[i] = {c, {x, y}};

    }



    sort(muchii.begin(), muchii.end());



    int costArb = 0;

    vector<pair<int, int>> arbore;

    for(auto muchie : muchii)

    {

        int x = muchie.second.first;

        int y = muchie.second.second;

        int cost = muchie.first;



        if(find(x) != find(y))

        {

            arbore.push_back({x, y});

            costArb += cost;



            unite(x, y);

        }

    }



    fout << costArb << '\n' << arbore.size() << '\n';

    for(auto muchie : arbore)

        fout << muchie.first << ' ' << muchie.second << '\n';



    return 0;

}
