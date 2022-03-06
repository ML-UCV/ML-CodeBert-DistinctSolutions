#include <fstream>
#include <cstring>
#include <vector>
using namespace std;



ifstream fin("strmatch.in");

ofstream fout("strmatch.out");



char subsecventa[2000000];

int lung_subseventa;

int lung_sir;

char sir[2000000];



int LPS[2000000];



vector <int> sol;



void construct_LPS()

{

    int i = 1;

    int j = 0;

    while(i < lung_subseventa)

    {

        if(subsecventa[i] == subsecventa[j])

            LPS[i] = j + 1, j++;

        else if(j != 0)

            j = LPS[j - 1], i--;

        else

            LPS[i] = 0;

        i++;

    }

}



void KMP()

{

    int i = 0;

    int j = 0;

    while(j < lung_sir)

    {

        if(subsecventa[i] != sir[j])

        {

            if(i == 0)

                j++;

            else

                i = LPS[i - 1];

        }

        else

        {

            i++;

            j++;

            if(i == lung_subseventa)

            {

                sol.push_back(j - i);

                i = LPS[i-1];

            }

        }

    }

}



void citire()

{

    fin.getline(subsecventa, sizeof(subsecventa) + 1);

    fin.getline(sir, sizeof(sir) + 1);

    lung_sir = strlen(sir);

    lung_subseventa = strlen(subsecventa);

}



void afisare()

{

    if(sol.size() > 1000)

    {

        fout << sol.size() << '\n';

        for(int i = 0; i < 1000; i++)

            fout << sol.at(i) << ' ';

    }

    else

    { fout << sol.size() << '\n';

        for(unsigned int i = 0; i < sol.size(); i++)

            fout << sol.at(i) << ' ';

    }

}



int main()

{

    citire();

    construct_LPS();

    KMP();

    afisare();

    return 0;

}
