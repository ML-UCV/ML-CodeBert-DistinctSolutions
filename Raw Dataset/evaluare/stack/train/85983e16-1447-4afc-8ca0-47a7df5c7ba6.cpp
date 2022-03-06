#include <fstream>
#include <stack>


using namespace std;



ifstream f("evaluare.in");

ofstream g("evaluare.out");



char c[100001];

int p[100001];

pair < int, char > v[100001], stiva[100001];

int nrv, nrs;



int rezolva(char c[])

{

    int rez = 0;

    char semn = '+';

    for (int i = 0; c[i]; i++)

    {

        if (c[i] == '+' || c[i] == '-' || c[i] == '*' || c[i] == '/')

            semn = c[i];

        else if (c[i] >= '0' && c[i] <= '9')

        {

            int nr = 0;

            while (c[i] >= '0' && c[i] <= '9')

            {

                nr = nr * 10 + c[i] - '0';

                i++;

            }

            i--;



            if (semn == '+' || semn == '-')

            {

                nrv++;

                v[nrv].first = nr;

                v[nrv].second = semn;

            }

            else

            {

                if (semn == '*')

                    v[nrv].first *= nr;

                else

                    v[nrv].first /= nr;

            }

        }

        else if (c[i] == '(')

        {

            nrs++;

            stiva[nrs].first = nrv + 1;

            stiva[nrs].second = semn;

            semn = '+';

        }

        else if (c[i] == ')')

        {

            for (int j = stiva[nrs].first + 1; j <= nrv; j++)

                if (v[j].second == '+')

                    v[stiva[nrs].first].first += v[j].first;

                else

                    v[stiva[nrs].first].first -= v[j].first;

            nrv = stiva[nrs].first;

            v[nrv].second = stiva[nrs].second;

            nrs--;

            if (stiva[nrs].first != nrv)

            {

                if (v[nrv].second == '*')

                {

                    v[nrv - 1].first *= v[nrv].first;

                    nrv--;

                }

                else if (v[nrv].second == '/')

                {

                    v[nrv - 1].first /= v[nrv].first;

                    nrv--;

                }

            }

        }

    }



    for (int i = 2; i <= nrv; i++)

        if (v[i].second == '+')

            v[1].first += v[i].first;

        else

            v[1].first -= v[i].first;



    g << v[1].first;

}



int main()

{

    f >> c;

    rezolva(c);

    return 0;

}
