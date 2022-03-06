#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <climits>


using namespace std;



ifstream in("cmap.in");

ofstream out("cmap.out");



struct punct {

    int x, y;

};



bool cmp(punct &A, punct &B) {

    if (A.x == B.x)

        return A.y < B.y;

    return A.x < B.x;

}



long long int dist(punct &A, punct &B) {

    return 1ll * (A.x - B.x) * (A.x - B.x) + 1ll *(A.y - B.y) * (A.y - B.y);

}



void interclaseaza(vector <punct> &p, int st, int m, int dr) {

    vector <punct> aux;

    int i = st, j = m + 1;

    while (i <= m && j <= dr) {

        if (p[i].y < p[j].y) {

            aux.push_back(p[i]);

            i++;

        }

        else {

            aux.push_back(p[j]);

            j++;

        }

    }



    while (i <= m) {

        aux.push_back(p[i]);

        i++;

    }

    while (j <= dr) {

        aux.push_back(p[j]);

        j++;

    }



    for (int i = st; i <= dr; i++) {

        p[i] = aux[i - st];

    }

}



long long int find_dist(vector <punct> &p, int st, int dr) {

    if (dr - st <= 2) {

        long long int d = LLONG_MAX;

        for (int i = st; i <= dr; i++) {

            for (int j = i + 1; j <= dr; j++) {

                d = min(d, dist(p[i], p[j]));

            }

        }

        for (int i = st; i <= dr; i++) {

            for (int j = i + 1; j <= dr; j++) {

                if (p[i].y > p[j].y)

                    swap(p[i], p[j]);

            }

        }

        return d;

    }



    int m = st + (dr - st) / 2;

    punct pmid = p[m];

    long long int d1 = find_dist(p, st, m);

    long long int d2 = find_dist(p, m + 1, dr);

    long long int d = min(d1, d2);





    interclaseaza(p, st, m, dr);



    vector <punct> banda;

    for (int i = st; i <= dr; i++) {

        if (1ll * (p[i].x - pmid.x) * (p[i].x - pmid.x) < d) {

            banda.push_back(p[i]);

        }

    }



    for (unsigned int i = 0; i < banda.size(); i++) {

        for (unsigned int j = i + 1; j < banda.size() && j - i <= 7; j++) {

            d = min(d, dist(banda[i], banda[j]));

        }

    }



    return d;

}



int main() {

    int n;

    in >> n;

    vector <punct> p(n);

    for (int i = 0; i < n; i++) {

        in >> p[i].x >> p[i].y;

    }



    sort(p.begin(), p.end(), cmp);



    out << fixed << setprecision(10) << sqrt(find_dist(p, 0, n - 1));

    return 0;

}
