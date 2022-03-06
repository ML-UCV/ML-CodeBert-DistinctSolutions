#include <bits/stdc++.h>


using namespace std;



int sufix[2000005], ans[1005], k, i, j, n, m;

char s[2000005], t[2000005];

int main()

{

    ifstream f("strmatch.in");

    ofstream g("strmatch.out");



    f.getline(t, sizeof(t));

    f.getline(s, sizeof(s));



    n = strlen(s);

    m = strlen(t);

    j = 0;

    i = 1;



    while(i < m)

    {

        if(t[j] == t[i])

        {

            sufix[i] = j + 1;

            j ++;

            i ++;

        }

        else if(j == 0)

        {

            sufix[i] = 0;

            i ++;

        }

        else j = sufix[j - 1];



    }



    j = 0;

    for(i = 0; i < n; i ++)

        if(s[i] == t[j])

        {

            j ++;

            if(j == m)

            {

                if(k <= 1002)

                {

                    ans[++ k] = i - m + 1;

                    j = sufix[j - 1];

                }

                else k ++;

            }

        }

        else if(j == 0) continue;

        else

        {

            j = sufix[j - 1];

            i --;

        }



    g << k << "\n";

    for(i = 1; i <= min(k, 1000); i ++)

        g << ans[i] << " ";

    return 0;

}
