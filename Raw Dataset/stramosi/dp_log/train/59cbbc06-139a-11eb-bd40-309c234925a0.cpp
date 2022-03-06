#include <iostream>
#include <fstream>
#include <vector>




using namespace std;



ifstream fin("stramosi.in");

ofstream fout("stramosi.out");



int n,m,mat[20][250000 +5],q,p;



int main()

{

    int i,j;

    fin>>n>>m;

    for(i=1;i<=n;i++){

        fin>>mat[0][i];

    }

    for(j=1;j<=17;j++){

        for(i=1;i<=n;i++){

            mat[j][i]=mat[j-1][mat[j-1][i]];

        }

    }

    while(m--){

        fin>>q>>p;

        for( j=17;j>=0;j--){

            if((1<<j)<=p){

                q=mat[j][q];

                p=p-(1<<j);

            }

        }

        fout<<q<<'\n';

    }



    return 0;

}
