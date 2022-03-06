#include <fstream>
#include <vector>


using namespace std;



ifstream fin("ctc.in");

ofstream fout("ctc.out");



vector <int> muchii[100005], muchiit[100005], rez[100005];

int n, m, viz[100005], S[100005], top, vizt[100005], cate;



void DFS(int nod) {



    int i;

    viz[nod] = 1;

    for ( auto i: muchii[nod])

        if (viz[i] == 0)

            DFS(i);



    S[++top] = nod;

}



void DFSt(int nod) {



    int i;

    vizt[nod] = 1;



    rez[cate].push_back(nod);



    for( auto i: muchiit[nod])

        if(vizt[i] == 0) {

            DFSt(i);

        }

}



int main()

{

    int i, x, y, j;



    fin >> n >> m;



    for (i = 1; i <= m; i++) {



        fin >> x >> y;

        muchii[x].push_back(y);

        muchiit[y].push_back(x);

    }



    for ( i = 1; i <= n; i++)

        if(viz[i] == 0)

            DFS(i);



    while(top != 0) {



        if(vizt[S[top]] == 0) {

            cate++;



            DFSt(S[top]);



        }

        top--;

    }



    fout << cate << "\n";



    for ( i = 1; i <= cate; i++) {



        for ( auto j: rez[i])

            fout << j << " ";



        fout << "\n";

    }



    return 0;

}
