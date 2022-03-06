#include <bits/stdc++.h>


using namespace std;

ifstream fin("apm.in");

ofstream fout("apm.out");



int n,m,a,b,c,conexe,suma,cnt,rasp[500005];

int tata[500005],conex[500005];



int grupa(int i)

{

    if(conex[i]==i)return i;

    conex[i]=grupa(conex[i]);

    return conex[i];

}

void reuniune(int i,int j)

{

    conex[grupa(i)]=grupa(j);

}



struct triplet

{

    int x,y,cost;

};



triplet muchie[500005];

bool cmp(triplet i,triplet j)

{

    return i.cost<j.cost;

}

int main()

{

    fin>>n>>m;

    for(int i=1;i<=m;i++)

    {

        fin>>muchie[i].x>>muchie[i].y>>muchie[i].cost;

        tata[i]=i;

        conex[i]=i;

    }

    sort(muchie+1,muchie+m+1,cmp);

    for(int i=1;i<=m;i++)

    {

        int a=muchie[tata[i]].x;

        int b=muchie[tata[i]].y;

        if(grupa(a)!=grupa(b))

        {

            suma+=muchie[i].cost;

            cnt++;

            rasp[cnt]=i;

            reuniune(a,b);

        }

    }

    fout<<suma<<'\n';

    fout<<cnt<<'\n';

    for(int i=1;i<=cnt;i++)

        fout<<muchie[rasp[i]].x<<" "<<muchie[rasp[i]].y<<'\n';

}
