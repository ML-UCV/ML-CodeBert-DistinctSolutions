#include <fstream>
#include <vector>
#include <queue>


using namespace std;



ifstream in("ctc.in");

ofstream out("ctc.out");



int n, m, k;

int sortat[100001];

bool vizitat[100001];

vector<vector<int> > graf(200002), grafInv(200002), rezultat;

queue<int> coada;



void sortareTopologica(){

    int nod = coada.front();

    coada.pop();

    vizitat[nod] = true;



    for(size_t i = 0; i < graf[nod].size(); ++i)

        if(!vizitat[graf[nod][i]]){

            coada.push(graf[nod][i]);

            sortareTopologica();

        }

    sortat[++k] = nod;

}



void kosaraju(){

    int nod = coada.front();

    coada.pop();

    vizitat[nod] = false;

    rezultat[rezultat.size() - 1].push_back(nod);



    for(size_t i = 0; i < grafInv[nod].size(); ++i)

        if(vizitat[grafInv[nod][i]]){

            coada.push(grafInv[nod][i]);

            kosaraju();

        }

}



int main()

{

    in>>n>>m;

    while(m--){

        int x, y;

        in>>x>>y;



        graf[x].push_back(y);

        grafInv[y].push_back(x);

    }



    for(int i = 1; i <= n; ++i)

        if(!vizitat[i]){

            coada.push(i);

            sortareTopologica();

        }



    while(!coada.empty())

        coada.pop();



    vector<int> aux;

    for(int i = n; i >= 1; --i)

        if(vizitat[sortat[i]]){

            rezultat.push_back(aux);

            coada.push(sortat[i]);

            kosaraju();

        }



    out<<rezultat.size()<<'\n';

    for(size_t i = 0; i < rezultat.size(); ++i){

        for(size_t j = 0; j < rezultat[i].size(); ++j)

            out<<rezultat[i][j]<<" ";

        out<<'\n';

    }

    in.close();

    out.close();

    return 0;

}
