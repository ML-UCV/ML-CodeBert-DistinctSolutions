#include <bits/stdc++.h>


using namespace std;

ifstream in ("strmatch.in") ;

ofstream out ("strmatch.out") ;

char caut[2000001], text[2000001];

int nr_r, r[2000001], l[2000001];



void make_pattern()

{

    int lp=strlen(caut);

    int i, j;

    l[0]=0;

    i=1;

    j=0;

    while(i<lp)

        if(caut[i]==caut[j])

        {

            j++;

            l[i]=j;

            i++;

        }

        else if(j==0)

            l[i++]=0;

        else

            j=l[j-1];



}



void search_pattern()

{

    int i, j;

    int lp=strlen(caut);

    int ls=strlen(text);

    i=0;

    j=0;

    while(i<ls)

        if(text[i]==caut[j])

        {

            i++;

            j++;

            if(j==lp)

            {

                r[nr_r++]=i-lp;

                j=l[j-1];

            }

        }

        else if(j==0)

            i++;

        else

            j=l[j-1];



}



int main()

{

    in.getline(caut, 2000001);

    in.getline(text, 2000001);

    make_pattern();

    search_pattern();

    out << nr_r << '\n';

    if(nr_r>1000)

        nr_r=1000;

    for(int i=0; i<nr_r; i++)

    {

        out << r[i] << " ";

    }

    return 0;

}
