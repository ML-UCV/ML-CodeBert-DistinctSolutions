#include <iostream>
#include <cstdio>


using namespace std;



const int NMAX = 25e4 + 5, MMAX = 20, BSIZE = (1 << 16);



int N, Q, T[NMAX];



int Ancestor[MMAX][NMAX];



int pos = BSIZE - 1;

char buff[BSIZE];



static inline char Char ()

{

    ++pos;



    if(pos == BSIZE)

    {

        pos = 0;



        fread(buff, 1, BSIZE, stdin);

    }



    return buff[pos];

}



static inline int Int ()

{

    int r = 0;



    for(;;)

    {

        char ch = Char();



        if(isdigit(ch))

        {

            r = (ch - '0');



            break;

        }

    }



    for(;;)

    {

        char ch = Char();



        if(isdigit(ch))

            r = r * 10 + (ch - '0');

        else

            break;

    }



    return r;

}



static inline void Read ()

{

    ios_base :: sync_with_stdio(false);

    cin.tie(NULL);



    freopen("stramosi.in", "r", stdin);

    freopen("stramosi.out", "w", stdout);



    N = Int();

    Q = Int();



    for(int i = 1; i <= N; ++i)

        T[i] = Int();



    return;

}



static inline void Precalculation ()

{

    for(int i = 1; i <= N; ++i)

        if(T[i])

            Ancestor[0][i] = T[i];



    for(int p = 1; (1 << p) <= N; ++p)

        for(int i = 1; i <= N; ++i)

            Ancestor[p][i] = Ancestor[p - 1][Ancestor[p - 1][i]];



    return;

}



static inline void Solve ()

{

    while(Q--)

    {

        int Node = 0, cnt = 0;



        Node = Int();

        cnt = Int();



        if(cnt == 0)

        {

            printf("%d\n", Node);



            continue;

        }



        if(T[Node] == 0)

        {

            printf("0\n");



            continue;

        }



        for(int p = 0; (1 << p) <= cnt; ++p)

            if(cnt & (1 << p))

                Node = Ancestor[p][Node];



        printf("%d\n", Node);

    }



    return;

}



int main()

{

    Read();



    Precalculation();



    Solve();



    return 0;

}
