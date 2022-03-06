#include <cstdio>
#include <vector>
#include <deque>
using namespace std;



int n, m;

int tata[427222];

int st[427222];

bool viz[427222];

vector< vector<int> > a;

vector< vector<int> > A;

vector< vector<int> > sol;

int q[427222];



int T[427222][3];

int t;

int poz[427222];



void citire()

{

  freopen("stramosi.in", "r", stdin);

  scanf("%d %d\n", &n, &m);

  int i;

  for(i=1;i<=n;i++) scanf("%d ", &tata[i]);

  A.reserve(n+1);

  a.reserve(n+1);

  sol.reserve(n+1);

  A.resize(n+1);

  a.resize(n+1);

  sol.resize(n+1);





  for(i=1;i<=m;i++)

    {

      int xx, yy;

      scanf("%d %d\n", &xx, &yy);

      q[xx]++;





      T[++t][1]=xx;

      T[t][2]=yy;

    }

  for(i=1;i<=n;i++)

    {

      a[i].reserve(q[i]);

      A[i].reserve(q[i]);

      sol[i].reserve(q[i]);

    }

  for(i=1;i<=m;i++) A[T[i][1]].push_back(T[i][2]);



  for(i=1;i<=n;i++) if(tata[i])a[tata[i]].push_back(i);



}

void dfs(int nod, int k)

{



  int i;

  st[k]=nod;

  viz[nod]=1;



  for(i=0;i<A[nod].size();i++)

    if(k-A[nod][i]<1) sol[nod].push_back(0);

    else sol[nod].push_back(st[k-A[nod][i]]);



  for(i=0;i<a[nod].size();i++)

    if(!viz[a[nod][i]])

      dfs(a[nod][i], k+1);

}







int main()

{

  int i, j;

  citire();

for(i=1;i<=n;i++) if(!tata[i]) dfs(i, 1);



freopen("stramosi.out", "w", stdout);

 for(i=1;i<=m;i++)

   {

     printf("%d\n", sol[T[i][1]][poz[T[i][1]]++]);

   }



  return 0;

}
