#include <cstdio>
#include <vector>
#include <queue>
#include <bitset>
#include <utility>
#include <algorithm>


const int MAX_N(105);
const int MAX_M(1005);

int n, m;
std::vector<std::pair<int,int>> Exp;
std::vector<int> Result;
bool Value [MAX_N << 1];
std::bitset<MAX_N << 1> Mark;
std::deque<int> Sorted;
std::vector<int> Graph [MAX_N << 1];
std::vector<int> Transpose [MAX_N << 1];
bool Flag [MAX_N];

inline void Read (void)
{
 std::freopen("party.in","r",stdin);
 std::scanf("%d %d",&n,&m);
 for (int i(1), a, b, t ; i <= m ; ++i)
 {
  std::scanf("%d %d %d",&a,&b,&t);
  if (t == 0)
   Exp.push_back(std::make_pair(a,b));
  else if (t == 1)
   Exp.push_back(std::make_pair(a,b + n));
  else if (t == 2)
   Exp.push_back(std::make_pair(a + n,b));
  else
   Exp.push_back(std::make_pair(a + n,b + n));
  Flag[a] = Flag[b] = true;
 }
 std::fclose(stdin);
}

inline void Print (void)
{
 std::freopen("party.out","w",stdout);
 std::printf("%d\n",static_cast<int>(Result.size()));
 for (auto it : Result)
  std::printf("%d\n",it);
 std::fclose(stdout);
}

inline int Non (const int X)
{
 if (X <= n)
  return X + n;
 return X - n;
}

inline void Build (void)
{
 for (auto it : Exp)
 {
  Graph[Non(it.first)].push_back(it.second);
  Graph[Non(it.second)].push_back(it.first);
  Transpose[it.second].push_back(Non(it.first));
  Transpose[it.first].push_back(Non(it.second));
 }
}

void Toposort (int node)
{
 for (auto it : Graph[node])
  if (!Mark[it])
  {
   Mark[it] = true;
   Toposort(it);
  }
 Sorted.push_front(node);
}

void DepthFirstSearch (int node)
{
 Mark[node] = true;
 Value[Non(node)] = true;
 for (auto it : Transpose[node])
  if (!Mark[it])
   DepthFirstSearch(it);
}

inline void Kosaraju (void)
{
 for (int i(1), end(n << 1) ; i <= end ; ++i)
  if (!Mark[i] && Flag[i])
  {
   Mark[i] = true;
   Toposort(i);
  }
 Mark.reset();
 for (auto it : Sorted)
  if (!(Value[it] || Value[Non(it)]))
   DepthFirstSearch(it);
}

inline void Sat (void)
{
 Build();
 Kosaraju();
}

inline void Count (void)
{
 for (int i(1) ; i <= n ; ++i)
  if (Value[i] || !Flag[i])
   Result.push_back(i);
}

int main (void)
{
 Read();
 Sat();
 Count();
 Print();
 return 0;
}
