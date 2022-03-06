#include <fstream>
#include <set>
#include <algorithm>
#include <cmath>
#include <iomanip>




using namespace std;



ifstream f("cmap.in");

ofstream g("cmap.out");



int n;

struct point

{

    int x, y;

    bool operator < (const point &ot) const

    {

        if (x == ot.x)

            return y < ot.y;

        return x < ot.x;

    }

} v[100005];

set < point > s;



double dist(point a, point b)

{

    return sqrt(1LL * (a.x - b.x) * (a.x - b.x) + 1LL * (a.y - b.y) * (a.y - b.y));

}



int main()

{

    f >> n;

    for (int i = 0; i < n; ++ i)

        f >> v[i].x >> v[i].y;



    sort(v, v + n);



    double dist_min = dist(v[0], v[1]);

    int k = 0;



    for (int i = 0; i < n; ++ i) {



        while (k < i && double(v[i].x - v[k].x) >= dist_min)



            s.erase(s.find(point{v[k].y, v[k++].x}));





        int dist_int = (int)(dist_min);

        set <point> :: iterator it1 = s.lower_bound(point{v[i].y - dist_int,-((1<<30) - 1)});

        set <point> :: iterator it2 = s.upper_bound(point{v[i].y + dist_int, ((1<<30) - 1)});





        if (it2 != s.begin() && it1 != s.end())

            for (set <point> :: iterator it3= it1; it3 != it2; it3++)

                dist_min = min(dist_min , dist(v[i], point{it3->y, it3->x}));



        s.insert(point{v[i].y, v[i].x});

    }



    g << setprecision(7) << fixed << dist_min;



    return 0;

}
