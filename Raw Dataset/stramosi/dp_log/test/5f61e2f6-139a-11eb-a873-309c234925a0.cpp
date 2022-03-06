#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

ifstream fin("stramosi.in");

ofstream fout("stramosi.out");



int n, m, k, t, i, j, d[25][250010], aux, p, nod;







int main(){

    fin>>n>>t;

    for(i=1; i<=n; i++){

        fin>>d[0][i];

    }

    for(i=1; i<=20; i++){

        for(j=1; j<=n; j++){

            aux=d[i-1][j];

            d[i][j]=d[i-1][aux];

        }

    }

    for(; t; t--){

        fin>>nod>>p;

        for(i=0; (1<<i)<=p; i++){

            if(p&(1<<i)){

                nod=d[i][nod];

            }

        }

        fout<<nod<<"\n";

    }

}
