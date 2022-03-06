#include <iostream>
#include<stdio.h>
#include <math.h>
#include <algorithm>
#include <iomanip>
FILE *f=fopen("cmap.in","r"),*g=fopen("cmap.out","w");

using namespace std;

int n;



struct Punct{

    double x;

    double y;

}v[100005],w[100005],a[100005];



void citire(){

int i;

    fscanf(f,"%d",&n);

    for(i=1; i<=n; i++){

        fscanf(f,"%lf %lf",&v[i].x,&v[i].y);

    }

}



double distanta(Punct A,Punct B){

    return (B.x-A.x)*(B.x-A.x) + (B.y-A.y)*(B.y-A.y);

}



bool cmp(Punct A,Punct B){

    if(A.x<B.x){return 1;}

    return 0;

}



void interschimba(Punct A,Punct B){

    Punct aux;

    aux=A; A=B; B=aux;

}



double minim;

double rezolvare(int st,int dr){

int mij,i,j,k,t,r;

double solst,soldr,xmij;



    if(dr-st+1==2){

        if(v[st].y>v[dr].y){

            interschimba(v[st],v[dr]);

        }

        return distanta(v[st],v[dr]);

    }

    else if(dr-st+1==3){

        if(v[st].y>v[st+1].y){

            interschimba(v[st],v[st+1]);

        }

        if(v[st+1].y>v[dr].y){

            interschimba(v[st+1],v[dr]);

        }

        if(v[st].y>v[dr].y){

            interschimba(v[st],v[dr]);

        }

        return min(distanta(v[st],v[st+1]),min(distanta(v[st+1],v[dr]),distanta(v[st],v[dr])));

    }

    else{

        mij=(st+dr)/2;

        xmij=v[mij].x;

        solst=rezolvare(st,mij);

        soldr=rezolvare(mij+1,dr);

        minim=min(solst,soldr);
        i=st; j=mij+1; k=i;

        while(i<=mij && j<=dr){

            if(v[i].y<v[j].y){

                w[k]=v[i]; k++; i++;

            }

            else{

                w[k]=v[j]; k++; j++;

            }

        }

        while(i<=mij){w[k]=v[i]; i++; k++;}

        while(j<=dr){w[k]=v[j]; j++; k++;}



        t=1;

        for(i=st; i<=dr; i++){

            v[i]=w[i];

            if(v[i].x-xmij<=(int)sqrt(minim) && v[i].x-xmij>=-(int)sqrt(minim)){



                a[t]=v[i]; t++;

            }

        }

        t--;

        for(i=1; i<=t; i++){





            if(i+7<=t){

                j=i+7;

            }

            else{j=t;}

            for(r=i+1; r<=j; r++){

                if(distanta(a[i],a[r])<minim){

                    minim=distanta(a[i],a[r]);

                }

            }

        }

        return minim;

    }

}

int main()

{

    citire();

    sort(v+1,v+n+1,cmp);

    fprintf(g,"%.6lf",sqrt(rezolvare(1,n)));

    return 0;

}
