#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin("apm.in");

ofstream fout("apm.out");



struct ura{

    int x,y,c;

}v[400001],a[200001];

int sef[200001];



bool cmp(ura a,ura b){

    return a.c<b.c;

}



int sefsuprem(int poz){

    if(sef[poz]==poz)

        return poz;

    return sef[poz]=sefsuprem(sef[poz]);

}



int main(){

    int i,n,m,s=0,k=1;

    fin>>n>>m;

    for(i=1;i<=m;i++)

        fin>>v[i].x>>v[i].y>>v[i].c;

    for(i=1;i<=n;i++)

        sef[i]=i;

    sort(v+1,v+m+1,cmp);

    for(i=1;i<=m && k<=n-1;i++)

        if(sefsuprem(v[i].x)!=sefsuprem(v[i].y)){

            a[k]=v[i];

            sef[sefsuprem(v[i].y)]=sefsuprem(v[i].x);

            s=s+v[i].c;

            k++;

        }

    fout<<s<<"\n";

    fout<<n-1<<"\n";

    for(i=1;i<n;i++)

        fout<<a[i].x<<" "<<a[i].y<<"\n";

    return 0;

}
