#include<cstdio>
#include<vector>


using namespace std;



int M, n_ans, ans[109];



class SAT

{

    public:



    int n_Q, n_componente, N, sol[209], ap[209], Q[209];

    vector < int > v[209], h[209];



    int cod (int v)

    {

        if (v < 0) return N - v;

        return v;

    }



    int opus (int x)

    {

        if (x<=N) return N + x;

        return x - N;

    }



    void Add_Implication (int x, int y)

    {

        v [ cod ( x ) ] . push_back ( cod ( y ) );

        h [ cod ( y ) ] . push_back ( cod ( x ) );

    }



    void Add_Clauza (int x, int y)

    {

        Add_Implication (-x, y);

        Add_Implication (-y, x);

    }



    void dfs (int nod)

    {

        ap[nod] = 1;

        for (vector < int > :: iterator it = v[nod].begin(); it != v[nod].end(); it++)

            if (ap[*it] == 0)

                dfs (*it);

        Q[++n_Q] = nod;

    }



    void dfp (int nod)

    {

        if (sol[nod])

        {

            sol[0] = -1;

            return ;

        }



        ap[nod] = 0;

        sol[opus(nod)] = 1;

        for (vector < int > :: iterator it = h[nod].begin(); it != h[nod].end(); it++)

            if (ap[*it] == 1)

                dfp (*it);

    }



    int solve ()

    {

        for (int i=1; i<=2*N; i++)

            if (ap[i] == 0)

                dfs (i);



        for (int i=n_Q; i>=1; i--)

            if (ap[Q[i]] && ap[opus(Q[i])])

                dfp (Q[i]);



        return sol[0];

    }

}sistem;



int main()

{

freopen ("party.in", "r", stdin);

freopen ("party.out", "w", stdout);



scanf ("%d %d", &sistem.N, &M);

for (int i=1; i<=M; i++)

{

    int X, Y, tip;

    scanf ("%d %d %d", &X, &Y, &tip);

    if (tip == 0) sistem . Add_Clauza (X, Y);

    else

    if (tip == 1) sistem . Add_Clauza (-Y, X);

    else

    if (tip == 2) sistem . Add_Clauza (-X, Y);

    else sistem . Add_Clauza (-X, -Y);

}



sistem.solve();



for (int i=1; i<=sistem.N; i++)

    if (sistem.sol[i])

        ans[++n_ans] = i;



printf ("%d\n", n_ans);

for (int i=1; i<=n_ans; i++)

    printf ("%d\n", ans[i]);



return 0;

}
