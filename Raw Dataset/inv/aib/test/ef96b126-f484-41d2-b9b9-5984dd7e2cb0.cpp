#include <bits/stdc++.h>


using namespace std;

ifstream f ("inv.in") ;

ofstream g ("inv.out") ;

int N , x , a , b , inversiune , sol[100005];

int AIB[100005];

int solutie;

struct normalize

{

    int val;

    int poz;

}v[100005];

bool cmp (normalize a , normalize b)

{

    if (a.val == b.val) return (a.poz < b.poz);

    return (a.val < b.val) ;

}

void Update (int poz , int val)

{

    for (int i = poz ; i <= N ; i += i & (-i))

        AIB[i] += val;



    return;

}

int Query (int poz)

{

    int sum = 0 ;

    for (int i = poz ; i >= 1 ; i -= i & (-i))

        sum += AIB[i] ;

    return sum ;

}

int main()

{

    f >> N ;

    for (int i = 1 ; i <= N ; ++i)

    {

        f >> v[i].val;

        v[i].poz = i ;

    }

    sort (v + 1 , v + N + 1 , cmp) ;



    for (int i = 1 ; i <= N ; ++i)

        sol[v[i].poz] = i ;







    for (int i = 1 ; i <= N ; ++i)

    {

        x = sol[i] ;

        inversiune = Query(N) - Query(x) ;

        solutie = (solutie + inversiune) % 9917;



        Update(x,1) ;

    }

    g << solutie ;

    f.close();

    g.close();

    return 0;

}
