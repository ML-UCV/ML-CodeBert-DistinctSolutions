#include <bits/stdc++.h>
 using namespace std;

int N , x , y ;

int v[30005] , aib[30005] , sol[30005];

void Update (int poz ,int val)

{

    int i ;

     for (int i = poz ; i <= N ; i += (i & (-i) ))

        aib[i] += val;

     return ;

}

int suma (int poz)

{

    int i ;

    int sum = 0 ;

    for (int i = poz ; i >= 1 ; i -= (i & (-i) ))

        sum += aib[i] ;



    return sum ;

}

int BinarySearch (int st , int dr , int val)

{

    int Min = N + 1;

    while (st <= dr)

    {

        int mij = (st + (dr - st) / 2) ;

        int Sum = suma(mij);

        if (val == Sum && mij < Min) Min = mij;

        else if (val <= Sum) dr = mij - 1 ;

        else st = mij + 1 ;

    }



    return Min ;

}

int main()

{

    freopen("schi.in" , "r" , stdin) ;

    freopen("schi.out" , "w" , stdout) ;

    scanf ("%d" , &N) ;

    for (int i = 1 ; i <= N ; ++i)

    {

        scanf("%d" , &v[i]) ;

        aib[i] = (i & (-i) );

    }



        for (int i = N ; i >= 1 ; --i)

        {

            int conc = BinarySearch(1,N,v[i]) ;

            Update(conc,-1) ;



            sol[conc] = i ;

        }

    for (int i = 1 ; i <= N ; ++i) printf("%d\n", sol[i]) ;

    return 0 ;

}
