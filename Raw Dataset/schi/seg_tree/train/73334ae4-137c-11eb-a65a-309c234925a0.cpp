#include<fstream>
using namespace std;

ifstream fin("schi.in");

ofstream fout("schi.out");

int n,i;

int v[30010],loc[30010],a[90010];



void build(int st, int dr, int nod){

    if(st==dr)

        a[nod]=1;

    else{

        int mid=(st+dr)/2;

        build(st,mid,2*nod);

        build(mid+1,dr,2*nod+1);

        a[nod]=a[2*nod]+a[2*nod+1];

    }

}



void clasament(int st, int dr, int nod,int poz2){

    if(st==dr){

        a[nod]=0;

        loc[st]=i;

    }

    else{

        int mid=(st+dr)/2;

        if(a[2*nod]>=poz2){

            clasament(st,mid,2*nod,poz2);

        }

        else{

            clasament(mid+1,dr,2*nod+1,poz2-a[2*nod]);

        }

        a[nod]=a[2*nod]+a[2*nod+1];

    }

}



int main(){

    fin>>n;

    for(int i=1;i<=n;i++){

        fin>>v[i];

    }

    build(1,n,1);

    for(i=n;i>=1;i--)

        clasament(1,n,1,v[i]);

    for(int i=1;i<=n;i++)

        fout<<loc[i]<<"\n";

    return 0;

}
