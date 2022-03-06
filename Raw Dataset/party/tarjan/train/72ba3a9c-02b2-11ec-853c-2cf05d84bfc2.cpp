#include <stdio.h>
#include <stdlib.h>
#include <time.h>


bool sol[115];



struct relation

{

    int x, y, type;

} x[1024];



bool bad(relation A)

{

    if (A.type == 0 && sol[A.x] == 0 && sol[A.y] == 0)

        return true;

    if (A.type == 1 && sol[A.x] == 0 && sol[A.y] == 1)

        return true;

    if (A.type == 2 && sol[A.x] == 1 && sol[A.y] == 0)

        return true;

    if (A.type == 3 && sol[A.x] == 1 && sol[A.y] == 1)

        return true;

    return false;

}



int main()

{

    int i, N, M, cnt = 0;



    freopen("party.in", "r", stdin);

    freopen("party.out", "w", stdout);



    srand(time(0));



    scanf("%d%d", &N, &M);

    for (i = 1; i <= M; i ++)

        scanf("%d%d%d", &x[i].x, &x[i].y, &x[i].type);



    bool isSolution;



    do

    {

        isSolution = true;

        for (i = 1; i <= M; i ++)

            if (bad(x[i]))

            {

                int X = x[i].x, Y = x[i].y;

                int which = rand() % 2;

                if (which == 0)

                {

                    cnt = cnt - sol[X];

                    sol[X] = 1 - sol[X];

                    cnt = cnt + sol[X];

                }

                else

                {

                    cnt = cnt - sol[Y];

                    sol[Y] = 1 - sol[Y];

                    cnt = cnt + sol[Y];

                }

                isSolution = false;

                break;

            }



        if (cnt == 0 && isSolution == true)

        {

            sol[rand() % N + 1] = 1; cnt ++;

            isSolution = false;

        }

    }

    while (isSolution == false);



    printf("%d\n", cnt);

    for (i = 1; i <= N; i ++)

        if (sol[i])

            printf("%d\n", i);



    return 0;

}
