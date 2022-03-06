#include <bits/stdc++.h>


using namespace std;

ifstream in("schi.in");

ofstream out("schi.out");

int a[30005],r[30005],v[30005],n;

void upd(int i){

    while(i<=n){

        ++a[i];

        i+=(i&(-i));

    }

}

int q(int i){

    int s=0;

    while(i){

        s+=a[i];

        i-=(i&(-i));

    }

    return s;

}

int main(){

    int i,x,y,aux,x1,y1,aux1;

    in>>n;

    for(i=1; i<=n; ++i)

        in>>v[i];

    for(i=n; i>0; --i){

        y=v[i];

        x=q(y)+y;

        if(x-y){

            x1=q(x), y1=x-y;

            while(x1!=y1){

                aux=x, aux1=x1;

                x+=x1-y1;

                x1=q(x);

                y=aux, y1=aux1;

            }

        }

        r[x]=i;

        upd(x);

    }

    for(i=1; i<=n; ++i)

        out<<r[i]<<"\n";

    return 0;

}
