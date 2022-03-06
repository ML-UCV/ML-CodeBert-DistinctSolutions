#include <fstream>
#include <cstring>
#include <vector>
using namespace std;



ifstream f("strmatch.in");

ofstream g("strmatch.out");



char pattern[2000005], text[2000005];

int prefix[2000005], n, m, k;

vector<int> sol;



void read()

{

    f.getline(pattern+1, 2000005);

    f.getline(text+1, 2000005);

    n = strlen(pattern+1);

    m = strlen(text+1);

}



void calcPrefix()

{

    int j = 0;

    for(int i = 2; i <= n; i++)

    {

        while(j > 0 && pattern[i] != pattern[j+1])

        {

            j = prefix[j];

        }

        if(pattern[i] == pattern[j+1])

        {

            prefix[i] = j+1;

            j++;

        }

    }

}



void calcMatch()

{

    int i = 0;

    for(int j = 1; j<=m; j++)

    {

        while(i > 0 && pattern[i+1] != text[j])

        {

            i = prefix[i];

        }

        if(pattern[i+1] == text[j])

        {

            i++;

            if(i == n)

            {

                k++;

                if(sol.size() < 1000)

                    sol.push_back(j - i);

                i = prefix[i];

            }

        }

    }

}



void afisare()

{

    g<<k<<"\n";

    for(int i = 0; i<sol.size(); i++)

        g<<sol[i]<<" ";

}



int main()

{

    read();

    calcPrefix();

    calcMatch();

    afisare();

    return 0;

}
