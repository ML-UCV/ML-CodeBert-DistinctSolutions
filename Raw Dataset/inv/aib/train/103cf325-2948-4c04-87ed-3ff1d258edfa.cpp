#include <fstream>
#include <algorithm>






using namespace std;

ifstream fin("inv.in");

ofstream fout("inv.out");



int n,i,a,b,k,v[100005],aint[3*100005],nr,sol,poz;

struct numar{

    int x,p;

}aa[100005];

int cmp(numar a, numar b){

    if(a.x==b.x)

        return a.p<b.p;

    return a.x<b.x;

}



void update(int nod, int st, int dr){

    if(st==dr){

        aint[nod]++;

        if(aint[nod]==9917)

            aint[nod]=0;

        return;

    }

    int mij=(st+dr)/2;

    if(poz<=mij)

        update(2*nod,st,mij);

    else

        update(2*nod+1,mij+1,dr);

    aint[nod]=aint[2*nod]+aint[2*nod+1];

    if(aint[nod]>9917)

        aint[nod]-=9917;

}



void query(int nod, int st, int dr){

    if(a<=st && dr<=b){

        nr+=aint[nod];

        if(nr>=9917)

            nr-=9917;

        return;

    }

    else{

        int mid=(st+dr)/2;

        if(a<=mid)

            query(2*nod,st,mid);

        if(b>mid)

            query(2*nod+1,mid+1,dr);

    }

}



int main()

{

    fin>>n;

    for(i=1;i<=n;i++){

        fin>>aa[i].x;

        aa[i].p=i;

    }

    sort(aa+1,aa+n+1,cmp);

    k=1;

    for(i=1;i<=n;i++){

        if(aa[i].x!=aa[i-1].x)

            k++;

        v[aa[i].p]=k;

    }

    for(i=1;i<=n;i++){

        a=v[i]+1; b=k;

        nr=0;

        query(1,1,k);

        sol+=nr;

        if(sol>=9917)

            sol-=9917;

        poz=v[i];

        update(1,1,k);

    }

    fout<<sol;

    return 0;

}
