#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin("inv.in");

ofstream fout("inv.out");

long long n,v[100010],a[100010],k=1,aux[100010];

long long query(long long x){

    int r=0;

    while(x){

        r+=aux[x];

        x-=(x&-x);

    }

    return r;

}

void update(long long x){

    while(x<=k){

        aux[x]++;

        x+=(x&-x);

    }

}

int main(){

    fin>>n;

    for(int i=1;i<=n;i++){

        fin>>v[i];

        a[i]=v[i];

    }

    sort(a+1,a+n+1);

    for(int i=2;i<=n;i++)

        if(a[i]!=a[k])

            a[++k]=a[i];



    for(int i=1;i<=n;i++){

        int st=1;

        int dr=k;

        while(st<=dr){

            int mid=(st+dr)/2;

            if(v[i]==a[mid]){

                v[i]=mid;

                break;

            }

            else

                if(v[i]>a[mid])

                    st=mid+1;

                else

                    dr=mid-1;



        }



    }

    int suma=0;





    for(int i=1;i<=n;i++){

        suma+=(query(k)-query(v[i]));suma%=9917;

        update(v[i]);

      }

      fout<<suma;

}
