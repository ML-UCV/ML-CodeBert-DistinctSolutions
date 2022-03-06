#include <iostream>
#include<fstream>


using namespace std;

ifstream in("stramosi.in");

ofstream out("stramosi.out");

int stramos[20][250001];

int main()

{

    int n,m,p,q;

    in>>n>>m;

    for(int i=1;i<=n;i++)

        in>>stramos[0][i];

    for(int i=1;i<=18;i++)

        for(int j=1;j<=n;j++){

            stramos[i][j]=stramos[i-1][stramos[i-1][j]];

        }

    for(int i=1;i<=m;i++){

        in>>q>>p;

        for(int j=0;p>0;j++){

            if((1<<j)&p){

                q=stramos[j][q];

                p-=(1<<j);

            }

        }



        out<<q<<"\n";

    }

    return 0;

}
