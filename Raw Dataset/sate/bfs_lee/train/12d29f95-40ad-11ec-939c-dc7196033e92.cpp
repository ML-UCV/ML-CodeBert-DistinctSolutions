#include <fstream>
#include <cstring>
#include <vector>
#include <queue>
#define Nmax 30005
#define INF 0x3f3f3f3f

using namespace std;

ifstream f("sate.in");
ofstream g("sate.out");

queue <int > Q;
vector <pair <int, int > > v[Nmax];
int d[Nmax];
bool seen[Nmax];
int n, m, X, Y;

void read()
{
    f >> n >> m >> X >> Y;int x,y,cost;
     for ( int i = 1 ; i <= m ; i ++ )
      {
          f >> x >> y >> cost;
          v[x].push_back(make_pair(cost,y));
          v[y].push_back(make_pair(cost,x));
      }
}

void BFS()
{
    Q.push(X);
    seen[X]=true;
    d[X]=1;
     while(!Q.empty())
      {
          int old_node=Q.front();
          Q.pop();
           for ( int k = 0 ; k < v[old_node].size() ; k ++ )
           {
               int new_cost=v[old_node][k].first;
               int new_node=v[old_node][k].second;
                if ( seen[new_node] == false )
                {
                    seen[new_node]=true;
                     if ( new_node > old_node )
                       d[new_node]=d[old_node]+new_cost;
                    else
                       d[new_node]=d[old_node]-new_cost;
                    Q.push(new_node);
                }
           }
      }
       /*for ( int i = 1 ; i <= n ; i ++ )
        g << d[i] << " ";
        g << '\n';*/
}
void print()
{
     g << d[Y]-d[X];
}

int main()
{
    read();
    BFS();
    print();
    return 0;
}
