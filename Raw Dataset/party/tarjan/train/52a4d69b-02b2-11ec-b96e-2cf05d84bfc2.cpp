#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("party.in");

ofstream fout("party.out");

struct cerinta

{

    int x, y, z;

} A[1024];

bool P[128];

int N, M, X, Y, Z;

int main()

{

    fin>>N>>M;

    for(int i=1; i<=N; i++)P[i]=true;

    for(int i=1; i<=M; i++)fin>>A[i].x>>A[i].y>>A[i].z;



    int ok=0;

    do

    {

        ok=1;

        for (int i=1; i<=M; i++)

        {

            X=A[i].x, Y=A[i].y, Z=A[i].z;

            if(Z==0)

                if(!P[X]&& !P[Y])

                {

                    P[X]=true;

                    P[Y]=true;

                    ok=0;

                    break;

                }

            if(Z==1)

                if(!P[X] && P[Y])

                {

                    P[Y]=false;

                    ok=false;

                    break;

                }

            if(Z==2)

                if(!P[Y] && P[X])

                {

                    P[X]=false;

                    ok=false;

                    break;

                }

            if(Z==3)

                if(P[X] && P[Y])

                {

                    P[Y]=false;

                    ok=0;

                    break;

                }

        }

    }while(!ok);



    int Cnt=0;

    for(int i=1; i<=N; i++)

        if(P[i])Cnt++;

    fout<<Cnt<<endl;

    for(int i=1; i<=N; i++)

        if(P[i])fout<<i<<endl;

    return 0;

}
