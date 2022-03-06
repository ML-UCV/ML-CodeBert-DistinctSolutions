#include <fstream>
#include <vector>
#include <queue>

using namespace std;

void citire( int &n, vector< pair<int, int> >* &la, int &x, int &y, ifstream &f)
{
    int m, it, i, j, cost;
    f >> n >> m >> x >> y;

    la = new  vector< pair<int, int> >[n+1];


    for(it = 1; it <= m; it++)
    {
        f >> i >> j >> cost;
        la[i].push_back({j, cost});
        la[j].push_back({i, cost});
    }
}



void Bf(const int &n, vector< pair<int, int> > *la, const int &nod_start, const int &nod_end, int* &dist)
{
    int *viz = new int[n+1](); //initial cu zero
    dist = new int[n+1]();
    queue<int> c;

    viz[nod_start] = 1;
    dist[nod_start] = 1;

    c.push(nod_start);

    while( !c.empty() )
    {
        int nod = c.front();
        c.pop();

        for(unsigned i = 0; i < la[nod].size(); i++)
        {
            int nod_nou = la[nod][i].first;
            int cost_nou = la[nod][i].second;

            if( viz[nod_nou] == 0)
            {
                viz[nod_nou] = 1;

                if( nod_nou > nod )
                    dist[nod_nou] = dist[nod] + cost_nou;
                else
                    dist[nod_nou] = dist[nod] - cost_nou;

                c.push(nod_nou);
            }
        }
    }

}

int main()
{
    ifstream fin ("sate.in");
    int n, nod_start, nod_end;
    vector< pair<int, int> > *la;
      citire(n, la, nod_start, nod_end, fin);
    fin.close();

   int *km;
   Bf(n, la, nod_start, nod_end, km);

    ofstream fout ("sate.out");

    fout << km[nod_end] - km[nod_start];

    fout.close();


    return 0;
}
