#include <stdio.h>
#include <stdlib.h>
#include <time.h>




int a[1005][2],viz[105];

int n,m,nrt;

void read ()

{

    int i,x,y,op;

    scanf ("%d%d",&n,&m);

    for (i=1; i<=m; ++i)

 {

        scanf ("%d%d%d",&x,&y,&op);

        if (!op)

        {

            a[i][0]=x;

            a[i][1]=y;

        }

  else if (op==1)

        {

            a[i][0]=x;

            a[i][1]=-y;

        }

        else if (op==2)

        {

            a[i][0]=-x;

            a[i][1]=y;

        }

        else if (op == 3)

        {

            a[i][0]=-x;

            a[i][1]=-y;

        }

    }

}

void solve ()

{

 int i,ok,x,y,op;

 for (i=1; i<=n; ++i)

  viz[i]=1;

 for (ok=1; ok; )

 {

  ok=0;

        for (i=1; i<=m; ++i)

        {

            if (a[i][0]>0)

                x=viz[a[i][0]];

            else

                x=!viz[-a[i][0]];

            if (a[i][1]>0)

                y=viz[a[i][1]];

            else

                y=!viz[-a[i][1]];

            if (!x && !y)

            {

                op = rand();

                if (op%2==0)

                {

                    x=a[i][0];

                    if (x<0)

                        x=-x;

                    viz[x]^=1;

               }

               else

               {

                   y=a[i][1];

                   if (y<0)

                    y=-y;

                   viz[y]^=1;

               }

               ok=1;

            }

        }

    }

    for (i=1; i<=n; ++i)

        if (viz[i])

            ++nrt;

}

void print ()

{

    int i;

    printf ("%d\n",nrt);

    for (i=1; i<=n; ++i)

        if (viz[i])

            printf ("%d\n",i);

}

int main ()

{

    freopen ("party.in","r",stdin);

    freopen ("party.out","w",stdout);

    srand (time (0));

    read ();

    solve ();

    print ();

    return 0;

}
