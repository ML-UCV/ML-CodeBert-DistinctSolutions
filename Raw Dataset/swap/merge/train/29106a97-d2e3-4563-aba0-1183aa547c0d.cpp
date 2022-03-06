#include <stdio.h>
#include <string.h>
#include <algorithm>


using namespace std;



typedef struct punct {int s; int p; int s2; int p2;} point;







int n, i, dp, k;

long long sol;

point x[60010], y[60010], z[60010];

int ai[4*60010], sl[60010];

char a[60010], b[60010];



int operator<(const point &c, const point &d)



{

 if (!dp)

    {

    if (c.s != d.s)

  return c.s < d.s;

    else

     return c.p < d.p;

    }

    else

    return c.p < d.p;

}



void ins(int nod, int nr, int l, int r)



{

 int mid = (l + r)/2;



    if (nr <=r && nr >=l && (l<=r))

    {

        ai[nod]++;

        if (nr > mid)

         ins(2*nod+1, nr, mid+1, r);

        else

        if (l != r)

         ins(2*nod, nr, l, mid);

    }



}



int find(int nod, int a, int b, int l, int r)



{

    int mid = (l+r)/2;



    if (a==l && b==r)

     return ai[nod];



    if (a >=l && b<=r)

    {

        if (a<=mid && b>=mid+1)

        {

            return (find(2*nod, a, mid, l, mid) + find(2*nod+1, mid+1, b, mid+1, r));

        }

        else

        if (a<=mid && b<=mid)

         return (find(2*nod, a, b, l, mid));

        else

        if (a>=mid+1 && b>=mid+1)

         return (find(2*nod+1, a, b, mid+1, r));



    }





}





void read()



{





 scanf("%s\n%s ", a, b);

}





void solve()



{

    n = strlen(a);
    for (i=0; i<n; i++)

    {

     x[i].s = a[i];

        y[i].s = b[i];

        x[i].p = i;

        y[i].p = i;

    }



    dp = 0;

    sort(x, x+n);

    sort(y, y+n);
    sol = 0;



    for (i=0; i<n; i++)

    {

     z[i].s2 = x[i].s;

        z[i].p2 = x[i].p;

        z[i].s = y[i].s;

        z[i].p = y[i].p;

     if (x[i].s != y[i].s)

        {

         i = n;

            sol = -1;

        }

    }



    if (sol == 0)

    {

     dp = 1;

        sort(z, z+n);
        sl[0] = abs(z[0].p - z[0].p2);



        if (z[0].p2 > 0)

         ins(1, z[0].p2-1, 0, n-1);



        sol+=sl[0];



        for (i=1; i<n; i++)

        {

            sl[i] = z[i].p2 - i + find(1, z[i].p2, n-1, 0, n-1);

            if (z[i].p2>0)

             ins(1, z[i].p2-1, 0, n-1);

            sol+=sl[i];

        }
    }



}





void write()



{

    printf("%lld\n", sol);

}





int main()



{

    freopen("swap.in", "r", stdin);

    freopen("swap.out","w",stdout);



    read();

    solve();

    write();



    fclose(stdin);

    fclose(stdout);



 return 0;

}
