#include <bits/stdc++.h>

using namespace std;

ifstream in("strmatch.in");
ofstream out("strmatch.out");

string cuv,sir;
int pref[2000001];
int sol[1001],t;

void createPref()
{
    int lung=0;

    for(int i=2;i<cuv.size();i++)
    {
        while(lung>0 && cuv[i]!=cuv[lung+1])
            lung=pref[lung];

        if(cuv[i]==cuv[lung+1])
            lung++;

        pref[i]=lung;
    }

}

int main()
{
    in>>cuv>>sir;
    cuv.insert(cuv.begin(),' ');
    sir.insert(sir.begin(),' ');

    createPref();

    int lung=0;
    for(int i=1;i<sir.size();i++)
    {
        while(lung>0 && sir[i]!=cuv[lung+1])
            lung=pref[lung];

        if(sir[i]==cuv[lung+1])
            lung++;

        if(lung==cuv.size()-1)
        {
            t++;
            if(t<=1000)
                sol[t]=i-cuv.size()+1;

            lung=pref[lung];
        }
    }

    out<<t<<'\n';

    for(int i=1;i<=min(1000,t);i++)
        out<<sol[i]<<' ';

    return 0;
}
