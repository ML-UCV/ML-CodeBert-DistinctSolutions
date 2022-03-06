#include <bits/stdc++.h>


using namespace std;



ifstream fin("inversmodular.in");

ofstream fout("inversmodular.out");



long long A,n,rez,P = 1,MOD;



int main(){

    int i;

    fin>>A>>n;

    rez = n;

    MOD = n;

    if(n%2 == 0){

        while(n%2 == 0){

            n/=2;

        }

        rez = rez/2;

    }

    for(i = 3; i*i <= n; i+=2){

        if(n%i == 0){

            while(n%i == 0){

                n/=i;

            }

            rez = rez - rez/i;

        }

    }

    if(n > 1){

        rez = rez-rez/n;

    }

    rez--;

    while(rez != 0){

        if(rez%2 == 1){

            P = ((P%MOD)*(A%MOD))%MOD;

        }

        A = ((A%MOD)*(A%MOD))%MOD;

        rez /= 2;

    }

    fout<<P%MOD<<'\n';

    return 0;

}
