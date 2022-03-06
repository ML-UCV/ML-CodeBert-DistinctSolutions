#include <fstream>
#include <cstring>


using namespace std;

ifstream fin("swap.in");

ofstream fout("swap.out");



int L[26][50010];

int F[26], G[26], P[50010];

int AIB[50010];

char A[50010], B[50010];



int n, i, j;

long long sol;



int query(int p) {

    int r = 0;

    for (;p;p -= (p&-p))

        r += AIB[p];

    return r;

}



void update(int p) {

    for (;p<=n;p += (p&-p))

        AIB[p]++;

}



int main() {

    fin>>A+1;

    fin>>B+1;

    n = strlen(A+1);

    for (i=1;i<=n;i++) {

        A[i] -= 'a';

        B[i] -= 'a';

    }



    for (i=1;i<=n;i++) {

        F[A[i]]++;

        L[ A[i] ][ F[A[i]] ] = i;

    }



    for (i=1;i<=n;i++) {

        G[ B[i] ]++;

        P[ L[ B[i] ][ G[ B[i] ] ] ] = i;

    }



    for (i=0;i<26;i++) {

        if (F[i] != G[i]) {

            fout<<-1;

            return 0;

        }

    }



    for (i=1;i<=n;i++)

        P[i] = n-P[i]+1;



    for (i=1;i<=n;i++) {

        sol += query(P[i]);

        update(P[i]);

    }



    fout<<sol<<"\n";



    return 0;

}
