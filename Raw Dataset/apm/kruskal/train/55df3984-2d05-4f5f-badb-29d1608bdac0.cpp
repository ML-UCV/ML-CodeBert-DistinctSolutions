#include <bits/stdc++.h>


using namespace std;

ifstream in("apm.in");

ofstream out("apm.out");

const int MAX=200001;

int n,m,tata[MAX],cnt,cost;

bool sel[MAX];

struct muchie

{

    int x,y,c;

}v[MAX];



bool cmp(muchie a, muchie b)

{

    return a.c<b.c;

}



int radacina(int nod)

{

    if(tata[nod]==nod) return nod;

    int ans;

    ans=radacina(tata[nod]);

    tata[nod]=ans ;

    return ans;

}

int main()

{



    in>>n>>m;

    for(int i=1;i<=n;i++) tata[i]=i;

    for(int i=1;i<=m;i++) in>>v[i].x>>v[i].y>>v[i].c;

    sort(v+1,v+m+1,cmp);



    for(int i=1;i<=m;i++)

    {

        if(radacina(v[i].x)!=radacina(v[i].y))

        {

            sel[i]=true;

            cnt++;

            cost+=v[i].c;

            tata[radacina(v[i].x)]=radacina(v[i].y);



        }

    }



    out<<cost<<"\n"<<cnt<<"\n";

    for(int i=1;i<=m;i++)

    {

        if(sel[i]==true) out<<v[i].x<<" "<<v[i].y<<"\n";

    }

    return 0;

}
