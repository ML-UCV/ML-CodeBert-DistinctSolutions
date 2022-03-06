#include <bits/stdc++.h>
using namespace std;



const long long mod=1e9+7;



long long a,n;



void invers(long long a,long long b,long long &X,long long &Y){

    if(b==0){ X=1;Y=0;}

    else{

        invers(b,a%b,X,Y);

        long long tz=X;

        X=Y;

        Y=tz-(a/b)*Y;

    }

}



int32_t main(){



    srand(chrono::steady_clock::now().time_since_epoch().count());

    ifstream fin("inversmodular.in");

    ofstream fout("inversmodular.out");

    fin >> a >> n;

    long long X0=0,Y0=0;

    invers(a,n,X0,Y0);

    X0=X0%n;

    if(X0<0) X0+=n;

    fout << X0 << '\n';

}
