#include <bits/stdc++.h>




using namespace std;



ifstream in("strmatch.in");

ofstream out("strmatch.out");



string cuv,sir;

int cuvSize,sirSize;

int sol[1001],t;



unsigned long long cuvP,A=915358133,B=974328597;

unsigned long long h[2000001],p[2000001];



void build()

{

    for(auto lit:cuv)

        cuvP=(cuvP*A+lit)%B;



    p[0]=1;



    for(int i=1;i<=sirSize;i++)

    {

        h[i]=(h[i-1]*A+sir[i-1])%B;

        p[i]=(p[i-1]*A)%B;

    }

}



void rabinKarp()

{

    for(int i=cuvSize;i<=sirSize;i++)

    {

        if( (h[i]-h[i-cuvSize]*p[cuvSize]+B*B)%B==cuvP )

        {

            t++;

            if(t<=1000)

                sol[t]=i-cuvSize;

        }

    }

}



int main()

{

    in>>cuv>>sir;

    cuvSize=cuv.size();

    sirSize=sir.size();



    build();

    rabinKarp();



    out<<t<<'\n';



    for(int i=1;i<=min(t,1000);i++)

        out<<sol[i]<<' ';



    return 0;

}
