#include <fstream>
#include <stack>
#include <vector>






using namespace std;



vector< vector<int>> Componente;

vector<int>graph[100005];

vector<int>ajut;



stack<int> S;

int nr;

int n, m, x, y;

int low_link[100005];

int is_in_stack[100005];

int viz[100005];

int idx[100005];

int index = 1;



void citire(){

    ifstream f("ctc.in");

    f>>n>>m;

    for(int i=1; i<=m; i++){

        f>>x>>y;

        graph[x].push_back(y);

    }

}



void tarjan(int i){

    low_link[i] = idx[i] = index;

    index ++;



    viz[i] = 1;

    is_in_stack[i] = 1;

    S.push(i);



    for(auto &v:graph[i]){

        if(viz[v] == 0){

            tarjan(v);

            low_link[i] = min(low_link[i], low_link[v]);

        }

        else if(is_in_stack[v] == 1){

            low_link[i] = min(low_link[i], low_link[v]);

        }

    }



    if(idx[i] == low_link[i]){

        ajut.clear();

        int el;

        do{

            el = S.top();

            ajut.push_back(el);

            S.pop();

            is_in_stack[el] = 0;

        }while(el!=i);

        Componente.push_back(ajut);

    }

}

void parcurg_componente_conexe_graf(){

    for(int i=1; i<=n; i++){

        if(viz[i] == 0){

            tarjan(i);

        }

    }

}



void afisare(){

    ofstream g("ctc.out");

    int m = Componente.size();

    g<<m<<'\n';

    for(int i=0; i<m; i++){

        int k=Componente[i].size();

        for(int j = 0; j<k; j++)

            g<<Componente[i][j]<<' ';

        g<<'\n';

    }

}

int main()

{

    citire();

    parcurg_componente_conexe_graf();

    afisare();

    return 0;

}
