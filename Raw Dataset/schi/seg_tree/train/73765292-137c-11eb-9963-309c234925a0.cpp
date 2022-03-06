#include <fstream>
using namespace std;



int C[30001],L[30001];

int V[30001*3];



int n,i;







void cre(int st, int dr, int nod){

    int mij;

    if (st==dr){

        V[nod] = 1;

    }

    else{

        mij = (st+dr)/2;

        cre(st, mij, 2*nod);

        cre(mij+1, dr, 2*nod+1);

        V[nod] = V[2*nod]+V[2*nod+1];

    }

}



void cautSiCorect(int st, int dr, int nod, int c, int poz){

    int mij;

    if (st==dr){

        V[nod] = 0;

        L[st] = c;

    }

    else{

        mij = (st+dr)/2;

        if (V[2*nod]>=poz)

            cautSiCorect(st,mij,2*nod,c,poz);

        else

            cautSiCorect(mij+1,dr,2*nod+1,c,poz-V[2*nod]);

        V[nod] = V[2*nod]+V[2*nod+1];

    }

}



int main(){

    ifstream fin("schi.in");

    ofstream fout("schi.out");

    fin>>n;

    for (i=1; i<=n; i++){

        fin>>C[i];

    }



    cre(1,n,1);



    for (i=n; i>=1; i--){

        cautSiCorect(1,n,1,i,C[i]);

    }





    for (i=1; i<=n; i++){

        fout<<L[i]<<"\n";

    }



    return 0;

}
