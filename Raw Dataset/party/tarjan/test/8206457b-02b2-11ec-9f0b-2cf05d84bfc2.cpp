#include <stdio.h>
#include <string.h>
#include <vector>


using namespace std;
int N, M, P[1005][2], x[105];

int q[105], ql, qr, uz[105];

vector<int> G[105];



int modul(int x)

{ if (x < 0) return -x; return x; }



int check(int prop)

{

    int v1 = (P[prop][0] > 0) ? (x[P[prop][0]]) : ((x[-P[prop][0]] == -1) ? (-1) : (!x[-P[prop][0]])), v2 = (P[prop][1] > 0) ? (x[P[prop][1]]) : ((x[-P[prop][1]] == -1) ? (-1) : (!x[-P[prop][1]]));



    if (v1 == -1 && !v2)

    {

        (P[prop][0] > 0) ? (x[P[prop][0]] = 1) : (x[-P[prop][0]] = 0);

        q[++ql] = modul(P[prop][0]);

    }

    else if (!v1 && v2 == -1)

    {

        (P[prop][1] > 0) ? (x[P[prop][1]] = 1) : (x[-P[prop][1]] = 0);

        q[++ql] = modul(P[prop][1]);

    }

    else if (v1 == -1 && v2 == -1)

        return 1;

    else if (v1 != -1 && v2 != -1)

        return v1 || v2;



    return 1;

}



int BF(int start)

{

    int sz, ok = 1, el, i, j;



    for (q[ql=qr=0] = start, uz[start] = 1; qr <= ql && ok; qr++)

        for (el = q[qr], sz = G[el].size(), i = 0; i < sz && ok; i++)

        {

            j = G[el][i];

            ok = check(j);

        }



    for (i = 0; i <= ql; i++)

        (!ok) ? (x[q[i]] = -1) : (0),

        uz[q[i]] = 0,

        q[i] = 0;



    return ok;

}



int main(void)

{

    int i, j, u, v, t;



    freopen("party.in", "r", stdin);

    freopen("party.out", "w", stdout);



    scanf("%d %d", &N, &M);

    for (i = 1; i <= M; i++)

    {

        scanf("%d %d %d", &u, &v, &t);

        G[u].push_back(i);

        G[v].push_back(i);

        P[i][0] = u; P[i][1] = v;



        if (t == 1)

            P[i][1] *= (-1);

        else if (t == 2)

            P[i][0] *= (-1);

        else if (t == 3)

            P[i][0] *= (-1), P[i][1] *= (-1);

    }



    memset(x, -1, sizeof(x));

    for (i = 1, j = 0; i <= N; i++)

        if (x[i] == -1)

        {

            x[i] = 0;

            j = BF(i);

            if (!j)

            {

                x[i] = 1;

                j = BF(i);

            }

        }



    for (j = 0, i = 1; i <= N; i++)

        j += (x[i] == 1);



    printf("%d\n", j);

    for (i = 1; i <= N; i++)

        if (x[i])

            printf("%d\n", i);



    return 0;

}
