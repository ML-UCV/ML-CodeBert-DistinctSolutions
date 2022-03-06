#include <fstream>
#include <vector>
#include <stack>




using namespace std;

int x,y;

int nrcomp;

stack<int>s;

const int MAXN=100001;

vector < int > g[MAXN];

vector<int>ctc[MAXN];

int viz[MAXN];

int iss[MAXN];

int nivel[MAXN],idk;

int L[MAXN];



ifstream cin("ctc.in");

ofstream cout("ctc.out");

void tarjan(int x) {

 viz[x] = 1;

 iss[x] = 1;

 s.push(x);

 nivel[x] = ++idk;

 L[x] = nivel[x];

 for ( auto y : g[x]) {

 if(!viz[y]) {

 tarjan(y);

 L[x] = min(L[x],L[y]);

}

 else

 if(iss[y]) {

  L[x] = min(nivel[y],L[x]);

}





}

 if(nivel[x] == L[x]) {

 ++nrcomp;

while(!s.empty()) {

 int y = s.top();

 s.pop();

 iss[y]=false;

 ctc[nrcomp].push_back(y);

 if(y == x)

  break;

}

}

}



int n,m;

int main() {

  cin >> n >>m;

 for ( int i = 1; i <= m; ++i) {

 cin >> x >> y;

 g[x].push_back(y);

}

 for ( int i = 1; i <= n; ++i)

  if(!viz[i])

   tarjan(i);



    cout << nrcomp <<"\n";

for (int i = 1; i <=nrcomp; ++i) {

 for ( auto y : ctc[i])

  cout << y <<" ";

cout << "\n";

}



}
