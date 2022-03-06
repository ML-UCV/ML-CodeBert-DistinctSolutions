#include <fstream>
using namespace std;



ifstream fin("schi.in");

ofstream fout("schi.out");



int n,i,v[30001],aib[30001],sol[30001],st,dr,mid,aux,r;



void upd(int p, int x){

    for(;p<=n;p+=(p&-p))

        aib[p]+=x;

}



int qry(int p){

    int s=0;



    for(;p;p-=(p&-p))

        s+=aib[p];



    return s;

}



int cb(int x){

    st=1; dr=n;

    r=1000000000;



    while(st<=dr){

        mid=(st+dr)/2;

        aux=qry(mid);



        if(x<=aux)

            dr=mid-1;

        else

            st=mid+1;

    }



    return st;

}





int main(){

    fin>>n;



    for(i=1;i<=n;i++){

        fin>>v[i];

        upd(i,1);

    }



    for(i=n;i>=1;i--){

        aux=cb(v[i]);

        upd(aux,-1);

        sol[aux]=i;

    }



    for(i=1;i<=n;i++)

        fout<<sol[i]<<"\n";



    return 0;

}
