#include <iostream>
#include <fstream>
using namespace std;



ifstream fin("strmatch.in");

ofstream fout("strmatch.out");



int lps[2000005];

string pat, txt;



void ComputeLps()

{

    int len = 0;

    int i = 1;

    lps[0] = 0;

    while(i < pat.size())

    {

        if(pat[i] == pat[len])

        {

            len++;

            lps[i] = len;

            i++;

        }

        else

        {

            if(len != 0)

            {

                len = lps[len-1];

            }

            else

            {

                lps[i] = 0;

                i++;

            }

        }

    }

}



int main()

{

    fin>>pat>>txt;

    ComputeLps();

    int n = txt.size(), m = pat.size(), i = 0, j = 0;



    fout<<"                   \n";

    int nr=0;

    while(i < n)

    {

        if(txt[i] == pat[j])

        {

            i++;

            j++;

        }

        if(j == m)

        {

            if(nr < 1000)

            {

                fout<<i-j<<' ';

            }

            nr++;

            j = lps[j-1];

        }

        else if(i < n && txt[i] != pat[j])

        {

            if(j != 0)

            {

                j = lps[j-1];

            }

            else

            {

                i++;

            }

        }

    }

    fout.close();

    fout.open("strmatch.out", ios::in | ios::out);

    fout<<nr;

    fin.close();

    fout.close();

    return 0;

}
