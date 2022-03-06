#include <iostream>
#include <fstream>


using namespace std;



ifstream x("schi.in");

ofstream y("schi.out");



int n,i,nr,pos,v[30002];



struct elem

{

    int s,lazy;

}a[4*30002];



void build(int nod, int left, int right)

{

    if(left==right)

    {

        a[nod].lazy=1;

        return;

    }



    int mij=(left+right)/2;



    build(nod*2,left,mij);

    build(nod*2+1,mij+1,right);



    a[nod].lazy=a[nod*2].lazy+a[nod*2+1].lazy;

}



void update(int nod, int left, int right, int m, int val)

{

    if(left==right)

    {

        a[right].s=val;

        a[nod].lazy=0;

        return;

    }



    int mij=(left+right)/2;



    if(m<=a[nod*2].lazy)

        update(nod*2,left,mij,m,val);

    else

        update(nod*2+1,mij+1,right,m-a[nod*2].lazy,val);



    a[nod].lazy=a[nod*2].lazy+a[nod*2+1].lazy;

}



void citire()

{

    x>>n;

    for(i=1;i<=n;i++)

        x>>v[i];

    build(1,1,n);

}



int main()

{

    citire();

    for(i=n;i>=1;i--)

        update(1,1,n,v[i],i);

    for(i=1;i<=n;i++)

        y<<a[i].s<<'\n';

    x.close();

    y.close();

    return 0;

}
