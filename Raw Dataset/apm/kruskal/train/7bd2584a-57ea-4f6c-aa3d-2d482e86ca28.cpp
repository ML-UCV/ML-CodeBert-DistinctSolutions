#include<iostream>
#include<fstream>
#include<vector>
#include<limits.h>
#include<algorithm>
#include<queue>


using namespace std;



ifstream f("apm.in");

ofstream o("apm.out");



int n,m,cost=0,t[200010],r[200010]; bool viz[200010];

struct muchie{int x,y,c;};

vector <muchie> v;

vector <pair<int,int> > p;



bool conditie(muchie a,muchie b){

    return a.c<b.c;

}

void citire(){

    f>>n>>m; int i,x,y,c;

    for(i=1;i<=m;i++){

        f>>x>>y>>c;

        v.push_back({x,y,c});

    }

    sort(v.begin(),v.end(),conditie);

    for(i=1;i<=n;i++)

        t[i]=i,r[i]=1;

}

int tata(int nod){

    while(t[nod]!=nod)

        nod=t[nod];

    return nod;

}

void unire(int t1,int t2){

    if(r[t1]<r[t2]) t[t1]=t2;

    else if(r[t2]<r[t1]) t[t2]=t1;

    else{

        t[t1]=t2; r[t2]++;

    }

}

void apm(){

    int i,t1,t2;

    for(i=0;i<m;i++){

        t1=tata(v[i].x);

        t2=tata(v[i].y);

        if(t1!=t2){

            unire(t1,t2);

            cost+=v[i].c;

            p.push_back(make_pair(v[i].x,v[i].y));

        }

    }

}

int main(){

    citire();

    apm();

    o<<cost<<'\n'<<p.size()<<'\n';

    int i;

    for(i=0;i<p.size();i++)

        o<<p[i].first<<" "<<p[i].second<<'\n';

    o.close();

    f.close();

}
