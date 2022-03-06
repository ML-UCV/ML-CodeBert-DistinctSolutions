#include <fstream>
#include <cstring>
#include <vector>


using namespace std;



ifstream f ("strmatch.in");

ofstream g ("strmatch.out");



constexpr int NMAX = 2e6 + 5;



char a[2*NMAX+5];

char b[NMAX+5];



int phi[2*NMAX+5];



int K, N;



void Read () {

    f.getline(a, NMAX);

    f.getline(b, NMAX);

    K = strlen(a);

    strcat(a, "#");

    strcat(a, b);

    N = strlen(a);

}



void Construiesc_KMP () {

    int rez = 0;

    for (int i = 1; i < N; ++ i ) {

        while (rez > 0 && a[ rez ] != a[ i ]) {

            rez = phi[ rez - 1 ];

        }

        if (a[ rez ] == a[ i ]) ++ rez;

        phi[ i ] = rez;

    }

}



int main ()

{

    Read();

    Construiesc_KMP();



    vector <int> ind;

    for (int i = K + 1; i < N; ++ i ) {

        if (phi[ i ] == K) ind.push_back(i-K-K);

    }



    g << ind.size() << '\n';

    for (int i = 0; i < min((int)ind.size(), 1000); ++i)

        g << ind[ i ] << " ";



    return 0;

}
