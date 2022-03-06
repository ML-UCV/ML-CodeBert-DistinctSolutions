#include <bits/stdc++.h>
using namespace std;



ifstream ci("apm.in");

ofstream cou("apm.out");



struct date{

    int x,y,cost;

};



int n,m;

int t[200005];

int cn;

int k;

date sol[400005];

date v[400005];



int Find(int x){

    int r=x,p,r1;

    while(t[r]){

        r=t[r];

    }

    p=r;

    r=x;

    while(t[r]){

        r1=t[r];

        t[r]=p;

        r=r1;

    }

    return p;

}

void Union(int x,int y){

    t[y]=x;

}



bool cmp(date a,date b){

    return a.cost<b.cost;

}



void citire(){

    int i;

    ci>>n>>m;

    for(i=1;i<=m;i++){

       ci>>v[i].x>>v[i].y>>v[i].cost;

    }

    sort(v+1,v+m+1,cmp);

}



void rez(){

    int i,x,y,s=0;

    for(i=1;i<=m;i++){

        x=v[i].x;

        y=v[i].y;

        if(Find(x)!=Find(y)){

            if(Find(x)!=x){

                cn++;

            }

            if(Find(y)!=y){

                cn++;

            }

            s+=v[i].cost;

            Union(Find(x),Find(y));

            sol[++k].x=x;

            sol[k].y=y;



        }

        if(cn==n){

            break;

        }

    }

    cou<<s<<"\n"<<k<<"\n";

    for(i=1;i<=k;i++){

        cou<<sol[i].x<<" "<<sol[i].y<<"\n";

    }



}



int main()

{

    citire();

    rez();

    return 0;

}
