#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


ifstream in("sate.in");
ofstream out("sate.out");


const int MAX = 30005;


vector < pair < int , int > > myVector[MAX];

bool beenThere[MAX];

int N,M,Plec,Ajung;
int D[MAX];

void Read()
{
    in >> N >> M >> Plec >> Ajung;

    for ( int i = 1; i <= M ; ++i)
    {
        int x,y,cost;
        int costnegativ;
        in >> x >> y >> cost;
        costnegativ = cost*-1;

        myVector[x].push_back(make_pair(y,cost));
        myVector[y].push_back(make_pair(x,costnegativ));
    }
}

void DFS(int nod)
{
    beenThere[nod] = true;

    for ( size_t k = 0 ; k < myVector[nod].size(); k++)
    {
        int Vecin = myVector[nod][k].first;
        int cost = myVector[nod][k].second;

        if(beenThere[Vecin] == false)
        {

                D[Vecin] = D[nod] + cost;


         DFS(Vecin);
        }
    }

}


void Rezolv()
{


 DFS(Plec);

 out << D[Ajung];



}


int main()
{
    Read();
    Rezolv();

    return 0;
}
