#include <bits/stdc++.h>


using namespace std;



ifstream in("strmatch.in");

ofstream out("strmatch.out");

string sir, cuv;

int pref[2000001], sol;

int pozitii[1001], vf;



int main()

{

    in >> cuv >> sir;

    cuv = " " + cuv;

    sir = " " + sir;



    for(int i = 2, lung = 0; i < cuv.size(); i++)

    {

        while(lung && cuv[lung+1] != cuv[i])

            lung = pref[lung];



        if(cuv[lung+1] == cuv[i])

            lung++;



        pref[i] = lung;

    }



    for(int i = 1, lung = 0; i < sir.size(); i++)

    {

        while(lung && cuv[lung+1] != sir[i])

            lung = pref[lung];



        if(cuv[lung+1] == sir[i])

            lung++;



        if(lung == cuv.size() - 1)

        {

            sol++;

            if(vf < 1000)

                pozitii[++vf] = i - lung;

            lung = pref[lung];

        }

    }



    out << sol << '\n';



    for(int i = 1; i <= min(1000, sol); i++)

        out << pozitii[i] << ' ';



    return 0;

}
