#include <cstdio>




int pos[5][1000 +1][1000 +1];

int atins[1000 +1];

int is[1000 +1];

int x[1000 +1];

int y[1000 +1];

int z[1000 +1];

int N,M,nr,deja=1;



void Write()

{

    int i;

    for(i = 1; i <= N; ++i)

    if( is[i] ) ++nr;



    if(nr)

    {

        printf("%d\n",nr);

        for(i = 1; i <= N; ++i)

        if( is[i] ) printf("%d\n",i);

        deja = 0;

    }

}



void Gen(int k)

{

    if(k==N+1)

        if(deja) Write();

        else;

    else{

        int i,j,ok=1;



        if( is[k] != -1 ) Gen(k+1);

        else{



            is[k] = 0;

            for(j = 1; j <= pos[0][k][0] && deja; ++j)

            if( is[ pos[0][k][j] ] < 0 )

            {

                is[ pos[0][k][j] ] = 1;

                atins[ pos[0][k][j] ] = k;

            }

            else if( is[ pos[0][k][j] ] != 1 ) { ok = 0; break; }



            for(j = 1; j <= pos[1][k][0] && deja; ++j)

            if( is[ pos[1][k][j] ] < 0 )

            {

                is[ pos[1][k][j] ] = 0;

                atins[ pos[1][k][j] ] = k;

            }

            else if( is[ pos[1][k][j] ] != 0 ) { ok = 0; break; }



            if(ok && deja) Gen(k+1);

            for(i = k+1; i <= N; ++i)

            if( atins[i] == k ) { atins[i] = 0; is[i] = -1; }



            ok = is[k] = 1;

            for(j = 1; j <= pos[2][k][0] && deja; ++j)

            if( is[ pos[2][k][j] ] < 0 )

            {

                is[ pos[2][k][j] ] = 1;

                atins[ pos[2][k][j] ] = k;

            }

            else if( is[ pos[2][k][j] ] != 1 ) { ok = 0; break; }



            for(j = 1; j <= pos[3][k][0] && deja; ++j)

            if( is[ pos[3][k][j] ] < 0 )

            {

                is[ pos[3][k][j] ] = 0;

                atins[ pos[3][k][j] ] = k;

            }

            else if( is[ pos[3][k][j] ] != 0 ) { ok = 0; break; }



            if(ok && deja) Gen(k+1);

            for(i = k+1; i <= N; ++i)

            if( atins[i] == k ) { atins[i] = 0; is[i] = -1; }



            is[k] = -1;

        }

    }

}



void Compute()

{

    int i,j;



    for(i = 1; i <= N; ++i)

    {

        for(j = 1; j <= M; ++j)

        if( x[j] == i && z[j] == 0 ) pos[0][i][ ++pos[0][i][0] ] = y[j];

        else if( y[j] == i && z[j] == 0 ) pos[0][i][ ++pos[0][i][0] ] = x[j];

        else if( x[j] == i && z[j] == 1 ) pos[1][i][ ++pos[1][i][0] ] = y[j];

        else if( y[j] == i && z[j] == 1 ) pos[2][i][ ++pos[2][i][0] ] = x[j];

        else if( y[j] == i && z[j] == 2 ) pos[1][i][ ++pos[1][i][0] ] = x[j];

        else if( x[j] == i && z[j] == 2 ) pos[2][i][ ++pos[2][i][0] ] = y[j];

        else if( x[j] == i && z[j] == 3 ) pos[3][i][ ++pos[3][i][0] ] = y[j];

        else if( y[j] == i && z[j] == 3 ) pos[3][i][ ++pos[3][i][0] ] = x[j];

    }

}



int main(){

    freopen("party.in","r",stdin);

    freopen("party.out","w",stdout);



    int i;



    scanf("%d %d",&N,&M);

    for(i = 1; i <= M; ++i) scanf("%d %d %d",&x[i], &y[i], &z[i]);

    for(i = 1; i <= N; ++i) is[i] = -1;

    Compute();

    Gen(1);







return 0;

}
