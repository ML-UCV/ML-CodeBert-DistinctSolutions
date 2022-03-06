#include <fstream>
#include <algorithm>
#include <vector>
#include <stack>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <queue>




using namespace std;



ifstream f("party.in");

ofstream g("party.out");



int N, M, ans, i;

int x[1020], y[1020], z[1020];

int sol[1020];



bool isWrong (int i)

{

    bool a=sol[x[i]];

    bool b=sol[y[i]];



    if (z[i]>1) a^=1;

    if (z[i]%2) b^=1;



    return !(a|b);

}



int main ()

{

    srand(time(0));



    f >> N >> M;

    for (i=1; i<=M; i++)

        f >> x[i] >> y[i] >> z[i];



    bool ok=0;

    do

    {

        ok=1;



        for (i=1; i<=M; i++)

            if (isWrong(i))

            {

                int a=x[i], b=y[i];

                if (rand()%2) swap(a, b);



                ans-=sol[a];

                sol[a]^=1;

                ans+=sol[a];



                ok=0;

            }



        if (ans==0 && ok==1)

        {

            ok=0;

            ans=sol[rand()%N+1]=1;

        }

    } while (ok==0);



    g << ans << '\n';

    for (i=1; i<=N; i++)

        if (sol[i]==1)

            g << i << '\n';



    f.close();

    g.close();



    return 0;

}
