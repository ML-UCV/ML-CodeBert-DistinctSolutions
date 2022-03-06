#include <iostream>
#include <list>
#include <fstream>
#include <vector>
#include <utility>
using namespace std;

ifstream fin("sate.in");
ofstream fout("sate.out");
void bfs( int c[], list<pair<int,int>> ad[], vector<int> &d,int n)
{
    int S=1, L=1;
    while(S<=L)
    {

        int parent =  c[S];
        for(auto &i: ad[parent])
        {

            if( d[i.first] == -1)
            {
                if(parent > i.first)
                     d[i.first] = d[parent] - i.second;
                else
                    d[i.first] = d[parent] + i.second;

                c[++L] = i.first;

            }

        }
        S++;


    }



}



int main()
{
    int n,m,x,y;
    fin>>n>>m>>x>>y;
    list <pair<int,int>> ad[n+1];

    for(int i = 0; i < m; i ++)
    {

        int x1,x2, dist;
        fin >> x1 >> x2 >> dist;
        ad[x1].push_back(make_pair(x2,dist));
        ad[x2].push_back(make_pair(x1,dist));

    }
    vector <int> d(n+1,-1);
    d[x] = 0;
    int c[n+1];
    c[1] = x;
    bfs(c,ad,d,n);
    fout<<d[y];
    return 0;
}
