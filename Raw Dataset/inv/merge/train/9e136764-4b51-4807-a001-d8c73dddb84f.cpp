#include <iostream>
#include <fstream>
using namespace std;

ifstream in("inv.in");

ofstream out("inv.out");

int v[100001],w[100001],n,nr=0;

void inversiune(int v[],int st,int dr){

    if(st<dr){

        int mijloc=(st+dr)/2;

        inversiune(v,st,mijloc);

        inversiune(v,mijloc+1,dr);

        int i=st,j=mijloc+1,k=0;

        while(i<=mijloc and j<=dr)

            if(v[i]<=v[j])

                w[++k]=v[i++];

            else{

                w[++k]=v[j++];

                nr=(nr+mijloc-i+1)%9917;

            }

        while(i<=mijloc)

            w[++k]=v[i++];

        while(j<=dr)

            w[++k]=v[j++];

        i=1;

        for(j=st;j<=dr;j++ and i++)

            v[j]=w[i];

    }

}

int main() {

    in>>n;

    for(int i=1;i<=n;i++)

        in>>v[i];

    inversiune(v,1,n);

    out<<nr;

    return 0;

}
