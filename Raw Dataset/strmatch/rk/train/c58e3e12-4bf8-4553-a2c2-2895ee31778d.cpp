#include <iostream>
#include<fstream>
#include<cstring>
char a[2000001], b[2000001], ok[2000001];



int i, j, na, nb, ns1, ns2, nsa1, nsa2, p1, p2, nr;



using namespace std;



int main() {



    ifstream fin("strmatch.in");

    ofstream fout("strmatch.out");

    fin.getline(a, 2000001);

    fin.getline(b, 2000001);

    na=strlen(a);

    nb=strlen(b);

    p1=p2=1;

    nsa1=nsa2=0;

    for(i=0;i<na;i++) {

            nsa1=(nsa1*73+a[i])%100007;

    nsa2=(nsa2*73+a[i])%100021;

    if(i!=0) {

            p1=(p1*73)%100007;

    p2=(p2*73)%100021;

    }

    }

    if(na>nb) {

            fout<<"0";

    }

    else {

         ns1=ns2=0;

    for(i=0;i<na;i++) {

            ns1=(ns1*73+b[i])%100007;

    ns2=(ns2*73+b[i])%100021;

    }

    nr=0;

    if(ns1==nsa1 && ns2==nsa2) {

            ok[0]=1;

            nr++;

    }

    for(i=na;i<nb;i++) {

           ns1=((ns1-(b[i-na]*p1)%100007 +100007)*73+b[i])%100007;

           ns2=((ns2-(b[i-na]*p2)%100021 +100021)*73+b[i])%100021;

           if(ns1==nsa1 && ns2==nsa2) {

                ok[i-na+1]=1;

           nr++;

           }

    }

    fout<<nr<<endl;

    nr=0;

    for(i=0;i<nb && nr<1000;i++) {

            if(ok[i]) {

                 fout<<i<<" ";

                    nr++;

            }

    }

    }

    return 0;

}
