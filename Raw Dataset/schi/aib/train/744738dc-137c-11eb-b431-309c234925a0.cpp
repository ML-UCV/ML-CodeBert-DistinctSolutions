#include <cstdio>
using namespace std;

const int NMAX = 30000;

int v[NMAX + 5] , aib[NMAX + 5] , ans[NMAX + 5] , n;

inline void update(int poz)

{

    for( ; poz <= n ; poz += (poz & (-poz)))

        aib[poz] --;

}

inline int query(int poz)

{

    int suma = 0;

    for( ; poz > 0 ; poz -= (poz & (-poz)))

        suma += aib[poz];

    return suma;

}

inline int bs(int st , int dr , int k)

{

    int last = 1000001;

    while(st <= dr)

    {

        int med = (st + dr) / 2;

        int aux = query(med);

        if(k == aux && med < last)

            last = med;

        if(k <= aux)

            dr = med - 1;

        else

            st = med + 1;

    }

    return last;

}

int main()

{

    freopen("schi.in" , "r" , stdin);

    freopen("schi.out" , "w" , stdout);

    int i;

    scanf("%d" , &n);

    for(i = 1 ; i <= n ; i ++)

    {

        scanf("%d" , &v[i]);

        aib[i] = (i & (-i));

    }

    for(i = n ; i >= 1 ; i --)

    {

        int poz = bs(1 , n ,v[i]);

        update(poz);

        ans[poz] = i;

    }

    for(i = 1 ; i <= n ; i ++)

        printf("%d\n" , ans[i]);

    return 0;

}
