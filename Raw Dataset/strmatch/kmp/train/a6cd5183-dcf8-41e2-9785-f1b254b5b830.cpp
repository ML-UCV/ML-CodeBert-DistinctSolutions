#include <iostream>
#include <fstream>
#include <string>
#include <vector>


using namespace std;



string w, t;

vector < int > sol, aux;



int main()

{

    ifstream f("strmatch.in");

    ofstream g("strmatch.out");

    getline(f, w);

    getline(f, t);

    aux.resize(w.size() + 2, 0);



    int p = 1, m = 0;

    while(p < w.size())

    {

        if(w[p] == w[m])

        {

            m++;

            aux[p] = m;

            p++;

        }

        else

        {

            if(m)

            {

                m = aux[m - 1];

            }

            else

            {

                aux[p] = 0;

                p++;

            }

        }

    }



    int i = 0, j = 0, nr = 0;

    while(j < t.size())

    {

        if(t[j] != w[i])

        {

            if(!i) j++;

            else i = aux[i - 1];

        }

        else

        {

            i++;

            j++;

            if(i == w.size())

            {

                nr++;

                if(nr <= 1000)

                    sol.push_back(j - i);

                i = aux[i - 1];

            }

        }

    }



    g << nr << '\n';

    for(int x: sol)

        g << x << ' ';

    g << '\n';

    f.close();

    g.close();

    return 0;

}
