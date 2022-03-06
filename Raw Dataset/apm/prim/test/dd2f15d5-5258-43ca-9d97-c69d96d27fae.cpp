#include<stdio.h>
#include<algorithm>
#include<vector>



using namespace std;

const int maxn = 200200;
const int INF = 200000200;

int VEC[maxn],ANS,V[maxn],H[maxn * 2 + 100],POZ[maxn];
vector <pair<int,int> > VECT[maxn],VANS;
int N,M,L,C[maxn];

void introduce_in_apm(int x)
{
 for(unsigned int i = 0;i < VECT[x].size(); ++i)
    {
  int nod = VECT[x][i].first;
  int cost = VECT[x][i].second;
  V[nod] = min(V[nod],cost);
  if (V[nod] == cost) VEC[nod] = x;
  }
}

void push(int poz)
{
 while((poz * 2 <= L && V[H[poz]] > V[H[poz * 2]]) || (poz * 2 + 1 <= L && V[H[poz]] > V[H[poz * 2 + 1]]))
 {
  if (V[H[poz * 2]] < V[H[poz * 2 + 1]] || poz * 2 + 1 > L)
  {
   swap(H[poz],H[poz * 2]);
   swap(POZ[H[poz]],POZ[H[poz * 2]]);
   poz *= 2;
  }
  else
  {
   swap(H[poz],H[poz * 2 + 1]);
            swap(POZ[H[poz]],POZ[H[poz * 2 + 1]]);
   poz = poz * 2 + 1;
  }
 }
}


void pop(int poz)
{
 while(poz > 1 && V[H[poz]] < V[H[poz / 2]])
 {
  swap(H[poz],H[poz / 2]);
  swap(POZ[H[poz]],POZ[H[poz / 2]]);
  poz = poz / 2;
 }
}

void introduce_in_heap(int nod)
{
 H[++L] = nod;
 POZ[nod] = L;
 pop(L);
}

int scoate_radacina_heap()
{
 int x = H[1];
 swap(H[1],H[L]);
 swap(POZ[H[1]],POZ[H[L]]);
 L--;
 push(1);
        POZ[x] = 0;
 return x;
}

int main()
{
 freopen("apm.in","r",stdin);
 freopen("apm.out","w",stdout);
 scanf("%d %d\n",&N,&M);
 for(int i = 1;i <= M; ++i)
 {
  int x,y,c;
  scanf("%d %d %d",&x,&y,&c);
  VECT[x].push_back(make_pair(y,c));
  VECT[y].push_back(make_pair(x,c));
 }

 for(int i = 1;i <= N; ++i) V[i] = INF;
 V[1] = 0;
 introduce_in_apm(1);
 for(int i = 2;i <= N; ++i)
 {
  introduce_in_heap(i);
 }
 for(int i = 1;i < N; ++i)
 {
  int x = scoate_radacina_heap();
  introduce_in_apm(x);
  ANS += V[x];
  VANS.push_back(make_pair(x,VEC[x]));
  for(unsigned int j = 0;j < VECT[x].size(); ++j)
  {
   int nod = VECT[x][j].first;
   if (POZ[nod]) pop(POZ[nod]);
  }
 }
 printf("%d\n",ANS);
 printf("%d\n",N-1);
 for(unsigned int i = 0;i < N - 1; ++i)
  printf("%d %d\n",VANS[i].first,VANS[i].second);
 return 0;
}
