#include <bits/stdc++.h>
#include <cstring>






using namespace std;

ifstream f("apm.in");

ofstream g("apm.out");

int nod,n,i,j,t[200000],aux,r[200000],m,x,y,c,xx,yy,sum;

struct muchie{

int x,y,c;};

vector <muchie> v;

vector <pair<int,int> > sol;

bool comp( const muchie a, const muchie b )

{return a.c<b.c;}



int findd(int x)

{ nod=x;

    while(t[x]!=x)

        x=t[x];



while(t[nod]!=nod)

{

    aux=t[nod];

    t[nod]=x;

    nod=aux;

}

return x;

}



void unionn(int a,int b)

{

    if(r[a]>r[b])

        t[b]=a;

    if(r[a]<r[b])

        t[a]=b;

    if(r[a]==r[b])

    {

        r[a]++;

        t[b]=a;

    }

}







int main()

{



   f>>n>>m;



   for(i=1;i<=n;i++)

   {

       t[i]=i;

       r[i]=1;

   }

   for(i=1;i<=m;i++)

   {

       f>>x>>y>>c;

       v.push_back({x,y,c});

   }

    sort(v.begin(),v.end(),comp);



   for(i=0;i<v.size();i++)

    {

        xx=findd(v[i].x);

        yy=findd(v[i].y);

        if(xx!=yy)

        {

            unionn(xx,yy);

            sum+=v[i].c;



            sol.push_back({v[i].x,v[i].y});

        }

    }

g<<sum<<"\n"<<sol.size()<<"\n";

for(i=0;i<sol.size();i++)

    g<<sol[i].first<<" "<<sol[i].second<<"\n";

    return 0;

}
