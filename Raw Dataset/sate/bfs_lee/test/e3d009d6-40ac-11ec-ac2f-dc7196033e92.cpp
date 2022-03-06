#include <fstream>
#include <queue>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;
ifstream fin("sate.in");
ofstream fout("sate.out");
const int NMAX = 30000;
long long viz[NMAX+5];
struct muchie
{
   int nod, cost;
};
vector <muchie> G[NMAX+5];
queue <int>q;
string sir;
void bfs(int nod, int finish)
{
   q.push(nod);
   muchie aux;
   viz[nod] =0;
   while(!q.empty())
   {
      nod = q.front();
      q.pop();
      for(int i =0; i<G[nod].size();i++)
      {
         aux = G[nod][i];
         if(viz[aux.nod] == -1)
         {
            viz[aux.nod] = viz[nod] + aux.cost;
            if(aux.nod == finish)
               return;
            q.push(aux.nod);

         }
      }
   }
}
int main()
{
   int n, m, x, y, c, start, finish, i;
   muchie aux;
   ///Pentru 100 de puncte trebuie facuta parsare, altfel punctajul va fi de 80;
   ///de asemena se poate face o implemenatre de 100 de puncte fara parsare, insa cu o cada scrisa de mana
   ///cod fara parsare

  /* fin>>n>>m>>start>>finish;
   for(i =1;i<=n;i++)
     viz[i] = -1;
   for(i=1;i<=m;i++)
   {
      fin>>x>>y>>c;
      aux.nod = y;
      aux.cost = c;
      G[x].push_back(aux);
      aux.nod = x;
      aux.cost = -c;
      G[y].push_back(aux);
   }
   bfs(start, finish);
   fout<<viz[finish]<<"\n";*/
   ///cod cu parsare

   getline(fin, sir);
   n =-1;
   m = -1;
   start = -1;
   finish = -1;
   for(i=0;i<sir.size();i++)
   {
     if(sir[i]>='0' and sir[i]<='9')
     {
        int nr = 0;
        for(int j = i; j<sir.size();j++)
        {
           if(sir[j]>='0' and sir[j]<='9')
            nr = nr * 10 + (sir[j]- '0');
           else
           {
              i = j;
              break;
           }
        }
        if(n == -1)
        {
           n = nr;
           continue;
         }
         if(m == -1)
         {
            m = nr;
            continue;
         }
         if(start == -1)
         {
            start = nr;
            continue;
         }
         if(finish == -1)
         {
            finish = nr;
            continue;
         }
     }
   }
    for(i =1;i<=n;i++)
     viz[i] = -1;
   ///Citim muchiile
   for(int k = 1; k<=m;k++)
   {
       getline(fin, sir);
       x =-1;
       y = -1;
       c = -1;
       ///citirea datalor de pe acel rand
       for(i=0;i<sir.size();i++)
       {
          if(sir[i]>='0' and sir[i]<='9')
          {
           int nr = 0;
           for(int j = i; j<sir.size();j++)
           {
            if(sir[j]>='0' and sir[j]<='9')
             nr = nr * 10 + (sir[j]- '0');
            else
            {
               i = j;
               break;
            }
           }
           if(x == -1)
           {
              x = nr;
              continue;
           }
           if(y == -1)
           {
              y = nr;
              continue;
           }
           if(c == -1)
           {
             c = nr;
             continue;
           }
          }
        }
        ///introducerea datelor in graf
        aux.nod = y;
        aux.cost =c;
        G[x].push_back(aux);
        aux.nod = x;
        aux.cost = -c;
        G[y].push_back(aux);
   }
   bfs(start, finish);
   fout<<viz[finish]<<"\n";



    return 0;
}
