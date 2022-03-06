#include <fstream>
using namespace std;

ifstream fin("schi.in");

ofstream fout("schi.out");



int n, i, a[100010], v[30010], sol[30010];



void initializeaza(int st, int dr, int nod){

    if(st==dr){

        a[nod]=1;

    }else{

        int mid=(st+dr)/2;

        initializeaza(st, mid, nod*2);

        initializeaza(mid+1, dr, nod*2+1);

        a[nod]=a[nod*2]+a[nod*2+1];

    }

}



void gaseste(int st, int dr, int nod, int pozCautata){

    if(st==dr){

        a[nod]=0;

        sol[st]=i;

    }else{

        int mid=(st+dr)/2;

        if(a[2*nod]>=pozCautata){



            gaseste(st, mid, 2*nod, pozCautata);

        }else{





            gaseste(mid+1, dr, 2*nod+1, pozCautata-a[2*nod]);

        }

        a[nod]=a[2*nod]+a[2*nod+1];

    }

}



int main(){

    fin>>n;

    for(i=1; i<=n; i++){

        fin>>v[i];

    }

    initializeaza(1, n, 1);

    for(i=n; i>0; i--){

        gaseste(1, n, 1, v[i]);

    }

    for(i=1; i<=n; i++){

        fout<<sol[i]<<"\n";

    }

}
