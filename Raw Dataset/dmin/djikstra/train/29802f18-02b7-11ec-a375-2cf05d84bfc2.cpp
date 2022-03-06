#include<stdio.h>
#include<math.h>
int vec[1515][1515], nvec[1515];

double cost[1515][1515];

int v[1515], c[1515];

double d[1515];



double modul(double x){

    if(x<0) return -x;

    return x;

}



int main(){



    FILE *fin = fopen("dmin.in","r"),

         *fout= fopen("dmin.out","w");



    int N,M;

    fscanf(fin,"%d%d",&N,&M);



    for(int i=1;i<=M;i++){

        int x,y,c;

        fscanf(fin,"%d%d%d",&x,&y,&c);

        vec[x][++nvec[x]] = y;

        cost[x][nvec[x]] = log((double)c);



        vec[y][++nvec[y]] = x;

        cost[y][nvec[y]] = cost[x][nvec[x]];

    }





    d[1] = 0;

    c[1] = 1;



    for(int i=2;i<=N;i++)

        d[i] = 50000.0;

    d[0] = 100000.0;



    for(int i=1;i<=N;i++){



        int poz = 0;

        for(int j=1;j<=N;j++)

            if(!v[j] && d[j] < d[poz])

                poz = j;





        for(int j=1;j<=nvec[poz];j++)

            if(v[vec[poz][j]] && modul(d[poz] - d[vec[poz][j]] - cost[poz][j]) < 0.000000001){

                c[poz] += c[vec[poz][j]];

                c[poz] %= 104659;

            }



        v[poz] = 1;





        for(int j=1;j<=nvec[poz];j++){

            int V = vec[poz][j];

            if(d[V] - d[poz] - cost[poz][j] > 0.000000001)

                d[V] = d[poz] + cost[poz][j];

        }



    }



    for(int i=2;i<=N;i++)

        fprintf(fout,"%d ",c[i]);



    fclose(fout);

    fclose(fin);

    return 0;

}
