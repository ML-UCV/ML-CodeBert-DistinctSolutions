#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;



ifstream fin("strmatch.in");

ofstream fout("strmatch.out");



char s[2000009];

char t[2000009];

int n,m;

int pref[2000009];



void Read()

{

    int i,j = 0;

    fin>>s;

    fin>>t;

    m = strlen(s);

    n = strlen(t);

    for(int i = 1; i < m; )

    {

        if(s[i] == s[j])

        {

            pref[i] = j+1;

            ++i;

            ++j;

        }

        else

        {

            if(j != 0)

            {

                j = pref[j-1];

            }

            else

            {



                ++i;

            }

        }

    }

}



void Do()

{

    int ct = 0;

    int sol[1005];

    int i,j = 0;

    i = 0;

    while( i < n)

    {

        if(t[i] == s[j])

        {

            ++i;

            ++j;

        }

        if( j == m)

        {

            if(ct <= 1000)

                sol[++ct] = i-j;

            else ct++;

            j = pref[j-1];

        }

        else if(i < n && s[j] != t[i])

             {

                 if(j!=0)

                    j = pref[j-1];

                else ++i;

             }

    }

    fout<<ct<<"\n";

    for(i=1; i<=min(1000,ct); ++i)

        fout<<sol[i]<<" ";

}



int main()

{

    Read();

    Do();

    return 0;

}
