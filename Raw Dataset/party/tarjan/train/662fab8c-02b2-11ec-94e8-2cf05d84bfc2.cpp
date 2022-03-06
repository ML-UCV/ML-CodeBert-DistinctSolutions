#include<cstdio>
#include<fstream>
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<bitset>
#include<deque>
#include<queue>
#include<set>
#include<map>
#include<cmath>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include<unordered_map>
using namespace std;



const int nmax = 105;

const int mmax = 1005;



int n, m, i, ok, s, sol[nmax];



struct propozitie

{

    int x, y, z;

};

propozitie a[mmax];



bool valid()

{

    for(i = 1; i <= m; i++)

    {

        if(a[i].z == 0)

            ok = sol[a[i].x] | sol[a[i].y];

        else if(a[i].z == 1)

            ok = sol[a[i].x] | !sol[a[i].y];

        else if(a[i].z == 2)

            ok = !sol[a[i].x] | sol[a[i].y];

        else

            ok = !sol[a[i].x] | !sol[a[i].y];



        if(!ok)

        {

            int mlc = rand() % 2;



            if(!mlc) sol[a[i].x] = !sol[a[i].x];

            else sol[a[i].y] = !sol[a[i].y];



            return 0;

        }

    }



    return 1;

}



int main()

{

    freopen("party.in", "r", stdin);

    freopen("party.out", "w", stdout);



    srand(time(0));



    scanf("%d%d", &n, &m);



    for(i = 1; i <= m; i++)

        scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].z);



    for(i = 1; i <= n; i++)

        sol[i] = rand() % 2;



    while(!valid());



    for(i = 1; i <= n; i++)

        s += sol[i];



    printf("%d\n", s);

    for(i = 1; i <= n; i++)

        if(sol[i])

            printf("%d\n", i);



    return 0;

}
