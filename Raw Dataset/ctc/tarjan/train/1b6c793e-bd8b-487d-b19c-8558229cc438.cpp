# include <cstdio>
# include <vector>


using namespace std;






int N, M, i, vf, ct, Time;
int St[100005];
int Lvl[100005];
int Low[100005];
vector <int> G[100005];
vector <int> CTC[100005];

     void Dfs(int nod)
     {
         vector <int> :: iterator it;

         St[++vf] = nod;
         Lvl[nod] = Low[nod] = ++Time;
         for (it = G[nod].begin(); it != G[nod].end(); ++it)
         {
             if (!Lvl[*it])
             {
                Dfs(*it);
                Low[nod] = (Low[nod] < Low[*it] ? Low[nod] : Low[*it]);
             } else
             if (Lvl[*it] > 0)
                Low[nod] = (Low[nod] < Lvl[*it] ? Low[nod] : Lvl[*it]);
         }

         if (Low[nod] == Lvl[nod])
           {
              ++ct;
              for (i = vf; St[i + 1] != nod; --i)
              {
                 CTC[ct].push_back(St[i]);
                 Lvl[St[i]] = -1;
              }
              vf = i;
           }
     }

     int main()
     {
         freopen("ctc.in","r",stdin);
         freopen("ctc.out","w",stdout);

         scanf("%d %d",&N, &M);
         for (i = 1; i <= M; ++i)
         {
             int x, y;
             scanf("%d %d",&x, &y);

             G[x].push_back(y);
         }

         vf = ct = Time = 0;
         for (i = 1; i <= N; ++i)
           if (!Lvl[i]) Dfs(i);

         printf("%d\n",ct);

         vector <int> :: iterator it;
         for (i = 1; i <= ct; ++i)
         {
             for (it = CTC[i].begin(); it != CTC[i].end(); ++it)
                printf("%d ",*it);
             printf("\n");
         }

         return 0;
     }
