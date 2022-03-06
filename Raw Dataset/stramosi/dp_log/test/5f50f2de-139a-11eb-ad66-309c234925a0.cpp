#include <iostream>
#include <fstream>
#include <map>


using namespace std;

ifstream fin("stramosi.in");

ofstream fout("stramosi.out");

int d[19][250004];

int n,m,i,p,a,b,j;

int main()

{

 fin>>n>>m;



 for(i=1;i<=n;i++){

    fin>>d[0][i];

 }

 for(i=1;i<=18;i++){

   for(j=1;j<=n;j++){

    d[i][j]=d[i-1][d[i-1][j]];

   }

 }

 for(i=1;i<=m;i++){

    fin>>a>>b;

    p=0;

    while(b){

        if(b&(1<<p)){

            a=d[p][a];

            b-=(1<<p);

        }

        p++;

    }

    fout<<a<<"\n";

 }

}
