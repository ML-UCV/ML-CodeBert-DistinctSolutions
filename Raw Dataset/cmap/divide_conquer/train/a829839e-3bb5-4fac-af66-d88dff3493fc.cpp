#include <iostream>#include <vector>
#include <fstream>#include <math.h>
#include <algorithm>
#include <iomanip>


using namespace std;



const long double INF = 1e100;



struct punct

{

    punct(int x = 0, int y = 0)

    {

        this->x = x;

        this->y = y;

    }

    int x, y;

};



bool cmp_x(const punct &a, const punct &b)

{

    if(a.x == b.x)

        return a.y < b.y;

    return a.x < b.x;

}



bool cmp_y(const punct &a, const punct &b)

{

    if(a.y == b.y)

        return a.x < b.x;

    return a.y < b.y;

}



long double dist(const punct &a, const punct &b)

{

    int difX = a.x - b.x;

    int difY = a.y - b.y;

    return sqrt(1LL * difX * difX + 1LL * difY * difY);

}



const int nMax = 100005;



int n;

vector<punct> v;



void citire()

{

    ifstream in("cmap.in");

    in >> n;

    v.resize(n);

    for(int i = 0; i < n; ++i)

        in >> v[i].x >> v[i].y;

    in.close();

}



pair<long double, vector<punct> > GetRasp(int first, int last)

{

    int nrPoints = last - first + 1;

    vector<punct> y_sorted(nrPoints);

    if(nrPoints <= 3)

    {

        copy(v.begin() + first, v.begin() + last + 1, y_sorted.begin());

        sort(y_sorted.begin(), y_sorted.end(), cmp_y);

        long double ret = INF;

        for(int i = first; i < last; ++i)

            for(int j = i + 1; j <= last; ++j)

                ret = min(ret, dist(v[i], v[j]));

        return make_pair(ret, y_sorted);

    }

    int mid = (first + last) / 2;

    pair<long double, vector<punct> > retSt = GetRasp(first, mid);

    pair<long double, vector<punct> > retDr = GetRasp(mid+1, last);



    long double ret = min(retSt.first, retDr.first);

    merge(retSt.second.begin(), retSt.second.end(),

          retDr.second.begin(), retDr.second.end(),

          y_sorted.begin(), cmp_y);



    for(int i = 0; i < y_sorted.size(); ++i)

        for(int j = i + 1; j < y_sorted.size(); ++j)

        {

            if(y_sorted[j].y - y_sorted[i].y >= ret)

                break;

            ret = min(ret, dist(y_sorted[i], y_sorted[j]));

        }



    return make_pair(ret, y_sorted);

}



void rezolvare()

{

    sort(v.begin(), v.end(), cmp_x);

    long double rasp = GetRasp(0, n-1).first;



    ofstream out("cmap.out");

    out << fixed << setprecision(8) << rasp;

    out.close();

}



int main()

{

    citire();

    rezolvare();

    return 0;

}
