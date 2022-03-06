#include <fstream>
#include <bitset>
#include <vector>


using namespace std;



ifstream cin("party.in");

ofstream cout("party.out");



const int NMAX = int(1e5) + 2;

int N, M;

vector<int> G[NMAX<<1], GT[NMAX<<1], s;

bitset< NMAX<<1 > visited, truthValue;

bool solution = true;





inline void addEdge(int a,int b) {

 G[(a > N ? a - N : a + N)].push_back(b);

    G[(b > N ? b - N : b + N)].push_back(a);

    GT[a].push_back((b > N ? b - N : b + N));

    GT[b].push_back((a > N ? a - N : a + N));



}



void readData(){

    cin>>N>>M;

    int a, b, t;

    for(int i = 0;i < M;i++) {

        cin>>a>>b>>t;

  if(t == 0) {

   addEdge(a,b);

  } else

  if(t == 1) {

   addEdge(b + N,a);

  } else

  if(t == 2) {

   addEdge(a + N,b);

  } else {

   addEdge(a + N,b + N);

  }

 }

}



void df(const int &v) {

    visited[v] = true;

    for(vector<int>::const_iterator w = G[v].begin();w != G[v].end();w++) {

        if(visited[*w] == false) {

            df(*w);

        }

    }

    s.push_back(v);

}



void df1(const int &v) {

    if(truthValue[v]) {

        solution = false;

    }

    truthValue[(v > N ? v - N : v + N)] = true;

    visited[v] = true;

    for(vector<int>::const_iterator w = GT[v].begin();w != GT[v].end();w++) {

        if(visited[*w] == false) {

            df1(*w);

        }

    }

}



void solve() {

    for(int i = 1;i <= (N<<1);i++){

        if(!visited[i]) {

            df(i);

        }

    }

    visited.reset();

    for(vector<int>::const_reverse_iterator it = s.rbegin();it != s.rend();it++) {

        if(!visited[*it] && !visited[(*it > N ? *it - N : *it + N)]) {

            df1(*it);

        }

    }

    if(solution) {

  int nr = 0;

  for(int i = 1;i <= N;i++) {

   nr += truthValue[i];

  }

  cout<<nr<<"\n";

        for(int i = 1;i <= N;i++) {

   if(truthValue[i]) {

    cout<<i<<"\n";

   }

        }

    } else {

        cout<<"-1\n";

    }

}



int main()

{

    readData();

    solve();

    return 0;

}
