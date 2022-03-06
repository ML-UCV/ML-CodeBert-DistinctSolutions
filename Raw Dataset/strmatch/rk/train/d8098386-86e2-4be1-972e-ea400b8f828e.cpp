#include <bits/stdc++.h>


using namespace std;



ifstream in("strmatch.in");

ofstream out("strmatch.out");



string cuv,sir;

unsigned long long Hcuv,A=915358133,B=974328597;

unsigned long long h[2000001],putere[2000001];

int sol[1001],nr;



int main()

{

    in>>cuv>>sir;



    for(auto lit:cuv)

        Hcuv=( Hcuv*A+lit )%B;



    h[0]=sir[0]%B;

    putere[0]=1;



    for(int i=1;i<sir.size();i++)

    {

        h[i]=( h[i-1]*A+sir[i] )%B;

        putere[i]=( putere[i-1]*A )%B;

    }



    for(int i=cuv.size()-1;i<sir.size();i++)

        if( ( h[i]-h[i-cuv.size()]*putere[cuv.size()]+B*B )%B == Hcuv )

        {

            nr++;

            if(nr<=1000)

                sol[nr]=i-cuv.size()+1;

        }



    out<<nr<<'\n';



    for(int i=1;i<=min(1000,nr);i++)

        out<<sol[i]<<' ';



    return 0;

}
