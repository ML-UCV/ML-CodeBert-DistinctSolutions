#include <fstream>
#include <iostream>
using namespace std;

ifstream fin("schi.in");

ofstream fout("schi.out");

int A[90000],n,x[30000],sol[30000];

void creare(int st,int dr,int nod){

    if(st==dr){

        A[nod]=1;



    }

    else{

        int mid=(st+dr)/2;

        creare(st,mid,2*nod);

        creare(mid+1,dr,2*nod+1);

        A[nod]=A[2*nod]+A[2*nod+1];





    }





}



void update(int st, int dr, int nod,int poz,int k){

    if(st==dr){

        sol[st]=k;

        A[nod]=0;

    }

    else{

        int mid=(st + dr)/2;

        if(A[2*nod]>=poz){

            update(st,mid,2*nod,poz,k);

        }

        else{

            update(mid+1,dr,2*nod+1,poz-A[2*nod],k);

        }

        A[nod]=(A[2*nod]+A[2*nod+1]);

    }

}



int main(){

    fin>>n;

    for(int i=1;i<=n;i++){

        fin>>x[i];

    }



    creare(1,n,1);



    for(int i=n;i>=1;i--){

        update(1,n,1,x[i],i);

    }

    for(int i=1;i<=n;i++){

        fout<<sol[i]<<"\n";

    }







}
