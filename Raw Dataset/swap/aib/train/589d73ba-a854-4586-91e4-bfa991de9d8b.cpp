#include <cstdio>
#include <deque>
using namespace std;







char a[51002], b[51002];

int aib[51002], x[51002], nx, n;

deque< int > v[30];



void update(int, int) ;

int query(int) ;



int main()

{

    freopen("swap.in", "r", stdin);

    freopen("swap.out", "w", stdout);



    int i, p, ch, rez;



    fgets(a , 50001, stdin);

    fgets(b , 50001, stdin);



    for(n = 0, i = 1; a[i] != '\0'; ++i, ++n)

    {

        ch = a[i] - 'a';

        v[ch].push_back(i);

    }



    for(i = 1; i <= n; ++i)

 {

  ch = b[i] - 'a';

  if(v[ch].empty())

  {

   printf("-1\n");

   return 0;

  }



  x[++nx] = v[ch].front();

  v[ch].pop_front();

 }



    for (i = 1;i <= n;++i)

  update(i, 1);



 for (rez=0,i = 1;i <= n;++i)

 {

  update(x[i], -1);

  rez += query(x[i]);

 }



    printf("%d\n", rez);



    return 0;

}



void update(int p, int val)

{

    for(; p <= n; p += p & -p) aib[p] += val;

}



int query(int p)

{

    int rez;



    for(rez = 0; p > 0; p -= p & -p) rez += aib[p];



    return rez;

}
