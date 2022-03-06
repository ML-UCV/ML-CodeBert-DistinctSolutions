#include <bits/stdc++.h>


using namespace std;



ifstream in("strmatch.in");

ofstream out("strmatch.out");



string sir,cuv;

int sol[1001],t;

int pref[2000001];



void adauga(int poz)

{

    t++;

    if(t<=1000)

        sol[t]=poz-cuv.size();

}



void buildPref(string cuv)

{

    int lung=0;



    for(int i=2;i<cuv.size();i++)

    {

        while( lung && cuv[lung+1]!=cuv[i] )

            lung=pref[lung];



        if( cuv[lung+1]==cuv[i] )

            lung++;



        pref[i]=lung;

    }

}



void KMP(string cuv,string sir)

{

    cuv.insert( cuv.begin(), ' ' );

    sir.insert( sir.begin(), ' ' );



    buildPref(cuv);



    int lung=0;



    for(int i=1;i<sir.size();i++)

    {

        while( lung && cuv[lung+1]!=sir[i] )

            lung=pref[lung];



        if( cuv[lung+1]==sir[i] )

            lung++;



        if( lung==cuv.size()-1 )

        {

            adauga(i);

            lung=pref[lung];

        }

    }

}



int main()

{

    in>>cuv>>sir;



    KMP(cuv,sir);



    out<<t<<'\n';



    for(int i=1;i<=min(1000,t);i++)

        out<<sol[i]<<' ';



    return 0;

}
