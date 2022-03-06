#include <fstream>
#include <vector>
#include <stack>




using namespace std;



ifstream cin("party.in");

ofstream cout("party.out");



const int NMAX = 200;



int N, M;

vector <int> g[NMAX + 5];

vector <int> t[NMAX + 5];



bool seen[NMAX + 5];

stack <int> st;

void dfs1(int node)

{

 seen[node] = true;



 for(auto it : g[node])

  if(!seen[it]) dfs1(it);



 st.push(node);

}



int kComp;

int comp[NMAX + 5];

void dfs2(int node)

{

 comp[node] = kComp;



 for(auto it : t[node])

  if(comp[it] == 0) dfs2(it);

}



vector <int> sol;



int Not(int x)

{

 return x;

}



int Nrm(int x)

{

 return x + N;

}



int main()

{

 cin >> N >> M;



 for(int i = 1; i <= M; i++)

  {

   int x, y, z;

   cin >> x >> y >> z;



   if(z == 0)

    {

     g[Not(x)].push_back(Nrm(y));

     g[Not(y)].push_back(Nrm(x));



     t[Nrm(y)].push_back(Not(x));

     t[Nrm(x)].push_back(Not(y));

    }

   else if(z == 1)

    {

     g[Not(x)].push_back(Not(y));

     g[Nrm(y)].push_back(Nrm(x));



     t[Not(y)].push_back(Not(x));

     t[Nrm(x)].push_back(Nrm(y));

    }

   else if(z == 2)

    {

     g[Nrm(x)].push_back(Nrm(y));

     g[Not(y)].push_back(Not(x));



     t[Nrm(y)].push_back(Nrm(x));

     t[Not(x)].push_back(Not(y));

    }

   else

    {

     g[Nrm(x)].push_back(Not(y));

     g[Nrm(y)].push_back(Not(x));



     t[Not(y)].push_back(Nrm(x));

     t[Not(x)].push_back(Nrm(y));

    }

  }



 for(int i = 1; i <= 2 * N; i++)

  if(!seen[i]) dfs1(i);



 while(!st.empty())

 {

  int node = st.top(); st.pop();



  if(comp[node] == 0)

  {

   ++kComp;

   dfs2(node);

  }

 }



 for(int i = 1; i <= N; i++)

  if(comp[i + N] > comp[i])

   sol.push_back(i);



 cout << sol.size() << '\n';

 for(auto it : sol)

  cout << it << '\n';



 return 0;

}
