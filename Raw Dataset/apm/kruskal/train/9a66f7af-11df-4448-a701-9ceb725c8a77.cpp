#include<stdio.h>
#include<algorithm>
#include<fstream>


using namespace std;







ifstream fin("apm.in");

ofstream fout("apm.out");



struct edges

{

    int x,y;

    short int c;

};







int n,m;

edges v[400010];

int ind[400010],t[200010],gr[200010];

int cost,rez[200010];



void read()

{

    fin>>n>>m;

    for(int i=0; i<m; ++i)

    { fin>>v[i].x>>v[i].y>>v[i].c;

        ind[i]=i;

    }

}



int find(int x)

{

    int r=x;

    for(; t[r]!=r; r=t[r])

        ;

    while(t[x]!=x)

    {

        int aux=t[x];

        t[x]=r;

        x=aux;

    }

    return r;

}



void reuniune(int x,int y)

{

    if(gr[x]<gr[y])

        t[x]=y;

    else

        t[y]=x;

    if(gr[x]==gr[y])

        ++gr[x];

}



bool compar(const int &x,const int &y)

{

    return (v[x].c<v[y].c);

}



void solve()

{

    for(int i=1; i<=n; ++i)

    {

        t[i]=i;

        gr[i]=1;

    }



    sort(ind,ind+m,compar);

    int n1=n-1;



    for(int i=0; i<m && rez[0]!=n1; ++i)

    {

        int nod=ind[i];

        if(find(v[nod].x)!=find(v[nod].y))

        {

            cost+=v[nod].c;

            rez[++rez[0]]=nod;

            reuniune(find(v[nod].x),find(v[nod].y));

        }

    }

}



void print()

{

    fout<<cost<<endl<<n-1<<endl;

    for(int i=1; i<=rez[0]; ++i)

        fout<<v[rez[i]].x<<" "<<v[rez[i]].y<<endl;



}



int main()

{



    read();

    solve();

    print();

    fin.close();

    fout.close();

    return 0;

}
