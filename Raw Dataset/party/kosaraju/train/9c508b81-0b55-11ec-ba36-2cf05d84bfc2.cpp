#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>


using namespace std;



ifstream cin ("party.in");

ofstream cout ("party.out");



int n, m, x, y, type;



bool viz[200005];

int val[100005], ind[200005], deg[200005];

vector <int> g[200005], ginv[200005];

vector <int> comp, st;

vector <vector <int>> comps;

queue <int> q;



int indx(int val) {

  if(val < 0)

    return n - val;

  return val;

}



int non(int val) {

  if(val > n)

    return val - n;

  return val + n;

}



void dfsp(int nod) {

  viz[nod] = 1;

  for(auto &fiu : g[nod]) {

    if(!viz[fiu])

      dfsp(fiu);

  }

  st.push_back(nod);

}



void dfsm(int nod) {

  viz[nod] = 1;

  comp.push_back(nod);

  for(auto &fiu : ginv[nod]) {

    if(!viz[fiu])

      dfsm(fiu);

  }

}



int main() {

  cin >> n >> m;

  for(int i = 1; i <= m; i++) {

    cin >> x >> y >> type;

    if(type == 0) {

      g[non(x)].push_back(y);

      g[non(y)].push_back(x);

      ginv[x].push_back(non(y));

      ginv[y].push_back(non(x));

    } else if(type == 3) {

      ginv[non(x)].push_back(y);

      ginv[non(y)].push_back(x);

      g[x].push_back(non(y));

      g[y].push_back(non(x));

    } else if(type == 1) {

      g[non(x)].push_back(non(y));

      g[y].push_back(x);

      ginv[x].push_back(y);

      ginv[non(y)].push_back(non(x));

    } else {

      ginv[non(x)].push_back(non(y));

      ginv[y].push_back(x);

      g[x].push_back(y);

      g[non(y)].push_back(non(x));

    }

  }

  for(int i = 1; i <= 2 * n; i++) {

    if(!viz[i])

      dfsp(i);

  }

  for(int i = 1; i <= 2 * n; i++)

    viz[i] = 0;

  while(!st.empty()) {

    int nod = st.back();

    st.pop_back();

    if(!viz[nod]) {

      comp.clear();

      dfsm(nod);

      for(auto &Nod : comp)

        ind[Nod] = comps.size();

      comps.push_back(comp);

    }

  }

  for(int i = 1; i <= n; i++) {



    if(ind[i] == ind[i + n]) {



      cout << -1;

      return 0;

    }

  }

  for(int i = 1; i <= 2 * n; i++) {

    for(auto &fiu : g[i]) {

      if(ind[fiu] != ind[i])

        deg[ind[fiu]]++;

    }

  }

  for(int i = 1; i <= n; i++)

    val[i] = 2;

  for(int i = 0; i < comps.size(); i++) {

    if(!deg[i])

      q.push(i);

  }

  while(!q.empty()) {

    int cmp = q.front();

    q.pop();

    for(auto &nod : comps[cmp]) {

      int trueNod = (nod > n ? nod - n : nod);

      if(val[trueNod] == 2)

        val[trueNod] = (nod > n);

    }

    for(auto &nod : comps[cmp]) {

      for(auto &fiu : g[nod]) {

        if(ind[nod] != ind[fiu]) {

          deg[ind[fiu]]--;

          if(!deg[ind[fiu]])

            q.push(ind[fiu]);

        }

      }

    }

  }

  vector <int> guests;

  for(int i = 1; i <= n; i++) {

    if(val[i])

      guests.push_back(i);

  }

  cout << guests.size() << "\n";

  for(auto &guest : guests)

    cout << guest << "\n";

  return 0;

}
