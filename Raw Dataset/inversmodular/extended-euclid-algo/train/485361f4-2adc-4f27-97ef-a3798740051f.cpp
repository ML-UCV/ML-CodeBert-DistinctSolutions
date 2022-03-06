#include <bits/stdc++.h>


using namespace std;



string file="inversmodular";

ifstream fin(file+".in");

ofstream fout(file+".out");



typedef long long ll;



int N,A;

ll inv,ins;



void gcd(ll &x,ll &y,ll a,ll b)

{

    if(!b){

        x=1; y=0;

    }

    else{

        gcd(x,y,b,a%b);

        ll aux=x;

        x=y;

        y=aux-y*(a/b);

    }

}



int main()

{

    fin>>A>>N;

    gcd(inv,ins,A,N);

    if(inv<=0){

        inv=N+inv%N;

    }

    fout<<inv;

    return 0;

}
