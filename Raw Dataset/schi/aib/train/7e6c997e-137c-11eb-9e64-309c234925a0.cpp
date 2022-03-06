#include <bits/stdc++.h>
using namespace std;

char BUF[1<<17];

int poz;



inline char getChar(){

    poz++;

    if(poz>=1<<17){

     fread(BUF,1<<17,1,stdin);

     poz=0;

    }

    return BUF[poz];

}



inline int getNr(){

    int r=0, semn=1;

    char ch=getChar();

    while(isdigit(ch)==0 && ch!='-') ch=getChar();

    if(ch=='-'){

        semn=-1;

        ch=getChar();

    }

    while(isdigit(ch)!=0){

        r=r*10+semn*(ch-'0');

        ch=getChar();

    }

    return r;

}



int v[30001],aib[30001],rez[30001],n;



int zeros(int x)

{

    return (x^(x-1))&x;

}



void update(int i,int x)

{

    for(int ct=i; ct<=n; ct+=zeros(ct))

        aib[ct]+=x;

}



int query(int i)

{

    int rez=0;

    for(int ct=i; ct>0; ct-=zeros(ct))

        rez+=aib[ct];

    return rez;

}



int main()

{

    int i,pas,z;

    freopen("schi.in","r",stdin);

    freopen("schi.out","w",stdout);

    n=getNr();

    for(i=1; i<=n; i++)

        v[i]=getNr();

    for(i=1; i<=n; i++)

        update(i,1);

    for(i=n; i>0; i--)

    {

        pas=1<<14;

        z=0;

        while(pas)

        {

            if(z+pas<=n && query(z+pas)<v[i])

                z+=pas;

            pas/=2;

        }

        rez[z+1]=i;

        update(z+1,-1);

    }

    for(i=1; i<=n; i++)

        printf("%d\n",rez[i]);



    return 0;

}
