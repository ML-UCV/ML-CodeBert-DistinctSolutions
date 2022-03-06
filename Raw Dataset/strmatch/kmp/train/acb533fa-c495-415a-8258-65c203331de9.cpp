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



    f[0] = 0, j = 0;

    for (i=1; i<m; i++)

    {

        while (j && p[j] != p[i])

            j = f[j-1];

        if (p[j] == p[i])

            j++;

        f[i] = j;

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
