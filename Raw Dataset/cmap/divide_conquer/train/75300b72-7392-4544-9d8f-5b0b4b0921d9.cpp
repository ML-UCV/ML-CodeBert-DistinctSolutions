#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;



ifstream f("cmap.in");

ofstream g("cmap.out");



struct point {

    long long x, y;

};
long long get_dist_sqr(point a, point b) {

    return (b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y);

}



bool comparex(point a, point b) {





    return a.x < b.x;

}



bool comparey(point a, point b) {





    return a.y < b.y;

}



long long get_min_strip(long long dmin, vector<point> strip) {



    unsigned n = strip.size();

    for (unsigned i = 0; i < n - 1; i++)

        for (unsigned j = i + 1; j < n and j < i + 8; j++) {

            if (get_dist_sqr(strip[i], strip[j]) < dmin)

                dmin = get_dist_sqr(strip[i], strip[j]);

        }

    return dmin;

}



long long distantaMinima(int st, int dr, vector<point> &pointx, vector<point> &pointy) {



    if (dr - st <= 3) {

        long long dmin = get_dist_sqr(pointx[st], pointx[st + 1]);

        for (unsigned i = st; i < dr; i++)

            for (unsigned j = i + 1; j <= dr; j++)

                if (get_dist_sqr(pointx[i], pointx[j]) < dmin)

                    dmin = get_dist_sqr(pointx[i], pointx[j]);

        return dmin;

    }



    else {

        int mij = (st + dr) / 2;

        point midPoint = pointx[mij];



        vector<point> ord_st, ord_dr;

        for (unsigned i = 0; i < pointy.size(); i++) {

            if (pointy[i].x <= midPoint.x)

                ord_st.push_back(pointy[i]);

            else

                ord_dr.push_back(pointy[i]);

        }



        long long d1 = distantaMinima(st, mij, pointx, ord_st);

        long long d2 = distantaMinima(mij + 1, dr, pointx, ord_dr);

        long long dmin = d1 < d2 ? d1 : d2;



        vector<point> fasie;

        for (unsigned i = 0; i < pointy.size(); i++) {

            if (pointy[i].x > midPoint.x - sqrt(dmin) and

                pointy[i].x < midPoint.x + sqrt(dmin))

                fasie.push_back(pointy[i]);





        }



        return get_min_strip(dmin, fasie);





    }

}



int main()

{

    int n;

    f >> n;

    vector<point> pointx(n), pointy(n);

    for (int i = 0; i < n; i++) {

        f >> pointx[i].x >> pointx[i].y;

        pointy[i] = pointx[i];

    }



    sort(pointx.begin(), pointx.end(), comparex);

    sort(pointy.begin(), pointy.end(), comparey);



    g << fixed << std::setprecision(8) << sqrt(distantaMinima(0, n - 1, pointx, pointy));

    return 0;

}
