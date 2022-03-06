#include <fstream>
#include <queue>
#include <vector>
using namespace std;

ifstream in("sate.in");
ofstream out("sate.out");

const int N = 30001;
const int M = 100021;
int d[N];
vector <pair<int, int>> a[N]; //pereche pt a pune al doilea sat si distanta dintre cele doua sate
queue <int> q;

void bfs(int s)
{
   q.push(s);
   while(!q.empty())
   {
       int x = q.front();
       q.pop();
       for(auto y : a[x])
       {
           if(d[y.first] == 0) // daca nu a fost vizitat
           {
               d[y.first] = d[x] + y.second;
               q.push(y.first);
           }
       }
   }
}

int main()
{
    int n,m,start,stop;
    in >> n >> m >> start >> stop;
    for(int i=1; i <= m; i++)
    {
        int z,b,c;
        in >> z >> b >> c;
        a[z].push_back({b,c}); // pun al doilea sat si distanta dintre cele doua sate
        a[b].push_back({z,-c});
    }
    bfs(start);
    out << d[stop] <<"\n";
    return 0;
}
