#include <fstream>


using namespace std;



ifstream fin("party.in");

ofstream fout("party.out");



const int nmax= 100;

const int mmax= 1000;



int n, m, sol;



bool u[nmax+1];

int x[mmax+1], y[mmax+1];



int main( ) {

    fin>>n>>m;

    for ( int i= 1, k; i<=m; ++i ) {

        fin>>x[i]>>y[i]>>k;

        if ( k==1 || k==3 ) {

            x[i]= -x[i];

        }

        if ( k==2 || k==3 ) {

            y[i]= -y[i];

        }

    }

    for ( int i= 1; i<=n; ++i ) {

        u[i]= 1;

    }



    for ( int ok= 0; ok==0; ) {

        ok= 1;

        for ( int i= 1; i<=m && ok==1; ++i ) {

            if ( x[i]>0 && y[i]>0 && u[x[i]]==0 && u[y[i]]==0 ) {

                u[x[i]]= u[y[i]]= 1;

                ok= 0;

            } else if ( x[i]<0 && y[i]>0 && u[-x[i]]==0 && u[y[i]]==1 ) {

                u[y[i]]^= 1;

                ok= 0;

            } else if ( x[i]>0 && y[i]<0 && u[x[i]]==1 && u[-y[i]]==0 ) {

                u[x[i]]^= 1;

                ok= 0;

            } else if ( x[i]<0 && y[i]<0 && u[-x[i]]==1 && u[-y[i]]==1 ) {

                u[-y[i]]^= 1;

                ok= 0;

            }

        }

    }



    for ( int i= 1; i<=n; ++i ) {

        if ( u[i]==1 ) {

            ++sol;

        }

    }



    fout<<sol<<"\n";

    for ( int i= 1; i<=n; ++i ) {

        if ( u[i]==1 ) {

            fout<<i<<"\n";

        }

    }



    return 0;

}
