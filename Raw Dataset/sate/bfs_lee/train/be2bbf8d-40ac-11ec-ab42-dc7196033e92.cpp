#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <queue>
using namespace std;
ifstream f("sate.in");
ofstream g("sate.out");

const int NMAX=30001;
vector <pair<int,int> > muchii[NMAX];
queue <int> coada;
int i,n,m,distanta[NMAX],x,y,nod1,nod2,distant;
bool vizitat[NMAX];

void BFS_sate(int x)
{
    coada.push(x);//pun nodul in coada
    vizitat[x]=1; //marchez nodul drept vizitat
    while(coada.empty()==0) //cat timp coada nu e vida
    {
        int varf=coada.front();//iau primul element
        for(int i=0; i<muchii[varf].size(); i++) //parcurg nodurile cu care are muchie varful
           {
               int nod=muchii[varf][i].first; // iau pe rand nodul si distanta
               int dist=muchii[varf][i].second;
               if(vizitat[nod]==0) //daca prmul nu a fost vizitat
               {
                   vizitat[nod]=1;//il marchez drept vizitat
                   if(varf<nod) //daca e mai mic decat varful adaug distanta, altfel o scad
                    distanta[nod]=distanta[varf]+dist;
                   else
                    distanta[nod]=distanta[varf]-dist;
                   coada.push(nod); //si adaug nodul in coada
               }
           }
        coada.pop();//si scot varful curent
    }

}
int main()
{
    f>>n>>m>>x>>y;

    for(i=1; i<=m; i++)
    {
        f>>nod1>>nod2>>distant;
        muchii[nod1].push_back(make_pair(nod2,distant));//adaug nodul2 si distanta in lista de muchii a nodului1
        muchii[nod2].push_back(make_pair(nod1,distant));//adaug nodul1 si distanta  in lista de muchii a nodului2
    }
    BFS_sate(x);
    g<<distanta[y];
    return 0;
}
