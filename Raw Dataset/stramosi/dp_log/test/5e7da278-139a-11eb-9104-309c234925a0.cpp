#include <fstream>


using namespace std;

ifstream fin("stramosi.in");

ofstream fout("stramosi.out");

int S[22][250010];

int n,m,i,p,putere,a,b;

int main(){

    fin>>n>>m;

    for(i=1;i<=n;i++)

        fin>>S[0][i];

    for(putere=1;putere<=18;putere++)

        for(i=1;i<=n;i++)

            S[putere][i]=S[putere-1][S[putere-1][i]];

    for(i=1;i<=m;i++){

        fin>>a>>b;

        for(p=0;(1<<p)<=b;p++){

            if(b&(1<<p))

                a=S[p][a];

        }

        fout<<a<<"\n";

    }

}
