#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <cstring>
#include <fstream>


using namespace std;
ifstream cin ("stramosi.in");

ofstream cout ("stramosi.out");



static const int NMAX = 25e4+5;



int n, m;

int logar[NMAX];

int dp[20][NMAX];



int search (int member, int degree) {

 for ( int i = logar[n]; i >= 0; --i ) {

  if ( (1<<i) <= degree ) {

   member = dp[i][member];

   degree -= (1<<i);

  }

 }



 return member;

}



int main() {

 ios::sync_with_stdio(false);

 cin.tie(0); cout.tie(0);



 for ( int i = 2; i <= NMAX-5; ++i ) {

  logar[i] = logar[i/2]+1;

 }



 cin>>n>>m;

 for ( int i = 1; i <= n; ++i ) {

  int x;

  cin>>x;

  dp[0][i] = x;

 }



 for ( int i = 1; i <= logar[n]; ++i ) {

  for ( int j = 1; j <= n; ++j ) {

   dp[i][j] = dp[i-1][dp[i-1][j]];

  }

 }



 for ( int i = 1; i <= m; ++i ) {

  int q, p;

  cin>>q>>p;



  cout<<search(q, p)<<'\n';

 }



}
