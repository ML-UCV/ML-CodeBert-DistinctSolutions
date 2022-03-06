#include <bits/stdc++.h>


using namespace std;

long long t;

long long a,b,c;

long long gcd(long long a,long long b,long long &X,long long &Y){

    if(b==0){

        X=1;

        Y=0;

        return a;

    }

    else{

        long long X0=0,Y0=0,D=0;

        D=gcd(b,a%b,X0,Y0);

        long long tz=X0;

        X=Y0;

        Y=(X0-(a/b)*Y0);

        return D;

    }

}

int32_t main() {

    ifstream fin("inversmodular.in");

    ofstream fout("inversmodular.out");



        fin>>a>>b;

        long long x=0,y=0;

        long long w=gcd(a,b,x,y);



        long long ans=x;

        ans=ans%b;

        while(ans<0) ans+=b;

        fout<<ans<<"\n";





    return 0;

}
