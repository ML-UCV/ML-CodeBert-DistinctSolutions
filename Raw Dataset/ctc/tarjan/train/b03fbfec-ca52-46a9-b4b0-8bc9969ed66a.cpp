#include <fstream>
#include <stack>
#include <vector>


using namespace std;



ifstream f("ctc.in");

ofstream g("ctc.out");



vector<int>graph[100005];

vector<int>comp[100005];

stack<int> S;



int viz[100005], is_in_stack[100005], idx[100005], low_link[100005];

int index, nrc, n, m, x, y;



void citire(){

    f>>n>>m;

    for(int i=0; i<m; i++){

        f>>x>>y;

        graph[x].push_back(y);

    }

}



void tarjan(int vf){



    low_link[vf] = idx[vf] = index;

    index++;



    viz[vf] = 1;

    is_in_stack[vf] = 1;

    S.push(vf);



    for(auto &v:graph[vf]){

        if(viz[v] == 0){

            tarjan(v);

            low_link[vf] = min(low_link[v], low_link[vf]);

        }

        else if(is_in_stack[v] == 1){

            low_link[vf] = min(low_link[v], low_link[vf]);

        }

    }



    if(idx[vf] == low_link[vf]){

        nrc++;

        int el;

        do{

            el = S.top();

            comp[nrc].push_back(el);

            S.pop();

            is_in_stack[el] = 0;

        }while(el != vf);

    }

}

void afis(){

    g<<nrc<<'\n';

    for(int i=1; i<=nrc; i++){

        for(auto &v:comp[i])

            g<<v<<' ';

        g<<'\n';

    }

}



void parcurgere(){

    for(int i=1; i<=n; i++)

        if(viz[i] == 0)

            tarjan(i);

}

int main()

{

    citire();

    parcurgere();

    afis();

    return 0;

}
