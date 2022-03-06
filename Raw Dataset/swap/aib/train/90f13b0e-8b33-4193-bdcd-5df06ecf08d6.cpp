#include <fstream>
#include <list>
#include <cstring>
using namespace std;



ifstream f("swap.in");

ofstream g("swap.out");



list<int> L[26];



int n;



int sol;



int A[50005];



char s1[50005], s2[50005];



void update(int p) {

    for (int i=p; i<=n; i+=(i&(-i))) {

        ++A[i];

    }

}



void query(int p) {

    for (int i=p; i>0; i-=(i&(-i))) {

        sol += A[i];

    }

}



int main () {

    f >> s1+1;

    f >> s2+1;

    n = strlen(s1+1);

    for (int i=1; i<=n; ++i) {

        L[s1[i] - 'a'].push_back(i);

    }

    for (int i=1; i<=n; ++i) {

        if (L[s2[i]-'a'].empty()) {

            g <<-1;

            return 0;

        }

        int p = *L[s2[i] - 'a'].begin();

        L[s2[i] - 'a'].pop_front();

        query(p);

        update(p);

    }

    g << 1LL*n*(n-1)/2 - sol;

    return 0;

}
