#include <cstdio>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <utility>

using namespace std;

int N, M;
pair<int, int> term[1002];
int type[1002];

bool go[102], sett[102];
bool newgo[102], newset[102];

int main()
{
 ifstream fin("party.in");
 ofstream fout("party.out");

 fin >> N >> M;
 for (int i = 1; i <= M; ++i)
  fin >> term[i].first >> term[i].second >> type[i];

 for (int i = 1; i <= N; ++i)
  if (!sett[i])
  {
   sett[i] = true, go[i] = true;



   memcpy(newgo, go, sizeof(newgo));
   memcpy(newset, sett, sizeof(newset));

   bool ok = true, valid = true;
   while (ok && valid)
   {
    ok = false;
    for (int j = 1; j <= M; ++j)
     if (newset[term[j].first] ^ newset[term[j].second])
     {
      int f1 = term[j].first, f2 = term[j].second;

      if (newset[f1])
      {
       if (!newgo[f1])
        if (type[j] == 0 || type[j] == 1)
        {
         newset[f2] = true;
         if (type[j] == 0)
          newgo[f2] = true;
         else if (type[j] == 1)
          newgo[f2] = false;

         ok = true;
        }
       if (newgo[f1])
        if (type[j] == 2 || type[j] == 3)
        {
         newset[f2] = true;
         if (type[j] == 2)
          newgo[f2] = true;
         else if (type[j] == 3)
          newgo[f2] = false;

         ok = true;
        }
      }
      else
      {
       swap(f1, f2);
       if (!newgo[f1])
        if (type[j] == 0 || type[j] == 2)
        {
         newset[f2] = true;
         if (type[j] == 0)
          newgo[f2] = true;
         else if (type[j] == 2)
          newgo[f2] = false;

         ok = true;
        }
       if (newgo[f1])
        if (type[j] == 1 || type[j] == 3)
        {
         newset[f2] = true;
         if (type[j] == 1)
          newgo[f2] = true;
         else if (type[j] == 3)
          newgo[f2] = false;

         ok = true;
        }
      }
     }
     else if (newset[term[j].first] && newset[term[j].second])
     {
      if (type[j] == 0 && !newgo[term[j].first] && !newgo[term[j].second]) valid = false;
      if (type[j] == 1 && !newgo[term[j].first] && newgo[term[j].second]) valid = false;
      if (type[j] == 2 && newgo[term[j].first] && !newgo[term[j].second]) valid = false;
      if (type[j] == 3 && newgo[term[j].first] && newgo[term[j].second]) valid = false;
     }
   }

   if (valid)
   {
    memcpy(go, newgo, sizeof(go));
    memcpy(sett, newset, sizeof(sett));
   }
   else
    go[i] = false;

   ok = true;
   while (ok)
   {
    ok = false;
    for (int j = 1; j <= M; ++j)
     if (newset[term[j].first] ^ newset[term[j].second])
     {
      int f1 = term[j].first, f2 = term[j].second;

      if (newset[f1])
      {
       if (!newgo[f1])
        if (type[j] == 0 || type[j] == 1)
        {
         newset[f2] = true;
         if (type[j] == 0)
          newgo[f2] = true;
         else if (type[j] == 1)
          newgo[f2] = false;

         ok = true;
        }
       if (newgo[f1])
        if (type[j] == 2 || type[j] == 3)
        {
         newset[f2] = true;
         if (type[j] == 2)
          newgo[f2] = true;
         else if (type[j] == 3)
          newgo[f2] = false;

         ok = true;
        }
      }
      else
      {
       swap(f1, f2);
       if (!newgo[f1])
        if (type[j] == 0 || type[j] == 2)
        {
         newset[f2] = true;
         if (type[j] == 0)
          newgo[f2] = true;
         else if (type[j] == 2)
          newgo[f2] = false;

         ok = true;
        }
       if (newgo[f1])
        if (type[j] == 1 || type[j] == 3)
        {
         newset[f2] = true;
         if (type[j] == 1)
          newgo[f2] = true;
         else if (type[j] == 3)
          newgo[f2] = false;

         ok = true;
        }
      }
     }
   }
  }

 int result = 0;
 for (int i = 1; i <= N; ++i)
  result += go[i];

 fout << result << '\n';
 for (int i = 1; i <= N; ++i)
  if (go[i])
   fout << i << '\n';

 fin.close();
 fout.close();
}
