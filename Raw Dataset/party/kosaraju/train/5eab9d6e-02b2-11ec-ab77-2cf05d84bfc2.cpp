#include<cstdio>
#include<vector>


using namespace std;

vector<int> g[2*110],gt[2*110];

int n,current=0;

int order[2*110],seen[2*110],answer[2*110];

void AddEdge(int x,int y){

    g[x].push_back(y);

    gt[y].push_back(x);

}

int Non(int x){

    if(x<=n)

        return x+n;

    return x-n;

}

void Or(int x,int y){

    AddEdge(Non(x),y);

    AddEdge(Non(y),x);

}

void FirstDFS(int node){

    int i;

    seen[node]=1;

    for(i=0;i<g[node].size();i++)

        if(seen[g[node][i]]==0)

            FirstDFS(g[node][i]);

    current++;

    order[current]=node;

}

void SecondDFS(int node){

    int i;

    seen[node]=0;

    answer[Non(node)]=1;

    for(i=0;i<gt[node].size();i++)

        if(seen[gt[node][i]]==1)

            SecondDFS(gt[node][i]);

}

int main(){

    freopen("party.in","r",stdin);

    freopen("party.out","w",stdout);

    int m,x,y,z,i;

    scanf("%d%d",&n,&m);

    for(i=1;i<=m;i++){

        scanf("%d%d%d",&x,&y,&z);

        if(z==0)

            Or(x,y);

        if(z==1)

            Or(x,Non(y));

        if(z==2)

            Or(Non(x),y);

        if(z==3)

            Or(Non(x),Non(y));

    }

    for(i=1;i<=2*n;i++)

        if(seen[i]==0)

            FirstDFS(i);

    for(i=current;i>=1;i--)

        if(seen[order[i]]==1&&seen[Non(order[i])]==1)

            SecondDFS(order[i]);

    current=0;

    for(i=1;i<=n;i++)

        if(answer[i]==1)

            current++;

    printf("%d\n",current);

    for(i=1;i<=n;i++)

        if(answer[i]==1)

            printf("%d\n",i);

    return 0;

}
