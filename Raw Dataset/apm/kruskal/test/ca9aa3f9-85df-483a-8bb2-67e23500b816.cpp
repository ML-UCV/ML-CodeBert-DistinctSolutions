#include <fstream>
#include <vector>
#include <algorithm>
struct s

{

    int n1, n2, muchii;

} v[400005];



using namespace std;



ifstream cin("apm.in");

ofstream cout("apm.out");





vector < s > sol;

vector < vector < pair < int, int > > > G;

int stramos[200005], raspuns;

int n, m;



bool cmp(s a, s b)

{

    return a.muchii < b.muchii ;

}



int tata(int x)

{

    if (stramos[x] == x)

        return x;

 stramos[x] = tata(stramos[x]);





 return stramos[x];

}



void reuniune(int x, int y)

{

    stramos[tata(x)] = tata(y);

}



void citire()

{

    cin >> n >> m;



    G.resize(n + 5);

    for(int i = 1 ; i <= m ; i++)

        cin >> v[i].n1 >> v[i].n2 >> v[i].muchii,

            G[v[i].n1].push_back(make_pair(v[i].n2, v[i].muchii)),

            G[v[i].n2].push_back(make_pair(v[i].n1, v[i].muchii));





}



void prep()

{

    sort(v + 1, v + m + 1, cmp);



    for(int i = 1 ; i <= n ; i++)

        stramos[i] = i;

}



void rez()

{

    int x, y, aux;



    for(int i = 1 ; i <= m ; i++)

        if (tata(v[i].n1) != tata(v[i].n2))

        {

            raspuns += v[i].muchii, reuniune(v[i].n1, v[i].n2),

            sol.push_back(v[i]);

        }

}



void afis()

{

    cout << raspuns << '\n' << sol.size() << '\n';



    for(int i = 0 ; i < sol.size() ; i++)

        cout << sol[i].n1 << ' ' << sol[i].n2 << '\n';

}



int main()

{

    citire();

    prep();

    rez();

    afis();

    return 0;

}
