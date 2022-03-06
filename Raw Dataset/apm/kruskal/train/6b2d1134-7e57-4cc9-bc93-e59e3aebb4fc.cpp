#include <fstream>
#include <algorithm>
#include <vector>


using namespace std;



ifstream cin("apm.in");

ofstream cout("apm.out");



int n, m, v[400005], rnk[400005], cost, nrsel, sel[400005];

vector < pair<int, pair<int, int> > > mm;



int getPar(int x)

{

    if(v[x] == x)

        return x;



    v[x] = getPar(v[x]);

    return v[x];

}



void unitePar(int x, int y)

{

    int px = getPar(x);

    int py = getPar(y);



    if(rnk[px] < rnk[py])

    {

        v[px] = py;

        rnk[py] = max(rnk[py], rnk[px] + 1);

    }

    else

    {

        v[py] = px;

        rnk[px] = max(rnk[px], rnk[py] + 1);

    }

}



int main()

{

    cin >> n >> m;



    for(int i = 1; i <= n; ++i)

    {

        v[i]=i;

    }

    for(int i = 1; i <= m; ++i)

    {

        int a, b, c;

        cin >> a >> b >> c;

        mm.push_back({c, {a, b}});

    }



    sort(mm.begin(),mm.end());



    for(auto it = mm.begin(); it != mm.end(); ++it)

    {

        if(getPar(it->second.first) != getPar(it->second.second))

        {

            unitePar(it->second.first, it->second.second);

            cost += it->first;

            sel[++nrsel] = distance(mm.begin(), it);

        }

    }



    cout << cost << '\n';

    cout << nrsel << '\n';



    for(int i = 1; i <= nrsel; ++i)

    {

        cout << next(mm.begin(), sel[i])->second.first << ' ' << next(mm.begin(), sel[i])->second.second << '\n';

    }



    return 0;

}
