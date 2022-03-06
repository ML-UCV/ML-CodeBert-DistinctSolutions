#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
ifstream fi("sate.in");
ofstream fo("sate.out");
int n,m;
int X,Y;
vector <pair<int,int>>vec[30005];
int parcurs[30005];
int sol[30005];
void componenta_conexa(int x,int value)
{
    sol[x]=value;
    for(int i=0;i<=vec[x].size()-1;i++)
    {
        if(parcurs[vec[x][i].first]==0)
        {
            parcurs[vec[x][i].first]=1;
            ///daca in vector distanta paan la nodul vec[x][i] este mai mica decat una calculata
            /// se scade altfe se insumeaza
            if(x>vec[x][i].first)
                componenta_conexa(vec[x][i].first,value-vec[x][i].second);
            else
                componenta_conexa(vec[x][i].first,value+vec[x][i].second);
        }
    }
}
int main()
{
    fi>>n>>m;
    fi>>X>>Y;
    int x,y,dist;
    for(int i=1;i<=m;i++)
    {
        fi>>x>>y>>dist;
        vec[x].push_back(make_pair(y,dist));
        vec[y].push_back(make_pair(x,dist));
    }
    parcurs[X]=1;
    componenta_conexa(X,0);
    fo<<sol[Y];
    return 0;
}
