#include <fstream>
#include <vector>


using namespace std;

ifstream cin("party.in");

ofstream cout("party.out");

bool viz[205];

int order[205],ctc[205],cnt,cont;

vector <int> v[205],v1[205];

void add(int a,int b){

    v[a].push_back(b);

    v1[b].push_back(a);

}

void dfs1(int w){

    viz[w]=1;

    for(auto u:v[w]){

        if(viz[u]==0){

            dfs1(u);

        }

    }

    order[++cont]=w;

}

void dfs2(int w){

    viz[w]=1;

    ctc[w]=cnt;

    for(auto u:v1[w]){

        if(viz[u]==0){

            dfs2(u);

        }

    }

}

int main()

{

    int n,m,a,b,t;

    cin>>n>>m;

    for(int i=1;i<=m;i++){

        cin>>a>>b>>t;

        if(t==0){

            add(a+n,b);

            add(b+n,a);

        }

        if(t==1){

            add(a+n,b+n);

            add(b,a);

        }

        if(t==2){

            add(a,b);

            add(b+n,a+n);

        }

        if(t==3){

            add(a,b+n);

            add(b,a+n);

        }

    }

    for(int i=1;i<=2*n;i++){

        if(viz[i]==0){

            dfs1(i);

        }

    }

    for(int i=1;i<=2*n;i++){

        viz[i]=0;

    }

    for(int i=2*n;i>=1;i--){

        if(viz[order[i]]==0){

            cnt++;

            dfs2(order[i]);

        }

    }

    int sum=0;

    for(int i=1;i<=n;i++){

        sum+=(ctc[i]>ctc[i+n]);

    }

    cout<<sum<<"\n";

    for(int i=1;i<=n;i++){

        if(ctc[i]>ctc[i+n])

            cout<<i<<"\n";

    }

    return 0;

}
