#include <fstream>
#include <vector>
using namespace std;

int n, m, nrsol;

vector <int> G[210], GT[210];

bool viz[210], sol[210];

int postordine[210], nrord;



inline int Not(int x)

{

 if(x <= n)

  return x + n;

 return x - n;

}



inline void Citire()

{

 int i, x, y, tip;

 ifstream fin("party.in");

 fin >> n >> m;

 for(i = 1; i <= m; ++i)

 {

  fin >> x >> y >> tip;

  if(tip == 0);

  else

  {

   if(tip == 1)

    y = Not(y);

   else

   {

    if(tip == 2)

     x = Not(x);

    else

    {

     x = Not(x);

     y = Not(y);

    }

   }

  }

  G[Not(x)].push_back(y);

  G[Not(y)].push_back(x);

  GT[x].push_back(Not(y));

  GT[y].push_back(Not(x));

 }

 fin.close();

}



inline void DFS(int x)

{

 viz[x] = true;

 vector <int>::iterator it;

 for(it = G[x].begin(); it != G[x].end(); ++it)

  if(!viz[*it])

   DFS(*it);

 postordine[++nrord] = x;

}



inline void DFST(int x)

{

 viz[x] = false;

 sol[Not(x)] = true;

 vector <int>::iterator it;

 for(it = GT[x].begin(); it != GT[x].end(); ++it)

  if(viz[*it])

   DFST(*it);

}



inline void Rezolvare()

{

 int i;

 for(i = 1; i <= 2 * n; ++i)

  if(!viz[i])

   DFS(i);

 for(i = 2 * n; i > 0; --i)

  if(viz[postordine[i]] && viz[Not(postordine[i])])

   DFST(postordine[i]);

 for(i = 1; i <= n; ++i)

  if(sol[i])

   nrsol++;

}



inline void Afisare()

{

 ofstream fout("party.out");

 fout << nrsol << "\n";

 for(int i = 1; i <= n; ++i)

  if(sol[i])

   fout << i << "\n";

 fout.close();

}



int main()

{

 Citire();

 Rezolvare();

 Afisare();

 return 0;

}
