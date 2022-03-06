#include <fstream>
#include <vector>
#include <stack>


using namespace std;



ifstream f("ctc.in");

ofstream g("ctc.out");



int n, m;

vector<int>graph[100005], gt[100005];

stack<int>s;

vector<int> comp[100005];

int viz[100005];

int nrc;



void citire(){

    f>>n>>m;

    int x, y;

    for(int i=0; i<m; i++){

        f>>x>>y;

        graph[x].push_back(y);

        gt[y].push_back(x);

    }

}



void DFS(int v){

    viz[v] = 1;

    for(auto &vf:graph[v])

        if(viz[vf] == 0)

            DFS(vf);

    s.push(v);

}



void DFSt(int v, int nrc){

    viz[v] = -1;

    for(auto &vf:gt[v])

        if(viz[vf] > 0)

            DFSt(vf, nrc);

    comp[nrc].push_back(v);

}



void parcurgere(){

    for(int i=1; i<=n; i++)

        if(viz[i] == 0)

            DFS(i);

}



void solve(){

    while(!s.empty()){

        int vf = s.top();

        s.pop();

        if(viz[vf] < 0)

            continue;

        nrc++;

        DFSt(vf, nrc);

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

int main()

{

    citire();

    parcurgere();

    solve();

    afis();

    return 0;

}
