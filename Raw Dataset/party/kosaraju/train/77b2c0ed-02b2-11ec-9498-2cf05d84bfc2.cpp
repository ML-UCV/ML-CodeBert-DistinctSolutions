# include <algorithm>
# include <cstdio>
# include <cstring>
# include <vector>
using namespace std;



const char *FIN = "party.in", *FOU = "party.out";

const int MAX = 215;



int N, M;

vector <int> GP[MAX], GM[MAX], Q;

bool VIZ[MAX], sol[MAX];



inline int NOT (int A) {

    return A > N ? A - N : A + N;

}



void dfp (int S) {

    VIZ[S] = 1;

    for (vector <int> :: iterator it = GP[S].begin (); it != GP[S].end (); ++it)

        if (VIZ[*it] == 0)

            dfp (*it);

    Q.push_back (S);

}



void dfm (int S) {

    VIZ[S] = sol[NOT(S)] = 1;

    for (vector <int> :: iterator it = GM[S].begin (); it != GM[S].end (); ++it)

        if (VIZ[*it] == 0)

            dfm (*it);

}



void baga (int x, int y) {

    GP[NOT (x)].push_back (y);

    GP[NOT (y)].push_back (x);

    GM[x].push_back (NOT (y));

    GM[y].push_back (NOT (x));

}



int main (void) {

    freopen (FIN, "r", stdin);



    scanf ("%d %d", &N, &M);

    for (int i = 1, x, y, z; i <= M; ++i) {

        scanf ("%d %d %d", &x, &y, &z);

        if (z == 0) baga (x, y);

        else if (z == 1) baga (x, NOT (y));

        else if (z == 2) baga (NOT (x), y);

        else baga (NOT (x), NOT (y));

    }

    for (int i = 1; i <= N << 1; ++i)

        if (VIZ[i] == 0)

            dfp (i);

    memset (VIZ, 0, sizeof (VIZ)), reverse (Q.begin (), Q.end ());

    for (vector <int> :: iterator it = Q.begin (); it != Q.end (); ++it)

        if (VIZ[*it] == 0 && VIZ[NOT (*it)] == 0)

            dfm (*it);

    Q.resize (0);

    for (int i = 1; i <= N; ++i)

        if (sol[i]) Q.push_back (i);



    freopen (FOU, "w", stdout);

    printf ("%d\n", Q.size ());

    for (size_t i = 0; i < Q.size (); ++i)

        printf ("%d\n", Q[i]);

}
