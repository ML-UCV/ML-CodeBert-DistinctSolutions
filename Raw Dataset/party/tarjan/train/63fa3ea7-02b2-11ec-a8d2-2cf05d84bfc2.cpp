#include <fstream>
#include <cstdlib>
#include <ctime>


using namespace std;



struct COND{int x, y, type;};



bool satisfied(bool valX, bool valY, int type)

{

    switch(type)

    {

        case 0: return (valX || valY);

        case 1: return (valX || !valY);

        case 2: return (!valX || valY);

        case 3: return (!valX || !valY);

    }

    return true;

}



COND conditions[1001];

bool values[101];



int main()

{

    int n, m;

    int i;

    int nrGuests = 0;

    srand(time(NULL));

    ifstream f("party.in");

    f>>n>>m;

    for(i = 1; i <= m; i++)

        f>>conditions[i].x>>conditions[i].y>>conditions[i].type;

    f.close();

    for(i = 1; i <= n; i++)

        values[i] = true;

    for(i = 1; i <= m; i++)

    {

        if(!satisfied(values[conditions[i].x], values[conditions[i].y], conditions[i].type))

        {

            if(rand() % 2 == 0)

                values[conditions[i].x] = !values[conditions[i].x];

            else

                values[conditions[i].y] = !values[conditions[i].y];

            i = 0;

        }

    }

    for(i = 1; i <= n ; i++)

        if(values[i])

            nrGuests++;

    ofstream g("party.out");

    g<<nrGuests<<'\n';

    for(i = 1; i <= n; i++)

        if(values[i])

            g<<i<<'\n';

    g.close();

    return 0;

}
