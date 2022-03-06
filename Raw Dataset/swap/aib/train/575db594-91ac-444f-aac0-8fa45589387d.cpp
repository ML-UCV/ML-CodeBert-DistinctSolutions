#include<fstream>#include <cstring>
#include<vector>
using namespace std;

const int MAX_N = 50007;

vector<int> B[27];

int AIB[MAX_N], A[27], N;

char S[MAX_N], T[MAX_N];

void update(int x)

{

 for(;x<=N;x+=(x&-x)) AIB[x]++;

}

inline int query(int x)

{

 int sol = 0;

 for(;x;x-=(x&-x)) sol += AIB[x];

 return sol;

}

inline int getP(char x, int y)

{

 int c = x - 96;

 if( B[c].size() <= y-1) return -1;

 return B[c][y-1];

}

int sol;

int main()

{

 ifstream in("swap.in"); ofstream out("swap.out");

 in>>S+1>>T+1;

 int i, P;

 N = strlen(S+1);

 for(i = 1; i <= N; ++i)

  B[ T[i] - 96 ].push_back(i);

 for(i = 1; i <= N; ++i)

 {

  A[ S[i] - 96 ]++;

  P = getP( S[i], A[ S[i] - 96 ] );

  if(P == -1) break;

  sol += query(N) - query(P);

  update(P);

 }

 if(P != - 1) out<<sol<<"\n";

 else out<<"-1\n";

 return 0;

}
