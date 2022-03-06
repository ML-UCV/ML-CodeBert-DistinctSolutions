#include <fstream>
#include <vector>
using namespace std;



ifstream fin("ctc.in");

ofstream fout("ctc.out");





int n, m, q;

int k, DUD[100006];

bool viz[100001];



vector <int> V1[100001];

vector <int> V2[100001];

vector <int> ctc[100001];







void DFS1(int nod){



    viz[nod] = 1;



    for(auto it : V1[nod])

        if(!viz[it])

            DFS1(it);



    DUD[++k] = nod;

}







void DFS2(int nod){



    viz[nod] = 0;

    ctc[q].push_back(nod);



    for(auto it : V2[nod])

        if(viz[it] == 1)

            DFS2(it);

}







int main(){



    fin >> n >> m;



    for(int i = 1; i <= m; i++){



        int x, y;

        fin >> x >> y;



        V1[x].push_back(y);

        V2[y].push_back(x);

    }



    for(int i = 1; i <= n; i++)

        if(!viz[i])

            DFS1(i);



    for(int i = n; i >= 1; i--)

        if(viz[DUD[i]] == 1){

                q++;

                DFS2(DUD[i]);

            }



    fout << q << '\n';



    for(int i = 1; i <= q; i++){



        for(auto it : ctc[i])

            fout << it << ' ';



        fout << '\n';

    }



    return 0;



}
