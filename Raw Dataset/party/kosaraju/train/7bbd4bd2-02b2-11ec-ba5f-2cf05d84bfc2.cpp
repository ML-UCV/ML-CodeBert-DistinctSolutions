#include <set>
#include <map>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <cmath>
#include <ctime>
#include <cctype>
#include <cstdio>
#include <vector>
#include <string>
#include <bitset>
#include <utility>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
typedef vector<int> VI;

typedef pair<int,int> pi;

typedef vector<string> VS;

template<class T> string toString(T n) {ostringstream ost;ost<<n;ost.flush();return ost.str();}



int N,M,S[(1<<8)];

vector<VI> A((1<<8)),B((1<<8));

bitset<(1<<8)> viz,Sol;

bool Aedge[(1<<8)][(1<<8)],Bedge[(1<<8)][(1<<8)];



inline void add_edge(int x,int y)

{

 if(!Aedge[x][y])

 {

  A[x].push_back(y);

  Aedge[x][y] = true;

 }

 if(!Bedge[y][x])

 {

  B[y].push_back(x);

  Bedge[y][x] = true;

 }

}



inline void scan()

{

 freopen("party.in","r",stdin);

 freopen("party.out","w",stdout);



 scanf("%d%d",&N,&M);

 int x,y,z;

 for(int (i)=(1);(i)<=(M);++(i))

 {

  scanf("%d%d%d",&x,&y,&z);

  switch(z)

  {

   case 0: { add_edge( ( (x) <= N ? (x) + N : (x) - N ),y); add_edge( ( (y) <= N ? (y) + N : (y) - N ),x ); break;};

   case 1: { add_edge( ( (x) <= N ? (x) + N : (x) - N ),( (y) <= N ? (y) + N : (y) - N ) ); add_edge( y,x ); break;};

   case 2: { add_edge( ( (y) <= N ? (y) + N : (y) - N ),( (x) <= N ? (x) + N : (x) - N ) ); add_edge( x,y ); break;};

   case 3: { add_edge( x,( (y) <= N ? (y) + N : (y) - N ) ); add_edge( y,( (x) <= N ? (x) + N : (x) - N ) ); break;};

  }

 }

}



inline void DFP(int nod)

{

 viz[nod] = true;



 for (__typeof((A[nod]).begin()) it = (A[nod]).begin(); it != (A[nod]).end(); ++it)

  if(!viz[*it])

   DFP(*it);

 S[++S[0]] = nod;

}



inline void DFM(int nod)

{

 viz[nod] = true;

 Sol[ ( (nod) <= N ? (nod) + N : (nod) - N ) ] = true;



 for (__typeof((B[nod]).begin()) it = (B[nod]).begin(); it != (B[nod]).end(); ++it)

  if(!viz[*it])

   DFM(*it);

}



inline void solve()

{

 for(int (i)=(1);(i)<=(N + N);++(i))

  if(!viz[i])

   DFP(i);



 viz.reset();



 for(int i = N + N;i >= 1;--i)

  if( !viz[ S[i] ] && !viz[ ( (S[i]) <= N ? (S[i]) + N : (S[i]) - N ) ] )

   DFM(S[i]);



 S[0] = 0;

 for(int (i)=(1);(i)<=(N);++(i))

  if(Sol[i] == true)

   S[++S[0]] = i;



 printf("%d\n",S[0]);

 for(int (i)=(1);(i)<=(S[0]);++(i))

  printf("%d\n",S[i]);

}



int main()

{

 scan();

 solve();

 return 0;

}
