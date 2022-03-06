#include <bits/stdc++.h>




using namespace std;

ifstream f ("apm.in") ;

ofstream g ("apm.out") ;

int T[200005] , h[200005] ;

struct solutie

{

    int st;

    int dr;

}v[200005];

int N , M , x ,y ,cost = 0;

int cnt = 0 , k = 0 ;

struct didi

{

    int a;

    int b;

    int c;

}mch[400005];

bool cmp (didi a , didi b)

{

    return (a.c < b.c) ;

}

int TATA (int x)

{

    if (x != T[x]) return TATA(T[x]) ;

    return x;

}

int muchie (int x , int y)

{

    int r1 = TATA(x) ;

    int r2 = TATA(y) ;



    if (r1 == r2) return 0 ;

    else

    {

        if (h[r1] < h[r2]) T[r1] = r2;

        else if (h[r1] > h[r2]) T[r2] = r1;

        else

        {

            T[r2] = r1;

            h[r1] ++ ;

        }



        return 1;

    }

}

void KRUSKAL()

{

     k = 1;

    while (cnt < N - 1 && k <= M)

    {

        x = mch[k].a;

        y = mch[k].b;

        if (muchie(x,y))

        {

            cost += mch[k].c ;

            cnt ++ ;

            v[cnt].st = x;

            v[cnt].dr = y;

        }



        k ++ ;

    }

}

int main()

{

    f >> N >> M ;

    for (int i = 1 ; i <= M ; ++i)

        f >> mch[i].a >> mch[i].b >> mch[i].c;



    sort(mch+1,mch+M+1,cmp) ;

    for (int i = 1; i <= N ; ++i) T[i] = i , h[i] = 1;



    KRUSKAL();



    g << cost << '\n' ;

    g << N - 1 << '\n' ;

    for (int i = 1 ; i <= cnt ; ++i)

        g << v[i].st << ' ' << v[i].dr << '\n' ;



    f.close();

    g.close();

    return 0 ;

}
