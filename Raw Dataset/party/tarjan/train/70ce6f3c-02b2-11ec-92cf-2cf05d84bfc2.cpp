#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;



const string file = "party";



const string infile = file + ".in";

const string outfile = file + ".out";





vector<int> values;

vector<vector<int> > G;



int N;

int M;



inline int non(int x)

{

 return x <= N ? x + N : x - N;

}
vector<int> ind;

vector<int> lowlink;

vector<bool> assined;

stack<int> stiva;

vector<vector<int> > ctc;



void Tarjan(int x, int& c)

{

 ind[x] = lowlink[x] = ++c;

 stiva.push(x);



 for(vector<int>::iterator itr = G[x].begin();

  itr != G[x].end();

  itr++)

 {

  if(ind[*itr] == 0)

  {

   Tarjan(*itr, c);

   lowlink[x] = min(lowlink[x], lowlink[*itr]);

  }

  else if(assined[*itr] == false)

  {

   lowlink[x] = min(lowlink[x], lowlink[*itr]);

  }

 }





 if(ind[x] == lowlink[x])

 {

  vector<int> newCtc;

  int nod = -1;

  while(nod != x)

  {

   nod = stiva.top();

   stiva.pop();

   assined[nod] = true;

   newCtc.push_back(nod);

  }

  ctc.push_back(newCtc);

 }





}



int main()

{

 fstream fin(infile.c_str(), ios::in);



 fin >> N >> M;

 G.resize(2*N + 1);



 for(int i = 0; i < M; i++)

 {

  int x, y, z;



  fin >> x >> y >> z;

  if( 2 & z) x = non(x);

  if( 1 & z) y = non(y);



  G[non(x)].push_back(y);

  G[non(y)].push_back(x);



 }



 fin.close();

 int c = 0;

 ind.resize(2* N + 1);

 lowlink.resize(2 * N + 1);

 assined.resize(2 * N + 1);



 for(int i = 1; i <= 2*N; i++)

 {

  if(ind[i] == 0)

  {

   Tarjan(i, c);

  }

 }





 values.resize(N + 1, -1);

 int size = 0;



 for(vector<vector<int> >::reverse_iterator itr = ctc.rbegin();

  itr != ctc.rend();

  itr++)

 {

  for(vector<int>::iterator itr2 = itr->begin();

   itr2 != itr->end();

   itr2++)

  {

   int value = *itr2 <= N ? 0 : 1;

   int nod = *itr2 <= N ? *itr2 : non(*itr2);



   if(values[nod] == -1)

   {

    values[nod] = value;

    if(value == 1) size++;

   }

   else

   {

    break;

   }



  }

 }
 fstream fout(outfile.c_str(), ios::out);

 fout << size << "\n";

 for(int i = 1; i <= N; i++)

 {

  if(values[i] == 1) fout << i << "\n";



 }





 fout.close();



}
