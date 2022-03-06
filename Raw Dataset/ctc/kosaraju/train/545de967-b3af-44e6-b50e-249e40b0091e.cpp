#include <fstream>
#include <cstring>
#include <vector>




using namespace std;

int cont=0,cnt=0;

int viz[100005];

vector<int> v1[100005],v2[100005];

int order[100005];

vector<int> comp[100005];

void dfs1(int nod){

    viz[nod]=1;

    for(auto u:v1[nod]){

        if(viz[u]==0){

            dfs1(u);

        }

    }

    order[++cont]=nod;

}



void dfs2(int nod){

    viz[nod]=1;

    comp[cnt].push_back(nod);

    for(auto u:v2[nod]){

        if(viz[u]==0){

            dfs2(u);

        }

    }

}



int main()

{

    ifstream cin("ctc.in");

    ofstream cout("ctc.out");

    int n,m,a,b;

    cin>>n>>m;

    for(int i=1;i<=m;i++){

        cin>>a>>b;

        v1[a].push_back(b);

        v2[b].push_back(a);

    }

    for(int i=1;i<=n;i++){

        if(viz[i]==0){

            dfs1(i);

        }

    }

    for(int i=1;i<=n;i++){

        viz[i]=0;

    }

    for(int i=n;i>=1;i--){

        if(viz[order[i]]==0){

            cnt++;

            dfs2(order[i]);

        }

    }

    cout<<cnt<<"\n";

    for(int i=1;i<=cnt;i++){

        for(auto j:comp[i]){

            cout<<j<<" ";

        }

        cout<<"\n";

    }

 return 0;

}
