#include <fstream>
#include <vector>
#include <stack>


using namespace std;

vector<int> a[100010];

vector<int> sol[100010];

stack<int> s;

int f[100010];

int niv[100010];

int low[100010];

int is[100010];

int i,n,m,u,g,x,y;



void dfs (int nod) {

    g++;

    niv[nod]=g;

    low[nod]=g;

    f[nod]=1;

    is[nod]=1;

    s.push(nod);

    is[nod]=1;

    for (auto vecin:a[nod]) {

        if (f[vecin]==0) {

            dfs(vecin);

            low[nod]=min(low[nod],low[vecin]);

        }

        else if (is[vecin]){

            low[nod]=min(low[nod],low[vecin]);

        }

    }



    if (low[nod]==niv[nod]) {

        u++;

        while (s.top()!=nod) {

            sol[u].push_back(s.top());

            is[s.top()]=0;

            s.pop();

        }

        sol[u].push_back(s.top());

        is[s.top()]=0;

        s.pop();

    }

}



int main() {

    ifstream fin("ctc.in");

    ofstream fout("ctc.out");

    fin>>n>>m;

    for (i=1;i<=m;i++) {

        fin>>x>>y;

        a[x].push_back(y);

    }

    for (i=1;i<=n;i++) {

        if (f[i]==0) {

            dfs(i);

        }

    }

    fout<<u<<"\n";

    for (i=1;i<=u;i++) {

        for (auto nod:sol[i]) {

            fout<<nod<<" ";

        }

        fout<<"\n";

    }

    return 0;

}
