#include <fstream>
#include <algorithm>
#include <iostream>
using namespace std;



ifstream fin("inv.in");

ofstream fout("inv.out");



int n,i,k,v[100001],a[100001],ord[100001];

long long sol;



inline int cb(int x){

    int st=1;

    int dr=k;

    int mid;



    while(st<=dr){

        mid=(st+dr)/2;



        if(x==ord[mid])

            return mid;



        if(x<ord[mid])

            dr=mid-1;

        else

            st=mid+1;

    }

}



int query(int p){

    int sol=0;

    for(;p;p-=(p&-p))

        sol+=v[p];



    return sol;

}



void upd(int p){

    for(;p<=n;p+=(p&-p))

        v[p]++;

}



int main(){

    fin>>n;

    for(i=1;i<=n;i++)

        fin>>a[i],ord[i]=a[i];

    sort(ord+1,ord+n+1);



    ord[0]=-1;

    for(i=1;i<=n;i++)

        if(ord[i]!=ord[k])

            ord[++k]=ord[i];



    for(i=1;i<=n;i++)

        a[i]=cb(a[i]);



    for(i=1;i<=n;i++){

        sol=(sol+i-1-query(a[i]))%9917;

        upd(a[i]);

    }



    fout<<sol;



    return 0;

}
