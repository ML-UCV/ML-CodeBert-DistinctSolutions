#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <iomanip>




using namespace std;



ifstream f("cmap.in");

ofstream g("cmap.out");



int n;



struct Punct {

    long long int x, y;

}p[120000];



long long int get_dist(Punct p1, Punct p2) {

    return ((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));

}



bool cmp_points_y(Punct p1, Punct p2) {

    return (p1.y < p2.y ? true: false);

}



long long int bin_search(int left, int right) {

    if (right - left <= 4) {

        long long int d_min = get_dist(p[left], p[left + 1]);

        for (int i = left; i <= right; ++i) {

            for (int j = i + 1; j <= right; ++j) {

                d_min = min(d_min, get_dist(p[i], p[j]));

            }

        }

        return d_min;

    }



    int mij = (left + right) / 2;

    long long int d_min_left = bin_search(left, mij);

    long long int d_min_right = bin_search(mij + 1, right);



    long long int d_min = min(d_min_left, d_min_right);

    int right_pointer = mij;

    int left_pointer = mij - 1;



    Punct *p_curent = new Punct[right - left + 1];

    int p_size = 0;



    while (left_pointer >= left) {

        if (abs(p[left_pointer].x - p[mij].x) < d_min) {

            p_curent[p_size].x = p[left_pointer].x;

            p_curent[p_size].y = p[left_pointer].y;

            p_size ++;

            left_pointer --;

        } else {

            break;

        }

    }

    while (right_pointer <= right) {

        if (abs(p[right_pointer].x - p[mij].x) < d_min) {

            p_curent[p_size].x = p[right_pointer].x;

            p_curent[p_size].y = p[right_pointer].y;

            p_size ++;

            right_pointer ++;

        } else {

            break;

        }

    }



    sort(p_curent, p_curent + p_size, cmp_points_y);

    for (int i = 0; i < p_size; ++i) {

        for (int j = 1; j < 9 && j + i < p_size; ++j) {

            d_min = min(d_min, get_dist(p_curent[i], p_curent[i + j]));

        }

    }



    delete[] p_curent;



    return d_min;



}



bool cmp_points_x(Punct p1, Punct p2) {

    return (p1.x < p2.x ? true: false);

}



int main() {



    f >> n;

    for (int i = 0; i < n; ++i) {

        f >> p[i].x >> p[i].y;

    }



    sort(p, p + n, cmp_points_x);



    long long int d_min = bin_search(0, n - 1);

    g << fixed << setprecision(7) << sqrt((double) d_min);



    return 0;

}
