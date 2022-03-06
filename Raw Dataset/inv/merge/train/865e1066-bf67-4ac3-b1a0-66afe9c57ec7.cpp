#include <iostream>
#include<fstream>




using namespace std;

ifstream fin("inv.in");

ofstream fout("inv.out");



int n;

int a[100005],b[100005];

int ct;



void inv(int s,int d)

{

    int mij=s+(d-s)/2,i,j,k;

    if(s==d)return ;

    if(s!=d)

    {

        inv(s,mij);

        inv(mij+1,d);



        i=s;j=mij+1;k=s-1;

        while(i<=mij&&j<=d)

            if(a[i]>a[j])

                b[++k]=a[j++];



            else

            {

               ct=(ct+j-mij-1)%9917;

               b[++k]=a[i++];

            }

        while(i<=mij)

            b[++k]=a[i++],ct=(ct+d-mij)%9917;



        while(j<=d)

            b[++k]=a[j++];



        for(i=s;i<=d;++i)

            a[i]=b[i];

    }





}



int main()

{

    int i;

    fin>>n;

    for(i=1;i<=n;++i)

        fin>>a[i];

    inv(1,n);

    fout<<ct;



    return 0;

}
