#include <bits/stdc++.h>


using namespace std;



ifstream in("stramosi.in");

ofstream out("stramosi.out");



int n,m,baza;

int stram[19][250001];



int main()

{

    in>>n>>m;

    baza=log2(n)+1;



    for(int j=1;j<=n;j++)

        in>>stram[1][j];



    for(int i=2;i<=baza;i++)

        for(int j=1;j<=n;j++)

            stram[i][j]=stram[i-1][ stram[i-1][j] ];



    for(int nod,p,i=1;i<=m;i++)

    {

        in>>nod>>p;



        for(int j=0;j<=baza;j++)

            if(p&(1<<j))

                nod=stram[j+1][nod];



        out<<nod<<'\n';

    }



    return 0;

}
