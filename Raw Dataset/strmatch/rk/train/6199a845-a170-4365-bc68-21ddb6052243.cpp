#include <bits/stdc++.h>
using namespace std;
ifstream fin("strmatch.in");

ofstream fout("strmatch.out");



string a,b;

vector <int> sol;



int main()

{

    fin >> a >> b;



    int cod1=0, cod2=0, p1, p2, c1=0, c2=0, nr = 0, n= a.size();

    cod1 = cod2 = 0;

    p1 = p2 = 1;

    for(unsigned int i = 0; i < a.size(); i++)

    {

        cod1 = (cod1*73 % 100007 + a[i]%100007)%100007;

        cod2 = (cod2*73 % 100021 + a[i]%100021)%100021;

        if(i != 0)

            p1 = p1*73 %100007, p2 = p2*73 %100021;

    }



    for(unsigned int i = 0 ; i < b.size(); i++)

        if(i < a.size())

        {

            c1 = (c1*73 %100007 + b[i]%100007)%100007;

            c2 = (c2*73 %100021 + b[i]%100021)%100021;



        }

        else{

            if(c1 == cod1 && c2 == cod2)

                {nr++; if(nr <= 1000) sol.push_back(i-n);}



            c1 = ((c1 + 100007 - b[i-n]*p1%100007)*73%100007 + b[i])%100007;

            c2 = ((c2 + 100021 - b[i-n]*p2%100021)*73%100021 + b[i])%100021;

        }



    if(c1 == cod1 && c2 == cod2)

            {

                nr++;

                if(nr <= 1000) sol.push_back(b.size()-n);

            }



    fout << nr <<'\n';

    for(unsigned int i = 0; i < sol.size(); i++)

        fout << sol[i] << " ";



    return 0;



}
