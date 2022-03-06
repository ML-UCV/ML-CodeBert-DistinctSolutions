#include <cstdio>
#include <ctime>
#include <cstdlib>




using namespace std;



const int MAX_N = 101;

const int MAX_M = 1001;



int stare[MAX_N], reqx[MAX_M],reqy[MAX_M],reqt[MAX_M];

int lst[MAX_M];



int main()

{



    freopen("party.in","r",stdin);



    int N, M;

    scanf("%d%d", &N, &M);



    for (int i = 1; i <= M; ++i)

        scanf("%d%d%d", &reqx[i], &reqy[i], &reqt[i]);

    int val = 0,cnt = 0, i;



    srand(time(0));



    for (int i = 1; i <= N; ++i)

        if (rand() & 3)

            stare[i] = 1;

        else

            stare[i] = 0;



    for (;;){



    lst[0] = 0;

    for (i = 1;i <= M; ++i){



        int x = stare[reqx[i]];

        int y = stare[reqy[i]];

        if ( reqt[i] == 0 )

            val=( x | y );

        if ( reqt[i] == 1 )

            val=( x | (y^1) );

        if ( reqt[i] == 2 )

            val=( (x^1) | y );

        if ( reqt[i] == 3 )

            val=( (x^1) | (y^1) );

        if ( val == 0 ){



            ++lst[0];

            lst[lst[0]] = i;

            }

        }



        int cnt = 0;



        for (int j = 1;j <= N; ++j)

            cnt += stare[j];



        if (lst[0] == 0 && cnt)

            break;



        if (lst[0]){

            i = lst[rand()%lst[0] + 1];

            if (rand()&3)

                stare[reqx[i]] ^=1;

            else

                stare[ reqy[i] ] ^=1;

        }

    }



    cnt = 0;



    for ( i = 1; i <= N ; ++i )

        cnt += stare[i];



    freopen("party.out","w",stdout);



    printf("%d\n",cnt);



    for ( i = 1; i <= N ; ++i )

        if (stare[i]) printf("%d\n",i);





    return 0;

}
