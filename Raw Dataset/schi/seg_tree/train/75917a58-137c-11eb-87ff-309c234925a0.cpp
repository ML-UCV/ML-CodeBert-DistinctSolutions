#include<fstream>


using namespace std;



ifstream f ("schi.in");

ofstream g ("schi.out");

int v[300607],i,j,clasament[300607],ordine[300607],n;

void build(int nod,int st,int dr)

{

    if(st==dr)

    {

        v[nod]=1;

        return;

    }

    int mij=(st+dr)/2;

    build(nod*2,st,mij);

    build(nod*2+1,mij+1,dr);

    v[nod]=v[nod*2]+v[nod*2+1];

}

void update(int nod,int st,int dr,int val,int pos)

{

    if(st==dr)

    {

        v[nod]=val;

        return;

    }

    int mij=(st+dr)/2;

    if(pos<=mij)

        update(nod*2,st,mij,val,pos);

    else

        update(nod*2+1,mij+1,dr,val,pos);

    v[nod]=v[nod*2]+v[nod*2+1];

}

int query(int nod,int st,int dr,int val)

{

    if(st==dr)

      return st;

    int mij=(st+dr)/2;

    if(val<=v[nod*2])

         query(nod*2,st,mij,val);

    else

        query(nod*2+1,mij+1,dr,val-v[nod*2]);

}

int main()

{

 f>>n;

 for(i=1;i<=n;i++)

     f>>ordine[i];

build(1,1,n);

for(i=n;i>=1;i--)

{

   int pozitie=query(1,1,n,ordine[i]);

   clasament[pozitie]=i;

   update(1,1,n,0,pozitie);

}

for(i=1;i<=n;i++)

     g<<clasament[i]<<'\n';

}
