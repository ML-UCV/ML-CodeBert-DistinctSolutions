#include <iostream>
#include<fstream>
#include<stdlib.h>
#include<cmath>
#include<algorithm>
#include<iomanip>
using namespace std;

ifstream f("cmap.in");

ofstream g("cmap.out");

struct punct

{

    int x;

    int y;

};



punct *vect,*X,*Y;

int nr;



void afisare(punct *vect,int inc, int dim)

{

    for(int i=inc; i<=dim; i++)

        cout<<vect[i].x<<" "<<vect[i].y<<endl;

    cout<<endl;

}



bool compare_abs (punct a, punct b)

{

    return a.x < b.x;

}



bool compare_ord (punct a, punct b)

{

    return a.y < b.y;

}





double distanta(punct a, punct b)

{

    double d1=(double)(a.x-b.x);

    double d2=(double)(a.y-b.y);

    return (d1*d1+d2*d2);

}



double DivImp( int st, int dr,punct *Y, int lung)

{

    if(dr-st+1==2)

        return distanta(X[st],X[dr]);



    if(dr-st+1==3)

             return min(distanta(X[st],X[st+1]),min(distanta(X[st+1],X[dr]),distanta(X[st],X[dr])));



    int mij=(st+dr)/2;

    punct *SY,*DY,*LY;

    SY=new punct[lung+1];

    DY=new punct[lung+1];

    LY=new punct[lung+1];

    int dim1,dim2,dim3;

    dim1=dim2=dim3=-1;



    for(int i=0; i<=lung; i++)

        if(Y[i].x<X[mij].x)

        {

            dim1++;

            SY[dim1]=Y[i];

        }

        else

        {

            dim2++;

            DY[dim2]=Y[i];

        }



    double d1=DivImp(st,mij,SY,dim1);

    double d2=DivImp(mij+1,dr,DY,dim2);

    double d=min(d1,d2);

    double delta=ceil(sqrt(d));

    for(int i=0; i<=lung; i++)

        if(abs(Y[i].x-X[mij].x)<=delta)

        {

            dim3++;

            LY[dim3]=Y[i];

        }



    for(int i=0;i<=dim3;i++)

        for(int j=i+1 ; j<=(i+7) && j<=dim3 ; j++)

            {

            d=min(d,distanta(LY[i],LY[j]));

            }

    delete[]SY;

    delete[]DY;

    delete[]LY;

    return d;



}



int main()

{

    f>>nr;

    vect=new punct[nr+1];

    X=new punct[nr+1];

    Y=new punct[nr+1];

    for(int i=0; i<nr; i++)

    {

        f>>vect[i].x>>vect[i].y;

        X[i]=vect[i];

        Y[i]=vect[i];

    }



    sort(X,X+nr,compare_abs);

    sort(Y,Y+nr,compare_ord);

    g<<fixed<<setprecision(6)<<sqrt(DivImp(0,nr-1,Y,nr-1));



    delete[] vect;

    delete[] X;

    delete[] Y;



    f.close();

    g.close();

    return 0;

}
