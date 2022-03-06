#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int val[128], a[1024][2], n,m;



int main()

{

    freopen("party.in","r",stdin);

    freopen("party.out","w",stdout);



    srand(time(0));



    scanf("%d%d", &n,&m);



    for (int i=1;i<=n;++i) val[i] = 1;



    int x,y,op;



    for (int i=1;i<=m;++i)

    {

        scanf("%d%d%d", &x,&y,&op);



        if (op == 0) { a[i][0] = x; a[i][1] = y; } else

        if (op == 1) { a[i][0] = x; a[i][1] = -y; } else

        if (op == 2) { a[i][0] = -x; a[i][1] = y; } else

        if (op == 3) { a[i][0] = -x; a[i][1] = -y; }

    }



    int notOK=1;



    while (notOK)

    {

        notOK = 0;

        for (int i=1;i<=m;++i)

        {

            if (a[i][0] > 0) x = val[a[i][0]]; else x = !val[-a[i][0]];

            if (a[i][1] > 0) y = val[a[i][1]]; else y = !val[-a[i][1]];

            if (y == 0 && x == 0)

            {

               op = rand();

               if (op % 2 == 0)

               {

                   x = a[i][0];

                   if (x < 0) x = -x;

                   val[x] ^= 1;

               }

               else

               {

                   y = a[i][1];

                   if (y < 0) y = -y;

                   val[y] ^= 1;

               }

               notOK = 1;

            }

        }

    }



    int cnt=0;

    for (int i=1;i<=n;++i) cnt += val[i];



    printf("%d\n", cnt);



    for (int i=1;i<=n;++i) if (val[i]==1) printf("%d\n", i);



    return 0;

}
