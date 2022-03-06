#include <bits/stdc++.h>


using namespace std;



ifstream in("strmatch.in");

ofstream out("strmatch.out");



string s;

string a, b;



unsigned int p[4000000 + 7];

unsigned int sol[4000000 + 7];



int main()

{

    in >> a >> b;

    s.resize(2 + a.size() + b.size());



    s = '*' + a;



    unsigned int k = 0;

    for(unsigned int i = 2; i < s.size(); i++)

    {

        while(k > 0 && s[k+1] != s[i])

            k = p[k];

        if(s[k+1] == s[i])

            k++;

        p[i] = k;

    }



    k = 0;

    int nr_ap = 0;

    for(unsigned int i = 0; i < b.size(); i++)

    {

        while(k > 0 && s[k+1] != b[i])

            k = p[k];

        if(s[k+1] == b[i])

            k++;



        sol[i] = k;



        if(k == a.size())

            nr_ap++;

    }



    out << nr_ap << endl;

    if(nr_ap > 1000) nr_ap = 1000;

    for(unsigned int i = 0; i < b.size(); i++)

    {

        if(sol[i] == a.size() && nr_ap)

        {

            out << i - a.size() +1 << " ";

            nr_ap--;

        }

    }

}
