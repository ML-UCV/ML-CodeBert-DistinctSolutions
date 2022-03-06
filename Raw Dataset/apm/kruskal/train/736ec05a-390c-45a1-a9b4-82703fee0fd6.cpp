#include <iostream>
#include <fstream>
#include <algorithm>






using namespace std;



ifstream f("apm.in");

ofstream o("apm.out");



struct muchie{

    int x,y,c;

} g[400001];



int k,n,m,x,y,c,rang[200001],t[200001],rez,s[400001],nr;



inline bool cmp(const muchie a,const muchie b){

    return a.c<b.c;

}



int multime(int nod){

    if(t[nod]!=nod)

        t[nod]=multime(t[nod]);

    return t[nod];

}



void reuneste(int i,int j){

    i=multime(i);

    j=multime(j);



    if(i==j) return;



    if(rang[i]<rang[j]) t[i]=j;

    else t[j]=i;

    if(rang[i]==rang[j]) ++rang[i];

}



void apm(){

    int i,j;

    for(k=1;k<=m;++k)

        t[k]=k;

    for(k=1;k<=m;++k){

        i=g[k].x;

        j=g[k].y;

        c=g[k].c;

        if(multime(i)!=multime(j)){

            s[++nr]=k;

            rez+=c;

            reuneste(i,j);

        }

    }

}



int main()

{

    int i;

    f>>n>>m;

    for(i=1;i<=m;++i)

        f>>g[i].x>>g[i].y>>g[i].c;



    sort(g+1,g+m+1,cmp);



    apm();

    o << rez << '\n' << n-1 << '\n';

    for(i=1;i<=nr;++i){

        k=s[i];

        o << g[k].x << " " << g[k].y << '\n';

    }

    return 0;

}
