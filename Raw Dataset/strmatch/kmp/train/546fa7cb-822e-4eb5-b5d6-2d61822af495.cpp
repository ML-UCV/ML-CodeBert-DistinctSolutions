#include <fstream>
#include <cstring>
#include <vector>


using namespace std;



ifstream fin("strmatch.in");

ofstream fout("strmatch.out");



char p[2000001], t[2000001];

int f[2000001];

vector < int > poz;



int kmp(char p[], char t[], vector < int > &poz)

{

    int n, m, i, j, nr;

    n = strlen(t);

    m = strlen(p);



    f[0] = 0;

    i = 0, j = 1;

    while (j < m)

    {

        while (j < m && p[i] != p[j])

        {

            f[j] = 0;

            j++;

        }



        if (j < m)

        {

            if (p[i] == p[j])

            {

                f[j] = i + 1;

                i++, j++;

            }

            if (p[i] != p[j])

                i = f[i-1];

        }

    }



    nr = 0;

    i = j = 0;

    while (i < n)

    {

        if (t[i] == p[j])

        {

            if (j == m - 1)

            {

               nr++;

               poz.push_back(i - m + 1);

               i++, j = f[j];

            }

            else

                i++, j++;

        }

        else if (j > 0)

            j = f[j-1];

        else

            i++;

    }



    return nr;

}



int main()

{

    fin >> p >> t;

    fout << kmp(p, t, poz) << "\n";

    for (int i=0; i<poz.size(); i++)

    {

        if (i == 1000)

            break;

        fout << poz[i] << " ";

    }

    return 0;

}
