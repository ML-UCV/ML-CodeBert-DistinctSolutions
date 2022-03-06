#include <iostream>
#include<fstream>


using namespace std;

int n;

int aib[30001], v[30001], sol[30001];



int len(int r) {

    return r-(r&(r-1));

}

void solve(int pz, int val) {

    while(pz<=n) {

            aib[pz]+=val;

            pz=pz+len(pz);

    }

}



int main() {

    int i, x, pas, rz;



    ifstream fin("schi.in");

    ofstream fout("schi.out");

    fin>>n;

    for(i=1;i<=n;i++) {

            fin>>v[i];

            solve(i, 1);

    }

    for(i=n;i>=1;i--) {

             x=v[i];

     pas=1<<20;

     rz=0;

    while(pas>0) {

        if(pas+rz<=n && aib[pas+rz]<x) {

                rz=rz+pas;

                x=x-aib[rz];

        }

        pas=pas/2;

    }

    sol[++rz]=i;

    solve(rz, -1);

    }

    for(i=1;i<=n;i++) {

            fout<<sol[i]<<"\n";

    }

    return 0;

}
