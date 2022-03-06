#include <fstream>
#include <vector>
#include <queue>




using namespace std;



ifstream in("apm.in");

ofstream out("apm.out");



struct amp{

    int x, y, c;

};



struct lat{

    int index, cost;

};



struct comp {

    bool operator()(amp const& a, amp const& b) {

        return a.c > b.c;

    }

};



int n, m, frecNod[200005] , totalCost;

vector < vector <lat> > L(200005);

vector <amp> rezultat;

priority_queue <int, vector <amp>, comp> coada;



amp muchie;



int main()

{

    in>>n>>m;

    for(int i = 1; i <= m; ++i){

        int x, y, c;

        lat latura;

        in>>x>>y>>c;

        latura.cost = c;



        latura.index = y;

        L[x].push_back(latura);



        latura.index = x;

        L[y].push_back(latura);

    }



    muchie.x = 0;

    muchie.y = 1;

    muchie.c = 0;

    coada.push(muchie);



    while(!coada.empty()){



        amp curent = coada.top();



        coada.pop();



        if(frecNod[curent.y]) continue;

        rezultat.push_back(curent);

        frecNod[curent.y] = 1;



        totalCost += curent.c;

        for(int i = 0; i < L[curent.y].size(); i++){

            muchie.x = curent.y;

            muchie.y = L[curent.y][i].index;

            muchie.c = L[curent.y][i].cost;



            coada.push(muchie);

        }

    }



    out<<totalCost<<'\n';

    out<<rezultat.size() - 1 <<'\n';

    for(int i = 1; i < rezultat.size(); i++)

        out<<rezultat[i].x<<" "<<rezultat[i].y<<'\n';



    in.close();

    out.close();

    return 0;

}
