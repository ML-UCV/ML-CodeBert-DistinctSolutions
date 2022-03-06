#include<iostream>
#include<ctime>
#include<cstdio>
#include<cstdlib>






using namespace std;



typedef struct cerinta {

    int x;

    int y;

    int z;

} cer;

cer c[1010];



int v[1010];

int main()

{

    srand(time(NULL));

    int n, m, ok, r;



    FILE *fin, *fout;

    fin = fopen("party.in", "r");

    fout=fopen("party.out", "w");



    fscanf(fin, "%d %d", &n, &m);



    for(int i=0; i<m; i++)

    {

        fscanf(fin, "%d %d %d", &c[i].x, &c[i].y, &c[i].z);

    }

    for(int i=1; i<=n; i++)

        v[i]=1;

    ok=0;

    while( !ok ) {

        ok=1;

        for(int i=0; i<m; i++) {

            if(c[i].z == 0) {

                if(v[c[i].x] == 0 && v[c[i].y] == 0)

                {

                    r = rand() % 2;

                    if(r == 0)

                        v[c[i].x] = 1;

                    else

                        v[c[i].y] = 1;

                    ok = 0;

                }

            }

            if(c[i].z == 1) {

                if(v[c[i].x] == 0 && v[c[i].y] == 1)

                {

                    r = rand() % 2;

                    if(r == 0)

                        v[c[i].x] = 1;

                    else

                        v[c[i].y] = 0;

                    ok = 0;

                }

            }

            if(c[i].z == 2) {

                if(v[c[i].x] == 1 && v[c[i].y] == 0) {

                    r = rand() % 2;

                    if(r == 0)

                        v[c[i].x] = 0;

                    else

                        v[c[i].y] = 1;

                    ok = 0;

                }

            }

            if(c[i].z == 3)

            {

                if(v[c[i].x] == 1 && v[c[i].y] == 1) {

                    r = rand() % 2;

                    if(r == 0)

                        v[c[i].x] = 0;

                    else

                        v[c[i].y] = 0;

                    ok = 0;

                }

            }

        }

    }

    int nr=0;

    for(int i=1; i <= n; i++)

        if(v[i]==1)

            nr++;

    fprintf(fout, "%d\n", nr);

    for(int i=1; i<=n; i++)

        if(v[i])

            fprintf(fout, "%d\n", i);

}
