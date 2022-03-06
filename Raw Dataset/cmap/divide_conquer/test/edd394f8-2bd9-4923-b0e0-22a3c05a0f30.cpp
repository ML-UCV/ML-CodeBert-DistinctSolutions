#include <fstream>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <vector>
using namespace std;



ifstream fin("cmap.in");

ofstream fout("cmap.out");



const long long INF = 1LL * 2e18;



inline long long sqr(int x) {

    return 1LL * x * x;

}



class Point {



public:



    int x, y;



    Point(){}

    Point(int x, int y) {

        this->x = x;

        this->y = y;

    }



    friend istream& operator>> (istream& in, Point& a) {

        in >> a.x >> a.y;

    }



    friend bool operator< (const Point a, const Point b) {

        return a.x < b.x;

    }



    friend long long dist(const Point a, const Point b) {

        return sqr(a.x - b.x) + sqr(a.y - b.y);

    }

};



vector<Point> puncte, middlePoints, aux;
void customMerge(int st, int mid, int dr, int lineX, long long d) {



    int i = st, j = mid + 1;



    aux.clear();

    while (i <= mid && j <= dr) {



        if (puncte[i].y <= puncte[j].y) {



            if (1LL * lineX - puncte[i].x < d)

                middlePoints.push_back(puncte[i]);



            aux.push_back(puncte[i]);

            ++i;

        }

        else {



            if (1LL * puncte[j].x - lineX < d)

                middlePoints.push_back(puncte[j]);



            aux.push_back(puncte[j]);

            ++j;

        }

    }



    while (i <= mid) {



        if (1LL * lineX - puncte[i].x < d)

                middlePoints.push_back(puncte[i]);



        aux.push_back(puncte[i]);

        ++i;

    }



    while (j <= dr) {



        if (1LL * puncte[j].x - lineX < d)

            middlePoints.push_back(puncte[j]);



        aux.push_back(puncte[j]);

        ++j;

    }



    for (int i = st, j = 0; j < aux.size(); ++i, ++j) {

        puncte[i] = aux[j];

    }

}





long long closestPoints(int st, int dr) {





    if (st >= dr) {

        return INF;

    }



    if (st + 1 == dr) {



        if (puncte[st].y > puncte[dr].y)

            swap(puncte[st], puncte[dr]);



        return dist(puncte[st], puncte[dr]);

    }



    int mid = (st + dr) >> 1;





    long long d1 = closestPoints(st, mid);

    long long d2 = closestPoints(mid + 1, dr);

    long long d = min(d1, d2);





    customMerge(st, mid, dr, puncte[mid].x, d);





    for (int i = 0; i < middlePoints.size(); ++i) {

        int go = min(i + 8, (int)middlePoints.size() - 1);

        for (int j = i + 1; j <= go ; ++j) {

            d = min(d, dist(middlePoints[i], middlePoints[j]));

        }

    }

    middlePoints.clear();

    return d;

}



int main() {



    int n;





    fin >> n;

    puncte.resize(n);



    for (int i = 0; i < n; ++i) {

        fin >> puncte[i];

    }





    sort(puncte.begin(), puncte.end());





    fout << fixed << setprecision(7) << sqrt(closestPoints(0, n - 1));



    return 0;

}
