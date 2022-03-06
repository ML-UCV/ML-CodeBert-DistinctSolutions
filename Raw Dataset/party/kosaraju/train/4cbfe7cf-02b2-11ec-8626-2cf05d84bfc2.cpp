#include <bits/stdc++.h>


using namespace std;

ifstream f("party.in");

ofstream g("party.out");

int n, m, x, y, t, comp, rez_nr;

vector<int> graf[2 * 100 + 5], graf_t[2 * 100 + 5];

int c[2 * 100 + 5];

stack<int> st;

bool viz[2 * 100 + 5], rez[100 + 5];



int Not(int x)

{

  if(x < n)

    return x + n;

  return x - n;

}



void add(int x, int y)

{

  graf[Not(x)].push_back(y);

  graf[Not(y)].push_back(x);

  graf_t[y].push_back(Not(x));

  graf_t[x].push_back(Not(y));

}



void Read()

{

  f>>n>>m;

  for(int i = 1;i <= m;++i)

    {

      f>>x>>y>>t;

      if(t == 0)

        add(x, y);

      else if(t == 1)

        add(x, Not(y));

      else if(t == 2)

        add(Not(x), y);

      else

        add(Not(x), Not(y));

    }

}



void dfs(int nod)

{

  viz[nod] = true;

  for(auto it : graf[nod])

    if(!viz[it])

      dfs(it);

  st.push(nod);

}



void dfs_t(int nod)

{

  c[nod] = comp;

  for(auto it : graf_t[nod])

    if(!c[it])

      dfs_t(it);

}



void Solve()

{

  for(int i = 1;i <= 2 * n;++i)

    if(!viz[i])

      dfs(i);

  while(!st.empty())

  {

    int node = st.top(); st.pop();



    if(!c[node])

    {

      ++comp;

      dfs_t(node);

    }

  }

  for(int i = 1;i <= n;++i)

    if(c[i] > c[Not(i)])

      ++rez_nr, rez[i] = true;

  g<<rez_nr<<'\n';

  for(int i = 1;i <= n;++i)

    if(rez[i])

      g<<i<<'\n';

}



int main()

{

  Read();

  Solve();

  return 0;

}
