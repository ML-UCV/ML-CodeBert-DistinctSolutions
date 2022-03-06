#include <fstream>
#include <cstring>
#include <climits>


using namespace std;

ifstream f("inv.in");

ofstream g("inv.out");

int n,k,i,st,dr,mid,pos,v[100001],in[100001];

long long S;

void cnt(int a,int m,int b){

    int c=0,i=a,j=m+1;

    while(i<=m&&j<=b){

        if(v[i]<=v[j]){

            in[++c]=v[i];

            i++;

        }

        else if(v[j]<v[i]){

            in[++c]=v[j];

            if(j-c>0)

                S=(S+j-(c+a-1))%9917;

            j++;

        }

    }

    while(i<=m){

        in[++c]=v[i];

        i++;

    }

    while(j<=b){

        in[++c]=v[j];

        j++;

    }

    for(i=a;i<=b;i++)

        v[i]=in[i-a+1];

}

void divi(int a,int b){

    if(b-a>0){

        int m=(a+b)/2;

        divi(a,m);

        divi(m+1,b);

        cnt(a,m,b);

    }

}

int main()

{ f>>n;

    for(i=1;i<=n;i++)

        f>>v[i];

    divi(1,n);

    g<<S;

    return 0;

}
