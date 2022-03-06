#include <fstream>


using namespace std;

ifstream f("schi.in");

ofstream g("schi.out");

int n,v[30004],sol[30004],tree[4*30004];

void init (int node,int low,int hi,int pos)

{

    if (low==hi)

    {

        tree[node]=1;

        return;

    }

    int mid=(low+hi)/2,nodes=2*node;

    if (pos<=mid) init(nodes,low,mid,pos);

    else init(nodes+1,mid+1,hi,pos);

    tree[node]=tree[nodes]+tree[nodes+1];

}

void update (int node,int low,int hi,int pos,int val)

{

    if (low==hi)

    {

        sol[low]=val;

        tree[node]=0;

        return;

    }

    int mid=(low+hi)/2,nodes=2*node;

    if (pos<=tree[nodes]) update(nodes,low,mid,pos,val);

    else update(nodes+1,mid+1,hi,pos-tree[nodes],val);

    tree[node]=tree[nodes]+tree[nodes+1];

}

int main()

{

    f>>n;

    for (int i=1;i<=n;i++) f>>v[i];

    for (int i=1;i<=n;i++) init(1,1,n,i);

    for (int i=n;i>=1;i--) update(1,1,n,v[i],i);

    for (int i=1;i<=n;i++) g<<sol[i]<<'\n';

    f.close();

    g.close();

    return 0;

}
