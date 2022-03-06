#include <stdio.h>
#include <string.h>
#include <vector>






using namespace std;



int T[2*(1<<16)], V[50666], N, X[30], Rez, P, Q, Cate;

char S1[50666], S2[50666];

vector<int> A[30];



void update(int p1, int p2, int nod)

{

        int mij;



        if (P <= p1 && p2 <= Q)

        {

                T[nod]++;

                return;

        }



        if ((p1 <= P && P <= p2) || (p1 <= Q && Q <= p2))

        {

                mij = (p1+p2)/2;

                update(p1, mij, 2*nod);

                update(mij+1, p2, 2*nod+1);

        }

}



void query(int x)

{

        int nod = (1<<16)+x;



        while (nod > 0)

        {

                Cate += T[nod];

                nod = nod>>1;

        }

}



int main()

{

        int i, n;



        freopen("swap.in", "r", stdin);

        freopen("swap.out", "w", stdout);



        fgets(S1, 50001, stdin);

        fgets(S2, 50001, stdin);



        n = strlen(S1);

        for (i = 0; i < n; i++)

            A[ S1[i]-'a' ].push_back(i);



        if (strlen(S1) != n) { printf("-1\n"); return 0; }



        for (i = 0; i < n; i++)

        {

            if ((A[ S2[i]-'a' ].size() == 0) || (A[ S2[i]-'a' ].size() == X[ S2[i]-'a' ]))

            { printf("-1\n"); return 0; }

            V[ A[ S2[i]-'a' ][ X[ S2[i]-'a' ]++ ] ] = i;

            i = i+1; i--;

        }



        for (i = 0; i < n; i++)

        {

                Cate = 0;

                query(V[i]);

                Rez += (V[i]-Cate);

                P = V[i]+1; Q = n;

                update(0, (1<<16)-1, 1);

        }



        printf("%d\n", Rez);

        return 0;



}
