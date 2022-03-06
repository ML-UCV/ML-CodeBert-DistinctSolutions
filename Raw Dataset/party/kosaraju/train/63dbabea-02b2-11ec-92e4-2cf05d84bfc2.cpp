#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;



const int MAX_N = 100005;



int n, m;

vector<int> G[2 * MAX_N], G2[2 * MAX_N];

int st[2 * MAX_N];

bool viz[2 * MAX_N];

bool value[2 * MAX_N], no_sol;



inline int neg(int val) { return val > n ? val - n : val + n; }



inline void add ( int x , int y )

{

    G [ x ].push_back ( y ) ;

    G2 [ y ].push_back ( x ) ;

}



void df(int nod) {

  viz[nod] = true;

  for (vector<int>::iterator it = G[nod].begin(); it != G[nod].end(); ++it)

    if (!viz[*it]) df(*it);

  st[++st[0]] = nod;

}



void df2(int nod) {

  if (value[nod]) no_sol = true;

  viz[nod] = true;

  value[neg(nod)] = true;

  for (vector<int>::iterator it = G2[nod].begin(); it != G2[nod].end(); ++it)

    if (!viz[*it]) df2(*it);

}





int main() {

  freopen("party.in", "r", stdin);

  freopen("party.out", "w", stdout);



  scanf("%d %d", &n, &m);

  for (int i = 0; i < m; ++i) {

    int x, y , c ;

    scanf("%d %d %d ", &x, &y, &c);





    if ( c == 0 )

    {

        add(neg(x),y);

        add(neg(y),x);

    }

    else if ( c == 1 )

    {

        add(neg(x),neg(y));

        add(y,x);

    }

    else if ( c == 2 )

    {

        add(x,y);

        add(neg(y),neg(x));

    }

    else {

        add(x,neg(y));

        add(y,neg(x));

    }

  }



  for (int i = 1; i <= 2*n; ++i)

    if (!viz[i]) df(i);

  memset(viz, false, sizeof(viz));

  for (int i = st [ 0 ] ; i; --i)

    if (!viz[st[i]] && !viz[neg(st[i])])

      df2(st[i]);



  int cate = 0 ;

    for (int i = 1; i <= n; ++i)

        if ( value [i] ) ++ cate ;

  printf ( "%d\n" , cate ) ;

  for (int i = 1; i <= n; ++i)

        if ( value [i] )

            printf("%d\n", i );

}
