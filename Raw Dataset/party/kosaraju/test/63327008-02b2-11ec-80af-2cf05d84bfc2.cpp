#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>


using namespace std;



const int N = 202;



vector <int> graph [N], graph2 [N];

stack <int> st;

bool used [N];

int n, value [N];



inline int no (const int &x) {

    if (x > n)

        return x - n;

    else return n + x;

}



void dfs (int x) {

    vector <int> :: iterator it;



    used [x] = 1;

    for (it = graph [x].begin (); it != graph [x].end (); ++ it)

        if (!used [*it])

            dfs (*it);

    st.push (x);

}



void dfs2 (int x) {

    vector <int> :: iterator it;



    used [x] = 1;

    value [no (x)] = 1;

    for (it = graph2 [x].begin (); it != graph2 [x].end (); ++ it)

        if (!used [*it])

            dfs2 (*it);

}



int main () {

    int i, a, b, m, ineg, c;

    vector <int> :: iterator it;



    freopen ("party.in", "r", stdin);

    freopen ("party.out", "w", stdout);



    scanf ("%d%d", &n, &m);

    for (i = 1; i <= m; i ++) {

        scanf ("%d%d%d", &a, &b, &c);

        if (c == 1)

            b = no (b);

        if (c == 2)

            a = no (a);

        if (c == 3) {

            a = no (a);

            b = no (b);

        }

        graph [no (a)].push_back (b);

        graph2 [b].push_back (no (a));

        graph [no (b)].push_back (a);

        graph2 [a].push_back (no (b));

    }

    for (i = 1; i <= 2 * n; i ++)

        if (!used [i])

            dfs (i);

    memset (used, 0, sizeof (used));

    while (!st.empty () ) {

        i = st.top ();

        ineg = no (i);

        st.pop ();

        if (!used [i] && !used [ineg]) {

            dfs2 (i);

        }

    }

    int ans = 0;

    for (i = 1; i <= n; i ++)

        ans += value [i];

    printf ("%d\n", ans);

    for (i = 1; i <= n; i ++)

        if (value [i])

            printf ("%d\n", i);

    printf ("\n");

    return 0;

}
