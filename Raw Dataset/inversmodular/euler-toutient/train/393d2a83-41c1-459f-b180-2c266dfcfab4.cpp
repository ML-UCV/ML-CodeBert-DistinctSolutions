#include <bits/stdc++.h>
using namespace std;



const long long mod=1e9+7;



long long a,n;



long long phi(long long x){

    long long rs=x;

    for(long long i=2LL;i*i<=x;i++){

        if(x%i==0LL){

            rs=((rs/i)*(i-1LL));

            while(x%i==0LL) x/=i;

        }

    }

    if(x>=2LL) rs=((rs/x)*(x-1LL));

    return rs;

}



long long lgp(long long a,long long b){

    if(b==0LL) return 1LL;

    else if(b==1LL) return (a%n);

    else{

        long long cc=(lgp(a,b/2LL)%n);

        if(b%2LL==1LL) return ((((cc%n)*(cc%n))%n)*(a%n))%n;

        else return ((cc%n)*(cc%n))%n;

    }

}



int32_t main(){



    srand(chrono::steady_clock::now().time_since_epoch().count());

    ifstream fin("inversmodular.in");

    ofstream fout("inversmodular.out");

    fin >> a >> n;

    fout << lgp(a,phi(n)-1LL)%n;

}
