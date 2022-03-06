#include <fstream>




const int MAX_N = 30000;



using namespace std;



ifstream fin("schi.in");

ofstream fout("schi.out");



int n;

int v[MAX_N + 5], sol[MAX_N + 5], AIB[MAX_N + 5];



void update(int p, int x) {

    for(; p <= n; p += p&(-p))

        AIB[p] += x;

}



int bs(int x) {

    int i = 0;

    int p = (1 << 15);

    while(p > 0) {

        if((i + p <= n) && (AIB[i + p] < x)) {

            i += p;

            x -= AIB[i];

            if(x == 0)

                break;

        }

        p >>= 1;

    }

    return i + 1;

}



int main() {

    fin >> n;

    for(int i = 1; i <= n; i++) {

        fin >> v[i];

        update(i, 1);

    }



    for(int i = n; i >= 1; i--) {

        int ans = bs(v[i]);

        sol[ans] = i;

        update(ans, -1);

    }



    for(int i = 1; i <= n; i++)

        fout << sol[i] << '\n';

    return 0;

}
