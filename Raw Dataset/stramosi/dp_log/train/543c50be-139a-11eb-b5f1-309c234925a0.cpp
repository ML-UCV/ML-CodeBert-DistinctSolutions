#include <bits/stdc++.h>




using namespace std;



ifstream fin ("stramosi.in");

ofstream fout ("stramosi.out");



void usain_bolt()

{

    ios::sync_with_stdio(false);

    fin.tie(0);

}



const int N = 250005;



int dad[N][18];



int main()

{

    usain_bolt();



    int n, q;



    fin >> n >> q;

    for(int i = 1; i <= n; ++i) {

        fin >> dad[i][0];

    }

    for(int j = 1; j <= 17; ++j) {

        for(int i = 1; i <= n; ++i) {

            dad[i][j] = dad[dad[i][j - 1]][j - 1];

        }

    }

    while(q--) {

        int x, y;



        fin >> x >> y;



        int cnt = 0;



        while(y > 0) {

            if(y & 1) {

                x = dad[x][cnt];

            }

            y >>= 1, ++cnt;

        }

        fout << x << "\n";

    }

    return 0;

}
