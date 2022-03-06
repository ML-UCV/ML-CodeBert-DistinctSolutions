#include <fstream>
using namespace std;



const int maxN=1e5+1;



int n;

int v[maxN];



int aint[4*maxN];

int sol[maxN];



void update(int nod,int st,int dr,int pos){

    if(st==dr){

        aint[nod]=1;

        return;

    }



    int mij=(st+dr)/2;



    if(pos<=mij){

        update(2*nod,st,mij,pos);

    } else {

        update(2*nod+1,mij+1,dr,pos);

    }



    aint[nod]=aint[2*nod]+aint[2*nod+1];

}



int query(int nod,int st,int dr,int k){

    if(st==dr){

        return st;

    }



    int mij=(st+dr)/2;

    int cntEmpty=(mij-st+1) - aint[2*nod];



    if(cntEmpty >= k){

        return query(2*nod,st,mij,k);

    } else {

        return query(2*nod+1,mij+1,dr,k-cntEmpty);

    }

}



int main(){

    ifstream cin("schi.in");

    ofstream cout("schi.out");



    cin>>n;

    for(int i=1;i<=n;i++){

        cin>>v[i];

    }



    for(int i=n;i>=1;i--){

        int where=query(1,1,n,v[i]);



        sol[where]=i;

        update(1,1,n,where);

    }



    for(int i=1;i<=n;i++){

        cout<<sol[i]<<'\n';

    }



    return 0;

}
