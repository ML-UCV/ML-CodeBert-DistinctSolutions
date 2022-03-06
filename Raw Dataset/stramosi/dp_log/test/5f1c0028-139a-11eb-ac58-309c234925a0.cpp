#include <fstream>
#include <iostream>
using namespace std;



ifstream fin("stramosi.in");

ofstream fout("stramosi.out");



int n,m,v[20][250001],i,j,p[20],x,cnt;



int main(){

    fin>>n>>m;



    for(i=1;i<=n;i++){

        fin>>v[0][i];

    }

    p[0]=1;



    for(cnt=1,j=2;j<=n;cnt++,j*=2){

        p[cnt]=j;



        for(i=1;i<=n;i++)

            v[cnt][i]=v[cnt-1][ v[cnt-1][i] ];

    }

    cnt--;
    for(;m;m--){

        fin>>i>>x;



        while(x){

            j=0;

            while(2*p[j]<=x){

                j++;

            }





            i=v[j][i];

            x-=p[j];

        }



        fout<<i<<"\n";

    }



    return 0;

}
