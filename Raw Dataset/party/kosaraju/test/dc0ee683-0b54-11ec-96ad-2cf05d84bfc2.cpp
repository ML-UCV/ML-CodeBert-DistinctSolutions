#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> G1[210], G2[210], Now, Top;

vector<vector<int> > V;

int N, M, A, B, C, D, Tip, ans[210], ctc[210];

bool Used[210];



int Oposite(int X)

{

    if(X <= N) return X + N;

    return X - N;

}



void DFS1(int node)

{

     Used[node] = 1;

     for(vector<int> :: iterator it = G1[node].begin(); it != G1[node].end(); ++it)

                     if(!Used[*it])

                                   DFS1(*it);

     Top.push_back(node);

}



void DFS2(int node, int comp)

{

     ctc[node] = comp;

     Now.push_back(node);

     for(vector<int> :: iterator it = G2[node].begin(); it != G2[node].end(); ++it)

                     if(!ctc[*it])

                                  DFS2(*it, comp);

}



void Kosaraju()

{

     for(int i = 1; i <= 2 * N; i++)

             if(!Used[i])

                         DFS1(i);

     int cnt = 1;

     while(Top.size())

     {

                      if(!ctc[Top.back()])

                      {

                                         Now.clear();

                                         DFS2(Top.back(), cnt);

                                         cnt ++;

                                         V.push_back(Now);

                      }

                      Top.pop_back();

     }

}





int main()

{

    freopen("party.in", "r", stdin);

    freopen("party.out", "w", stdout);

    int i;

    scanf("%i %i", &N, &M);

    for(i = 1; i <= M; i++)

    {

          scanf("%i %i %i", &A, &B, &Tip);

          if(Tip == 0)

          {

                 C = Oposite(A);

                 D = Oposite(B);

          }

          if(Tip == 1)

          {

                 C = Oposite(A);

                 D = B;

                 B = Oposite(B);

          }

          if(Tip == 2)

          {

                 C = A;

                 D = Oposite(B);

                 A = Oposite(A);

          }

          if(Tip == 3)

          {

                 C = A;

                 D = B;

                 A = Oposite(A);

                 B = Oposite(B);

          }

          G1[C].push_back(B);

          G1[D].push_back(A);

          G2[A].push_back(D);

          G2[B].push_back(C);

    }

    Kosaraju();

    for(i = 0; i < V.size(); i++)

    {

          if(!ans[i + 1]) ans[i + 1] = 2;

          for(vector<int> :: iterator it = V[i].begin(); it != V[i].end(); ++it)

                          if(!ans[ctc[Oposite(*it)]])

                                                 ans[ctc[Oposite(*it)]] = 3 - ans[i + 1];

    }

    int cnt = 0;

    for(i = 1; i <= N; i++)

          if(ans[ctc[i]] == 1)

                         cnt ++;

    printf("%i\n", cnt);

    for(i = 1; i <= N; i++)

          if(ans[ctc[i]] == 1)

                         printf("%i\n", i);

    return 0;

}
