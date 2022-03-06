#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;



const int MAX_N = 100005;



int n, m;

vector<int> G[2 * MAX_N], G2[2 * MAX_N];

int st[2 * MAX_N];

bool viz[2 * MAX_N];

bool ans[2 * MAX_N], sol = true;



inline int neg(int val) { return val > n ? val - n : val + n; }



inline void add_edge(int x, int y)

{

 G[x].push_back(y);

 G2[y].push_back(x);

}



void df(int nod)

{

    viz[nod] = true;

    vector <int> :: iterator it = G[nod].begin();

    while(it != G[nod].end())

    {

        if(!viz[*it]) df(*it);

        it++;

    }

    st[++st[0]] = nod;

}



void df2(int nod)

{

    if(ans[nod]) sol = false;

    viz[nod] = true;

    ans[neg(nod)] = true;

    vector <int> :: iterator it = G2[nod].begin();

    while(it != G2[nod].end())

    {

        if(!viz[*it]) df2(*it);

        it++;

    }

}



int main()

{

    freopen("party.in", "r", stdin);

    freopen("party.out", "w", stdout);

    scanf("%d %d", &n, &m);

    for(int i=0; i<m; i++)

    {

        int a, b, x;

        scanf("%d %d %d", &a, &b, &x);

        if(x == 0)

  {

   add_edge(neg(a), b);

   add_edge(neg(b), a);

  }

  else if(x == 1)

  {

   add_edge(neg(a), neg(b));

   add_edge(b, a);

  }

  else if(x == 2)

  {

   add_edge(a, b);

   add_edge(neg(b), neg(a));

  }

  else if(x == 3)

  {

   add_edge(a, neg(b));

   add_edge(b, neg(a));

  }

    }

    for(int i=1; i<=2*n; i++)

        if(!viz[i]) df(i);

    memset(viz, false, sizeof(viz));

    for(int i=2*n; i>=0; i--)

        if(!viz[st[i]] && !viz[neg(st[i])])

    df2(st[i]);

    if(!sol) printf("-1\n");

    else

 {

  int nr = 0;

  for(int i=1; i<=n; i++)

   if(ans[i]) nr++;

  printf("%d\n", nr);

  for(int i=1; i<=n; i++)

   if(ans[i]) printf("%d\n", i);

 }

}
