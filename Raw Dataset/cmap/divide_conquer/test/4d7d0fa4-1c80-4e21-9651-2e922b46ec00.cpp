#include <iostream>#include <vector>
#include <fstream>#include <math.h>
#include <algorithm>
#include <iomanip>


using namespace std;



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



class cmap

{

public:

    void AddPoint(int x, int y)

    {

        v.push_back(punct(x, y));

    }

    pair<long double, vector<punct> > GetCmap()

    {

        sort(v.begin(), v.end(), cmp_x);

        return GetCmap(0, v.size() - 1);

    }

private:

    pair<long double, vector<punct> > GetCmap(int first, int last)

    {

        int nrPoints = last - first + 1;

        vector<punct> y_sorted(nrPoints);

        if(nrPoints <= 3)

        {

            copy(v.begin() + first, v.begin() + last + 1, y_sorted.begin());

            sort(y_sorted.begin(), y_sorted.end(), cmp_y);

            long double ret = dist(v[first], v[first+1]);

            for(int i = first; i < last; ++i)

                for(int j = i + 1; j <= last; ++j)

                    ret = min(ret, dist(v[i], v[j]));

            return make_pair(ret, y_sorted);

        }

        int mid = (first + last) / 2;

        pair<long double, vector<punct> > retSt = GetCmap(first, mid);

        pair<long double, vector<punct> > retDr = GetCmap(mid+1, last);



        long double ret = min(retSt.first, retDr.first);

        merge(retSt.second.begin(), retSt.second.end(),

              retDr.second.begin(), retDr.second.end(),

              y_sorted.begin(), cmp_y);



        vector<punct> utile;

        for(auto &p:y_sorted)

            if(abs(p.x - v[mid].x) <= ret)

                utile.push_back(p);



        for(int i = 0; i < utile.size(); ++i)

            for(int j = i + 1; j < utile.size(); ++j)

            {

                if(j - i >= 8)

                    break;

                ret = min(ret, dist(utile[i], utile[j]));

            }



        return make_pair(ret, y_sorted);

    }

    vector<punct> v;

};



int main()

{

    ifstream in("cmap.in");

    cmap puncte;

    int n, x, y;

    in >> n;

    while(n--)

    {

        in >> x >> y;

        puncte.AddPoint(x, y);

    }

    in.close();



    ofstream out("cmap.out");

    out << fixed << setprecision(8) << puncte.GetCmap().first;

    out.close();

    return 0;

}
