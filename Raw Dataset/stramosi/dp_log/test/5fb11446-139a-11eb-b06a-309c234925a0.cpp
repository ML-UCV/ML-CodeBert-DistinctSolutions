#include <iostream>
#include <fstream>




using namespace std;



ifstream f("stramosi.in");

ofstream o("stramosi.out");



int n,m,t,d[20][250002],q,p,i,k,putere;



int main()

{

    f >> n >> m;

    for(i=1;i<=n;++i)

        f >> d[0][i];



    for(k=1;(1<<k)<=n;++k)

        for(i=1;i<=n;++i)

            d[k][i]=d[k-1][d[k-1][i]];



    for(i=1;i<=m;++i){

        f >> q >> p;



        putere=0;

        while(p>0){

            if(p&1)

                q=d[putere][q];

            ++putere;

            p>>=1;

        }

        o << q << '\n';

    }

    return 0;

}
