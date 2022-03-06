#include <fstream>
#include <cstring>




using namespace std;



ifstream fin("strmatch.in");

ofstream fout("strmatch.out");



char s1[4000002], s2[4000002];

int pref[4000002], n;



void f_pref(char s[4000002], int pref[4000002], int n) {

    pref[0] = 0;

    for (int i = 1; i < n; i++) {

        int j = i;

        while (j > 0 && s[pref[j - 1]] != s[i]) {

            j = pref[j - 1];

        }

        if (j == 0)

            pref[i] = 0;

        else

            pref[i] = pref[j - 1] + 1;

    }

}



int main()

{

    int ct=0, lg1, i;



    fin.getline(s1, 4000002);

    lg1=strlen(s1);

    fin.getline(s2, 4000002);

    strcat(s1, "$");

    strcat(s1, s2);

    n=strlen(s1);

    f_pref(s1, pref, n);

    for(i=0; i<n; ++i)

        if(pref[i]==lg1)

            ct++;

    fout << ct << '\n';

    ct=0;

    for(i=0; i<n; ++i)

        if(pref[i]==lg1)

        {

            if(ct<1000)

            {

                fout << i-2*lg1 << ' ';

                ct++;

            }

            else

                break;

        }

    return 0;

}
