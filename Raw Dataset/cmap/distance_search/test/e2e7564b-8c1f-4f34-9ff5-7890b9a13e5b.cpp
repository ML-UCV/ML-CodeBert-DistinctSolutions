#include <fstream>
#include <iomanip>
#include <set>
#include <vector>
#include <math.h>


int points;



typedef std::pair<double, double> point;

std::set<point> v;



void read();

void resolve();

double dist(const point, const point);



main(){

    read();

    resolve();



    return 0;

}



void read(){

    std::ifstream f("cmap.in");

    f>>points;

    int x, y;

    for (int i=0; i<points; i++)

    {

        f>>x>>y;

        v.insert(point(x,y));

    }

    f.close();

}

void resolve() {

    typedef std::set<point>::iterator iterable;

    double min_dist = dist(*v.begin(), *v.end());

    for (iterable i=v.begin(); i!=(--v.end()); i++)

    {

        iterable i2 = i;

        ++i2;

        double d = dist(*i, *i2);

        if (d<min_dist) min_dist = d;

    }

    for (iterable i=v.begin(); i!=(--v.end()); i++){

        iterable gt = v.upper_bound({i->first + min_dist, 0});

        iterable lt = v.lower_bound({i->first - min_dist, 0});

        for (iterable i2 = lt; i2!=gt; i2++){

            if (*i2!=*i) {

                double d = dist(*i, *i2);

                if (d<min_dist) min_dist = d;

            }



        }



    }

    std::ofstream f("cmap.out");



    f<<std::fixed<<std::setprecision(6)<<min_dist<<std::endl;

    f.close();

}



double dist(const point a, const point b){

    return sqrt((a.first - b.first)*(a.first - b.first) + (a.second - b.second)*(a.second- b.second));



}
