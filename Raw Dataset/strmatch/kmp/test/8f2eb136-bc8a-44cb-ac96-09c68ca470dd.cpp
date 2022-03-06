#include <fstream>
#include <cstring>
#include <string>


using namespace std;



ifstream fin("strmatch.in");

ofstream fout("strmatch.out");



int pattern[2000001];



void Pattern( string s1, int n)

{

    int i = 1, j = 0;

    while(i < n)

    {

        if(s1[i] == s1[j])

        {

            j++;

            pattern[i] = j;

            i++;

        }

        else

        {

            if(j != 0)

                j = pattern[j - 1];

            else

            {

                pattern[i] = 0;

                i++;

            }

        }



    }



}



int main()

{

    string s1, s2;

    fin >> s1 >> s2;

    int l1 = s1.length(), l2 = s2.length(), sol[1001];

    Pattern(s1, l1);

    int i = 0, j = 0, k = 0, ct = 0;

    while(i < l2)

    {

        if(s2[i] == s1[j])

        {

            i++;

            j++;

        }

        if(j == l1)

        {

            k++;

            if(ct < 1000)

                sol[ct++] = i - l1;

            j = pattern[j - 1];

        }

        else if(s1[j] != s2[i] && i < l2)

        {

            if(j == 0)

                i++;

            else

                j = pattern[j - 1];

        }

    }

    fout << k << '\n';

    for(i = 0; i < ct; i++)

        fout << sol[i] <<' ';

}
