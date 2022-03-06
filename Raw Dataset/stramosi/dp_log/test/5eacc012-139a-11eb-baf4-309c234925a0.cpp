#include <fstream>
using namespace std;

ifstream fin("stramosi.in");

ofstream fout("stramosi.out");

int n,q,i,j,D[20][250010],a,b;

int main(){

    fin>>n>>q;

    for(i=1;i<=n;i++)

        fin>>D[0][i];

    for(i=1;i<=19;i++){

        for(j=1;j<=n;j++)

            D[i][j]=D[i-1][D[i-1][j]];

    }

    for(;q--;){

        fin>>a>>b;

        for(i=0;(1<<i)<=b;i++)

            if(b&(1<<i))

                a=D[i][a];

        fout<<a<<"\n";

    }

    return 0;

}
