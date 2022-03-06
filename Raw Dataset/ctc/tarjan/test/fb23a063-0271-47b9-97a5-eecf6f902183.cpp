#include<fstream>
#include<stack>
#include<bitset>
#include<vector>
using namespace std;

ifstream fin("ctc.in");

ofstream fout("ctc.out");

int n,m,k,x,y,NR;

int nivel[100010],low[100010];

vector<int> L[100010];

vector<int> componente[100010];

stack<int> stiva;

bitset <100010> f;



void dfs(int nod){

    f[nod]=1;

    nivel[nod]=++k;

    low[nod]=k;

    stiva.push(nod);

    for(int i=0;i<L[nod].size();i++){

        int vecin=L[nod][i];

        if(nivel[vecin]==0){

            dfs(vecin);

            low[nod]=min(low[nod],low[vecin]);

        }

        else{

            if(f[vecin]!=0){

                low[nod]=min(low[nod],low[vecin]);

            }

        }

    }

    if(nivel[nod]==low[nod]){

        NR++;

        int aux;

        do{

            aux=stiva.top();

            stiva.pop();

            f[aux]=0;

            componente[NR].push_back(aux);

        }while(aux!=nod);

    }

}



int main(){

    fin>>n>>m;

    for(int i=1;i<=m;i++){

        fin>>x>>y;

        L[x].push_back(y);

    }

    for(int i=1;i<=n;i++){

        if(nivel[i]==0){

            dfs(i);

        }

    }

    fout<<NR<<"\n";

    for(int i=1;i<=NR;i++){

        for(int j=0;j<componente[i].size();j++){

            fout<<componente[i][j]<<" ";

        }

        fout<<"\n";

    }

    return 0;

}
