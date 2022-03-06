#include <iostream>
#include <fstream>


using namespace std;



ifstream f("party.in");

ofstream g("party.out");

struct cerinta

{

    int x, y, z;

} A[1024];



int P[128];

int N, M, ok, i, X, Y, Z, Cnt;



int main()

{

    f>>N>>M;

    for(i=1; i<=N; i++)P[i]=1;



    for(i=1; i<=M; i++)

        f>>A[i].x>>A[i].y>>A[i].z;

    ok=0;

    while(ok==0)

    {

        ok=1;

        for (i=1; i<=M; i++)

        {

            X=A[i].x, Y=A[i].y, Z=A[i].z;

            if(Z==0)

                if(P[X]==0 && P[Y]==0)

                {

                    P[X]=1;

                    P[Y]=1;

                    ok=0;

                    break;

                }

            if(Z==1)

                if(P[X]==0 && P[Y]!=0)

                {

                    P[Y]=0;

                    ok=0;

                    break;

                }

            if(Z==2)

                if(P[Y]==0 && P[X]!=0)

                {

                    P[X]=0;

                    ok=0;

                    break;

                }

            if(Z==3)

                if(P[X]==1 && P[Y]==1)

                {

                    P[Y]=0;

                    ok=0;

                    break;

                }

        }

    }

    for(i=1; i<=N; i++)

        if(P[i])Cnt++;

    g<<Cnt<<endl;



    for(i=1; i<=N; i++)

        if(P[i])g<<i<<endl;

}
