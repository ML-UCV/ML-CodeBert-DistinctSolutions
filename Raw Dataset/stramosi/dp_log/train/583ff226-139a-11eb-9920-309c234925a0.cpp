#include <bits/stdc++.h>
using namespace std;



ifstream in("stramosi.in");

ofstream out("stramosi.out");



const int N=250005;

int far[18][N];

int n,m;



int main(){

    in>>n>>m;

    for(int i=1;i<=n;i++){

        in>>far[0][i];

    }

    for(int lg=1;lg<18;lg++){

        for(int i=1;i<=n;i++)

            far[lg][i]=far[lg-1][far[lg-1][i]];

    }

    while(m--){

        int nod,k;

        in>>nod>>k;

        for(int lg=0;lg<18;lg++){

            if(k%2){

                nod=far[lg][nod];

            }

            k/=2;

        }

        out<<nod<<'\n';

    }

    return 0;

}
