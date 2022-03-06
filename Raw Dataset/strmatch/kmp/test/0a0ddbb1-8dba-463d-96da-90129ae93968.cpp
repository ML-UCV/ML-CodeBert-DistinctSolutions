#include <bits/stdc++.h>


using namespace std;



ifstream in("strmatch.in");

ofstream out("strmatch.out");



string cuv,sir;

int sol[1001],nrS;



int pref[2000001];



void addSol(int i)

{

    nrS++;



    if(nrS<=1000)

        sol[nrS]=i-cuv.size()+1;

}



void prefix()

{

    int lung=0;



    for(int i=2;i<cuv.size();i++)

    {

        while(lung && cuv[lung+1]!=cuv[i])

            lung=pref[lung];



        if(cuv[lung+1]==cuv[i])

            lung++;



        pref[i]=lung;

    }

}



void KMP()

{

    prefix();



    int lung=0;



    for(int i=1;i<sir.size();i++)

    {

        while(lung && cuv[lung+1]!=sir[i])

            lung=pref[lung];



        if(cuv[lung+1]==sir[i])

            lung++;



        if(lung==cuv.size()-1)

        {

            addSol(i);

            lung=pref[lung];

        }

    }

}



int main()

{

    in>>cuv>>sir;

    cuv.insert(cuv.begin(),' ');

    sir.insert(sir.begin(),' ');



    KMP();



    out<<nrS<<'\n';



    for(int i=1;i<=min(nrS,1000);i++)

        out<<sol[i]<<' ';



    return 0;

}
