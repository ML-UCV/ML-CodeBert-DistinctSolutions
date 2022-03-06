#include <fstream>
#include <queue>


using namespace std;



ifstream fin("swap.in");

ofstream fout("swap.out");



const int sigma= 26;

const int nmax= 50000;



int ft[nmax+1], f1[sigma];



char a[nmax+2], b[nmax+2];

queue <int> v[sigma];



void update( int p, int n ) {

    for ( ; p<=n; p= 2*p-(p&(p-1)) ){

        ++ft[p];

    }

}



int query( int p ) {

    int sol= 0;

    for ( ; p>0; p&= (p-1) ) {

        sol+= ft[p];

    }

    return sol;

}



int main( ) {

    int ans= 0;

    fin.getline(a, nmax+2);

    fin.getline(b, nmax+2);



    int n;

    for ( n= 0; a[n]>='a' && a[n]<='z'; ++n ) {

        ++f1[a[n]-'a'], --f1[b[n]-'a'];

    }

    for ( int i= 0; i<sigma; ++i ) {

        if ( f1[i]!=0 ) {

            fout<<"-1\n";

            return 0;

        }

    }



    for ( int i= 0; i<n; ++i ) {

        v[a[i]-'a'].push(i+1);

    }



    for (int i= 0; i<n; ++i){

        int x= v[b[i]-'a'].front();

        v[b[i]-'a'].pop();

        ans+= x-query(x)-1;

        update(x, n);

    }



    fout<<ans<<"\n";



    return 0;

}
