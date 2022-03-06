#include <bits/stdc++.h>
using namespace std;



ifstream in("inv.in");

ofstream out("inv.out");



const int max_size = 100000 + 1;



int ans;

vector <int> v(max_size), temp(max_size);



void interclasare(int s, int m, int d) {



    int i = s, j = m + 1, k = 0;



    while (i <= m && j <= d) {



        if (v[i] <= v[j])

            temp[k++] = v[i++];



        else {

            ans = (ans + m - i + 1) % 9917;

            temp[k++] = v[j++];

        }



    }



    while (i <= m)

        temp[k++] = v[i++];



    while (j <= d)

        temp[k++] = v[j++];



    for (k = s; k <= d; ++k)

        v[k] = temp[k - s];

}



void merge_sort(int s, int d) {

    if (s < d) {

        int m = (s + d) / 2;

        merge_sort(s, m);

        merge_sort(m + 1, d);

        interclasare(s, m, d);

    }

}



int main() {

    int N;

    in >> N;



    for (int i = 0; i < N; ++i)

        in >> v.at(i);



    merge_sort(0, N - 1);



    out << ans;



    return 0;

}
