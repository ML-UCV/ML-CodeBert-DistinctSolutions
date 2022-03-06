#include<iostream>
#include<fstream>
#include<cstdlib>
#include<ctime>


using namespace std;



ifstream in ("party.in");

ofstream out ("party.out");



int C[10*101], n, m, i, Nr;

struct inv

{

    int x,y;

    int c;

};



inv v[10*101];



int verificare(int k)

{



    if(k==0)

        return C[v[i].x] || C[v[i].y];



    if(k==1)

        return C[v[i].x] || !C[v[i].y];



    if(k==2)

        return C[v[i].y]||!C[v[i].x];



    if(k==3)

        return C[v[i].x]+C[v[i].y]!=2;



    return 0;

}

int main ()

{



    in>>n>>m;



    for(i=1;i<=m;i++)

        in>>v[i].x>>v[i].y>>v[i].c;

    for(i=1;i<=n;i++)

        C[i]=1;



    for(i=1;i<=m;i++)

    {



        if(!verificare(v[i].c))

        {

            int a=rand()%2;



            if(a==1) C[v[i].y]=!C[v[i].y];

            else C[v[i].x]=!C[v[i].x];

            i=0;

        }

    }

    for(i=1;i<=n;i++)

        if(C[i]) ++Nr;

    out<<Nr<<"\n";

    for(i=1;i<=n;++i)

    {

        if(C[i])

            out<<i<<"\n";

    }

    return 0;

}
