#include <iostream>
#include <fstream>




using namespace std;

ifstream fin("inversmodular.in");

ofstream fout("inversmodular.out");

long long n,m;

long long phi(long long nr){

    long long rez=nr;

    for(int i=2;i*i<=nr;i++){

        if(nr%i==0){

            while(nr%i==0) nr/=i;

            rez=(rez/i)*(i-1);

        }

    }

    if(nr!=1) rez=rez/nr*(nr-1);

    return rez;

}

int main(){

    fin>>n>>m;

    long long nr=n,crt=1,put=phi(m)-1;

    for(long long p=1;p<=put;p<<=1){

        if(p&put) crt=(crt*nr)%m;

        nr=(nr*nr)%m;

    }

    fout<<crt;

    return 0;

}
